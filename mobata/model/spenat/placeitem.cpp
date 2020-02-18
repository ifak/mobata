#include "placeitem.hpp"

#include "../../memory_leak_start.hpp"

namespace model{
namespace spenat{

PlaceItem::PlaceItem(const QString& name,
                       const QUuid& id)
  :	NodeItem(id), prop::NameProperty(name)
{
  this->setIcon(QIcon(QLatin1String(":mobata/images/spenat/place.png")));
}

PlaceItem::~PlaceItem()
{}

QString PlaceItem::toString() const
{
  return this->name();
}

}///end namespace model
}///end namespace spenat
