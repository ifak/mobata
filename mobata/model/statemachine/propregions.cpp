#include "propregions.hpp"

#include "regionitem.hpp"

#include <QString>
#include <QIcon>

#include "../../memory_leak_start.hpp"

namespace model {
namespace statemachine {

class PropRegions::Private
{
  friend class PropRegions;
};

PropRegions::PropRegions(QStandardItem* ownerItem)
  : BaseClass(ownerItem,
              QLatin1String("regions"),
              QIcon(QLatin1String(":/mobata/images/statemachine/manyregion.png"))),
    _d(new Private)
{}

PropRegions::~PropRegions()
{
  delete this->_d;
}

void PropRegions::resetRegions()
{
  return BaseClass::resetChildren();
}

bool PropRegions::addRegion(RegionItem* regionItem,
                          QString* errorString)
{
  Q_ASSERT(this->_ownerItem);
  Q_ASSERT(regionItem);

  if(this->region(regionItem->uuid()))
  {
    if(errorString)
      *errorString += QObject::tr("there is already a region with this id; "
                                  "region '%1' is not added!").arg(regionItem->name());
    return false;
  }

  BaseClass::addChild(regionItem);

  return true;
}

RegionItem const*  PropRegions::region(const QUuid& regionId) const
{
  return BaseClass::childByUuid(regionId);
}

PropRegions::RegionSet PropRegions::regions()
{
  return BaseClass::children();
}

PropRegions::ConstRegionSet PropRegions::regions() const
{
  return BaseClass::children();
}

void PropRegions::removeRegion(const QUuid& regionUuid)
{
  return BaseClass::removeChild(regionUuid);
}

void PropRegions::removeRegion(RegionItem* regionItem)
{
  return BaseClass::removeChild(regionItem);
}

} // namespace statemachine
} // namespace model

