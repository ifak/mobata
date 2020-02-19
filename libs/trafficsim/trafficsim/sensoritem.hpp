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
#ifndef SENSORITEM_H
#define SENSORITEM_H

#include <mobata/model/base/modelitem.hpp>

namespace trafficsim {

class SensorItem : public model::base::ModelItem
{
public:
    SensorItem(QString const &name,QString const &sensorType,QString const &measuredArm,QString const &measuredLane,QString const &message);
    QString name() const;

    QString sensorType() const;

    QString measuredArm() const;

    QString measuredLane() const;

    QString message() const;
private:
    QString _name;
    QString _sensorType;
    QString _measuredArm;
    QString _measuredLane;
    QString _message;
};
}//namespace trafficsim
#endif // SENSORITEM_H
