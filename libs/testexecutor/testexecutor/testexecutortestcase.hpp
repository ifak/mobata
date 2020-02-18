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

#include "mobata/model/ts/testcaseitem.hpp"

namespace testexecutor {

class TESTEXECUTORSHARED_EXPORT TestexecutorTestCase : public model::ts::TestCaseItem
{
public:
  TestexecutorTestCase(QString tcname);
  enum Result{
    FAIL,
    SUCCESS,
    EXCLUDE,
    NOT_EXECUTED
  };

  void clearResult();

  void setResult(Result result);
  void setErrorMessage(const QString& error);

  Result testResult();
  QString testResultToString();
  QString testResultToString(const Result& result);
  QString errorMessage() const;

  void setFilePath(const QString& path);
  QString filePath();

private:
  Result _result = NOT_EXECUTED;
  QString _errorMessage;
  QString _filePath;

};

}
