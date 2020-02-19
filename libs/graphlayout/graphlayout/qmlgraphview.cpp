#include "qmlgraphview.hpp"

#include "layoutnode.hpp"
#include "layoutedge.hpp"
#include "comcreatelayout.hpp"
#include "comcreatelayoutedgesonly.hpp"

#include <QtQuick>
#include <QtWidgets>
#include <QQuickWidget>
#include <QQuickItem>
#include <QStringList>
#include <QList>

#include <QFileDialog>
#include <QDebug>

#include <mobata/memory_leak_start.hpp>

//inline void initMyResource() { Q_INIT_RESOURCE(graphlayout); }

using namespace graphlayout;

class QmlGraphView::QmlGraphViewVars{
  friend class QmlGraphView;
public:
  QmlGraphViewVars(){}

  graphlayout::LayoutGraph* _graph;
  graphlayout::GraphvizAlgorithm _algorithm;

  QString _lastGraphvizLog = "";

  QQuickItem* _rootObject;
  QQmlEngine* _engine;

  QString _graphvizPath;

  bool _propertiesMenu = false;
  double _zoomBound= 0.99;
  QString _zoomType = "zoom_full";

  float _nodeBorderWidth = 2;
  QColor _nodeBorderColor = QColor("black");

  float _edgeWidth = 2;
  float _edgeArrowSize = 15;

  //! Title
  float _titleTextSize = 20;
  QColor _titleTextColor = QColor("black");
  QColor _titleBackgroundColor = QColor("white");
  ShapeEnum _titleShape = Plaintext;
  QColor _titleBorderColor = QColor("black");
  double _titleBorderWidth = 2.0;
  QColor _backgroundColor = QColor("white");

  //! Infobox
  QColor _infoboxBackgroundcolor = QColor("white");
  QColor _infoboxTextcolor = QColor("black");
  int _infoboxTextsize = 12;

  QFont _textfamily = QFont("Times-Roman");

  //!highlighted items
  QHash<LayoutNode*, QQuickItem*> _highlightedNodes;
  QHash<LayoutEdge*, QQuickItem*> _highlightedEdges;
};


QmlGraphView::QmlGraphView(QQuickView *view,
                           graphlayout::LayoutGraph *graph,
                           graphlayout::GraphvizAlgorithm algorithm,
                           QObject* parent)
  :QObject(parent), _d(new QmlGraphViewVars())
{
  view->setResizeMode(QQuickView::SizeRootObjectToView);
  view->setSource(QUrl("qrc:/graphlayout/qml/graph_main.qml"));
  this->_d->_engine=view->engine();
  this->_d->_algorithm=algorithm;
  this->_d->_graph = graph;
  this->_d->_rootObject =view->rootObject();
  QQuickItem* item = _d->_rootObject->findChild<QQuickItem*>("zoomObject");
  QObject::connect(item,SIGNAL(scaleChanged()),this,SLOT(zoomLevelSlot()));
//  initMyResource();
}
QmlGraphView::QmlGraphView(QQuickWidget *widget,
                           graphlayout::LayoutGraph *graph,
                           graphlayout::GraphvizAlgorithm algorithm,
                           QObject* parent)
  :QObject(parent), _d(new QmlGraphViewVars())
{
  widget->setResizeMode(QQuickWidget::SizeRootObjectToView);
  widget->setSource(QUrl("qrc:/graphlayout/qml/main.qml"));
  this->_d->_engine=widget->engine();
  this->_d->_algorithm=algorithm;
  this->_d->_graph = graph;
  this->_d->_rootObject =widget->rootObject();
  QQuickItem* item = _d->_rootObject->findChild<QQuickItem*>("zoomObject");
  QObject::connect(item,SIGNAL(scaleChanged()),this,SLOT(zoomLevelSlot()));
//  initMyResource();
}

QmlGraphView::~QmlGraphView()
{
  delete this->_d;
}
const QString& QmlGraphView::lastLog() const
{
  return this->_d->_lastGraphvizLog;
}

void QmlGraphView::reset()
{
  for(QQuickItem* item :
      _d->_rootObject->findChildren<QQuickItem*>(QRegExp("text*",
                                                         Qt::CaseSensitive,
                                                         QRegExp::Wildcard))){
    item->deleteLater();
    item->setProperty("uuid",0);
  }
  for(QQuickItem* item : _d->_rootObject->findChildren<QQuickItem*>("edge")){
    if(this->_d->_graph->edgeByExternUuid(QUuid(qvariant_cast<QString>(item->property("uuid"))))==nullptr)
      item->deleteLater();
  }
  for(QQuickItem* item : _d->_rootObject->findChildren<QQuickItem*>("port")){
    LayoutNodePort* port = this->_d->_graph->port(QUuid(qvariant_cast<QString>(item->property("uuid"))));
    if(port!=nullptr)
      port->setPos(QPointF(0,0));
    item->setProperty("uuid",0);
    item->deleteLater();
  }
  for(QQuickItem* item : _d->_rootObject->findChildren<QQuickItem*>(QRegExp("node*",
                                                                            Qt::CaseSensitive,
                                                                            QRegExp::Wildcard))){
    if(this->_d->_graph->nodeByExternUuid(QUuid(qvariant_cast<QString>(item->property("uuid"))))==nullptr){
      item->setProperty("uuid",0);
      item->deleteLater();
    }
  }

  return;
}

bool QmlGraphView::layout(QString* errorString)
{
  QTime myTimer;
  myTimer.start();

  this->reset();

  graphlayout::ComCreateLayout graphviz(_d->_graph,_d->_algorithm,_d->_graphvizPath);
  this->_d->_lastGraphvizLog = "";
  bool result = graphviz.execute(errorString, &this->_d->_lastGraphvizLog);
  if(!result)
    return false;

  QmlGraphView::addNodesFromList(_d->_graph->nodes(),_d->_rootObject->findChild<QQuickItem*>("drawArea"));
  QmlGraphView::addEdgesFromList(_d->_graph->edges());

  if(this->_d->_graph->allPorts().isEmpty()==false){
    graphlayout::ComCreateLayoutEdgesOnly graphvizEdge(_d->_graph,_d->_algorithm,_d->_graphvizPath);
    graphvizEdge.execute(errorString, &this->_d->_lastGraphvizLog);
    foreach(QQuickItem* item, _d->_rootObject->findChildren<QQuickItem*>(QRegExp("text*",Qt::CaseSensitive,QRegExp::Wildcard))){
      item->deleteLater();
      item->setProperty("uuid",0);
    }
    foreach(QQuickItem* item, _d->_rootObject->findChildren<QQuickItem*>("edge")){
      item->deleteLater();
    }
    foreach(QQuickItem* item, _d->_rootObject->findChildren<QQuickItem*>("port")){
      item->setProperty("uuid",0);
      item->deleteLater();
    }
    foreach(QQuickItem* item, _d->_rootObject->findChildren<QQuickItem*>(QRegExp("node*",Qt::CaseSensitive,QRegExp::Wildcard))){
      item->setProperty("uuid",0);
      item->deleteLater();
    }
    QmlGraphView::addNodesFromList(_d->_graph->nodes(),_d->_rootObject->findChild<QQuickItem*>("drawArea"));
    QmlGraphView::addEdgesFromList(_d->_graph->edges());
    foreach(LayoutNodePort* port, _d->_graph->allPorts()){
      if(port->pos()==QPointF(0,0)){
        port->setPos(_d->_graph->portParentNode(port->externUuid())->pos());
      }
    }
  }
  this->_d->_rootObject->setProperty("color",_d->_backgroundColor);
  QObject* drawArea = _d->_rootObject->findChild<QObject*>("drawArea");
  QQuickItem *quickDrawArea = qobject_cast<QQuickItem*>(drawArea);

  if(_d->_rootObject->findChild<QObject*>("graphTitle")){
    _d->_rootObject->findChild<QObject*>("graphTitle")->setProperty("xLabel",_d->_graph->name());
    _d->_rootObject->findChild<QObject*>("graphTitle")->setProperty("textColor",_d->_titleTextColor);
    _d->_rootObject->findChild<QObject*>("graphTitle")->setProperty("textSize",_d->_titleTextSize);
    _d->_rootObject->findChild<QObject*>("graphTitle")->setProperty("textFamily",_d->_textfamily.family());
    _d->_rootObject->findChild<QObject*>("graphTitle")->setProperty("shape",_d->_titleShape);
    _d->_rootObject->findChild<QObject*>("graphTitle")->setProperty("color",_d->_titleBackgroundColor);
    _d->_rootObject->findChild<QObject*>("graphTitle")->setProperty("borderWidth",_d->_titleBorderWidth);
    _d->_rootObject->findChild<QObject*>("graphTitle")->setProperty("borderColor",_d->_titleBorderColor);
    QFont genFont(this->_d->_textfamily.family(), _d->_titleTextSize);
    QFontMetrics f1(genFont);
    QSize r1 = f1.size(0,_d->_graph->name());
    _d->_rootObject->findChild<QObject*>("graphTitle")->setProperty("width",r1.width()+_d->_nodeBorderWidth*2);
    _d->_rootObject->findChild<QObject*>("graphTitle")->setProperty("height",r1.height()+_d->_nodeBorderWidth*2);
  }else{
    QQmlComponent dyn(_d->_engine,QUrl("qrc:/graphlayout/qml/GraphNode.qml"),_d->_rootObject->findChild<QQuickItem*>("drawArea"));
    QObject *dynObject = dyn.create();
    QQuickItem *item = qobject_cast<QQuickItem*>(dynObject);
    item->setX(10);
    item->setY(10);
    item->setProperty("uuid","1234");
    item->setProperty("shape",_d->_titleShape);
    item->setProperty("xLabel",_d->_graph->name());
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
    QSize r1 = f1.size(0,_d->_graph->name());
    item->setWidth(r1.width()+_d->_nodeBorderWidth*2);
    item->setHeight(r1.height()+_d->_nodeBorderWidth*2);
  }


  this->setZoom();

  if(*errorString!="")
    qDebug()<<*errorString;
//  qDebug()<<"Layout time: " << myTimer.elapsed()<<" ms";

  return true;
}
//! Call the addNode function foreach node
void QmlGraphView::addNodesFromList(const QList<graphlayout::LayoutNode*>& list,
                                    QQuickItem *parent){
  for(graphlayout::LayoutNode const* node : list) {
    QQuickItem *item = this->addNode(node, parent);
    if(node->nodes().isEmpty() == false){
      this->addNodesFromList(node->nodes(), item);
    }
    if(node->ports().isEmpty() == false){
      foreach (LayoutNodePort* port, node->ports()) {
        if(this->_d->_graph->allUsedPorts().contains(port)){
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
void QmlGraphView::addEdgesFromList(const QList<graphlayout::LayoutEdge*>& list){
  for(graphlayout::LayoutEdge const* edge : list) {
    this->addEdge(edge);
  }

  return;
}

//! Return QObject node for the given uuid
QObject* QmlGraphView::graphicQmlNodeFromUuid(const QUuid& uuid)
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
QObject* QmlGraphView::graphicQmlEdgeFromUuid(const QUuid& uuid)
{
  for (QObject* object : _d->_rootObject->findChildren<QObject*>("edge")) {
    if(object->property("uuid")==uuid){
      return object;
    }
  }
  return nullptr;
}
//! Return QObject port for the given uuid
QObject* QmlGraphView::graphicQmlPortFromUuid(const QUuid& uuid)
{
  for (QObject* object : _d->_rootObject->findChildren<QObject*>("port")) {
    if(object->property("uuid")==uuid){
      return object;
    }
  }
  return nullptr;
}
//! Return the QObject label from a node with the given uuid
QObject* QmlGraphView::graphicQmlLabelFromUuid(const QUuid& uuid)
{
  for (QObject* object : _d->_rootObject->findChildren<QObject*>("text")) {
    if(object->property("uuid")==uuid){
      return object;
    }
  }
  return nullptr;
}
//! Add a Edge
QQuickItem* QmlGraphView::addEdge(LayoutEdge const* edge)
{
  if(edge->points().length()>=2 && edge->type()!=Invisible){
    QQuickItem *item = nullptr;
    if(graphicQmlEdgeFromUuid(edge->uuid().toString()) == nullptr){
      QQmlComponent dyn(_d->_engine,QUrl("qrc:/graphlayout/qml/GraphEdge.qml"),
                        _d->_rootObject->findChild<QObject*>("drawArea"));
      QObject *dynObject = dyn.create();
      item = qobject_cast<QQuickItem*>(dynObject);
    }else{
      item = qobject_cast<QQuickItem*>(graphicQmlEdgeFromUuid(edge->uuid().toString()));
    }
    if(item == nullptr)
      return nullptr;

    item->setProperty("itemAuuid",edge->source()->externUuid());
    item->setProperty("itemBuuid",edge->target()->externUuid());

    QSizeF mouseAreaSize;
    QRectF linePos(edge->points().first()->x(),edge->points().first()->y(),0,0);
    foreach (QPointF* poi, edge->points()) {
      if(linePos.x()>poi->x())
        linePos.setX(poi->x());
      if(linePos.y()>poi->y())
        linePos.setY(poi->y());
    }
    foreach (QPointF* poi, edge->points()) {
      if(linePos.width()<poi->x()-linePos.left())
        linePos.setWidth(poi->x()-linePos.left());
      if(linePos.height()<poi->y()-linePos.top())
        linePos.setHeight(poi->y()-linePos.top());
    }

    mouseAreaSize.setWidth(linePos.width());
    mouseAreaSize.setHeight(linePos.height());

    linePos.setX(linePos.x()-20-edge->Arrowsize());
    linePos.setY(linePos.y()-20-edge->Arrowsize());
    linePos.setWidth(linePos.width()+40+edge->Arrowsize()*2);
    linePos.setHeight(linePos.height()+40+edge->Arrowsize()*2);

    QList<QVariant> pointlist;
    foreach (QPointF* poi, edge->points()) {
      pointlist.append(QVariant::fromValue(poi->toPoint()));
    }
    item->setProperty("points",pointlist);
    item->setX(linePos.x());
    item->setY(linePos.y());
    item->setWidth(linePos.width());
    item->setHeight(linePos.height());
    item->setProperty("splines",_d->_graph->splines());

    QQuickItem* mouseArea = item->findChild<QQuickItem*>("thisMouseArea");
    if(mouseArea){
      mouseArea->setX(20+edge->Arrowsize());
      mouseArea->setY(20+edge->Arrowsize());
      mouseArea->setWidth(mouseAreaSize.width());
      mouseArea->setHeight(mouseAreaSize.height());
      if(mouseArea->width()< 6){
        mouseArea->setX(mouseArea->x()-3);
        mouseArea->setWidth(6);
      }
      if(mouseArea->height()< 6){
        mouseArea->setY(mouseArea->y()-3);
        mouseArea->setHeight(6);
      }
    }

    item->setProperty("lineColor",edge->color());
    item->setProperty("lineWidth",edge->lineWidth());
    item->setProperty("arrowSize",edge->Arrowsize());
    item->setProperty("uuid",edge->externUuid());
    item->setProperty("type",edge->type());
    item->setParent(_d->_rootObject->findChild<QQuickItem*>("drawArea"));
    item->setParentItem(_d->_rootObject->findChild<QQuickItem*>("drawArea"));

    item->setProperty("infoBox",edge->showInfobox());
    if(edge->showInfobox()==true){
      QObject::connect(item,SIGNAL(showInfoBox(QString)),this,SLOT(infoBoxEdge(QString)));
    }else{
      QQuickItem* mouseArea = item->findChild<QQuickItem*>("thisMouseArea");
      if(mouseArea)
        mouseArea->deleteLater();
    }

    if(edge->label()!=""){
      QQmlComponent dyn2(_d->_engine,QUrl("qrc:/graphlayout/qml/GraphText.qml"),item);
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
      }else if(edge->staticLabel()==true && this->_d->_graph->splines()==straight){
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
          newX = edge->points()[qCeil(edge->points().length()/2)]->x();
          newY = edge->points()[qCeil(edge->points().length()/2)]->y();
        }else{
          newX = (edge->points().first()->x()+edge->points().last()->x())/2;
          newY = (edge->points().first()->y()+edge->points().last()->y())/2;
        }
        newX += r1.width()/2;
        newY += r1.height();
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
        this->_d->_graph->port(edge->targetPort()->externUuid())->setPos(QPointF(qvariant_cast<float>(port->property("x")),qvariant_cast<float>(port->property("y"))));
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
        this->_d->_graph->port(edge->sourcePort()->externUuid())->setPos(QPointF(qvariant_cast<float>(port->property("x")),qvariant_cast<float>(port->property("y"))));
      }
    }
    return item;
  }else{
    return nullptr;
  }
}
//! Add a node
QQuickItem* QmlGraphView::addNode(graphlayout::LayoutNode const* node,
                                  QQuickItem *parent){
  QQuickItem* item = nullptr;
  if(graphicQmlNodeFromUuid(node->uuid().toString())==nullptr){
    QQmlComponent dyn(_d->_engine,
                      QUrl("qrc:/graphlayout/qml/GraphNode.qml"),
                      _d->_rootObject->findChild<QQuickItem*>("drawArea"));
    QObject *dynObject = dyn.create();
    item = qobject_cast<QQuickItem*>(dynObject);
  }else{
    item = qobject_cast<QQuickItem*>(graphicQmlNodeFromUuid(node->uuid().toString()));
  }
  if(item == nullptr)
    return nullptr;

  item->setWidth(node->size().width());
  item->setHeight(node->size().height());
  item->setX(node->pos().x());
  item->setY(node->pos().y());
  if(node->nodes().isEmpty()==true)
    item->setZ(2);
  item->setProperty("uuid",node->externUuid());
  item->setProperty("shape",node->shape());
  item->setProperty("xLabel",node->xLabel());
  item->setProperty("color",node->color());

  item->setProperty("borderWidth",node->borderWidth());
  item->setProperty("borderColor",node->borderColor());
  item->setProperty("textSize",node->xLabelTextSize());
  item->setProperty("textColor",node->xLabelColor());
  item->setProperty("textFamily",this->_d->_textfamily.family());

  item->setProperty("token",node->token());
  item->setProperty("tokencolor",node->tokenColor());

  item->setObjectName(node->objectName());

  item->setParent(parent);
  item->setParentItem(parent);

  item->setProperty("infoBox",node->showInfobox());
  if(node->showInfobox()==true){
    QObject::connect(item,SIGNAL(showInfoBox(QString)),
                     this,SLOT(infoBox(QString)));
  }else{
    QQuickItem* mouseArea = item->findChild<QQuickItem*>("thisMouseArea");
    if(mouseArea)
      mouseArea->deleteLater();
  }

  if(node->label()!=""){
    QQmlComponent dyn2(_d->_engine,QUrl("qrc:/graphlayout/qml/GraphText.qml"),item);
    QObject* dynObject2 = dyn2.create();
    QQuickItem *item2 = qobject_cast<QQuickItem*>(dynObject2);
    Q_ASSERT(item2);

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
  return item;
}//! Add a port
QQuickItem* QmlGraphView::addPort(const LayoutNodePort* port, QQuickItem *parent)
{
  QQmlComponent dyn(_d->_engine,QUrl("qrc:/graphlayout/qml/GraphNode.qml"),_d->_rootObject->findChild<QQuickItem*>("drawArea"));
  QObject *dynObject = dyn.create();
  QQuickItem *item = qobject_cast<QQuickItem*>(dynObject);
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
    QQmlComponent dyn2(_d->_engine,QUrl("qrc:/graphlayout/qml/GraphText.qml"),item);
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
void QmlGraphView::setZoom(QString zoomType){
  bool ok = false;
  double zoomChange = zoomType.toDouble(&ok);
  if(ok == false){
    if(zoomType=="")
      zoomType = this->_d->_zoomType;

    double zoomscale = qvariant_cast<double>(this->_d->_rootObject->findChild<QQuickItem*>("zoomObject")->property("scale"));
    if(zoomType=="zoom_full"){
      zoomscale = this->_d->_rootObject->width()/this->_d->_graph->graphSize().width();
      if(zoomscale > this->_d->_rootObject->height()/this->_d->_graph->graphSize().height())
        zoomscale = this->_d->_rootObject->height()/this->_d->_graph->graphSize().height();
    }else if(zoomType=="zoom_height"){
      zoomscale = this->_d->_rootObject->height()/this->_d->_graph->graphSize().height();
    }else if(zoomType=="zoom_width"){
      zoomscale = this->_d->_rootObject->width()/this->_d->_graph->graphSize().width();
    }
    if(zoomscale <= 0)
      zoomscale = 1.0;
    this->_d->_rootObject->findChild<QQuickItem*>("zoomObject")->setProperty("scale",zoomscale);
    this->zoomLevel();
  }else{
    if(zoomChange == 1){
      this->_d->_rootObject->findChild<QQuickItem*>("zoomObject")->setProperty("scale",1);
    }else{
      double zoomscale = qvariant_cast<double>(this->_d->_rootObject->findChild<QQuickItem*>("zoomObject")->property("scale"));
      this->_d->_rootObject->findChild<QQuickItem*>("zoomObject")->setProperty("scale",zoomscale+zoomChange);
    }
  }
}

//! Hide/Show Labels dependent on zoomLevel
void QmlGraphView::zoomLevel(){
  QQuickItem* item = this->_d->_rootObject->findChild<QQuickItem*>("zoomObject");
  if(item->scale()<this->_d->_zoomBound){
    foreach(QQuickItem* item, _d->_rootObject->findChildren<QQuickItem*>("text")){
      item->setProperty("visible",false);
    }
  }else{
    foreach(QQuickItem* item, _d->_rootObject->findChildren<QQuickItem*>("text")){
      item->setProperty("visible",true);
    }
  }
}

//! InfoBox
void QmlGraphView::infoBox(QString uuid){
  QObject* infobox = this->_d->_rootObject->findChild<QObject*>("infobox");
  if(infobox){
    LayoutNode* node = this->_d->_graph->nodeByExternUuid(QUuid(uuid));
    if(node){
      if(node->infoBoxStrings().isEmpty()==false){
        QObject* infotext = this->_d->_rootObject->findChild<QObject*>("infoboxtext");
        if(infotext){
          infotext->setProperty("text",node->infoBoxStrings());
          infotext->setProperty("lines",node->infoBoxStrings().count("\n")+1);
          infotext->setProperty("color",this->_d->_infoboxTextcolor);
          infotext->setProperty("textfamily",this->_d->_textfamily.family());
          infotext->setProperty("textsize",this->_d->_infoboxTextsize);
          if(infobox)
            infobox->setProperty("color",this->_d->_infoboxBackgroundcolor);
          QMetaObject::invokeMethod(infobox,"openThisDrawer");
        }
      }
    }
  }
}
void QmlGraphView::infoBoxEdge(QString uuid){
  QObject* infobox = this->_d->_rootObject->findChild<QObject*>("infobox");
  if(infobox){
    LayoutEdge* edge = this->_d->_graph->edgeByExternUuid(QUuid(uuid));
    if(edge){
      if(edge->infoBoxStrings().isEmpty()==false){
        QObject* infotext = this->_d->_rootObject->findChild<QObject*>("infoboxtext");
        if(infotext){
          infotext->setProperty("text",edge->infoBoxStrings());
          infotext->setProperty("lines",edge->infoBoxStrings().count("\n")+1);
          infotext->setProperty("color",this->_d->_infoboxTextcolor);
          infotext->setProperty("textfamily",this->_d->_textfamily.family());
          infotext->setProperty("textsize",this->_d->_infoboxTextsize);
          if(infobox)
            infobox->setProperty("color",this->_d->_infoboxBackgroundcolor);
          QMetaObject::invokeMethod(infobox,"openThisDrawer");
        }
      }
    }
  }
}

void QmlGraphView::unhighlightAllItems()
{
  //FIXME: not implemented yet...

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

void QmlGraphView::highlightItemByUuid(const QUuid& itemUuid, const bool enabled)
{
//  qDebug()<<"QmlGraphView::highlightItemByUuid() executed!";

  LayoutNode* currentNode = nullptr;
  currentNode = this->_d->_graph->nodeByExternUuid(itemUuid);
  if(currentNode){
    QObject* graphicQmlNode = graphicQmlNodeFromUuid(itemUuid);
    if(graphicQmlNode){
      QQuickItem* nodeItem = qobject_cast<QQuickItem*>(graphicQmlNode);
      Q_ASSERT(nodeItem);
      if(enabled==true){
        nodeItem->setProperty("color",currentNode->highlightColor());
        nodeItem->setProperty("borderColor",currentNode->highlightBorderColor());
        nodeItem->setProperty("borderWidth",currentNode->highlightBorderWidth());
        this->_d->_highlightedNodes.insert(currentNode, nodeItem);
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
  currentEdge = this->_d->_graph->edgeByExternUuid(itemUuid);
  if(currentEdge){
    QObject* edge = graphicQmlEdgeFromUuid(itemUuid);
    if(edge){
      QQuickItem* edgeItem = qobject_cast<QQuickItem*>(edge);
      if(enabled==true){
        edgeItem->setProperty("lineColor",currentEdge->highlightColor());
        this->_d->_highlightedEdges.insert(currentEdge, edgeItem);
      }else{
        edgeItem->setProperty("lineColor",currentEdge->color());
        this->_d->_highlightedEdges.remove(currentEdge);
      }
      return;
    }
  }
  
  return;
}

void QmlGraphView::highlightItemByName(const QString& itemName, const bool enabled)
{
  qDebug()<<"QmlGraphView::highlightItemByName() executed!";

  LayoutNode* currentNode = nullptr;
  currentNode = this->_d->_graph->nodeByName(itemName);
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
  currentEdge = this->_d->_graph->edgeByExternUuid(itemName);
  if(currentEdge){
    QObject* edge = graphicQmlEdgeFromUuid(currentEdge->externUuid());
    if(edge){
      QQuickItem* edgeItem = qobject_cast<QQuickItem*>(edge);
      if(enabled==true){
        edgeItem->setProperty("lineColor",currentEdge->highlightColor());
        this->_d->_highlightedEdges.insert(currentEdge, edgeItem);
      }else{
        edgeItem->setProperty("lineColor",currentEdge->color());
        this->_d->_highlightedEdges.remove(currentEdge);
      }
      return;
    }
  }

  return;
}

void QmlGraphView::setZoomBound(double zoom){
  this->_d->_zoomBound=zoom;
}
double QmlGraphView::zoomBound(){
  return this->_d->_zoomBound;
}
void QmlGraphView::setGraphvizPath(QString path){
  this->_d->_graphvizPath=path;
}
void QmlGraphView::setAlgorithm(GraphvizAlgorithm algorithm){
  this->_d->_algorithm=algorithm;
}
void QmlGraphView::setZoomType(const QString& type){
  this->_d->_zoomType=type;
}
void QmlGraphView::setBackgroundColor(QColor color){
  this->_d->_backgroundColor=color;
}
void QmlGraphView::setTitleColor(QColor color){
  this->_d->_titleTextColor=color;
}
void QmlGraphView::setTitleSize(int textsize){
  this->_d->_titleTextSize=textsize;
}
void QmlGraphView::setTitleShape(ShapeEnum shape){
  this->_d->_titleShape=shape;
}
void QmlGraphView::setTitleBorderColor(QColor color){
  this->_d->_titleBorderColor = color;
}
void QmlGraphView::setTitleBorderWidth(double width){
  this->_d->_titleBorderWidth = width;
}
void QmlGraphView::setTitleBackgroundColor(QColor color){
  this->_d->_titleBackgroundColor = color;
}
void QmlGraphView::setInfoboxBackgroundcolor(QColor color){
  this->_d->_infoboxBackgroundcolor = color;
}
void QmlGraphView::setInfoboxTextcolor(QColor color){
  this->_d->_infoboxTextcolor = color;
}
void QmlGraphView::setInfoboxTextsize(int size){
  this->_d->_infoboxTextsize = size;
}
