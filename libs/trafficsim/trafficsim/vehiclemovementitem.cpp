#include "vehiclemovementitem.hpp"
#include "trafficdistributionitem.hpp"

namespace trafficsim {

VehicleMovementItem::VehicleMovementItem(const QString &startEdge,
                                         int vehiclePerHour,
                                         TrafficDistributionItem *distribution)
    : ModelItem("VehicleMovement"),
      _startEdge(startEdge),
      _vehiclePerHour(vehiclePerHour),
      _distribution(distribution)
{
    this->appendRow(new ModelItem("Startarm: " + startEdge));
    this->appendRow(new ModelItem("Vehicle per hour: " + QString::number(vehiclePerHour)));
    this->appendRow(_distribution);
}

VehicleMovementItem::~VehicleMovementItem()
{
    this->takeRow(_distribution->row());

    this->removeRows(0, this->rowCount());
}

QString VehicleMovementItem::startEdge() const
{
    return _startEdge;
}

int VehicleMovementItem::vehiclePerHour() const
{
    return _vehiclePerHour;
}

QString VehicleMovementItem::distributionName() const
{
    return _distribution->name();
}

}///end namespace trafficsim
