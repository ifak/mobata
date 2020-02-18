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
#ifndef PHASEITEM_HPP
#define PHASEITEM_HPP

#include <mobata/model/base/modelitem.hpp>

namespace trafficsim {

class EdgeItem;

class PhaseItem : public model::base::ModelItem
{
public:
    /**
     * @brief PhaseItem
     * @param state state of every traffic light
     * @param duration of the main green phase
     */
    PhaseItem(const QMap<QString,QString> states, double duration, const QString &name, double minDur, double maxDur);
    ~PhaseItem();

    /**
     * @brief state
     * @return state
     */
    QMap<QString,QString> states() const;
    /**
     * @brief duration
     * @return duration
     */
    double duration() const;
    /**
     * @brief minDur
     * @return minDur
     */
    double minDur() const;
    /**
     * @brief maxDur
     * @return maxDur
     */
    double maxDur() const;
    /**
     * @brief name
     * @return name
     */
    QString name() const;

private:

    /**
     * @brief _state
     */
    QMap<QString,QString> _states;

    /**
     * @brief _duration
     */
    double _duration;

    QString _name;

    /**
     * @brief _minDur
     */
    double _minDur;

    /**
     * @brief _maxDur
     */
    double _maxDur;

};
}//namespace trafficsim
#endif // PHASEITEM_HPP
