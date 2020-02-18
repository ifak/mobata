#include "ellipsenode.hpp"

#include "../base/textitem.hpp"
#include "resizingrect.hpp"

#include <QPainter>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace graph{

class EllipseNode::Private
{
	friend class EllipseNode;
public:
	Private()	:	_rect(0)
	{}
	~Private()
	{}
private:
	ResizingRect* _rect;
};

EllipseNode::EllipseNode(const QString &notation, 
													 const NodeOptions &nodeOptions, 
													 const QUuid &uuid,
													 QGraphicsItem* parent)
	: AbstractNode(notation, uuid, parent)
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
	
	this->setHandlesChildEvents(false);
	this->setCursor(Qt::PointingHandCursor);

	this->notationItem()->setPos(this->boundingRect().width()/2, 
																	-this->notationItem()->boundingRect().height()/2);
}

EllipseNode::~EllipseNode()
{
	delete this->_d;
}

int EllipseNode::type() const
{
	return Type;
}

QRectF	EllipseNode::boundingRect() const
{
	QSize controlPointSize=this->_d->_rect->getControlPointSize();
	return this->_d->_rect->rect().adjusted(controlPointSize.width()/2, 
																					controlPointSize.height()/2, 
																					-controlPointSize.width()/2, 
																					-controlPointSize.height()/2);
}

QSizeF EllipseNode::size() const
{
	QRectF sizeRect=this->_d->_rect->rect();
	return QSizeF(sizeRect.width(), sizeRect.height());
}

void EllipseNode::setSize(QSizeF size)
{
	this->_d->_rect->setRect(-size.width()/2, -size.height()/2,
													 size.width(), size.height());
	
	return;
}

void EllipseNode::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);

	painter->setBrush(this->brush());
	painter->setPen(this->pen());
	painter->drawEllipse(this->boundingRect());

	if(this->isSelected() || this->_d->_rect->isResizing())
		this->_d->_rect->show();
	else
		this->_d->_rect->hide();

//	if(this->isSelected())
//	{
////		const QColor fgcolor = option->palette.windowText().color();
////		const QColor bgcolor( // ensure good contrast against fgcolor
////				fgcolor.red()   > 127 ? 0 : 255,
////				fgcolor.green() > 127 ? 0 : 255,
////				fgcolor.blue()  > 127 ? 0 : 255);

////		painter->setPen(QPen(bgcolor, 0, Qt::SolidLine));
////		painter->setBrush(Qt::NoBrush);
////		painter->drawRect(this->_d->_rect.adjusted(0.5, 0.5, -0.5, -0.5));

//		painter->setPen(QPen(option->palette.windowText(), 0, Qt::DashLine));
//		painter->setBrush(Qt::NoBrush);
//		painter->drawRect(this->_d->_rect.adjusted(0.5, 0.5, -0.5, -0.5));
//	}

	return;
}

}////end namespace graph
}//end namespace view
