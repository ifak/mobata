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
#ifndef VIEW_GRAPH_RESIZINGRECTNODE_HPP
#define VIEW_GRAPH_RESIZINGRECTNODE_HPP

#include "../mobatawidgets_global.hpp"

#include "types.hpp"
#include "abstractnode.hpp"

class QGraphicsProxyWidget;

namespace view{
namespace graph{

class ResizingRect;

class MOBATAWIDGETSSHARED_EXPORT ResizingRectNode
    : public AbstractNode
{
public:
  enum { Type = ResizingRectType};
  
public:
	ResizingRectNode(const QString& notation=QString(),
										const NodeOptions& nodeOptions=NodeOptions(), 
										const QUuid &uuid=QUuid::createUuid(),
										QGraphicsItem * parent = 0);

	virtual ~ResizingRectNode();

public:
	virtual int			type() const;
	virtual void		paint(QPainter *painter, 
												const QStyleOptionGraphicsItem *option, 
												QWidget *widget = 0);
	
public:
	QSizeF	size() const;
	void		setSize(QSizeF size);

	QRectF	boundingRect() const;
	QRectF	rect() const;
	void		setControlPointsMovable(bool value);
	void		setControlPointsSelectable(bool value);
	void		setMinimumSize(QSizeF minSize);
	void		setWidget(QWidget* widget, uint offset);

protected:
	void									updateProxyWidgetGeometry();
	ResizingRect*				getResizingRect();
	QGraphicsProxyWidget*	getProxyWidget();

private:
	class Private;
	Private* _d;
};

}////end namespace graph
}//end namespace view

#endif // VIEW_GRAPH_RECTNODE_HPP
