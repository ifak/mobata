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

namespace rhapsody{

  QString elementName(const IRPModelElementPtr& element,
                      QString *errorMessage);

  QString elementInterface(const IRPModelElementPtr& element,
                      QString *errorMessage);

  QString stateType(const IRPStatePtr& state,
                    QString *errorMessage);

  IRPModelElementPtr findModelElement(const QString& elementName,
                                      const IRPCollectionPtr& elementCollection,
                                      QString *errorMessage);

  bool containsPathElements(const QList<QString>& pathList,
                            const IRPModelElementPtr& element,
                            QString* errorMessage);

  QString bstrConvert(const BSTR &string);

  bool hasAction(const IRPTransitionPtr& transition,
                 QString* errorMessage);

  void replaceParams(QString& string);

} //rhapsody

#include "importrhapsodyutils.inl"
