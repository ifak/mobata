#include <QDebug>

#include "trafficdistributionitem.hpp"

namespace trafficsim {


TrafficDistributionItem::TrafficDistributionItem(const QString &name,
                                                 float car,
                                                 float bicycle,
                                                 float moped,
                                                 float bus,
                                                 float motorcycle,
                                                 float truck,
                                                 float emergency)
    : ModelItem("TrafficDistribution"),
      _name(name)
{
    this->appendRow(new ModelItem("Name: " + name));
    this->appendRow(new ModelItem("Car: " + QString::number(car)));
    this->appendRow(new ModelItem("Bicycle: " + QString::number(bicycle)));
    this->appendRow(new ModelItem("Truck: " + QString::number(truck)));
    this->appendRow(new ModelItem("Bus: " + QString::number(bus)));
    this->appendRow(new ModelItem("Moped: " + QString::number(moped)));
    this->appendRow(new ModelItem("Motorcycle: " + QString::number(motorcycle)));
    this->appendRow(new ModelItem("Emergency: " + QString::number(emergency)));
    _values.append(car);
    _values.append(bicycle);
    _values.append(moped);
    _values.append(bus);
    _values.append(motorcycle);
    _values.append(truck);
    _values.append(emergency);
}

TrafficDistributionItem::~TrafficDistributionItem()
{
    this->removeRows(0, this->rowCount());
}

TrafficDistributionItem *TrafficDistributionItem::copy()
{
    TrafficDistributionItem *copy = new TrafficDistributionItem();
    for(int i = 0; i < this->rowCount(); i++)
    {
        copy->appendRow(this->child(i)->clone());
    }
    copy->_name = _name;

    return copy;
}

const QList<float> &TrafficDistributionItem::values() const
{
    return _values;
}

QString TrafficDistributionItem::name() const
{
    return _name;
}

TrafficDistributionItem::TrafficDistributionItem()
    : ModelItem("TrafficDistribution")
{
    // Do nothing
}
}///end namespace trafficsim
