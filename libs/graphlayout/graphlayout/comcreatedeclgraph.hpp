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

#include "mobata/model/base/signaltriggeritem.hpp"
#include "mobata/model/base/timeouttriggeritem.hpp"
#include "mobata/model/base/atriggeritem.hpp"

#include "mobata/model/spenat/spenatdeclmodel.hpp"
#include "mobata/model/spenat/transitionitem.hpp"
#include "mobata/model/spenat/junctionitem.hpp"
#include "mobata/model/spenat/placeitem.hpp"
#include "mobata/model/spenat/initplaceitem.hpp"
#include "mobata/model/spenat/postplacearc.hpp"
#include "mobata/model/spenat/preplacearc.hpp"
#include "mobata/model/base/signalitem.hpp"
#include "mobata/model/base/portitem.hpp"

#include <QList>
#include <QStringList>

#include <QDebug>

namespace graphlayout {

class ComCreateDeclGraph
{
public:
  ComCreateDeclGraph(LayoutGraph* graph, model::spenat::SpenatDeclModel const* decl);
  ~ComCreateDeclGraph(){}

public:
  bool execute(QString* errorString);

private:
  LayoutGraph* _graph;
  model::spenat::SpenatDeclModel const* _decl;

  OverlapEnum _overlap = default0;
  SplineEnum _splines = ortho;

  bool _staticEdgeLabels = true;
  bool _staticNodeLabels = true;

  QColor _initPlaceColor = QColor("black");

  ShapeEnum _placeShape = RoundedRect;
  QColor _placeColor = QColor("white");
  QColor _placeBorderColor = QColor("black");
  double _placeBorderWidth = 2.0;

  int _placeLabelSize = 12;
  QColor _placeLabelColor = QColor("black");

  ShapeEnum _transitionShape = Rect;
  QColor _transitionColor = QColor("white");
  double _transitionBorderWidth = 2;
  QColor _transitionBorderColor = QColor("black");

  bool _transitionSimple = true;
  QColor _transitionSimpleColor = QColor("black");
  ArrowEnum _transitionSimpleArrowtype = Arrow;
  int _transitionSimpleArrowsize = 15;
  double _transitionSimpleLinewidth = 2;

  int _transitionLabelSize = 12;
  QColor _transitionLabelColor = QColor("black");
  int _transitionGuardLabelSize = 12;
  int _transitionActionIndention = 2;

  ShapeEnum _junctionShape = Circle;
  QColor _junctionColor = QColor("white");

  QColor _arcColor = QColor("black");
  ArrowEnum _arcShape = Arrow;
  int _arcArrowsize = 15;
  double _arcLineWidth = 2;

  bool _highlightEnabled = true;
  QColor _highlightPlaceColor = QColor("green");
  QColor _highlightPlaceBorderColor = QColor("green");
  double _highlightPlaceBorderWidth = 2;
  QColor _highlightTransitionColor = QColor("green");
  QColor _highlightTransitionBorderColor = QColor("green");
  double _highlightTransitionBorderWidth = 2;

  bool _showLabelName = true;
  bool _showLabelGuard = true;
  bool _showLabelAction = false;

public:
  //graph
  void setOverlap(const OverlapEnum& overlap){this->_overlap=overlap;}
  void setSplines(const SplineEnum& splines){this->_splines=splines;}
  void setStaticEdgeLabels(const bool& enabled){this->_staticEdgeLabels=enabled;}
  void setStaticNodeLabels(const bool& enabled){this->_staticNodeLabels=enabled;}
  //Initplace
  void setInitPlaceColor(const QColor& color){this->_initPlaceColor=color;}
  //place
  void setPlaceShape(const ShapeEnum& shape){this->_placeShape=shape;}
  void setPlaceColor(const QColor& color){this->_placeColor=color;}
  void setPlaceBorderColor(const QColor& color){this->_placeBorderColor=color;}
  void setPlaceBorderWidth(const double& width){this->_placeBorderWidth=width;}
  //placelabel
  void setPlaceLabelSize(const int& labelSize){this->_placeLabelSize=labelSize;}
  void setPlaceLabelColor(const QColor& color){this->_placeLabelColor=color;}
  //transition
  void setTransitionShape(const ShapeEnum& shape){this->_transitionShape=shape;}
  void setTransitionColor(const QColor& color){this->_transitionColor=color;}
  void setTransitionBorderWidth(const int& width){this->_transitionBorderWidth=width;}
  void setTransitionBorderColor(const QColor& color){this->_transitionBorderColor=color;}
  //simple transition
  void setTransitionSimple(const bool& d){this->_transitionSimple=d;}
  void setTransitionSimpleColor(const QColor& color){this->_transitionSimpleColor=color;}
  void setTransitionSimpleArrowtype(const ArrowEnum& type){this->_transitionSimpleArrowtype=type;}
  void setTransitionSimpleArrowsize(const int& size){this->_transitionSimpleArrowsize=size;}
  void setTransitionSimpleLinewidth(const double& width){this->_transitionSimpleLinewidth=width;}
  //transitionlabel
  void setTransitionLabelSize(const int& labelSize){this->_transitionLabelSize=labelSize;}
  void setTransitionLabelColor(const QColor& color){this->_transitionLabelColor=color;}
  void setTransitionGuardLabelSize(const int& xLabelSize){this->_transitionGuardLabelSize=xLabelSize;}
  void setTransitionActionIndention(const int& indention){this->_transitionActionIndention=indention;}
  //junction
  void setJunctionShape(const ShapeEnum& shape){this->_junctionShape=shape;}
  void setJunctionColor(const QColor& color){this->_junctionColor=color;}
  //arc
  void setArcColor(const QColor& color){this->_arcColor=color;}
  void setArcShape(const ArrowEnum& shape){this->_arcShape=shape;}
  void setArcArrowsize(const int& size){this->_arcArrowsize=size;}
  void setArcLineWidth(const double& width){this->_arcLineWidth=width;}
  //highlight
  void setHighlightEnabled(const bool& enabled){this->_highlightEnabled = enabled;}
  //Highlight Place
  void setHighlightPlaceColor(const QColor& color){this->_highlightPlaceColor = color;}
  void setHighlightPlaceBorderColor(const QColor& color){this->_highlightPlaceBorderColor = color;}
  void setHighlightPlaceBorderWidth(const double& width){this->_highlightPlaceBorderWidth = width;}
  //Highlight Transition
  void setHighlightTransitionColor(const QColor& color){this->_highlightTransitionColor = color;}
  void setHighlightTransitionBorderColor(const QColor& color){this->_highlightTransitionBorderColor = color;}
  void setHighlightTransitionBorderWidth(const double& width){this->_highlightTransitionBorderWidth = width;}
  //showLabel
  void setShowLabelName(const bool& enabled){this->_showLabelName = enabled;}
  void setShowLabelGuard(const bool& enabled){this->_showLabelGuard = enabled;}
  void setShowLabelAction(const bool& enabled){this->_showLabelAction = enabled;}
};
}// end namespace graphlayout
