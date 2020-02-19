#include "propdatatypes.hpp"

#include "datatypeitem.hpp"
#include "../../utils/functors.hpp"

#include "../../memory_leak_start.hpp"

using namespace utils;

namespace model {
namespace base {

class PropDataTypes::Private
{
  friend class PropDataTypes;

  Private()
    : _dataTypesItem(nullptr)
  {}

public:
  ~Private()
  {}

private:
  QStandardItem*  _dataTypesItem;
};

PropDataTypes::PropDataTypes(QStandardItem* parentItem)
  : _d(new Private())
{
  Q_ASSERT(parentItem);
  this->setDataTypesParentItem(parentItem);
}

PropDataTypes::~PropDataTypes()
{
  delete this->_d;
}

void PropDataTypes::resetDataTypes()
{
  if(this->_d->_dataTypesItem)
    this->_d->_dataTypesItem->removeRows(0, this->_d->_dataTypesItem->rowCount());

  return;
}

void PropDataTypes::initStandardDataTypes()
{
  this->addDataType("int");
  this->addDataType("real");
  this->addDataType("bool");
  this->addDataType("string");

  return;
}

void PropDataTypes::setDataTypesParentItem(QStandardItem* typesParentItem)
{
  Q_ASSERT(typesParentItem);

  if(this->_d->_dataTypesItem)
    return;

  this->_d->_dataTypesItem=new QStandardItem(QIcon(QLatin1String(":mobata/images/base/manytype.png")),
                                             QLatin1String("types"));
  this->_d->_dataTypesItem->setFlags(this->_d->_dataTypesItem->flags() & ~Qt::ItemIsEditable);

  typesParentItem->appendRow(this->_d->_dataTypesItem);

  return;
}

DataTypeItem* PropDataTypes::addDataType(const QString &name,
                                         QString* errorString)
{
  Q_ASSERT(this->_d->_dataTypesItem);

  return this->addDataType(name, QUuid::createUuid(), errorString);
}

DataTypeItem* PropDataTypes::addDataType(const QString &name,
                                         const QUuid& uuid,
                                         QString* errorString)
{
  Q_ASSERT(this->_d->_dataTypesItem);

  if(name.isEmpty())
  {
    utils::AddPtrString(errorString)<<QObject::tr("no name for data type, data type is not added!!");
    return 0;
  }

  if(this->dataType(name))
  {
    utils::AddPtrString(errorString)<<QObject::tr("There is already a type '%1'!")
                                      .arg(name);
    return 0;
  }

  DataTypeItem* newTypeItem=new DataTypeItem(name, uuid);
  this->_d->_dataTypesItem->appendRow(newTypeItem);
  prop::TypeEnum typeEnum=prop::string2typeEnum(name);
  if(typeEnum!=prop::Unknown)
    newTypeItem->setTypeEnum(typeEnum);

  return newTypeItem;
}

bool PropDataTypes::addDataType(DataTypeItem* newType,
                                QString* errorString)
{
  Q_ASSERT(this->_d->_dataTypesItem);
  Q_ASSERT(newType);

  if(this->dataType(newType->name()))
  {
    utils::AddPtrString(errorString)<<QObject::tr("There is already a type '%1'!")
                                      .arg(newType->name());
    return 0;
  }

  this->_d->_dataTypesItem->appendRow(newType);

  return true;
}

void PropDataTypes::removeDataTypeByID(const QUuid& dataTypeUuid)
{
  Q_ASSERT(this->_d->_dataTypesItem);

  DataTypeItem* remDataType = this->dataTypeByID(dataTypeUuid);
  if(remDataType)
    this->_d->_dataTypesItem->removeRow(remDataType->row());

  return;
}

void PropDataTypes::removeDataType(const QString& dataTypeName)
{
  Q_ASSERT(this->_d->_dataTypesItem);

  DataTypeItem* remDataType = this->dataType(dataTypeName);
  if(remDataType)
    this->_d->_dataTypesItem->removeRow(remDataType->row());

  return;
}

DataTypeItem* PropDataTypes::dataTypeByID(const QUuid &typeUuid)
{
  return FindByUuid<DataTypeSet>()(typeUuid, this->dataTypes());
}

DataTypeItem const* PropDataTypes::dataTypeByID(const QUuid &typeUuid) const
{
  return FindByUuid<ConstDataTypeSet>()(typeUuid, this->dataTypes());
}

DataTypeItem* PropDataTypes::dataType(const QString& typeName)
{
  return FindByName<DataTypeSet>()(typeName, this->dataTypes());
}

DataTypeItem const* PropDataTypes::dataType(const QString& typeName) const
{
  return FindByName<ConstDataTypeSet>()(typeName, this->dataTypes());
}

PropDataTypes::DataTypeSet PropDataTypes::dataTypes()
{
  DataTypeSet types;
  if(!this->_d->_dataTypesItem)
    return types;

  int end=this->_d->_dataTypesItem->rowCount();
  for(int i=0; i<end; ++i)
  {
    DataTypeItem* type=simple_cast<DataTypeItem*>(this->_d->_dataTypesItem->child(i));
    types.append(type);
  }

  return types;
}

PropDataTypes::ConstDataTypeSet PropDataTypes::dataTypes() const
{
  ConstDataTypeSet types;
  if(!this->_d->_dataTypesItem)
    return types;

  int end=this->_d->_dataTypesItem->rowCount();
  for(int i=0; i<end; ++i)
  {
    DataTypeItem* type=simple_cast<DataTypeItem*>(this->_d->_dataTypesItem->child(i));
    types.append(type);
  }

  return types;
}

void PropDataTypes::cloneDataTypes(PropDataTypes* cloneDataTypes) const
{
  Q_ASSERT(cloneDataTypes);

  bool result = false;
  for(DataTypeItem const* dataType : this->dataTypes())
  {
    DataTypeItem* cloneDataType = new DataTypeItem(dataType->name());
    cloneDataType->setTypeProperties(*dataType);
    result = cloneDataTypes->addDataType(cloneDataType);
    Q_ASSERT(result);
  }

  return;
}

bool PropDataTypes::hasEnumValue(const QString& enumValue) const
{
  for(DataTypeItem const* dataType : this->dataTypes())
  {
    if(dataType->typeEnum()!=prop::Enum)
      continue;

    for(const QString& typeEnumValue : dataType->literals())
    {
      if(typeEnumValue==enumValue)
        return true;
    }
  }

  return false;
}

} // namespace base
} // namespace model

