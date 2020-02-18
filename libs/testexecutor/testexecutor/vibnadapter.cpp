#include "vibnadapter.hpp"

namespace testexecutor {
VibnAdapter::VibnAdapter()
{

}

bool VibnAdapter::isInit()
{
  return false;
}

void VibnAdapter::sendSignal(const QString& Signalname, const QList<QVariant>& values)
{
  Q_UNUSED(Signalname);
  Q_UNUSED(values);
}

void VibnAdapter::sendReadValue(const QString& signalName, const QVariant& expectedValue, int timeout, int pollingrate, double accuracy)
{
  Q_UNUSED(signalName);
  Q_UNUSED(expectedValue);
  Q_UNUSED(timeout);
  Q_UNUSED(pollingrate);
  Q_UNUSED(accuracy);
}

}
