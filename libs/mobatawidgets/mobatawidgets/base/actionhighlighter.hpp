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
#ifndef VIEW_BASE_ACTIONHIGHLIGHTER_HPP
#define VIEW_BASE_ACTIONHIGHLIGHTER_HPP

#include "../mobatawidgets_global.hpp"

#include <QSyntaxHighlighter>
#include <QScopedPointer>

namespace view{
namespace base{

class MOBATAWIDGETSSHARED_EXPORT ActionHighlighter
		: public QSyntaxHighlighter
{
	Q_OBJECT

public:
  ActionHighlighter(QTextDocument* parent = 0);
  virtual ~ActionHighlighter();

protected:
	void highlightBlock(const QString &text);

private:
	class Private;
	QScopedPointer<Private> _d;
};

}/// namespace base
}/// namespace view

#endif
