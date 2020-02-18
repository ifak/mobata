#include "testadapter.hpp"

#include <QVariantMap>

#include <mobata/memory_leak_start.hpp>

TestAdapter::TestAdapter(QObject *parent) : QObject(parent)
{}

void TestAdapter::setupedSlot(bool value, const QStringList& messages)
{
  QVariantMap args;
  args.insert(QStringLiteral("value"), value);
  args.insert(QStringLiteral("messages"), messages);
  emit messageReceived("setuped", args);

  return;
}

void TestAdapter::startedSlot(bool value, const QStringList& messages)
{
  QVariantMap args;
  args.insert(QStringLiteral("value"), value);
  args.insert(QStringLiteral("messages"), messages);
  emit messageReceived("started", args);

  return;
}

void TestAdapter::stoppedSlot(bool value, const QStringList& messages)
{
  QVariantMap args;
  args.insert(QStringLiteral("value"), value);
  args.insert(QStringLiteral("messages"), messages);
  emit messageReceived("stopped", args);

  return;
}

void TestAdapter::resettedSlot(bool value, const QStringList& messages)
{
  QVariantMap args;
  args.insert(QStringLiteral("value"), value);
  args.insert(QStringLiteral("messages"), messages);
  emit messageReceived("resetted", args);

  return;
}

void TestAdapter::statusSlot(const QString& state, const QStringList& messages)
{
  QVariantMap args;
  args.insert(QStringLiteral("state"), state);
  args.insert(QStringLiteral("messages"), messages);
  emit messageReceived("status", args);

  return;
}
