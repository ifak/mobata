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

#include "importrhapsody_global.hpp"
#include <mobata/model/statemachine/types.hpp>

namespace model{
namespace base{
class ModelItem;
}
}

namespace rhapsody {

class ImportRhapsodyLayout {

public:

  ImportRhapsodyLayout();

  virtual ~ImportRhapsodyLayout();

  template<class RhapsodyPtr>
  void importStateLayout(model::base::ModelItem* item,
                         const RhapsodyPtr& state,
                         bool isNewInit,
                         QString* errorMessage);

  bool importTransitionLayout(model::base::ModelItem* transitionItem,
                              const IRPTransitionPtr rhapsodyTransition,
                              QString* errorMessage);

  void importRegionLayout(model::statemachine::RegionItem* regionItem,
                          const IRPStatePtr rhapsodyState,
                          const model::statemachine::ConcurrentStateItem* concurrent,
                          int totalRegions,
                          int currentRegion,
                          QString* errorMessage);

private:

  QString graphPropertyValue(const IRPGraphElementPtr &graphElement,
                             const QString& propertyKey,
                             QString* errorMessage);

  IRPGraphElementPtr transitionGraphElement(const IRPTransitionPtr transition,
                                            QString* errorMessage);

  void importPolygon(model::base::ModelItem *item,
                     const IRPGraphElementPtr& graphElement,
                     QString* errorMessage);

  void importPosition(model::base::ModelItem* item,
                      const IRPGraphElementPtr& graphElement,
                      QString propertyKey,
                      int positionRole,
                      QString* errorMessage);

  void importSize(model::base::ModelItem* item,
                  const IRPGraphElementPtr &graphElement,
                  bool isNewInit,
                  QString* errorMessage);

  void importGenericProperty(model::base::ModelItem* item,
                             const IRPGraphElementPtr &graphElement,
                             QString propertyKey,
                             int role,
                             QString type,
                             QString* errorMessage);

  void importColor(model::base::ModelItem* item,
                   const IRPGraphElementPtr &graphElement,
                   QString propertyKey,
                   int role,
                   QString* errorMessage);

  //template methods
  template<class RhapsodyPtr>
  IRPGraphElementPtr stateGraphElement(const RhapsodyPtr& state,
                                       bool isNewInit,
                                       QString* errorMessage);
};

} //rhapsody

#include "importrhapsodylayout.inl"
