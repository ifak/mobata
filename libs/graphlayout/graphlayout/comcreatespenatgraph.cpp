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

  foreach (const PlaceItem* const place, _spenat->initPlaces()) {
    LayoutNode* node = _graph->addNode();
    node->setUuid(place->uuid());
    node->setExternUuid(place->uuid());
    node->setXLabel(place->text());
    node->setShape(_initPlaceShape);
    node->setColor(_initPlaceColor);
  }
  foreach (PlaceItem* place, _spenat->places()) {
    if(_graph->nodeByExternUuid(place->uuid())==nullptr){
      LayoutNode* node = _graph->addNode();
      node->setUuid(place->uuid());
      node->setExternUuid(place->uuid());
      node->setXLabel(place->text());
      node->setShape(_placeShape);
      node->setColor(_placeColor);
    }
  }
  foreach (TransitionItem* trans, _spenat->transitions()) {
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
      foreach (PostPlaceArc* arc, trans->postPlaceArcs()) {
        LayoutEdge* edge = _graph->addEdge(_graph->nodeByExternUuid(trans->uuid()),_graph->nodeByExternUuid(arc->target()->uuid()));
        edge->setColor(_arcColor);
        edge->setType(Arrow);
      }
      foreach (PrePlaceArc* arc, trans->prePlaceArcs()) {
        LayoutEdge* edge = _graph->addEdge(_graph->nodeByExternUuid(arc->source()->uuid()),_graph->nodeByExternUuid(trans->uuid()));
        edge->setColor(_arcColor);
        edge->setType(Arrow);
      }
    }
  }

  return true;
}
