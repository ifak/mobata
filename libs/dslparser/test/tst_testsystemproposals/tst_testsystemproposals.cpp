#include <QtTest>

#include <dslparser/testsystem/comcreatetestsystemproposals.hpp>
#include <dslparser/testsystem/combuildtestsystemmodel.hpp>

#include <mobata/model/ts/testsystemitem.hpp>

#include <mobata/memory_leak_start.hpp>

using namespace dslparser;
using namespace dslparser::testsystem;
using namespace model::ts;

class TestSystemProposalsTest
    : public QObject
{
  Q_OBJECT

public:
  TestSystemProposalsTest();

private Q_SLOTS:
  void initTest();
  void cleanupTest();
  void testsystemProposalEmptyTextTest_1();
  void testsystemProposalTest_1();
  void testsystemProposalTest_2();
  void testsystemProposalTest_2_1();
  void testsystemProposalTest_3();
  void testsystemProposalTest_4();
  void testsystemProposalTest_5();
  void testsystemProposalTest_6();
  void testsystemProposalTest_7();
  void testsystemProposalTest_8();
  void testsystemProposalTest_9();
  void testsystemProposalTest_10();
  void testsystemProposalTest_11();
  void includeTestSystemProposalTest1();
  void includeTestSystemProposalTest2();
  void includeTestSystemProposalTest3();
  void includeTestSystemProposalTest4();
  void includeTestSystemProposalErrorTest();
  void LinkTestSystemProposalTest1();
  void LinkTestSystemProposalTest2();
  void LinkTestSystemProposalErrorTest();
  void testsystemProposalAfterCommentTest_1();
  void testsystemProposalAfterCommentTest_2();
  void testsystemProposalAfterCommentTest_3();
  void testsystemProposalAfterCommentTest_4();
  void testsystemProposalWithinCommentTest_1();
  void testsystemProposalWithinCommentTest_2();
  void testsystemProposalAfterPortDecl_1();
};

TestSystemProposalsTest::TestSystemProposalsTest()
{}

void TestSystemProposalsTest::initTest()
{}

void TestSystemProposalsTest::cleanupTest()
{}

void TestSystemProposalsTest::testsystemProposalEmptyTextTest_1()
{
  QString docText("");

  ComCreateTestSystemProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(2, command.testSystemProposals().count());

  DslProposal firstProposal = command.testSystemProposals().at(0);
  QCOMPARE(QString("TestSystem"), firstProposal.proposalText);
  QCOMPARE((int)TestSystem, firstProposal.proposalType);

  DslProposal secProposal = command.testSystemProposals().at(1);
  QCOMPARE(QString("import"), secProposal.proposalText);
  QCOMPARE((int)Import, secProposal.proposalType);

  return;
}

void TestSystemProposalsTest::testsystemProposalTest_1()
{
  QString docText(L'\u2029');
  docText+=" ";
  docText+=QChar(L'\u2029');
  docText+=" ";

  ComCreateTestSystemProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(2, command.testSystemProposals().count());

  DslProposal firstProposal = command.testSystemProposals().at(0);
  QCOMPARE(QString("TestSystem"), firstProposal.proposalText);
  QCOMPARE((int)TestSystem, firstProposal.proposalType);

  DslProposal secProposal = command.testSystemProposals().at(1);
  QCOMPARE(QString("import"), secProposal.proposalText);
  QCOMPARE((int)Import, secProposal.proposalType);
  return;
}

void TestSystemProposalsTest::testsystemProposalTest_2()
{
  QString docText(L'\u2029');
  docText+=" ";
  docText+=QChar(L'\u2029');
  docText+=" TestSystem";

  ComCreateTestSystemProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(1, command.testSystemProposals().count());

  DslProposal firstProposal = command.testSystemProposals().at(0);
  QCOMPARE(QString("{"), firstProposal.proposalText);
  QCOMPARE((int)LeftBrace, firstProposal.proposalType);

  return;
}

void TestSystemProposalsTest::testsystemProposalTest_2_1()
{
  QString docText("TestSystem");

  ComCreateTestSystemProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(1, command.testSystemProposals().count());

  DslProposal firstProposal = command.testSystemProposals().at(0);
  QCOMPARE(QString("{"), firstProposal.proposalText);
  QCOMPARE((int)LeftBrace, firstProposal.proposalType);

  return;
}

void TestSystemProposalsTest::testsystemProposalTest_3()
{
  QString docText("TestSystem{");

  ComCreateTestSystemProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(1, command.testSystemProposals().count());

  DslProposal firstProposal = command.testSystemProposals().at(0);
  QCOMPARE(QString("name"), firstProposal.proposalText);
  QCOMPARE((int)Name, firstProposal.proposalType);

  return;
}

void TestSystemProposalsTest::testsystemProposalTest_4()
{
  QString docText("TestSystem{name");

  ComCreateTestSystemProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(1, command.testSystemProposals().count());

  DslProposal firstProposal = command.testSystemProposals().at(0);
  QCOMPARE(QString(":"), firstProposal.proposalText);
  QCOMPARE((int)Colon, firstProposal.proposalType);

  return;
}

void TestSystemProposalsTest::testsystemProposalTest_5()
{
  QString docText("TestSystem{name:");

  ComCreateTestSystemProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.testSystemProposals().count());

  return;
}

void TestSystemProposalsTest::testsystemProposalTest_6()
{
  QString docText("TestSystem{name:myTestSystem; ");

  ComCreateTestSystemProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(4, command.testSystemProposals().count());

  DslProposal proposal = command.testSystemProposals().at(0);
  QCOMPARE(QString("Attribute"), proposal.proposalText);
  QCOMPARE((int)Attribute, proposal.proposalType);

  proposal = command.testSystemProposals().at(1);
  QCOMPARE(QString("Link"), proposal.proposalText);
  QCOMPARE((int)Link, proposal.proposalType);

  proposal = command.testSystemProposals().at(2);
  QCOMPARE(QString("TestComponent"), proposal.proposalText);
  QCOMPARE((int)TestComponent, proposal.proposalType);

  proposal = command.testSystemProposals().at(3);
  QCOMPARE(QString("}"), proposal.proposalText);
  QCOMPARE((int)RightBrace, proposal.proposalType);

  return;
}

void TestSystemProposalsTest::testsystemProposalTest_7()
{
  QString docText("TestSystem{name:myTestSystem; TestComponent{name: comp1;} ");

  ComCreateTestSystemProposals command(docText);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(4, command.testSystemProposals().count());

  DslProposal proposal = command.testSystemProposals().at(0);
  QCOMPARE(QString("Attribute"), proposal.proposalText);
  QCOMPARE((int)Attribute, proposal.proposalType);

  proposal = command.testSystemProposals().at(1);
  QCOMPARE(QString("Link"), proposal.proposalText);
  QCOMPARE((int)Link, proposal.proposalType);

  proposal = command.testSystemProposals().at(2);
  QCOMPARE(QString("TestComponent"), proposal.proposalText);
  QCOMPARE((int)TestComponent, proposal.proposalType);

  proposal = command.testSystemProposals().at(3);
  QCOMPARE(QString("}"), proposal.proposalText);
  QCOMPARE((int)RightBrace, proposal.proposalType);

  return;
}

void TestSystemProposalsTest::testsystemProposalTest_8()
{
  QString docText("TestSystem{name:myTestSystem; TestComponent{name: p1;");

  ComCreateTestSystemProposals command(docText);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(4, command.testSystemProposals().count());

  DslProposal proposal = command.testSystemProposals().at(0);
  QCOMPARE(QString("Attribute"), proposal.proposalText);
  QCOMPARE((int)Attribute, proposal.proposalType);

  proposal = command.testSystemProposals().at(1);
  QCOMPARE(QString("Port"), proposal.proposalText);
  QCOMPARE((int)Port, proposal.proposalType);

  proposal = command.testSystemProposals().at(2);
  QCOMPARE(QString("enabled"), proposal.proposalText);
  QCOMPARE((int)Enabled, proposal.proposalType);

  proposal = command.testSystemProposals().at(3);
  QCOMPARE(QString("}"), proposal.proposalText);
  QCOMPARE((int)RightBrace, proposal.proposalType);

  return;
}

void TestSystemProposalsTest::testsystemProposalTest_9()
{
  QString docText("TestSystem{name:myTestSystem; TestComponent{name: comp1; Port p1");

  ComCreateTestSystemProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(2, propCommand.testSystemProposals().count());

  DslProposal proposal = propCommand.testSystemProposals().at(0);
  QCOMPARE(QString(","), proposal.proposalText);
  QCOMPARE((int)Comma, proposal.proposalType);

  proposal = propCommand.testSystemProposals().at(1);
  QCOMPARE(QString(";"), proposal.proposalText);
  QCOMPARE((int)Semi, proposal.proposalType);

  return;
}

void TestSystemProposalsTest::testsystemProposalTest_10()
{
  QString docText("TestSystem{name:myTestSystem; TestComponent{name: comp1; Port p1,p2");

  ComCreateTestSystemProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(2, propCommand.testSystemProposals().count());

  DslProposal proposal = propCommand.testSystemProposals().at(0);
  QCOMPARE(QString(","), proposal.proposalText);
  QCOMPARE((int)Comma, proposal.proposalType);

  proposal = propCommand.testSystemProposals().at(1);
  QCOMPARE(QString(";"), proposal.proposalText);
  QCOMPARE((int)Semi, proposal.proposalType);

  return;
}

void TestSystemProposalsTest::testsystemProposalTest_11()
{
  QString docText("TestSystem{name:myTestSystem; TestComponent{name: comp1; Port p1;");

  ComCreateTestSystemProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(4, propCommand.testSystemProposals().count());

  DslProposal proposal = propCommand.testSystemProposals().at(0);
  QCOMPARE(QString("Attribute"), proposal.proposalText);
  QCOMPARE((int)Attribute, proposal.proposalType);

  proposal = propCommand.testSystemProposals().at(1);
  QCOMPARE(QString("Port"), proposal.proposalText);
  QCOMPARE((int)Port, proposal.proposalType);

  proposal = propCommand.testSystemProposals().at(2);
  QCOMPARE(QString("enabled"), proposal.proposalText);
  QCOMPARE((int)Enabled, proposal.proposalType);

  proposal = propCommand.testSystemProposals().at(3);
  QCOMPARE(QString("}"), proposal.proposalText);
  QCOMPARE((int)RightBrace, proposal.proposalType);

  return;
}

void TestSystemProposalsTest::includeTestSystemProposalTest1(){
    QString praefix = ":/Examples/";
    QString filename = praefix + "testpath/example2.testsystem";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        qDebug()<<"file '"<<filename<<"' could not be opended!";
    QString docText(file.readAll());

    ComCreateTestSystemProposals propCommand(docText,praefix);
    QString errorString;
    bool result = propCommand.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(5, propCommand.testSystemProposals().size());

    DslProposal proposal = propCommand.testSystemProposals().at(0);
    QCOMPARE(QString("example1.testsystem"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    proposal = propCommand.testSystemProposals().at(1);
    QCOMPARE(QString("example1_2.testsystem"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    proposal = propCommand.testSystemProposals().at(2);
    QCOMPARE(QString("example1_3.testsystem"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    proposal = propCommand.testSystemProposals().at(3);
    QCOMPARE(QString("sutExample.sut"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    proposal = propCommand.testSystemProposals().at(4);
    QCOMPARE(QString("testpath"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);
}

void TestSystemProposalsTest::includeTestSystemProposalTest2(){
    QString praefix = ":/Examples/";
    QString filename = praefix + "testpath/example3.testsystem";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        qDebug()<<"file '"<<filename<<"' could not be opended!";
    QString docText(file.readAll());

    ComCreateTestSystemProposals propCommand(docText,praefix);
    QString errorString;
    bool result = propCommand.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(7,propCommand.testSystemProposals().size());

    DslProposal proposal = propCommand.testSystemProposals().at(0);
    QCOMPARE(QString("example2.testsystem"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    proposal = propCommand.testSystemProposals().at(1);
    QCOMPARE(QString("example3.testsystem"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    proposal = propCommand.testSystemProposals().at(2);
    QCOMPARE(QString("example4.testsystem"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    proposal = propCommand.testSystemProposals().at(3);
    QCOMPARE(QString("example5.testsystem"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    proposal = propCommand.testSystemProposals().at(4);
    QCOMPARE(QString("sutExample2.sut"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    proposal = propCommand.testSystemProposals().at(5);
    QCOMPARE(QString("sutExample3.sut"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    proposal = propCommand.testSystemProposals().at(6);
    QCOMPARE(QString("sutExample4.sut"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);
}

void TestSystemProposalsTest::includeTestSystemProposalTest3(){
    QString praefix = ":/Examples/";
    QString filename = praefix + "testpath/example4.testsystem";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        qDebug()<<"file '"<<filename<<"' could not be opended!";
    QString docText(file.readAll());

    ComCreateTestSystemProposals propCommand(docText,praefix);
    QString errorString;
    bool result = propCommand.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(3,propCommand.testSystemProposals().size());

    DslProposal proposal = propCommand.testSystemProposals().at(0);
    QCOMPARE(QString("2.sut"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    proposal = propCommand.testSystemProposals().at(1);
    QCOMPARE(QString("3.sut"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    proposal = propCommand.testSystemProposals().at(2);
    QCOMPARE(QString("4.sut"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);
}

void TestSystemProposalsTest::includeTestSystemProposalTest4(){
    QString praefix = ":/Examples/";
    QString docText("import <testpath/../");

    ComCreateTestSystemProposals propCommand(docText,praefix);
    QString errorString;
    bool result = propCommand.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(5,propCommand.testSystemProposals().size());

    DslProposal proposal = propCommand.testSystemProposals().at(0);
    QCOMPARE(QString("example1.testsystem"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    proposal = propCommand.testSystemProposals().at(1);
    QCOMPARE(QString("example1_2.testsystem"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    proposal = propCommand.testSystemProposals().at(2);
    QCOMPARE(QString("example1_3.testsystem"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    proposal = propCommand.testSystemProposals().at(3);
    QCOMPARE(QString("sutExample.sut"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    proposal = propCommand.testSystemProposals().at(4);
    QCOMPARE(QString("testpath"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);
}

void TestSystemProposalsTest::includeTestSystemProposalErrorTest(){
    QString praefix = ":/Examples/";
    QString docText("import <testpath/huivva/");

    ComCreateTestSystemProposals propCommand(docText,praefix);
    QString errorString;
    bool result = propCommand.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(0,propCommand.testSystemProposals().size());

    return;
}

void TestSystemProposalsTest::LinkTestSystemProposalTest1(){
    QString praefix = ":/Examples/";
    QString filename = praefix + "example1.testsystem";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        qDebug()<<"file '"<<filename<<"' could not be opended!";
    QString docText(file.readAll());

    ComCreateTestSystemProposals propCommand(docText,praefix);
    QString errorString;
    bool result = propCommand.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(3,propCommand.testSystemProposals().size());

    DslProposal proposal = propCommand.testSystemProposals().at(0);
    QCOMPARE(QString("_defaultPort"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    proposal = propCommand.testSystemProposals().at(1);
    QCOMPARE(QString("pEvaluation"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    proposal = propCommand.testSystemProposals().at(2);
    QCOMPARE(QString("pTestSystem"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);
}

void TestSystemProposalsTest::LinkTestSystemProposalTest2(){
    QString praefix = ":/Examples/";
    QString filename = praefix + "example1_2.testsystem";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        qDebug()<<"file '"<<filename<<"' could not be opended!";
    QString docText(file.readAll());

    ComCreateTestSystemProposals propCommand(docText,praefix);
    QString errorString;
    bool result = propCommand.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(2,propCommand.testSystemProposals().size());

    DslProposal proposal = propCommand.testSystemProposals().at(0);
    QCOMPARE(QString("_defaultPort"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    proposal = propCommand.testSystemProposals().at(1);
    QCOMPARE(QString("pRseApp"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

}

void TestSystemProposalsTest::LinkTestSystemProposalErrorTest(){
    QString praefix = ":/Examples/";
    QString filename = praefix + "example1_3.testsystem";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        qDebug()<<"file '"<<filename<<"' could not be opended!";
    QString docText(file.readAll());

    ComCreateTestSystemProposals propCommand(docText,praefix);
    QString errorString;
    bool result = propCommand.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(0,propCommand.testSystemProposals().size());
}

void TestSystemProposalsTest::testsystemProposalAfterCommentTest_1()
{
  QString docText("\n TestSystem{\n name: myTestSystem;\n\n /*comment*/ TestComponent{ ");

  ComCreateTestSystemProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(1, propCommand.testSystemProposals().count());

  DslProposal proposal = propCommand.testSystemProposals().at(0);
  QCOMPARE(QString("name"), proposal.proposalText);
  QCOMPARE(proposal.proposalType, (int)Name);

  return;
}

void TestSystemProposalsTest::testsystemProposalAfterCommentTest_2()
{
  QString docText("/*it has to start with TestSystem */");

  ComCreateTestSystemProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(2, propCommand.testSystemProposals().count());

  DslProposal firstProposal = propCommand.testSystemProposals().at(0);
  QCOMPARE(QString("TestSystem"), firstProposal.proposalText);
  QCOMPARE((int)TestSystem, firstProposal.proposalType);

  DslProposal secProposal = propCommand.testSystemProposals().at(1);
  QCOMPARE(QString("import"), secProposal.proposalText);
  QCOMPARE((int)Import, secProposal.proposalType);

  return;
}

void TestSystemProposalsTest::testsystemProposalAfterCommentTest_3()
{
  QString docText("/*it has to start with 'TestSystem' */");

  ComCreateTestSystemProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(2, propCommand.testSystemProposals().count());

  DslProposal firstProposal = propCommand.testSystemProposals().at(0);
  QCOMPARE(QString("TestSystem"), firstProposal.proposalText);
  QCOMPARE((int)TestSystem, firstProposal.proposalType);

  DslProposal secProposal = propCommand.testSystemProposals().at(1);
  QCOMPARE(QString("import"), secProposal.proposalText);
  QCOMPARE((int)Import, secProposal.proposalType);

  return;
}

void TestSystemProposalsTest::testsystemProposalAfterCommentTest_4()
{
  QString docText("/*it has to start with \"TestSystem\" */");

  ComCreateTestSystemProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(2, propCommand.testSystemProposals().count());

  DslProposal firstProposal = propCommand.testSystemProposals().at(0);
  QCOMPARE(QString("TestSystem"), firstProposal.proposalText);
  QCOMPARE((int)TestSystem, firstProposal.proposalType);

  DslProposal secProposal = propCommand.testSystemProposals().at(1);
  QCOMPARE(QString("import"), secProposal.proposalText);
  QCOMPARE((int)Import, secProposal.proposalType);

  return;
}

void TestSystemProposalsTest::testsystemProposalWithinCommentTest_1()
{
  QString docText("\n TestSystem{\n name: myTestSystem;\n\n //comment  ");

  ComCreateTestSystemProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(0, propCommand.testSystemProposals().count());

  return;
}

void TestSystemProposalsTest::testsystemProposalWithinCommentTest_2()
{
  QString docText("\n TestSystem{\n name: myTestSystem;\n\n /*comment \n further comment \n ");

  ComCreateTestSystemProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(0, propCommand.testSystemProposals().count());

  return;
}

void TestSystemProposalsTest::testsystemProposalAfterPortDecl_1()
{
  QString docText("\n TestSystem{\n name: myTestSystem;\n\n //commenting something//\n  TestComponent{ ");

  ComCreateTestSystemProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(1, propCommand.testSystemProposals().count());

  DslProposal proposal = propCommand.testSystemProposals().at(0);
  QCOMPARE(QString("name"), proposal.proposalText);
  QCOMPARE(proposal.proposalType, (int)Name);

  return;
}

QTEST_GUILESS_MAIN(TestSystemProposalsTest)

#include "tst_testsystemproposals.moc"
