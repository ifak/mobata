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
