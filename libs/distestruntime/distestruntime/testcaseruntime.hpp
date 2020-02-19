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

#include "distestruntime_global.hpp"

#include <QObject>

namespace distestruntime{

class TestCompRuntime;

class DISTESTRUNTIMESHARED_EXPORT TestCaseRuntime
    : public QObject
{
  Q_OBJECT
public:
  explicit TestCaseRuntime(const QList<TestCompRuntime*>& activeTestCompRuntimes,
                           QObject *parent = 0);
  virtual ~TestCaseRuntime();

signals:
  void testCaseQuitted();

public slots:
  void start();

private slots:
  void testCompQuitted();

private:
  Q_DISABLE_COPY(TestCaseRuntime)
  class Private;
  Private* _d;
};

}// namespace distestruntime
