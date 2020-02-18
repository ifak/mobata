#include "resizingrect.hpp"

#include "abstractnode.hpp"

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace graph{

class ResizingRect::Private
{
	friend class ResizingRect;
	
public:
	Private(QSize controlPointSize)
		:	_topLeft(0), _topMiddle(0), _topRight(0), _leftMiddle(0), 
			_rightMiddle(0), _bottomLeft(0), _bottomMiddle(0), _bottomRight(0),
			_oldRect(), _isResizing(false), _controlPointSize(controlPointSize), 
			_minimumSize(QSize(10,10))
	{}
	~Private()
	{}
	
private:
	ControlPointType* _topLeft;
	ControlPointType* _topMiddle;
	ControlPointType* _topRight;
	ControlPointType* _leftMiddle;
	ControlPointType* _rightMiddle;
	ControlPointType* _bottomLeft;
	ControlPointType* _bottomMiddle;
	ControlPointType* _bottomRight;

	QRectF	_oldRect;
	bool		_isResizing;
	QSize		_controlPointSize;
	QSizeF	_minimumSize;
};

ResizingRect::ResizingRect(const QRectF& rect, 
														 QSize controlPointSize, 
														 QGraphicsItem* parentItem)
	: QGraphicsRectItem(parentItem)
{
	this->_d=new Private(controlPointSize);
	
	this->_d->_oldRect=rect;
	this->setRect(rect);

	this->_d->_topLeft=new ControlPointType(this, this->_d->_controlPointSize);
	this->_d->_topLeft->show();
	this->_d->_topLeft->setBrush(Qt::black);
	this->_d->_topLeft->setCursors(QCursor(Qt::SizeFDiagCursor), QCursor(Qt::SizeFDiagCursor));

	this->_d->_topMiddle=new ControlPointType(this, this->_d->_controlPointSize);
	this->_d->_topMiddle->show();
	this->_d->_topMiddle->setBrush(Qt::black);
	this->_d->_topMiddle->setCursors(QCursor(Qt::SizeVerCursor), QCursor(Qt::SizeVerCursor));

	this->_d->_topRight=new ControlPointType(this, this->_d->_controlPointSize);
	this->_d->_topRight->show();
	this->_d->_topRight->setBrush(Qt::black);
	this->_d->_topRight->setCursors(QCursor(Qt::SizeBDiagCursor), QCursor(Qt::SizeBDiagCursor));

	this->_d->_leftMiddle=new ControlPointType(this,this->_d->_controlPointSize);
	this->_d->_leftMiddle->show();
	this->_d->_leftMiddle->setBrush(Qt::black);
	this->_d->_leftMiddle->setCursors(QCursor(Qt::SizeHorCursor), QCursor(Qt::SizeHorCursor));

	this->_d->_rightMiddle=new ControlPointType(this, this->_d->_controlPointSize);
	this->_d->_rightMiddle->show();
	this->_d->_rightMiddle->setBrush(Qt::black);
	this->_d->_rightMiddle->setCursors(QCursor(Qt::SizeHorCursor), QCursor(Qt::SizeHorCursor));

	this->_d->_bottomLeft=new ControlPointType(this, this->_d->_controlPointSize);
	this->_d->_bottomLeft->show();
	this->_d->_bottomLeft->setBrush(Qt::black);
	this->_d->_bottomLeft->setCursors(QCursor(Qt::SizeBDiagCursor), QCursor(Qt::SizeBDiagCursor));

	this->_d->_bottomMiddle=new ControlPointType(this, this->_d->_controlPointSize);
	this->_d->_bottomMiddle->show();
	this->_d->_bottomMiddle->setBrush(Qt::black);
	this->_d->_bottomMiddle->setCursors(QCursor(Qt::SizeVerCursor), QCursor(Qt::SizeVerCursor));

	this->_d->_bottomRight=new ControlPointType(this, this->_d->_controlPointSize);
	this->_d->_bottomRight->show();
	this->_d->_bottomRight->setBrush(Qt::black);
	this->_d->_bottomRight->setCursors(QCursor(Qt::SizeFDiagCursor), QCursor(Qt::SizeFDiagCursor));

	this->updateControlPointPositions();
}

ResizingRect::~ResizingRect()
{
	delete this->_d;
}

void ResizingRect::updateControlPointPositions()
{
	QRectF rect=this->rect();
	QPointF centerPoint=rect.center();

	this->_d->_topLeft->setPos(rect.topLeft());
	this->_d->_topMiddle->setPos(centerPoint.x(), rect.top());
	this->_d->_topRight->setPos(rect.topRight());
	this->_d->_leftMiddle->setPos(rect.left(), centerPoint.y());
	this->_d->_rightMiddle->setPos(rect.right(), centerPoint.y());
	this->_d->_bottomLeft->setPos(rect.bottomLeft());
	this->_d->_bottomMiddle->setPos(centerPoint.x(), rect.bottom());
	this->_d->_bottomRight->setPos(rect.bottomRight());

	return;
}

void ResizingRect::setMinimumSize(const QSizeF minSize)
{
	this->_d->_minimumSize=minSize;

	QSizeF size=this->rect().size();
	if(size.width()<this->_d->_minimumSize.width())
		size.setWidth(this->_d->_minimumSize.width());
	if(size.height()<this->_d->_minimumSize.height())
		size.setHeight(this->_d->_minimumSize.height());

	QRectF newRect(-size.width()/2, -size.height()/2, 
								 size.width(), size.height());
	this->setRect(newRect);
	this->updateControlPointPositions();

	return;
}

bool ResizingRect::isValid(const QRectF& rect) const
{
	if(rect.width() < this->_d->_minimumSize.width()
		 || rect.height() < this->_d->_minimumSize.height())
		return false;

	return true;
}

void ResizingRect::controlPointMove(ControlPointType* controlPoint)
{
	if(controlPoint==this->_d->_topLeft || controlPoint==this->_d->_bottomRight)
	{
		QRectF newRect(this->_d->_topLeft->pos(), 
									 this->_d->_bottomRight->pos());
		if(isValid(newRect))
			this->setRect(newRect);
	}
	else if(controlPoint==this->_d->_topMiddle)
	{
		QRectF newRect(QPointF(this->_d->_topLeft->pos().x(), 
													 this->_d->_topMiddle->pos().y()), 
									 this->_d->_bottomRight->pos());
		if(isValid(newRect))
			this->setRect(newRect);
	}
	else if(controlPoint==this->_d->_topRight)
	{
		QRectF newRect(QPointF(this->_d->_topLeft->pos().x(), 
													 this->_d->_topRight->pos().y()), 
									 QPointF(this->_d->_topRight->pos().x(), 
													 this->_d->_bottomRight->pos().y()));
		if(isValid(newRect))
			this->setRect(newRect);
	}
	else if(controlPoint==this->_d->_leftMiddle)
	{
		QRectF newRect(QPointF(this->_d->_leftMiddle->pos().x(), 
													 this->_d->_topLeft->pos().y()), 
									 this->_d->_bottomRight->pos());
		if(isValid(newRect))
			this->setRect(newRect);
	}
	else if(controlPoint==this->_d->_rightMiddle)
	{
		QRectF newRect(this->_d->_topLeft->pos(), 
									 QPointF(this->_d->_rightMiddle->pos().x(), 
													 this->_d->_bottomRight->pos().y()));
		if(isValid(newRect))
			this->setRect(newRect);
	}
	else if(controlPoint==this->_d->_bottomLeft)
	{
		QRectF newRect(QPointF(this->_d->_bottomLeft->pos().x(), 
													 this->_d->_topLeft->pos().y()), 
									 QPointF(this->_d->_bottomRight->pos().x(), 
													 this->_d->_bottomLeft->pos().y()));
		if(isValid(newRect))
			this->setRect(newRect);
	}
	else if(controlPoint==this->_d->_bottomMiddle)
	{
		QRectF newRect(this->_d->_topLeft->pos(), 
									 QPointF(this->_d->_bottomRight->pos().x(), 
													 this->_d->_bottomMiddle->pos().y()));
		if(isValid(newRect))
			this->setRect(newRect);
	}
	else
		return;

	this->updateControlPointPositions();
	if(AbstractNode* parentNode=dynamic_cast<AbstractNode*>(this->parentItem()))
		parentNode->updateEdgesPosition();

	return;
}

void ResizingRect::controlPointPressed(ControlPointType* controlPoint)
{
	Q_UNUSED(controlPoint);

	this->_d->_oldRect=this->rect();
	this->_d->_isResizing=true;
	if(this->parentItem())
		this->parentItem()->setSelected(false);

	return;
}

void ResizingRect::controlPointReleased(ControlPointType* controlPoint)
{
	Q_UNUSED(controlPoint);

	QRectF newRect=this->rect();
	QPointF diff=newRect.center()-this->_d->_oldRect.center();
	newRect.adjust(-diff.x(), -diff.y(), -diff.x(), -diff.y());
	if(newRect.isValid())
		this->setRect(newRect);
	this->updateControlPointPositions();
	if(QGraphicsItem* parentItem=this->parentItem())
	{
		parentItem->moveBy(diff.x(), diff.y());
		parentItem->setSelected(true);
		if(AbstractNode* parentNode=dynamic_cast<AbstractNode*>(parentItem))
			parentNode->resized();
	}

	this->_d->_isResizing=false;

	return;
}

bool ResizingRect::isResizing() const
{
	return this->_d->_isResizing;
}

QSize ResizingRect::getControlPointSize() const
{
	return this->_d->_controlPointSize;
}

void ResizingRect::setControlPointsMovable(bool value)
{
	this->_d->_bottomLeft->setFlag(QGraphicsItem::ItemIsMovable, value);
	this->_d->_bottomMiddle->setFlag(QGraphicsItem::ItemIsMovable, value);
	this->_d->_bottomRight->setFlag(QGraphicsItem::ItemIsMovable, value);
	this->_d->_leftMiddle->setFlag(QGraphicsItem::ItemIsMovable, value);
	this->_d->_rightMiddle->setFlag(QGraphicsItem::ItemIsMovable, value);
	this->_d->_topLeft->setFlag(QGraphicsItem::ItemIsMovable, value);
	this->_d->_topMiddle->setFlag(QGraphicsItem::ItemIsMovable, value);
	this->_d->_topRight->setFlag(QGraphicsItem::ItemIsMovable, value);

	return;
}

void ResizingRect::setControlPointsSelectable(bool value)
{
	this->_d->_bottomLeft->setFlag(QGraphicsItem::ItemIsSelectable, value);
	this->_d->_bottomMiddle->setFlag(QGraphicsItem::ItemIsSelectable, value);
	this->_d->_bottomRight->setFlag(QGraphicsItem::ItemIsSelectable, value);
	this->_d->_leftMiddle->setFlag(QGraphicsItem::ItemIsSelectable, value);
	this->_d->_rightMiddle->setFlag(QGraphicsItem::ItemIsSelectable, value);
	this->_d->_topLeft->setFlag(QGraphicsItem::ItemIsSelectable, value);
	this->_d->_topMiddle->setFlag(QGraphicsItem::ItemIsSelectable, value);
	this->_d->_topRight->setFlag(QGraphicsItem::ItemIsSelectable, value);

	return;
}

}///////end namespace graph
}//end namespace view
