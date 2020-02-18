#include "remotecontroltester.hpp"

#include <mobata/memory_leak_start.hpp>

RemoteControlTester::RemoteControlTester(const QString& name,
                                         RemoteControlTesterService* remoteControlTesterService,
                                         QObject* parent)
  : remotecontrol::RemoteControlUser(name,remoteControlTesterService,parent)
{}

RemoteControlTester::~RemoteControlTester()
{}
