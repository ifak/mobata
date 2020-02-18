#include "graphscene.hpp"

#include <QtSvg/QSvgGenerator>
#include <QFileDialog>
#include <QPainter>
#include <QMenu>
#include <QGraphicsSceneContextMenuEvent>
#include <QDebug>

#include "abstractnode.hpp"
#include "edge.hpp"
#include "functors.hpp"

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace graph{

class GraphScene::Private
{
  friend class GraphScene;
public:
  Private()
    : _name(QStringLiteral("graph")),
      _grid(10)
  {}
  ~Private()
  {}
private:
  QString       _name;
  qreal         _grid;
  QList<Edge*>  _tempMovableEdges;
};

GraphScene::GraphScene(QObject* parent) : QGraphicsScene(parent)
{
  this->_d=new Private();
  connect(this, SIGNAL(selectionChanged()), this, SLOT(selectionChangedSlot()));
}

GraphScene::~GraphScene()
{
  delete this->_d;
}

void GraphScene::removeGraphItem(QGraphicsItem* graphItem)
{
  if(!graphItem)
    return;

  if(AbstractNode* node=dynamic_cast<AbstractNode*>(graphItem))
    this->removeNode(node);
  else if(Edge* edge=dynamic_cast<Edge*>(graphItem))
    this->removeEdge(edge);

  return;
}

void GraphScene::setName(const QString& name)
{
  this->_d->_name=name;

  return;
}

const QString& GraphScene::name() const
{
  return this->_d->_name;
}


QPointF GraphScene::onGrid(QPointF pos)
{
  if(this->_d->_grid==0.0)
    return pos;

  qreal x = qRound(pos.x()/this->_d->_grid)*this->_d->_grid;
  qreal y = qRound(pos.y()/this->_d->_grid)*this->_d->_grid;

  return QPointF(x,y);
}

void GraphScene::setGrid(qreal newGrid)
{
  if(newGrid==0.0)
    return;

  this->_d->_grid=newGrid;

  return;
}

const AbstractNode *GraphScene::node(const QUuid &nodeUuid) const
{
  foreach(QGraphicsItem* currItem, this->items())
  {
    if(AbstractNode* currNode=qgraphicsitem_cast<AbstractNode*>(currItem))
      if(currNode->uuid()==nodeUuid)
        return currNode;
  }
  
  return 0;
}

AbstractNode *GraphScene::node(const QUuid &nodeUuid)
{
  foreach(QGraphicsItem* currItem, this->items())
  {
    if(AbstractNode* currNode=qgraphicsitem_cast<AbstractNode*>(currItem))
      if(currNode->uuid()==nodeUuid)
        return currNode;
  }
  
  return 0;
}

GraphScene::ConstNodeSet GraphScene::nodes() const
{
  return graph::graphSceneItems<AbstractNode const, ConstNodeSet>(this);
}

GraphScene::NodeSet GraphScene::nodes()
{
  return graph::graphSceneItems<AbstractNode, NodeSet>(this);
}

void GraphScene::removeNode(AbstractNode *node)
{
  if(!node)
    return;

  foreach(Edge* edge, node->edges())
  {
    if(edge->source()==node)
      edge->setSource(0);
    if(edge->target()==node)
      edge->setTarget(0);
  }

  this->removeItem(node);
  delete node;

  return;
}

Edge const* GraphScene::edge(const QUuid &edgeUuid) const
{
  foreach(QGraphicsItem* currItem, this->items())
  {
    if(Edge* currEdge=qgraphicsitem_cast<Edge*>(currItem))
      if(currEdge->uuid()==edgeUuid)
        return currEdge;
  }
  
  return 0;
}

Edge* GraphScene::edge(const QUuid &edgeUuid)
{
  foreach(QGraphicsItem* currItem, this->items())
  {
    if(Edge* currEdge=qgraphicsitem_cast<Edge*>(currItem))
      if(currEdge->uuid()==edgeUuid)
        return currEdge;
  }
  
  return 0;
}

GraphScene::ConstEdgeSet GraphScene::edges() const
{
  return graph::graphSceneItems<Edge const, ConstEdgeSet>(this);
}

GraphScene::EdgeSet GraphScene::edges()
{
  return graph::graphSceneItems<Edge, EdgeSet>(this);
}

void GraphScene::removeEdge(Edge *edge)
{
  if(!edge)
    return;

  if(edge->source())
    edge->source()->removeEdge(edge);
  if(edge->target())
    edge->target()->removeEdge(edge);

  this->removeItem(edge);
  delete edge;

  return;
}

void GraphScene::exportGraphicSlot()
{
  QString selectedFilter=QString();
  QString fileName = QFileDialog::getSaveFileName(0, tr("Save this graphic as a picture"), "", "SVG (*.svg);;PNG (*.png);;JPG (*.jpg);;JPEG (*.jpeg);;BMP (*.bmp);;PPM (*.ppm);;TIFF (*.tiff);;XBM (*.xbm);;XPM (*.xpm)", &selectedFilter);
  if (fileName.isEmpty())
    return;

  if(selectedFilter=="SVG (*.svg)")
  {
    QSvgGenerator picture;
    picture.setFileName(fileName);
    QRectF itemsBoundingRect=this->itemsBoundingRect();
    picture.setSize(QSize(itemsBoundingRect.width(), itemsBoundingRect.height()));
    QPainter painter(&picture);
    this->render(&painter);
    painter.end();
  }
  else
  {
    QImage image(this->width(), this->height(), QImage::Format_RGB32);
    QPainter painter(&image);
    /*painter.setRenderHint(QPainter::Antialiasing);*/
    this->render(&painter);
    painter.end();

    if(selectedFilter=="PNG (*.png)")
      image.save(fileName, "PNG");
    else if(selectedFilter=="JPG (*.jpg)")
      image.save(fileName, "JPG");
    else if(selectedFilter=="JPEG (*.jpeg)")
      image.save(fileName, "JPEG");
    else if(selectedFilter=="BMP (*.bmp)")
      image.save(fileName, "BMP");
    else if(selectedFilter=="PPM (*.ppm)")
      image.save(fileName, "PPM");
    else if(selectedFilter=="TIFF (*.tiff)")
      image.save(fileName, "TIFF");
    else if(selectedFilter=="XBM (*.xbm)")
      image.save(fileName, "XBM");
    else if(selectedFilter=="XPM (*.xpm)")
      image.save(fileName, "XPM");
  }

  return;
}

void GraphScene::contextMenuEvent(QGraphicsSceneContextMenuEvent* contextMenuEvent)
{
  QMenu menu;

  QAction* exportGraphicAction = new QAction(QIcon(":/graphics/save.png"), "Export as a picture", this);
  exportGraphicAction->setToolTip("Export this graphic as a picture");
  exportGraphicAction->setStatusTip("Export this graphic as a picture");
  connect(exportGraphicAction, SIGNAL(triggered()), this, SLOT(exportGraphicSlot()));

  menu.addAction(exportGraphicAction);

  menu.exec(contextMenuEvent->screenPos());
}

void GraphScene::selectionChangedSlot()
{
  foreach(Edge* currEdge, this->_d->_tempMovableEdges)
    currEdge->setFlag(QGraphicsItem::ItemIsMovable, false);
  this->_d->_tempMovableEdges.clear();

  QList<QGraphicsItem*> currSelection=this->selectedItems();
  if(currSelection.size())
  {
    int topLevelItemsCount=0;
    foreach(QGraphicsItem* currItem, currSelection)
    {
      if(Edge* currEdge=qgraphicsitem_cast<Edge*>(currItem))
      {
        currEdge->setFlag(QGraphicsItem::ItemIsMovable, true);
        this->_d->_tempMovableEdges.push_back(currEdge);
        ++topLevelItemsCount;
      }
      else if(!currItem->parentItem())
        ++topLevelItemsCount;
    }

    if(topLevelItemsCount==1 && this->_d->_tempMovableEdges.size()==1)
    {
      this->_d->_tempMovableEdges.front()->setFlag(QGraphicsItem::ItemIsMovable, false);
      this->_d->_tempMovableEdges.clear();
    }
  }
  else
    this->clearSelection();

  return;
}

}//////end namespace graph
}//end namespace view
