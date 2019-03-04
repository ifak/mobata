#pragma once

#include <QObject>

class QScxmlStateMachine;
class QScxmlEvent;

namespace model{namespace statemachine{
class StateMachineModel;
}}

class ScxmlSutAdapter
    : public QObject
{
  Q_OBJECT
public:
  ScxmlSutAdapter(QScxmlStateMachine* machine,
                  model::statemachine::StateMachineModel* model,
                  QObject* parent = nullptr);
  virtual ~ScxmlSutAdapter();
  void connectToEvent(QString eventName);
public slots:
  void start();
  void messageToScxml(const QString &messageName,
                      const QString& portName,
                      const QVariantMap& paramValues,
                      const QUuid &messageID);

protected slots:
  void messageFromScxml(const QScxmlEvent &event);

signals:
  void messageReceived(const QString& messageName,
                       const QString& portName,
                       const QVariantMap& paramValues);
  void submitScxmlEvent(const QString &messageName, const QVariantMap &paramMap);
  void messageSent(const QUuid &messageID,
                   bool result,
                   const QString& errorMessage=QStringLiteral(""));
  void errors(const QStringList& errorMessages);

private:
  Q_DISABLE_COPY(ScxmlSutAdapter)
  class Private;
  Private* _d;
};
