#include "functionitem.hpp"

#include "datatypeitem.hpp"
#include "paramitem.hpp"
#include "basemodel.hpp"

#include "../../utils/functors.hpp"

#include "../../memory_leak_start.hpp"

using namespace utils;

namespace model{
namespace base{

class FunctionItem::Private
{
  friend class FunctionItem;

public:
  Private(const QString& returnType,
          const QString& statementBody)
    : _returnType(returnType),
      _statementBody(statementBody)
  {}

  ~Private()
  {}

private:
  QString _returnType;
  QString	_statementBody;
};

FunctionItem::FunctionItem(const QString& name,
                           const QString& returnType,
                           const QString& statementBody,
                           const QUuid &uuid)
  : ModelItem(uuid),
    PropParams(this),
    PropAttributes(this),
    prop::NameProperty(name),
    _d(new Private(returnType, statementBody))
{
  this->setIcon(QIcon(QLatin1String(":mobata/images/base/function.png")));
  this->setText(this->name());
}

FunctionItem::~FunctionItem()
{
  delete this->_d;
}

QString FunctionItem::declarationToString() const
{
  QString declaration = this->returnType();

  declaration += this->name();
  declaration += QStringLiteral("(");

  ///parameters////////////////////////
  int pos=0;
  for(ParamItem const* param : this->params())
  {
    if(pos)
      declaration+=QStringLiteral(",");

    const QString paramType = param->dataType();
    if(!paramType.isEmpty())
      declaration+=paramType;
    else
      declaration+=QStringLiteral("unknown_type");

    declaration+=QStringLiteral(" ")+param->name();

    ++pos;
  }

  declaration+=QStringLiteral(")");

  return declaration;
}

QString FunctionItem::toString() const
{
  QString definition = this->declarationToString();

  definition += QStringLiteral("\n{");
  definition += this->statementBody();
  definition += QStringLiteral("\n}");

  return definition;
}

QString FunctionItem::returnType() const
{
  return this->_d->_returnType;
}

void FunctionItem::setReturnType(const QString& returnType)
{
  this->_d->_returnType = returnType;
}

const	QString& FunctionItem::statementBody() const
{
  return this->_d->_statementBody;
}
void FunctionItem::setStatementBody(const QString& statementBody)
{
  this->_d->_statementBody = statementBody;
}

FunctionItem* FunctionItem::clone() const
{
  FunctionItem* cloneFunctionItem = new FunctionItem(this->name());
  this->cloneParams(cloneFunctionItem);
  cloneFunctionItem->setReturnType(this->returnType());
  cloneFunctionItem->setStatementBody(this->statementBody());

  return cloneFunctionItem;
}

}///end namespace base
}///end namespace model
