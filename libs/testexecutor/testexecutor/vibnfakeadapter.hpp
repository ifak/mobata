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

#include "vibnadapter.hpp"
#include <QObject>
#include <QPair>
#include <QVariant>

namespace testexecutor {

class VibnFakeAdapter : public VibnAdapter
{
  Q_OBJECT
public:
  VibnFakeAdapter();
  bool isInit() override{return true;}

  void setAnswerList(QList<QPair<QString,QVariant>> list){this->_answerList = list;}

public slots:
  void sendSignal(const QString& Signalname, const QList<QVariant>& values) override;
  void sendReadValue(const QString& signalName, const QVariant& expectedValue, int timeout = 0, int pollingrate = 0, double accuracy = 0) override;

private:
  QList<QPair<QString,QVariant>> _answerList;
};

}
