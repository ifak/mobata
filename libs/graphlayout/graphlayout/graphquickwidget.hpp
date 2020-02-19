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
#include "qmledge.hpp"
#include "qmlnode.hpp"
#include "comexportgraph.hpp"

#include <QQuickWidget>

namespace graphlayout{

class LayoutGraph;
class LayoutNode;
class LayoutNodePort;
class LayoutEdge;

class GRAPHLAYOUTSHARED_EXPORT GraphQuickWidget
    : public QQuickWidget
{
  Q_OBJECT
public:
  GraphQuickWidget(LayoutGraph* graph,
                   GraphvizAlgorithm algorithm = graphlayout::Dot,
                   QWidget* parent = nullptr);
  virtual ~GraphQuickWidget();

protected:
  void reset();

protected:
  void              setLayoutGraph(LayoutGraph* layoutGraph);
  LayoutGraph*      layoutGraph() const;

public:
  bool              layout(QString* errorString);
  GraphvizAlgorithm graphvizAlgorithm() const;

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
  void setGraphvizAlgorithm(GraphvizAlgorithm graphvizAlgorithm);
  const QString& lastLog() const;
  bool saveCurrentViewPicture(const QString& path = "");
  bool saveGraphPicture(const QString& path = "");

public slots:
  void zoomLevelSlot(){
    zoomLevel();
  }
  void zoomIn();
  void zoomOut();
  void zoomReset();
  void zoomFull();
  void zoomWidth();
  void zoomHeight();

  void showLabels(bool enabled);

  void clickedObject(const QUuid& uuid);

  void unhighlightAllGraphicItems();
  void highlightItemByUuid(const QUuid& itemUuid,
                           const bool highlight);
  void highlightItemByName(const QString& itemName,
                           const bool highlight);
  void highlightGraphicItemByUuid(const QUuid& itemUuid,
                                  bool highlight,
                                  bool unhighlightOtherItems = false);
  void highlightGraphicItemsByUuids(const QList<QUuid>& itemUuids,
                                    bool highlight,
                                    bool unhighlightOtherItems = true);
  void highlightGraphicItemByName(const QString& itemName,
                                  bool highlight,
                                  bool unhighlightOtherItems = false);
  void highlightGraphicItemsByNames(const QList<QString>& itemNames,
                                    bool highlight,
                                    bool unhighlightOtherItems = true);
  void zoomToActiveEnabled(const bool enabled);
  void toggleLabel(const bool enabled);
  void layoutNoChecks();
  void saveCurrentViewAsPicture();
  void saveGraphAsPicture();
  void exportGraphWithEdgeLabels();
  void exportGraphWithoutEdgeLabels();

signals:
  void selectedItem(const QUuid& itemUuid);

protected:
  QmlNode*    addNode(LayoutNode const* node, QQuickItem *parent);
  QQuickItem* addPort(graphlayout::LayoutNodePort const* port,
                      QQuickItem *parent);
  QQuickItem* addEdge(graphlayout::LayoutEdge const* edge);

  QObject* graphicQmlNodeFromUuid(const QUuid& uuid);
  QObject* graphicQmlEdgeFromUuid(const QUuid& uuid);
  QObject* graphicQmlPortFromUuid(const QUuid& uuid);
  QObject* graphicQmlLabelFromUuid(const QUuid& uuid);

  void    zoomLevel();
  double  zoomBound();
  void    zoomToItem(QQuickItem* item);

  void  setZoom(const double zoom, const double setX=0.0, const double setY=0.0);
  qreal getZoom();

  void addNodesFromList(const QList<LayoutNode*>& list,
                        QQuickItem *parent);
  void addEdgesFromList(const QList<graphlayout::LayoutEdge*>& list);
  void showLabel(bool enabled);

  void resetSavePicture();
  void exportGraph(const QString& fileName,
                   bool withEdgeLabels);

protected:
  virtual void  contextMenuEvent(QContextMenuEvent* event);

private:
  Q_DISABLE_COPY(GraphQuickWidget)
  class Private;
  Private* _d;
};
}// end namespace graphlayout

