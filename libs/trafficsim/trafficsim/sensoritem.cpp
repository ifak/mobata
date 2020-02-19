#include "sensoritem.hpp"

namespace trafficsim {

SensorItem::SensorItem(QString const &name,QString const &type,QString const &measuredArm,QString const &measuredLane,QString const &message):
    ModelItem("Sensor"),_name(name),_sensorType(type), _measuredArm(measuredArm), _measuredLane(measuredLane), _message(message)
{

}

QString SensorItem::name() const{
    return _name;
}


QString SensorItem::sensorType() const{
    return _sensorType;
}

QString SensorItem::measuredArm() const{
    return _measuredArm;
}

QString SensorItem::measuredLane() const{
    return _measuredLane;
}

QString SensorItem::message() const{
    return _message;
}
}///end namespace trafficsim
