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

#include "comcreatestatemachinegraph.hpp"

#include "layoutnode.hpp"
#include "layoutedge.hpp"
#include "layoutroles.hpp"

using namespace graphlayout;
using namespace model::statemachine;
//using namespace model::base;

ComCreateStateMachineGraph::ComCreateStateMachineGraph(LayoutGraph* graph, StateMachineModel* stateMachine)
  :_graph(graph),
  _stateMachine(stateMachine)
{}

bool ComCreateStateMachineGraph::execute(QString* errorString)
{
  Q_UNUSED(errorString);

  _graph->clearGraph();
  _graph->setSplines(_splines);
  _graph->setOverlap(_overlap);
  _graph->setName(_stateMachine->name());

  for(const AbstractStateItem* state: this->_stateMachine->states())
    addState(state, nullptr);
  for(const TransitionItem* transition: this->_stateMachine->transitions())
    addEdge(transition);
  return true;
}

void ComCreateStateMachineGraph::addCompositeChilds(const CompositeStateItem* compositeState,LayoutNode* parentNode){
  LayoutNode* Compnode = nullptr;
  if(parentNode==nullptr){
    Compnode = _graph->addNode();
  }else{
    Compnode = parentNode->addNode();
  }
  if(Compnode==nullptr){
    return;
  }
  Compnode->setName(compositeState->name());
  Compnode->setHideLabel(false);
  Compnode->setShape(this->_compositeShape);
  Compnode->setColor(this->_compositeColor);
  Compnode->setBorderColor(this->_compositeBorderColor);
  Compnode->setBorderWidth(this->_compositeBorderWidth);
  Compnode->setLabelColor(this->_compositeLabelColor);
  Compnode->setLabelTextSize(this->_compositeLabelSize);
  Compnode->setLabel(compositeState->name());
  Compnode->setUuid(compositeState->uuid());
  Compnode->setExternUuid(compositeState->uuid());
  this->setInternalNodeData(compositeState, Compnode);
  this->setInternalLabelData(compositeState, Compnode);

  if(this->_highlightEnabled==true){
    Compnode->setHighlight(true);
    Compnode->setHighlightColor(this->_highlightStateColor);
    Compnode->setHighlightBorderColor(this->_highlightStateBorderColor);
    Compnode->setHighlightBorderWidth(this->_highlightStateBorderWidth);
  }
  for(const AbstractStateItem* intStates: compositeState->states()) {
    addState(intStates,Compnode);
  }
  return;
}

void ComCreateStateMachineGraph::addState(const AbstractStateItem* state,
                                          LayoutNode* parentNode){
  if(_graph->nodeByExternUuid(state->uuid()) != nullptr){
    return;
  }

  if(state->stateType() == Simple){
    const SimpleStateItem* simpleState = dynamic_cast<const SimpleStateItem*>(state);
    LayoutNode* Simplenode = nullptr;
    if(parentNode==nullptr){
      Simplenode = _graph->addNode();
    }else{
      Simplenode = parentNode->addNode();
    }

    Simplenode->setName(state->name());
    if(simpleState->isInit()==true){
        Simplenode->setShape(this->_initShape);
        Simplenode->setColor(this->_initColor);
        Simplenode->setBorderColor(this->_initBorderColor);
        Simplenode->setBorderWidth(this->_initBorderWidth);
        Simplenode->setXLabelColor(this->_initLabelColor);
        Simplenode->setXLabelTextSize(this->_initLabelSize);
        Simplenode->setToken(true);
        Simplenode->setTokenColor(this->_initTokenColor);
        Simplenode->setXLabel("\n" + state->name());
    }else{
        Simplenode->setShape(this->_simpleShape);
        Simplenode->setColor(this->_simpleColor);
        Simplenode->setBorderColor(this->_simpleBorderColor);
        Simplenode->setBorderWidth(this->_simpleBorderWidth);
        Simplenode->setXLabelColor(this->_simpleLabelColor);
        Simplenode->setXLabelTextSize(this->_simpleLabelSize);
            Simplenode->setXLabel(state->name());
    }

    Simplenode->setUuid(state->uuid());
    Simplenode->setExternUuid(state->uuid());
    this->setInternalNodeData(state, Simplenode);
    this->setInternalLabelData(state, Simplenode);
    if(this->_highlightEnabled==true){
      Simplenode->setHighlight(true);
      Simplenode->setHighlightColor(this->_highlightStateColor);
      Simplenode->setHighlightBorderColor(this->_highlightStateBorderColor);
      Simplenode->setHighlightBorderWidth(this->_highlightStateBorderWidth);
    }
  }else if(state->stateType() == Concurrent){
    const ConcurrentStateItem* conState = dynamic_cast<const ConcurrentStateItem*>(state);

    LayoutNode* Concurrentnode = nullptr;
    if(parentNode==nullptr){
      Concurrentnode = _graph->addNode();
    }else{
      Concurrentnode = parentNode->addNode();
    }
    Concurrentnode->setName(conState->name());
    Concurrentnode->setShape(this->_concurrentShape);
    Concurrentnode->setColor(this->_concurrentColor);
    Concurrentnode->setBorderColor(this->_concurrentBorderColor);
    Concurrentnode->setBorderWidth(this->_concurrentBorderWidth);
    Concurrentnode->setLabelColor(this->_concurrentLabelColor);
    Concurrentnode->setLabelTextSize(this->_concurrentLabelSize);

    Concurrentnode->setLabel(conState->name());
    Concurrentnode->setUuid(conState->uuid());
    Concurrentnode->setExternUuid(conState->uuid());
    this->setInternalNodeData(state, Concurrentnode);
    this->setInternalLabelData(state, Concurrentnode);

    if(this->_highlightEnabled==true){
      Concurrentnode->setHighlight(true);
      Concurrentnode->setHighlightColor(this->_highlightStateColor);
      Concurrentnode->setHighlightBorderColor(this->_highlightStateBorderColor);
      Concurrentnode->setHighlightBorderWidth(this->_highlightStateBorderWidth);
    }

    for (const RegionItem* region: conState->regions()){
      LayoutNode* regionnode = Concurrentnode->addNode();
      regionnode->setName(region->name());
      regionnode->setShape(Rect);
      regionnode->setColor(QColor("transparent"));
      regionnode->setBorderColor(this->_concurrentBorderColor);
      regionnode->setBorderWidth(this->_concurrentBorderWidth);
      regionnode->setUuid(region->uuid());
      regionnode->setExternUuid(region->uuid());
      regionnode->setHideLabel(true);
      this->setInternalNodeData(region, regionnode);
      for(const AbstractStateItem* intstates: region->states()) {
        addState(intstates,regionnode);
      }
    }
  }else if(state->stateType() == Composite){
    addCompositeChilds(dynamic_cast<const CompositeStateItem*>(state), parentNode);
  }
  else if(state->stateType() == Final){
    LayoutNode* Finalnode = nullptr;
    if(parentNode==nullptr){
      Finalnode = _graph->addNode();
    }else{
      Finalnode = parentNode->addNode();
    }
    Finalnode->setName(state->name());
    Finalnode->setShape(this->_finalShape);
    Finalnode->setColor(this->_finalColor);
    Finalnode->setBorderColor(this->_finalBorderColor);
    Finalnode->setBorderWidth(this->_finalBorderWidth);
    Finalnode->setXLabelColor(this->_finalLabelColor);
    Finalnode->setXLabelTextSize(this->_finalLabelSize);

    Finalnode->setXLabel(state->name());
    Finalnode->setUuid(state->uuid());
    Finalnode->setExternUuid(state->uuid());
    this->setInternalNodeData(state, Finalnode);
    this->setInternalLabelData(state, Finalnode);

    if(this->_highlightEnabled==true){
      Finalnode->setHighlight(true);
      Finalnode->setHighlightColor(this->_highlightStateColor);
      Finalnode->setHighlightBorderColor(this->_highlightStateBorderColor);
      Finalnode->setHighlightBorderWidth(this->_highlightStateBorderWidth);
    }
  }else if(state->stateType() == Choice){
    LayoutNode* Choicenode = nullptr;
    if(parentNode==nullptr){
      Choicenode = _graph->addNode();
    }else{
      Choicenode = parentNode->addNode();
    }
    Choicenode->setName(state->name());
    Choicenode->setShape(this->_choiceShape);
    Choicenode->setColor(this->_choiceColor);
    Choicenode->setBorderColor(this->_choiceBorderColor);
    Choicenode->setBorderWidth(this->_choiceBorderWidth);
    Choicenode->setXLabelColor(this->_choiceLabelColor);
    Choicenode->setXLabelTextSize(this->_choiceLabelSize);

    Choicenode->setXLabel(state->name());
    Choicenode->setUuid(state->uuid());
    Choicenode->setExternUuid(state->uuid());
    this->setInternalNodeData(state, Choicenode);
    this->setInternalLabelData(state, Choicenode);

    if(this->_highlightEnabled==true){
      Choicenode->setHighlight(true);
      Choicenode->setHighlightColor(this->_highlightStateColor);
      Choicenode->setHighlightBorderColor(this->_highlightStateBorderColor);
      Choicenode->setHighlightBorderWidth(this->_highlightStateBorderWidth);
    }
  }else if(state->stateType() == Junction){
    LayoutNode* Junctionnode = nullptr;
    if(parentNode==nullptr){
      Junctionnode = _graph->addNode();
    }else{
      Junctionnode = parentNode->addNode();
    }
    Junctionnode->setName(state->name());
    Junctionnode->setShape(this->_junctionShape);
    Junctionnode->setColor(this->_junctionColor);
    Junctionnode->setBorderColor(this->_junctionBorderColor);
    Junctionnode->setBorderWidth(this->_junctionBorderWidth);
    Junctionnode->setLabelColor(this->_junctionLabelColor);
    Junctionnode->setLabelTextSize(this->_junctionLabelSize);

    Junctionnode->setLabel(state->name());
    Junctionnode->setUuid(state->uuid());
    Junctionnode->setExternUuid(state->uuid());
    this->setInternalNodeData(state, Junctionnode);
    this->setInternalLabelData(state, Junctionnode);

    if(this->_highlightEnabled==true){
      Junctionnode->setHighlight(true);
      Junctionnode->setHighlightColor(this->_highlightStateColor);
      Junctionnode->setHighlightBorderColor(this->_highlightStateBorderColor);
      Junctionnode->setHighlightBorderWidth(this->_highlightStateBorderWidth);
    }
    const JunctionStateItem* junctionItem = static_cast<const JunctionStateItem*>(state);
    Q_ASSERT(junctionItem);
    for(const TransitionItem* transition: junctionItem->transitions()){
      addEdge(transition);
    }
  }
}

void ComCreateStateMachineGraph::addEdge(const TransitionItem* transition)
{
  if(_graph->edgeByExternUuid(transition->uuid()) != nullptr)
    return;

  if(transition->source() && transition->target()){
    const AbstractStateItem* sourceItem = transition->source();
    const AbstractStateItem* targetItem = transition->target();
    QUuid uuid1 = sourceItem->uuid();
    QUuid uuid2 = targetItem->uuid();

    const LayoutNode* source = _graph->nodeByExternUuid(uuid1);
    const LayoutNode* target = _graph->nodeByExternUuid(uuid2);
    if(source!=nullptr && target!=nullptr){
      LayoutEdge* edge = _graph->addEdge(source,target);
      edge->setName(transition->name());
      edge->setLineWidth(this->_transitionWidth);
      edge->setColor(this->_transitionColor);
      edge->setArrowsize(this->_transitionArrowsize);
      edge->setType(this->_transitionShape);
      edge->setLabelTextSize(this->_transitionLabelSize);
      edge->setLabelColor(this->_transitionLabelColor);
      edge->setHighlightColor(this->_highlightTransitionColor);

      edge->setUuid(transition->uuid());
      edge->setExternUuid(transition->uuid());

      QString labeltext("");
      labeltext = transition->name();
      labeltext = labeltext + ": ";
      labeltext = labeltext + "\n" + "[";
      labeltext = labeltext + transition->guard();
      labeltext = labeltext + "]" + "\n";
      labeltext = labeltext + transition->action();
      edge->setLabel(labeltext);

      setInternalEdgeData(transition, edge);
    }
  }
}

void ComCreateStateMachineGraph::setInternalNodeData(const ModelItem* item, LayoutNode* node)
{
  const LayoutNode* parentNode = node->parentNode();

  //absolute position
  QVariant absPositionData = item->data(AbsPositionRole);
  if(absPositionData.isValid()){
    QPointF absPosition = absPositionData.value<QPointF>();
    node->setFixedPos(true);
    node->setAbsolutePos(absPosition);
  }

  //relative position
  QVariant relPositionData = item->data(RelPositionRole);
  if(relPositionData.isValid()){
    QPointF position = relPositionData.value<QPointF>();
    node->setFixedPos(true);
    node->setPos(position);
  }
  else if(parentNode != nullptr && !parentNode->absolutePos().isNull()){
    QPointF position(node->absolutePos().x() - parentNode->absolutePos().x(),
                     node->absolutePos().y() - parentNode->absolutePos().y());
    node->setPos(position);
  }
  else
    node->setPos(node->absolutePos());

  //size
  QVariant widthData = item->data(WidthRole);
  QVariant heightData = item->data(HeightRole);
  if(widthData.isValid() && heightData.isValid()){
    node->setSize(QSizeF(widthData.toDouble(),
                         heightData.toDouble()));
  }

  //LineWidth
  QVariant lineWidthData = item->data(LineWidthRole);
  if(lineWidthData.isValid())
    node->setBorderWidth(lineWidthData.toDouble());

  //background color
  QVariant backgroundColorData = item->data(BackgroundColorRole);
  if(backgroundColorData.isValid()){
    QColor bgColor = backgroundColorData.value<QColor>();
    if(bgColor.isValid())
      node->setColor(bgColor);
  }
}

void ComCreateStateMachineGraph::setInternalEdgeData(const ModelItem* item,
                                                     LayoutEdge* edge)
{
  //line polygon
  QVariant polygonData = item->data(PolygonRole);
  if(polygonData.isValid()){
    QVector<QPointF> coordinates = polygonData.value<QVector<QPointF>>();
    edge->clearPoints();
    for(int i = 0; i < coordinates.size(); i++){
      edge->addPoint(coordinates.at(i));
    }
  }

  //LineWidth
  QVariant lineWidthData = item->data(LineWidthRole);
  if(lineWidthData.isValid())
    edge->setLineWidth(lineWidthData.toDouble());

  //line color
  QVariant foregroundColorData = item->data(ForegroundColorRole);
  if(foregroundColorData.isValid()){
    QColor fgColor = foregroundColorData.value<QColor>();
    if(fgColor.isValid())
      edge->setColor(fgColor);
  }

  //text color
  QVariant textColorData = item->data(TextColorRole);
  if(textColorData.isValid()){
    QColor colorText = textColorData.value<QColor>();
    if(colorText.isValid())
      edge->setLabelColor(colorText);
  }

  //Text position
  QVariant textPositionData = item->data(TextPositionRole);
  if(textPositionData.isValid()){
    QPointF textPosition = textPositionData.value<QPointF>();
    edge->setLabelPos(textPosition);
  }

  //Text font size
  QVariant textSizeData = item->data(TextFontSizeRole);
  if(textSizeData.isValid())
    edge->setLabelTextSize(textSizeData.toDouble());
}

void ComCreateStateMachineGraph::setInternalLabelData(const ModelItem* item,
                                                      LayoutNode* node)
{
  //text color
  QVariant textColorData = item->data(TextColorRole);
  if(textColorData.isValid()){
    QColor colorText = textColorData.value<QColor>();
    if(colorText.isValid())
      node->setLabelColor(colorText);
  }

  //Text position
  QVariant textPositionData = item->data(TextPositionRole);
  if(textPositionData.isValid()){
    QPointF textPosition = textPositionData.value<QPointF>();
    node->setLabelPos(textPosition);
  }

  //Text font size
  QVariant textSizeData = item->data(TextFontSizeRole);
  if(textSizeData.isValid())
    node->setLabelTextSize(textSizeData.toDouble());
}
