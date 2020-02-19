#include "concurrentstateitem.hpp"
#include "regionitem.hpp"

#include <QString>

namespace model {
namespace statemachine {

ConcurrentStateItem::ConcurrentStateItem(const QString& name,
                                         const QUuid& id)
  : AbstractStateItem(name, id),
    PropRegions(this)
{
  this->setIcon(QIcon(QLatin1String(":mobata/images/statemachine/concurrentstate.png")));
}

ConcurrentStateItem::~ConcurrentStateItem()
{}

StateType ConcurrentStateItem::stateType() const
{
  return Concurrent;
}

bool ConcurrentStateItem::initRegions(int numRegions,
                                      QString* errorString)
{
  if(this->regions().count())
    return false;

  while(this->regions().count() < 2 || this->regions().count() < numRegions){
    RegionItem* region = new RegionItem(QString("region") + QString::number(this->regions().count()));
    this->addRegion(region, errorString);

    Q_ASSERT(region);
  }

  return true;
}

} // namespace statemachine
} // namespace model
