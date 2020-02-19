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

class ControlPort : public QObject
{
  Q_OBJECT
public:
  explicit ControlPort(QObject* parent = 0)
    : QObject(parent)
  {}

signals:
  void remoteControlOpen();
  void remoteControlClose();
  void setupControl(const QVariantMap& setupArgs);
  void controlSetupped(bool value, const QString& message);
  void startControl();
  void controlStarted(bool value, const QString& message);
  void stopControl();
  void controlStopped(bool value, const QString& message);
  void resetControl();
  void controlResetted(bool value, const QString& message);

  void controlFinished(bool value, const QString& message);

  void statusRequest();
};

} // namespace remotecontrol
