/*
 * This file is part of mobata.
 *
 * mobata is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * mobata is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License
 * along with mobata.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

#include "testexecutor_global.h"

#include "vibnadapter.hpp"

#include "vibn_plugin.hpp"

namespace testexecutor {

class TESTEXECUTORSHARED_EXPORT VibnTestAdapter : public VibnAdapter
{
  Q_OBJECT
public:
  VibnTestAdapter(const QString& ip = "127.0.0.1", int port = 1883, const QString& modus = "opcua");
  bool execute(QString* errorString);
  bool isInit() override{return this->_init;}

public slots:
  void sendSignal(const QString& Signalname, const QList<QVariant>& values) override;
  void sendReadValue(const QString& signalName, const QVariant& expectedValue, int timeout = 0, int pollingrate = 0, double accuracy = 0) override;

private:
  QString _mappingFile;
  bool _init = false;

  QString _ip;
  int _port;
  QString _modus;

  vibn_plugin::VIBNMosquittoClient m_mc;
  mosquitto_client::SendMessageHandler<vibn_messages::CommandReadValueMessage>* m_send_read_handler;
  mosquitto_client::SendMessageHandler<vibn_messages::CommandWriteValueMessage>* m_send_write_handler;
  mosquitto_client::SendMessageHandler<vibn_messages::CommandReadValueMessage>* m_send_subscribe_handler;
  mosquitto_client::SendMessageHandler<vibn_messages::CommandMessage>* m_send_command_handler;

  bool setup();


  bool handle_message(std::string const & topic, vibn_messages::LogMessage const &  message);
  bool handle_message(std::string const & topic, vibn_messages::CommandMessage const &  message);
  bool handle_message(std::string const & topic, vibn_messages::CommandReadValueMessage const &  message);
  bool handle_message(std::string const & topic, vibn_messages::CommandWriteValueMessage const &  message);
};
}
