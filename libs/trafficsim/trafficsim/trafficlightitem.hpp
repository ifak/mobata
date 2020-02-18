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
#ifndef TRAFFICLIGHTITEM_HPP
#define TRAFFICLIGHTITEM_HPP

#include <mobata/model/base/modelitem.hpp>

#include "tlTransitionitem.hpp"

namespace trafficsim {

class PhaseItem;

class TrafficLightItem : public model::base::ModelItem
{
public:
    /**
     * @brief TrafficLightItem
     * @param name
     * @param id id of the junction controlled by traffic light
     * @param type type of the traffic light
     */
    TrafficLightItem(const QString& name, const QString& type, int duration, int turns , bool createPhases);
    ~TrafficLightItem();

    /**
     * @brief trafficLightType
     * @return type
     */
    QString trafficLightType() const;

    /**
     * @brief id
     * @return id
     */
    QString id() const;

    /**
     * @brief duration
     * @return duration
     */
    double duration() const;

    /**
     * @brief phases
     * @return phases
     */
    const QList<PhaseItem *> &phases() const;

    /**
     * @brief turns
     * @return turns
     */
    int turns() const;

    /**
     * @brief addPhases
     * @param newPhase
     */
    void addPhases(PhaseItem* &newPhase);

    const QList<TlTransitionItem *> &transitions() const;
    void addTransitions(TlTransitionItem* &newTransition);

    /**
     * @brief setId
     * @param id
     */
    void setID(const QString &id);

    /**
     * @brief setDuration
     * @param duration
     */
    void setDuration(int duration);

    /**
     * @brief setCreatePhases
     * @param createPhases
     */
    void setCreatePhases(bool createPhases);

    /**
     * @brief createPhases
     * @return createPhases
     */
    bool createPhases() const;

private:
    /**
     * @brief _types
     */
    QString _type;

    /**
     * @brief _duration
     */
    double _duration;

    /**
     * @brief _id
     */
    QString _id;

    /**
     * @brief _phases
     */
    QList<PhaseItem* > _phases;
    QList<TlTransitionItem* > _transitions;

    /**
     * @brief _turns
     */
    int _turns;

    /**
     * @brief _createPhases
     */
    bool _createPhases;
};
}//namespace trafficsim
#endif // TRAFFICLIGHTITEM_HPP
