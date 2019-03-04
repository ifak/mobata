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
