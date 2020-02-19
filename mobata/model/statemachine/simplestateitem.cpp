#include "simplestateitem.hpp"

#include "../../memory_leak_start.hpp"

namespace model {
namespace statemachine {

SimpleStateItem::SimpleStateItem(const QString& name,
                                 const QString& entryAction,
                                 const QString& exitAction,
                                 const QUuid& id)
  : AbstractStateItem(name, id),
    PropEntryAction(entryAction),
    PropExitAction(exitAction)
{
  this->setIcon(QIcon(QLatin1String(":mobata/images/statemachine/simplestate.png")));
}

SimpleStateItem::~SimpleStateItem()
{}

StateType SimpleStateItem::stateType() const
{
  return Simple;
}

} // namespace statemachine
} // namespace model

