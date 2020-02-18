#include <QtTest>
// add necessary includes here
#include <QApplication>
#include <QMessageBox>
#include <QtConcurrent>

#include "testexecutor/testexecutormodel.hpp"
#include "testexecutor/vibntestexecutor.hpp"

#include "mobata/model/ts/testsuite.hpp"
#include "mobata/model/ts/testsystemitem.hpp"
#include "mobata/model/ts/sutitem.hpp"

#include "mobata/model/base/componentitem.hpp"
#include "mobata/model/base/signalitem.hpp"

#include "mobata/model/msc/mscmessageitem.hpp"
#include "mobata/model/msc/mscsequenceitem.hpp"

#include "mobata/model/base/paramvalueitem.hpp"

class TestexecutorTest : public QObject
{
  Q_OBJECT

public:
  TestexecutorTest();
  ~TestexecutorTest();

private slots:
  void initTestCase();
  void cleanupTestCase();
  void test_case1();
  void test_case2();
  void test_case3();
  void test_case4();
  void test_case5();

public slots:
  void test_debug(bool result, const QString& message);

private:
  testexecutor::TestexecutorModel* _model;
  testexecutor::VibnTestExecutor* _executor;

};

TestexecutorTest::TestexecutorTest()
{

}

TestexecutorTest::~TestexecutorTest()
{

}

void TestexecutorTest::test_debug(bool result, const QString& message)
{
  Q_UNUSED(result);
  qDebug()<<"Finished Execution received";
  qDebug()<<message;
}

void TestexecutorTest::initTestCase()
{
  QString errorString;
  this->_model = new testexecutor::TestexecutorModel();
  model::ts::TestSuite* testsuite = new model::ts::TestSuite();
  model::ts::TestSystemItem* tsitem = testsuite->testSystemItem();
  model::ts::SutItem* sutitem = testsuite->sutItem();

  model::msc::MscComponentItem* ts = new model::msc::MscComponentItem("ts");
  tsitem->addComponent(ts, &errorString);

  model::msc::MscComponentItem* sut = new model::msc::MscComponentItem("sut");
  sutitem->addComponent(sut, &errorString);


  model::base::SignalItem* setBool = new model::base::SignalItem("setBool");
  setBool->addParameter("bValue","bool");
  model::base::SignalItem* setInt = new model::base::SignalItem("setInt");
  setInt->addParameter("iValue","int");
  model::base::SignalItem* setDouble = new model::base::SignalItem("setDouble");
  setDouble->addParameter("dValue","real");
  model::base::SignalItem* setString = new model::base::SignalItem("setString");
  setString->addParameter("sValue","string");

  //!XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
  // SetBool Test
  //!XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

  testexecutor::TestexecutorTestCase* tc1 = new testexecutor::TestexecutorTestCase("testcase_1");
  tc1->addSignal(setBool,&errorString);

  model::msc::MscMessageItem* t1msgItem1 = tc1->addMessage(ts, sut, QStringLiteral("setBool(bValue=true)"));
  t1msgItem1->setSignal(setBool);
  t1msgItem1->addParamValue(setBool->params().first(),true);

  model::msc::MscTimerItem* timer1 = tc1->addTimer(ts,"timer1");
  timer1->setValue(5);

  model::msc::MscCheckMessageItem* t1msgItem2 = tc1->addCheck(sut, ts, QStringLiteral("setBool(bValue=true)"));
  t1msgItem2->setSignal(setBool);
  t1msgItem2->addParamValue(setBool->params().first(),true);

  model::msc::MscMessageItem* t1msgItem3 = tc1->addMessage(ts, sut, QStringLiteral("setBool(bValue=false)"));
  t1msgItem3->setSignal(setBool);
  t1msgItem3->addParamValue(setBool->params().first(),false);

  this->_model->addTestCase("", tc1, &errorString);
  testsuite->addTestCase(tc1, &errorString);

  //!XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
  // SetInt Test
  //!XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

  testexecutor::TestexecutorTestCase* tc2 = new testexecutor::TestexecutorTestCase("testcase_2");
  tc2->addSignal(setInt,&errorString);

  model::msc::MscMessageItem* t2msgItem1 = tc2->addMessage(ts, sut, QStringLiteral("setInt(iValue=-987)"));
  t2msgItem1->setSignal(setInt);
  t2msgItem1->addParamValue(setInt->params().first(), -987);

  model::msc::MscCheckMessageItem* t2msgItem2 = tc2->addCheck(sut, ts, QStringLiteral("setInt(iValue=-987)"));
  t2msgItem2->setSignal(setInt);
  t2msgItem2->addParamValue(setInt->params().first(), -987);

  model::msc::MscMessageItem* t2msgItem3 = tc2->addMessage(ts, sut, QStringLiteral("setInt(iValue=10)"));
  t2msgItem3->setSignal(setInt);
  t2msgItem3->addParamValue(setInt->params().first(), 10);

  model::msc::MscCheckMessageItem* t2msgItem4 = tc2->addCheck(sut, ts, QStringLiteral("setInt(iValue=10)"));
  t2msgItem4->setSignal(setInt);
  t2msgItem4->addParamValue(setInt->params().first(), 10);
  model::msc::MscCheckMessageItem* t2msgItem5 = tc2->addCheck(sut, ts, QStringLiteral("setInt(iValue=10)"));
  t2msgItem5->setSignal(setInt);
  t2msgItem5->addParamValue(setInt->params().first(), 10);
  model::msc::MscCheckMessageItem* t2msgItem6 = tc2->addCheck(sut, ts, QStringLiteral("setInt(iValue=10)"));
  t2msgItem6->setSignal(setInt);
  t2msgItem6->addParamValue(setInt->params().first(), 10);

  model::msc::MscMessageItem* t2msgItem7 = tc2->addMessage(ts, sut, QStringLiteral("setInt(iValue=63587)"));
  t2msgItem7->setSignal(setInt);
  t2msgItem7->addParamValue(setInt->params().first(), 63587);

  this->_model->addTestCase("", tc2, &errorString);
  testsuite->addTestCase(tc2, &errorString);

  //!XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
  // SetDouble Test
  //!XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

  testexecutor::TestexecutorTestCase* tc3 = new testexecutor::TestexecutorTestCase("testcase_3");
  tc3->addSignal(setDouble,&errorString);

  model::msc::MscMessageItem* t3msgItem1 = tc3->addMessage(ts, sut, QStringLiteral("setDouble(dValue=-987)"));
  t3msgItem1->setSignal(setDouble);
  t3msgItem1->addParamValue(setDouble->params().first(), -987);

  model::msc::MscCheckMessageItem* t3msgItem2 = tc3->addCheck(sut, ts, QStringLiteral("setDouble(dValue=-987)"));
  t3msgItem2->setSignal(setDouble);
  t3msgItem2->addParamValue(setDouble->params().first(), -987);

  model::msc::MscMessageItem* t3msgItem3 = tc3->addMessage(ts, sut, QStringLiteral("setDouble(dValue=10.6587)"));
  t3msgItem3->setSignal(setDouble);
  t3msgItem3->addParamValue(setDouble->params().first(), 10.6587);

  model::msc::MscCheckMessageItem* t3msgItem4 = tc3->addCheck(sut, ts, QStringLiteral("setDouble(dValue=10.6587)"));
  t3msgItem4->setSignal(setDouble);
  t3msgItem4->addParamValue(setDouble->params().first(), 10.6587);
  model::msc::MscCheckMessageItem* t3msgItem5 = tc3->addCheck(sut, ts, QStringLiteral("setDouble(dValue=10.6587)"));
  t3msgItem5->setSignal(setDouble);
  t3msgItem5->addParamValue(setDouble->params().first(), 10.6587);
  model::msc::MscCheckMessageItem* t3msgItem6 = tc3->addCheck(sut, ts, QStringLiteral("setDouble(dValue=10.6587)"));
  t3msgItem6->setSignal(setDouble);
  t3msgItem6->addParamValue(setDouble->params().first(), 10.6587);

  model::msc::MscMessageItem* t3msgItem7 = tc3->addMessage(ts, sut, QStringLiteral("setDouble(dValue=-63587.7896324)"));
  t3msgItem7->setSignal(setDouble);
  t3msgItem7->addParamValue(setDouble->params().first(), -63587.7896324);

  this->_model->addTestCase("", tc3, &errorString);
  testsuite->addTestCase(tc3, &errorString);

  //!XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
  // SetString Test
  //!XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

  testexecutor::TestexecutorTestCase* tc4 = new testexecutor::TestexecutorTestCase("testcase_4");
  tc4->addSignal(setString,&errorString);

  model::msc::MscMessageItem* t4msgItem1 = tc4->addMessage(ts, sut, QStringLiteral("setString(sValue=Hello)"));
  t4msgItem1->setSignal(setString);
  t4msgItem1->addParamValue(setString->params().first(), "Hello");

  model::msc::MscCheckMessageItem* t4msgItem2 = tc4->addCheck(sut, ts, QStringLiteral("setString(sValue=Hello)"));
  t4msgItem2->setSignal(setString);
  t4msgItem2->addParamValue(setString->params().first(), "Hello");

  model::msc::MscMessageItem* t4msgItem3 = tc4->addMessage(ts, sut, QStringLiteral("setString(sValue=World)"));
  t4msgItem3->setSignal(setString);
  t4msgItem3->addParamValue(setString->params().first(), "World");

  model::msc::MscCheckMessageItem* t4msgItem4 = tc4->addCheck(sut, ts, QStringLiteral("setString(sValue=World)"));
  t4msgItem4->setSignal(setString);
  t4msgItem4->addParamValue(setString->params().first(), "World");
  model::msc::MscCheckMessageItem* t4msgItem5 = tc4->addCheck(sut, ts, QStringLiteral("setString(sValue=World)"));
  t4msgItem5->setSignal(setString);
  t4msgItem5->addParamValue(setString->params().first(), "World");
  model::msc::MscCheckMessageItem* t4msgItem6 = tc4->addCheck(sut, ts, QStringLiteral("setString(sValue=World)"));
  t4msgItem6->setSignal(setString);
  t4msgItem6->addParamValue(setString->params().first(), "World");

  model::msc::MscMessageItem* t4msgItem7 = tc4->addMessage(ts, sut, QStringLiteral("setString(sValue=!)"));
  t4msgItem7->setSignal(setString);
  t4msgItem7->addParamValue(setString->params().first(), "!");

  this->_model->addTestCase("", tc4, &errorString);
  testsuite->addTestCase(tc4, &errorString);


  this->_model->setTestSuite(testsuite);
}

void TestexecutorTest::cleanupTestCase()
{
  delete this->_model;
}

void TestexecutorTest::test_case1()
{
  QCOMPARE(this->_model->testSuite()->testCases().length(), 4);
  this->_model->testSuite()->testCases().at(0)->setEnabled(true);
  this->_model->testSuite()->testCases().at(1)->setEnabled(true);
  this->_model->testSuite()->testCases().at(2)->setEnabled(true);
  this->_model->testSuite()->testCases().at(3)->setEnabled(true);

  if(this->_executor){
    delete this->_executor;
  }
  this->_executor = new testexecutor::VibnTestExecutor(this->_model, "");

  QList<QPair<QString, QVariant>> list;
  list.append(QPair<QString, QVariant>("setBool",true));
  list.append(QPair<QString, QVariant>("setBool",true));
  list.append(QPair<QString, QVariant>("setBool",false));

  list.append(QPair<QString, QVariant>("setInt",-987));
  list.append(QPair<QString, QVariant>("setInt",-987));
  list.append(QPair<QString, QVariant>("setInt",10));
  list.append(QPair<QString, QVariant>("setInt",10));
  list.append(QPair<QString, QVariant>("setInt",10));
  list.append(QPair<QString, QVariant>("setInt",10));
  list.append(QPair<QString, QVariant>("setInt",63587));

  list.append(QPair<QString, QVariant>("setDouble",-987.0));
  list.append(QPair<QString, QVariant>("setDouble",-987.0));
  list.append(QPair<QString, QVariant>("setDouble",10.6587));
  list.append(QPair<QString, QVariant>("setDouble",10.6587));
  list.append(QPair<QString, QVariant>("setDouble",10.6587));
  list.append(QPair<QString, QVariant>("setDouble",10.6587));
  list.append(QPair<QString, QVariant>("setDouble",-63587.7896324));

  list.append(QPair<QString, QVariant>("setString","Hello"));
  list.append(QPair<QString, QVariant>("setString","Hello"));
  list.append(QPair<QString, QVariant>("setString","World"));
  list.append(QPair<QString, QVariant>("setString","World"));
  list.append(QPair<QString, QVariant>("setString","World"));
  list.append(QPair<QString, QVariant>("setString","World"));
  list.append(QPair<QString, QVariant>("setString","!"));

  bool setuped = _executor->setupFake(list);
  QVERIFY(setuped);
  _executor->start();

  QTest::qWaitFor([&](){return _executor->finishedState();},30000);
  model::ts::TestCaseItem* tc;
  testexecutor::TestexecutorTestCase* ttc;
  QCOMPARE(this->_model->testSuite()->testCases().length(), 4);
  tc = this->_model->testSuite()->testCases().at(0);
  QVERIFY(tc);
  ttc = dynamic_cast<testexecutor::TestexecutorTestCase*>(tc);
  QVERIFY(ttc);
  QCOMPARE(ttc->testResultToString(), QStringLiteral("Succeeded"));
  QCOMPARE(ttc->errorMessage(), QStringLiteral(""));

  tc = this->_model->testSuite()->testCases().at(1);
  QVERIFY(tc);
  ttc = dynamic_cast<testexecutor::TestexecutorTestCase*>(tc);
  QVERIFY(ttc);
  QCOMPARE(ttc->testResultToString(), QStringLiteral("Succeeded"));
  QCOMPARE(ttc->errorMessage(), QStringLiteral(""));

  tc = this->_model->testSuite()->testCases().at(2);
  QVERIFY(tc);
  ttc = dynamic_cast<testexecutor::TestexecutorTestCase*>(tc);
  QVERIFY(ttc);
  QCOMPARE(ttc->testResultToString(), QStringLiteral("Succeeded"));
  QCOMPARE(ttc->errorMessage(), QStringLiteral(""));

  tc = this->_model->testSuite()->testCases().at(3);
  QVERIFY(tc);
  ttc = dynamic_cast<testexecutor::TestexecutorTestCase*>(tc);
  QVERIFY(ttc);
  QCOMPARE(ttc->testResultToString(), QStringLiteral("Succeeded"));
  QCOMPARE(ttc->errorMessage(), QStringLiteral(""));


  QCOMPARE(this->_executor->result(),true);
}

void TestexecutorTest::test_case2()
{
  QCOMPARE(this->_model->testSuite()->testCases().length(), 4);
  this->_model->testSuite()->testCases().at(0)->setEnabled(true);
  this->_model->testSuite()->testCases().at(1)->setEnabled(false);
  this->_model->testSuite()->testCases().at(2)->setEnabled(false);
  this->_model->testSuite()->testCases().at(3)->setEnabled(false);

  if(this->_executor){
    delete this->_executor;
  }
  this->_executor = new testexecutor::VibnTestExecutor(this->_model, "");

  QList<QPair<QString, QVariant>> list;
  list.append(QPair<QString, QVariant>("setBool",false));
  list.append(QPair<QString, QVariant>("setBool",true));
  list.append(QPair<QString, QVariant>("setBool",false));

  bool setuped = _executor->setupFake(list);
  QVERIFY(setuped);
  _executor->start();

  QTest::qWaitFor([&](){return _executor->finishedState();},30000);
  model::ts::TestCaseItem* tc;
  testexecutor::TestexecutorTestCase* ttc;
  QCOMPARE(this->_model->testSuite()->testCases().length(), 4);
  tc = this->_model->testSuite()->testCases().at(0);
  QVERIFY(tc);
  ttc = dynamic_cast<testexecutor::TestexecutorTestCase*>(tc);
  QVERIFY(ttc);
  QCOMPARE(ttc->testResultToString(), QStringLiteral("Failed"));
  QCOMPARE(ttc->errorMessage(), QStringLiteral("Error: setBool actual ( false ) , expected ( true )\n"));

  tc = this->_model->testSuite()->testCases().at(1);
  QVERIFY(tc);
  ttc = dynamic_cast<testexecutor::TestexecutorTestCase*>(tc);
  QVERIFY(ttc);
  QCOMPARE(ttc->testResultToString(), QStringLiteral("Excluded"));
  QCOMPARE(ttc->errorMessage(), QStringLiteral(""));

  tc = this->_model->testSuite()->testCases().at(2);
  QVERIFY(tc);
  ttc = dynamic_cast<testexecutor::TestexecutorTestCase*>(tc);
  QVERIFY(ttc);
  QCOMPARE(ttc->testResultToString(), QStringLiteral("Excluded"));
  QCOMPARE(ttc->errorMessage(), QStringLiteral(""));

  tc = this->_model->testSuite()->testCases().at(3);
  QVERIFY(tc);
  ttc = dynamic_cast<testexecutor::TestexecutorTestCase*>(tc);
  QVERIFY(ttc);
  QCOMPARE(ttc->testResultToString(), QStringLiteral("Excluded"));
  QCOMPARE(ttc->errorMessage(), QStringLiteral(""));


  QCOMPARE(this->_executor->result(),false);
}

void TestexecutorTest::test_case3()
{
  QCOMPARE(this->_model->testSuite()->testCases().length(), 4);
  this->_model->testSuite()->testCases().at(0)->setEnabled(true);
  this->_model->testSuite()->testCases().at(1)->setEnabled(false);
  this->_model->testSuite()->testCases().at(2)->setEnabled(false);
  this->_model->testSuite()->testCases().at(3)->setEnabled(false);

  if(this->_executor){
    delete this->_executor;
  }
  this->_executor = new testexecutor::VibnTestExecutor(this->_model, "");

  QList<QPair<QString, QVariant>> list;
  list.append(QPair<QString, QVariant>("setBool",true));
  list.append(QPair<QString, QVariant>("setBool",false));
  list.append(QPair<QString, QVariant>("setBool",false));

  bool setuped = _executor->setupFake(list);
  QVERIFY(setuped);
  _executor->start();

  QTest::qWaitFor([&](){return _executor->finishedState();},30000);
  model::ts::TestCaseItem* tc;
  testexecutor::TestexecutorTestCase* ttc;
  QCOMPARE(this->_model->testSuite()->testCases().length(), 4);
  tc = this->_model->testSuite()->testCases().at(0);
  QVERIFY(tc);
  ttc = dynamic_cast<testexecutor::TestexecutorTestCase*>(tc);
  QVERIFY(ttc);
  QCOMPARE(ttc->testResultToString(), QStringLiteral("Failed"));
  QCOMPARE(ttc->errorMessage(), QStringLiteral("Error: setBool actual ( false ) , expected ( true )\n"));

  tc = this->_model->testSuite()->testCases().at(1);
  QVERIFY(tc);
  ttc = dynamic_cast<testexecutor::TestexecutorTestCase*>(tc);
  QVERIFY(ttc);
  QCOMPARE(ttc->testResultToString(), QStringLiteral("Excluded"));
  QCOMPARE(ttc->errorMessage(), QStringLiteral(""));

  tc = this->_model->testSuite()->testCases().at(2);
  QVERIFY(tc);
  ttc = dynamic_cast<testexecutor::TestexecutorTestCase*>(tc);
  QVERIFY(ttc);
  QCOMPARE(ttc->testResultToString(), QStringLiteral("Excluded"));
  QCOMPARE(ttc->errorMessage(), QStringLiteral(""));

  tc = this->_model->testSuite()->testCases().at(3);
  QVERIFY(tc);
  ttc = dynamic_cast<testexecutor::TestexecutorTestCase*>(tc);
  QVERIFY(ttc);
  QCOMPARE(ttc->testResultToString(), QStringLiteral("Excluded"));
  QCOMPARE(ttc->errorMessage(), QStringLiteral(""));


  QCOMPARE(this->_executor->result(),false);
}

void TestexecutorTest::test_case4()
{
  QCOMPARE(this->_model->testSuite()->testCases().length(), 4);
  this->_model->testSuite()->testCases().at(0)->setEnabled(true);
  this->_model->testSuite()->testCases().at(1)->setEnabled(false);
  this->_model->testSuite()->testCases().at(2)->setEnabled(false);
  this->_model->testSuite()->testCases().at(3)->setEnabled(false);

  if(this->_executor){
    delete this->_executor;
  }
  this->_executor = new testexecutor::VibnTestExecutor(this->_model, "");

  QList<QPair<QString, QVariant>> list;
  list.append(QPair<QString, QVariant>("setBool",true));
  list.append(QPair<QString, QVariant>("setInt",158));
  list.append(QPair<QString, QVariant>("setBool",false));

  bool setuped = _executor->setupFake(list);
  QVERIFY(setuped);
  _executor->start();

  QTest::qWaitFor([&](){return _executor->finishedState();},30000);
  model::ts::TestCaseItem* tc;
  testexecutor::TestexecutorTestCase* ttc;
  QCOMPARE(this->_model->testSuite()->testCases().length(), 4);
  tc = this->_model->testSuite()->testCases().at(0);
  QVERIFY(tc);
  ttc = dynamic_cast<testexecutor::TestexecutorTestCase*>(tc);
  QVERIFY(ttc);
  QCOMPARE(ttc->testResultToString(), QStringLiteral("Failed"));
  QCOMPARE(ttc->errorMessage(), QStringLiteral("Error: setInt actual ( received signal ) , expected ( setBool )\n"));

  tc = this->_model->testSuite()->testCases().at(1);
  QVERIFY(tc);
  ttc = dynamic_cast<testexecutor::TestexecutorTestCase*>(tc);
  QVERIFY(ttc);
  QCOMPARE(ttc->testResultToString(), QStringLiteral("Excluded"));
  QCOMPARE(ttc->errorMessage(), QStringLiteral(""));

  tc = this->_model->testSuite()->testCases().at(2);
  QVERIFY(tc);
  ttc = dynamic_cast<testexecutor::TestexecutorTestCase*>(tc);
  QVERIFY(ttc);
  QCOMPARE(ttc->testResultToString(), QStringLiteral("Excluded"));
  QCOMPARE(ttc->errorMessage(), QStringLiteral(""));

  tc = this->_model->testSuite()->testCases().at(3);
  QVERIFY(tc);
  ttc = dynamic_cast<testexecutor::TestexecutorTestCase*>(tc);
  QVERIFY(ttc);
  QCOMPARE(ttc->testResultToString(), QStringLiteral("Excluded"));
  QCOMPARE(ttc->errorMessage(), QStringLiteral(""));


  QCOMPARE(this->_executor->result(),false);
}

void TestexecutorTest::test_case5()
{
  QCOMPARE(this->_model->testSuite()->testCases().length(), 4);
  this->_model->testSuite()->testCases().at(0)->setEnabled(false);
  this->_model->testSuite()->testCases().at(1)->setEnabled(true);
  this->_model->testSuite()->testCases().at(2)->setEnabled(false);
  this->_model->testSuite()->testCases().at(3)->setEnabled(false);

  if(this->_executor){
    delete this->_executor;
  }
  this->_executor = new testexecutor::VibnTestExecutor(this->_model, "");

  QList<QPair<QString, QVariant>> list;
  list.append(QPair<QString, QVariant>("setInt",-987));
  list.append(QPair<QString, QVariant>("setInt",-987));
  list.append(QPair<QString, QVariant>("setInt",10));
  list.append(QPair<QString, QVariant>("setInt",10));
  list.append(QPair<QString, QVariant>("setInt","empty"));
  list.append(QPair<QString, QVariant>("setInt",10));
  list.append(QPair<QString, QVariant>("setInt",63587));

  bool setuped = _executor->setupFake(list);
  QVERIFY(setuped);
  _executor->start();

  QTest::qWaitFor([&](){return _executor->finishedState();},30000);
  model::ts::TestCaseItem* tc;
  testexecutor::TestexecutorTestCase* ttc;
  QCOMPARE(this->_model->testSuite()->testCases().length(), 4);
  tc = this->_model->testSuite()->testCases().at(0);
  QVERIFY(tc);
  ttc = dynamic_cast<testexecutor::TestexecutorTestCase*>(tc);
  QVERIFY(ttc);
  QCOMPARE(ttc->testResultToString(), QStringLiteral("Excluded"));

  tc = this->_model->testSuite()->testCases().at(1);
  QVERIFY(tc);
  ttc = dynamic_cast<testexecutor::TestexecutorTestCase*>(tc);
  QVERIFY(ttc);
  QCOMPARE(ttc->testResultToString(), QStringLiteral("Failed"));
  QCOMPARE(ttc->errorMessage(), QStringLiteral("Error: setInt actual ( 0 ) , expected ( 1 ) parameter count\n"));

  tc = this->_model->testSuite()->testCases().at(2);
  QVERIFY(tc);
  ttc = dynamic_cast<testexecutor::TestexecutorTestCase*>(tc);
  QVERIFY(ttc);
  QCOMPARE(ttc->testResultToString(), QStringLiteral("Excluded"));
  QCOMPARE(ttc->errorMessage(), QStringLiteral(""));

  tc = this->_model->testSuite()->testCases().at(3);
  QVERIFY(tc);
  ttc = dynamic_cast<testexecutor::TestexecutorTestCase*>(tc);
  QVERIFY(ttc);
  QCOMPARE(ttc->testResultToString(), QStringLiteral("Excluded"));
  QCOMPARE(ttc->errorMessage(), QStringLiteral(""));


  QCOMPARE(this->_executor->result(),false);
}

QTEST_MAIN(TestexecutorTest)

#include "tst_testexecutortest.moc"
