#include "signaltriggeritem.hpp"

#include "signalitem.hpp"
#include "portitem.hpp"

namespace model {
namespace base {

class SignalTriggerItem::Private
{
  friend class SignalTriggerItem;

  base::SignalItem const* _triggerSignal;
  base::PortItem const*   _port;

  Private(base::SignalItem const* triggerSignal =nullptr,
          base::PortItem const* port =nullptr)
    : _triggerSignal(triggerSignal), _port(port)
  {}
};

SignalTriggerItem::SignalTriggerItem(base::SignalItem const* triggerSignal)
  : _d(new Private(triggerSignal))
{}

SignalTriggerItem::SignalTriggerItem(base::SignalItem const* triggerSignal,
                                     base::PortItem const* port)
  : _d(new Private(triggerSignal, port))
{}

SignalTriggerItem::~SignalTriggerItem()
{
  delete this->_d;
}

QString SignalTriggerItem::declaration() const
{
  QString declaration(QStringLiteral(""));

  if(this->_d->_triggerSignal)
  {
    declaration = this->_d->_triggerSignal->name();
    if(this->_d->_port)
      declaration += QStringLiteral(" at ")
                     +this->_d->_port->name();
  }

  return declaration;
}

void SignalTriggerItem::setTriggerSignal(const base::SignalItem *triggerSignal)
{
  this->_d->_triggerSignal=triggerSignal;

  return;
}

base::SignalItem const* SignalTriggerItem::triggerSignal() const
{
  return this->_d->_triggerSignal;
}

void SignalTriggerItem::setPort(const base::PortItem *port)
{
  this->_d->_port=port;

  return;
}

base::PortItem const* SignalTriggerItem::port() const
{
  return this->_d->_port;
}

} // namespace base
} // namespace model
