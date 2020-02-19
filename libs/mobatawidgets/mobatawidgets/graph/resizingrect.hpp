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
#ifndef VIEW_GRAPH_RESIZINGRECT_HPP
#define VIEW_GRAPH_RESIZINGRECT_HPP

#include "../mobatawidgets_global.hpp"

#include <QGraphicsRectItem>

#include "controlpoint.hpp"

namespace view{
namespace graph{

class MOBATAWIDGETSSHARED_EXPORT ResizingRect : public QGraphicsRectItem
{
	typedef ControlPoint<ResizingRect>	ControlPointType;

public:
	ResizingRect(const QRectF& rect, 
								QSize controlPointSize=QSize(4,4), 
								QGraphicsItem* parentItem=0);
	virtual ~ResizingRect();

public:
	virtual void	controlPointMove(ControlPointType* controlPoint);
	virtual void	controlPointPressed(ControlPointType* controlPoint);
	virtual void	controlPointReleased(ControlPointType* controlPoint);

public:
	bool	isResizing() const;
	QSize	getControlPointSize() const;
	void	setControlPointsMovable(bool value);
	void	setControlPointsSelectable(bool value);
	void	setMinimumSize(const QSizeF minSize);
	bool	isValid(const QRectF& rect) const;

private:
	void	updateControlPointPositions();

private:
	class Private;
	Private* _d;
};

}/////end namespace graph
}//end namespace view

#endif // VIEW_GRAPH_RESIZINGRECT_HPP
