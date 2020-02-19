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
#ifndef MODEL_SPENAT_NODEITEM_HPP
#define MODEL_SPENAT_NODEITEM_HPP

#include "../../modeling_global.hpp"

#include "../base/modelitem.hpp"

namespace model{
namespace spenat{

class MODELINGSHARED_EXPORT NodeItem	:	public base::ModelItem
{
public:
	NodeItem(const QUuid& uuid);
	virtual ~NodeItem();
};

}//////end namespace spenat
}///end namespace model

#endif // MODEL_SPENAT_NODEITEM_HPP
