#include "modelitem.hpp"

#include "basemodel.hpp"

#include "../../utils/functors.hpp"

#include <QDebug>

#include "../../memory_leak_start.hpp"

namespace model{
namespace base{

struct Property
{
  Property()
    : index(-1), item(0)
  {}

  Property(const int indexParam,
           QStandardItem* valueParam)
    : index(indexParam), item(valueParam)
  {
    Q_ASSERT(item);
  }

  const Property& operator =(const Property& rhs)
  {
    if(this!=&rhs)
    {
      this->index=rhs.index;
      this->item=rhs.item;
    }

    return *this;
  }

  int             index;
  QStandardItem*  item;
};

typedef QHash<QString, Property>	PropertyMap;

class ModelItem::Private
{
  friend class ModelItem;

public:
  Private(const QUuid& uuid)
    : _uuid(uuid)
  {}

private:
  QUuid         _uuid;
};

ModelItem::ModelItem(const QUuid &uuid)
  : _d(new Private(uuid))
{
  ///insert this as declaration-property
  this->setData(QLatin1String(""), Qt::DisplayRole);
  this->setFlags(this->flags()  & ~Qt::ItemIsEditable);

  this->setText(this->toString());
}

ModelItem::~ModelItem()
{
  delete this->_d;
}

const QUuid& ModelItem::uuid() const
{
  return this->_d->_uuid;
}

void ModelItem::setUuid(const QUuid uuid)
{
  this->_d->_uuid=uuid;

  return;
}

QString ModelItem::toString() const
{
  return QStringLiteral("");
}

BaseModel const* ModelItem::getModel() const
{
  return utils::simple_cast<BaseModel const*>(this->model());
}

}///end namespace base
}///end namespace model
