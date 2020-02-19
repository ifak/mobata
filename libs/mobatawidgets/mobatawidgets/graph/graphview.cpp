#include "graphview.hpp"

#include "graphscene.hpp"
#include "abstractnode.hpp"

#include <math.h>
#include <assert.h>

#include <QSlider>
#include <QIcon>
#include <QAction>
#include <QWheelEvent>
#include <QDebug>

#include <mobata/utils/functors.hpp>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace graph{

QSizeF suitableViewportSize(QGraphicsView* graphicsView)
{
  Q_ASSERT(graphicsView);

  QSizeF viewportSize=graphicsView->viewport()->size();
  viewportSize.setWidth(viewportSize.width()-5);
  viewportSize.setHeight(viewportSize.height()-5);

  return viewportSize;
}

class GraphView::Private
{
  friend class GraphView;

  QAction*  _zoomInAction;
  QAction*  _zoomOutAction;
  QAction*  _zoomFitInViewAction;
  QAction*  _zoomResetAction;
  int       _zoomValue;
  int       _zoomMin;
  int       _zoomMax;

  Private()
    : _zoomValue(250), _zoomMin(0), _zoomMax(500)
  {}

  void createActions(GraphView* graphView);
};

void GraphView::Private::createActions(GraphView* graphView)
{
  Q_ASSERT(graphView);

  this->_zoomInAction = new QAction(QIcon(QLatin1String(":/mobata/images/zoomin_dark.png")),
                                    tr("zoom in"),
                                    graphView);
  this->_zoomInAction->setStatusTip(tr("zoom in"));
  this->_zoomInAction->setToolTip(tr("zoom in"));
  this->_zoomInAction->setCheckable(false);
  this->_zoomInAction->setAutoRepeat(true);
  this->_zoomInAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Plus));
  connect(this->_zoomInAction, &QAction::triggered,
          graphView, &GraphView::zoomIn);

  this->_zoomOutAction = new QAction(QIcon(QLatin1String(":/mobata/images/zoomout_dark.png")),
                                     tr("zoom out"),
                                     graphView);
  this->_zoomOutAction->setStatusTip(tr("zoom out"));
  this->_zoomOutAction->setToolTip(tr("zoom out"));
  this->_zoomOutAction->setCheckable(false);
  this->_zoomOutAction->setAutoRepeat(true);
  this->_zoomOutAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Minus));
  connect(this->_zoomOutAction, &QAction::triggered,
          graphView, &GraphView::zoomOut);

  this->_zoomFitInViewAction = new QAction(QIcon(QLatin1String(":/mobata/images/zoominview_dark.png")),
                                           tr("zoom fit in view"),
                                           graphView);
  this->_zoomFitInViewAction->setStatusTip(tr("zoom fit in view"));
  this->_zoomFitInViewAction->setToolTip(tr("zoom fit in view"));
  this->_zoomFitInViewAction->setCheckable(false);
  connect(this->_zoomFitInViewAction, &QAction::triggered,
          graphView, &GraphView::zoomInView);

  this->_zoomResetAction = new QAction(QIcon(QLatin1String(":/mobata/images/zoomreset_dark.png")),
                                       tr("reset zoom"),
                                       graphView);
  this->_zoomResetAction->setStatusTip(tr("reset zoom"));
  this->_zoomResetAction->setToolTip(tr("reset zoom"));
  this->_zoomResetAction->setCheckable(false);
  connect(this->_zoomResetAction, &QAction::triggered,
          graphView, &GraphView::zoomReset);

  return;
}

GraphView::GraphView(QWidget* parent)
  : QGraphicsView(parent), _d(new Private())
{
  this->setDragMode(QGraphicsView::RubberBandDrag);
  this->setRubberBandSelectionMode(Qt::ContainsItemShape);
  this->setBackgroundBrush(QBrush(Qt::lightGray/*, Qt::Dense7Pattern*/));
  this->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
  this->setMouseTracking(true);

  this->_d->createActions(this);
}

GraphView::GraphView(GraphScene* graphScene, QWidget* parent)
  : QGraphicsView(graphScene, parent), _d(new Private())
{
  Q_ASSERT(graphScene);
  Q_ASSERT(this->scene());

  this->setDragMode(QGraphicsView::RubberBandDrag);
  this->setRubberBandSelectionMode(Qt::ContainsItemShape);
  this->setBackgroundBrush(QBrush(Qt::lightGray/*, Qt::Dense7Pattern*/));
  this->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
  this->setMouseTracking(true);

  this->_d->createActions(this);
}

GraphView::~GraphView()
{
  delete this->_d;
}

QAction* GraphView::zoomInAction()
{
  return this->_d->_zoomInAction;
}

QAction* GraphView::zoomOutAction()
{
  return this->_d->_zoomOutAction;
}

QAction* GraphView::zoomFitInViewAction()
{
  return this->_d->_zoomFitInViewAction;
}

QAction* GraphView::zoomResetAction()
{
  return this->_d->_zoomResetAction;
}

QList<QAction *> GraphView::allZoomActions()
{
  return QList<QAction*>()<<this->_d->_zoomInAction
                         <<this->_d->_zoomOutAction
                        <<this->_d->_zoomFitInViewAction
                       <<this->_d->_zoomResetAction;
}

void GraphView::updateSceneRect()
{
  if(!this->scene())
    return;

  QSizeF viewportSize=suitableViewportSize(this);
  QRectF itemsBoundRect=this->scene()->itemsBoundingRect();
  qreal x=itemsBoundRect.x();
  qreal y=itemsBoundRect.y();
  qreal w=itemsBoundRect.width();
  qreal h=itemsBoundRect.height();

  if(x>=0)
  {
    w=w+x;
    x=0;
  }

  if(y>=0)
  {
    h=h+y;
    y=0;
  }

  if(w<viewportSize.width())
    w=viewportSize.width();
  if(h<viewportSize.height())
    h=viewportSize.height();

  QRectF newSceneRect(x,y,w,h);

  this->scene()->setSceneRect(newSceneRect);

  return;
}

void GraphView::zoomInView()
{
  //  this->updateSceneRect();
  this->fitInView(this->sceneRect(), Qt::KeepAspectRatio);

  QMatrix matrix=this->matrix();

  qreal zoomInValue=::log(matrix.m22())/::log(2.0);
  zoomInValue*=50;
  zoomInValue+=250;

  this->_d->_zoomValue=zoomInValue;
  emit zoomValueChanged(this->_d->_zoomValue);

  return;
}

void GraphView::zoomIn()
{
  if(this->_d->_zoomValue>=this->_d->_zoomMax)
    return;

  this->_d->_zoomValue+=2;
  if(this->_d->_zoomValue>this->_d->_zoomMax)
    this->_d->_zoomValue=this->_d->_zoomMax;
  emit zoomValueChanged(this->_d->_zoomValue);

  this->setupTransform();

  return;
}

void GraphView::zoomOut()
{
  if(this->_d->_zoomValue<=this->_d->_zoomMin)
    return;

  this->_d->_zoomValue-=2;
  if(this->_d->_zoomValue<this->_d->_zoomMin)
    this->_d->_zoomValue=this->_d->_zoomMin;
  emit zoomValueChanged(this->_d->_zoomValue);

  this->setupTransform();

  return;
}

void GraphView::setupTransform()
{
  int range=this->_d->_zoomMax-this->_d->_zoomMin;
  qreal scale = ::pow(2.0, (this->_d->_zoomValue - range/2) / 50.0);

  QTransform transform;
  transform.scale(scale, scale);

  this->setTransform(transform);

  return;
}

void GraphView::zoomReset()
{
  int range=this->_d->_zoomMax-this->_d->_zoomMin;
  this->_d->_zoomValue=this->_d->_zoomMin+range/2;
  emit zoomValueChanged(this->_d->_zoomValue);

  this->resetTransform();
  this->ensureVisible(QRectF(0, 0, 0, 0));

  return;
}

void GraphView::print()
{

  return;
}

void GraphView::wheelEvent(QWheelEvent *event)
{
  if(event->modifiers()==Qt::CTRL)
  {
    int numDegrees = event->delta() / 8;
    int numSteps = numDegrees / 15;
    this->_d->_zoomValue+=numSteps;
    emit zoomValueChanged(this->_d->_zoomValue);

    this->setupTransform();
    return event->accept();
  }

  return QGraphicsView::wheelEvent(event);
}

void GraphView::showEvent(QShowEvent* event)
{
  Q_UNUSED(event);

  emit shown();

  return;
}

void GraphView::resizeEvent(QResizeEvent *event)
{
  Q_UNUSED(event);

  emit resized();

  return;
}

int GraphView::zoomValue() const
{
  return this->_d->_zoomValue;
}

int GraphView::zoomMin() const
{
  return this->_d->_zoomMin;
}

int GraphView::zoomMax() const
{
  return this->_d->_zoomMax;
}

void GraphView::setZoomRange(const int zoomMin, const int zoomMax)
{
  if(zoomMin<0)
    this->_d->_zoomMin=0;
  else
    this->_d->_zoomMin=zoomMin;

  if(zoomMax<=this->_d->_zoomMin)
    this->_d->_zoomMax=this->_d->_zoomMin;
  else
    this->_d->_zoomMax=zoomMax;

  return;
}

void GraphView::setZoomValue(int zoomValue)
{
  this->_d->_zoomValue=zoomValue;
  emit zoomValueChanged(this->_d->_zoomValue);

  this->setupTransform();

  return;
}

GraphScene *GraphView::graphScene()
{
  return utils::simple_cast<GraphScene*>(this->scene());
}

}////end namespace graph
}//end namespace view
