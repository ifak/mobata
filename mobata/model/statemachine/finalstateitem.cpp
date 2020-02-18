#include "finalstateitem.hpp"

#include "../../memory_leak_start.hpp"

namespace model {
namespace statemachine {

FinalStateItem::FinalStateItem(const QString& name,
                               const QUuid& id)
  : AbstractStateItem(name.isEmpty()?QStringLiteral("final"):name,
                      id)
{
  this->setIcon(QIcon(QLatin1String(":mobata/images/statemachine/finalstate.png")));
}

FinalStateItem::~FinalStateItem()
{}

StateType FinalStateItem::stateType() const
{
  return Final;
}

} // namespace statemachine
} // namespace model

