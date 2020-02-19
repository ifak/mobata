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

#include <QList>

class QUuid;
class QStandardItem;
class QJsonObject;

namespace model{
namespace base{

class PortItem;

class PropPorts
{
public:
  typedef QList<PortItem const*>  ConstPortSet;
  typedef QList<PortItem*>        PortSet;
  
public:
  PropPorts(QStandardItem* parentItem);
  virtual ~PropPorts();
  
public:
  virtual bool      addPort(PortItem* port,
                            QString* errorString=0);
  virtual PortItem* addPort(const QString &portName,
                            QString* errorString=0);

public:
  void            removePortById(const QUuid& portUuid);
  void            removePort(const QString& portName);

public:
  PortItem*       portById(const QUuid &portUuid);
  PortItem*       port(const QString& portName);
  PortItem const* portById(const QUuid& portUuid) const;
  PortItem const* port(const QString& portName) const;
  ConstPortSet    ports() const;
  PortSet         ports();
  void            clonePorts(PropPorts* clonePorts) const;
  
protected:
  void  resetPorts();
  
private:
  Q_DISABLE_COPY(PropPorts)
  class Private;
  Private*  _d;
};

bool readPorts(QJsonObject const* json_propPortsObject,
               PropPorts* propPorts,
               QString* errorString = 0);

void writePorts(PropPorts const* propPorts,
                QJsonObject* json_propPortsObject);

} // namespace base
} // namespace model
