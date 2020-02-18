#include "simpleptccomponent.hpp"

#include "simpleptcservice.hpp"

#include <QTimer>

SimplePtcComponent::SimplePtcComponent(const QString &name,
                                       SimplePtcService* simplePtcService,
                                       QObject *parent)
  : remotecontrol::RemoteControl(name,
                                 simplePtcService,
                                 parent)
{
  Q_ASSERT(simplePtcService);

  connect(simplePtcService, &SimplePtcService::started,
          this, &SimplePtcComponent::startedSlot);
}

SimplePtcComponent::~SimplePtcComponent()
{}

void SimplePtcComponent::startedSlot()
{
  ///we do something...
  QTimer::singleShot(10000, this, SLOT(finishSlot()));

  return;
}

void SimplePtcComponent::finishSlot()
{
  /// now we are ready
  this->sendFinished(true, QStringLiteral("now we are finished!"));

  return;
}

void SimplePtcComponent::sendFinished(bool value, const QString& message)
{
  Q_ASSERT(this->remoteConnectionManager());

  this->remoteConnectionManager()->sendMessage(QStringLiteral("finished"),
                                               QVariantList()<<value<<message);

  return;
}
