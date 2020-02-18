#include "msccheckmessageitem.hpp"
#include <mobata/model/msc/msctimeoutitem.hpp>
#include <QDebug>

#include "../../memory_leak_start.hpp"

namespace model {
namespace msc {

class MscCheckMessageItem::Private
{
  friend class MscCheckMessageItem;

  QString _guard;
  int     _timeout;
  double  _accuracy;
  QHash<QString,QString> _assign;

  Private(const QString& guard,
          const int timeout,
          const double accuracy)
    : _guard(guard),
      _timeout(timeout),
      _accuracy(accuracy)
  {}
};

MscCheckMessageItem::MscCheckMessageItem(const PortItem* sourcePort,
                                         const PortItem* targetPort,
                                         const QString& guard,
                                         const int timeout,
                                         const double accuracy)
  : MscMessageItem(sourcePort, targetPort),
    _d(new Private(guard, timeout, accuracy))
{
  this->setText(this->toString());
}

MscCheckMessageItem::~MscCheckMessageItem()
{  
  delete this->_d;
}

const QString& MscCheckMessageItem::guard() const
{
  return this->_d->_guard;
}

void MscCheckMessageItem::setGuard(const QString &guard)
{
  this->_d->_guard=guard;

  return;
}

int MscCheckMessageItem::timeout() const
{
  return this->_d->_timeout;
}

void MscCheckMessageItem::setTimeout(const int timeOut)
{
  this->_d->_timeout = timeOut;

  return;
}

double MscCheckMessageItem::accuracy() const
{
  return _d->_accuracy;
}

void MscCheckMessageItem::setAccuracy(const double accuracy)
{
  this->_d->_accuracy = accuracy;

  return;
}

QHash<QString, QString> MscCheckMessageItem::assign() const
{
  return this->_d->_assign;
}

void MscCheckMessageItem::appendAssign(QString attribute, QString signalParam)
{
  this->_d->_assign.insert(attribute, signalParam);
}

QString MscCheckMessageItem::toString() const
{
  QString messageString;
  if (MscMessageItem::toString(true) == QLatin1Char('[') + this->_d->_guard + QLatin1Char(']')){
    messageString = MscMessageItem::toString(true);
  }else{
    messageString = MscMessageItem::toString(true);
    if(!this->_d->_guard.isEmpty())
      messageString+=QLatin1Char('[')
                     + this->_d->_guard
                     +QLatin1Char(']');

    if(!this->paramValues().isEmpty()){
      messageString = messageString.replace("(", "[");
      messageString = messageString.replace(")", "]");
      messageString = messageString.replace("=", "==");
    }

    if(this->_d->_accuracy > 0)
      messageString +=QLatin1String(" +- ")
                      + QString::number(this->_d->_accuracy);

    if(this->_d->_timeout > 0)
      messageString +=QLatin1String(" during ")
                      + QString::number(this->_d->_timeout)
                      + QLatin1String(" ms");
  }
  return messageString;
}

} // namespace msc
} // namespace model

