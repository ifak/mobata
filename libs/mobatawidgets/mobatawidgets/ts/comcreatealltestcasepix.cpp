#include "comcreatealltestcasepix.hpp"

#include <mobata/memory_leak_start.hpp>

namespace view
{
namespace ts
{

class ComCreateAllTestCasePix::Private
{
  friend class ComCreateAllTestCasePix;

  typedef QMap<model::ts::TestCaseItem const*,
               ComCreateTestCasePix*>           TestCasePixCommands;
  typedef QMap<model::ts::TestCaseItem const*,
               QPixmap>                         TestCasePixMap;

  model::ts::TestSuite const* _testSuite;
  QNetworkAccessManager*      _networkManager;
  TestCasePixCommands         _testCasePixCommands;
  TestCasePixMap              _testCasePixs;
  QPixmap                     _nullPix;
  int                         _maxTestCases;

  Private(model::ts::TestSuite const* testSuite,
          QNetworkAccessManager* networkManager)
    :	_testSuite(testSuite),
      _networkManager(networkManager),
      _nullPix(),
      _maxTestCases(0)
  {}
};

ComCreateAllTestCasePix::ComCreateAllTestCasePix(model::ts::TestSuite const* testSuite,
                                                 QNetworkAccessManager* networkManager,
                                                 QObject *parent)
  :	QObject(parent), _d(new Private(testSuite, networkManager))
{}

ComCreateAllTestCasePix::~ComCreateAllTestCasePix()
{
  delete this->_d;
}

const QPixmap&
ComCreateAllTestCasePix::testCasePix(model::ts::TestCaseItem const* testCase)
{
  if(this->_d->_testCasePixs.find(testCase)==this->_d->_testCasePixs.end())
    return this->_d->_nullPix;

  return this->_d->_testCasePixs[testCase];
}

void ComCreateAllTestCasePix::testCasePixSlot(model::ts::TestCaseItem const* testCase,
                                              const QPixmap &testCasePix)
{
  Q_ASSERT(this->_d->_testCasePixCommands.find(testCase)!=this->_d->_testCasePixCommands.end());

  this->_d->_testCasePixCommands.remove(testCase);
  this->_d->_testCasePixs.insert(testCase, testCasePix);

  emit progress(100 - 100*this->_d->_testCasePixCommands.size()/this->_d->_maxTestCases);

  if(this->_d->_testCasePixCommands.isEmpty())
    emit finished();

  return;
}

void ComCreateAllTestCasePix::reset()
{
  this->_d->_maxTestCases=0;
  this->_d->_testCasePixCommands.clear();
  this->_d->_testCasePixs.clear();

  return;
}

model::ts::TestSuite const* ComCreateAllTestCasePix::testSuite()
{
  return this->_d->_testSuite;
}

QNetworkAccessManager* ComCreateAllTestCasePix::networkManager()
{
  return this->_d->_networkManager;
}

void ComCreateAllTestCasePix::addTcPixCommand(model::ts::TestCaseItem const* testCaseItem,
                                              ComCreateTestCasePix *tcPixCommand)
{
  Q_ASSERT(testCaseItem && tcPixCommand);

  this->_d->_testCasePixCommands.insert(testCaseItem, tcPixCommand);
  ++this->_d->_maxTestCases;

  return;
}

} // end namespace ts
} // end namespace view
