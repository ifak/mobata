#include "comcreatedeclgraph.hpp"

#include "layoutnode.hpp"
#include "layoutedge.hpp"

using namespace graphlayout;
using namespace model::spenat;
using namespace model::base;

ComCreateDeclGraph::ComCreateDeclGraph(LayoutGraph* graph, SpenatDeclModel const* decl)
  :_graph(graph),_decl(decl)
{
}

bool ComCreateDeclGraph::execute(QString* errorString){
//  qDebug()<<"ComCreateDeclGraph::execute() executed!";

  Q_UNUSED(errorString);

  _graph->clearGraph();
  _graph->setOverlap(_overlap);
  _graph->setSplines(_splines);
  _graph->setName(_decl->name());

  QString indention = "";
  for(int i = 0; i < this->_transitionActionIndention; i++){
    indention += " ";
  }

  for (PlaceItem const* place : _decl->initPlaces()) {
    LayoutNode* node = _graph->addNode();
    node->setName(place->name());
    node->setUuid(place->uuid());
    node->setExternUuid(place->uuid());
    node->setXLabel("\n" + place->text());
    node->setShape(_placeShape);
    node->setColor(_placeColor);
    node->setBorderColor(_placeBorderColor);
    node->setBorderWidth(_placeBorderWidth);
    node->setXLabelTextSize(_placeLabelSize);
    node->setXLabelColor(_placeLabelColor);
    node->setToken(true);
    node->setTokenColor(_initPlaceColor);
    if(this->_highlightEnabled==true){
      node->setHighlight(true);
      node->setHighlightColor(this->_highlightPlaceColor);
      node->setHighlightBorderColor(this->_highlightPlaceBorderColor);
      node->setHighlightBorderWidth(this->_highlightPlaceBorderWidth);
    }
  }
  for(PlaceItem* place : _decl->places()) {
    if(_graph->nodeByName(place->name())==nullptr){
      LayoutNode* node = _graph->addNode();
      node->setName(place->name());
      node->setUuid(place->uuid());
      node->setExternUuid(place->uuid());
      node->setXLabel(place->text());
      node->setShape(_placeShape);
      node->setColor(_placeColor);
      node->setBorderColor(_placeBorderColor);
      node->setBorderWidth(_placeBorderWidth);
      node->setXLabelTextSize(_placeLabelSize);
      node->setXLabelColor(_placeLabelColor);
      if(this->_highlightEnabled==true){
        node->setHighlight(true);
        node->setHighlightColor(this->_highlightPlaceColor);
        node->setHighlightBorderColor(this->_highlightPlaceBorderColor);
        node->setHighlightBorderWidth(this->_highlightPlaceBorderWidth);
      }
    }
  }
  for (JunctionItem* junc: _decl->junctions()) {
    LayoutNode* node = _graph->addNode();
    node->setName(junc->toString());
    node->setUuid(junc->uuid());
    node->setExternUuid(junc->uuid());
    node->setLabel(junc->text());
    node->setShape(_junctionShape);
    node->setColor(_junctionColor);
    if(this->_highlightEnabled==true){
      node->setHighlight(true);
      node->setHighlightColor(this->_highlightPlaceColor);
      node->setHighlightBorderColor(this->_highlightPlaceBorderColor);
      node->setHighlightBorderWidth(this->_highlightPlaceBorderWidth);
    }
  }
  for (TransitionItem* trans : _decl->transitions()) {
    // Signal
    QString signalName = "";
    QString portName = "";
    QString transitionType = "";
    QString timeout = "";
    if(trans->triggerItem()){
      if(trans->triggerItem()->triggerType()== ATriggerItem::EventTrigger){
        transitionType = "SignalTransition";
        const SignalTriggerItem* item = static_cast<const SignalTriggerItem*>(trans->triggerItem());
        Q_ASSERT(item);
        if(item->triggerSignal())
          signalName = item->triggerSignal()->name();
        if(item->port())
          portName = item->port()->name();
      }
      if(trans->triggerItem()->triggerType()== ATriggerItem::TimeoutTrigger){
        transitionType = "TimeoutTransition";
        const TimeoutTriggerItem* item = static_cast<const TimeoutTriggerItem*>(trans->triggerItem());
        Q_ASSERT(item);
        timeout = item->declaration();
      }
    }
    //labeltext
    QString labeltext = trans->getLabel();
    if(signalName!=""){
      labeltext.replace("trigger",signalName);
      labeltext.replace("msg",signalName);
    }
    labeltext.replace("/","/\n");
    QString tmp = "";
    while(tmp != labeltext){
      tmp = labeltext;
      labeltext.replace(";]","]");
      labeltext.replace("  "," ");
      labeltext.replace("\t"," ");
      labeltext.replace("; ",";");
      labeltext.replace(";\n",";");
      labeltext.replace("/\n","/");
    }
    labeltext.replace(";",";\n"+indention);
    labeltext.replace("/","/\n"+indention);

    labeltext = "";

    if(this->_showLabelName==true){
        labeltext+=trans->name();
        if(timeout!="")
          labeltext += ": " + timeout;
        if(signalName!="")
          labeltext += ": " + signalName;
    }
    if(this->_showLabelGuard==true && trans->guard() != ""){
        if(labeltext!=""){
            labeltext+="\n";
        }
        labeltext+=indention + "[";
        labeltext+=trans->guard();
        labeltext+="]";
    }
    if(this->_showLabelAction==true){
        if(labeltext!=""){
            labeltext+="\n"+indention;
        }
        labeltext+=trans->actions();
    }

    //simple Transition
    if(trans->postPlaceArcs().length()==1
       && trans->prePlaceArcs().length()==1
       && this->_transitionSimple==true){
      LayoutEdge* edge = _graph->addEdge(_graph->nodeByExternUuid(trans->prePlaceArcs().first()->source()->uuid()),
                                         _graph->nodeByExternUuid(trans->postPlaceArcs().first()->target()->uuid()));
      edge->setName(trans->name());
      edge->setUuid(trans->uuid());
      edge->setExternUuid(trans->uuid());

      edge->setStaticLabel(this->_staticEdgeLabels);
      edge->setLabel(labeltext);
      edge->setColor(_transitionSimpleColor);
      edge->setArrowsize(_transitionSimpleArrowsize);
      edge->setType(_transitionSimpleArrowtype);
      edge->setLineWidth(_transitionSimpleLinewidth);
      edge->setLabelTextSize(_transitionGuardLabelSize);
      edge->setLabelColor(_transitionLabelColor);
      if(this->_highlightEnabled==true){
        edge->setHighlight(true);
        edge->setHighlightColor(this->_highlightTransitionColor);
      }

    }else{ //TransitionNode
      LayoutNode* node = _graph->addNode();
      node->setStaticLabels(this->_staticNodeLabels);
      node->setName(trans->name());
      node->setUuid(trans->uuid());
      node->setExternUuid(trans->uuid());
      node->setXLabel(trans->name());
      if(this->_showLabelName==true){
        node->setLabel(labeltext.right(labeltext.length() - trans->name().length() - 1));
      }else{
        node->setLabel(labeltext);
      }
      node->setShape(_transitionShape);
      node->setColor(_transitionColor);
      node->setBorderColor(_transitionBorderColor);
      node->setBorderWidth(_transitionBorderWidth);
      node->setXLabelTextSize(_transitionLabelSize);
      node->setLabelTextSize(_transitionGuardLabelSize);
      node->setLabelColor(_transitionLabelColor);
      node->setXLabelColor(_transitionLabelColor);
      if(this->_highlightEnabled==true){
        node->setHighlight(true);
        node->setHighlightColor(this->_highlightTransitionColor);
        node->setHighlightBorderColor(this->_highlightTransitionBorderColor);
        node->setHighlightBorderWidth(this->_highlightTransitionBorderWidth);
      }
      for (PostPlaceArc* arc : trans->postPlaceArcs()) {
        LayoutEdge* edge = _graph->addEdge(_graph->nodeByExternUuid(trans->uuid()),
                                           _graph->nodeByExternUuid(arc->target()->uuid()));
        edge->setName(arc->toString());
        edge->setColor(_arcColor);
        edge->setType(_arcShape);
        edge->setLineWidth(_arcLineWidth);
        edge->setArrowsize(_arcArrowsize);
      }
      for (PrePlaceArc* arc : trans->prePlaceArcs()) {
        LayoutEdge* edge = _graph->addEdge(_graph->nodeByExternUuid(arc->source()->uuid()),
                                           _graph->nodeByExternUuid(trans->uuid()));
        edge->setName(arc->toString());
        edge->setColor(_arcColor);
        edge->setType(_arcShape);
        edge->setLineWidth(_arcLineWidth);
        edge->setArrowsize(_arcArrowsize);
      }
    }
  }

  return true;
}
