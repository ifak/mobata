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

#include "graphlayout_global.hpp"
#include "layoutglobal.hpp"

#include <QObject>

class QQuickItem;
class QQuickView;
class QQuickWidget;

namespace graphlayout{

class LayoutGraph;
class LayoutNode;
class LayoutNodePort;
class LayoutEdge;

class GRAPHLAYOUTSHARED_EXPORT QmlGraphView
    :public QObject
{
  Q_OBJECT
public:
  QmlGraphView(QQuickView *view,
               graphlayout::LayoutGraph *graph,
               graphlayout::GraphvizAlgorithm algorithm = graphlayout::Dot,
               QObject *parent = 0);

  QmlGraphView(QQuickWidget *widget,
               graphlayout::LayoutGraph *graph,
               graphlayout::GraphvizAlgorithm algorithm = graphlayout::Dot,
               QObject *parent = 0);

  virtual ~QmlGraphView();

private:
  void reset();

public:
  bool layout(QString* errorString);

public:
  void setZoomBound(double zoom);
  void setZoomType(const QString& type);
  void setGraphvizPath(QString path);
  void setAlgorithm(GraphvizAlgorithm algorithm);
  void setBackgroundColor(QColor color);
  void setTitleColor(QColor color);
  void setTitleSize(int textsize);
  void setTitleShape(ShapeEnum shape);
  void setTitleBorderColor(QColor color);
  void setTitleBorderWidth(double width);
  void setTitleBackgroundColor(QColor color);
  void setInfoboxBackgroundcolor(QColor color);
  void setInfoboxTextcolor(QColor color);
  void setInfoboxTextsize(int size);
  const QString& lastLog() const;

public slots:
  void zoomLevelSlot(){
    zoomLevel();
  }
  void zoomIn(){
    this->setZoom("+0.1");
  }
  void zoomOut(){
    this->setZoom("-0.1");
  }
  void zoomReset(){
    this->setZoom("1");
  }
  void zoomFull(){
    this->setZoom("zoom_full");
  }
  void infoBox(QString uuid);
  void infoBoxEdge(QString uuid);

  void unhighlightAllItems();
  void highlightItemByUuid(const QUuid& itemUuid,
                           const bool highlight);
  void highlightItemByName(const QString& itemName,
                     const bool highlight);

protected:
  QQuickItem* addNode(LayoutNode const* node, QQuickItem *parent);
  QQuickItem* addPort(graphlayout::LayoutNodePort const* port,
                      QQuickItem *parent);
  QQuickItem* addEdge(graphlayout::LayoutEdge const* edge);

  QObject* graphicQmlNodeFromUuid(const QUuid& uuid);
  QObject* graphicQmlEdgeFromUuid(const QUuid& uuid);
  QObject* graphicQmlPortFromUuid(const QUuid& uuid);
  QObject* graphicQmlLabelFromUuid(const QUuid& uuid);

  void zoomLevel();
  double zoomBound();

  void setZoom(QString zoomType = "");

  void addNodesFromList(const QList<LayoutNode*>& list,
                        QQuickItem *parent);
  void addEdgesFromList(const QList<graphlayout::LayoutEdge*>& list);

private:
  class QmlGraphViewVars;
  QmlGraphViewVars* _d;
};
}// end namespace graphlayout

