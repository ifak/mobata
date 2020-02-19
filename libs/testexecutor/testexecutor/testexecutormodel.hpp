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

#include "testexecutor_global.h"

//#include "testexecutor_global.hpp"

#include <QStandardItemModel>
#include "testexecutortestcase.hpp"

#include "mobata/model/ts/testsuite.hpp"

namespace testexecutor {

class TESTEXECUTORSHARED_EXPORT TestexecutorModel
    : public QStandardItemModel
{
public:
  explicit TestexecutorModel(QObject* parent = nullptr);
  ~TestexecutorModel();

public:
  void setSutFilePath(const QString& sutFilePath);
  void setTestSystemFilePath(const QString& testSystemFilePath);

  const QString&  sutFilePath() const;
  const QString&  testSystemFilePath() const;

  void reset();

public:
  bool addTestCase(const QString& testCaseFilePath,
                   model::ts::TestCaseItem* testCase,
                   QString* errorString = nullptr);
  void removeTestCase(const QString& testCaseFilePath);

  QList<QString> testCaseFiles() const;
  model::ts::TestCaseItem *testCaseModel(const QString& testCaseFile);
  QString testCaseFile(model::ts::TestCaseItem *testCaseModel) const;

  void setTestSuite(model::ts::TestSuite* testsuite);
  model::ts::TestSuite* testSuite();

  void addPrioTC(const QString& tcPath, TestexecutorTestCase* tc);
  bool setPrio(const QString& prioFilePath, QString *errorString);

  void updateTestSuite();

public:
  int _interval_length = 100;

protected:
  Qt::DropActions supportedDropActions() const;

private slots:
  void handleItemChange(QStandardItem* item);

private:
  Q_DISABLE_COPY(TestexecutorModel)
  class Private;
  Private*  _d;
};

}
