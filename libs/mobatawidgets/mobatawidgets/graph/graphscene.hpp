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
#ifndef VIEW_GRAPH_GRAPHSCENE_HPP
#define VIEW_GRAPH_GRAPHSCENE_HPP

#include "../mobatawidgets_global.hpp"

#include <QGraphicsScene>

namespace view{
namespace graph{

class AbstractNode;
class Edge;

class MOBATAWIDGETSSHARED_EXPORT GraphScene
    : public QGraphicsScene
{
	Q_OBJECT

public:
  typedef QList<AbstractNode const*>  ConstNodeSet;
  typedef QList<AbstractNode*>        NodeSet;
  typedef QList<Edge const*>          ConstEdgeSet;
  typedef QList<Edge*>                EdgeSet;

public:
	GraphScene(QObject* parent = 0);
	virtual	~GraphScene();
  
signals:
  void graphModified(const bool);
  
public:
  virtual void                removeGraphItem(QGraphicsItem* graphItem);

  virtual AbstractNode const* node(const QUuid& nodeUuid) const;
  virtual AbstractNode*       node(const QUuid& nodeUuid);
  virtual ConstNodeSet        nodes() const;
  virtual NodeSet             nodes();
  virtual void                removeNode(AbstractNode* node);
  
  virtual Edge const*   edge(const QUuid& edgeUuid) const;
  virtual Edge*         edge(const QUuid& edgeUuid);
  virtual ConstEdgeSet  edges() const;
  virtual EdgeSet       edges();
	virtual void          removeEdge(Edge* edge);

public:
  const QString&  name() const;
  void            setName(const QString &name);
	QPointF         onGrid(QPointF pos);
	void            setGrid(qreal newGrid);

protected slots:
	void exportGraphicSlot();
	void selectionChangedSlot();

protected:
	void contextMenuEvent(QGraphicsSceneContextMenuEvent* contextMenuEvent);
	
private:
	class Private;
	Private* _d;
};

}//////end namespace graph
}//end namespace view

#endif //VIEW_GRAPH_GRAPHSCENE_HPP
