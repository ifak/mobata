#include "simpleptcservice.hpp"

#include "simpleptccomponent.hpp"

#include <mobata/memory_leak_start.hpp>

SimplePtcService::SimplePtcService(QObject *parent)
  : remotecontrol::RemoteControlService(parent)
{}

SimplePtcService::~SimplePtcService()
{}

QJsonValue SimplePtcService::setup(const QString &configData,
                                   const int configSpeed)
{
  //do something with config-data
  Q_UNUSED(configData);
  Q_UNUSED(configSpeed);

  QJsonArray resultArray;
  resultArray.append(true);//result
  resultArray.append(QStringLiteral("everything is fine ... :)"));//message

  return resultArray;///will be send back
}
