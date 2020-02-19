#include "stepitem.hpp"
#include "vehiclemovementitem.hpp"
#include "trafficdistributionitem.hpp"

namespace trafficsim {

StepItem::StepItem(const QString &name, int start, int stop)
    : ModelItem(name),
      _movements(0),
      _start(start),
      _stop(stop)
{
    this->appendRow(new ModelItem("Start: " + QString::number(start)));
    this->appendRow(new ModelItem("Stop: " + QString::number(stop)));
}

StepItem::~StepItem()
{
    if (_movements)
    {
        for (int i = 0; i < _vehicleMovements.count(); i++)
        {
            _movements->takeRow(_vehicleMovements.at(i)->row());
        }
        qDeleteAll(_vehicleMovements);

        _movements->removeRows(0, _movements->rowCount());

        this->takeRow(_movements->row());
        delete _movements;
    }

    this->removeRows(0, this->rowCount());
}

VehicleMovementItem *StepItem::addVehicleMovement(const QString &startEdge,
                                                  int vehiclePerHour,
                                                  TrafficDistributionItem *distribution)
{
    if(0x00 == _movements)
    {
        _movements = new ModelItem("Movements");
        this->appendRow(_movements);
    }

    VehicleMovementItem *newMovement = new VehicleMovementItem(startEdge, vehiclePerHour, distribution);
    _movements->appendRow(newMovement);

    _vehicleMovements.append(newMovement);

    return newMovement;
}

const QList<VehicleMovementItem*> &StepItem::vehicleMovements() const
{
    return _vehicleMovements;
}

int StepItem::start() const
{
    return _start;
}

int StepItem::stop() const
{
    return _stop;
}

}///end namespace trafficsim
