#include "choicestateitem.hpp"

#include "../../memory_leak_start.hpp"

namespace model {
namespace statemachine {

ChoiceStateItem::ChoiceStateItem(const QString& name,
                                 const QUuid& id)
  : AbstractStateItem(name.isEmpty()?QStringLiteral("choice"):name,
                      id)
{
  this->setIcon(QIcon(QLatin1String(":mobata/images/statemachine/choicestate.png")));
}

ChoiceStateItem::~ChoiceStateItem()
{}

StateType ChoiceStateItem::stateType() const
{
  return Choice;
}

} // namespace statemachine
} // namespace model

