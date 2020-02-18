#include "propparams.hpp"
#include "propfunctions.hpp"
#include "functionitem.hpp"
#include "propparams.hpp"

#include "../../utils/functors.hpp"

#include "../../memory_leak_start.hpp"

namespace model {
namespace base {

class PropFunctions::Private
{
  friend class PropFunctions;

  Private()
    : _functionsItem(0)
  {}

public:
  ~Private()
  {}

private:
  QStandardItem*	_functionsItem;
};

PropFunctions::PropFunctions(QStandardItem* parentItem)
  : _d(new Private())
{
  Q_ASSERT(parentItem);
  this->setFunctionsParentItem(parentItem);
}

PropFunctions::~PropFunctions()
{
  delete this->_d;
}

void PropFunctions::resetFunctions()
{
  if(this->_d->_functionsItem)
    this->_d->_functionsItem->removeRows(0, this->_d->_functionsItem->rowCount());

  return;
}

void PropFunctions::setFunctionsParentItem(QStandardItem* parent)
{
  Q_ASSERT(parent);

  if(this->_d->_functionsItem)
    return;

  this->_d->_functionsItem=new QStandardItem(QIcon(":/mobata/images/base/manyfunctions.png"),
                                              QLatin1String("functions"));
  this->_d->_functionsItem->setFlags(this->_d->_functionsItem->flags() & ~Qt::ItemIsEditable);
  parent->appendRow(this->_d->_functionsItem);

  return;
}

bool PropFunctions::addFunction(FunctionItem *function,
                                QString* errorString)
{
  Q_ASSERT(this->_d->_functionsItem);

  if(!function)
    return false;

  if(this->function(function->name()))
  {
    utils::AddPtrString(errorString)<<QObject::tr((QLatin1String("There is already a function '")
                                                   +function->name().toLatin1()
                                                   +QLatin1String("' available!")).toLatin1());
    return false;
  }

  this->_d->_functionsItem->appendRow(function);

  return true;
}

FunctionItem* PropFunctions::addFunction(const QString& name,
                                         const QString& returnType,
                                         const QString& statementBody,
                                         QString* errorString)
{
  Q_ASSERT(this->_d->_functionsItem);

  if(this->function(name))
  {
    utils::AddPtrString(errorString)<<QObject::tr((QLatin1String("There is already a function with name '")
                                                   +name
                                                   +QLatin1String("' available!")).toLatin1());
    return 0;
  }

  FunctionItem* newFunctionItem=new FunctionItem(name,
                                                 returnType,
                                                 statementBody);

  this->_d->_functionsItem->appendRow(newFunctionItem);
  newFunctionItem->setText(newFunctionItem->toString());

  return newFunctionItem;
}

void PropFunctions::removeFunctionByID(const QUuid& functionUuid)
{
  Q_ASSERT(this->_d->_functionsItem);

  FunctionItem* remFunction = this->function(functionUuid);
  if(remFunction)
    this->_d->_functionsItem->removeRow(remFunction->row());

  return;
}

void PropFunctions::removeFunction(const QString& functionName)
{
  Q_ASSERT(this->_d->_functionsItem);

  FunctionItem* remFunction = this->function(functionName);
  if(remFunction)
    this->_d->_functionsItem->removeRow(remFunction->row());

  return;
}

FunctionItem* PropFunctions::function(const QString &functionName) const
{
  for(FunctionItem* functionItem : this->functions())
    if(functionItem->name().compare(functionName, Qt::CaseInsensitive)==0)
      return functionItem;

  return nullptr;
}

FunctionItem* PropFunctions::function(const QUuid& functionUuid) const
{
  for(FunctionItem* functionItem : this->functions())
    if(functionItem->uuid()==functionUuid)
      return functionItem;

  return nullptr;
}

PropFunctions::FunctionSet PropFunctions::functions() const
{
  FunctionSet functions;
  if(!this->_d->_functionsItem)
    return functions;

  int end=this->_d->_functionsItem->rowCount();
  for(int i=0; i<end; ++i)
  {
    QStandardItem* currChildItem=this->_d->_functionsItem->child(i);
    FunctionItem* function=utils::simple_cast<FunctionItem*>(currChildItem);
    Q_ASSERT(function);
    functions.append(function);
  }

  return functions;
}

void PropFunctions::cloneFunctions(PropFunctions* cloneFunctions) const
{
  Q_ASSERT(cloneFunctions);

  bool result = false;
  for(FunctionItem const* function : this->functions())
  {
    FunctionItem* cloneFunction = function->clone();
    result = cloneFunctions->addFunction(cloneFunction);
    Q_ASSERT(result);
  }

  return;
}

QString PropFunctions::functionsDeclString() const
{
  QString declString=QStringLiteral("");

  for(FunctionItem const* function : this->functions())
  {
    declString+=function->toString()
                +QStringLiteral(";");
    declString+=QStringLiteral("\n");
  }
  if(!declString.isEmpty())
    declString.remove(declString.size(),1);//last "\n"

  return declString;
}

} // namespace base
} // namespace model
