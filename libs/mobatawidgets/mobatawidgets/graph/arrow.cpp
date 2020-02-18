#include "arrow.hpp"
#include "abstractnode.hpp"
#include "directededge.hpp"

#include <math.h>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace graph{

class Arrow::Private
{
	friend class Arrow;
public:
	Private(QPointF startPos, QPointF endPos, qreal arrowWidth,  qreal arrowHeight)
		:	_startPoint(startPos), _endPoint(endPos), _arrowWidth(arrowWidth), _arrowHeight(arrowHeight)
	{}
	~Private()
	{}
	
private:
	QPointF	_startPoint;
	QPointF	_endPoint;
	qreal		_arrowWidth;
	qreal		_arrowHeight;
};

Arrow::Arrow(QPointF startPos, QPointF endPos, DirectedEdge* parentEdge)
	:  QGraphicsPathItem(parentEdge)
{
	this->_d=new Private(startPos, endPos, 8, 8);

	this->setFlag(QGraphicsItem::ItemIsSelectable, false);
	this->updateArrow(this->_d->_startPoint, this->_d->_endPoint);
}

Arrow::Arrow(QPointF startPos, QPointF endPos, qreal arrowWidth, qreal arrowHeight, DirectedEdge* parentEdge)
    : QGraphicsPathItem(parentEdge),
      _d(new Private(startPos, endPos, arrowWidth, arrowHeight))
{
    this->setFlag(QGraphicsItem::ItemIsSelectable, false);
    this->updateArrow(this->_d->_startPoint, this->_d->_endPoint);
}

Arrow::~Arrow()
{
	delete this->_d;
}

int Arrow::type() const
{
	return Type;
}

void Arrow::updateArrow(QPointF startPos, QPointF endPos)
{
	const qreal Pi = 3.14;

	this->_d->_startPoint=startPos;
	this->_d->_endPoint=endPos;

	if(this->_d->_startPoint==this->_d->_endPoint)
		return;

	QLineF line(this->_d->_startPoint, this->_d->_endPoint);

	double angle = ::acos(line.dx() / line.length());
	if (line.dy() >= 0)
		angle = (Pi * 2) - angle;

	QPointF arrowP1 = this->_d->_endPoint - QPointF(sin(angle + Pi/3)*this->_d->_arrowWidth, 
																									cos(angle+Pi/3)*this->_d->_arrowHeight);
	QPointF arrowP2 = this->_d->_endPoint - QPointF(sin(angle + Pi-Pi/3)*this->_d->_arrowWidth, 
																									cos(angle+Pi-Pi/3)*this->_d->_arrowHeight);

	QPainterPath path;
	path.moveTo(this->_d->_endPoint);
	path.lineTo(arrowP1);
	path.lineTo(arrowP2);
	path.lineTo(this->_d->_endPoint);
	this->setPath(path);

	return;
}

}///////end namespace graph
}//end namespace view
