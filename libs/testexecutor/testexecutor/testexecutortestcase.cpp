#include "testexecutortestcase.hpp"

namespace testexecutor {

TestexecutorTestCase::TestexecutorTestCase(QString tcname)
  :TestCaseItem(tcname)
{
}

void TestexecutorTestCase::clearResult()
{
  this->_result = NOT_EXECUTED;
  this->_errorMessage = QLatin1String("");
}

void TestexecutorTestCase::setResult(Result result)
{
  this->_result = result;
}

void TestexecutorTestCase::setErrorMessage(const QString& error)
{
  this->_errorMessage = error;
}

TestexecutorTestCase::Result TestexecutorTestCase::testResult()
{
  return this->_result;
}

QString TestexecutorTestCase::testResultToString()
{
  return this->testResultToString(this->_result);
}

QString TestexecutorTestCase::testResultToString(const Result& result)
{
  switch (result){
    case SUCCESS:
      return QStringLiteral("Succeeded");
    case FAIL:
      return QStringLiteral("Failed");
    case EXCLUDE:
      return QStringLiteral("Excluded");
    case NOT_EXECUTED:
      return QStringLiteral("NoRun");
    default:
      return QStringLiteral("Unknown result");
  }
  return QStringLiteral("Unknown result");
}

QString TestexecutorTestCase::errorMessage() const
{
  return this->_errorMessage;
}

void TestexecutorTestCase::setFilePath(const QString& path)
{
  this->_filePath = path;
}

QString TestexecutorTestCase::filePath()
{
  return this->_filePath;
}

}
