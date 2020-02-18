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

#include "../../modeling_global.hpp"

#include "declmodel.hpp"

namespace model{
namespace spenat{

class MODELINGSHARED_EXPORT DeclGraphModel
    : public DeclModel
{
  Q_OBJECT

private:
  typedef DeclModel         BaseClass;

public:
  explicit DeclGraphModel(QObject *parent = 0);
  explicit DeclGraphModel(const QString& name, QObject *parent = 0);
  virtual	~DeclGraphModel();

public:
  static
  bool isValidArc(NodeItem const* sourceNode,
                  NodeItem const* targetNode,
                  QString *errorMessage);

public://virtual methods
  virtual void          reset();
  virtual void          resetGraphDecl();
  virtual JsonObjectPtr createJson() const;

public slots:
  void	addPlaceSlot(QUuid placeID,
                     const QString& placeText);
  void	addTransitionSlot(const QString& name,
                          QUuid transitionID,
                          const QString& transitionText);
  void  addJunctionSlot(const QUuid& uuid);
  bool  addArcSlot(const QString& name,
                   QUuid arcUuid,
                   QUuid sourceID,
                   QUuid targetID,
                   const QString& arcText,
                   QString* errorString);

  void changePlaceSlot(QUuid placeID,
                       const QString& placeText,
                       bool initMarking);
  void	changeTransitionSlot(QUuid transitionID,
                             const QString& transitionText);
  void	changeArcSlot(QUuid arcUuid,
                      QUuid sourceID,
                      QUuid targetID,
                      const QString& arcText);

  void	removePlaceSlot(const QUuid& placeUuid);
  void	removeTransitionSlot(QUuid transitionID);
  void	removeJunctionSlot(QUuid junctionID);
  void	removeArcSlot(QUuid arcID,
                      QUuid sourceID,
                      QUuid targetID);

private:
  Q_DISABLE_COPY(DeclGraphModel)
  class Private;
  Private*  _d;
};

typedef QSharedPointer<DeclGraphModel> DeclGraphModelPtr;

}///end namespace spenat
}///end namespace model
