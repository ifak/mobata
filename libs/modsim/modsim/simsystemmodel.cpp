#include "simsystemmodel.hpp"
#include "simsystemitem.hpp"

namespace modsim{

class SimSystemModel::Private{
  friend class SimSystemModel;

  SimSystemItem* _simSysItem = nullptr;

  Private(){
  }
};

SimSystemModel::SimSystemModel():
  model::base::BaseModel(),
  _d(new Private())
{
  SimSystemItem* item = new SimSystemItem;
  appendRow(item);
  _d->_simSysItem = item;
}

SimSystemModel::~SimSystemModel()
{
  delete _d;
}

SimSystemItem *SimSystemModel::simSystemItem()
{
  return _d->_simSysItem;
}

void SimSystemModel::setSimSystemItem(SimSystemItem *item)
{
  removeRows(0,rowCount());
  appendRow(item);
  _d->_simSysItem = item;
}

void SimSystemModel::resetModel()
{
  SimSystemItem* item = new SimSystemItem;
  removeRows(0,rowCount());
  appendRow(item);
  _d->_simSysItem = item;
}

}//namespace modsim
