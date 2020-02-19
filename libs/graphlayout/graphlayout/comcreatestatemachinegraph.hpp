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
#pragma once

#include <graphlayout/layoutgraph.hpp>
#include <mobata/model/statemachine/statemachine.hpp>
#include <QDebug>

namespace graphlayout {

class ComCreateStateMachineGraph
{
public:
    ComCreateStateMachineGraph(LayoutGraph* graph,
                               model::statemachine::StateMachineModel *stateMachine);
    ~ComCreateStateMachineGraph(){}


    bool execute(QString* errorString);
private:

    void setInternalNodeData(const model::base::ModelItem *item,
                             LayoutNode* node);
    void setInternalEdgeData(const model::statemachine::ModelItem *item,
                             LayoutEdge* edge);
    void setInternalLabelData(const model::base::ModelItem* item,
                              LayoutNode* node);

    LayoutGraph* _graph;
    const model::statemachine::StateMachineModel* _stateMachine;

    SplineEnum _splines = ortho;
    OverlapEnum _overlap = default0;

    // SimpleState
    ShapeEnum _simpleShape = RoundedRect;
    QColor _simpleColor = QColor("white");
    QColor _simpleBorderColor = QColor("black");
    double _simpleBorderWidth = 2.0;
    QColor _simpleLabelColor = QColor("black");
    int _simpleLabelSize = 12;
    // ConcurrentState
    ShapeEnum _concurrentShape = Rect;
    QColor _concurrentColor = QColor("lightgrey");
    QColor _concurrentBorderColor = QColor("black");
    double _concurrentBorderWidth = 2.0;
    QColor _concurrentLabelColor = QColor("black");
    int _concurrentLabelSize = 12;
    // ConcurrentRegion
    QColor _concurrentRegionColor = QColor("grey");
    QColor _concurrentRegionBorderColor = QColor("black");
    double _concurrentRegionBorderWidth = 2.0;
    QColor _concurrentRegionLabelColor = QColor("black");
    int _concurrentRegionLabelSize = 12;
    // CompositeState
    ShapeEnum _compositeShape = Rect;
    QColor _compositeColor = QColor("white");
    QColor _compositeBorderColor = QColor("black");
    double _compositeBorderWidth = 2.0;
    QColor _compositeLabelColor = QColor("black");
    int _compositeLabelSize = 12;
    // InitState
    ShapeEnum _initShape = RoundedRect;
    QColor _initColor = QColor("white");
    QColor _initBorderColor = QColor("black");
    double _initBorderWidth = 2.0;
    QColor _initTokenColor = QColor("black");
    QColor _initLabelColor = QColor("black");
    int _initLabelSize = 12;
    // FinalState
    ShapeEnum _finalShape = Octagon;
    QColor _finalColor = QColor("white");
    QColor _finalBorderColor = QColor("black");
    double _finalBorderWidth = 2.0;
    QColor _finalLabelColor = QColor("black");
    int _finalLabelSize = 12;
    // JunctionState
    ShapeEnum _junctionShape = Circle;
    QColor _junctionColor = QColor("white");
    QColor _junctionBorderColor = QColor("black");
    double _junctionBorderWidth = 2.0;
    QColor _junctionLabelColor = QColor("black");
    int _junctionLabelSize = 12;
    // ChoiceState
    ShapeEnum _choiceShape = Parallelogram;
    QColor _choiceColor = QColor("white");
    QColor _choiceBorderColor = QColor("black");
    double _choiceBorderWidth = 2.0;
    QColor _choiceLabelColor = QColor("black");
    int _choiceLabelSize = 12;

    // Transition
    QColor _transitionColor = QColor("black");
    double _transitionWidth = 2.0;
    ArrowEnum _transitionShape = Arrow;
    int _transitionArrowsize = 10;
    QColor _transitionLabelColor = QColor("black");
    int _transitionLabelSize = 12;

    //Highlight
    bool _highlightEnabled = true;
    QColor _highlightStateColor = QColor("green");
    QColor _highlightStateBorderColor = QColor("green");
    double _highlightStateBorderWidth = 2;
    QColor _highlightTransitionColor = QColor("green");

public:
    //Settings
    void setSplines(SplineEnum splines){this->_splines = splines;}
    void setOverlap(OverlapEnum overlap){this->_overlap = overlap;}
    // SimpleState
    void setSimpleShape(ShapeEnum shape){this->_simpleShape = shape;}
    void setSimpleColor(QColor color){this->_simpleColor = color;}
    void setSimpleBorderColor(QColor color){this->_simpleBorderColor = color;}
    void setSimpleBorderWidth(double width){this->_simpleBorderWidth = width;}
    void setSimpleLabelColor(QColor color){this->_simpleLabelColor = color;}
    void setSimpleLabelSize(int size){this->_simpleLabelSize = size;}
    // ConcurrentState
    void setConcurrentShape(ShapeEnum shape){this->_concurrentShape = shape;}
    void setConcurrentColor(QColor color){this->_concurrentColor = color;}
    void setConcurrentBorderColor(QColor color){this->_concurrentBorderColor = color;}
    void setConcurrentBorderWidth(double width){this->_concurrentBorderWidth = width;}
    void setConcurrentLabelColor(QColor color){this->_concurrentLabelColor = color;}
    void setConcurrentLabelSize(int size){this->_concurrentLabelSize = size;}
    // ConcurrentRegion
    void setConcurrentRegionColor(QColor color){this->_concurrentRegionColor = color;}
    void setConcurrentRegionBorderColor(QColor color){this->_concurrentRegionBorderColor = color;}
    void setConcurrentRegionBorderWidth(double width){this->_concurrentRegionBorderWidth = width;}
    void setConcurrentRegionLabelColor(QColor color){this->_concurrentRegionLabelColor = color;}
    void setConcurrentRegionLabelSize(int size){this->_concurrentRegionLabelSize = size;}
    // CompositeState
    void setCompositeShape(ShapeEnum shape){this->_compositeShape = shape;}
    void setCompositeColor(QColor color){this->_compositeColor = color;}
    void setCompositeBorderColor(QColor color){this->_compositeBorderColor = color;}
    void setCompositeBorderWidth(double width){this->_compositeBorderWidth = width;}
    void setCompositeLabelColor(QColor color){this->_compositeLabelColor = color;}
    void setCompositeLabelSize(int size){this->_compositeLabelSize = size;}
    // InitState
    void setInitShape(ShapeEnum shape){this->_initShape = shape;}
    void setInitColor(QColor color){this->_initColor = color;}
    void setInitBorderColor(QColor color){this->_initBorderColor = color;}
    void setInitBorderWidth(double width){this->_initBorderWidth = width;}
    void setInitLabelColor(QColor color){this->_initLabelColor = color;}
    void setInitLabelSize(int size){this->_initLabelSize = size;}
    void setInitTokenColor(QColor color){this->_initTokenColor = color;}
    // FinalState
    void setFinalShape(ShapeEnum shape){this->_finalShape = shape;}
    void setFinalColor(QColor color){this->_finalColor = color;}
    void setFinalBorderColor(QColor color){this->_finalBorderColor = color;}
    void setFinalBorderWidth(double width){this->_finalBorderWidth = width;}
    void setFinalLabelColor(QColor color){this->_finalLabelColor = color;}
    void setFinalLabelSize(int size){this->_finalLabelSize = size;}
    // JunctionState
    void setJunctionShape(ShapeEnum shape){this->_junctionShape = shape;}
    void setJunctionColor(QColor color){this->_junctionColor = color;}
    void setJunctionBorderColor(QColor color){this->_junctionBorderColor = color;}
    void setJunctionBorderWidth(double width){this->_junctionBorderWidth = width;}
    void setJunctionLabelColor(QColor color){this->_junctionLabelColor = color;}
    void setJunctionLabelSize(int size){this->_junctionLabelSize = size;}
    // ChoiceState
    void setChoiceShape(ShapeEnum shape){this->_choiceShape = shape;}
    void setChoiceColor(QColor color){this->_choiceColor = color;}
    void setChoiceBorderColor(QColor color){this->_choiceBorderColor = color;}
    void setChoiceBorderWidth(double width){this->_choiceBorderWidth = width;}
    void setChoiceLabelColor(QColor color){this->_choiceLabelColor = color;}
    void setChoiceLabelSize(int size){this->_choiceLabelSize = size;}

    // Transition
    void setTransitionColor(QColor color){this->_transitionColor = color;}
    void setTransitionWidth(double width){this->_transitionWidth = width;}
    void setTransitionShape(ArrowEnum shape){this->_transitionShape = shape;}
    void setTransitionArrowsize(int size){this->_transitionArrowsize = size;}
    void setTransitionLabelColor(QColor color){this->_transitionLabelColor = color;}
    void setTransitionLabelSize(int size){this->_transitionLabelSize = size;}

    //Highlight
    void setHighlightEnabled(const bool& enabled){this->_highlightEnabled = enabled;}
    //Highlight State
    void setHighlightStateColor(const QColor& color){this->_highlightStateColor = color;}
    void setHighlightStateBorderColor(const QColor& color){this->_highlightStateBorderColor = color;}
    void setHighlightStateBorderWidth(const double& width){this->_highlightStateBorderWidth = width;}
    //Highlight Transition
    void setHighlightTransitionColor(const QColor& color){this->_highlightTransitionColor = color;}


private:
    void addCompositeChilds(const model::statemachine::CompositeStateItem* compositeState,LayoutNode* parentNode);
    void addState(const model::statemachine::AbstractStateItem *state, LayoutNode* parentNode);
    void addEdge(const model::statemachine::TransitionItem* transition);

};
}
