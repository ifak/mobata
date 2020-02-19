#include "timeouttriggeritem.hpp"

namespace model {
namespace base {

TimeoutTriggerItem::TimeoutTriggerItem(const double value)
  : _value(value)
{}

TimeoutTriggerItem::~TimeoutTriggerItem()
{}

ATriggerItem::TriggerType TimeoutTriggerItem::triggerType() const
{
  return TimeoutTrigger;
}

QString TimeoutTriggerItem::declaration() const
{
  return QString(QStringLiteral("after ")
                 + QString(QStringLiteral("%1")).arg(this->_value)
                 + QStringLiteral("ms"));

}

void  TimeoutTriggerItem::setValue(const double value)
{
  this->_value=value;

  return;
}

double TimeoutTriggerItem::value() const
{
  return this->_value;
}

} // namespace base
} // namespace model
