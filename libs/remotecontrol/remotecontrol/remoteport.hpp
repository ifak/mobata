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

namespace remotecontrol {

class RemotePort : public QObject
{
  Q_OBJECT

public:
  explicit RemotePort(QObject* parent = 0)
    : QObject(parent)
  {}

signals:
  void remoteControlOpen();
  void remoteControlClose();
  void setup(const QVariantMap& setupArgs);
  void setuped(bool value, const QString& message);
  void start();
  void started(bool value, const QString& message);
  void stop();
  void stopped(bool value, const QString& message);
  void reset(bool force = false);
  void resetted(bool value, const QString& message);
  void finished(bool value, const QString& message);

  void statusResponse(const QStringList& messages);
};

} // namespace remotecontrol
