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
#ifndef TRAFFICSIMMODEL_HPP
#define TRAFFICSIMMODEL_HPP

#include <QStandardItemModel>
#include <QQmlError>
#include "trafficdistributionitem.hpp"

#include <mobata/model/base/modelitem.hpp>

namespace trafficsim {

class IntersectionItem;
class StepItem;

/**
 * @brief The SimulationModel class containting the model representation of the TrafficSim file
 * inherits from QStandardItemModel and therefore can be used to show treeView
 */
class TrafficSimModel : public QStandardItemModel
{
public:
    /**
     * @brief SimulationModel
     */
    TrafficSimModel(QObject* parent=0);
    ~TrafficSimModel();

    /**
     * @brief trafficDistributions
     * @return a list of all defined traffic distributions
     */
    const QList<TrafficDistributionItem*>& trafficDistributions() const;

    /**
     * @brief setTrafficDistributions
     * @param value
     */
    void setTrafficDistributions(const QList<TrafficDistributionItem*>& value);

    /**
     * @brief addTrafficDistribution
     * @param newDistribution
     */
    void addTrafficDistribution(TrafficDistributionItem* newDistribution);


    /**
     * @brief createIntersection creates an intersection item
     * @param name
     * @param accident probability of an accident to occur
     * @param hasTrafficLight true if the intersection will be controlled by a traffic light
     * @param errorList container for errors
     * @param fileName
     * @return
     */
    IntersectionItem* addIntersection(const QString& name,
                                         qreal accident,
                                         bool hasTrafficLight,
                                         QList<QQmlError>& errorList,
                                         const QString& fileName);

    /**
     * @brief addStep adds a new step
     * @param name
     * @param start start time of the step
     * @param stop end time of the steo
     * @return
     */
    StepItem* addStep(const QString &name, int start, int stop);

    /**
     * @brief simulationSteps
     * @return list of steps
     */
    const QList<StepItem*>& simulationSteps() const;

    /**
     * @brief intersection
     * @return
     */
    const QList<IntersectionItem*>& intersections() const;

    /**
     * @brief reset
     * @return
     */
    void reset();

private:
    /**
     * @brief _intersection
     */
    QList<IntersectionItem*> _intersections;

    /**
     * @brief _trafficDistributions
     */
    QList<TrafficDistributionItem*> _trafficDistributions;


    /**
     * @brief _steps
     */
    model::base::ModelItem* _steps;

    /**
     * @brief _simulationSteps
     */
    QList<StepItem*> _simulationSteps;

};
}//namespace trafficsim
#endif // TRAFFICSIMMODEL_HPP
