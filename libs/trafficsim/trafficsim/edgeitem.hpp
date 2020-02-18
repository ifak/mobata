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
#ifndef EDGEITEM_HPP
#define EDGEITEM_HPP

#include <QQmlError>
#include <mobata/model/base/modelitem.hpp>

namespace trafficsim {

class LaneItem;
class PhaseItem;

/**
 * @brief The EdgeItem class representing an abstract edge of an intersection
 */
class MOBATASHARED_EXPORT EdgeItem : public model::base::ModelItem
{
public:
    EdgeItem(const QString& name);
    ~EdgeItem();

    /**
     * @brief addLane adds a lane child to the edge item
     * @param name the name of the lane
     * @param type the type e.g. bicycle, carIn
     * @param errorLIst container for errors
     * @param fileName
     * @return true if no error happend false otherwise
     */
    bool addLane(const QString& name,
                 const QString& type,
                 QList<QQmlError>& errorList,
                 const QString& fileName);

    /**
     * @brief
     * @return list of LaneItem containting all ingoing lanes of the intersection within the edge
     */
    const QList<LaneItem*>& inboundLanes() const;

    /**
     * @brief outboundLanes
     * @return list of LaneItem containting all outgoing lanes of the intersection within the edge
     */
    const QList<LaneItem*>& outboundLanes() const;

    /**
     * @brief numLanes
     * @return number of lanes
     */
    int numLanes() const;

    /**
     * @brief addPhase
     * @param phase
     */
    void addPhase(PhaseItem* &phase);

    /**
     * @brief phases
     * @return list of phases
     */
    const QList<PhaseItem* > & phases() const;

private:
    ModelItem* _lanesParent;
    int _numLanes;

    /**
     * @brief _inboundLanes
     */
    QList<LaneItem*> _inboundLanes;

    /**
     * @brief _outboundLanes
     */
    QList<LaneItem*> _outboundLanes;

    /**
     * @brief isLanePresent checks if the edge has a lane called name
     * @param name the name of the lane
     * @return true if a lane with the name was found otherwise false
     */
    bool isLanePresent(const QString& name);

    /**
     * @brief isLanePresent
     * @param name
     * @param isEgress
     * @return
     */
    bool isLanePresent(const QString& name, bool isEgress);

    /**
     * @brief _phases
     */
    QList<PhaseItem* >  _phases;
};

}//namespace trafficsim

#endif // EDGEITEM_HPP
