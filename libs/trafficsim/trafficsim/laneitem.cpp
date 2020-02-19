#include "laneitem.hpp"
#include "lanetypeitem.hpp"

namespace trafficsim {

LaneItem::LaneItem(const QString &name, const QString &type)
    : model::base::ModelItem(QUuid(name)),
      _laneType(new LaneTypeItem(type))
{
    this->appendRow(_laneType);
}

LaneItem::~LaneItem()
{
    this->takeRow(_laneType->row());
    delete _laneType;
}

QString LaneItem::name() const
{
    return _laneType->accessibleText(); //TODO: no idea if this works!
}

LaneTypeItem *LaneItem::laneType() const
{
    return _laneType;
}

}///end namespace trafficsim
