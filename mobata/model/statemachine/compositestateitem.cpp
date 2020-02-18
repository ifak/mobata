#include "compositestateitem.hpp"

namespace model {
namespace statemachine {

CompositeStateItem::CompositeStateItem(const QString& name,
                                       const QUuid& id)
  : AbstractStateItem(name, id),
    PropStates(this)
{
  this->setIcon(QIcon(QLatin1String(":mobata/images/statemachine/compositestate.png")));
}

CompositeStateItem::~CompositeStateItem()
{}

StateType CompositeStateItem::stateType() const
{
  return Composite;
}

} // namespace statemachine
} // namespace model
