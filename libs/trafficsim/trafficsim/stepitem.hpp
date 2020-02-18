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
#ifndef STEPITEM_HPP
#define STEPITEM_HPP

#include <mobata/model/base/modelitem.hpp>

namespace trafficsim {

class VehicleMovementItem;
class TrafficDistributionItem;

/**
 * @brief The StepItem class representing a single step item with its movement childs
 */
class StepItem : public model::base::ModelItem
{
public:
    /**
     * @brief StepItem
     * @param name
     * @param start start time of the  interval
     * @param stop end time of the interval
     */
    StepItem(const QString& name, int start, int stop);
    ~StepItem();
    /**
     * @brief addVehicleMovement
     * @param startEdge the edge the traffic will start
     * @param vehiclePerHour the number of vehicle per hour
     * @param distribution the vehicle distribution to be used
     * @return
     */
    VehicleMovementItem* addVehicleMovement(const QString& startEdge,
                                            int vehiclePerHour,
                                            TrafficDistributionItem* distribution);
    /**
     * @brief vehicleMovements
     * @return
     */
    const QList<VehicleMovementItem*>& vehicleMovements() const;
    /**
     * @brief start
     * @return
     */
    int start() const;
    /**
     * @brief stop
     * @return
     */
    int stop() const;

private:
    /**
     * @brief _movements
     */
    ModelItem* _movements;
    int _start;
    /**
     * @brief _stop
     */
    int _stop;
    /**
     * @brief _vehicleMovements
     */
    QList<VehicleMovementItem*> _vehicleMovements;

};
}//namespace trafficsim
#endif // STEPITEM_HPP
