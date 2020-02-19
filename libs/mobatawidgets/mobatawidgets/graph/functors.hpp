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
#ifndef VIEW_GRAPH_FUNCTORS_HPP
#define VIEW_GRAPH_FUNCTORS_HPP

#include <QGraphicsScene>
#include <QTextCursor>

#include "abstractnode.hpp"
#include "edge.hpp"

#include "../base/functors.hpp"

namespace view{
namespace graph{

using base::makeRectPath;
using base::calcIntercectPoint;

template<class ControlPointSet>
static inline
void makeNiceArcControlPoints(ControlPointSet* controlPoints, int offset=10)
{
  if(!controlPoints)
    return;

  typedef typename ControlPointSet::value_type	ControlPoint;

  ControlPoint currentPoint;
  int pos=0;
  foreach(ControlPoint controlPoint, controlPoints)
  {
    if(!pos)
    {
      currentPoint=controlPoint;
      continue;
    }

    qreal pos_x=controlPoint->pos().x();
    qreal pos_y=controlPoint->pos().y();

    if(qAbs(currentPoint->pos().x()-pos_x)<=offset)
      pos_x=currentPoint->pos().x();
    if(qAbs(currentPoint->pos().y-pos_y)<=offset)
      pos_y=currentPoint->pos().y();

    controlPoint->setPos(pos_x, pos_y);

    currentPoint=controlPoint;
    ++pos;
  }

  return;
}

template<class GraphSceneItem>
QList<GraphSceneItem*>	graphSceneItems(QGraphicsScene const* graphicsScene)
{
  Q_ASSERT(graphicsScene);

  QList<GraphSceneItem*> graphSceneItems;

  foreach (QGraphicsItem* graphicsItem, graphicsScene->items())
    if(GraphSceneItem* graphSceneItem=qgraphicsitem_cast<GraphSceneItem*>(graphicsItem))
      graphSceneItems.push_back(graphSceneItem);

  return graphSceneItems;
}

template<class GraphSceneItem, class Collection>
Collection	graphSceneItems(QGraphicsScene const* graphicsScene)
{
  Q_ASSERT(graphicsScene);

  Collection graphSceneItems;

  foreach (QGraphicsItem* graphicsItem, graphicsScene->items())
    if(GraphSceneItem* graphSceneItem=qgraphicsitem_cast<GraphSceneItem*>(graphicsItem))
      graphSceneItems.push_back(graphSceneItem);

  return graphSceneItems;
}

template<class GraphSceneItem>
GraphSceneItem*	graphSceneItem(const QUuid& itemUuid,
                               QGraphicsScene const* graphicsScene)
{
  Q_ASSERT(graphicsScene);

  foreach (GraphSceneItem* graphSceneItem,
           graphSceneItems<GraphSceneItem>(graphicsScene))
    if(graphSceneItem->uuid()==itemUuid)
      return graphSceneItem;

  return 0;
}

///helper methods////////////
inline AbstractNode* getNode(QGraphicsItem* pointItem)
{
  if(!pointItem)
    return 0;

  graph::AbstractNode* node=0;

  if((node=dynamic_cast<AbstractNode*>(pointItem)))
    return node;
  else if((node=dynamic_cast<AbstractNode*>(pointItem->parentItem())))
    return node;

  return 0;
}

inline AbstractNode* getNode(QList<QGraphicsItem*> itemList)
{
  if(!itemList.length())
    return 0;

  graph::AbstractNode* node = 0;

  for(int i = 0; i < itemList.length(); i++){
    if((node=dynamic_cast<graph::AbstractNode*>(itemList.at(i))))
      return node;
    else if((node=dynamic_cast<graph::AbstractNode*>(itemList.at(i)->parentItem())))
      return node;
  }

  return 0;
}

inline Edge* getEdge(QGraphicsItem* pointItem)
{
  if(!pointItem)
    return 0;

  Edge *edge = 0;

  if((edge = dynamic_cast<Edge*>(pointItem)))
    return edge;
  else if((edge = dynamic_cast<Edge*>(pointItem->parentItem())))
    return edge;

  return 0;
}
template<class NotationItem>
void setFocus(NotationItem* notationItem, const bool underline=false)
{
  Q_ASSERT(notationItem);

  notationItem->setSelected(true);
  notationItem->setFocus();
  QTextCursor tc=notationItem->textCursor();
  tc.select(QTextCursor::Document);
  if(underline)
  {
    QTextCharFormat tFormat=tc.charFormat();
    tFormat.setFontUnderline(true);
    tFormat.setUnderlineColor(Qt::darkRed);
    tFormat.setUnderlineStyle(QTextCharFormat::WaveUnderline);
    tc.mergeCharFormat(tFormat);
  }
  notationItem->setTextCursor(tc);

  return;
}

}///end namespace graph
}//end namespace view

#endif // VIEW_GRAPH_FUNCTORS_HPP
