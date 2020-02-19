#include "diagsignalitem.hpp"
#include "../base/paramitem.hpp"
#include "../../memory_leak_start.hpp"
namespace model{
namespace diagnosis{

class DiagSignalItem::Private
{
    friend class DiagSignalItem;
    const QString _necguard;
    const QString _suffguard;
    DiagSignalItem* _baseSignal = 0;
    QHash<QString,QString> _nameMap;
    Private(const QString &necguard,const QString &suffguard):
        _necguard(necguard),_suffguard(suffguard)
    {}
};

DiagSignalItem::DiagSignalItem(const QString &name, const QString necguard, const QString suffguard, const QUuid &uuid)
    :SignalItem(name,uuid),_d(new Private(necguard,suffguard))
{
    setText(this->toString());
}

void DiagSignalItem::setBaseSignal(DiagSignalItem *baseSignal)
{
    _d->_baseSignal = baseSignal;
    setText(this->toString());
}

DiagSignalItem *DiagSignalItem::BaseSignal()
{
    return _d->_baseSignal;
}

QString DiagSignalItem::condition()
{
    QString res = (QString)_d->_necguard;
    if(_d->_baseSignal){
        for(auto key : _d->_baseSignal->aliases().keys()){
            if(res.contains(key)){
                res.replace(key,_d->_baseSignal->aliases().value(key));
            }
        }
    }
    return res;
}

QString DiagSignalItem::check()
{
    QString res = (QString)_d->_suffguard;
    if(_d->_baseSignal){
        for(auto key : _d->_baseSignal->aliases().keys()){
            if(res.contains(key)){
                res.replace(key,_d->_baseSignal->aliases().value(key));
            }
        }
    }
    return res;
}

void DiagSignalItem::addAlias(QString original, QString alias)
{
    _d->_nameMap.insert(alias,original);
}

QHash<QString, QString> DiagSignalItem::aliases()
{
    return _d->_nameMap;
}

DiagSignalItem::~DiagSignalItem()
{
    delete(_d);
}

QString DiagSignalItem::toString() const
{
    if(_d->_baseSignal){
        return _d->_baseSignal->name() + QStringLiteral("(") + _d->_necguard + QStringLiteral(")");
    }
    return QStringLiteral("");
}

}/// end namespace diagnosislanguage
}/// end namespace model
