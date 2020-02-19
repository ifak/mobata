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
#ifndef VEHICLEMOVEMENTITEM_HPP
#define VEHICLEMOVEMENTITEM_HPP

#include <mobata/model/base/modelitem.hpp>

namespace trafficsim {

class TrafficDistributionItem;

/**
 * @brief The VehicleMovementItem class representing a vehicle movement
 */

class VehicleMovementItem: public model::base::ModelItem
{
public:
    /**
     * @brief VehicleMovementItem
     * @param startEdge start edge
     * @param vehiclePerHour number of vehicle per hour
     * @param distribution used vehicle distribution
     */
    VehicleMovementItem(const QString& startEdge,
                        int vehiclePerHour,
                        TrafficDistributionItem* distribution);
    ~VehicleMovementItem();

    /**
     * @brief startEdge
     * @return
     */
    QString startEdge() const;

    /**
     * @brief vehiclePerHour
     * @return
     */
    int vehiclePerHour() const;

    /**
     * @brief distributionName
     * @return
     */
    QString distributionName() const;

private:
    /**
     * @brief _startEdge
     */
    QString _startEdge;

    /**
     * @brief _vehiclePerHour
     */
    int _vehiclePerHour;

    /**
     * @brief _distribution
     */
    TrafficDistributionItem* _distribution;
};
}//namespace trafficsim
#endif // VEHICLEMOVEMENTITEM_HPP
