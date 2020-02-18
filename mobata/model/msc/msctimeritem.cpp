#include "msctimeritem.hpp"

#include "../../memory_leak_start.hpp"

namespace model{
namespace msc{

class MscTimerItem::Private
{
  friend class MscTimerItem;

  Private(int value)
    : _value(value)
  {}

  double  _value;
};

MscTimerItem::MscTimerItem(const MscComponentItem* component,
                           const QString& name,
                           double value)
  :	MscStepItem(component),
    prop::NameProperty(name),
    _d(new Private(value))
{
  Q_ASSERT(component);
  this->setIcon(QIcon(QLatin1String(":mobata/images/msc/timer.png")));
  this->setText(this->toString());
}

MscTimerItem::~MscTimerItem()
{
  delete this->_d;
}

void MscTimerItem::setValue(double value)
{
  this->_d->_value=value;

  this->setText(this->toString());

  return;
}

double MscTimerItem::value() const
{
  return this->_d->_value;
}

QString MscTimerItem::toString() const
{
  return QString(this->name()
                 +QLatin1String(": after ")
                 +QString::fromLatin1("%1").arg(this->_d->_value)
                 +QLatin1String("s"));
}

}/// end namespace msc
}/// end namespace model
