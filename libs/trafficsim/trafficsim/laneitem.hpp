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
#ifndef LANEITEM_HPP
#define LANEITEM_HPP

#include <mobata/model/base/modelitem.hpp>

namespace trafficsim {

class LaneTypeItem;

/**
 * @brief The LaneItem class represents a single lane within the edge
 */
class LaneItem : public model::base::ModelItem
{
public:
    /**
     * @brief LaneItem
     * @param name name of the lane
     * @param type
     */
    LaneItem(const QString& name, const QString& type);
    ~LaneItem();

    /**
     * @brief name
     * @return
     */
    QString name() const;

    /**
     * @brief laneType
     * @return
     */
    LaneTypeItem* laneType() const;

private:
    /**
     * @brief _laneType
     */
    LaneTypeItem* _laneType;
};

}//namespace trafficsim

#endif // LANEITEM_HPP
