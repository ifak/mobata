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

#include "comcreatespenatgraph.hpp"

#include "layoutnode.hpp"
#include "layoutedge.hpp"

using namespace graphlayout;
using namespace model::spenat;

ComCreateSpenatGraph::ComCreateSpenatGraph(LayoutGraph* graph,
                                           SpenatBaseModel const* spenat)
  :_graph(graph),_spenat(spenat)
{
}

bool ComCreateSpenatGraph::execute(QString* errorString)
{
  Q_UNUSED(errorString);

  _graph->setOverlap(_overlap);
  _graph->setSplines(_splines);
  _graph->setName(_spenat->name());

  for (const PlaceItem* const place: _spenat->initPlaces()) {
    LayoutNode* node = _graph->addNode();
    node->setUuid(place->uuid());
    node->setExternUuid(place->uuid());
    node->setXLabel(place->text());
    node->setShape(_initPlaceShape);
    node->setColor(_initPlaceColor);
  }
  for (PlaceItem* place: _spenat->places()) {
    if(_graph->nodeByExternUuid(place->uuid())==nullptr){
      LayoutNode* node = _graph->addNode();
      node->setUuid(place->uuid());
      node->setExternUuid(place->uuid());
      node->setXLabel(place->text());
      node->setShape(_placeShape);
      node->setColor(_placeColor);
    }
  }
  for (TransitionItem* trans: _spenat->transitions()) {
    if(trans->postPlaceArcs().length()==1 && trans->prePlaceArcs().length()==1){

      LayoutEdge* edge = _graph->addEdge(_graph->nodeByExternUuid(trans->prePlaceArcs().first()->source()->uuid()),
                                         _graph->nodeByExternUuid(trans->postPlaceArcs().first()->target()->uuid()));
      edge->setLabel(trans->name()+": "+"["+trans->guard()+"]"+trans->actions());
      edge->setColor(_arcWithTransitionColor);
      edge->setType(Arrow);
    }else{
      LayoutNode* node = _graph->addNode();
      node->setUuid(trans->uuid());
      node->setExternUuid(trans->uuid());
      node->setXLabel(trans->name());
      node->setLabel("trigger: ["+trans->guard()+"]"+trans->actions());
      node->setShape(_transitionShape);
      node->setColor(_transitionColor);
      for (PostPlaceArc* arc: trans->postPlaceArcs()) {
        LayoutEdge* edge = _graph->addEdge(_graph->nodeByExternUuid(trans->uuid()),_graph->nodeByExternUuid(arc->target()->uuid()));
        edge->setColor(_arcColor);
        edge->setType(Arrow);
      }
      for (PrePlaceArc* arc: trans->prePlaceArcs()) {
        LayoutEdge* edge = _graph->addEdge(_graph->nodeByExternUuid(arc->source()->uuid()),_graph->nodeByExternUuid(trans->uuid()));
        edge->setColor(_arcColor);
        edge->setType(Arrow);
      }
    }
  }

  return true;
}
