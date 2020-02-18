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
#ifndef MODEL_SPENAT_JUNCTIONITEM_HPP
#define MODEL_SPENAT_JUNCTIONITEM_HPP

#include "../../mobata_global.hpp"

#include "../graph/nodeitem.hpp"

namespace model{
namespace spenat{

class PlaceItem;
class JunctionArc;
class JunctionArc;

class MOBATASHARED_EXPORT JunctionItem
    : public graph::NodeItem
{
public:
  typedef QList<JunctionArc const*>  ConstJunctionSourceSet;
  typedef QList<JunctionArc*>        JunctionSourceSet;
  typedef QList<JunctionArc const*>  ConstJunctionTargetSet;
  typedef QList<JunctionArc*>        JunctionTargetSet;

public:
  JunctionItem(const QUuid& uuid=QUuid::createUuid());
  virtual ~JunctionItem();

public:
  JunctionArc*            addSource(NodeItem* sourceNode);
  JunctionArc const*      source(const NodeItem* sourceNode) const;
  JunctionArc const*      sourceArc(const QUuid& arcUuid) const;
  JunctionSourceSet       sources();
  ConstJunctionSourceSet  sources() const;
  void                    removeSource(NodeItem const* sourceNode);

  JunctionArc*            addTarget(NodeItem* targetNode);
  JunctionArc const*      target(const NodeItem* targetNode) const;
  JunctionArc const*      targetArc(const QUuid& arcUuid) const;
  ConstJunctionTargetSet  targets() const;
  JunctionTargetSet       targets();
  void                    removeTarget(NodeItem const* targetNode);

  void                    updateText();
  QString                 toString() const;

protected:
  void build();

private:
  Q_DISABLE_COPY(JunctionItem)
  class Private;
  QScopedPointer<Private>	_d;
};

}//////end namespace spenat
}///end namespace model

#endif // MODEL_SPENAT_JUNCTIONITEM_HPP
