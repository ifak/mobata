/*
 * This file is part of mobata.
 *
 * Copyright (C) 2019 ifak, https://www.ifak.eu/
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

#include "placearc.hpp"

#include "placeitem.hpp"

namespace model{
namespace spenat{

class PlaceArc::Private
{
	friend class PlaceArc;
	
public:
	Private() : _place(0)
	{}
	~Private()
	{}
	
private:
	PlaceItem const* _place;
};

PlaceArc::PlaceArc(const QUuid &uuid)
	:	ModelItem(uuid), _d(new Private())
{}

PlaceArc::~PlaceArc()
{}

PlaceItem const* PlaceArc::place() const
{
	return this->_d->_place;
}

void PlaceArc::setPlace(PlaceItem const* place)
{
	this->_d->_place=place;
	
	return;
}

QString PlaceArc::toString() const
{
	if(this->_d->_place)
		return this->_d->_place->name();

	return QLatin1String("");
}

} // namespace model
} // namespace spenat
