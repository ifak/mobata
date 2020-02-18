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
#ifndef VIEW_SPENAT_TYPES_HPP
#define VIEW_SPENAT_TYPES_HPP

#include "../mobatawidgets_global.hpp"

#include "../comp/types.hpp"

namespace view{
namespace spenat{

enum SpenatType
{
  PlaceType=comp::CompUserType+1,
  TransitionType,
  JunctionType,
  ArcType,
  SpenatUserType
};

class MOBATAWIDGETSSHARED_EXPORT PlaceOptions : public graph::NodeOptions
{
public:
	PlaceOptions()
		: _markingBrush(Qt::darkBlue),
			_markingTextColor(Qt::white)
	{
		this->setTextFont(QFont(QLatin1String("Arial"),10));
		this->setSize(40,30);
	}
	virtual ~PlaceOptions()
	{}
	
public:
	QColor getMarkingBrush() const
	{
		return this->_markingBrush;
	}
	
	QColor getMarkingTextColor() const
	{
		return this->_markingTextColor;
	}
	
private:
	QColor	_markingBrush;
	QColor	_markingTextColor;
};

class MOBATAWIDGETSSHARED_EXPORT TransitionOptions
		:	public graph::NodeOptions
{
public:
	TransitionOptions()
	{
		this->setTextFont(QFont(QLatin1String("Arial"),10));
		this->setSize(40,30);
    this->setColor(QColor("darkBlue"));
	}
	
	virtual ~TransitionOptions()
	{}
};

class MOBATAWIDGETSSHARED_EXPORT ArcOptions : public graph::ArcOptions
{
public:
	ArcOptions()
	{
		this->setTextFont(QFont(QLatin1String("Arial"),10));
	}
	
	virtual ~ArcOptions()
	{}
};

}/// namespace spenat
}/// namespace view

#endif // VIEW_SPENAT_TYPES_HPP
