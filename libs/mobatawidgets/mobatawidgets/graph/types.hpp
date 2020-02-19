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
#ifndef VIEW_GRAPH_TYPES_HPP
#define VIEW_GRAPH_TYPES_HPP

#include "../mobatawidgets_global.hpp"

#include "../base/types.hpp"

#include <QPen>
#include <QSizeF>
#include <QFont>
#include <QColor>

#include <QGraphicsItem>

namespace view{
namespace graph{

enum GraphType
{
  ArrowType=base::BaseUserType+1,
  ControlPointType,
  EdgeType,
  DirectedEdgeType,
  EllipseType,
  NodeType,
  RectType,
  ResizingRectType,
  RoundRectType,
  GraphUserType
};

class MOBATAWIDGETSSHARED_EXPORT PenOption
{
public:
  PenOption(QPen pen=QPen(Qt::black)) : _pen(pen)
  {}

public:
  QPen	pen() const		{return this->_pen;}
  void	setPen(QPen pen)	{this->_pen=pen;}

protected:
  QPen	_pen;
};

class MOBATAWIDGETSSHARED_EXPORT ColorOption
{
public:
  ColorOption(QColor color=Qt::darkYellow) : _color(color)
  {}

public:
  QColor	getColor() const			{return this->_color;}
  void		setColor(QColor color)	{this->_color=color;}

protected:
  QColor	_color;
};

class MOBATAWIDGETSSHARED_EXPORT SizeOption
{
public:
  SizeOption(QSizeF size=QSizeF(40,30)) : _size(size)
  {}

public:
  QSizeF	size() const				{return this->_size;}
  void		setSize(QSizeF size)	{this->_size=size;}

protected:
  QSizeF	_size;
};

class MOBATAWIDGETSSHARED_EXPORT TextOptions
{
public:
  TextOptions() : _textColor(Qt::black), _textFont(QFont(QLatin1String("Arial"),8))
  {}

  TextOptions(QColor textColor, QFont textFont)
    : _textColor(textColor), _textFont(textFont)
  {}

  TextOptions(QColor textColor) : _textColor(textColor), _textFont(QFont(QLatin1String("Arial"),8))
  {}

  TextOptions(QFont textFont) : _textColor(Qt::black), _textFont(textFont)
  {}

public:
  QColor  textColor() const               {return this->_textColor;}
  void    setTextColor(QColor textColor)  {this->_textColor=textColor;}

  QFont textFont() const            {return this->_textFont;}
  void  setTextFont(QFont textFont) {this->_textFont=textFont;}

protected:
  QColor  _textColor;
  QFont   _textFont;
};

class MOBATAWIDGETSSHARED_EXPORT NodeOptions
    : public PenOption, public ColorOption, public SizeOption, public TextOptions
{
public:
  NodeOptions()
  {}

  NodeOptions& setPen(const QPen& pen)
  {
    this->_pen=pen;

    return *this;
  }

  NodeOptions& setColor(const QColor& color)
  {
    this->_color=color;

    return *this;
  }

  NodeOptions& setSize(const QSizeF& size)
  {
    this->_size=size;

    return *this;
  }

  NodeOptions& setSize(qreal x, qreal y)
  {
    this->_size=QSizeF(x,y);

    return *this;
  }

  NodeOptions& setTextColor(const QColor& textColor)
  {
    this->_textColor=textColor;

    return *this;
  }

  NodeOptions& setTextFont(const QFont& textFont)
  {
    this->_textFont=textFont;

    return *this;
  }
};

class MOBATAWIDGETSSHARED_EXPORT ArcOptions
    : public PenOption,
    public TextOptions
{
public:
  ArcOptions()
  {}

  ArcOptions& setPen(const QPen& pen)
  {
    this->_pen=pen;

    return *this;
  }

  ArcOptions& setTextColor(const QColor& textColor)
  {
    this->_textColor=textColor;

    return *this;
  }

  ArcOptions& setTextFont(const QFont& textFont)
  {
    this->_textFont=textFont;

    return *this;
  }
};

}//end namespace graph
}//end namespace view

#endif // VIEW_GRAPH_TYPES_HPP
