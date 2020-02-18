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
#ifndef MODEL_SPENAT_INITPLACEITEM_HPP
#define MODEL_SPENAT_INITPLACEITEM_HPP

#include "../../mobata_global.hpp"

#include "../base/modelitem.hpp"

namespace model{
namespace spenat{
	
class PlaceItem;

class MOBATASHARED_EXPORT InitPlaceItem : public base::ModelItem
{
public:
	InitPlaceItem(PlaceItem const* placeItem);
	InitPlaceItem(const QUuid& uuid, 
								 PlaceItem const* placeItem);
	virtual ~InitPlaceItem();
	
public:
	PlaceItem const*	getPlaceItem() const;
	void							setPlaceItem(PlaceItem const* placeItem);

protected:
	PlaceItem const* _placeItem;
};

}//////end namespace spenat
}///end namespace model

#endif // MODEL_SPENAT_INITPLACEITEM_HPP
