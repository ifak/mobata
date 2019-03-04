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

#include <mobata/prop/nameproperty.hpp>
#include <mobata/prop/idproperty.hpp>
#include <QObject>

namespace modsim {

class SimRuntime;

class MODSIMSHARED_EXPORT SimRuntimePort
    : public QObject,
    public prop::NameProperty,
    public prop::IdProperty
{
  Q_OBJECT

public:
  SimRuntimePort(SimRuntime const* simRuntime,
                 const QString& name,
                 const quint32 id,
                 QObject* parent = nullptr);
  virtual ~SimRuntimePort();

public:
  SimRuntime const* simRuntime() const;

signals:
  void receiveMessage(const QString& signalName, const QVariantMap& params);
  void sendMessage(const QString& signalName, const QVariantMap& params);

private:
  Q_DISABLE_COPY(SimRuntimePort)
  class Private;
  Private* _d;
};

} // namespace modsim
