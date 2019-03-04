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

#include "modsim_global.hpp"

#include <QObject>

#include "simruntime.hpp"

namespace modsim {
class SimModel;

class MODSIMSHARED_EXPORT SimModelWorker
    : public QObject
{
  Q_OBJECT

public:
  typedef SimRuntime::SimRuntimePorts  SimRuntimePorts;

public:
  SimModelWorker(SimModel* simModel,
                 QObject* parent = nullptr);
  virtual ~SimModelWorker();

public:
  const QString&          simModelAsName() const;
  SimRuntimePort const*   simRuntimePort(const QString& portName) const;
  const SimRuntimePorts&  simRuntimePorts() const;

public slots:
  virtual void prepare();
  virtual void start();
  virtual void stop();

signals:
  void prepared(bool result, const QStringList& messages = QStringList());
  void started(bool result, const QStringList& messages = QStringList());
  void stopped(bool result, const QStringList& messages = QStringList());

private:
  Q_DISABLE_COPY(SimModelWorker)
  class Private;
  Private* _d;
};

//class MODSIMSHARED_EXPORT SimSpenatWorker
//    : public SimModelWorker
//{
//  Q_OBJECT

//public:
//  SimSpenatWorker(SimSpenatModel* simSpenatModel,
//                  QObject* parent = nullptr);
//  ~SimSpenatWorker();

//public:
//  const QString&  simModelAsName() const;

//public slots:
//  virtual void prepare() override;
//  virtual void start() override;
//  virtual void stop() override;

//private:
//  Q_DISABLE_COPY(SimSpenatWorker)
//  class Private;
//  Private* _d;
//};

//class MODSIMSHARED_EXPORT SimStateMachineWorker
//    : public SimModelWorker
//{
//  Q_OBJECT

//public:
//  SimStateMachineWorker(SimStateMachineModel* simStateMachineModel,
//                        QObject* parent = nullptr);
//  ~SimStateMachineWorker();

//public slots:
//  virtual void prepare() override;
//  virtual void start() override;
//  virtual void stop() override;

//private:
//  Q_DISABLE_COPY(SimStateMachineWorker)
//  class Private;
//  Private* _d;
//};

} // namespace modsim
