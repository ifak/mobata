#include "remotecontrolstatemachineqml.hpp"

#include "remoteport.hpp"
#include "controlport.hpp"

#include <QQmlEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include <QTimer>
#include <QMetaObject>
#include <QDebug>

#include <mobata/memory_leak_start.hpp>

inline void initMyResource() { Q_INIT_RESOURCE(remotecontrol); }


using namespace remotecontrol;

class RemoteControlStateMachineQml::Private
{
  friend class RemoteControlStateMachineQml;

  RemotePort*   _remotePort;
  ControlPort*  _controlPort;
  QQmlEngine*   _stateMachineEngine;
  QObject*      _stateMachineObject;

  QString _currentState;
  QTimer* _controlSetupedTimer;
  QTimer* _controlStartedTimer;
  QTimer* _controlStoppedTimer;
  QTimer* _controlResettedTimer;

  Private(RemotePort* remotePort,
          ControlPort* controlPort)
    : _remotePort(remotePort),
      _controlPort(controlPort),
      _stateMachineEngine(0),
      _stateMachineObject(0)
  {}
};

RemoteControlStateMachineQml::RemoteControlStateMachineQml(const QString& name,
                                                           RemotePort* remotePort,
                                                           ControlPort* controlPort,
                                                           QObject* parent)
  : QObject(parent),
    prop::NameProperty(name),
    _d(new Private(remotePort, controlPort))
{
  Q_ASSERT(this->_d->_remotePort);
  Q_ASSERT(this->_d->_controlPort);
  initMyResource();
  //queued connections between port signals and state machine signals
  bool result = connect(this->_d->_remotePort, &RemotePort::remoteControlOpen,
                        this, &RemoteControlStateMachineQml::remoteRemoteControlOpen,
                        Qt::QueuedConnection);
  Q_ASSERT(result==true);
  result = connect(this, &RemoteControlStateMachineQml::controlRemoteControlOpen,
                   this->_d->_controlPort, &ControlPort::remoteControlOpen,
                   Qt::QueuedConnection);
  Q_ASSERT(result==true);
  result = connect(this->_d->_remotePort, &RemotePort::remoteControlClose,
                   this, &RemoteControlStateMachineQml::remoteRemoteControlClose,
                   Qt::QueuedConnection);
  Q_ASSERT(result==true);
  result = connect(this, &RemoteControlStateMachineQml::controlRemoteControlClose,
                   this->_d->_controlPort, &ControlPort::remoteControlClose,
                   Qt::QueuedConnection);
  Q_ASSERT(result==true);

  this->createSetuppingConnections();
  this->createStartingConnections();
  this->createStoppingConnections();
  this->createResettingConnections();
  this->createFinishingConnections();

  this->_d->_stateMachineEngine=new QQmlEngine(this);

  //make ports accessible for qml state machine
  this->_d->_stateMachineEngine->rootContext()->setContextProperty(QStringLiteral("pRemote"),
                                                                   this->_d->_remotePort);
  this->_d->_stateMachineEngine->rootContext()->setContextProperty(QStringLiteral("pControl"),
                                                                   this->_d->_controlPort);
  this->_d->_stateMachineEngine->rootContext()->setContextProperty(QStringLiteral("intern"),
                                                                   this);
  //init state machine///
  QQmlComponent component(this->_d->_stateMachineEngine,
                          QUrl("qrc:///remotecontrol/remotecontrolstatemachine.qml"));
  this->_d->_stateMachineObject = component.create();
  if(!this->_d->_stateMachineObject
     || component.isError())
  {
    qCritical()<<"state machine error: "<<component.errorString();
  }
}

RemoteControlStateMachineQml::~RemoteControlStateMachineQml()
{
  delete this->_d->_stateMachineObject;
  delete this->_d;
}

void RemoteControlStateMachineQml::createSetuppingConnections()
{
  Q_ASSERT(this->_d->_remotePort);
  Q_ASSERT(this->_d->_controlPort);

  //queued connections between port signals and state machine signals
  connect(this->_d->_remotePort, &RemotePort::setup,
          this, &RemoteControlStateMachineQml::remoteSetup,
          Qt::QueuedConnection);
  connect(this, &RemoteControlStateMachineQml::setupedRemote,
          this->_d->_remotePort, &RemotePort::setuped,
          Qt::QueuedConnection);

  connect(this, &RemoteControlStateMachineQml::setupControl,
          this->_d->_controlPort, &ControlPort::setupControl,
          Qt::QueuedConnection);
  connect(this->_d->_controlPort, &ControlPort::controlSetupped,
          this, &RemoteControlStateMachineQml::controlSetuped,
          Qt::QueuedConnection);

  this->_d->_controlSetupedTimer=new QTimer(this);
  this->_d->_controlSetupedTimer->setSingleShot(true);
  this->_d->_controlSetupedTimer->setInterval(3000);//default value
  connect(this->_d->_controlSetupedTimer, &QTimer::timeout,
          this, [=]()
  {
    this->_d->_controlSetupedTimer->stop();

    emit this->controlSetupedTimeout();
  });

  return;
}

void RemoteControlStateMachineQml::createStartingConnections()
{
  Q_ASSERT(this->_d->_remotePort);
  Q_ASSERT(this->_d->_controlPort);

  //queued connections between port signals and state machine signals
  connect(this->_d->_remotePort, &RemotePort::start,
          this, &RemoteControlStateMachineQml::remoteStart,
          Qt::QueuedConnection);
  connect(this, &RemoteControlStateMachineQml::startedRemote,
          this->_d->_remotePort, &RemotePort::started,
          Qt::QueuedConnection);

  connect(this, &RemoteControlStateMachineQml::startControl,
          this->_d->_controlPort, &ControlPort::startControl,
          Qt::QueuedConnection);
  connect(this->_d->_controlPort, &ControlPort::controlStarted,
          this, &RemoteControlStateMachineQml::controlStarted,
          Qt::QueuedConnection);

  this->_d->_controlStartedTimer=new QTimer(this);
  this->_d->_controlStartedTimer->setSingleShot(true);
  this->_d->_controlStartedTimer->setInterval(3000);//default value
  connect(this->_d->_controlStartedTimer, &QTimer::timeout,
          this, [=]()
  {
    this->_d->_controlStartedTimer->stop();

    emit this->controlStartedTimeout();
  });

  return;
}

void RemoteControlStateMachineQml::createStoppingConnections()
{
  Q_ASSERT(this->_d->_remotePort);
  Q_ASSERT(this->_d->_controlPort);

  //queued connections between port signals and state machine signals
  connect(this->_d->_remotePort, &RemotePort::stop,
          this, &RemoteControlStateMachineQml::remoteStop,
          Qt::QueuedConnection);
  connect(this, &RemoteControlStateMachineQml::stoppedRemote,
          this->_d->_remotePort, &RemotePort::stopped,
          Qt::QueuedConnection);

  connect(this, &RemoteControlStateMachineQml::stopControl,
          this->_d->_controlPort, &ControlPort::stopControl,
          Qt::QueuedConnection);
  connect(this->_d->_controlPort, &ControlPort::controlStopped,
          this, &RemoteControlStateMachineQml::controlStopped,
          Qt::QueuedConnection);

  this->_d->_controlStoppedTimer=new QTimer(this);
  this->_d->_controlStoppedTimer->setSingleShot(true);
  this->_d->_controlStoppedTimer->setInterval(3000);//default value
  connect(this->_d->_controlStoppedTimer, &QTimer::timeout,
          this, [=]()
  {
    this->_d->_controlStoppedTimer->stop();

    emit this->controlStoppedTimeout();
  });

  return;
}

void RemoteControlStateMachineQml::createResettingConnections()
{
  Q_ASSERT(this->_d->_remotePort);
  Q_ASSERT(this->_d->_controlPort);

  //queued connections between port signals and state machine signals
  connect(this->_d->_remotePort, &RemotePort::reset,
          this, &RemoteControlStateMachineQml::remoteReset,
          Qt::QueuedConnection);
  connect(this, &RemoteControlStateMachineQml::resettedRemote,
          this->_d->_remotePort, &RemotePort::resetted,
          Qt::QueuedConnection);

  connect(this, &RemoteControlStateMachineQml::resetControl,
          this->_d->_controlPort, &ControlPort::resetControl,
          Qt::QueuedConnection);
  connect(this->_d->_controlPort, &ControlPort::controlResetted,
          this, &RemoteControlStateMachineQml::controlResetted,
          Qt::QueuedConnection);

  this->_d->_controlResettedTimer=new QTimer(this);
  this->_d->_controlResettedTimer->setSingleShot(true);
  this->_d->_controlResettedTimer->setInterval(3000);//default value
  connect(this->_d->_controlResettedTimer, &QTimer::timeout,
          this, [=]()
  {
    this->_d->_controlResettedTimer->stop();

    emit this->controlResettedTimeout();
  });

  return;
}

void RemoteControlStateMachineQml::createFinishingConnections()
{
  Q_ASSERT(this->_d->_remotePort);
  Q_ASSERT(this->_d->_controlPort);

  //queued connections between port signals and state machine signals
  connect(this->_d->_controlPort, &ControlPort::controlFinished,
          this, &RemoteControlStateMachineQml::controlFinished,
          Qt::QueuedConnection);
  connect(this, &RemoteControlStateMachineQml::finishedRemote,
          this->_d->_remotePort, &RemotePort::finished,
          Qt::QueuedConnection);

  return;
}

RemotePort* RemoteControlStateMachineQml::remotePort()
{
  return this->_d->_remotePort;
}

ControlPort*  RemoteControlStateMachineQml::controlPort()
{
  return this->_d->_controlPort;
}

const QString& RemoteControlStateMachineQml::currentState()
{
  return this->_d->_currentState;
}

void RemoteControlStateMachineQml::setCurrentState(const QString &currentState)
{
  this->_d->_currentState=currentState;

  return;
}

void RemoteControlStateMachineQml::startControlSetupedTimer()
{
  Q_ASSERT(this->_d->_controlSetupedTimer);

  this->_d->_controlSetupedTimer->start();

  return;
}

void RemoteControlStateMachineQml::startControlStartedTimer()
{
  Q_ASSERT(this->_d->_controlStartedTimer);

  this->_d->_controlStartedTimer->start();

  return;
}

void RemoteControlStateMachineQml::startControlStoppedTimer()
{
  Q_ASSERT(this->_d->_controlStoppedTimer);

  this->_d->_controlStoppedTimer->start();

  return;
}

void RemoteControlStateMachineQml::startControlResettedTimer()
{
  Q_ASSERT(this->_d->_controlResettedTimer);

  this->_d->_controlResettedTimer->start();

  return;
}

void RemoteControlStateMachineQml::setControlSetupedTimeout(int controlSetupedTimeout)
{
  Q_ASSERT(this->_d->_controlSetupedTimer);

  this->_d->_controlSetupedTimer->setInterval(controlSetupedTimeout);

  return;
}

void RemoteControlStateMachineQml::setControlStartedTimeout(int controlStartedTimeout)
{
  Q_ASSERT(this->_d->_controlStartedTimer);

  this->_d->_controlStartedTimer->setInterval(controlStartedTimeout);

  return;
}

void RemoteControlStateMachineQml::setControlStoppedTimeout(int controlStoppedTimeout)
{
  Q_ASSERT(this->_d->_controlStoppedTimer);

  this->_d->_controlStoppedTimer->setInterval(controlStoppedTimeout);

  return;
}

void RemoteControlStateMachineQml::setControlResettedTimeout(int controlResettedTimeout)
{
  Q_ASSERT(this->_d->_controlResettedTimer);

  this->_d->_controlResettedTimer->setInterval(controlResettedTimeout);

  return;
}
