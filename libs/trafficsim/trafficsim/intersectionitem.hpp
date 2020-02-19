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
#ifndef INTERSECTIONITEM_HPP
#define INTERSECTIONITEM_HPP

#include <mobata/model/base/modelitem.hpp>
#include "sensoritem.hpp"
#include <QQmlError>

namespace trafficsim {

class EdgeItem;
class TrafficLightItem;
class TrafficDistributionItem;
class SensorItem;

/**
 * @brief The IntersectionItem class reprenting a single intersection with a number of edges and an optional traffic light
 */
class IntersectionItem : public model::base::ModelItem
{
public:
    /**
     * @brief IntersectionItem
     * @param name name of the intersection
     * @param accident the probability of an accident to occur
     * @param hasTrafficLight true if the intersection is controlled by a traffic light
     */
    IntersectionItem(const QString& name, qreal accident, bool hasTrafficLight);
    ~IntersectionItem();

    /**
     * @brief edgeNames
     * @return the name of the edges contained in the intersection
     */
    QList<QString> edgeNames() const;

    /**
     * @brief setEdgeNames sets the names of the different edges
     *          useful for mapping purpose
     * @param edgeNames
     */
    void setEdgeNames(const QList<QString>& edgeNames);

    /**
     * @brief addEdgeName adds a name to the edges
     * @param name
     */
    void addEdgeName(const QString& name);

    /**
     * @brief addEdge adds an edge
     * @param name name of the edge
     * @param errorList container for errors
     * @param fileName
     * @return
     */
    EdgeItem* addEdge(const QString& name,
                      QList<QQmlError>& errorList,
                      const QString& fileName);

    /**
     * @brief edges
     * @return a list of EdgeItem
     */
    const QList<EdgeItem*>& edges() const;

    /**
     * @brief accident
     * @return probability of an accident to occur
     */
    qreal accident() const;

    /**
     * @brief hasTrafficLight
     * @return true if a traffic light is present
     */
    bool hasTrafficLight() const;


    /**
     * @brief trafficLight
     * @return a list of all defined traffic lights
     */
    const QList<TrafficLightItem* >& trafficLights() const;

    /**
     * @brief addTrafficLight
     * @param newtrafficLight
     */
    void addTrafficLight(TrafficLightItem* newTrafficLight);


    const QList<SensorItem* >& sensors() const;
    void addSensor(SensorItem* sensors);

private:
    /**
     * @brief _edgeNames
     */
    QList<QString> _edgeNames;

    /**
     * @brief _edges
     */
    QList<EdgeItem*> _edges;

    /**
     * @brief _edgeParent
     */
    ModelItem* _edgeParent;

    /**
     * @brief _accident
     */
    qreal _accident;

    /**
     * @brief _hasTrafficLight
     */
    bool _hasTrafficLight;

    /**
     * @brief _TrafficLight
     */
    QList<TrafficLightItem* > _trafficLights;
    QList<SensorItem* > _sensors;

};

}//namespace trafficsim

#endif // INTERSECTIONITEM_HPP
