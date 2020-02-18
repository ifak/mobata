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
#ifndef VIEW_SPENAT_DECLTRANSITION_HPP
#define VIEW_SPENAT_DECLTRANSITION_HPP

#include "../mobatawidgets_global.hpp"

#include "types.hpp"

#include "../graph/rectnode.hpp"

namespace view{
namespace spenat{

class MOBATAWIDGETSSHARED_EXPORT DeclTransition : public graph::RectNode
{
public:
  enum { Type = TransitionType};

public:
  DeclTransition(const QString& notation=QLatin1String("ev[guard]/send ev() to env;"),
                 const TransitionOptions& transitionOptions=TransitionOptions());
  DeclTransition(const TransitionOptions& transitionOptions);
  DeclTransition(const QString& notation);

  virtual ~DeclTransition();

public:
  virtual int type() const;
};

}///end namespace spenat
}///end namespace view

#endif // VIEW_SPENAT_DECLTRANSITION_HPP
