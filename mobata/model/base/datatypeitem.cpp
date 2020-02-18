#include "datatypeitem.hpp"

namespace model{
namespace base{

DataTypeItem::DataTypeItem(const QString &name,
                           const QUuid &uuid)
  : ModelItem(uuid), prop::NameProperty(name)
{
  this->setIcon(QIcon(QLatin1String(":mobata/images/base/type.png")));
  this->setText(this->name());
}

DataTypeItem::~DataTypeItem()
{}

QString DataTypeItem::toString() const
{
  return this->name();
}

}///end namespace base
}///end namespace model
