#include "paramvalueitem.hpp"

#include "paramitem.hpp"
#include "datatypeitem.hpp"

#include "../../memory_leak_start.hpp"

namespace model {
namespace base {

class ParamValueItem::Private
{
  friend class ParamValueItem;

  Private(ParamItem const* param)
  : _param(param)
  { }

  ParamItem const* _param;
};

ParamValueItem::ParamValueItem(ParamItem const* param,
                               const QVariant& value)
  : _d(new Private(param))
{
  Q_ASSERT(param);

  this->setData(value);
  this->setText(this->toString());
}

ParamValueItem::~ParamValueItem()
{
  delete this->_d;
}

void  ParamValueItem::setParam(ParamItem const* param)
{
  this->_d->_param=param;
  this->setText(this->toString());

  return;
}

ParamItem const*  ParamValueItem::param() const
{
  return this->_d->_param;
}

void  ParamValueItem::setValue(const QVariant& value)
{
  this->setData(value);
  this->setText(this->toString());

  return;
}

QVariant ParamValueItem::value() const
{
  return this->data();
}


QString ParamValueItem::toString() const
{
  QString paramValueString="";
  if(this->_d->_param)
    paramValueString+=this->_d->_param->name();

  paramValueString+="="+this->data().toString();

  return paramValueString;
}

} // namespace base
} // namespace model
