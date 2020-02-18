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
#ifndef VIEW_SPENAT_DECLSCENE_HPP
#define VIEW_SPENAT_DECLSCENE_HPP

#include "../mobatawidgets_global.hpp"

#include "types.hpp"

#include "spenatscene.hpp"

#include <QUuid>

namespace view{
namespace spenat{

class DeclJunction;

class MOBATAWIDGETSSHARED_EXPORT DeclScene
    : public SpenatScene
{
	Q_OBJECT
	
public:
	DeclScene(QObject *parent = 0);
	virtual ~DeclScene();

signals:
	void junctionAdded(QUuid junctionUuid);
	void junctionRemoved(QUuid junctionID);
	
public:
  virtual bool  isValidArc(graph::AbstractNode const* sourceNode, 
                           graph::AbstractNode const* targetNode, 
                           QString *errorMessage) const;
  virtual void  removeGraphItem(QGraphicsItem* graphItem);
  
public:
  DeclJunction*               junction(QUuid junctionUuid);
  DeclJunction const*         junction(QUuid junctionUuid) const;
  QList<DeclJunction const*>  junctions() const;
  QList<DeclJunction*>        junctions();
  
public:
	DeclJunction* addJunction(QPointF pos,
                            QUuid junctionUuid=QUuid::createUuid());
  void          removeJunction(const QUuid& junctionUuid);
  void          removeJunction(DeclJunction* junction);
  
public:
  virtual graph::AbstractNode const*  node(const QUuid& nodeUuid) const;
  virtual graph::AbstractNode *       node(const QUuid& nodeUuid);
  virtual ConstNodeSet                nodes() const;
  virtual NodeSet                     nodes();

private:
	class Private;
	Private* _d;
};

}/// namespace spenat
}/// namespace view

#endif
