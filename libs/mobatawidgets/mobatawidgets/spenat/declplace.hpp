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
#ifndef VIEW_SPENAT_DECLPLACE_HPP
#define VIEW_SPENAT_DECLPLACE_HPP

#include "../mobatawidgets_global.hpp"

#include "types.hpp"

#include "../graph/roundrectnode.hpp"

namespace view{
namespace spenat{

class MOBATAWIDGETSSHARED_EXPORT DeclPlace : public graph::RoundRectNode
{
public:
  enum { Type = PlaceType};

public:
	DeclPlace(const QString& notation=QLatin1String("newPlace"),
						 const PlaceOptions& placeOptions=PlaceOptions());
	DeclPlace(const QString& notation);
	DeclPlace(const PlaceOptions& placeOptions);
	
	virtual ~DeclPlace();
  
public:
  virtual int type() const;
	
public:
	void	centerNotationItem();
	void	setMarking(const bool marking);
	bool	getMarking() const;
	void	setInitMarking(const bool initMarking);
	bool	getInitMarking() const;
	
private:
	void createMarkingPoint();
	
private:
	class Private;
	Private* _d;
};

}/// namespace spenat
}/// namespace view

#endif // VIEW_SPENAT_DECLPLACE_HPP
