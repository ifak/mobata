#include "diagcomponentitem.hpp"
#include "../base/paramitem.hpp"
#include "../../memory_leak_start.hpp"
namespace model{
namespace diagnosis{

class DiagComponentItem::Private
{
  friend class DiagComponentItem;
  const QString _necguard;
  const QString _suffguard;
  DiagComponentItem* _baseComponent = 0;
  QHash<QString,QString> _nameMap;

  Private(const QString &necguard,const QString &suffguard):
    _necguard(necguard),_suffguard(suffguard)
  {}
};

DiagComponentItem::DiagComponentItem(const QString &name, const QString necguard, const QString suffguard)
  :msc::MscComponentItem(name),_d(new Private(necguard,suffguard))
{
  setText(this->toString());
}

DiagComponentItem::~DiagComponentItem()
{
  delete this->_d;
}

void DiagComponentItem::setBaseComponent(DiagComponentItem *baseComponent)
{
  _d->_baseComponent = baseComponent;
  setText(this->toString());
}

DiagComponentItem *DiagComponentItem::baseComponent()
{
  return _d->_baseComponent;
}

QString DiagComponentItem::check()
{
  QString res = (QString)_d->_suffguard;
  if(_d->_baseComponent){
    for(auto key : _d->_baseComponent->aliases().keys()){
      if(res.contains(key)){
        res.replace(key,_d->_baseComponent->aliases().value(key));
      }
    }
  }
  return res;
}

QString DiagComponentItem::condition()
{
  QString res = (QString)_d->_necguard;
  if(_d->_baseComponent){
    for(auto key : _d->_baseComponent->aliases().keys()){
      if(res.contains(key)){
        res.replace(key,_d->_baseComponent->aliases().value(key));
      }
    }
  }
  return res;
}

void DiagComponentItem::addAlias(const QString& original,
                                 const QString& alias)
{
  _d->_nameMap.insert(alias,original);
}

const QHash<QString, QString>& DiagComponentItem::aliases()
{
  return _d->_nameMap;
}

QString DiagComponentItem::toString() const
{
  QString res = this->name() + QStringLiteral(": ");
  if(_d->_baseComponent){
    res += _d->_baseComponent->name()
           + QStringLiteral("(")
           + _d->_baseComponent->condition()
           + (_d->_baseComponent->check()==QString("") ? (QString("+") + _d->_baseComponent->check())
                                                       :QString("")) + QStringLiteral(")");
  }
  else res +=_d->_necguard + _d->_suffguard==QString("") ? (QString("+") + _d->_suffguard):QString("");
  return res;
}

}/// end namespace diagnosislanguage
}/// end namespace model
