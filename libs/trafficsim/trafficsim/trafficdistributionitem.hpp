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
#ifndef TRAFFICDISTRIBUTIONITEM_HPP
#define TRAFFICDISTRIBUTIONITEM_HPP

#include <mobata/model/base/modelitem.hpp>

namespace trafficsim {
/**
 * @brief The TrafficDistributionItem class item to represent a traffic distribution for the different vehicle classes
 */
class TrafficDistributionItem : public model::base::ModelItem
{
public:
    /**
     * @brief TrafficDistributionItem
     * @param name the unique name of the distribution
     * @param car probability of cars
     * @param bicycle probability of
     * @param moped probability of
     * @param bus probability of
     * @param motorcycle probability of
     * @param truck probability of
     * @param emergency probability of
     */
    TrafficDistributionItem(const QString& name,
                            float car = 0.4,
                            float bicycle = 0.15,
                            float moped = 0.05,
                            float bus = 0.1,
                            float motorcycle = 0.05,
                            float truck = 0.2,
                            float emergency = 0.05);
    virtual ~TrafficDistributionItem();

    /**
     * @brief copy creates a deep copy
     * @return the copy
     */
    TrafficDistributionItem* copy();

    /**
     * @brief values
     * @return a list of all values for the different vehicle types
     */
    const QList<float>& values() const;

    /**
     * @brief name
     * @return
     */
    QString name() const;

private:
    /**
     * @brief _values
     */
    QList<float> _values;

    /**
     * @brief _name
     */
    QString _name;

    /**
     * @brief TrafficDistributionItem
     */
    TrafficDistributionItem();
};
}//namespace trafficsim
#endif // TRAFFICDISTRIBUTIONITEM_HPP
