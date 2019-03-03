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

#include "graphquickwidget.hpp"

#include "layoutnode.hpp"
#include "layoutedge.hpp"
#include "comcreatelayout.hpp"
#include "comcreatelayoutedgesonly.hpp"

#include <QtQuick>
#include <QtMath>
#include <QtWidgets>
#include <QQuickItem>
#include <QStringList>
#include <QList>

#include <QFileDialog>
#include <QDialogButtonBox>
#include <QDebug>
#include <QPixmap>

using namespace graphlayout;

class GraphQuickWidget::Private{
  friend class GraphQuickWidget;

  LayoutGraph*      _layoutGraph;
  GraphvizAlgorithm _graphvizAlgorithm;

  QString _lastGraphvizLog = "";

  QQuickItem* _rootObject;
  QQmlEngine* _engine;

  QString _graphvizPath;

  bool _propertiesMenu = false;
  QString _zoomType = "zoom_full";
  bool _zoomToActive = false;

  double _nodeBorderWidth = 2;
  QColor _nodeBorderColor = QColor("black");

  double _edgeWidth = 2;
  double _edgeArrowSize = 15;

  //! Title
  double _titleTextSize = 20;
  QColor _titleTextColor = QColor("black");
  QColor _titleBackgroundColor = QColor("white");
  ShapeEnum _titleShape = Plaintext;
  QColor _titleBorderColor = QColor("black");
  double _titleBorderWidth = 2.0;
  QColor _backgroundColor = QColor("white");

  QFont _textfamily = QFont("Times-Roman");

  //!highlighted items
  QHash<LayoutNode*, QQuickItem*> _highlightedNodes;
  QHash<LayoutEdge*, QQuickItem*> _highlightedEdges;

  //!dynamicLabels
  QHash<LayoutEdge*, bool> _labelvisibility;
  bool _force_labels = false;

  //!save as picture
  bool _saveActive = false;

  Private(LayoutGraph *graph,
          GraphvizAlgorithm algorithm)
    : _layoutGraph(graph),
      _graphvizAlgorithm(algorithm)
  {}
};


GraphQuickWidget::GraphQuickWidget(LayoutGraph *graph,
                                   GraphvizAlgorithm algorithm,
                                   QWidget* parent)
  :QQuickWidget(parent), _d(new Private(graph, algorithm))
{
  qmlRegisterType<QmlEdge>("QEdge",1,0,"QmlEdge");
  qmlRegisterType<QmlNode>("QNode",1,0,"QmlNode");
  this->setResizeMode(QQuickWidget::SizeRootObjectToView);
  this->setSource(QUrl::fromLocalFile(":/graphlayout/qml/graph_main.qml"));
  if(this->status()==QQuickWidget::Error)
  {
    for(const QQmlError& currError : this->errors())
      qDebug()<<"graphlayout/main.qml error: "<<currError.toString();
    Q_ASSERT(false);
  }
  this->_d->_engine=this->engine();
  Q_ASSERT(this->_d->_engine);

  if(this->_d->_layoutGraph){
    this->_d->_labelvisibility.clear();
    for(LayoutEdge* edge : this->_d->_layoutGraph->edges())
      this->_d->_labelvisibility[edge] = edge->staticLabel();
  }

  this->_d->_rootObject =this->rootObject();
  Q_ASSERT(this->_d->_rootObject);

  QQuickItem* zoomObjectItem = _d->_rootObject->findChild<QQuickItem*>("zoomObject");
  Q_ASSERT(zoomObjectItem);
  QObject::connect(zoomObjectItem,SIGNAL(skaleChanged()),
                   this, SLOT(zoomLevelSlot()));

  QObject::connect(zoomObjectItem, SIGNAL(unhighlight()),
                   this, SLOT(unhighlightAllGraphicItems()));

}

GraphQuickWidget::~GraphQuickWidget()
{
  delete this->_d;
}

void GraphQuickWidget::setLayoutGraph(LayoutGraph *layoutGraph)
{
  this->_d->_layoutGraph = layoutGraph;
  this->_d->_labelvisibility.clear();
  for(LayoutEdge* edge : this->_d->_layoutGraph->edges())
  {
    this->_d->_labelvisibility[edge] = edge->staticLabel();
  }

  return;
}

LayoutGraph* GraphQuickWidget::layoutGraph() const
{
  return this->_d->_layoutGraph;
}

void GraphQuickWidget::setGraphvizAlgorithm(GraphvizAlgorithm graphvizAlgorithm)
{
  this->_d->_graphvizAlgorithm = graphvizAlgorithm;

  return;
}

GraphvizAlgorithm GraphQuickWidget::graphvizAlgorithm() const
{
  return this->_d->_graphvizAlgorithm;
}

const QString& GraphQuickWidget::lastLog() const
{
  return this->_d->_lastGraphvizLog;
}

void GraphQuickWidget::reset()
{
  Q_ASSERT(this->_d->_layoutGraph);

  for(QQuickItem* item :
      _d->_rootObject->findChildren<QQuickItem*>(QRegExp("text*",
                                                         Qt::CaseSensitive,
                                                         QRegExp::Wildcard))){
    delete item;
    item=nullptr;
  }
  for(QQuickItem* item : _d->_rootObject->findChildren<QQuickItem*>("edge")){
    //if(this->_d->_layoutGraph->edgeByExternUuid(QUuid(qvariant_cast<QString>(item->property("uuid"))))==nullptr)
    //{
    delete item;
    item=nullptr;
    //}
  }
  for(QQuickItem* item : _d->_rootObject->findChildren<QQuickItem*>("port")){
    LayoutNodePort* port = this->_d->_layoutGraph->port(QUuid(qvariant_cast<QString>(item->property("uuid"))));
    if(port!=nullptr)
    {
      port->setPos(QPointF(0,0));
      delete item;
      item=nullptr;
    }
  }
  for(QmlNode* item : _d->_rootObject->findChildren<QmlNode*>(QRegExp("node*",
                                                                      Qt::CaseSensitive,
                                                                      QRegExp::Wildcard))){
    if(!item){
      item->deleteLater();
      continue;
    }
    if(item->uuid()==""){
      item->deleteLater();
      continue;
    }
    if(this->_d->_layoutGraph->nodeByExternUuid(QUuid(qvariant_cast<QString>(item->uuid())))==nullptr){
      item->deleteLater();
    }
  }
  this->_d->_highlightedNodes.clear();
  this->_d->_highlightedEdges.clear();

  return;
}

bool GraphQuickWidget::layout(QString* errorString)
{
  Q_ASSERT(this->_d->_layoutGraph);

  QTime myTimer;
  myTimer.start();

  this->reset();

  if(this->_d->_graphvizAlgorithm != graphlayout::NoGraphviz){
    graphlayout::ComCreateLayout graphviz(_d->_layoutGraph,
                                          _d->_graphvizAlgorithm,
                                          _d->_graphvizPath);
    this->_d->_lastGraphvizLog = "";
    bool result = graphviz.execute(errorString, &this->_d->_lastGraphvizLog);
    if(!result)
      return false;
  }

  this->addNodesFromList(_d->_layoutGraph->nodes(),
                         _d->_rootObject->findChild<QQuickItem*>("drawArea"));
  this->addEdgesFromList(_d->_layoutGraph->edges());

  if(this->_d->_layoutGraph->allPorts().isEmpty()==false)
  {
    graphlayout::ComCreateLayoutEdgesOnly graphvizEdge(_d->_layoutGraph,
                                                       _d->_graphvizAlgorithm,
                                                       _d->_graphvizPath);
    graphvizEdge.execute(errorString, &this->_d->_lastGraphvizLog);
    for(QQuickItem* item : _d->_rootObject->findChildren<QQuickItem*>(QRegExp("text*",
                                                                              Qt::CaseSensitive,
                                                                              QRegExp::Wildcard)))
    {
      item->setProperty("uuid",0);
      item->deleteLater();
    }
    for(QQuickItem* item : _d->_rootObject->findChildren<QQuickItem*>("edge"))
    {
      item->deleteLater();
    }
    for(QQuickItem* item : _d->_rootObject->findChildren<QQuickItem*>("port"))
    {
      item->setProperty("uuid",0);
      item->deleteLater();
    }
    for(QQuickItem* item : _d->_rootObject->findChildren<QQuickItem*>(QRegExp("node*",
                                                                              Qt::CaseSensitive,
                                                                              QRegExp::Wildcard)))
    {
      item->setProperty("uuid",0);
      item->deleteLater();
    }
    this->addNodesFromList(_d->_layoutGraph->nodes(),
                           _d->_rootObject->findChild<QQuickItem*>("drawArea"));
    this->addEdgesFromList(_d->_layoutGraph->edges());
    for(LayoutNodePort* port : _d->_layoutGraph->allPorts())
    {
      if(port->pos()==QPointF(0,0)){
        port->setPos(_d->_layoutGraph->portParentNode(port->externUuid())->pos());
      }
    }
  }

  this->_d->_rootObject->setProperty("color",_d->_backgroundColor);

  QObject* drawArea = _d->_rootObject->findChild<QObject*>("drawArea");
  QQuickItem *quickDrawArea = qobject_cast<QQuickItem*>(drawArea);

  if(QObject* graphTitleObject = _d->_rootObject->findChild<QObject*>("graphTitle"))
  {
    graphTitleObject->setProperty("xLabel",_d->_layoutGraph->name());
    graphTitleObject->setProperty("textColor",_d->_titleTextColor);
    graphTitleObject->setProperty("textSize",_d->_titleTextSize);
    graphTitleObject->setProperty("textFamily",_d->_textfamily.family());
    graphTitleObject->setProperty("shape",_d->_titleShape);
    graphTitleObject->setProperty("color",_d->_titleBackgroundColor);
    graphTitleObject->setProperty("borderWidth",_d->_titleBorderWidth);
    graphTitleObject->setProperty("borderColor",_d->_titleBorderColor);
    QFont genFont(this->_d->_textfamily.family(), _d->_titleTextSize);
    QFontMetrics f1(genFont);
    QSize r1 = f1.size(0,_d->_layoutGraph->name());
    graphTitleObject->setProperty("width",r1.width()+_d->_nodeBorderWidth*2);
    graphTitleObject->setProperty("height",r1.height()+_d->_nodeBorderWidth*2);
  }
  else
  {
    QQmlComponent dyn(_d->_engine,
                      QUrl::fromLocalFile(":/graphlayout/qml/GraphNode.qml"),
                      _d->_rootObject->findChild<QQuickItem*>("drawArea"));
    QObject *dynObject = dyn.create();
    Q_ASSERT(dynObject);
    QQuickItem *item = qobject_cast<QQuickItem*>(dynObject);
    Q_ASSERT(item);

    item->setX(10);
    item->setY(10);
    item->setProperty("uuid","1234");
    item->setProperty("shape",_d->_titleShape);
    item->setProperty("xLabel",_d->_layoutGraph->name());
    item->setProperty("color",_d->_titleBackgroundColor);
    item->setProperty("borderWidth",_d->_titleBorderWidth);
    item->setProperty("borderColor",_d->_titleBorderColor);
    item->setProperty("textSize",_d->_titleTextSize);
    item->setProperty("textColor",_d->_titleTextColor);
    item->setProperty("textFamily",this->_d->_textfamily.family());
    item->setObjectName("graphTitle");
    item->setParent(quickDrawArea);
    item->setParentItem(quickDrawArea);
    QFont genFont(this->_d->_textfamily.family(), _d->_titleTextSize);
    QFontMetrics f1(genFont);
    QSize r1 = f1.size(0,_d->_layoutGraph->name());
    item->setWidth(r1.width()+_d->_nodeBorderWidth*2);
    item->setHeight(r1.height()+_d->_nodeBorderWidth*2);
  }


  for(QQuickItem* item: _d->_rootObject->findChildren<QQuickItem*>("text"))
  {
    item->setProperty("visible",false);
  }

  if(*errorString!="")
    qDebug()<<*errorString;
//  qDebug()<<"Layout time: " << myTimer.elapsed()<<" ms";

  return true;
}
//! Call the addNode function for each node
void GraphQuickWidget::addNodesFromList(const QList<graphlayout::LayoutNode*>& list,
                                        QQuickItem *parent){
  for(graphlayout::LayoutNode const* node : list) {
    QmlNode *item = this->addNode(node, parent);
    if(node->nodes().isEmpty() == false){
      this->addNodesFromList(node->nodes(), item);
    }
    if(node->ports().isEmpty() == false){
      for (LayoutNodePort* port: node->ports()) {
        if(this->_d->_layoutGraph->allUsedPorts().contains(port)){
          port->setPos(QPointF(0,0));
          this->addPort(port,parent);
        }else{
          port->setPos(QPointF(0,0));
          this->addPort(port,item);
        }
      }
    }
  }

  return;
}

//! Call the addEdge function for each edge
void GraphQuickWidget::addEdgesFromList(const QList<graphlayout::LayoutEdge*>& list){
  for(graphlayout::LayoutEdge const* edge : list) {
    this->addEdge(edge);
  }

  return;
}

//! Return QObject node for the given uuid
QObject* GraphQuickWidget::graphicQmlNodeFromUuid(const QUuid& uuid)
{
  for(QObject* object
      : _d->_rootObject->findChildren<QObject*>(QRegExp("node*",
                                                        Qt::CaseSensitive,
                                                        QRegExp::Wildcard))) {
    if(object->property("uuid")==uuid){
      return object;
    }
  }
  return nullptr;
}
//! Return QObject edge for the given uuid
QObject* GraphQuickWidget::graphicQmlEdgeFromUuid(const QUuid& uuid)
{
  for (QObject* object : _d->_rootObject->findChildren<QObject*>("edge")) {
    if(object->property("uuid")==uuid){
      return object;
    }
  }
  return nullptr;
}
//! Return QObject port for the given uuid
QObject* GraphQuickWidget::graphicQmlPortFromUuid(const QUuid& uuid)
{
  for (QObject* object : _d->_rootObject->findChildren<QObject*>("port")) {
    if(object->property("uuid")==uuid){
      return object;
    }
  }
  return nullptr;
}
//! Return the QObject label from a node with the given uuid
QObject* GraphQuickWidget::graphicQmlLabelFromUuid(const QUuid& uuid)
{
  for (QObject* object : _d->_rootObject->findChildren<QObject*>("text")) {
    if(object->property("uuid")==uuid){
      return object;
    }
  }
  return nullptr;
}
//! Add a Edge
QQuickItem* GraphQuickWidget::addEdge(LayoutEdge const* edge)
{
  if(edge->points().length()>=2 && edge->type()!=Invisible){
    QQuickItem *item = nullptr;
    if(graphicQmlEdgeFromUuid(edge->uuid().toString()) == nullptr){
      QQmlComponent dyn(_d->_engine,QUrl::fromLocalFile(":/graphlayout/qml/GraphEdge.qml"),
                        _d->_rootObject->findChild<QObject*>("drawArea"));
      QObject *dynObject = dyn.create();
      item = qobject_cast<QQuickItem*>(dynObject);
      if(!item)
      {
        delete dynObject;
        return nullptr;
      }
    }else{
      item = qobject_cast<QQuickItem*>(graphicQmlEdgeFromUuid(edge->uuid().toString()));
      if(!item)
        return nullptr;
    }

    Q_ASSERT(item);

    QSizeF mouseAreaSize;
    QRectF linePos(edge->points().first()->x(),edge->points().first()->y(),0,0);
    for (QPointF* poi : edge->points()) {
      if(linePos.x()>poi->x())
        linePos.setX(poi->x());
      if(linePos.y()>poi->y())
        linePos.setY(poi->y());
    }
    for (QPointF* poi : edge->points()) {
      if(linePos.width()<poi->x()-linePos.left())
        linePos.setWidth(poi->x()-linePos.left());
      if(linePos.height()<poi->y()-linePos.top())
        linePos.setHeight(poi->y()-linePos.top());
    }

    mouseAreaSize.setWidth(linePos.width());
    mouseAreaSize.setHeight(linePos.height());

    linePos.setX(linePos.x()-edge->Arrowsize());
    linePos.setY(linePos.y()-edge->Arrowsize());
    linePos.setWidth(linePos.width()+edge->Arrowsize()*2);
    linePos.setHeight(linePos.height()+edge->Arrowsize()*2);


    QList<QPointF> pointlist;
    for (QPointF* poi: edge->points()) {
      pointlist.append(poi->toPoint());
    }
    QmlEdge* edgeItem = qobject_cast<QmlEdge*>(item);
    if(!edgeItem)
    {
      delete item;
      return nullptr;
    }

    edgeItem->setPoints(pointlist);
    edgeItem->setX(linePos.x());
    edgeItem->setY(linePos.y());
    edgeItem->setWidth(linePos.width());
    edgeItem->setHeight(linePos.height());
    edgeItem->setSkaleX(linePos.x());
    edgeItem->setSkaleY(linePos.y());
    edgeItem->setSkaleW(linePos.width());
    edgeItem->setSkaleH(linePos.height());
    edgeItem->setSplines(this->_d->_layoutGraph->splines());

    QQuickItem* mouseArea = item->findChild<QQuickItem*>("thisMouseArea");
    if(mouseArea){
//      mouseArea->setX(20+edge->Arrowsize());
//      mouseArea->setY(20+edge->Arrowsize());
//      mouseArea->setWidth(mouseAreaSize.width());
//      mouseArea->setHeight(mouseAreaSize.height());
//      if(mouseArea->width()< 6){
//        mouseArea->setX(mouseArea->x()-3);
//        mouseArea->setWidth(6);
//      }
//      if(mouseArea->height()< 6){
//        mouseArea->setY(mouseArea->y()-3);
//        mouseArea->setHeight(6);
//      }
      edgeItem->setZ(1000 -
                      ((linePos.width() * linePos.height() * 950) /
                      (this->_d->_layoutGraph->graphSize().width() * this->_d->_layoutGraph->graphSize().height())));
    }

    edgeItem->setLineColor(edge->color());
    edgeItem->setLineWidth(edge->lineWidth());
    edgeItem->setArrowSize(edge->Arrowsize());
    edgeItem->setUuid(edge->externUuid());
    edgeItem->setType(edge->type());
    item->setParent(_d->_rootObject->findChild<QQuickItem*>("drawArea"));
    item->setParentItem(_d->_rootObject->findChild<QQuickItem*>("drawArea"));

    QObject::connect(edgeItem, &QmlEdge::edgeClicked,
                     this, &GraphQuickWidget::clickedObject);

    if(edge->label()!=""){
      QQmlComponent dyn2(_d->_engine,
                         QUrl::fromLocalFile(":/graphlayout/qml/GraphText.qml"),item);
      QObject* dynObject2 = dyn2.create();
      QQuickItem *item2 = qobject_cast<QQuickItem*>(dynObject2);
      Q_ASSERT(item2);

      item2->setProperty("text",edge->label());
      item2->setProperty("textSize",edge->labelTextSize());
      item2->setProperty("textColor",edge->labelColor());
      item2->setProperty("textFamily",this->_d->_textfamily.family());
      item2->setProperty("uuid",edge->externUuid());
      if(edge->staticLabel()==false){
        item2->setProperty("parentPosX",edge->labelPos().x());
        item2->setProperty("parentPosY",edge->labelPos().y());
      }else if(edge->staticLabel()==true && this->_d->_layoutGraph->splines()==straight){
        qreal newX = 0;
        qreal newY = 0;
        QFont genFont(this->_d->_textfamily.family(), edge->labelTextSize()-1);
        QFontMetrics f1(genFont);
        QSize r1 = f1.size(0, edge->label());
        newX = (edge->points().first()->x()+edge->points().last()->x())/2;
        newY = (edge->points().first()->y()+edge->points().last()->y())/2;
        newY = newY - r1.height()/2;

        item2->setProperty("parentPosX",newX);
        item2->setProperty("parentPosY",newY);
      }else if(edge->staticLabel()==true){
        QFont genFont(this->_d->_textfamily.family(), edge->labelTextSize()-1);
        QFontMetrics f1(genFont);
        QSize r1 = f1.size(0, edge->label());
        qreal newX = 0;
        qreal newY = 0;
        if(edge->points().length()>2){
          newX = edge->points()[qFloor(edge->points().length()/2)]->x();
          newY = edge->points()[qFloor(edge->points().length()/2)]->y();
        }else{
          newX = (edge->points().first()->x()+edge->points().last()->x())/2;
          newY = (edge->points().first()->y()+edge->points().last()->y())/2;
        }
        if(newX < 0){
          newX = 0;
        }
        newX += r1.width()/2-20;
        newY += r1.height()/2;
        item2->setProperty("parentPosX",newX);
        item2->setProperty("parentPosY",newY);
      }
      item2->setParentItem(_d->_rootObject->findChild<QQuickItem*>("drawArea"));
      item2->setParent(_d->_rootObject->findChild<QQuickItem*>("drawArea"));
    }

    if(edge->targetPort()!=nullptr){
      QObject* port = graphicQmlPortFromUuid(edge->targetPort()->externUuid());
      if(port->property("x")==0 && port->property("y")==0){
        QObject* par = port->parent();
        QPointF pos(0,0);
        while(par != _d->_rootObject->findChild<QObject*>("drawArea")){
          pos.setX(pos.x()+qvariant_cast<float>(par->property("x")));
          pos.setY(pos.y()+qvariant_cast<float>(par->property("y")));
          par = par->parent();
        }
        port->setProperty("x",-pos.x() + edge->points().last()->x() - qvariant_cast<float>(port->property("width"))/2);
        port->setProperty("y",-pos.y() + edge->points().last()->y() - qvariant_cast<float>(port->property("height"))/2);
        this->_d->_layoutGraph->port(edge->targetPort()->externUuid())->setPos(QPointF(qvariant_cast<float>(port->property("x")),qvariant_cast<float>(port->property("y"))));
      }
    }
    if(edge->sourcePort()!=nullptr){
      QObject* port = graphicQmlPortFromUuid(edge->sourcePort()->externUuid());
      if(port->property("x")==0 && port->property("y")==0){
        QObject* par = port->parent();
        QPointF pos(0,0);
        while(par != _d->_rootObject->findChild<QObject*>("drawArea")){
          pos.setX(pos.x()+qvariant_cast<float>(par->property("x")));
          pos.setY(pos.y()+qvariant_cast<float>(par->property("y")));
          par = par->parent();
        }
        port->setProperty("x",-pos.x() + edge->points().first()->x() - qvariant_cast<float>(port->property("width"))/2);
        port->setProperty("y",-pos.y() + edge->points().first()->y() - qvariant_cast<float>(port->property("height"))/2);
        this->_d->_layoutGraph->port(edge->sourcePort()->externUuid())->setPos(QPointF(qvariant_cast<float>(port->property("x")),qvariant_cast<float>(port->property("y"))));
      }
    }
    return item;
  }else{
    return nullptr;
  }
}
//! Add a node
QmlNode *GraphQuickWidget::addNode(graphlayout::LayoutNode const* node,
                                      QQuickItem *parent){
  QQuickItem* item = nullptr;
  if(graphicQmlNodeFromUuid(node->uuid().toString())==nullptr)
  {
    QQmlComponent dyn(_d->_engine,
                      QUrl::fromLocalFile(":/graphlayout/qml/GraphNode.qml"),
                      _d->_rootObject->findChild<QQuickItem*>("drawArea"));
    QObject *dynObject = dyn.create();
    item = qobject_cast<QQuickItem*>(dynObject);
    if(!item)
    {
      delete dynObject;
      return nullptr;
    }

  }else{
    item = qobject_cast<QQuickItem*>(graphicQmlNodeFromUuid(node->uuid().toString()));
    if(!item)
      return nullptr;
  }

  Q_ASSERT(item);

  QmlNode* nodeItem = qobject_cast<QmlNode*>(item);
  if(!nodeItem)
  {
    delete item;
    return nullptr;
  }

  nodeItem->setWidth(node->size().width());
  nodeItem->setHeight(node->size().height());
  nodeItem->setX(node->pos().x());
  nodeItem->setY(node->pos().y());

  nodeItem->setSkaleW(node->size().width());
  nodeItem->setSkaleH(node->size().height());
  nodeItem->setSkaleX(node->pos().x());
  nodeItem->setSkaleY(node->pos().y());

  if(node->nodes().isEmpty()==true){
    nodeItem->setZ(1003);
  }
  nodeItem->setUuid(node->externUuid());
  nodeItem->setShape(node->shape());
  nodeItem->setXLabel(node->xLabel());
  nodeItem->setColor(node->color());

  nodeItem->setBorderWidth(node->borderWidth());
  nodeItem->setBorderColor(node->borderColor());
  nodeItem->setTextSize(node->xLabelTextSize());
  nodeItem->setTextColor(node->xLabelColor());
  nodeItem->setTextFamily(this->_d->_textfamily.family());

  nodeItem->setToken(node->token());
  nodeItem->setTokenColor(node->tokenColor());

  item->setObjectName(node->objectName());

  item->setParent(parent);
  item->setParentItem(parent);

  QObject::connect(nodeItem,&QmlNode::nodeClicked,
                     this,&GraphQuickWidget::clickedObject);

  if(node->label()!=""){
    QQmlComponent dyn2(_d->_engine,
                       QUrl::fromLocalFile(":/graphlayout/qml/GraphText.qml"),item);
    QObject* dynObject2 = dyn2.create();
    QQuickItem *item2 = qobject_cast<QQuickItem*>(dynObject2);
    Q_ASSERT(item2);
    QObject* labelmousearea = item2->findChild<QObject*>("labelMouseArea");
    if (labelmousearea){
      labelmousearea->deleteLater();
    }

    item2->setProperty("text",node->label());
    item2->setProperty("textSize",node->labelTextSize());
    item2->setProperty("textColor",node->labelColor());
    item2->setProperty("textFamily",this->_d->_textfamily.family());
    item2->setProperty("uuid",node->externUuid());
    qreal newX = 0;
    qreal newY = 0;
    if(node->staticLabels()==false){

      newX = node->labelPos().x();
      if(node->labelPos().x()<node->pos().x()){
        QFont genFont(this->_d->_textfamily.family(), node->xLabelTextSize());
        QFontMetrics f1(genFont);
        QSize r1 = f1.size(0,node->label());
        QFont newFont(this->_d->_textfamily.family(), node->labelTextSize());
        QFontMetrics f2(newFont);
        QSize r2 = f2.size(0,node->label());
        qreal v = r1.width()/2 - r2.width()/2;
        newX = newX + v;

      }else if(node->labelPos().x()>node->pos().x()+node->size().width()){
        QFont genFont(this->_d->_textfamily.family(), node->xLabelTextSize());
        QFontMetrics f1(genFont);
        QSize r1 = f1.size(0,node->label());
        QFont newFont(this->_d->_textfamily.family(), node->labelTextSize());
        QFontMetrics f2(newFont);
        QSize r2 = f2.size(0,node->label());
        qreal v = r1.width()/2 - r2.width()/2;
        newX = newX - v;
      }
      newY = node->labelPos().y();
      if(node->labelPos().y()<node->pos().y()){
        QFont genFont(this->_d->_textfamily.family(), node->xLabelTextSize());
        QFontMetrics f1(genFont);
        QSize r1 = f1.size(0, node->label());
        QFont newFont(this->_d->_textfamily.family(), node->labelTextSize());
        QFontMetrics f2(newFont);
        QSize r2 = f2.size(0, node->label());
        qreal v = r1.height()/2 - r2.height()/2;
        newY = newY + v;

      }else if(node->labelPos().y()>node->pos().y()){
        QFont genFont(this->_d->_textfamily.family(), node->xLabelTextSize());
        QFontMetrics f1(genFont);
        QSize r1 = f1.size(0, node->label());
        QFont newFont(this->_d->_textfamily.family(), node->labelTextSize());
        QFontMetrics f2(newFont);
        QSize r2 = f2.size(0, node->label());
        qreal v = r1.height()/2 - r2.height()/2;
        newY = newY - v;
      }
      item2->setZ(1000);
    }else if(node->staticLabels()==true){
      QFont genFont(this->_d->_textfamily.family(), node->labelTextSize()-1);
      QFontMetrics f1(genFont);
      QSize r1 = f1.size(0, node->label());
      newX = item->position().x() + item->width() + r1.width()/2;
      newY = item->position().y() + r1.height()/2;
      item2->setProperty("z",5);
    }

    item2->setProperty("parentPosX",newX);
    item2->setProperty("parentPosY",newY);
    if(node->hideLabel()==false){
      item2->setObjectName("text_p");
    }
    item2->setParentItem(_d->_rootObject->findChild<QQuickItem*>("drawArea"));
    item2->setParent(_d->_rootObject->findChild<QQuickItem*>("drawArea"));
  }
  return nodeItem;
}//! Add a port
QQuickItem* GraphQuickWidget::addPort(const LayoutNodePort* port, QQuickItem *parent)
{
  QQmlComponent dyn(_d->_engine,
                    QUrl::fromLocalFile(":/graphlayout/qml/GraphNode.qml"),
                    _d->_rootObject->findChild<QQuickItem*>("drawArea"));
  QObject *dynObject = dyn.create();
  Q_ASSERT(dynObject);
  QQuickItem *item = qobject_cast<QQuickItem*>(dynObject);
  Q_ASSERT(item);

  if(port->pos()!=QPointF(0,0)){
    item->setX(port->pos().x());
    item->setY(port->pos().y());
  }
  item->setWidth(port->size().width());
  item->setHeight(port->size().height());
  item->setProperty("uuid",port->externUuid());
  item->setProperty("shape",port->shape());
  item->setProperty("color",port->color());

  item->setProperty("borderWidth",this->_d->_nodeBorderWidth);
  item->setProperty("borderColor",this->_d->_nodeBorderColor);
  item->setProperty("textSize",port->labelSize());
  //item->setProperty("textColor",this->_d->_nodeTextColor);
  item->setProperty("textFamily",this->_d->_textfamily);

  item->setObjectName(port->objectName());

  item->setParent(parent);
  item->setParentItem(parent);

  if(port->label()!=""){
    QQmlComponent dyn2(_d->_engine,
                       QUrl::fromLocalFile(":/graphlayout/qml/GraphText.qml"),item);
    QObject* dynObject2 = dyn2.create();
    QQuickItem *item2 = qobject_cast<QQuickItem*>(dynObject2);
    Q_ASSERT(item2);

    item2->setProperty("text",port->label());
    item2->setProperty("textSize",port->labelSize());
    item2->setProperty("textColor",QColor("black"));
    item2->setProperty("textFamily",this->_d->_textfamily);
    item2->setProperty("uuid",port->externUuid());

    item2->setProperty("parentPosX",port->labelPos().x());
    item2->setProperty("parentPosY",port->labelPos().y());
    item2->setParentItem(_d->_rootObject->findChild<QQuickItem*>("drawArea"));
    item2->setParent(_d->_rootObject->findChild<QQuickItem*>("drawArea"));
  }
  return item;
}
//! Set Zoom
qreal GraphQuickWidget::getZoom(){
  QQuickItem* zoomItem = this->_d->_rootObject->findChild<QQuickItem*>("zoomObject");
  if(!zoomItem){
    return 0;
  }
  return qvariant_cast<qreal>(zoomItem->property("skale"));
}
void GraphQuickWidget::setZoom(const double zoom, const double setX, const double setY){
  QQuickItem* zoomItem = this->_d->_rootObject->findChild<QQuickItem*>("zoomObject");
  if(!zoomItem){
    return;
  }
  if(setX != 0){
    zoomItem->setX(setX);
  }
  if(setY != 0){
    zoomItem->setY(setY);
  }
  zoomItem->setProperty("skale",zoom);
}
void GraphQuickWidget::zoomIn(){
  this->setZoom(this->getZoom() + 0.1);
}
void GraphQuickWidget::zoomOut(){
  this->setZoom(this->getZoom() - 0.1);
}
void GraphQuickWidget::zoomReset(){
  this->setZoom(1);
}
void GraphQuickWidget::zoomFull(){
  qreal zoomscale = this->_d->_rootObject->width()/this->_d->_layoutGraph->graphSize().width();
  if(zoomscale > this->_d->_rootObject->height()/this->_d->_layoutGraph->graphSize().height())
    zoomscale = this->_d->_rootObject->height()/this->_d->_layoutGraph->graphSize().height();
  this->setZoom(zoomscale,0.01,0.01);
}
void GraphQuickWidget::zoomWidth(){
  qreal zoomscale = this->_d->_rootObject->width()/this->_d->_layoutGraph->graphSize().width();
  this->setZoom(zoomscale,0.01,0.0);
}
void GraphQuickWidget::zoomHeight(){
  qreal zoomscale = this->_d->_rootObject->height()/this->_d->_layoutGraph->graphSize().height();
  this->setZoom(zoomscale,0.0,0.01);
}

//! Hide/Show Labels dependent on zoomLevel
void GraphQuickWidget::zoomLevel()
{
  qreal actualzoom = this->getZoom();

  if(this->_d->_layoutGraph->graphSize().width() / actualzoom > 500){
    this->showLabel(false);
  }else{
    this->showLabel(true);
  }
}

//! Clicked Object
void GraphQuickWidget::clickedObject(const QUuid &uuid){
  if(this->_d->_force_labels==true)
    return;
  //qDebug()<<"graphquickwidget clicked: "<<uuid;
  emit selectedItem(uuid);
  unhighlightAllGraphicItems();
  highlightItemByUuid(uuid,true);
}

void GraphQuickWidget::unhighlightAllGraphicItems()
{
  for(LayoutNode* currLayoutNode : this->_d->_highlightedNodes.keys())
  {
    QQuickItem* currQuickNode = this->_d->_highlightedNodes.value(currLayoutNode);
    Q_ASSERT(currQuickNode);

    currQuickNode->setProperty("color",currLayoutNode->color());
    currQuickNode->setProperty("borderColor",currLayoutNode->borderColor());
    currQuickNode->setProperty("borderWidth",currLayoutNode->borderWidth());
  }
  this->_d->_highlightedNodes.clear();

  for(LayoutEdge* currLayoutEdge : this->_d->_highlightedEdges.keys())
  {
    QQuickItem* currQuickEdge = this->_d->_highlightedEdges.value(currLayoutEdge);
    Q_ASSERT(currQuickEdge);

    currQuickEdge->setProperty("lineColor",currLayoutEdge->color());
  }
  this->_d->_highlightedEdges.clear();

  return;
}

void GraphQuickWidget::highlightItemByUuid(const QUuid& itemUuid, const bool enabled)
{
  //  qDebug()<<"GraphQuickWidget::highlightItemByUuid() executed!";

  LayoutNode* currentNode = nullptr;
  currentNode = this->_d->_layoutGraph->nodeByExternUuid(itemUuid);
  if(currentNode){
    QObject* graphicQmlNode = graphicQmlNodeFromUuid(itemUuid);
    if(graphicQmlNode){
      QmlNode* nodeItem = qobject_cast<QmlNode*>(graphicQmlNode);
      Q_ASSERT(nodeItem);
      if(enabled==true){
        nodeItem->setColor(currentNode->highlightColor());
        nodeItem->setBorderColor(currentNode->highlightBorderColor());
        nodeItem->setBorderWidth(currentNode->highlightBorderWidth());
        this->_d->_highlightedNodes.insert(currentNode, nodeItem);
        if(this->_d->_zoomToActive==true)
          this->zoomToItem(nodeItem);
      }else{
        nodeItem->setColor(currentNode->color());
        nodeItem->setBorderColor(currentNode->borderColor());
        nodeItem->setBorderWidth(currentNode->borderWidth());
        this->_d->_highlightedNodes.remove(currentNode);
      }
      return;
    }
  }

  LayoutEdge* currentEdge = nullptr;
  currentEdge = this->_d->_layoutGraph->edgeByExternUuid(itemUuid);
  if(currentEdge){
    QObject* edge = graphicQmlEdgeFromUuid(itemUuid);
    if(edge){
      QQuickItem* edgeItem = qobject_cast<QQuickItem*>(edge);
      if(enabled==true){
        edgeItem->setProperty("lineColor",currentEdge->highlightColor());
        this->_d->_highlightedEdges.insert(currentEdge, edgeItem);
        if(this->_d->_zoomToActive==true)
          this->zoomToItem(edgeItem);
      }else{
        edgeItem->setProperty("lineColor",currentEdge->color());
        this->_d->_highlightedEdges.remove(currentEdge);
      }
      return;
    }
  }
  
  return;
}

void GraphQuickWidget::highlightItemByName(const QString& itemName, const bool enabled)
{
  //qDebug()<<"GraphQuickWidget::highlightItemByName() executed!";

  LayoutNode* currentNode = nullptr;
  currentNode = this->_d->_layoutGraph->nodeByName(itemName);
  if(currentNode){
    QObject* graphicQmlNode = graphicQmlNodeFromUuid(currentNode->externUuid());
    if(graphicQmlNode){
      QQuickItem* nodeItem = qobject_cast<QQuickItem*>(graphicQmlNode);
      Q_ASSERT(nodeItem);
      if(enabled==true){
        nodeItem->setProperty("color",currentNode->highlightColor());
        nodeItem->setProperty("borderColor",currentNode->highlightBorderColor());
        nodeItem->setProperty("borderWidth",currentNode->highlightBorderWidth());
        this->_d->_highlightedNodes.insert(currentNode, nodeItem);
        if(this->_d->_zoomToActive==true)
          this->zoomToItem(nodeItem);
      }else{
        nodeItem->setProperty("color",currentNode->color());
        nodeItem->setProperty("borderColor",currentNode->borderColor());
        nodeItem->setProperty("borderWidth",currentNode->borderWidth());
        this->_d->_highlightedNodes.remove(currentNode);
      }
      return;
    }
  }

  LayoutEdge* currentEdge = nullptr;
  currentEdge = this->_d->_layoutGraph->edgeByExternUuid(itemName);
  if(currentEdge){
    QObject* edge = graphicQmlEdgeFromUuid(currentEdge->externUuid());
    if(edge){
      QQuickItem* edgeItem = qobject_cast<QQuickItem*>(edge);
      if(enabled==true){
        edgeItem->setProperty("lineColor",currentEdge->highlightColor());
        this->_d->_highlightedEdges.insert(currentEdge, edgeItem);
        if(this->_d->_zoomToActive==true)
          this->zoomToItem(edgeItem);
      }else{
        edgeItem->setProperty("lineColor",currentEdge->color());
        this->_d->_highlightedEdges.remove(currentEdge);
      }
      return;
    }
  }

  return;
}

void GraphQuickWidget::highlightGraphicItemByUuid(const QUuid& itemUuid,
                                                     bool highlight,
                                                     bool unhighlightOtherItems)
{
  if(unhighlightOtherItems)
    this->unhighlightAllGraphicItems();

  this->highlightItemByUuid(itemUuid, highlight);

  return;
}

void GraphQuickWidget::highlightGraphicItemsByUuids(const QList<QUuid>& itemUuids,
                                                       bool highlight,
                                                       bool unhighlightOtherItems)
{
  if(unhighlightOtherItems)
    this->unhighlightAllGraphicItems();

  for(const QUuid& currItemUuid : itemUuids)
    this->highlightItemByUuid(currItemUuid, highlight);

  return;
}

void GraphQuickWidget::highlightGraphicItemByName(const QString& itemName,
                                                     bool highlight,
                                                     bool unhighlightOtherItems)
{
  if(unhighlightOtherItems)
    this->unhighlightAllGraphicItems();

  this->highlightItemByName(itemName, highlight);

  return;
}

void GraphQuickWidget::highlightGraphicItemsByNames(const QList<QString> &itemNames,
                                                       bool highlight,
                                                       bool unhighlightOtherItems)
{
  if(unhighlightOtherItems)
    this->unhighlightAllGraphicItems();

  for(const QString& currItemName : itemNames)
    this->highlightItemByName(currItemName, highlight);

  return;
}

void GraphQuickWidget::zoomToItem(QQuickItem *item){
  QRectF zoomwindow(0,0,0,0);
  zoomwindow.setX(qvariant_cast<double>(item->property("skaleX")) - 100);
  zoomwindow.setY(qvariant_cast<double>(item->property("skaleY")) - 100);
  zoomwindow.setWidth(qvariant_cast<double>(item->property("skaleW")) + 200);
  zoomwindow.setHeight(qvariant_cast<double>(item->property("skaleH")) + 200);

  double zoomscale = this->_d->_rootObject->width()/zoomwindow.width();
  if(zoomscale > this->_d->_rootObject->height()/zoomwindow.height()){
    zoomscale = this->_d->_rootObject->height()/zoomwindow.height();
  }

  this->setZoom(zoomscale,-zoomwindow.x()*zoomscale,-zoomwindow.y()*zoomscale);
}
void GraphQuickWidget::showLabels(bool enabled){
  this->showLabel(enabled);
}
void GraphQuickWidget::showLabel(bool enabled){
  if(enabled==true){
    for(QQuickItem* item: _d->_rootObject->findChildren<QQuickItem*>("text"))
    {
      item->setProperty("visible",true);
    }
  }else{
    for(QQuickItem* item: _d->_rootObject->findChildren<QQuickItem*>("text"))
    {
      item->setProperty("visible",false);
    }
  }
}

void GraphQuickWidget::zoomToActiveEnabled(const bool enabled){
  this->_d->_zoomToActive = enabled;
}
void GraphQuickWidget::toggleLabel(const bool enabled){
  this->showLabel(enabled);
}

void GraphQuickWidget::setZoomBound(double zoom){
  Q_UNUSED(zoom);
  return;
}
double GraphQuickWidget::zoomBound(){
  return 0;
}
void GraphQuickWidget::setGraphvizPath(QString path){
  this->_d->_graphvizPath=path;
}
void GraphQuickWidget::setAlgorithm(GraphvizAlgorithm algorithm){
  this->_d->_graphvizAlgorithm=algorithm;
}
void GraphQuickWidget::setZoomType(const QString& type){
  this->_d->_zoomType=type;
}
void GraphQuickWidget::setBackgroundColor(QColor color){
  this->_d->_backgroundColor=color;
}
void GraphQuickWidget::setTitleColor(QColor color){
  this->_d->_titleTextColor=color;
}
void GraphQuickWidget::setTitleSize(int textsize){
  this->_d->_titleTextSize=textsize;
}
void GraphQuickWidget::setTitleShape(ShapeEnum shape){
  this->_d->_titleShape=shape;
}
void GraphQuickWidget::setTitleBorderColor(QColor color){
  this->_d->_titleBorderColor = color;
}
void GraphQuickWidget::setTitleBorderWidth(double width){
  this->_d->_titleBorderWidth = width;
}
void GraphQuickWidget::setTitleBackgroundColor(QColor color){
  this->_d->_titleBackgroundColor = color;
}
void GraphQuickWidget::layoutNoChecks(){
  QString error = "";
  this->layout(&error);
}
bool GraphQuickWidget::saveCurrentViewPicture(const QString& path){
  QPixmap pixmap(this->size());
  this->render(&pixmap);
  bool success =  pixmap.save(path,nullptr,100);
  if (success == true)
    qDebug()<<"Image saved"<<path;
  else
    qDebug()<<"Error while image saving";
  return success;
}
bool GraphQuickWidget::saveGraphPicture(const QString& path){
  QQuickItem* zoomObject = _d->_rootObject->findChild<QQuickItem*>("zoomObject");
  Q_ASSERT(zoomObject);
  QSharedPointer<QQuickItemGrabResult> grabObject = zoomObject->grabToImage(this->_d->_layoutGraph->graphSize().toSize());
  QTimer timeout;
  timeout.setSingleShot(true);
  QEventLoop loop;
  QObject::connect(grabObject.data(), &QQuickItemGrabResult::ready,
                   &loop, &QEventLoop::quit);
  QObject::connect(&timeout, &QTimer::timeout,
                   &loop, &QEventLoop::quit);
  timeout.start(10000);
  loop.exec();
  if(timeout.isActive()){
    bool success =  grabObject.data()->saveToFile(path);
    if (success == true)
      qDebug()<<"Image saved"<<path;
    else
      qDebug()<<"Error while image saving";
    return success;
  }else{
    qDebug()<<"Error while image saving - timeout";
    return false;
  }

}
void GraphQuickWidget::saveCurrentViewAsPicture(){
  QString location = QFileDialog::getSaveFileName(this,"Save Graphic","","PNG(*.png);;BMP(*.bmp);;JPG(*.jpg);;JPEG(*.jpeg);;PPM(*.ppm);;XBM(*.xbm);;XPM(*.xpm)");
  if(location != "")
    this->saveCurrentViewPicture(location);
}
void GraphQuickWidget::saveGraphAsPicture(){
  QString location = QFileDialog::getSaveFileName(this,"Save Graphic","","PNG(*.png);;BMP(*.bmp);;JPG(*.jpg);;JPEG(*.jpeg);;PPM(*.ppm);;XBM(*.xbm);;XPM(*.xpm)");
  if(location != "")
    this->saveGraphPicture(location);
}
void GraphQuickWidget::resetSavePicture(){
  this->_d->_saveActive=false;
}

void GraphQuickWidget::contextMenuEvent(QContextMenuEvent* event){
  QMenu menu(this);
  QMenu* zoomMenu = menu.addMenu(QIcon(QLatin1String(":/mobata/images/zoomin_dark.png")),"zoom");
  QAction* zoomFullAction = zoomMenu->addAction(QIcon(QLatin1String(":/mobata/images/zoominview_dark.png")),"fit in view");
  QAction* zoomResetAction = zoomMenu->addAction(QIcon(QLatin1String(":/mobata/images/zoomreset_dark.png")),"reset");
  QAction* zoomWidthAction = zoomMenu->addAction(QIcon(QLatin1String(":/mobata/images/zoomwidth_dark.png")),"fit to width");
  QAction* zoomHeightAction = zoomMenu->addAction(QIcon(QLatin1String(":/mobata/images/zoomheight_dark.png")),"fit to height");
  QObject::connect(zoomFullAction, &QAction::triggered,
                   this, &GraphQuickWidget::zoomFull);
  QObject::connect(zoomResetAction, &QAction::triggered,
                   this, &GraphQuickWidget::zoomReset);
  QObject::connect(zoomWidthAction, &QAction::triggered,
                   this, &GraphQuickWidget::zoomWidth);
  QObject::connect(zoomHeightAction, &QAction::triggered,
                   this, &GraphQuickWidget::zoomHeight);
  QMenu* saveMenu = menu.addMenu(QIcon(QLatin1String(":/mobata/images/save_picture.png")),"save as image");
  QAction* saveFull = saveMenu->addAction(QIcon(QLatin1String(":/mobata/images/save_picture.png")),"save full graph");
  QAction* saveView = saveMenu->addAction(QIcon(QLatin1String(":/mobata/images/save_picture.png")),"save current view");
  QObject::connect(saveFull, &QAction::triggered,
                   this, &GraphQuickWidget::saveGraphAsPicture);
  QObject::connect(saveView, &QAction::triggered,
                   this, &GraphQuickWidget::saveCurrentViewAsPicture);

  QMenu* exportMenu = menu.addMenu(QIcon(QLatin1String(":/mobata/images/export.png")),"export as dot");
  QAction* exportGraphWithLabels = exportMenu->addAction(QIcon(QLatin1String(":/mobata/images/export.png")),"with edgelabels");
  QObject::connect(exportGraphWithLabels, &QAction::triggered,
                   this, &GraphQuickWidget::exportGraphWithEdgeLabels);
  QAction* exportGraphWithoutLabels = exportMenu->addAction(QIcon(QLatin1String(":/mobata/images/export.png")),"without edgelabels");
  QObject::connect(exportGraphWithoutLabels, &QAction::triggered,
                   this, &GraphQuickWidget::exportGraphWithoutEdgeLabels);

  menu.exec(event->globalPos());
}

void GraphQuickWidget::exportGraphWithEdgeLabels()
{
  QString location = QFileDialog::getSaveFileName(this,"Export Graphic","","dot(*.dot)");
  if(location == "")
    return;

  return this->exportGraph(location, true);
}

void GraphQuickWidget::exportGraphWithoutEdgeLabels(){
  QString location = QFileDialog::getSaveFileName(this,"Export Graphic","","dot(*.dot)");
  if(location == "")
    return;

  return this->exportGraph(location, false);
}

void GraphQuickWidget::exportGraph(const QString& fileName,
                                   bool withEdgelLabels)
{
  QString graphFileName = fileName;
  if(graphFileName.isEmpty())
    return;

  if(!graphFileName.endsWith(QLatin1String(".dot")))
    graphFileName.append(QLatin1String(".dot"));

  QString graphString;
  graphlayout::ComExportGraph comExport(this->_d->_layoutGraph,
                                        &graphString);
  comExport.setWithEdgeLabels(withEdgelLabels);

  QString errorString;
  bool result = comExport.execute(&errorString);
  if(!result){
    qWarning()<<errorString;
    return;
  }

  QFile file(graphFileName);
  if(file.open(QIODevice::WriteOnly)){
      QTextStream stream(&file);
      stream<<graphString;
  }else{
      qWarning()<<"could not write graphviz file: "<<graphFileName;
      return;
  }

  return;
}
