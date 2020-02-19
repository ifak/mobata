#include "paramitem.hpp"

#include "datatypeitem.hpp"
#include "basemodel.hpp"

#include "../../memory_leak_start.hpp"

namespace model{
namespace base{

class ParamItem::Private
{
  friend class ParamItem;

  QString _dataType;

  explicit Private(const QString& dataType)
    :	_dataType(dataType)
  {}
};

ParamItem::ParamItem(const QString& name,
                     const QString& dataType,
                     const QUuid& uuid)
  : ModelItem(uuid),
    prop::NameProperty(name),
    _d(new Private(dataType))
{
  this->setIcon(QIcon(":/mobata/images/base/attribute.png"));
  this->setText(this->name());
}

ParamItem::~ParamItem()
{
  delete this->_d;
}

const QString& ParamItem::dataType() const
{
  return this->_d->_dataType;
}

void ParamItem::setDataType(const QString& dataType)
{
  this->_d->_dataType=dataType;

  return;
}

QString ParamItem::toString() const
{
  QString typeName=QLatin1String("!unknown type!");
  if(this->_d->_dataType.size())
    typeName=this->_d->_dataType;

  QString declString=typeName+QLatin1String(" ");
  declString+=this->name();

  return declString;
}

}///end namespace base
}///end namespace model
