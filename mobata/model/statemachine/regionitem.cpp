#include "regionitem.hpp"

namespace model {
namespace statemachine {

RegionItem::RegionItem(const QString& name,
                       const QUuid& id)
  : base::ModelItem(id),
    prop::NameProperty(name),
    PropStates(this)
{
  this->setIcon(QIcon(QLatin1String(":mobata/images/statemachine/region.png")));
  this->setText(name);
}

RegionItem::~RegionItem()
{}

} // namespace statemachine
} // namespace model

