#include "remotecontrolsut.hpp"

#include <mobata/memory_leak_start.hpp>

RemoteControlSut::RemoteControlSut(const QString& name,
                                   RemoteControlSutService* remoteControlSutService,
                                   QObject* parent)
  : remotecontrol::RemoteControl(name, remoteControlSutService, parent)
{}

RemoteControlSut::~RemoteControlSut()
{}
