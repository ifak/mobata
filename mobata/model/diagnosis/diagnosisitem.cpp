#include "diagnosisitem.hpp"
#include "diagcomponentitem.hpp"
#include "model/base/basemodel.hpp"
#include "../../memory_leak_start.hpp"

#include "../../memory_leak_start.hpp"

namespace model{
namespace diagnosis{

class DiagnosisItem::Private
{
  friend class DiagnosisItem;
  QList<base::ModelItem *> _rules;
  QList<DiagnosisItem *> _imports;
  QList<DiagComponentItem*> _components;
  //QStandardItem _importsItem;
  //QStandardItem _rulesItem;
  //QStandardItem _componentsItem;
  Private()
  {}

  ~Private()  {

      for(auto * rule : _rules){
          delete(rule);
      }
      _rules.clear();

      for(DiagnosisItem * import : _imports){
          delete(import);
      }
      _imports.clear();

      for(auto comp : _components){
          delete(comp);
      }
      _components.clear();
  }
};

DiagnosisItem::DiagnosisItem(const QString name)
  : ModelItem(),
    PropDataTypes(this),
    PropAttributes(this),
    PropSignals(this),
    NameProperty(name),
    _d(new Private)
{

  //this->setDataTypesParentItem(this->invisibleRootItem());
  //this->setAttributesParentItem(this->invisibleRootItem());
  //this->setSignalsParentItem(this->invisibleRootItem());

  this->setName(name);
  this->setText(name);

//  _d->_importsItem.setText(QString("imports"));
//  _d->_componentsItem.setText(QString("components"));
//  _d->_rulesItem.setText(QString("rules"));

//  for(auto item : _d->_imports) _d->_importsItem.appendRow(item);
//  for(auto item : _d->_components) _d->_componentsItem.appendRow(item);
//  for(auto item : _d->_rules) _d->_rulesItem.appendRow(item);

//  this->appendRow(&_d->_importsItem);
//  this->appendRow(&_d->_componentsItem);
//  this->appendRow(&_d->_rulesItem);

  //this->setHeaderData(0, Qt::Horizontal, this->name(), Qt::DisplayRole);
}

DiagnosisItem::~DiagnosisItem()
{
  delete(_d);
}

void DiagnosisItem::reset()
{
  for(auto * rule : _d->_rules){
    delete(rule);
  }
  _d->_rules.clear();
  //_d->_rulesItem.removeRows(0,_d->_rulesItem.rowCount());

  for(DiagnosisItem * import : _d->_imports){
    delete(import);
  }
  _d->_imports.clear();
  //_d->_importsItem.removeRows(0,_d->_importsItem.rowCount());

  for(auto comp : _d->_components){
    delete(comp);
  }
  _d->_components.clear();
  //_d->_componentsItem.removeRows(0,_d->_componentsItem.rowCount());

  return;
}

const QList<base::ModelItem*>& DiagnosisItem::rules()
{
  return _d->_rules;
}

void DiagnosisItem::addRule(base::ModelItem *rule)
{
  _d->_rules.append(rule);
  //_d->_rulesItem.appendRow(rule);
}

const QList<DiagnosisItem*>& DiagnosisItem::importItems()
{
  return _d->_imports;
}

void DiagnosisItem::addImportItem(DiagnosisItem *item)
{
  _d->_imports.append(item);
  //_d->_importsItem.appendRow(item);
}

void DiagnosisItem::addComponent(DiagComponentItem *item)
{
  _d->_components.append(item);
  //_d->_componentsItem.appendRow(item);
}

const QList<DiagComponentItem*>& DiagnosisItem::components()
{
  return _d->_components;
}

}/// end namespace ts
}/// end namespace model
