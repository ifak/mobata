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
#ifndef VIEW_SPENAT_DECLJUNCTION_HPP
#define VIEW_SPENAT_DECLJUNCTION_HPP

#include "../mobatawidgets_global.hpp"

#include "../graph/ellipsenode.hpp"

#include "types.hpp"

namespace view{
namespace spenat{

class MOBATAWIDGETSSHARED_EXPORT DeclJunction : public graph::EllipseNode
{
public:
  enum { Type = JunctionType};

public:
	DeclJunction();	
	virtual ~DeclJunction();
  
public:
  virtual int type() const;
};

}///end namespace spenat
}///end namespace view

#endif // VIEW_SPENAT_DECLJUNCTION_HPP
