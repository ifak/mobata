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

#include "comcreatesutgraph.hpp"

#include "layoutnode.hpp"
#include "layoutedge.hpp"

using namespace graphlayout;
using namespace model::ts;
using namespace model::base;

ComCreateSutGraph::ComCreateSutGraph(LayoutGraph* graph, SutItem* sutItem)
  :_graph(graph),_sutItem(sutItem)
{
}

void ComCreateSutGraph::setSutComponentColor(const QColor& color){
  this->_sutComponentColor=color;
}

void ComCreateSutGraph::setSutPortColor(const QColor& color){
  this->_sutPortColor=color;
}

const QColor& ComCreateSutGraph::sutComponentColor(){
  return this->_sutComponentColor;
}

const QColor& ComCreateSutGraph::sutPortColor(){
  return this->_sutPortColor;
}

void ComCreateSutGraph::execute(){
  _graph->clearGraph();
  _graph->setOverlap(default0);
  _graph->setSplines(ortho);
  _graph->setName(_sutItem->name());
  for(ComponentItem* item :  _sutItem->components()) {
    LayoutNode* node = _graph->addNode();
    node->setName(item->toString());
    node->setUuid(item->uuid());
    node->setShape(Rect);
    node->setColor(_sutComponentColor);
    node->setExternUuid(item->uuid());
    node->setXLabel(item->text());
    for(PortItem* port: item->ports()){
      LayoutNodePort* portNode = node->addPort();
      portNode->setName(port->name());
      portNode->setShape(Square);
      portNode->setColor(_sutPortColor);
      portNode->setUuid(port->uuid());
      portNode->setExternUuid(port->uuid());
      portNode->setLabel(port->name());
    }
  }
  for (model::base::LinkItem* link: _sutItem->links()) {
    LayoutEdge* edge = _graph->addEdge(
                         _graph->portParentNode(link->from()->uuid()),
                         _graph->portParentNode(link->to()->uuid())
                         );
    edge->setName(link->toString());
    edge->setSourcePort(_graph->port(link->from()->uuid()));
    edge->setTargetPort(_graph->port(link->to()->uuid()));
    edge->setType(Line);
    edge->setExternUuid(link->uuid());
  }
}
