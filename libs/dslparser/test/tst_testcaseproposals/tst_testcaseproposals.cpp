#include <QtTest>

#include <dslparser/testcase/comcreatetestcaseproposals.hpp>
#include <dslparser/testcase/combuildtestcasemodel.hpp>

#include <mobata/model/ts/testcaseitem.hpp>

#include <mobata/memory_leak_start.hpp>

using namespace dslparser;
using namespace dslparser::testcase;
using namespace model::ts;

class TestCaseProposalsTest
    : public QObject
{
  Q_OBJECT

public:
  TestCaseProposalsTest();

private Q_SLOTS:
  void initTest();
  void cleanupTest();
  void testcaseProposalEmptyTextTest_1();
  void testcaseProposalTest_1();
  void testcaseProposalTest_2();
  void testcaseProposalTest_2_1();
  void testcaseProposalTest_2_2();
  void testcaseProposalTest_3();
  void testcaseProposalTest_4();
  void testcaseProposalTest_5();
  void testcaseProposalTest_6();
  void testcaseProposalTest_7();
  void testcaseProposalTest_8();
  void testcaseProposalTest_9();
  void testcaseProposalTest_10();
  void testcaseProposalTest_11();
  void testcaseProposalTest_12();
  void testcaseProposalTest_13();
  void testcaseProposalTest_14();
  void includeTestCaseProposalTest1();
  void includeTestCaseProposalTest2();
  void includeTestCaseProposalTest3();
  void includeTestCaseProposalTest4();
  void includeTestCaseProposalErrorTest();
  void testcaseProposalAfterCommentTest_1();
  void testcaseProposalAfterCommentTest_2();
  void testcaseProposalAfterCommentTest_3();
  void testcaseProposalAfterCommentTest_4();
  void testcaseProposalWithinCommentTest_1();
  void testcaseProposalWithinCommentTest_2();
};

TestCaseProposalsTest::TestCaseProposalsTest()
{}

void TestCaseProposalsTest::initTest()
{}

void TestCaseProposalsTest::cleanupTest()
{}

void TestCaseProposalsTest::testcaseProposalEmptyTextTest_1()
{
  QString docText("");

  ComCreateTestCaseProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(2, command.testCaseProposals().count());

  DslProposal firstProposal = command.testCaseProposals().at(0);
  QCOMPARE(QString("TestCase"), firstProposal.proposalText);
  QCOMPARE((int)TestCase, firstProposal.proposalType);

  DslProposal secProposal = command.testCaseProposals().at(1);
  QCOMPARE(QString("import"), secProposal.proposalText);
  QCOMPARE((int)Import, secProposal.proposalType);

  return;
}

void TestCaseProposalsTest::testcaseProposalTest_1()
{
  QString docText(L'\u2029');
  docText+=" ";
  docText+=QChar(L'\u2029');
  docText+=" ";

  ComCreateTestCaseProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(2, command.testCaseProposals().count());

  DslProposal firstProposal = command.testCaseProposals().at(0);
  QCOMPARE(QString("TestCase"), firstProposal.proposalText);
  QCOMPARE((int)TestCase, firstProposal.proposalType);

  DslProposal secProposal = command.testCaseProposals().at(1);
  QCOMPARE(QString("import"), secProposal.proposalText);
  QCOMPARE((int)Import, secProposal.proposalType);
  return;
}

void TestCaseProposalsTest::testcaseProposalTest_2()
{
  QString docText(L'\u2029');
  docText+=" ";
  docText+=QChar(L'\u2029');
  docText+=" TestCase";

  ComCreateTestCaseProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(1, command.testCaseProposals().count());

  DslProposal firstProposal = command.testCaseProposals().at(0);
  QCOMPARE(QString("{"), firstProposal.proposalText);
  QCOMPARE((int)LeftBrace, firstProposal.proposalType);

  return;
}

void TestCaseProposalsTest::testcaseProposalTest_2_1()
{
  QString docText(L'\u2029');
  docText+=" ";
  docText+=QChar(L'\u2029');
  docText+=QChar('\r');
  docText+=QChar('\n');
  docText+=" TestCase";

  ComCreateTestCaseProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(1, command.testCaseProposals().count());

  DslProposal firstProposal = command.testCaseProposals().at(0);
  QCOMPARE(QString("{"), firstProposal.proposalText);
  QCOMPARE((int)LeftBrace, firstProposal.proposalType);

  return;
}

void TestCaseProposalsTest::testcaseProposalTest_2_2()
{
  QString docText("TestCase");

  ComCreateTestCaseProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(1, command.testCaseProposals().count());

  DslProposal firstProposal = command.testCaseProposals().at(0);
  QCOMPARE(QString("{"), firstProposal.proposalText);
  QCOMPARE((int)LeftBrace, firstProposal.proposalType);

  return;
}

void TestCaseProposalsTest::testcaseProposalTest_3()
{
  QString docText("TestCase{");

  ComCreateTestCaseProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(1, command.testCaseProposals().count());

  DslProposal firstProposal = command.testCaseProposals().at(0);
  QCOMPARE(QString("Declaration"), firstProposal.proposalText);
  QCOMPARE((int)Declaration, firstProposal.proposalType);

  return;
}

void TestCaseProposalsTest::testcaseProposalTest_4()
{
  QString docText("TestCase{Declaration{name");

  ComCreateTestCaseProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(1, command.testCaseProposals().count());

  DslProposal firstProposal = command.testCaseProposals().at(0);
  QCOMPARE(QString(":"), firstProposal.proposalText);
  QCOMPARE((int)Colon, firstProposal.proposalType);

  return;
}

void TestCaseProposalsTest::testcaseProposalTest_5()
{
  QString docText("TestCase{Declaration{name:");

  ComCreateTestCaseProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.testCaseProposals().count());

  return;
}

void TestCaseProposalsTest::testcaseProposalTest_6()
{
  QString docText("TestCase{Declaration{name:myTestCase; ");

  ComCreateTestCaseProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(8, command.testCaseProposals().count());

  DslProposal proposal = command.testCaseProposals().at(0);
  QCOMPARE(QString("Attribute"), proposal.proposalText);
  QCOMPARE((int)Attribute, proposal.proposalType);

  proposal = command.testCaseProposals().at(1);
  QCOMPARE(QString("Check"), proposal.proposalText);
  QCOMPARE((int)Check, proposal.proposalType);

  proposal = command.testCaseProposals().at(2);
  QCOMPARE(QString("Component"), proposal.proposalText);
  QCOMPARE((int)Component, proposal.proposalType);

  proposal = command.testCaseProposals().at(3);
  QCOMPARE(QString("Signal"), proposal.proposalText);
  QCOMPARE((int)Signal, proposal.proposalType);

  proposal = command.testCaseProposals().at(4);
  QCOMPARE(QString("enabled"), proposal.proposalText);
  QCOMPARE((int)Enabled, proposal.proposalType);

  proposal = command.testCaseProposals().at(5);
  QCOMPARE(QString("name"), proposal.proposalText);
  QCOMPARE((int)Name, proposal.proposalType);

  proposal = command.testCaseProposals().at(6);
  QCOMPARE(QString("uuid"), proposal.proposalText);
  QCOMPARE(0, proposal.proposalType);

  proposal = command.testCaseProposals().at(7);
  QCOMPARE(QString("}"), proposal.proposalText);
  QCOMPARE((int)RightBrace, proposal.proposalType);

  return;
}

void TestCaseProposalsTest::testcaseProposalTest_7()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_testcase_3.testcase";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  ComCreateTestCaseProposals command(docText,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(3, command.testCaseProposals().count());

  DslProposal proposal = command.testCaseProposals().at(0);
  QCOMPARE(QString("sut."), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.testCaseProposals().at(1);
  QCOMPARE(QString("testsystem."), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.testCaseProposals().at(2);
  QCOMPARE(QString("this."), proposal.proposalText);
  QCOMPARE((int)This, proposal.proposalType);
  return;
}

void TestCaseProposalsTest::testcaseProposalTest_8()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_testcase_4.testcase";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  ComCreateTestCaseProposals command(docText,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(3, command.testCaseProposals().count());

  DslProposal proposal = command.testCaseProposals().at(0);
  QCOMPARE(QString("sut."), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.testCaseProposals().at(1);
  QCOMPARE(QString("testsystem."), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.testCaseProposals().at(2);
  QCOMPARE(QString("this."), proposal.proposalText);
  QCOMPARE((int)This, proposal.proposalType);

  return;
}

void TestCaseProposalsTest::testcaseProposalTest_9()
{
//  QString praefix = ":/Examples/";
//  QString filename = praefix + "example_testcase_5.testcase";
//  QFile file(filename);
//  if(!file.open(QFile::ReadOnly))
//    qDebug()<<"file '"<<filename<<"' could not be opended!";
//  QString docText(file.readAll());
//  file.close();
//  ComCreateTestCaseProposals command(docText,praefix);
//  QString errorString;
//  bool result = command.execute(&errorString);
//  QCOMPARE(result, true);
//  QCOMPARE(10, command.testCaseProposals().count());//FIXME: no operational symbols as proposal

//  DslProposal proposal = command.testCaseProposals().at(0);
//  QCOMPARE(QString("!"), proposal.proposalText);
//  QCOMPARE((int)Not, proposal.proposalType);

//  proposal = command.testCaseProposals().at(1);
//  QCOMPARE(QString("&&"), proposal.proposalText);
//  QCOMPARE((int)And, proposal.proposalType);

//  proposal = command.testCaseProposals().at(2);
//  QCOMPARE(QString("*"), proposal.proposalText);
//  QCOMPARE((int)Mult, proposal.proposalType);

//  proposal = command.testCaseProposals().at(3);
//  QCOMPARE(QString("+"), proposal.proposalText);
//  QCOMPARE((int)Plus, proposal.proposalType);

//  proposal = command.testCaseProposals().at(4);
//  QCOMPARE(QString("-"), proposal.proposalText);
//  QCOMPARE((int)Minus, proposal.proposalType);

//  proposal = command.testCaseProposals().at(5);
//  QCOMPARE(QString("/"), proposal.proposalText);
//  QCOMPARE((int)Div, proposal.proposalType);

//  proposal = command.testCaseProposals().at(6);
//  QCOMPARE(QString("<"), proposal.proposalText);
//  QCOMPARE((int)LessThan, proposal.proposalType);

//  proposal = command.testCaseProposals().at(7);
//  QCOMPARE(QString("="), proposal.proposalText);
//  QCOMPARE((int)Assign, proposal.proposalType);

//  proposal = command.testCaseProposals().at(8);
//  QCOMPARE(QString(">"), proposal.proposalText);
//  QCOMPARE((int)GreaterThan, proposal.proposalType);

//  proposal = command.testCaseProposals().at(9);
//  QCOMPARE(QString("]"), proposal.proposalText);
//  QCOMPARE((int)RightBracket, proposal.proposalType);

//  proposal = command.testCaseProposals().at(10);
//  QCOMPARE(QString("and"), proposal.proposalText);
//  QCOMPARE((int)And, proposal.proposalType);

//  proposal = command.testCaseProposals().at(11);
//  QCOMPARE(QString("not"), proposal.proposalText);
//  QCOMPARE((int)Not, proposal.proposalType);

//  proposal = command.testCaseProposals().at(12);
//  QCOMPARE(QString("or"), proposal.proposalText);
//  QCOMPARE((int)Or, proposal.proposalType);

//  proposal = command.testCaseProposals().at(13);
//  QCOMPARE(QString("||"), proposal.proposalText);
//  QCOMPARE((int)Or, proposal.proposalType);

  return;
}

void TestCaseProposalsTest::testcaseProposalTest_10()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_testcase_6.testcase";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  ComCreateTestCaseProposals command(docText,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(1, command.testCaseProposals().count());

  DslProposal proposal = command.testCaseProposals().at(0);
  QCOMPARE(QString("->"), proposal.proposalText);
  QCOMPARE(int(RightArrow), proposal.proposalType);

  return;
}

void TestCaseProposalsTest::testcaseProposalTest_11()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_testcase_7.testcase";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  ComCreateTestCaseProposals command(docText,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(4, command.testCaseProposals().count());

  DslProposal proposal = command.testCaseProposals().at(0);
  QCOMPARE(QString("RSE_App"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.testCaseProposals().at(1);
  QCOMPARE(QString("RSE_App."), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.testCaseProposals().at(2);
  QCOMPARE(QString("sut_comp_2"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.testCaseProposals().at(3);
  QCOMPARE(QString("sut_comp_2."), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  return;
}

void TestCaseProposalsTest::testcaseProposalTest_12()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_testcase_9.testcase";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  ComCreateTestCaseProposals command(docText,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(2, command.testCaseProposals().count());

  DslProposal proposal = command.testCaseProposals().at(0);
  QCOMPARE(QString(";"), proposal.proposalText);
  QCOMPARE((int)Semi, proposal.proposalType);

  proposal = command.testCaseProposals().at(1);
  QCOMPARE(QString("="), proposal.proposalText);
  QCOMPARE((int)Assign, proposal.proposalType);
  return;
}

void TestCaseProposalsTest::testcaseProposalTest_13()
{
//  QString praefix = ":/Examples/";
//  QString filename = praefix + "example_testcase_10.testcase";
//  QFile file(filename);
//  if(!file.open(QFile::ReadOnly))
//    qDebug()<<"file '"<<filename<<"' could not be opended!";
//  QString docText(file.readAll());
//  file.close();
//  ComCreateTestCaseProposals command(docText,praefix);
//  QString errorString;
//  bool result = command.execute(&errorString);
//  QCOMPARE(result, true);
//  QCOMPARE(3, command.testCaseProposals().count());

//  DslProposal proposal = command.testCaseProposals().at(0);
//  QCOMPARE(QString("response"), proposal.proposalText);
//  QCOMPARE((int)Identifier, proposal.proposalType);

//  proposal = command.testCaseProposals().at(1);
//  QCOMPARE(QString("stimuli"), proposal.proposalText);
//  QCOMPARE((int)Identifier, proposal.proposalType);

//  proposal = command.testCaseProposals().at(2);
//  QCOMPARE(QString("winmodVar"), proposal.proposalText);
//  QCOMPARE((int)Identifier, proposal.proposalType);
  return;
}

void TestCaseProposalsTest::testcaseProposalTest_14()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_testcase_11.testcase";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  ComCreateTestCaseProposals command(docText,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(4, command.testCaseProposals().count());

  DslProposal proposal = command.testCaseProposals().at(0);
  QCOMPARE(QString("response"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.testCaseProposals().at(1);
  QCOMPARE(QString("stimuli"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.testCaseProposals().at(2);
  QCOMPARE(QString("this."), proposal.proposalText);
  QCOMPARE((int)This, proposal.proposalType);

  proposal = command.testCaseProposals().at(3);
  QCOMPARE(QString("winmodVar"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);
  return;
}

void TestCaseProposalsTest::includeTestCaseProposalTest1(){
  QString praefix = ":/Examples/";
  QString filename = praefix + "testpath/example2.testcase";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();

  ComCreateTestCaseProposals propCommand(docText,praefix);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(15,propCommand.testCaseProposals().size());

  DslProposal proposal = propCommand.testCaseProposals().at(0);
  QCOMPARE(QString(".."), proposal.proposalText);
  QCOMPARE((int)Range, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(1);
  QCOMPARE(QString("example1.testsystem"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(2);
  QCOMPARE(QString("example1_2.testsystem"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(3);
  QCOMPARE(QString("example1_3.testsystem"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(4);
  QCOMPARE(QString("example_testcase_1.testcase"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(5);
  QCOMPARE(QString("example_testcase_10.testcase"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(6);
  QCOMPARE(QString("example_testcase_11.testcase"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(7);
  QCOMPARE(QString("example_testcase_3.testcase"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(8);
  QCOMPARE(QString("example_testcase_4.testcase"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(9);
  QCOMPARE(QString("example_testcase_5.testcase"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(10);
  QCOMPARE(QString("example_testcase_6.testcase"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(11);
  QCOMPARE(QString("example_testcase_7.testcase"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(12);
  QCOMPARE(QString("example_testcase_9.testcase"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(13);
  QCOMPARE(QString("sutExample.sut"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(14);
  QCOMPARE(QString("testpath"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);
}

void TestCaseProposalsTest::includeTestCaseProposalTest2(){
  QString praefix = ":/Examples/";
  QString filename = praefix + "testpath/example3.testcase";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();

  ComCreateTestCaseProposals propCommand(docText,praefix);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(8,propCommand.testCaseProposals().size());

  DslProposal proposal = propCommand.testCaseProposals().at(0);
  QCOMPARE(QString(".."), proposal.proposalText);
  QCOMPARE((int)Range, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(1);
  QCOMPARE(QString("example2.testcase"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(2);
  QCOMPARE(QString("example3.testcase"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(3);
  QCOMPARE(QString("example4.testcase"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(4);
  QCOMPARE(QString("example5.testcase"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(5);
  QCOMPARE(QString("sutExample2.sut"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(6);
  QCOMPARE(QString("sutExample3.sut"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(7);
  QCOMPARE(QString("sutExample4.sut"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);
}

void TestCaseProposalsTest::includeTestCaseProposalTest3(){
  QString praefix = ":/Examples/";
  QString filename = praefix + "testpath/example4.testcase";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();

  ComCreateTestCaseProposals propCommand(docText,praefix);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(4,propCommand.testCaseProposals().size());

  DslProposal proposal = propCommand.testCaseProposals().at(0);
  QCOMPARE(QString(".."), proposal.proposalText);
  QCOMPARE((int)Range, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(1);
  QCOMPARE(QString("2.sut"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(2);
  QCOMPARE(QString("3.sut"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(3);
  QCOMPARE(QString("4.sut"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);
}

void TestCaseProposalsTest::includeTestCaseProposalTest4(){
  QString praefix = ":/Examples/";
  QString docText("import <testpath/../");

  ComCreateTestCaseProposals propCommand(docText,praefix);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(15,propCommand.testCaseProposals().size());

  DslProposal proposal = propCommand.testCaseProposals().at(0);
  QCOMPARE(QString(".."), proposal.proposalText);
  QCOMPARE((int)Range, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(1);
  QCOMPARE(QString("example1.testsystem"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(2);
  QCOMPARE(QString("example1_2.testsystem"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(3);
  QCOMPARE(QString("example1_3.testsystem"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(4);
  QCOMPARE(QString("example_testcase_1.testcase"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(5);
  QCOMPARE(QString("example_testcase_10.testcase"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(6);
  QCOMPARE(QString("example_testcase_11.testcase"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(7);
  QCOMPARE(QString("example_testcase_3.testcase"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(8);
  QCOMPARE(QString("example_testcase_4.testcase"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(9);
  QCOMPARE(QString("example_testcase_5.testcase"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(10);
  QCOMPARE(QString("example_testcase_6.testcase"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(11);
  QCOMPARE(QString("example_testcase_7.testcase"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(12);
  QCOMPARE(QString("example_testcase_9.testcase"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(13);
  QCOMPARE(QString("sutExample.sut"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(14);
  QCOMPARE(QString("testpath"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);
}

void TestCaseProposalsTest::includeTestCaseProposalErrorTest(){
  QString praefix = ":/Examples/";
  QString docText("import <testpath/huivva/");

  ComCreateTestCaseProposals propCommand(docText,praefix);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0,propCommand.testCaseProposals().size());
}

void TestCaseProposalsTest::testcaseProposalAfterCommentTest_1()
{
  QString docText("\n TestCase{\n Declaration{ name: myTestCase;\n\n /*comment*/ ");

  ComCreateTestCaseProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(8, propCommand.testCaseProposals().count());

  DslProposal proposal = propCommand.testCaseProposals().at(0);
  QCOMPARE(QString("Attribute"), proposal.proposalText);
  QCOMPARE((int)Attribute, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(1);
  QCOMPARE(QString("Check"), proposal.proposalText);
  QCOMPARE((int)Check, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(2);
  QCOMPARE(QString("Component"), proposal.proposalText);
  QCOMPARE((int)Component, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(3);
  QCOMPARE(QString("Signal"), proposal.proposalText);
  QCOMPARE((int)Signal, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(4);
  QCOMPARE(QString("enabled"), proposal.proposalText);
  QCOMPARE((int)Enabled, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(5);
  QCOMPARE(QString("name"), proposal.proposalText);
  QCOMPARE((int)Name, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(6);
  QCOMPARE(QString("uuid"), proposal.proposalText);
  QCOMPARE(0, proposal.proposalType);

  proposal = propCommand.testCaseProposals().at(7);
  QCOMPARE(QString("}"), proposal.proposalText);
  QCOMPARE((int)RightBrace, proposal.proposalType);

  return;
}

void TestCaseProposalsTest::testcaseProposalAfterCommentTest_2()
{
  QString docText("/*it has to start with TestCase */");

  ComCreateTestCaseProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(2, propCommand.testCaseProposals().count());

  DslProposal firstProposal = propCommand.testCaseProposals().at(0);
  QCOMPARE(QString("TestCase"), firstProposal.proposalText);
  QCOMPARE((int)TestCase, firstProposal.proposalType);

  DslProposal secProposal = propCommand.testCaseProposals().at(1);
  QCOMPARE(QString("import"), secProposal.proposalText);
  QCOMPARE((int)Import, secProposal.proposalType);

  return;
}

void TestCaseProposalsTest::testcaseProposalAfterCommentTest_3()
{
  QString docText("/*it has to start with 'TestCase' */");

  ComCreateTestCaseProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(2, propCommand.testCaseProposals().count());

  DslProposal firstProposal = propCommand.testCaseProposals().at(0);
  QCOMPARE(QString("TestCase"), firstProposal.proposalText);
  QCOMPARE((int)TestCase, firstProposal.proposalType);

  DslProposal secProposal = propCommand.testCaseProposals().at(1);
  QCOMPARE(QString("import"), secProposal.proposalText);
  QCOMPARE((int)Import, secProposal.proposalType);

  return;
}

void TestCaseProposalsTest::testcaseProposalAfterCommentTest_4()
{
  QString docText("/*it has to start with \"TestCase\" */");

  ComCreateTestCaseProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(2, propCommand.testCaseProposals().count());

  DslProposal firstProposal = propCommand.testCaseProposals().at(0);
  QCOMPARE(QString("TestCase"), firstProposal.proposalText);
  QCOMPARE((int)TestCase, firstProposal.proposalType);

  DslProposal secProposal = propCommand.testCaseProposals().at(1);
  QCOMPARE(QString("import"), secProposal.proposalText);
  QCOMPARE((int)Import, secProposal.proposalType);

  return;
}

void TestCaseProposalsTest::testcaseProposalWithinCommentTest_1()
{
  QString docText("\n TestCase{\n Declaration{name: myTestCase;\n\n //comment  ");

  ComCreateTestCaseProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(0, propCommand.testCaseProposals().count());

  return;
}

void TestCaseProposalsTest::testcaseProposalWithinCommentTest_2()
{
  QString docText("\n TestCase{\n name: myTestCase;\n\n /*comment \n further comment \n ");

  ComCreateTestCaseProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(0, propCommand.testCaseProposals().count());

  return;
}

QTEST_GUILESS_MAIN(TestCaseProposalsTest)

#include "tst_testcaseproposals.moc"
