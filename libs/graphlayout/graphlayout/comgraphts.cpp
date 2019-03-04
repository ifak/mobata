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

#include "comgraphts.hpp"

#include "layoutnode.hpp"
#include "layoutedge.hpp"

using namespace graphlayout;
using namespace model::ts;
using namespace model::base;

ComGraphTS::ComGraphTS(LayoutGraph* graph, TestSystemItem* tsItem)
    :_graph(graph),_tsItem(tsItem)
{
}

void ComGraphTS::setSutItemColor(const QColor& color){
    this->_SutItemColor=color;
}

void ComGraphTS::setSutComponentColor(const QColor& color){
    this->_SutComponentColor=color;
}

void ComGraphTS::setSutPortColor(const QColor& color){
    this->_SutPortColor=color;
}

void ComGraphTS::setTsComponentColor(const QColor& color){
    this->_TsComponentColor=color;
}

void ComGraphTS::setTsPortColor(const QColor& color){
    this->_TsPortColor=color;
}

const QColor& ComGraphTS::sutItemColor(){
    return this->_SutItemColor;
}

const QColor& ComGraphTS::sutComponentColor(){
    return this->_SutComponentColor;
}

const QColor& ComGraphTS::sutPortColor(){
    return this->_SutPortColor;
}

const QColor& ComGraphTS::tsComponentColor(){
    return this->_TsComponentColor;
}

const QColor& ComGraphTS::tsPortColor(){
    return this->_TsPortColor;
}


void ComGraphTS::execute(){
    _graph->clearGraph();
    _graph->setName(_tsItem->name());
    _graph->setSplines(ortho);
    _graph->setOverlap(default0);
    //! SUT
    LayoutNode* sutNode = _graph->addNode();
    sutNode->setShape(Rect);
    sutNode->setLabel(_tsItem->sutItem()->name());
    sutNode->setObjectName("node_TS_SUT");
    sutNode->setColor(this->_SutItemColor);
    sutNode->setExternUuid(_tsItem->sutItem()->uuid());
    sutNode->setUuid(_tsItem->sutItem()->uuid());
    for(const ComponentItem* item : _tsItem->sutItem()->components()) {
        LayoutNode* node = sutNode->addNode();
        node->setUuid(item->uuid());
        node->setShape(Rect);
        node->setExternUuid(item->uuid());
        node->setXLabel(item->text());
        node->setObjectName("node_SUT_Component");
        node->setColor(this->_SutComponentColor);
        for(const PortItem* port : item->ports()){
            LayoutNodePort* portNode = node->addPort();
            portNode->setShape(Square);
            portNode->setUuid(port->uuid());
            portNode->setExternUuid(port->uuid());
            portNode->setColor(this->_SutPortColor);
            portNode->setLabel(port->name());
        }
    }
    for (const LinkItem* link: _tsItem->sutItem()->links()) {
        LayoutEdge* edge = _graph->addEdge(
                    _graph->portParentNode(link->from()->uuid()),
                    _graph->portParentNode(link->to()->uuid())
                    );
        edge->setSourcePort(_graph->port(link->from()->uuid()));
        edge->setTargetPort(_graph->port(link->to()->uuid()));

        edge->setType(Line);
        edge->setExternUuid(link->uuid());
    }
    //!TS
    for (ComponentItem* item: _tsItem->components()) {
        LayoutNode* node = _graph->addNode();
        node->setUuid(item->uuid());
        node->setShape(Rect);
        node->setExternUuid(item->uuid());
        node->setXLabel(item->text());
        node->setObjectName("node_TS_Component");
        node->setColor(this->_TsComponentColor);
        for(PortItem* port: item->ports()){
            LayoutNodePort* portNode = node->addPort();
            portNode->setShape(Square);
            portNode->setUuid(port->uuid());
            portNode->setExternUuid(port->uuid());
            portNode->setColor(this->_TsPortColor);
            portNode->setLabel(port->name());
        }
    }
    for (LinkItem* link: _tsItem->links()) {
        LayoutEdge* edge = _graph->addEdge(
                    _graph->portParentNode(link->from()->uuid()),
                    _graph->portParentNode(link->to()->uuid())
                    );
        edge->setSourcePort(_graph->port(link->from()->uuid()));
        edge->setTargetPort(_graph->port(link->to()->uuid()));

        edge->setType(Line);
        edge->setExternUuid(link->uuid());
    }
}
