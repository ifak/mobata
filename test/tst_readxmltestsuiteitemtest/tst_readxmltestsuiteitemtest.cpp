#include <QString>
#include <QtTest>

#include <QString>
#include <QtTest>

#include <mobata/model/ts/testsuiteitem.hpp>
#include <mobata/model/ts/sutitem.hpp>
#include <mobata/model/ts/testsystemitem.hpp>
#include <mobata/model/ts/testcaseitem.hpp>

#include <mobata/model/ts/io/comreadxmltestsuiteitem.hpp>

class ReadXmlTestSuiteItemTest
    : public QObject
{
  Q_OBJECT

public:
  ReadXmlTestSuiteItemTest();

private Q_SLOTS:
  void initTest();
  void cleanupTest();
  void readXmlTestSuiteItemTest_1();
  void readXmlTestSuiteItemTest_2();
};

ReadXmlTestSuiteItemTest::ReadXmlTestSuiteItemTest()
{}

void ReadXmlTestSuiteItemTest::initTest()
{}

void ReadXmlTestSuiteItemTest::cleanupTest()
{}

void ReadXmlTestSuiteItemTest::readXmlTestSuiteItemTest_1()
{
  using namespace model::ts;
  using namespace model::ts::io;

  TestSuiteItem testSuiteItem;
  ComReadXmlTestSuiteItem readTestSuiteItemCommand(":/testdata/tst_testsuite_1.ats",
                                                   &testSuiteItem);
  QString errorMessage;
  bool result = readTestSuiteItemCommand.execute(&errorMessage);
  if(!result)
    qDebug()<<"error within test case readXmlTestSuiteItemTest_1: "<<errorMessage;
  QVERIFY2(result, errorMessage.toLatin1());
  QVERIFY2(errorMessage.isEmpty(), errorMessage.toLatin1());

  QCOMPARE(testSuiteItem.name(), QLatin1String("tst_testsuite_1"));

  QVERIFY(testSuiteItem.sutItem());
  QCOMPARE(testSuiteItem.sutItem()->name(), QLatin1String("tst_testsuite_1_sut"));
  QCOMPARE(testSuiteItem.sutItem()->components().count(), 1);
  QCOMPARE(testSuiteItem.sutItem()->components().at(0)->name(), QLatin1String("sut_component"));
  QCOMPARE(testSuiteItem.sutItem()->components().at(0)->ports().count(), 3);
  QCOMPARE(testSuiteItem.sutItem()->components().at(0)->ports().at(0)->name(), QLatin1String("_defaultPort"));
  QCOMPARE(testSuiteItem.sutItem()->components().at(0)->ports().at(1)->name(), QLatin1String("env"));
  QCOMPARE(testSuiteItem.sutItem()->components().at(0)->ports().at(2)->name(), QLatin1String("p"));

  QVERIFY(testSuiteItem.testSystemItem());
  QCOMPARE(testSuiteItem.testSystemItem()->name(), QLatin1String("tst_testsuite_1_testsystem"));
  QCOMPARE(testSuiteItem.testSystemItem()->components().count(), 2);
  QCOMPARE(testSuiteItem.testSystemItem()->components().at(0)->name(), QLatin1String("MTC"));
  QCOMPARE(testSuiteItem.testSystemItem()->components().at(0)->ports().count(), 1);
  QCOMPARE(testSuiteItem.testSystemItem()->components().at(0)->ports().at(0)->name(), QLatin1String("_defaultPort"));

  QCOMPARE(testSuiteItem.testSystemItem()->components().at(1)->name(), QLatin1String("test_component"));
  QCOMPARE(testSuiteItem.testSystemItem()->components().at(1)->ports().count(), 3);
  QCOMPARE(testSuiteItem.testSystemItem()->components().at(1)->ports().at(0)->name(), QLatin1String("_defaultPort"));
  QCOMPARE(testSuiteItem.testSystemItem()->components().at(1)->ports().at(1)->name(), QLatin1String("env"));
  QCOMPARE(testSuiteItem.testSystemItem()->components().at(1)->ports().at(2)->name(), QLatin1String("p"));

  QCOMPARE(testSuiteItem.testCases().count(), 7);
  QCOMPARE(testSuiteItem.testCases().at(0)->sequenceItems().count(), 3);
  QCOMPARE(testSuiteItem.testCases().at(1)->sequenceItems().count(), 5);
  QCOMPARE(testSuiteItem.testCases().at(2)->sequenceItems().count(), 6);
  QCOMPARE(testSuiteItem.testCases().at(3)->sequenceItems().count(), 4);
  QCOMPARE(testSuiteItem.testCases().at(4)->sequenceItems().count(), 5);
  QCOMPARE(testSuiteItem.testCases().at(5)->sequenceItems().count(), 7);
  QCOMPARE(testSuiteItem.testCases().at(6)->sequenceItems().count(), 7);

  return;
}

void ReadXmlTestSuiteItemTest::readXmlTestSuiteItemTest_2()
{
  using namespace model::ts;
  using namespace model::ts::io;

  TestSuiteItem testSuiteItem;
  ComReadXmlTestSuiteItem readTestSuiteItemCommand(":/testdata/tst_testsuite_2.ats",
                                                   &testSuiteItem);
  QString errorMessage;
  bool result = readTestSuiteItemCommand.execute(&errorMessage);
  if(!result)
    qDebug()<<"error within test case readXmlTestSuiteItemTest_2: "<<errorMessage;
  QVERIFY2(result, errorMessage.toLatin1());
  QVERIFY2(errorMessage.isEmpty(), errorMessage.toLatin1());

  QCOMPARE(testSuiteItem.name(), QLatin1String("iolinksafety_master"));

  QVERIFY(testSuiteItem.sutItem());
  QCOMPARE(testSuiteItem.sutItem()->name(), QLatin1String("iolinksafety_master_sut"));
  QCOMPARE(testSuiteItem.sutItem()->components().count(), 1);
  QCOMPARE(testSuiteItem.sutItem()->components().at(0)->name(), QLatin1String("iolinksafety_master_sut"));
  QCOMPARE(testSuiteItem.sutItem()->components().at(0)->ports().count(), 4);
  QCOMPARE(testSuiteItem.sutItem()->components().at(0)->ports().at(0)->name(), QLatin1String("_defaultPort"));
  QCOMPARE(testSuiteItem.sutItem()->components().at(0)->ports().at(1)->name(), QLatin1String("env"));
  QCOMPARE(testSuiteItem.sutItem()->components().at(0)->ports().at(2)->name(), QLatin1String("app_port"));
  QCOMPARE(testSuiteItem.sutItem()->components().at(0)->ports().at(3)->name(), QLatin1String("device_port"));

  QVERIFY(testSuiteItem.testSystemItem());
  QCOMPARE(testSuiteItem.testSystemItem()->name(), QLatin1String("iolinksafety_master_testsystem"));
  QCOMPARE(testSuiteItem.testSystemItem()->components().count(), 2);
  QCOMPARE(testSuiteItem.testSystemItem()->components().at(0)->name(), QLatin1String("MTC"));
  QCOMPARE(testSuiteItem.testSystemItem()->components().at(0)->ports().count(), 1);
  QCOMPARE(testSuiteItem.testSystemItem()->components().at(0)->ports().at(0)->name(), QLatin1String("_defaultPort"));

  QCOMPARE(testSuiteItem.testSystemItem()->components().at(1)->name(), QLatin1String("iolinksafety_master_mtc"));
  QCOMPARE(testSuiteItem.testSystemItem()->components().at(1)->ports().count(), 4);
  QCOMPARE(testSuiteItem.testSystemItem()->components().at(1)->ports().at(0)->name(), QLatin1String("_defaultPort"));
  QCOMPARE(testSuiteItem.testSystemItem()->components().at(1)->ports().at(1)->name(), QLatin1String("env"));
  QCOMPARE(testSuiteItem.testSystemItem()->components().at(1)->ports().at(2)->name(), QLatin1String("app_port"));
  QCOMPARE(testSuiteItem.testSystemItem()->components().at(1)->ports().at(3)->name(), QLatin1String("device_port"));

  QCOMPARE(testSuiteItem.testCases().count(), 3);
  QCOMPARE(testSuiteItem.testCases().at(0)->sequenceItems().count(), 3);
  QCOMPARE(testSuiteItem.testCases().at(1)->sequenceItems().count(), 6);
  QCOMPARE(testSuiteItem.testCases().at(2)->sequenceItems().count(), 9);

  return;
}

QTEST_GUILESS_MAIN(ReadXmlTestSuiteItemTest)

#include "tst_readxmltestsuiteitemtest.moc"
