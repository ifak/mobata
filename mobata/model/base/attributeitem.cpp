#include "attributeitem.hpp"

#include "basemodel.hpp"
#include "datatypeitem.hpp"

#include "../../memory_leak_start.hpp"

namespace model{
namespace base{

class AttributeItem::Private
{
  friend class AttributeItem;

public:
  Private(const QString& initValue)
    : _initValue(initValue)
  {}

  ~Private()
  {}

private:
  QString	_initValue;
};

AttributeItem::AttributeItem(const QString& name,
                             const QString& dataType,
                             const QString& initValue,
                             const QUuid& uuid)
  : ParamItem(name, dataType, uuid), _d(new Private(initValue))
{}

AttributeItem::~AttributeItem()
{}

const QString& AttributeItem::initValue() const
{
  return this->_d->_initValue;
}

void AttributeItem::setInitValue(const QString &initValue)
{
  this->_d->_initValue=initValue;

  return;
}

QString AttributeItem::toString() const
{
  QString typeName=QStringLiteral("!unknown type!");
  if(this->dataType().size())
    typeName=this->dataType();

  QString declString=typeName+QStringLiteral(" ");
  declString+=this->name();
  if(!this->_d->_initValue.isEmpty())
    declString+=QStringLiteral("=")+this->_d->_initValue;

  return declString;
}

}///end namespace base
}///end namespace model
