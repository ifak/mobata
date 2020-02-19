#include "propisrdl.hpp"

#include "isrdlitem.hpp"

#include "../../utils/functors.hpp"

#include "../../memory_leak_start.hpp"

namespace model {
namespace isrdl {

class PropIsrdl::Private
{
  friend class PropIsrdl;

  Private()
    : _isrdlItem(nullptr)
  {}

public:
  ~Private()
  {}

private:
  QStandardItem*  _isrdlItem;
};

PropIsrdl::PropIsrdl(QStandardItem* parentItem)
  : _d(new Private())
{
  Q_ASSERT(parentItem);
  this->setIsrdlParentItem(parentItem);
}

PropIsrdl::~PropIsrdl()
{
  delete this->_d;
}

void PropIsrdl::setIsrdlParentItem(QStandardItem* parent)
{
  Q_ASSERT(parent);

  if(this->_d->_isrdlItem)
    return;

  this->_d->_isrdlItem=new QStandardItem(QIcon(":mobata/images/isrdl/isrdlpic.png"),
                                             QLatin1String("isrdls"));
  this->_d->_isrdlItem->setFlags(this->_d->_isrdlItem->flags() & ~Qt::ItemIsEditable);
  parent->appendRow(this->_d->_isrdlItem);

  return;
}

void PropIsrdl::resetIsrdlItems()
{
  if(this->_d->_isrdlItem)
    this->_d->_isrdlItem->removeRows(0,
                                         this->_d->_isrdlItem->rowCount());

  return;
}

bool PropIsrdl::addIsrdlItem(IsrdlItem* isrdl,
                                QString* errorString)
{
  if(!isrdl)
    return false;

  if(this->isrdlItem(isrdl->uuid()))
  {
    utils::AddPtrString(errorString)<<QObject::tr("There is already a isrdl "
                                                  "with uuid'%1' available!")
                                      .arg(isrdl->uuid().toString());
    return false;
  }

  this->_d->_isrdlItem->appendRow(isrdl);
  isrdl->setText(isrdl->name());

  return true;
}

IsrdlItem* PropIsrdl::addIsrdlItem(const QString& name)
{
  IsrdlItem* newIsrdl=new IsrdlItem(name);
  this->_d->_isrdlItem->appendRow(newIsrdl);
  newIsrdl->setText(newIsrdl->name());

  return newIsrdl;
}

void PropIsrdl::removeIsrdlItem(IsrdlItem* isrdl)
{
  if(!isrdl)
    return;
  Q_ASSERT(this->_d->_isrdlItem->model()==isrdl->model());

  this->_d->_isrdlItem->removeRow(isrdl->row());

  return;
}

void PropIsrdl::removeIsrdlItem(const QUuid& isrdlUuid)
{
  IsrdlItem* isrdl=this->isrdlItem(isrdlUuid);
  if(!isrdl)
    return;

  this->_d->_isrdlItem->removeRow(isrdl->row());

  return;
}

IsrdlItem* PropIsrdl::isrdlItem(const QUuid& isrdlUuid) const
{
  foreach(IsrdlItem* isrdlItem, this->isrdlItems())
    if(isrdlItem->uuid()==isrdlUuid)
      return isrdlItem;

  return 0;
}

PropIsrdl::IsrdlSet PropIsrdl::isrdlItems() const
{
  IsrdlSet isrdlSet;
  if(!this->_d->_isrdlItem)
    return isrdlSet;

  int end=this->_d->_isrdlItem->rowCount();
  for(int i=0; i<end; ++i)
  {
    QStandardItem* currChildItem=this->_d->_isrdlItem->child(i);
    IsrdlItem* isrdl=utils::simple_cast<IsrdlItem*>(currChildItem);
    Q_ASSERT(isrdl);
    isrdlSet.append(isrdl);
  }

  return isrdlSet;
}

} // namespace isrdl
} // namespace model
