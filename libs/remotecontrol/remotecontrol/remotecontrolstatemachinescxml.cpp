#include "remotecontrolstatemachinescxml.hpp"

#include "scxmlrcstatemachine.h"

#include "remoteport.hpp"
#include "controlport.hpp"

#include <qslog/QsLog.h>

#include <QTimer>
#include <QDebug>

#include <mobata/memory_leak_start.hpp>

using namespace remotecontrol;

class RemoteControlStateMachineScxml::Private
{
  friend class RemoteControlStateMachineScxml;

  RemotePort*                     _remotePort;
  ControlPort*                    _controlPort;
  ScxmlRemoteControlStateMachine  _remoteControlStateMachine;

  QTimer* _controlSetupedTimer;
  QTimer* _controlStartedTimer;
  QTimer* _controlStoppedTimer;
  QTimer* _controlResettedTimer;

  Private(RemotePort* remotePort,
          ControlPort* controlPort)
    : _remotePort(remotePort),
      _controlPort(controlPort)
  {}
};

RemoteControlStateMachineScxml::RemoteControlStateMachineScxml(const QString& name,
                                                               RemotePort* remotePort,
                                                               ControlPort* controlPort,
                                                               QObject* parent)
  : QObject(parent),
    prop::NameProperty(name),
    _d(new Private(remotePort, controlPort))
{
  Q_ASSERT(this->_d->_remotePort);
  Q_ASSERT(this->_d->_controlPort);

  this->_d->_controlSetupedTimer=new QTimer(this);
  this->_d->_controlSetupedTimer->setInterval(3000);//default value

  this->_d->_controlStartedTimer=new QTimer(this);
  this->_d->_controlStartedTimer->setInterval(3000);//default value

  this->_d->_controlStoppedTimer=new QTimer(this);
  this->_d->_controlStoppedTimer->setInterval(3000);//default value

  this->_d->_controlResettedTimer=new QTimer(this);
  this->_d->_controlResettedTimer->setInterval(3000);//default value

  this->createSetupConnections();
  this->createStartConnections();
  this->createStopConnections();
  this->createResetConnections();

  this->_d->_remoteControlStateMachine.start();
}

RemoteControlStateMachineScxml::~RemoteControlStateMachineScxml()
{
  delete this->_d;
}

void RemoteControlStateMachineScxml::createSetupConnections()
{
  connect(this->_d->_remotePort, &RemotePort::setup,
          this, [=](const QVariantMap& setupArgs)
  {
    QVariantMap data;
    data.insert(QStringLiteral("setupArgs"), setupArgs);
    qDebug()<<"event-data: "<<data;
    this->_d->_remoteControlStateMachine.submitEvent("remoteSetup", data);
  });

  connect(this->_d->_controlPort, &ControlPort::controlSetuped,
          this, [=](bool value, const QString& message)
  {
    this->_d->_controlSetupedTimer->stop();

    QVariantMap data;
    data.insert(QStringLiteral("value"), value);
    data.insert(QStringLiteral("message"), message);
    this->_d->_remoteControlStateMachine.submitEvent("controlSetuped", data);
  });

  connect(this->_d->_controlSetupedTimer, &QTimer::timeout,
          this, [=]()
  {
    this->_d->_controlSetupedTimer->stop();

    this->_d->_remoteControlStateMachine.submitEvent("controlSetupedTimeout");
  });

  this->_d->_remoteControlStateMachine.connectToEvent(QStringLiteral("setupControl"),
                                                      this, [=](const QScxmlEvent& event)
  {
    emit this->_d->_controlPort->setupControl(event.data().toMap().value(QStringLiteral("setupArgs")).toMap());
  });

  this->_d->_remoteControlStateMachine.connectToEvent(QStringLiteral("startControlSetupedTimer"),
                                                      this, [=](const QScxmlEvent& event)
  {
    Q_UNUSED(event);

    this->_d->_controlSetupedTimer->start();
  });

  this->_d->_remoteControlStateMachine.connectToEvent(QStringLiteral("setuped"),
                                                      this, [=](const QScxmlEvent& event)
  {
    QVariantMap args=event.data().toMap();
    qDebug()<<"setuped() from state machine; value: "<<args.value(QStringLiteral("value")).toBool()
           <<"errorMessage: "<<args.value(QStringLiteral("errorMessage")).toString();

    emit this->_d->_remotePort->setuped(args.value(QStringLiteral("value")).toBool(),
                                        args.value(QStringLiteral("errorMessage")).toString());
  });

  return;
}

void RemoteControlStateMachineScxml::createStartConnections()
{
  connect(this->_d->_remotePort, &RemotePort::start,
          this, [=]()
  {
    this->_d->_remoteControlStateMachine.submitEvent("remoteStart");
  });

  connect(this->_d->_controlPort, &ControlPort::controlStarted,
          this, [=](bool value, const QString& message)
  {
    this->_d->_controlStartedTimer->stop();

    QVariantMap data;
    data.insert(QStringLiteral("value"), value);
    data.insert(QStringLiteral("message"), message);
    this->_d->_remoteControlStateMachine.submitEvent("controlStarted", data);
  });

  connect(this->_d->_controlStartedTimer, &QTimer::timeout,
          [this]()
  {
    this->_d->_controlStartedTimer->stop();

    this->_d->_remoteControlStateMachine.submitEvent("controlStartedTimeout");
  });

  this->_d->_remoteControlStateMachine.connectToEvent(QStringLiteral("startControl"),
                                                      this, [=](const QScxmlEvent& event)
  {
    Q_UNUSED(event);
    emit this->_d->_controlPort->startControl();
  });

  this->_d->_remoteControlStateMachine.connectToEvent(QStringLiteral("startControlStartedTimer"),
                                                      this, [=](const QScxmlEvent& event)
  {
    Q_UNUSED(event);

    this->_d->_controlStartedTimer->start();
  });

  this->_d->_remoteControlStateMachine.connectToEvent(QStringLiteral("started"),
                                                      this, [=](const QScxmlEvent& event)
  {
    QVariantMap args=event.data().toMap();
    qDebug()<<"started() from state machine; value: "<<args.value(QStringLiteral("value")).toBool()
           <<"errorMessage: "<<args.value(QStringLiteral("errorMessage")).toString();

    emit this->_d->_remotePort->started(args.value(QStringLiteral("value")).toBool(),
                                        args.value(QStringLiteral("errorMessage")).toString());
  });

  return;
}

void RemoteControlStateMachineScxml::createStopConnections()
{
  connect(this->_d->_remotePort, &RemotePort::stop,
          this, [=]()
  {
    this->_d->_remoteControlStateMachine.submitEvent("remoteStop");
  });

  connect(this->_d->_controlPort, &ControlPort::controlStopped,
          this, [=](bool value, const QString& message)
  {
    this->_d->_controlStoppedTimer->stop();

    QVariantMap data;
    data.insert(QStringLiteral("value"), value);
    data.insert(QStringLiteral("message"), message);
    this->_d->_remoteControlStateMachine.submitEvent("controlStopped", data);
  });

  connect(this->_d->_controlStoppedTimer, &QTimer::timeout,
          [this]()
  {
    this->_d->_controlStoppedTimer->stop();

    this->_d->_remoteControlStateMachine.submitEvent("controlStoppedTimeout");
  });

  this->_d->_remoteControlStateMachine.connectToEvent(QStringLiteral("stopControl"),
                                                      this, [=](const QScxmlEvent& event)
  {
    Q_UNUSED(event);
    emit this->_d->_controlPort->stopControl();
  });

  this->_d->_remoteControlStateMachine.connectToEvent(QStringLiteral("startControlStoppedTimer"),
                                                      this, [=](const QScxmlEvent& event)
  {
    Q_UNUSED(event);

    this->_d->_controlStoppedTimer->start();
  });

  this->_d->_remoteControlStateMachine.connectToEvent(QStringLiteral("stopped"),
                                                      this, [=](const QScxmlEvent& event)
  {
    QVariantMap args=event.data().toMap();
    qDebug()<<"stopped() from state machine; value: "<<args.value(QStringLiteral("value")).toBool()
           <<"errorMessage: "<<args.value(QStringLiteral("errorMessage")).toString();

    emit this->_d->_remotePort->stopped(args.value(QStringLiteral("value")).toBool(),
                                        args.value(QStringLiteral("errorMessage")).toString());
  });

  return;
}

void RemoteControlStateMachineScxml::createResetConnections()
{
  connect(this->_d->_remotePort, &RemotePort::reset,
          this, [=]()
  {
    this->_d->_remoteControlStateMachine.submitEvent("remoteReset");
  });

  connect(this->_d->_controlPort, &ControlPort::controlResetted,
          this, [=](bool value, const QString& message)
  {
    this->_d->_controlResettedTimer->stop();

    QVariantMap data;
    data.insert(QStringLiteral("value"), value);
    data.insert(QStringLiteral("message"), message);
    this->_d->_remoteControlStateMachine.submitEvent("controlResetted", data);
  });

  connect(this->_d->_controlResettedTimer, &QTimer::timeout,
          [this]()
  {
    this->_d->_controlResettedTimer->stop();

    this->_d->_remoteControlStateMachine.submitEvent("controlResettedTimeout");
  });

  this->_d->_remoteControlStateMachine.connectToEvent(QStringLiteral("resetControl"),
                                                      this, [=](const QScxmlEvent& event)
  {
    Q_UNUSED(event);
    emit this->_d->_controlPort->resetControl();
  });

  this->_d->_remoteControlStateMachine.connectToEvent(QStringLiteral("startControlResettedTimer"),
                                                      this, [=](const QScxmlEvent& event)
  {
    Q_UNUSED(event);

    this->_d->_controlResettedTimer->start();
  });

  this->_d->_remoteControlStateMachine.connectToEvent(QStringLiteral("resetted"),
                                                      this, [=](const QScxmlEvent& event)
  {
    QVariantMap args=event.data().toMap();
    qDebug()<<"resetted() from state machine; value: "<<args.value(QStringLiteral("value")).toBool()
           <<"errorMessage: "<<args.value(QStringLiteral("errorMessage")).toString();

    emit this->_d->_remotePort->resetted(args.value(QStringLiteral("value")).toBool(),
                                         args.value(QStringLiteral("errorMessage")).toString());
  });

  return;
}

RemotePort* RemoteControlStateMachineScxml::remotePort()
{
  return this->_d->_remotePort;
}

ControlPort*  RemoteControlStateMachineScxml::controlPort()
{
  return this->_d->_controlPort;
}

QString RemoteControlStateMachineScxml::currentState()
{
  if(!this->_d->_remoteControlStateMachine.isRunning())
    return QStringLiteral("Not_Running");

  QString states;int pos=0;
  for(const QString& actState
      : this->_d->_remoteControlStateMachine.activeStateNames())
  {
    if(pos)
      states.append(",");
    states.append(actState);
    ++pos;
  }

  return states;
}

void RemoteControlStateMachineScxml::setControlSetupedTimeout(int controlSetupedTimeout)
{
  Q_ASSERT(this->_d->_controlSetupedTimer);

  this->_d->_controlSetupedTimer->setInterval(controlSetupedTimeout);

  return;
}

void RemoteControlStateMachineScxml::setControlStartedTimeout(int controlStartedTimeout)
{
  Q_ASSERT(this->_d->_controlStartedTimer);

  this->_d->_controlStartedTimer->setInterval(controlStartedTimeout);

  return;
}

void RemoteControlStateMachineScxml::setControlStoppedTimeout(int controlStoppedTimeout)
{
  Q_ASSERT(this->_d->_controlStoppedTimer);

  this->_d->_controlStoppedTimer->setInterval(controlStoppedTimeout);

  return;
}

void RemoteControlStateMachineScxml::setControlResettedTimeout(int controlResettedTimeout)
{
  Q_ASSERT(this->_d->_controlResettedTimer);

  this->_d->_controlResettedTimer->setInterval(controlResettedTimeout);

  return;
}
