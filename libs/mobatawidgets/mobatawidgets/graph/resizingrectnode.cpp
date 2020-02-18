#include "resizingrectnode.hpp"

#include "../base/textitem.hpp"
#include "resizingrect.hpp"

#include <QGraphicsProxyWidget>
#include <QPainter>
#include <QWidget>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace graph{

class ResizingRectNode::Private
{
  friend class ResizingRectNode;

public:
  Private()	: _rect(0), _proxyWidget(0), _offset(0)
  {}
  ~Private()
  {}

private:
  ResizingRect*				_rect;
  QGraphicsProxyWidget*	_proxyWidget;
  uint									_offset;
};

ResizingRectNode::ResizingRectNode(const QString& notation,
                                   const NodeOptions& nodeOptions,
                                   const QUuid& uuid,
                                   QGraphicsItem * parentItem)
  :	AbstractNode(notation, uuid, parentItem)
{
  this->_d=new Private();

  QSizeF size=nodeOptions.size();
  this->_d->_rect=new ResizingRect(QRectF(-size.width()/2,
                                          -size.height()/2,
                                          size.width(),
                                          size.height()),
                                   QSize(5,5),
                                   this);
  this->setBrush(nodeOptions.getColor());
  this->setPen(nodeOptions.pen());
  this->notationItem()->setDefaultTextColor(nodeOptions.textColor());
  this->notationItem()->setFont(nodeOptions.textFont());

  this->setHandlesChildEvents(false);
  this->setCursor(Qt::PointingHandCursor);

  this->notationItem()->setPos(this->boundingRect().width()/2,
                               -this->notationItem()->boundingRect().height()/2);
}

ResizingRectNode::~ResizingRectNode()
{
  delete this->_d;
}

int ResizingRectNode::type() const
{
  return Type;
}

QRectF	ResizingRectNode::boundingRect() const
{
  QSize controlPointSize=this->_d->_rect->getControlPointSize();
  return this->_d->_rect->rect().adjusted(controlPointSize.width()/2,
                                          controlPointSize.height()/2,
                                          -controlPointSize.width()/2,
                                          -controlPointSize.height()/2);
}

QRectF	ResizingRectNode::rect() const
{
  return this->_d->_rect->rect();
}

QSizeF ResizingRectNode::size() const
{
  //	QRectF sizeRect=this->boundingRect();
  QRectF sizeRect=this->_d->_rect->rect();
  return QSizeF(sizeRect.width(), sizeRect.height());
}

void ResizingRectNode::setSize(QSizeF size)
{
  this->_d->_rect->setRect(-size.width()/2, -size.height()/2,
                           size.width(), size.height());

  return;
}

void ResizingRectNode::setMinimumSize(const QSizeF minSize)
{
  this->_d->_rect->setMinimumSize(minSize);

  return;
}

void ResizingRectNode::setWidget(QWidget* newWidget, uint offset)
{
  if(!this->_d->_proxyWidget)
    this->_d->_proxyWidget=new QGraphicsProxyWidget(this);

  QWidget* oldWidget=this->_d->_proxyWidget->widget();
  this->_d->_proxyWidget->setWidget(newWidget);
  if(oldWidget)
    delete oldWidget;

  /////if newWidget=0/////////
  if(!this->_d->_proxyWidget->widget())
  {
    delete this->_d->_proxyWidget;
    this->_d->_proxyWidget=0;
    this->_d->_offset=0;

    return;
  }

  this->_d->_offset=offset;

  QSizeF minSize=this->_d->_proxyWidget->minimumSize();
  minSize.setWidth(minSize.width()+2*this->_d->_offset);
  minSize.setHeight(minSize.height()+2*this->_d->_offset);
  this->setMinimumSize(minSize/*QSize(100,100)*/);
  this->updateProxyWidgetGeometry();
  this->update();

  return;
}

void ResizingRectNode::updateProxyWidgetGeometry()
{
  QRectF widgetRect=this->rect();

  widgetRect.setLeft(widgetRect.left()+this->_d->_offset);
  widgetRect.setTop(widgetRect.top()+this->_d->_offset);
  widgetRect.setRight(widgetRect.right()-this->_d->_offset);
  widgetRect.setBottom(widgetRect.bottom()-this->_d->_offset);

  this->_d->_proxyWidget->setGeometry(widgetRect);

  return;
}

ResizingRect *ResizingRectNode::getResizingRect()
{
  return this->_d->_rect;
}

QGraphicsProxyWidget *ResizingRectNode::getProxyWidget()
{
  return this->_d->_proxyWidget;
}

void ResizingRectNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  Q_UNUSED(option);
  Q_UNUSED(widget);

  painter->setBrush(this->brush());
  painter->setPen(this->pen());
  painter->drawRect(this->boundingRect());

  if(this->isSelected() || this->_d->_rect->isResizing())
    this->_d->_rect->show();
  else
    this->_d->_rect->hide();

  if(this->_d->_proxyWidget)
    this->updateProxyWidgetGeometry();

  this->updateEdgesPosition();

  return;
}

void ResizingRectNode::setControlPointsMovable(bool value)
{
  this->_d->_rect->setControlPointsMovable(value);

  return;
}

void ResizingRectNode::setControlPointsSelectable(bool value)
{
  this->_d->_rect->setControlPointsSelectable(value);

  return;
}

}////end namespace graph
}//end namespace view
