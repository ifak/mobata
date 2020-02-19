#include "vibnfakeadapter.hpp"

#include <QEventLoop>
#include <QTimer>
#include <QtConcurrent>

namespace testexecutor {
VibnFakeAdapter::VibnFakeAdapter() : VibnAdapter()
{

}

void VibnFakeAdapter::sendSignal(const QString& Signalname, const QList<QVariant>& values)
{
  QEventLoop loop;
  QTimer::singleShot(100, &loop, &QEventLoop::quit);
  loop.exec();
  this->sendSignalDone(true);
  QTimer::singleShot(100, &loop, &QEventLoop::quit);
  loop.exec();
  if(!this->_answerList.isEmpty()){
    QPair<const QString&,QVariant> pair = this->_answerList.first();
    QString sigName = pair.first;
    QVariant var = pair.second;
    QList<QVariant> varList;
    if(var.toString() != "empty")
      varList<<var;
    this->_answerList.removeFirst();
    QtConcurrent::run([=](){this->signalReceived(sigName,varList);});
  }else{
    this->signalReceived(Signalname, values);
  }
}

void VibnFakeAdapter::sendReadValue(const QString& signalName, const QVariant& expectedValue, int timeout, int pollingrate, double accuracy)
{
  Q_UNUSED(timeout);
  Q_UNUSED(pollingrate);
  Q_UNUSED(accuracy);
  QEventLoop loop;
  QTimer::singleShot(100, &loop, &QEventLoop::quit);
  loop.exec();
  if(!this->_answerList.isEmpty()){
    QPair<const QString&,QVariant> pair = this->_answerList.first();
    QString sigName = pair.first;
    QVariant var = pair.second;
    QList<QVariant> varList;
    if(var.toString() != "empty")
      varList<<var;
    this->_answerList.removeFirst();
    QtConcurrent::run([=](){this->signalReceived(sigName,varList);});
  }else{
    this->signalReceived(signalName,QList<QVariant>()<<expectedValue);
  }
}

}
