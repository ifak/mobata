#include "msctimeoutitem.hpp"

#include "msctimeritem.hpp"

#include "../../memory_leak_start.hpp"

namespace model {
namespace msc {

class MscTimeoutItem::Private
{
  friend class MscTimeoutItem;

  Private(MscTimerItem const* timer)
    : _timer(timer)
  {}

  MscTimerItem const* _timer;
};
MscTimeoutItem::MscTimeoutItem(const MscComponentItem* component,
                               MscTimerItem const* timer)
  : MscStepItem(component),
    _d(new Private(timer))
{
  Q_ASSERT(component);
  Q_ASSERT(this->_d->_timer);
  Q_ASSERT(component==this->_d->_timer->component());

  this->setIcon(QIcon(QLatin1String(":mobata/images/msc/timeout.png")));
  this->setText(this->toString());
}

MscTimeoutItem::~MscTimeoutItem()
{
  delete this->_d;
}

MscTimerItem const* MscTimeoutItem::timer() const
{
  return this->_d->_timer;
}

void MscTimeoutItem::setTimer(MscTimerItem const* timer)
{
  this->_d->_timer=timer;

  this->setText(this->toString());

  return;
}

QString MscTimeoutItem::toString() const
{
  QString timeoutString=QStringLiteral("timeout: ");
  if(this->_d->_timer)
    timeoutString+=QStringLiteral("of timer '")
                   +this->_d->_timer->name()
                   +QStringLiteral("'");

  return timeoutString;
}

} // namespace msc
} // namespace model

