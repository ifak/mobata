/*
 * This file is part of mobata.
 *
 * mobata is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * mobata is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License
 * along with mobata.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef SETTINGS_HPP
#define SETTINGS_HPP

template <typename P, typename T> void setProperty(const P& property, T& (T:: *setDelegate)(const P&), T* targetOptions)
{
    try
    {
        (targetOptions->*setDelegate)(property);
    }
    catch (QString& ex)
    {
        qDebug() << ex;
    }
    catch (...)
    {
        throw;
    }
}

template <typename T> void* Settings::findSettings(const QString categoryName,
                                                   const QList<OptionInfoSt<T> >& container) const
{
    OptionInfoSt<T> *targetSettings = 0;
    bool hasCategory = false;

    foreach (const OptionInfoSt<T> &currInfo, container)
    {
        if (!currInfo.infoName.compare(categoryName))
        {
            targetSettings = (const_cast<OptionInfoSt<T>*>(&currInfo));
            hasCategory = true;
            break;
        }
    }

    if (!hasCategory)
    {
        throw ErrorReport(not_found, categoryName);
    }

    return static_cast<void*>(targetSettings);
}

template <typename T> void Settings::addSettings(const QString categoryName, const T& defaultOptions, const QString additionalInfo, QList<OptionInfoSt<T> >& container)
{
    container.append(OptionInfoSt<T>(categoryName, defaultOptions, additionalInfo));
}

template <typename T> int Settings::removeSettings(const QString categoryName, QList<OptionInfoSt<T> >& container)
{
    int currIndex = -1;
    bool hasCategory = false;

    foreach (const OptionInfoSt<T> &currInfo, container)
    {
        currIndex++;
        if (!currInfo.infoName.compare(categoryName))
        {
            hasCategory = true;
            break;
        }
    }

    if (!hasCategory)
    {
        throw ErrorReport(not_found, categoryName);
    }

    container.removeAt(currIndex);

    return currIndex;
}

template <typename T> void Settings::replaceOptions(const QString categoryName, const T& options, QList<OptionInfoSt<T> >& container)
{
    int replacingIndex = removeSettings<T>(categoryName, container);
    container.insert(replacingIndex, OptionInfoSt<T>(categoryName, options));
}

template <typename T> void Settings::setOptions(const QString categoryName, const T& options, void (*setOptionsDelegate)(const T&, T*), QList<OptionInfoSt<T> >& container)
{
    T *targetOption = findOptions<T>(categoryName, container);
    setOptionsDelegate(options, targetOption);
}

template <typename T> int Settings::readPenSettingFromConfigFile(T* targetOptions, T& (T:: *setDelegate)(const QPen&))
{
    int incompleteSubItemCount = 0;

    QPen currentPen(targetOptions->pen());
    if (!_configs->contains("color"))
    {
        currentPen.setColor(targetOptions->pen().brush().color());
        incompleteSubItemCount++;
    }
    else
    {
        currentPen.setColor(QString(_configs->value("color").toString()));
    }

    if (!_configs->contains("width"))
    {
        currentPen.setWidth(targetOptions->pen().width());
        incompleteSubItemCount++;
    }
    else
    {
        currentPen.setWidth(_configs->value("width").toInt());
    }

    (targetOptions->*setDelegate)(currentPen);

    return incompleteSubItemCount;
}

template <typename T> int Settings::readColorSettingFromConfigFile(T* targetOptions, T& (T:: *setDelegate)(const QColor&))
{
    int incompleteSubItemCount = 0;

    if (!_configs->contains("color"))
    {
        incompleteSubItemCount++;
    }
    else
    {
        (targetOptions->*setDelegate)(QColor(_configs->value("color").toString()));
    }

    return incompleteSubItemCount;
}

template <typename T> int Settings::readSizeSettingFromConfigFile(T* targetOptions, T& (T:: *setDelegate)(const QSizeF&))
{
    int incompleteSubItemCount = 0;

    QSizeF currentBoxSize(targetOptions->size());
    if (!_configs->contains("width"))
    {
        currentBoxSize.setWidth(targetOptions->size().width());
        incompleteSubItemCount++;
    }
    else
    {
        currentBoxSize.setWidth(_configs->value("width").toDouble());
    }

    if (!_configs->contains("height"))
    {
        currentBoxSize.setHeight(targetOptions->size().height());
        incompleteSubItemCount++;
    }
    else
    {
        currentBoxSize.setHeight(_configs->value("height").toDouble());
    }

    (targetOptions->*setDelegate)(currentBoxSize);

    return incompleteSubItemCount;
}

template <typename T> int Settings::readFontSettingFromConfigFile(T* targetOptions, T& (T:: *setDelegate)(const QFont&))
{
    int incompleteSubItemCount = 0;

    QFont currentFont(targetOptions->textFont());
    if (!_configs->contains("series"))
    {
        currentFont.setFamily(targetOptions->textFont().family());
        incompleteSubItemCount++;
    }
    else
    {
        currentFont.setFamily(_configs->value("series").toString());
    }

    if (!_configs->contains("size"))
    {
        currentFont.setPointSize(targetOptions->textFont().pointSize());
        incompleteSubItemCount++;
    }
    else
    {
        currentFont.setPointSize(_configs->value("size").toInt());
    }

    if (!_configs->contains("bold"))
    {
        currentFont.setBold(targetOptions->textFont().bold());
        incompleteSubItemCount++;
    }
    else
    {
        currentFont.setBold(_configs->value("bold").toBool());
    }

    if (!_configs->contains("italic"))
    {
        currentFont.setItalic(targetOptions->textFont().italic());
        incompleteSubItemCount++;
    }
    else
    {
        currentFont.setItalic(_configs->value("italic").toBool());
    }

    (targetOptions->*setDelegate)(currentFont);

    return incompleteSubItemCount;
}

template <typename T> void Settings::writePenSettingsToConfigFile(T* sourceOptions, QPen (T:: *getDelegate)() const)
{
    QPen currentPen((sourceOptions->*getDelegate)());
    _configs->setValue("color", currentPen.brush().color().name());
    _configs->setValue("width", currentPen.width());
}

template <typename T> void Settings::writeColorSettingsToConfigFile(T* sourceOptions, QColor (T:: *getDelegate)() const)
{
    QColor currentColor((sourceOptions->*getDelegate)());
    _configs->setValue("color", currentColor.name());
}

template <typename T> void Settings::writeSizeSettingsToConfigFile(T* sourceOptions, QSizeF (T:: *getDelegate)() const)
{
    QSizeF currentSize((sourceOptions->*getDelegate)());
    _configs->setValue("width", currentSize.width());
    _configs->setValue("height", currentSize.height());
}

template <typename T> void Settings::writeFontSettingsToConfigFile(T* sourceOptions, QFont (T:: *getDelegate)() const)
{
    QFont currentFont((sourceOptions->*getDelegate)());
    _configs->setValue("series", currentFont.family());
    _configs->setValue("size", currentFont.pointSize());
    _configs->setValue("bold", currentFont.bold());
    _configs->setValue("italic", currentFont.italic());
}

template <typename T> QList<QList<QStandardItem*> > Settings::exportPenProperty(QString title, T* sourceOptions, QPen (T:: *getDelegate)() const) const
{
    QList<QList<QStandardItem*> > penConfigList;
    QPen currentPen((sourceOptions->*getDelegate)());

    QList<QStandardItem*> penWidthConfigList;
    QStandardItem* penWidth = new QStandardItem(QString("%1 Width").arg(title));
    penWidth->setEditable(false);
    penWidthConfigList.append(penWidth);
    QStandardItem* penWidthValue = new QStandardItem(QString::number(currentPen.width()));
    penWidthConfigList.append(penWidthValue);
    QStandardItem* penWidthChar = new QStandardItem(QString("LENGTH"));
    penWidthChar->setEditable(false);
    penWidthConfigList.append(penWidthChar);
    penConfigList.append(penWidthConfigList);

    QList<QStandardItem*> penColorConfigList;
    QStandardItem* penColor = new QStandardItem(QString("%1 Color").arg(title));
    penColor->setEditable(false);
    penColorConfigList.append(penColor);
    QStandardItem* penColorValue = new QStandardItem(currentPen.brush().color().name());
    penColorConfigList.append(penColorValue);
    QStandardItem* penColorChar = new QStandardItem(QString("COLOR"));
    penColorChar->setEditable(false);
    penColorConfigList.append(penColorChar);
    penConfigList.append(penColorConfigList);

    return penConfigList;
}

template <typename T> QList<QStandardItem*> Settings::exportColorProperty(QString title, T* sourceOptions, QColor (T:: *getDelegate)() const) const
{
    QList<QStandardItem*> colorConfigList;

    QStandardItem* itemColor = new QStandardItem(title);
    itemColor->setEditable(false);
    colorConfigList.append(itemColor);

    QStandardItem* itemColorValue = new QStandardItem((sourceOptions->*getDelegate)().name());
    colorConfigList.append(itemColorValue);
    QStandardItem* itemColorChar = new QStandardItem(QString("COLOR"));
    itemColorChar->setEditable(false);
    colorConfigList.append(itemColorChar);

    return colorConfigList;
}

template <typename T> QList<QStandardItem*> Settings::exportSizeProperty(QString title, T* sourceOptions, QSizeF (T:: *getDelegate)() const) const
{
    QList<QStandardItem*> sizeConfigList;

    QStandardItem* itemSize = new QStandardItem(title);
    itemSize->setEditable(false);
    sizeConfigList.append(itemSize);

    QSizeF currentSize((sourceOptions->*getDelegate)());
    QList<QStandardItem*> itemSizeWConfigList;
    QStandardItem* itemSizeW = new QStandardItem(QString("Width"));
    itemSizeW->setEditable(false);
    itemSizeWConfigList.append(itemSizeW);
    QStandardItem* itemSizeWValue = new QStandardItem(QString::number(currentSize.width()));
    itemSizeWConfigList.append(itemSizeWValue);
    QStandardItem* itemSizeWChar = new QStandardItem(QString("LENGTH"));
    itemSizeWChar->setEditable(false);
    itemSizeWConfigList.append(itemSizeWChar);
    itemSize->appendRow(itemSizeWConfigList);
    QList<QStandardItem*> itemSizeHConfigList;
    QStandardItem* itemSizeH = new QStandardItem(QString("Height"));
    itemSizeH->setEditable(false);
    itemSizeHConfigList.append(itemSizeH);
    QStandardItem* itemSizeHValue = new QStandardItem(QString::number(currentSize.height()));
    itemSizeHConfigList.append(itemSizeHValue);
    QStandardItem* itemSizeHChar = new QStandardItem(QString("LENGTH"));
    itemSizeHChar->setEditable(false);
    itemSizeHConfigList.append(itemSizeHChar);
    itemSize->appendRow(itemSizeHConfigList);

    QStandardItem* itemSizeValue = new QStandardItem(QString(""));
    itemSizeValue->setEditable(false);
    sizeConfigList.append(itemSizeValue);
    QStandardItem* itemSizeChar = new QStandardItem(QString("INFO"));
    itemSizeChar->setEditable(false);
    sizeConfigList.append(itemSizeChar);

    return sizeConfigList;
}

template <typename T> QList<QStandardItem*> Settings::exportFontProperty(QString title, T* sourceOptions, QFont (T:: *getDelegate)() const) const
{
    QList<QStandardItem*> fontConfigList;

    QStandardItem* itemFont = new QStandardItem(title);
    itemFont->setEditable(false);
    fontConfigList.append(itemFont);

    QFont currentFont((sourceOptions->*getDelegate)());
    QList<QStandardItem*> itemFontSeriesConfigList;
    QStandardItem* itemFontSeries = new QStandardItem(QString("Series"));
    itemFontSeries->setEditable(false);
    itemFontSeriesConfigList.append(itemFontSeries);
    QStandardItem* itemFontSeriesValue = new QStandardItem(currentFont.family());
    itemFontSeriesConfigList.append(itemFontSeriesValue);
    QStandardItem* itemFontSeriesChar = new QStandardItem(QString("FONT"));
    itemFontSeriesChar->setEditable(false);
    itemFontSeriesConfigList.append(itemFontSeriesChar);
    itemFont->appendRow(itemFontSeriesConfigList);
    QList<QStandardItem*> itemFontSizeConfigList;
    QStandardItem* itemFontSize = new QStandardItem(QString("Size"));
    itemFontSize->setEditable(false);
    itemFontSizeConfigList.append(itemFontSize);
    QStandardItem* itemFontSizeValue = new QStandardItem(QString::number(currentFont.pointSize()));
    itemFontSizeConfigList.append(itemFontSizeValue);
    QStandardItem* itemFontSizeChar = new QStandardItem(QString("FONTSIZE"));
    itemFontSizeChar->setEditable(false);
    itemFontSizeConfigList.append(itemFontSizeChar);
    itemFont->appendRow(itemFontSizeConfigList);
    QList<QStandardItem*> itemFontBoldOptionConfigList;
    QStandardItem* itemFontBoldOption = new QStandardItem(QString("Bold"));
    itemFontBoldOption->setEditable(false);
    itemFontBoldOptionConfigList.append(itemFontBoldOption);
    QStandardItem* itemFontBoldOptionValue = new QStandardItem(QString((currentFont.bold())?("true"):("false")));
    itemFontBoldOptionConfigList.append(itemFontBoldOptionValue);
    QStandardItem* itemFontBoldOptionChar = new QStandardItem(QString("BOOLEANOPTION"));
    itemFontBoldOptionChar->setEditable(false);
    itemFontBoldOptionConfigList.append(itemFontBoldOptionChar);
    itemFont->appendRow(itemFontBoldOptionConfigList);
    QList<QStandardItem*> itemFontItalicOptionConfigList;
    QStandardItem* itemFontItalicOption = new QStandardItem(QString("Italic"));
    itemFontItalicOption->setEditable(false);
    itemFontItalicOptionConfigList.append(itemFontItalicOption);
    QStandardItem* itemFontItalicOptionValue = new QStandardItem(QString((currentFont.italic())?("true"):("false")));
    itemFontItalicOptionConfigList.append(itemFontItalicOptionValue);
    QStandardItem* itemFontItalicOptionChar = new QStandardItem(QString("BOOLEANOPTION"));
    itemFontItalicOptionChar->setEditable(false);
    itemFontItalicOptionConfigList.append(itemFontItalicOptionChar);
    itemFont->appendRow(itemFontItalicOptionConfigList);

    QStandardItem* itemFontValue = new QStandardItem(QString(""));
    fontConfigList.append(itemFontValue);
    QStandardItem* itemFontChar = new QStandardItem(QString("INFO"));
    itemFontChar->setEditable(false);
    fontConfigList.append(itemFontChar);

    return fontConfigList;
}

template <typename T> void Settings::importPenProperty(const QPen& pen, T* targetOptions, T& (T:: *setDelegate)(const QPen&))
{
    (targetOptions->*setDelegate)(pen);
}

template <typename T> void Settings::importColorProperty(const QStandardItem* item, T* targetOptions, T& (T:: *setDelegate)(const QColor&))
{
    (targetOptions->*setDelegate)(QColor(item->text()));
}

template <typename T> void Settings::importSizeProperty(const QStandardItem* item, T* targetOptions, T& (T:: *setDelegate)(const QSizeF&))
{
    QSizeF newBoxSize(targetOptions->size());
    for (int i = 0; i < item->rowCount(); i++)
    {
        QString subOptionName = item->child(i, 0)->text();
        if (!subOptionName.compare(QString("Width")))
        {
            newBoxSize.setWidth(item->child(i, 1)->text().toDouble());
        }
        else if (!subOptionName.compare(QString("Height")))
        {
            newBoxSize.setHeight(item->child(i, 1)->text().toDouble());
        }
        else
        {
            continue;
        }
    }

    (targetOptions->*setDelegate)(newBoxSize);
}

template <typename T> void Settings::importFontProperty(const QStandardItem* item, T* targetOptions, T& (T:: *setDelegate)(const QFont&))
{
    QFont newFont(targetOptions->textFont());
    for (int i = 0; i < item->rowCount(); i++)
    {
        QString subOptionName = item->child(i, 0)->text();
        if (!subOptionName.compare(QString("Series")))
        {
            newFont.setFamily(item->child(i, 1)->text());
        }
        else if (!subOptionName.compare(QString("Size")))
        {
            newFont.setPointSize(item->child(i, 1)->text().toInt());
        }
        else if (!subOptionName.compare(QString("Bold")))
        {
            newFont.setBold((item->child(i, 1)->text().compare(QString("true")))?(false):(true));
        }
        else if (!subOptionName.compare(QString("Italic")))
        {
            newFont.setItalic((item->child(i, 1)->text().compare(QString("true")))?(false):(true));
        }
        else
        {
            continue;
        }
    }

    (targetOptions->*setDelegate)(newFont);
}

#endif // SETTINGS_HPP
