#include "simsystemitem.hpp"
#include "simsystemitem.hpp"
#include "simmodelitem.hpp"
#include "simconnectionitem.hpp"
#include "simconfigitem.hpp"

namespace modsim{

class SimSystemItem::Private{
  friend class SimSystemItem;

  QList<SimModelItem*>      _simModelItems;
  QList<SimConnectionItem*> _simConnectionItems;
  SimConfigItem*            _simConfigItem;

  QStandardItem*            _simModels;
  QStandardItem*            _simConnections;

  Private(){
    _simModelItems =      QList<SimModelItem*>();
    _simConnectionItems = QList<SimConnectionItem*>();
    _simModels      = new QStandardItem;
    _simConnections = new QStandardItem;
  }
};

SimSystemItem::SimSystemItem():
  model::base::ModelItem(),
  prop::NameProperty(),
  _d(new Private())
{
  SimConfigItem* item = new SimConfigItem();
  appendRow(item);
  _d->_simConfigItem = item;
  appendRow(_d->_simModels);
  appendRow(_d->_simConnections);
  _d->_simConnections->setText(QString("connections"));
  _d->_simModels->setText(QString("models"));
}

SimSystemItem::~SimSystemItem()
{
  delete _d;
}

QList<SimModelItem *> SimSystemItem::simModelItems()
{
  return _d->_simModelItems;
}

QList<SimConnectionItem *> SimSystemItem::simConnnetionItems()
{
  return _d->_simConnectionItems;
}

SimConfigItem *SimSystemItem::simConfigItem()
{
  return _d->_simConfigItem;
}

void SimSystemItem::addSimModelItem(SimModelItem *item)
{
  _d->_simModels->appendRow(item);
  _d->_simModelItems.append(item);
}

void SimSystemItem::addSimConnnetionItem(SimConnectionItem *item)
{
  _d->_simConnections->appendRow(item);
  _d->_simConnectionItems.append(item);
}

}//namespace modsim
