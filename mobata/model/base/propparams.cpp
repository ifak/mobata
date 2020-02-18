#include "propparams.hpp"

#include "datatypeitem.hpp"
#include "paramitem.hpp"

#include "../../utils/functors.hpp"

#include "../../memory_leak_start.hpp"

using namespace utils;

namespace model {
namespace base {

class PropParams::Private
{
  friend class PropParams;

  Private()
    : _paramsItem(0)
  {}

public:
  ~Private()
  {}

private:
  QStandardItem*  _paramsItem;
};

PropParams::PropParams(QStandardItem* parentItem)
  : _d(new Private())
{
  Q_ASSERT(parentItem);
  this->setParamsParentItem(parentItem);
}

PropParams::~PropParams()
{
  delete this->_d;
}

void PropParams::resetParams()
{
  if(this->_d->_paramsItem)
    this->_d->_paramsItem->removeRows(0, this->_d->_paramsItem->rowCount());

  return;
}

void PropParams::cloneParams(PropParams* cloneParams) const
{
  Q_ASSERT(cloneParams);

  bool result = false;
  for(ParamItem const* paramItem : this->params())
  {
    ParamItem* cloneParamItem = new ParamItem(paramItem->name(),
                                              paramItem->dataType());
    result = cloneParams->addParameter(cloneParamItem);
    Q_ASSERT(result);
  }

  return;
}

void PropParams::setParamsParentItem(QStandardItem* paramsParentItem)
{
  Q_ASSERT(paramsParentItem);

  if(this->_d->_paramsItem)
    return;


  this->_d->_paramsItem=new QStandardItem(QIcon(QLatin1String(":mobata/images/base/manyparam.png")),
                                          QLatin1String("params"));
  this->_d->_paramsItem->setFlags(this->_d->_paramsItem->flags() & ~Qt::ItemIsEditable);

  paramsParentItem->appendRow(this->_d->_paramsItem);

  return;
}

ParamItem* PropParams::addParameter(const QString &name,
                                    const QString& dataType,
                                    QString* errorString)
{
  Q_ASSERT(this->_d->_paramsItem);

  if(name.isEmpty())
  {
    utils::AddPtrString(errorString)<<QObject::tr("no name for parameter, parameter is not added!!");
    return 0;
  }

  if(this->parameter(name))
  {
    utils::AddPtrString(errorString)<<QObject::tr("There is already a parameter '%1' available!")
                                      .arg(name);
    return 0;
  }

  ParamItem* newParamItem=new ParamItem(name,
                                        dataType);
  this->_d->_paramsItem->appendRow(newParamItem);
  newParamItem->setText(newParamItem->toString());

  return newParamItem;
}

bool PropParams::addParameter(ParamItem* newParam,
                              QString* errorString)
{
  Q_ASSERT(this->_d->_paramsItem);
  Q_ASSERT(newParam);

  if(this->parameter(newParam->name()))
  {
    utils::AddPtrString(errorString)<<QObject::tr("There is already a paramater '%1'!")
                                      .arg(newParam->name());
    return 0;
  }

  this->_d->_paramsItem->appendRow(newParam);
  newParam->setText(newParam->toString());

  return true;
}

PropParams::ParameterSet PropParams::params()
{
  ParameterSet params;
  if(!this->_d->_paramsItem)
    return params;

  int end=this->_d->_paramsItem->rowCount();
  for(int i=0; i<end; ++i)
  {
    ParamItem* paramItem=simple_cast<ParamItem*>(this->_d->_paramsItem->child(i));
    params.append(paramItem);
  }

  return params;
}

PropParams::ConstParameterSet PropParams::params() const
{
  ConstParameterSet params;
  if(!this->_d->_paramsItem)
    return params;

  int end=this->_d->_paramsItem->rowCount();
  for(int i=0; i<end; ++i)
  {
    ParamItem* param=simple_cast<ParamItem*>(this->_d->_paramsItem->child(i));
    params.append(param);
  }

  return params;
}

ParamItem* PropParams::parameter(const QString &name)
{
  return FindByName<ParameterSet>()(name, this->params());
}

ParamItem const* PropParams::parameter(const QString &name) const
{
  return FindByName<ConstParameterSet>()(name, this->params());
}

} // namespace base
} // namespace model
