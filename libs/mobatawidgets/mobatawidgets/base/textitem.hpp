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
#ifndef VIEW_BASE_TEXTITEM_HPP
#define VIEW_BASE_TEXTITEM_HPP

#include "../mobatawidgets_global.hpp"

#include "types.hpp"

#include <QGraphicsTextItem>

class QSyntaxHighlighter;

namespace view{
namespace base{

class MOBATAWIDGETSSHARED_EXPORT TextItem
    : public QGraphicsTextItem
{
  Q_OBJECT

public:
  enum {Type = TextType};

public:
  TextItem(const QString& text, QGraphicsItem * parentItem = 0);
  virtual ~TextItem();

signals:
  void changed(bool);

public:
  int		type() const;
  void	setSyntaxHighlighter(QSyntaxHighlighter* syntaxHighlighter);
  void	showAssociationLine(bool value);

protected:
  virtual void      focusOutEvent(QFocusEvent * event);
  virtual void      mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);
  virtual QVariant  itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant& value);

private:
  class Private;
  Private* _d;
};

}//end namespace base
}//end namespace view

#endif //VIEW_BASE_TEXTITEM_HPP
