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
#ifndef VIEW_BASE_TEXTEDITWIDGETITEM_HPP
#define VIEW_BASE_TEXTEDITWIDGETITEM_HPP

#include "../mobatawidgets_global.hpp"

#include <QGraphicsProxyWidget>

#include "types.hpp"

class QTextEdit;

namespace view{
namespace base{

class MOBATAWIDGETSSHARED_EXPORT TextEditWidget
    : public QGraphicsProxyWidget
{
public:
  enum {Type = TextEditWidgetType};

public:
  TextEditWidget(QTextEdit* textEditWidget =0, QGraphicsItem * parent = 0 );
  virtual ~TextEditWidget();

public:
  int	type() const;

  //protected:
  //	virtual void			focusOutEvent(QFocusEvent * event);
  //	virtual void			mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);
  //	virtual QVariant	itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant& value);
};

}//end namespace base
}//end namespace view

#endif // VIEW_BASE_TEXTWIDGETITEM_HPP
