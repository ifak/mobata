#include "settings.h"

#include <iostream>

void setNodeOptionsDelegate(const view::graph::NodeOptions& options, view::graph::NodeOptions* targetOptions)
{
  setPen<view::graph::NodeOptions>(options.pen(), targetOptions);
  setColor<view::graph::NodeOptions>(options.getColor(), targetOptions);
  setSize<view::graph::NodeOptions>(options.size(), targetOptions);
  setTextColor<view::graph::NodeOptions>(options.textColor(), targetOptions);
  setTextFont<view::graph::NodeOptions>(options.textFont(), targetOptions);
}

void setArcOptionsDelegate(const view::graph::ArcOptions& options, view::graph::ArcOptions* targetOptions)
{
  setPen<view::graph::ArcOptions>(options.pen(), targetOptions);
  setTextColor<view::graph::ArcOptions>(options.textColor(), targetOptions);
  setTextFont<view::graph::ArcOptions>(options.textFont(), targetOptions);
}

void setMiscOptionsDelegate(const QVariant &options, QVariant* targetOptions)
{
  *targetOptions = options;
}

Settings::Settings(QObject *parent, QString settingPrefix, QString appInfo, QString orgInfo)
  : QObject(parent), _settingPrefix(settingPrefix), _configs(new QSettings(orgInfo, appInfo))
{
  connect(this, SIGNAL(nodeOptionsModified(QString)), this, SLOT(updateNodeConfig(QString)));
  connect(this, SIGNAL(arcOptionsModified(QString)), this, SLOT(updateArcConfig(QString)));
  connect(this, SIGNAL(miscOptionsModified(QString)), this, SLOT(updateMiscConfig(QString)));
  connect(this, SIGNAL(nodeOptionsReplaced(QString)), this, SLOT(updateNodeConfig(QString)));
  connect(this, SIGNAL(arcOptionsReplaced(QString)), this, SLOT(updateArcConfig(QString)));
  connect(this, SIGNAL(miscOptionsReplaced(QString)), this, SLOT(updateMiscConfig(QString)));
  connect(this, SIGNAL(nodeOptionsRemoved(QString)), this, SLOT(updateNodeConfig(QString)));
  connect(this, SIGNAL(arcOptionsRemoved(QString)), this, SLOT(updateArcConfig(QString)));
  connect(this, SIGNAL(miscOptionsRemoved(QString)), this, SLOT(updateMiscConfig(QString)));
}

Settings::Settings(const Settings& source, QObject *parent)
  : QObject(parent), _settingPrefix(source._settingPrefix), _configs(source._configs),
    _nodeOptionList(source._nodeOptionList), _arcOptionList(source._arcOptionList), _miscOptionList(source._miscOptionList)
{
  connect(this, SIGNAL(nodeOptionsModified(QString)), this, SLOT(updateNodeConfig(QString)));
  connect(this, SIGNAL(arcOptionsModified(QString)), this, SLOT(updateArcConfig(QString)));
  connect(this, SIGNAL(miscOptionsModified(QString)), this, SLOT(updateMiscConfig(QString)));
  connect(this, SIGNAL(nodeOptionsReplaced(QString)), this, SLOT(updateNodeConfig(QString)));
  connect(this, SIGNAL(arcOptionsReplaced(QString)), this, SLOT(updateArcConfig(QString)));
  connect(this, SIGNAL(miscOptionsReplaced(QString)), this, SLOT(updateMiscConfig(QString)));
  connect(this, SIGNAL(nodeOptionsRemoved(QString)), this, SLOT(updateNodeConfig(QString)));
  connect(this, SIGNAL(arcOptionsRemoved(QString)), this, SLOT(updateArcConfig(QString)));
  connect(this, SIGNAL(miscOptionsRemoved(QString)), this, SLOT(updateMiscConfig(QString)));
}

Settings::~Settings()
{
  delete _configs;
}

QString Settings::settingPrefix()
{
  return _settingPrefix;
}

void Settings::synchronizeOptions(QStandardItem* itemGroup)
{
  importAllPropertiesFromQStandardItem(itemGroup);
}

void Settings::synchronizeOptions(QStandardItemModel* model)
{
  importAllPropertiesFromQStandardItemModel(model);
}

void Settings::updateNodeConfig(QString categoryName)
{
  try
  {
    findNodeOptions(categoryName);
    writeNodeSettingsToConfigFile(categoryName);
  }
  catch (ErrorReport& ex)
  {
    if (not_found == ex.type)
    {
      if (-1 != _configs->childGroups().indexOf(categoryName.toLower()))
      {
        _configs->remove(categoryName.toLower());
      }
    }
  }
}

void Settings::updateArcConfig(QString categoryName)
{
  try
  {
    findArcOptions(categoryName);
    writeArcSettingsToConfigFile(categoryName);
  }
  catch (ErrorReport& ex)
  {
    if (not_found == ex.type)
    {
      if (-1 != _configs->childGroups().indexOf(categoryName.toLower()))
      {
        _configs->remove(categoryName.toLower());
      }
    }
  }
}

void Settings::updateMiscConfig(QString categoryName)
{
  try
  {
    findMiscSetting(categoryName);
    writeMiscSettingsToConfigFile(categoryName);
  }
  catch (ErrorReport& ex)
  {
    if (not_found == ex.type)
    {
      _configs->beginGroup("misc");
      if (-1 != _configs->childGroups().indexOf(categoryName.toLower()))
      {
        _configs->remove(categoryName.toLower());
      }
      _configs->endGroup();
    }
  }
}

int Settings::readNodeSettingsFromConfigFile(const QString categoryName)
{
  view::graph::NodeOptions *nodeOptions;
  try
  {
    nodeOptions = findNodeOptions(categoryName);
  }
  catch (ErrorReport& ex)
  {
    if (not_found == ex.type)
    {
      throw ErrorReport(not_found, ex.item);
    }
  }

  if (_settingPrefix.compare(QString("")))
  {
    _configs->beginGroup(_settingPrefix);
  }

  int incompleteSubItemCount = 0;

  if (-1 == _configs->childGroups().indexOf(categoryName.toLower()))
  {
    incompleteSubItemCount++;
  }
  else
  {
    _configs->beginGroup(categoryName.toLower());
    const QStringList containedItemList = _configs->childGroups();

    _configs->beginGroup("text");
    if (-1 == containedItemList.indexOf("text"))
    {
      incompleteSubItemCount++;
    }
    else
    {
      incompleteSubItemCount+=(readColorSettingFromConfigFile<view::graph::NodeOptions>(nodeOptions,
                                                                                        &view::graph::NodeOptions::setTextColor));
      incompleteSubItemCount+=(readFontSettingFromConfigFile<view::graph::NodeOptions>(nodeOptions,
                                                                                       &view::graph::NodeOptions::setTextFont));
    }
    _configs->endGroup();

    _configs->beginGroup("box");
    if (-1 == containedItemList.indexOf("box"))
    {
      incompleteSubItemCount++;
    }
    else
    {
      incompleteSubItemCount+=(readColorSettingFromConfigFile<view::graph::NodeOptions>(nodeOptions,
                                                                                        &view::graph::NodeOptions::setColor));
      incompleteSubItemCount+=(readSizeSettingFromConfigFile<view::graph::NodeOptions>(nodeOptions,
                                                                                       &view::graph::NodeOptions::setSize));
    }
    _configs->endGroup();

    _configs->beginGroup("border");
    if (-1 == containedItemList.indexOf("border"))
    {
      incompleteSubItemCount++;
    }
    else
    {
      incompleteSubItemCount+=(readPenSettingFromConfigFile<view::graph::NodeOptions>(nodeOptions,
                                                                                      &view::graph::NodeOptions::setPen));
    }
    _configs->endGroup();

    _configs->endGroup();
  }

  if (_settingPrefix.compare(QString("")))
  {
    _configs->endGroup();
  }

  return incompleteSubItemCount;
}

int Settings::readArcSettingsFromConfigFile(const QString categoryName)
{
  view::graph::ArcOptions* arcOptions = 0;
  try
  {
    arcOptions = findArcOptions(categoryName);
  }
  catch (ErrorReport& ex)
  {
    throw ErrorReport(ex.type, ex.item);
  }
  catch(std::exception& exc)
  {
    std::cerr<<exc.what();
    return 0;
  }
  Q_ASSERT(arcOptions);

  if (_settingPrefix.compare(QString("")))
  {
    _configs->beginGroup(_settingPrefix);
  }

  int incompleteSubItemCount = 0;

  if (-1 == _configs->childGroups().indexOf(categoryName.toLower()))
  {
    incompleteSubItemCount++;
  }
  else
  {
    _configs->beginGroup(categoryName.toLower());
    const QStringList containedItemList = _configs->childGroups();

    _configs->beginGroup("text");
    if (-1 == containedItemList.indexOf("text"))
    {
      incompleteSubItemCount++;
    }
    else
    {
      incompleteSubItemCount+=(readColorSettingFromConfigFile<view::graph::ArcOptions>(arcOptions,
                                                                                       &view::graph::ArcOptions::setTextColor));
      incompleteSubItemCount+=(readFontSettingFromConfigFile<view::graph::ArcOptions>(arcOptions,
                                                                                      &view::graph::ArcOptions::setTextFont));
    }
    _configs->endGroup();

    _configs->beginGroup("line");
    if (-1 == containedItemList.indexOf("line"))
    {
      incompleteSubItemCount++;
    }
    else
    {
      incompleteSubItemCount+=(readPenSettingFromConfigFile<view::graph::ArcOptions>(arcOptions,
                                                                                     &view::graph::ArcOptions::setPen));
    }
    _configs->endGroup();

    _configs->endGroup();
  }

  if (_settingPrefix.compare(QString("")))
  {
    _configs->endGroup();
  }

  return incompleteSubItemCount;
}

int Settings::readMiscSettingsFromConfigFile(const QString categoryName)
{
  OptionInfoSt<QVariant>* miscSetting = 0;
  try
  {
    miscSetting = static_cast<OptionInfoSt<QVariant>* >(findMiscSetting(categoryName));
  }
  catch (ErrorReport& ex)
  {
    throw ErrorReport(ex.type, ex.item);
  }
  catch(std::exception& exc)
  {
    std::cerr<<exc.what();
    return 0;
  }
  Q_ASSERT(miscSetting);

  if (_settingPrefix.compare(QString("")))
  {
    _configs->beginGroup(_settingPrefix);
  }

  int incompleteSubItemCount = 0;

  _configs->beginGroup("misc");
  if (-1 == _configs->childGroups().indexOf(categoryName.toLower()))
  {
    incompleteSubItemCount++;
  }
  else
  {
    _configs->beginGroup(categoryName.toLower());
    if (!_configs->contains("type"))
    {
      // The value cannot be parsed.
      incompleteSubItemCount++;
    }
    else
    {
      miscSetting->infoOptions = _configs->value("value");
      miscSetting->additionalInfo = _configs->value("type").toString();
    }
    _configs->endGroup();
  }
  _configs->endGroup();

  if (_settingPrefix.compare(QString("")))
  {
    _configs->endGroup();
  }

  return incompleteSubItemCount;
}

int Settings::readAllSettingsFromConfigFile()
{
  int incompleteSubItemCount = 0;

  foreach (const OptionInfoSt<view::graph::NodeOptions> &nodeInfo, _nodeOptionList)
  {
    try
    {
      incompleteSubItemCount+=(readNodeSettingsFromConfigFile(nodeInfo.infoName));
    }
    catch (ErrorReport& ex)
    {
      if (not_found == ex.type)
      {
        qDebug() << "An unknown error occured during excuting the method \'Settings::readNodeSettingsFromConfigFile()\' : reading " << ex.item << " options is not possible.";
      }
    }
  }

  foreach (const OptionInfoSt<view::graph::ArcOptions> &arcInfo, _arcOptionList)
  {
    try
    {
      incompleteSubItemCount+=(readArcSettingsFromConfigFile(arcInfo.infoName));
    }
    catch (ErrorReport& ex)
    {
      if (not_found == ex.type)
      {
        qDebug() << "An unknown error occured during excuting the method \'Settings::readArcSettingsFromConfigFile()\' : reading " << ex.item << " options is not possible.";
      }
    }
  }

  foreach (const OptionInfoSt<QVariant> &miscInfo, _miscOptionList)
  {
    try
    {
      incompleteSubItemCount+=(readMiscSettingsFromConfigFile(miscInfo.infoName));
    }
    catch (ErrorReport& ex)
    {
      if (not_found == ex.type)
      {
        qDebug() << "An unknown error occured during excuting the method \'Settings::readMiscSettingsFromConfigFile()\' : reading " << ex.item << " options is not possible.";
      }
    }
  }

  return incompleteSubItemCount;
}

void Settings::writeNodeSettingsToConfigFile(const QString categoryName)
{
  view::graph::NodeOptions* nodeOptions = 0;
  try
  {
    nodeOptions = findNodeOptions(categoryName);
  }
  catch (ErrorReport& ex)
  {
    throw ErrorReport(ex.type, ex.item);
  }
  catch(std::exception& exc)
  {
    std::cerr<<exc.what();
    return;
  }
  Q_ASSERT(nodeOptions);

  if (_settingPrefix.compare(QString("")))
  {
    _configs->beginGroup(_settingPrefix);
  }

  _configs->beginGroup(categoryName.toLower());
  _configs->beginGroup("text");
  writeColorSettingsToConfigFile<view::graph::NodeOptions>(nodeOptions, &view::graph::NodeOptions::textColor);
  writeFontSettingsToConfigFile<view::graph::NodeOptions>(nodeOptions, &view::graph::NodeOptions::textFont);
  _configs->endGroup();
  _configs->beginGroup("box");
  writeColorSettingsToConfigFile<view::graph::NodeOptions>(nodeOptions, &view::graph::NodeOptions::getColor);
  writeSizeSettingsToConfigFile<view::graph::NodeOptions>(nodeOptions, &view::graph::NodeOptions::size);
  _configs->endGroup();
  _configs->beginGroup("border");
  writePenSettingsToConfigFile<view::graph::NodeOptions>(nodeOptions, &view::graph::NodeOptions::pen);
  _configs->endGroup();
  _configs->endGroup();

  if (_settingPrefix.compare(QString("")))
  {
    _configs->endGroup();
  }
}

void Settings::writeArcSettingsToConfigFile(const QString categoryName)
{
  view::graph::ArcOptions* arcOptions = 0;
  try
  {
    arcOptions = findArcOptions(categoryName);
  }
  catch (ErrorReport& ex)
  {
    throw ErrorReport(ex.type, ex.item);
  }
  catch(std::exception& exc)
  {
    std::cerr<<exc.what();
    return;
  }
  Q_ASSERT(arcOptions);

  if (_settingPrefix.compare(QString("")))
  {
    _configs->beginGroup(_settingPrefix);
  }

  _configs->beginGroup(categoryName.toLower());
  _configs->beginGroup("text");
  writeColorSettingsToConfigFile<view::graph::ArcOptions>(arcOptions, &view::graph::ArcOptions::textColor);
  writeFontSettingsToConfigFile<view::graph::ArcOptions>(arcOptions, &view::graph::ArcOptions::textFont);
  _configs->endGroup();
  _configs->beginGroup("line");
  writePenSettingsToConfigFile<view::graph::ArcOptions>(arcOptions, &view::graph::ArcOptions::pen);
  _configs->endGroup();
  _configs->endGroup();

  if (_settingPrefix.compare(QString("")))
  {
    _configs->endGroup();
  }
}

void Settings::writeMiscSettingsToConfigFile(const QString categoryName)
{
  OptionInfoSt<QVariant>* miscSetting = 0;
  try
  {
    miscSetting = static_cast<OptionInfoSt<QVariant>* >(findMiscSetting(categoryName));
  }
  catch (ErrorReport& ex)
  {
    throw ErrorReport(ex.type, ex.item);
  }
  catch(std::exception& exc)
  {
    std::cerr<<exc.what();
    return;
  }
  Q_ASSERT(miscSetting);

  if (_settingPrefix.compare(QString("")))
  {
    _configs->beginGroup(_settingPrefix);
  }

  _configs->beginGroup("misc");
  _configs->beginGroup(categoryName.toLower());
  _configs->setValue("value", miscSetting->infoOptions);
  _configs->setValue("type", miscSetting->additionalInfo);
  _configs->endGroup();
  _configs->endGroup();

  if (_settingPrefix.compare(QString("")))
  {
    _configs->endGroup();
  }
}

void Settings::writeAllSettingsToConfigFile()
{
  foreach (const OptionInfoSt<view::graph::NodeOptions> &nodeInfo, _nodeOptionList)
  {
    try
    {
      writeNodeSettingsToConfigFile(nodeInfo.infoName);
    }
    catch (ErrorReport& ex)
    {
      if (not_found == ex.type)
      {
        qDebug() << "An unknown error occured during excuting the method \'Settings::writeNodeSettingsToConfigFile()\' : writing " << ex.item << " options is not possible.";
      }
    }
  }

  foreach (const OptionInfoSt<view::graph::ArcOptions> &arcInfo, _arcOptionList)
  {
    try
    {
      writeArcSettingsToConfigFile(arcInfo.infoName);
    }
    catch (ErrorReport& ex)
    {
      if (not_found == ex.type)
      {
        qDebug() << "An unknown error occured during excuting the method \'Settings::writeArcSettingsToConfigFile()\' : writing " << ex.item << " options is not possible.";
      }
    }
  }

  foreach (const OptionInfoSt<QVariant> &miscInfo, _miscOptionList)
  {
    try
    {
      writeMiscSettingsToConfigFile(miscInfo.infoName);
    }
    catch (ErrorReport& ex)
    {
      if (not_found == ex.type)
      {
        qDebug() << "An unknown error occured during excuting the method \'Settings::writeMiscSettingsToConfigFile()\' : writing " << ex.item << " options is not possible.";
      }
    }
  }
}

QStandardItem* Settings::exportNodeProperties(const QString categoryName) const
{
  view::graph::NodeOptions* nodeOptions = 0;
  try
  {
    nodeOptions = findNodeOptions(categoryName);
  }
  catch (ErrorReport& ex)
  {
    throw ErrorReport(not_found, ex.item);
  }
  catch(std::exception& exc)
  {
    std::cerr<<exc.what();
    return 0;
  }
  Q_ASSERT(nodeOptions);

  QStandardItem *nodeItem = new QStandardItem(categoryName);
  nodeItem->setEditable(false);

  QList< QList<QStandardItem*> > itemConfigList;
  itemConfigList.append(exportFontProperty<view::graph::NodeOptions>(QString("Text Font"),
                                                                     nodeOptions,
                                                                     &view::graph::NodeOptions::textFont));
  itemConfigList.append(exportColorProperty<view::graph::NodeOptions>(QString("Text Color"),
                                                                      nodeOptions,
                                                                      &view::graph::NodeOptions::textColor));
  itemConfigList.append(exportSizeProperty<view::graph::NodeOptions>(QString("Box Size"), nodeOptions, &view::graph::NodeOptions::size));
  itemConfigList.append(exportColorProperty<view::graph::NodeOptions>(QString("Box Color"), nodeOptions, &view::graph::NodeOptions::getColor));

  QList<QList<QStandardItem*> > nodeBorderPenConfigList(exportPenProperty<view::graph::NodeOptions>(QString("Border"), nodeOptions, &view::graph::NodeOptions::pen));
  foreach (const QList<QStandardItem*> currProperty, nodeBorderPenConfigList)
  {
    itemConfigList.append(currProperty);
  }
  foreach (const QList<QStandardItem*> subConfigs, itemConfigList)
  {
    nodeItem->appendRow(subConfigs);
  }

  nodeItem->setWhatsThis(QString("Node Options"));

  return nodeItem;
}

QStandardItem* Settings::exportArcProperties(const QString categoryName) const
{
  view::graph::ArcOptions* arcOptions = 0;
  try
  {
    arcOptions = findArcOptions(categoryName);
  }
  catch (ErrorReport& ex)
  {
    throw ErrorReport(ex.type, ex.item);
  }
  catch(std::exception& exc)
  {
    std::cerr<<exc.what();
    return 0;
  }
  Q_ASSERT(arcOptions);

  QStandardItem *arcItem = new QStandardItem(categoryName);
  arcItem->setEditable(false);

  QList< QList<QStandardItem*> > itemConfigList;

  itemConfigList.append(exportFontProperty<view::graph::ArcOptions>(QString("Text Font"),
                                                                    arcOptions,
                                                                    &view::graph::ArcOptions::textFont));
  itemConfigList.append(exportColorProperty<view::graph::ArcOptions>(QString("Text Color"),
                                                                     arcOptions,
                                                                     &view::graph::ArcOptions::textColor));
  QList<QList<QStandardItem*> > arcLinePenConfigList(exportPenProperty<view::graph::ArcOptions>(QString("Line"),
                                                                                                arcOptions,
                                                                                                &view::graph::ArcOptions::pen));
  foreach (const QList<QStandardItem*> currProperty,
           arcLinePenConfigList)
    itemConfigList.append(currProperty);

  foreach (const QList<QStandardItem*> subConfigs,
           itemConfigList)
    arcItem->appendRow(subConfigs);

  arcItem->setWhatsThis(QString("Arc Options"));

  return arcItem;
}

QStandardItem* Settings::exportMiscProperties() const
{
  QStandardItem *miscItem = new QStandardItem("misc");

  foreach (const OptionInfoSt<QVariant> &optionInfo, _miscOptionList)
  {
    QList<QStandardItem*> currConfigList;

    QStandardItem *currItem = new QStandardItem(optionInfo.infoName);
    currItem->setEditable(false);
    currConfigList.append(currItem);

    QStandardItem *currItemValue = new QStandardItem(optionInfo.infoOptions.toString());
    currConfigList.append(currItemValue);

    QStandardItem *currItemChar = new QStandardItem(optionInfo.additionalInfo);
    currItemChar->setEditable(false);
    currConfigList.append(currItemChar);

    miscItem->appendRow(currConfigList);
  }

  miscItem->setWhatsThis(QString("Misc Options"));

  return miscItem;
}

QStandardItem *Settings::exportAllPropertiesToQStandardItem(const QString customPrefix) const
{
  QStandardItem *itemGroup;

  if (customPrefix.compare(""))
  {
    itemGroup = new QStandardItem(customPrefix);
  }
  else
  {
    itemGroup = new QStandardItem(_settingPrefix);
  }

  foreach (const OptionInfoSt<view::graph::NodeOptions> &nodeInfo, _nodeOptionList)
  {
    try
    {
      itemGroup->appendRow(exportNodeProperties(nodeInfo.infoName));
    }
    catch (ErrorReport& ex)
    {
      if (not_found == ex.type)
      {
        qDebug() << "An unknown error occured during excuting the method \'Settings::exportNodeProperties()\' : exporting " << ex.item << " options is not possible.";
      }
    }
  }

  foreach (const OptionInfoSt<view::graph::ArcOptions> &arcInfo, _arcOptionList)
  {
    try
    {
      itemGroup->appendRow(exportArcProperties(arcInfo.infoName));
    }
    catch (ErrorReport& ex)
    {
      if (not_found == ex.type)
      {
        qDebug() << "An unknown error occured during excuting the method \'Settings::exportArcProperties()\' : exporting " << ex.item << " options is not possible.";
      }
    }
  }

  QStandardItem *miscProperties = exportMiscProperties();
  if (0 < miscProperties->rowCount())
  {
    itemGroup->appendRow(exportMiscProperties());
  }

  return itemGroup;
}

QStandardItemModel *Settings::exportAllPropertiesToQStandardItemModel(QObject *parent, const QString customPrefix) const
{
  QStandardItemModel *newModel = new QStandardItemModel(parent);

  newModel->setColumnCount(2);
  newModel->setHorizontalHeaderItem(0, new QStandardItem(QString("Characteristic")));
  newModel->setHorizontalHeaderItem(1, new QStandardItem(QString("Value")));

  if (customPrefix.compare(QString("")))
  {
    QStandardItem *fqig = exportAllPropertiesToQStandardItem(customPrefix);
    newModel->appendRow(fqig);
  }
  else if (_settingPrefix.compare(QString("")))
  {
    QStandardItem *fqig = exportAllPropertiesToQStandardItem(_settingPrefix);
    newModel->appendRow(fqig);
  }
  else
  {
    foreach (const OptionInfoSt<view::graph::NodeOptions> &nodeInfo, _nodeOptionList)
    {
      try
      {
        newModel->appendRow(exportNodeProperties(nodeInfo.infoName));
      }
      catch (ErrorReport& ex)
      {
        if (not_found == ex.type)
        {
          qDebug() << "An unknown error occured during excution the method \'Settings::exportNodeProperties()\' : exporting " << ex.item << " options is not possible.";
        }
      }
    }

    foreach (const OptionInfoSt<view::graph::ArcOptions> &arcInfo, _arcOptionList)
    {
      try
      {
        newModel->appendRow(exportArcProperties(arcInfo.infoName));
      }
      catch (ErrorReport& ex)
      {
        if (not_found == ex.type)
        {
          qDebug() << "An unknown error occured during excuting the method \'Settings::exportArcProperties()\' : exporting " << ex.item << " options is not possible.";
        }
      }
    }

    QStandardItem *miscProperties = exportMiscProperties();
    if (0 < miscProperties->rowCount())
    {
      newModel->appendRow(exportMiscProperties());
    }
  }

  return newModel;
}

void Settings::importNodeProperties(const QStandardItem* item)
{
  QString categoryName = item->text();
  view::graph::NodeOptions* nodeOptions = 0;
  try
  {
    nodeOptions = findNodeOptions(categoryName);
  }
  catch (ErrorReport& ex)
  {
    throw ErrorReport(ex.type, ex.item);
  }
  catch(std::exception& exc)
  {
    std::cerr<<exc.what();
    return;
  }
  Q_ASSERT(nodeOptions);

  bool hasPenSettings = false;
  QPen newPen(nodeOptions->pen());

  for (int i = 0; i < item->rowCount(); i++)
  {
    QStandardItem *currOption = item->child(i, 0);
    QString currOptionName = currOption->text();
    if (!currOptionName.compare(QString("Text Font")))
    {
      try
      {
        importFontProperty<view::graph::NodeOptions>(currOption, nodeOptions, &view::graph::NodeOptions::setTextFont);
      }
      catch (QString& ex)
      {
        qDebug() << "Not allowed action for the category \'" << categoryName << "\' : " << ex;
      }
    }
    else if (!currOptionName.compare(QString("Text Color")))
    {
      try
      {
        importColorProperty<view::graph::NodeOptions>(item->child(i, 1), nodeOptions, &view::graph::NodeOptions::setTextColor);
      }
      catch (QString& ex)
      {
        qDebug() << "Not allowed action for the category \'" << categoryName << "\' : " << ex;
      }
    }
    else if (!currOptionName.compare(QString("Box Size")))
    {
      try
      {
        importSizeProperty<view::graph::NodeOptions>(currOption, nodeOptions, &view::graph::NodeOptions::setSize);
      }
      catch (QString& ex)
      {
        qDebug() << "Not allowed action for the category \'" << categoryName << "\' : " << ex;
      }
    }
    else if (!currOptionName.compare(QString("Box Color")))
    {
      try
      {
        importColorProperty<view::graph::NodeOptions>(item->child(i, 1), nodeOptions, &view::graph::NodeOptions::setColor);
      }
      catch (QString& ex)
      {
        qDebug() << "Not allowed action for the category \'" << categoryName << "\' : " << ex;
      }
    }
    else if (!currOptionName.compare(QString("Border Width")))
    {
      hasPenSettings = true;
      newPen.setWidth(item->child(i, 1)->text().toInt());
    }
    else if (!currOptionName.compare(QString("Border Color")))
    {
      hasPenSettings = true;
      newPen.setColor(QColor(item->child(i, 1)->text()));
    }
    else
    {
      continue;
    }
  }

  if (hasPenSettings)
  {
    try
    {
      importPenProperty<view::graph::NodeOptions>(newPen, nodeOptions, &view::graph::NodeOptions::setPen);
    }
    catch (QString& ex)
    {
      qDebug() << "Not allowed action for the category \'" << categoryName << "\' : " << ex;
    }
  }

  emit nodeOptionsModified(categoryName);
}

void Settings::importArcProperties(const QStandardItem* item)
{
  QString categoryName = item->text();
  view::graph::ArcOptions* arcOptions = 0;
  try
  {
    arcOptions = findArcOptions(categoryName);
  }
  catch (ErrorReport& ex)
  {
    throw ErrorReport(ex.type, ex.item);
  }
  catch(std::exception& exc)
  {
    std::cerr<<exc.what();
    return;
  }
  Q_ASSERT(arcOptions);

  bool hasPenSettings = false;
  QPen newPen(arcOptions->pen());

  for (int i = 0; i < item->rowCount(); i++)
  {
    QStandardItem *currOption = item->child(i, 0);
    QString currOptionName = currOption->text();
    if (!currOptionName.compare(QString("Text Font")))
    {
      try
      {
        importFontProperty<view::graph::ArcOptions>(currOption, arcOptions, &view::graph::ArcOptions::setTextFont);
      }
      catch (QString& ex)
      {
        qDebug() << "Not allowed action for the category \'" << categoryName << "\' : " << ex;
      }
    }
    else if (!currOptionName.compare(QString("Text Color")))
    {
      try
      {
        importColorProperty<view::graph::ArcOptions>(item->child(i, 1), arcOptions, &view::graph::ArcOptions::setTextColor);
      }
      catch (QString& ex)
      {
        qDebug() << "Not allowed action for the category \'" << categoryName << "\' : " << ex;
      }
    }
    else if (!currOptionName.compare(QString("Line Width")))
    {
      hasPenSettings = true;
      newPen.setWidth(item->child(i, 1)->text().toInt());
    }
    else if (!currOptionName.compare(QString("Line Color")))
    {
      hasPenSettings = true;
      newPen.setColor(QColor(item->child(i, 1)->text()));
    }
    else
    {
      continue;
    }
  }

  if (hasPenSettings)
  {
    try
    {
      importPenProperty<view::graph::ArcOptions>(newPen, arcOptions, &view::graph::ArcOptions::setPen);
    }
    catch (QString& ex)
    {
      qDebug() << "Not allowed action for the category \'" << categoryName << "\' : " << ex;
    }
  }

  emit arcOptionsModified(categoryName);
}

void Settings::importMiscProperties(const QStandardItem* item)
{
  for (int i = 0; i < item->rowCount(); i++)
  {
    QString categoryName = item->child(i, 0)->text();
    try
    {
      OptionInfoSt<QVariant> *currSetting = static_cast<OptionInfoSt<QVariant>*>(findMiscSetting(categoryName));
      currSetting->infoOptions = item->child(i, 1)->text();
      currSetting->additionalInfo = item->child(i, 2)->text();
    }
    catch (ErrorReport& ex)
    {
      if (not_found == ex.type)
      {
        qDebug() << "An error occured during excuting the method \'Settings::importMiscProperties()\' : the Property \'" << ex.item << "\' is not found.";
      }
    }

    emit miscOptionsModified(categoryName);
  }
}

void Settings::importAllPropertiesFromQStandardItem(QStandardItem* itemGroup, const QString customPrefix)
{
  if (customPrefix.compare(""))
  {
    if (customPrefix.compare(itemGroup->text()))
    {
      throw ErrorReport(not_allowed, customPrefix);
    }
  }
  else
  {
    if (_settingPrefix.compare(itemGroup->text()))
    {
      throw ErrorReport(not_allowed, _settingPrefix);
    }
  }

  for (int i = 0; i < itemGroup->rowCount(); i++)
  {
    QStandardItem *currCategoryItem = itemGroup->child(i);
    QString currCategoryItemType = currCategoryItem->whatsThis();
    if (!currCategoryItemType.compare(QString("Node Options")))
    {
      try
      {
        importNodeProperties(currCategoryItem);
      }
      catch (ErrorReport& ex)
      {
        if (not_found == ex.type)
        {
          qDebug() << "An unknown error occured during excuting the method \'Settings:importNodeProperties()\' : importing " << ex.item << " options is not possible.";
        }
      }
    }
    else if (!currCategoryItemType.compare(QString("Arc Options")))
    {
      try
      {
        importArcProperties(currCategoryItem);
      }
      catch (ErrorReport& ex)
      {
        if (not_found == ex.type)
        {
          qDebug() << "An unknown error occured during excuting the method \'Settings:importArcProperties()\' : importing " << ex.item << " options is not possible.";
        }
      }
    }
    else if (!currCategoryItemType.compare(QString("Misc Options")))
    {
      importMiscProperties(currCategoryItem);
    }
    else
    {
      continue;
    }
  }

  emit optionsChanged();
}

void Settings::importAllPropertiesFromQStandardItemModel(QStandardItemModel* model, const QString customPrefix)
{
  if ((customPrefix.compare("")) || (_settingPrefix.compare("")))
  {
    bool hasItemGroup = false;
    QStandardItem *fqig;

    if (customPrefix.compare(QString("")))
    {
      for (int i = 0; i < model->rowCount(); i++)
      {
        QStandardItem *currItemGroup = model->item(i);
        if (!currItemGroup->text().compare(customPrefix))
        {
          hasItemGroup = true;
          fqig = currItemGroup;
          break;
        }
      }

      if (!hasItemGroup)
      {
        throw ErrorReport(not_found, customPrefix);
      }
    }
    else
    {
      for (int i = 0; i < model->rowCount(); i++)
      {
        QStandardItem *currItemGroup = model->item(i);
        if (!currItemGroup->text().compare(_settingPrefix))
        {
          hasItemGroup = true;
          fqig = currItemGroup;
          break;
        }
      }

      if (!hasItemGroup)
      {
        throw ErrorReport(not_found, _settingPrefix);
      }
    }

    importAllPropertiesFromQStandardItem(fqig);
    return;
  }

  for (int i = 0; i < model->rowCount(); i++)
  {
    QStandardItem *currCategoryItem = model->item(i);
    QString currCategoryItemType = currCategoryItem->whatsThis();
    if (!currCategoryItemType.compare(QString("Node Options")))
    {
      try
      {
        importNodeProperties(currCategoryItem);
      }
      catch (ErrorReport& ex)
      {
        if (not_found == ex.type)
        {
          qDebug() << "An unknown error occured during excuting the method \'Settings:importNodeProperties()\' : importing " << ex.item << " options is not possible.";
        }
      }
    }
    else if (!currCategoryItemType.compare(QString("Arc Options")))
    {
      try
      {
        importArcProperties(currCategoryItem);
      }
      catch (ErrorReport& ex)
      {
        if (not_found == ex.type)
        {
          qDebug() << "An unknown error occured during excuting the method \'Settings:importArcProperties()\' : importing " << ex.item << " options is not possible.";
        }
      }
    }
    else if (!currCategoryItemType.compare(QString("Misc Options")))
    {
      importMiscProperties(currCategoryItem);
    }
    else
    {
      continue;
    }
  }

  emit optionsChanged();
}
