#pragma once

#include <QObject>
#include <QSet>
#include <QVariantMap>
#include <QUuid>

class SimRuntimeControllerSutAdapter : public QObject
{
  Q_OBJECT

public:
  explicit SimRuntimeControllerSutAdapter(QObject *parent = nullptr);

signals:
  void messageReceived(const QString& messageName,
                       const QString& portName,
                       const QVariantMap& paramValues = QVariantMap());
  void errors(const QStringList& errorMessages);
  void messageSent(const QUuid &messageID,
                   bool result,
                   const QString& errorMessage=QStringLiteral(""));

  //to controller
  void prepareController();
  void startController();
  void stopController();
  void sendMessage(const QString& modelAsName,
                   const QString& messageName,
                   const QString& portName,
                   const QVariantMap& paramValues = QVariantMap());

public slots:
  void controllerPreparedSlot(bool result, const QStringList& messages = QStringList());
  void controllerStartedSlot(bool result, const QStringList& messages = QStringList());
  void controllerStoppedSlot(bool result, const QStringList& messages = QStringList());
  void receiveRuntimeMessageSlot(const QString& modelAsName,
                                 const QString& portName,
                                 const QString& messageName,
                                 const QVariantMap& paramValues = QVariantMap());
  void observedRuntimeMessageSlot(const QString& sourceModelAsName,
                                  const QString& sourcePortName,
                                  const QString& targetModelAsName,
                                  const QString& targetPortName,
                                  const QString& messageName,
                                  const QVariantMap& paramValues = QVariantMap());

  void sendMessageSlot(const QString& messageName,
                       const QString& portName,
                       const QVariantMap& paramValues,
                       const QUuid& messageID);
private:
  QSet<QUuid> _openMessages;
};
