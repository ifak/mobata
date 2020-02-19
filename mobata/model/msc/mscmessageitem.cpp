#include "mscmessageitem.hpp"

#include "msccomponentitem.hpp"

#include "../base/paramvalueitem.hpp"
#include "../base/paramitem.hpp"
#include "../base/signalitem.hpp"
#include "../base/portitem.hpp"

#include "../../utils/functors.hpp"

#include "../../memory_leak_start.hpp"

namespace model{
namespace msc{

class MscMessageItem::Private
{
  friend class MscMessageItem;

  Private(PortItem const* sourcePort,
          PortItem const* targetPort)
    : _signal(0),
      _sourcePort(sourcePort),
      _targetPort(targetPort)
  {}

  SignalItem const* _signal;
  PortItem const*   _sourcePort;
  PortItem const*   _targetPort;
  QUuid             _referenceUuid;
};

MscMessageItem::MscMessageItem(PortItem const* sourcePort,
                               PortItem const* targetPort,
                               const QString &text)
  : MscStepItem(utils::simple_cast<MscComponentItem const*>(sourcePort->owner())),
    _d(new Private(sourcePort, targetPort))
{
  Q_ASSERT(this->_d->_sourcePort);
  Q_ASSERT(this->_d->_targetPort);

  this->setIcon(QIcon(":mobata/images/msc/message.png"));
  this->setText(text);

}

MscMessageItem::~MscMessageItem()
{
  delete this->_d;
}

ParamValueItem* MscMessageItem::addParamValue(ParamItem const* param,
                                              const QVariant& value)
{
  for(ParamValueItem* paramValue : this->paramValues())
  {
    Q_ASSERT(paramValue->param());
    if(paramValue->param()==param)
    {
      paramValue->setValue(value);
      return paramValue;
    }
  }

  ParamValueItem* newMessageParam=new ParamValueItem(param, value);
  this->appendRow(newMessageParam);

  return newMessageParam;
}

ParamValueItem const* MscMessageItem::paramValue(const QString &paramName) const
{
  for(ParamValueItem const* paramValue : this->paramValues())
  {	Q_ASSERT(paramValue->param());
    if(paramValue->param()->name()==paramName)
      return paramValue;
  }

  return 0;
}

ParamValueItem *MscMessageItem::paramValue(const QString &paramName)
{
  foreach(ParamValueItem* paramValue, this->paramValues())
  {	Q_ASSERT(paramValue->param());
    if(paramValue->param()->name()==paramName)
      return paramValue;
  }

  return 0;
}

MscMessageItem::ConstParamValues MscMessageItem::paramValues() const
{
  ConstParamValues parameters;
  int end=this->rowCount();
  for(int i=0; i<end; ++i)
  {
    QStandardItem* currChild=this->child(i);
    ParamValueItem* param=utils::simple_cast<ParamValueItem*>(currChild);
    Q_ASSERT(param);
    parameters.append(param);
  }

  return parameters;
}

MscMessageItem::ParamValues MscMessageItem::paramValues()
{
  ParamValues parameters;
  int end=this->rowCount();
  for(int i=0; i<end; ++i)
  {
    QStandardItem* currChild=this->child(i);
    ParamValueItem* param=utils::simple_cast<ParamValueItem*>(currChild);
    Q_ASSERT(param);
    parameters.append(param);
  }

  return parameters;
}

QString MscMessageItem::toString() const
{
  return this->toString(false);
}

QString MscMessageItem::toString(bool prettyPrint) const
{
  QString messageString = QLatin1String("");
  if(this->_d->_signal)
  {
    messageString+=this->_d->_signal->name();
    messageString+=QLatin1Char('(');
    int pos=0;
    for(ParamValueItem const* param : this->paramValues())
    {
      if(pos)
      {
        messageString += QLatin1String(", ");
        if(prettyPrint)
        {
          messageString += QLatin1Char('\n');
          int emptyCharLength = this->_d->_signal->name().length() +1;
          for(int i = 0; i<emptyCharLength; ++i)
            messageString += QLatin1Char(' ');
        }
      }

      messageString += param->toString();

      ++pos;
    }
    messageString+=QLatin1Char(')');
  }else{
      messageString = this->text();
  }

  return messageString;
}

void MscMessageItem::setSignal(SignalItem const* signal)
{
  this->_d->_signal=signal;

  if(this->_d->_signal)
    this->setText(this->toString());

  return;
}

SignalItem const* MscMessageItem::signal() const
{
  return this->_d->_signal;
}

const PortItem *MscMessageItem::sourcePort() const
{
  return this->_d->_sourcePort;
}

const PortItem *MscMessageItem::targetPort() const
{
  return this->_d->_targetPort;
}

}/// end namespace msc
}/// end namespace model
