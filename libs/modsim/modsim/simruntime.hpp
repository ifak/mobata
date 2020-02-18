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
#include "simmodel.hpp"

class QScxmlEvent;

namespace modsim {
class SimRuntimePort;

class SimRuntime : public QObject
{
  Q_OBJECT

public:
  typedef QVector<SimRuntimePort*>  SimRuntimePorts;

public:
  explicit SimRuntime(SimModel const* simModel,
                      QObject *parent = nullptr);
  virtual ~SimRuntime();

public:
  const QString&          simModelAsName() const;
  SimModel const*         simModel() const;
  SimRuntimePort const*   simRuntimePort(const QString& portName) const;
  SimRuntimePort const*   simRuntimePort(const quint32 portId) const;
  const SimRuntimePorts&  simRuntimePorts() const;

signals:
  void error(const QStringList& errorMessages);

public:
  virtual bool prepare(QString* errorString) =0;
  virtual bool start(QString* errorString) =0;
  virtual bool stop(QString* errorString) =0;

protected slots:
  virtual void receiveMessage(const QString& messageName,
                              const QVariantMap& messageData) =0;
  virtual void sendMessage(const QScxmlEvent& scxmlEvent) =0;

protected:
  virtual QString runtimeDeclString() const =0;//especially for error messages

protected:
  SimModel const* _simModel;
  SimRuntimePorts _simRuntimePorts;
};

class SimScxmlRuntime : public SimRuntime
{
  Q_OBJECT

public:
  SimScxmlRuntime(SimStateMachineModel const* simStateMachineModel,
                  QObject* parent = nullptr);
  virtual ~SimScxmlRuntime();

private:
  SimStateMachineModel const* simStateMachineModel() const;

public:
  bool prepare(QString* errorString) override;
  bool start(QString* errorString) override;
  bool stop(QString* errorString) override;

protected slots:
  void receiveMessage(const QString& messageName,
                      const QVariantMap& messageData) override;
  void sendMessage(const QScxmlEvent& scxmlEvent) override;

protected:
  QString runtimeDeclString() const override;//especially for error messages

private:
  Q_DISABLE_COPY(SimScxmlRuntime)
  class Private;
  Private* _d;
};

} // namespace modsim
