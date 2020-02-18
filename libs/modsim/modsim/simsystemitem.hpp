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
#pragma once

#include "modsim_global.hpp"

#include <mobata/model/base/modelitem.hpp>
#include <mobata/prop/nameproperty.hpp>

namespace modsim{

class SimModelItem;
class SimConfigItem;
class SimConnectionItem;
class SimActorItem;

class MODSIMSHARED_EXPORT SimSystemItem :
    public model::base::ModelItem,
    public prop::NameProperty
{
public:
  SimSystemItem();
  ~SimSystemItem();

  QList<SimModelItem*>      simModelItems();
  QList<SimConnectionItem*> simConnnetionItems();
  SimConfigItem*            simConfigItem();

  void                      addSimModelItem(SimModelItem* item);
  void                      addSimConnnetionItem(SimConnectionItem* item);

private:
  class Private;
  Private* _d;
};

}//namespace modsim
