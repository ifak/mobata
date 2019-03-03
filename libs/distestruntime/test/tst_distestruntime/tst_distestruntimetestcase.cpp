#include <QtTest>

// add necessary includes here
#include <distestruntime/distestruntime.hpp>

class DisTestRuntimeTestCase : public QObject
{
  Q_OBJECT

public:
  DisTestRuntimeTestCase();
  ~DisTestRuntimeTestCase();

private slots:
  void initTestCase();
  void cleanupTestCase();
  void prepareDisTestRuntime_1();
};

DisTestRuntimeTestCase::DisTestRuntimeTestCase()
{

}

DisTestRuntimeTestCase::~DisTestRuntimeTestCase()
{

}

void DisTestRuntimeTestCase::initTestCase()
{

}

void DisTestRuntimeTestCase::cleanupTestCase()
{

}

void DisTestRuntimeTestCase::prepareDisTestRuntime_1()
{
  return;
}

QTEST_APPLESS_MAIN(DisTestRuntimeTestCase)

#include "tst_distestruntimetestcase.moc"
