#include "signalitem.hpp"

#include "datatypeitem.hpp"
#include "paramitem.hpp"
#include "basemodel.hpp"

#include "../../utils/functors.hpp"

#include "../../memory_leak_start.hpp"

using namespace utils;

namespace model{
namespace base{

SignalItem::SignalItem(const QString& name,
                       const QUuid &uuid)
  : ModelItem(uuid),
    PropParams(this),
    prop::NameProperty(name)
{
  this->setIcon(QIcon(QLatin1String(":mobata/images/base/signal.png")));
  this->setText(this->name());
}

SignalItem::~SignalItem()
{}

SignalItem* SignalItem::clone() const
{
  SignalItem* cloneSignalItem = new SignalItem(this->name());
  this->cloneParams(cloneSignalItem);

  return cloneSignalItem;
}

QString SignalItem::toString() const
{
  QString declaration=this->name();

  declaration+=QStringLiteral("(");

  ///parameters////////////////////////
  int pos=0;
  for(ParamItem const* param : this->params())
  {
    if(pos)
      declaration+=QStringLiteral(",");

    QString paramType=param->dataType();
    if(paramType.size())
      declaration+=paramType;
    else
      declaration+=QStringLiteral("unknown_type");

    declaration+=QStringLiteral(" ")+param->name();

    ++pos;
  }

  declaration+=QStringLiteral(")");

  return declaration;
}

}///end namespace base
}///end namespace model
