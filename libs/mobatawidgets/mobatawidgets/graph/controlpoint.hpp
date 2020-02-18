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
#ifndef VIEW_GRAPH_CONTROLPOINT_HPP
#define VIEW_GRAPH_CONTROLPOINT_HPP

#include "../mobatawidgets_global.hpp"

#include <QGraphicsRectItem>
#include <QCursor>

#include "types.hpp"

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace graph{

template<class OwnerType>
class MOBATAWIDGETSSHARED_EXPORT ControlPoint : public QGraphicsRectItem
{
public:
	enum {Type = ControlPointType};

public:
	ControlPoint(OwnerType* owner, const QSizeF& size=QSizeF(7,7))
		:	QGraphicsRectItem(-(size.width()/2), 
												-(size.height()/2), 
												size.width(), 
												size.height(), 
												owner),
			_owner(owner), _normalCursor(Qt::OpenHandCursor), 
			_mousePressCursor(Qt::ClosedHandCursor)
	{
		this->setBrush(Qt::black);
		this->hide();
		this->setFlag(QGraphicsItem::ItemIsMovable, true);
		this->setCursor(this->_normalCursor);
	}
	
	virtual ~ControlPoint()
	{}

public:
	int	type() const
	{
		return Type;
	}

	void setCursors(const QCursor& normalCursor, const QCursor& mousePressCursor)
	{
		this->_normalCursor=normalCursor;
		this->setCursor(this->_normalCursor);
		this->_mousePressCursor=mousePressCursor;

		return;
    }

protected:
	void	mouseMoveEvent(QGraphicsSceneMouseEvent* event)
	{
		QGraphicsRectItem::mouseMoveEvent(event);

		if(!this->_owner)
			return;

		this->_owner->controlPointMove(this);

		return;
	}

	void	mousePressEvent(QGraphicsSceneMouseEvent* event)
	{
		this->setCursor(this->_mousePressCursor);

		if(this->_owner)
			this->_owner->controlPointPressed(this);

		return QGraphicsRectItem::mousePressEvent(event);
	}

	void	mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
	{
		this->setCursor(this->_normalCursor);

		if(this->_owner)
			this->_owner->controlPointReleased(this);

		return QGraphicsRectItem::mouseReleaseEvent(event);
    }

private:
	OwnerType*	_owner;
	QCursor			_normalCursor;
	QCursor			_mousePressCursor;
};

}////end namespace graph
}//end namespace view

#include <mobata/memory_leak_end.hpp>

#endif //VIEW_GRAPH_EDGECONTROLPOINT_HPP
