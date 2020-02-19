#include "mscsleeptimeritem.hpp"

#include "../../memory_leak_start.hpp"

namespace model{
namespace msc{

class MscSleepTimerItem::Private
{
  friend class MscSleepTimerItem;

  Private(int value)
    : _value(value)

  {}

  double  _value;
};

MscSleepTimerItem::MscSleepTimerItem(const MscComponentItem* component,
                                     double value)
  :	MscStepItem(component), _d(new Private(value))
{
  Q_ASSERT(component);

  this->setIcon(QIcon(QLatin1String(":mobata/images/msc/sleeptimer.png")));
  this->setText(this->toString());
}

MscSleepTimerItem::~MscSleepTimerItem()
{
  delete this->_d;
}

void MscSleepTimerItem::setValue(double value)
{
  this->_d->_value=value;

  this->setText(this->toString());

  return;
}

double MscSleepTimerItem::value() const
{
  return this->_d->_value;
}

QString MscSleepTimerItem::toString() const
{
  return QString(QLatin1String("sleeping for ")
                 +QString::fromLatin1("%1").arg(this->_d->_value)
                 +QLatin1String("s"));
}

} // namespace msc
} // namespace model

