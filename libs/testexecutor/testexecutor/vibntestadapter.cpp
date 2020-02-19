#include "vibntestadapter.hpp"
#include <QVariant>
#include <QEventLoop>
#include <QDebug>
#include <QMessageBox>

namespace testexecutor {

VibnTestAdapter::VibnTestAdapter(const QString& ip, int port, const QString &modus): VibnAdapter()
{
  _ip = ip;
  _port = port;
  _modus = modus;
  _init = this->setup();
}

bool VibnTestAdapter::execute(QString *errorString)
{
  Q_UNUSED(errorString)
  QEventLoop loop;
  loop.exec();
  //should we doing something here?
  //we could "request" new value updates here regularily
  qDebug()<<"VibnTestAdapter finished";
  return true;
}

void VibnTestAdapter::sendSignal(const QString& Signalname, const QList<QVariant>& values)
{
  if(!_init){
    emit this->sendSignalDone(false);
    QMessageBox::critical(nullptr, QStringLiteral("TestAdapter connection error"), QStringLiteral("Adapter is not initialized"));
    return;
  }
 //write that value
  vibn_messages::CommandWriteValueMessage m;
  m.mbt_signal = Signalname.toStdString();
  m.remote_adapter_name = this->_modus.toStdString(); // this is for now the fixed name for the adapter, this variable is for multiple adapters later
  m.command = std::string("write"); //this is more or less redundand with the topic but in case we need to have subsections under one topic
  m.name = std::string("mbtcreator"); //senders name, in case this might be important

  //this actually does not work, as we don't know the type?
  //should we build the message using qjson?
  //  for(auto v : values)
    //m.parameter.push_back(v.value<int>());
//  QJsonValue val = QJsonValue::fromVariant(values);

  for(QVariant var : values){
    switch(var.type()){
    case QVariant::Int:
      m.parameter.push_back(var.toInt());
      break;
    case QVariant::Double:
      m.parameter.push_back(var.toDouble());
      break;
    case QVariant::Bool:
      m.parameter.push_back(var.toBool());
      break;
    case QVariant::String:
      m.parameter.push_back(var.toString().toStdString());
      break;
    default:
      break;
    }
  }

  m_send_write_handler->publish(m);

  emit this->sendSignalDone(true);

  //write that value
}

void VibnTestAdapter::sendReadValue(const QString& signalName, const QVariant& expectedValue, int timeout, int pollingrate, double accuracy)
{
  if(!_init){
    QMessageBox::critical(nullptr, QStringLiteral("TestAdapter connection error"), QStringLiteral("Adapter is not initialized"));
    return;
  }
  vibn_messages::CommandReadValueMessage m;
  m.mbt_signal = signalName.toStdString();
  switch(expectedValue.type()){
  case QVariant::Int:
    m.parameter.push_back(expectedValue.toInt());
    break;
  case QVariant::Double:
    m.parameter.push_back(expectedValue.toDouble());
    break;
  case QVariant::Bool:
    m.parameter.push_back(expectedValue.toBool());
    break;
  case QVariant::String:
    m.parameter.push_back(expectedValue.toString().toStdString());
    break;
  default:
    break;
  }
  m.parameter.push_back(timeout);
  m.parameter.push_back(pollingrate);
  m.parameter.push_back(accuracy);
  m.remote_adapter_name = this->_modus.toStdString(); // this is for now the fixed name for the adapter, this variable is for multiple adapters later
  m.command = std::string("read"); //this is more or less redundand with the topic but in case we need to have subsections under one topic
  m.name = std::string("mbtcreator"); //senders name, in case this might be important

  m_send_read_handler->publish(m);

  //write that value
}

using system_clock = std::chrono::system_clock;
bool VibnTestAdapter::setup()
{
  std::string my_send_name = "mbtcreator";
  std::string default_adapter_name = "default";
  std::string listen_prefix = "vibnadapter/+/";
  std::string send_prefix = "vibnadapter/" + my_send_name +"/";

  //Topics
  //to { all, <device_name> }
  //vibnadapter/<sender_name>/<to>/command
  //vibnadapter/<sender_name>/<to>/read
  //vibnadapter/<sender_name>/<to>/write
  //vibnadapter/<sender_name>/<to>/subscibe

  //write topics
  const std::string command_topic         = "/command";
  const std::string read_topic            = "/read";
  const std::string write_topic           = "/write";
  const std::string subscribe_topic       = "/subscribe";
  const std::string log_topic             = "/log";

  //read topics
  const std::string command_reply_topic       = "/command_reply";
  const std::string command_value_reply_topic = "/command_value_reply";
  const std::string subscribe_reply_topic     = "/subscribe_reply";


  if ( m_mc.connect(this->_ip.toStdString(), this->_port) )
  {
        m_mc.registerReceive<vibn_messages::LogMessage>(listen_prefix + my_send_name + log_topic,
                           [&](std::string const & topic,vibn_messages::LogMessage const & message,system_clock::time_point const &  /* tp */)
                           { return handle_message(topic,message); } , 0 );
        m_mc.registerReceive<vibn_messages::CommandMessage>(listen_prefix+ my_send_name + command_reply_topic,
                           [&](std::string const & topic,vibn_messages::CommandMessage const & message,system_clock::time_point const &  /* tp */)
                           { return handle_message(topic,message); } , 0);
        m_mc.registerReceive<vibn_messages::CommandReadValueMessage>(listen_prefix+ my_send_name + command_value_reply_topic,
                           [&](std::string const & topic,vibn_messages::CommandReadValueMessage const & message,system_clock::time_point const &  /* tp */)
                           { return handle_message(topic,message); } , 0 );
   //     m_mc.registerReceive<vibn_messages::CommandWriteValueMessage>(listen_prefix+ my_send_name + command_value_reply_topic,
   //                        [&](std::string const & topic,vibn_messages::CommandWriteValueMessage const & message,system_clock::time_point const &  /* tp */)
   //                        { return handle_message(topic,message); } , 0 );

       m_send_read_handler = m_mc.registerSend<vibn_messages::CommandReadValueMessage>(send_prefix + default_adapter_name + read_topic);
       m_send_write_handler = m_mc.registerSend<vibn_messages::CommandWriteValueMessage>(send_prefix + default_adapter_name + write_topic );
       m_send_command_handler = m_mc.registerSend<vibn_messages::CommandMessage>(send_prefix + default_adapter_name + command_topic);
       m_send_subscribe_handler = m_mc.registerSend<vibn_messages::CommandReadValueMessage>(send_prefix + default_adapter_name + subscribe_topic);
  }
  else
  {
    QMessageBox::critical(nullptr, QStringLiteral("TestAdapter connection error"), QStringLiteral("Adapter is not initialized"));
    return false;
  }
  _init = true;
  return true;

}
  bool VibnTestAdapter::handle_message(std::string const & /* topic */, vibn_messages::LogMessage const & /* message */ )
  {
    //ok what are we doing with those fance log messages?
    return true;
  }
  bool VibnTestAdapter::handle_message(std::string const & /* topic */, vibn_messages::CommandMessage const &  /* message */)
  {
    //this is the answer to a command we send... what is the resulting information?
    //is this useful to us?
    return true;
  }
  bool VibnTestAdapter::handle_message(std::string const & /* topic */ , vibn_messages::CommandReadValueMessage const &  message )
  {
    qDebug()<<"VibnTestAdapter"<<"handle_message";
    // void signalReceived(const QString& Signalname, const QList<QVariant>& values);
    QList<QVariant> list;
    for (auto m : message.parameter)
    {
      if ( m.is_bool() )
        list.append(QVariant( m.bool_value() ));
      if ( m.is_number() )
        list.append(QVariant( m.number_value() ));
      if ( m.is_string() )
        list.append(QVariant( m.string_value().c_str() ));
      //are we expecting more complex datatypes?
    }
    emit signalReceived(QString(message.mbt_signal.c_str()),list);

    return true;
  }
  bool VibnTestAdapter::handle_message(std::string const & /* topic */ , vibn_messages::CommandWriteValueMessage const & /* message */ )
  {
    //what do you expect when this is "failure"?
    //if it actually can be failure
    return true;
  }

}
