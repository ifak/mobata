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
    foreach(PortItem* port, item->ports()){
      LayoutNodePort* portNode = node->addPort();
      portNode->setName(port->name());
      portNode->setShape(Square);
      portNode->setColor(_sutPortColor);
      portNode->setUuid(port->uuid());
      portNode->setExternUuid(port->uuid());
      portNode->setLabel(port->name());
    }
  }
  foreach (model::base::LinkItem* link, _sutItem->links()) {
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
