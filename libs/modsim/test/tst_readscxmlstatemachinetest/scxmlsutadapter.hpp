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
