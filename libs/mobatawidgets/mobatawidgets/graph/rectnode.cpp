#include "rectnode.hpp"

#include "../base/textitem.hpp"

#include <QCursor>
#include <QPainter>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace graph{

class RectNode::Private
{
	friend class RectNode;
	
public:
	Private()	: _rect(QRectF())
	{}
	~Private()
	{}
	
private:
	QRectF _rect;
};

RectNode::RectNode(const QString& notation,
										 const NodeOptions& nodeOptions,
										 const QUuid &uuid,
										 QGraphicsItem* parentItem)
	:	AbstractNode(notation, uuid, parentItem)
{
	this->_d=new Private();
	
	QSizeF size=nodeOptions.size();
	this->_d->_rect=QRectF(-size.width()/2, -size.height()/2, size.width(), size.height());
	this->setBrush(nodeOptions.getColor());
	this->setPen(nodeOptions.pen());
	this->notationItem()->setDefaultTextColor(nodeOptions.textColor());
	this->notationItem()->setFont(nodeOptions.textFont());
	
	this->setHandlesChildEvents(false);
	this->setCursor(Qt::PointingHandCursor);

	this->notationItem()->setPos(this->boundingRect().width()/2, 
																	-this->notationItem()->boundingRect().height()/2);
}

RectNode::RectNode(QGraphicsItem* parentItem)
	:	AbstractNode("", QUuid::createUuid(), parentItem)
{
	this->_d=new Private();
	
	this->setHandlesChildEvents(false);
	this->setBrush(QColor(225, 225, 175));
	this->setPen(QPen(Qt::darkRed, 3));
	this->setCursor(Qt::PointingHandCursor);

	this->notationItem()->setPos(this->boundingRect().width()/2, 
																	-this->notationItem()->boundingRect().height()/2);
}

RectNode::~RectNode()
{
	delete this->_d;
}

int RectNode::type() const
{
	return Type;
}

QRectF	RectNode::boundingRect() const
{
	return this->_d->_rect;
}

QRectF	RectNode::rect() const
{
	return this->_d->_rect;
}

QSizeF RectNode::size() const
{
	return QSizeF(this->_d->_rect.width(), 
								this->_d->_rect.height());
}

void RectNode::setSize(QSizeF size)
{
	this->_d->_rect=QRectF(-size.width()/2, -size.height()/2,
												 size.width(), size.height());
	
	return;
}

void RectNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);

//	this->_rect=this->childrenBoundingRect();
//	this->_rect.adjust(-10,-10,10,10);

	painter->setBrush(this->brush());
	painter->setPen(this->pen());
	painter->drawRect(this->_d->_rect);

	return;
}

}////end namespace graph
}//end namespace view
