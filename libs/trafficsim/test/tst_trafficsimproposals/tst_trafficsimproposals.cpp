#include <QtTest>

#include <trafficsim/comcreatetrafficsimproposals.hpp>
#include <trafficsim/combuildtrafficsimmodel.hpp>
#include <trafficsim/trafficsimmodel.hpp>

using namespace dslparser;
using namespace trafficsim;

class TrafficSimProposalsTest
    : public QObject
{
  Q_OBJECT

public:
  TrafficSimProposalsTest();

private Q_SLOTS:
  void initTest();
  void cleanupTest();
  void trafficsimProposalEmptyTextTest_1();
  void trafficsimProposalTest_1();
  void trafficsimProposalTest_2();
  void trafficsimProposalTest_2_1();
  void trafficsimProposalTest_3();
  void trafficsimProposalTest_4();
  void trafficsimProposalTest_5();
  void trafficsimProposalTest_6();
  void trafficsimProposalTest_7();
  void trafficsimProposalTest_8();
  void trafficsimProposalTest_9();
  void trafficsimProposalTest_10();
  void trafficsimProposalTest_11();
  void includeTrafficSimProposalTest1();
  void includeTrafficSimProposalTest2();
  void includeTrafficSimProposalTest3();
  void includeTrafficSimProposalTest4();
  void includeTrafficSimProposalErrorTest();
  void LinkTrafficSimProposalTest1();
  void LinkTrafficSimProposalTest2();
  void LinkTrafficSimProposalErrorTest();
  void trafficsimProposalAfterCommentTest_1();
  void trafficsimProposalAfterCommentTest_2();
  void trafficsimProposalAfterCommentTest_3();
  void trafficsimProposalAfterCommentTest_4();
  void trafficsimProposalWithinCommentTest_1();
  void trafficsimProposalWithinCommentTest_2();
  void trafficsimProposalAfterPortDecl_1();
};

TrafficSimProposalsTest::TrafficSimProposalsTest()
{}

void TrafficSimProposalsTest::initTest()
{}

void TrafficSimProposalsTest::cleanupTest()
{}

void TrafficSimProposalsTest::trafficsimProposalEmptyTextTest_1()
{
  QString docText("");

  ComCreateTrafficSimProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(2, command.TrafficSimProposals().count());

  TrafficSimProposal firstProposal = command.TrafficSimProposals().at(0);
  QCOMPARE(QString("TrafficSim"), firstProposal.proposalText);
  QCOMPARE((int)TrafficSim, firstProposal.proposalType);

  TrafficSimProposal secProposal = command.TrafficSimProposals().at(1);
  QCOMPARE(QString("import"), secProposal.proposalText);
  QCOMPARE((int)Import, secProposal.proposalType);

  return;
}

void TrafficSimProposalsTest::trafficsimProposalTest_1()
{
  QString docText(L'\u2029');
  docText+=" ";
  docText+=QChar(L'\u2029');
  docText+=" ";

  ComCreateTrafficSimProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(2, command.TrafficSimProposals().count());

  TrafficSimProposal firstProposal = command.TrafficSimProposals().at(0);
  QCOMPARE(QString("TrafficSim"), firstProposal.proposalText);
  QCOMPARE((int)TrafficSim, firstProposal.proposalType);

  TrafficSimProposal secProposal = command.TrafficSimProposals().at(1);
  QCOMPARE(QString("import"), secProposal.proposalText);
  QCOMPARE((int)Import, secProposal.proposalType);
  return;
}

void TrafficSimProposalsTest::trafficsimProposalTest_2()
{
  QString docText(L'\u2029');
  docText+=" ";
  docText+=QChar(L'\u2029');
  docText+=" TrafficSim";

  ComCreateTrafficSimProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(1, command.TrafficSimProposals().count());

  TrafficSimProposal firstProposal = command.TrafficSimProposals().at(0);
  QCOMPARE(QString("{"), firstProposal.proposalText);
  QCOMPARE((int)LeftBrace, firstProposal.proposalType);

  return;
}

void TrafficSimProposalsTest::trafficsimProposalTest_2_1()
{
  QString docText("TrafficSim");

  ComCreateTrafficSimProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(1, command.TrafficSimProposals().count());

  TrafficSimProposal firstProposal = command.TrafficSimProposals().at(0);
  QCOMPARE(QString("{"), firstProposal.proposalText);
  QCOMPARE((int)LeftBrace, firstProposal.proposalType);

  return;
}

void TrafficSimProposalsTest::trafficsimProposalTest_3()
{
  QString docText("TrafficSim{");

  ComCreateTrafficSimProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(1, command.TrafficSimProposals().count());

  TrafficSimProposal firstProposal = command.TrafficSimProposals().at(0);
  QCOMPARE(QString("name"), firstProposal.proposalText);
  QCOMPARE((int)Name, firstProposal.proposalType);

  return;
}

void TrafficSimProposalsTest::trafficsimProposalTest_4()
{
  QString docText("TrafficSim{name");

  ComCreateTrafficSimProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(1, command.TrafficSimProposals().count());

  TrafficSimProposal firstProposal = command.TrafficSimProposals().at(0);
  QCOMPARE(QString(":"), firstProposal.proposalText);
  QCOMPARE((int)Colon, firstProposal.proposalType);

  return;
}

void TrafficSimProposalsTest::trafficsimProposalTest_5()
{
  QString docText("TrafficSim{name:");

  ComCreateTrafficSimProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.TrafficSimProposals().count());

  return;
}

void TrafficSimProposalsTest::trafficsimProposalTest_6()
{
  QString docText("TrafficSim{name:myTrafficSim; ");

  ComCreateTrafficSimProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(4, command.TrafficSimProposals().count());

  TrafficSimProposal proposal = command.TrafficSimProposals().at(0);
  QCOMPARE(QString("Attribute"), proposal.proposalText);
  QCOMPARE((int)Attribute, proposal.proposalType);

  proposal = command.TrafficSimProposals().at(1);
  QCOMPARE(QString("Link"), proposal.proposalText);
  QCOMPARE((int)Link, proposal.proposalType);

  proposal = command.TrafficSimProposals().at(2);
  QCOMPARE(QString("TestComponent"), proposal.proposalText);
  QCOMPARE((int)TestComponent, proposal.proposalType);

  proposal = command.TrafficSimProposals().at(3);
  QCOMPARE(QString("}"), proposal.proposalText);
  QCOMPARE((int)RightBrace, proposal.proposalType);

  return;
}

void TrafficSimProposalsTest::trafficsimProposalTest_7()
{
  QString docText("TrafficSim{name:myTrafficSim; TestComponent{name: comp1;} ");

  ComCreateTrafficSimProposals command(docText);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(4, command.TrafficSimProposals().count());

  TrafficSimProposal proposal = command.TrafficSimProposals().at(0);
  QCOMPARE(QString("Attribute"), proposal.proposalText);
  QCOMPARE((int)Attribute, proposal.proposalType);

  proposal = command.TrafficSimProposals().at(1);
  QCOMPARE(QString("Link"), proposal.proposalText);
  QCOMPARE((int)Link, proposal.proposalType);

  proposal = command.TrafficSimProposals().at(2);
  QCOMPARE(QString("TestComponent"), proposal.proposalText);
  QCOMPARE((int)TestComponent, proposal.proposalType);

  proposal = command.TrafficSimProposals().at(3);
  QCOMPARE(QString("}"), proposal.proposalText);
  QCOMPARE((int)RightBrace, proposal.proposalType);

  return;
}

void TrafficSimProposalsTest::trafficsimProposalTest_8()
{
  QString docText("TrafficSim{name:myTrafficSim; TestComponent{name: p1;");

  ComCreateTrafficSimProposals command(docText);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(4, command.TrafficSimProposals().count());

  TrafficSimProposal proposal = command.TrafficSimProposals().at(0);
  QCOMPARE(QString("Attribute"), proposal.proposalText);
  QCOMPARE((int)Attribute, proposal.proposalType);

  proposal = command.TrafficSimProposals().at(1);
  QCOMPARE(QString("Port"), proposal.proposalText);
  QCOMPARE((int)Port, proposal.proposalType);

  proposal = command.TrafficSimProposals().at(2);
  QCOMPARE(QString("enabled"), proposal.proposalText);
  QCOMPARE((int)Enabled, proposal.proposalType);

  proposal = command.TrafficSimProposals().at(3);
  QCOMPARE(QString("}"), proposal.proposalText);
  QCOMPARE((int)RightBrace, proposal.proposalType);

  return;
}

void TrafficSimProposalsTest::trafficsimProposalTest_9()
{
  QString docText("TrafficSim{name:myTrafficSim; TestComponent{name: comp1; Port p1");

  ComCreateTrafficSimProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(2, propCommand.TrafficSimProposals().count());

  TrafficSimProposal proposal = propCommand.TrafficSimProposals().at(0);
  QCOMPARE(QString(","), proposal.proposalText);
  QCOMPARE((int)Comma, proposal.proposalType);

  proposal = propCommand.TrafficSimProposals().at(1);
  QCOMPARE(QString(";"), proposal.proposalText);
  QCOMPARE((int)Semi, proposal.proposalType);

  return;
}

void TrafficSimProposalsTest::trafficsimProposalTest_10()
{
  QString docText("TrafficSim{name:myTrafficSim; TestComponent{name: comp1; Port p1,p2");

  ComCreateTrafficSimProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(2, propCommand.TrafficSimProposals().count());

  TrafficSimProposal proposal = propCommand.TrafficSimProposals().at(0);
  QCOMPARE(QString(","), proposal.proposalText);
  QCOMPARE((int)Comma, proposal.proposalType);

  proposal = propCommand.TrafficSimProposals().at(1);
  QCOMPARE(QString(";"), proposal.proposalText);
  QCOMPARE((int)Semi, proposal.proposalType);

  return;
}

void TrafficSimProposalsTest::trafficsimProposalTest_11()
{
  QString docText("TrafficSim{name:myTrafficSim; TestComponent{name: comp1; Port p1;");

  ComCreateTrafficSimProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(4, propCommand.TrafficSimProposals().count());

  TrafficSimProposal proposal = propCommand.TrafficSimProposals().at(0);
  QCOMPARE(QString("Attribute"), proposal.proposalText);
  QCOMPARE((int)Attribute, proposal.proposalType);

  proposal = propCommand.TrafficSimProposals().at(1);
  QCOMPARE(QString("Port"), proposal.proposalText);
  QCOMPARE((int)Port, proposal.proposalType);

  proposal = propCommand.TrafficSimProposals().at(2);
  QCOMPARE(QString("enabled"), proposal.proposalText);
  QCOMPARE((int)Enabled, proposal.proposalType);

  proposal = propCommand.TrafficSimProposals().at(3);
  QCOMPARE(QString("}"), proposal.proposalText);
  QCOMPARE((int)RightBrace, proposal.proposalType);

  return;
}

void TrafficSimProposalsTest::includeTrafficSimProposalTest1(){
    QString praefix = ":/Examples/";
    QString filename = praefix + "testpath/example2.trafficsim";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        qDebug()<<"file '"<<filename<<"' could not be opended!";
    QString docText(file.readAll());

    ComCreateTrafficSimProposals propCommand(docText,praefix);
    QString errorString;
    bool result = propCommand.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(6,propCommand.TrafficSimProposals().size());

    TrafficSimProposal proposal = propCommand.TrafficSimProposals().at(0);
    QCOMPARE(QString(".."), proposal.proposalText);
    QCOMPARE((int)Range, proposal.proposalType);

    proposal = propCommand.TrafficSimProposals().at(1);
    QCOMPARE(QString("example1.trafficsim"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.TrafficSimProposals().at(2);
    QCOMPARE(QString("example1_2.trafficsim"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.TrafficSimProposals().at(3);
    QCOMPARE(QString("example1_3.trafficsim"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.TrafficSimProposals().at(4);
    QCOMPARE(QString("sutExample.sut"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.TrafficSimProposals().at(5);
    QCOMPARE(QString("testpath"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);
}

void TrafficSimProposalsTest::includeTrafficSimProposalTest2(){
    QString praefix = ":/Examples/";
    QString filename = praefix + "testpath/example3.trafficsim";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        qDebug()<<"file '"<<filename<<"' could not be opended!";
    QString docText(file.readAll());

    ComCreateTrafficSimProposals propCommand(docText,praefix);
    QString errorString;
    bool result = propCommand.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(8,propCommand.TrafficSimProposals().size());

    TrafficSimProposal proposal = propCommand.TrafficSimProposals().at(0);
    QCOMPARE(QString(".."), proposal.proposalText);
    QCOMPARE((int)Range, proposal.proposalType);

    proposal = propCommand.TrafficSimProposals().at(1);
    QCOMPARE(QString("example2.trafficsim"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.TrafficSimProposals().at(2);
    QCOMPARE(QString("example3.trafficsim"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.TrafficSimProposals().at(3);
    QCOMPARE(QString("example4.trafficsim"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.TrafficSimProposals().at(4);
    QCOMPARE(QString("example5.trafficsim"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.TrafficSimProposals().at(5);
    QCOMPARE(QString("sutExample2.sut"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.TrafficSimProposals().at(6);
    QCOMPARE(QString("sutExample3.sut"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.TrafficSimProposals().at(7);
    QCOMPARE(QString("sutExample4.sut"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);
}

void TrafficSimProposalsTest::includeTrafficSimProposalTest3(){
    QString praefix = ":/Examples/";
    QString filename = praefix + "testpath/example4.trafficsim";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        qDebug()<<"file '"<<filename<<"' could not be opended!";
    QString docText(file.readAll());

    ComCreateTrafficSimProposals propCommand(docText,praefix);
    QString errorString;
    bool result = propCommand.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(4,propCommand.TrafficSimProposals().size());

    TrafficSimProposal proposal = propCommand.TrafficSimProposals().at(0);
    QCOMPARE(QString(".."), proposal.proposalText);
    QCOMPARE((int)Range, proposal.proposalType);

    proposal = propCommand.TrafficSimProposals().at(1);
    QCOMPARE(QString("2.sut"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.TrafficSimProposals().at(2);
    QCOMPARE(QString("3.sut"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.TrafficSimProposals().at(3);
    QCOMPARE(QString("4.sut"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);
}

void TrafficSimProposalsTest::includeTrafficSimProposalTest4(){
    QString praefix = ":/Examples/";
    QString docText("import <testpath/../");

    ComCreateTrafficSimProposals propCommand(docText,praefix);
    QString errorString;
    bool result = propCommand.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(6,propCommand.TrafficSimProposals().size());

    TrafficSimProposal proposal = propCommand.TrafficSimProposals().at(0);
    QCOMPARE(QString(".."), proposal.proposalText);
    QCOMPARE((int)Range, proposal.proposalType);

    proposal = propCommand.TrafficSimProposals().at(1);
    QCOMPARE(QString("example1.trafficsim"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.TrafficSimProposals().at(2);
    QCOMPARE(QString("example1_2.trafficsim"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.TrafficSimProposals().at(3);
    QCOMPARE(QString("example1_3.trafficsim"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.TrafficSimProposals().at(4);
    QCOMPARE(QString("sutExample.sut"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.TrafficSimProposals().at(5);
    QCOMPARE(QString("testpath"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);
}

void TrafficSimProposalsTest::includeTrafficSimProposalErrorTest(){
    QString praefix = ":/Examples/";
    QString docText("import <testpath/huivva/");

    ComCreateTrafficSimProposals propCommand(docText,praefix);
    QString errorString;
    bool result = propCommand.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(1,propCommand.TrafficSimProposals().size());

    TrafficSimProposal proposal = propCommand.TrafficSimProposals().at(0);
    QCOMPARE(QString(".."), proposal.proposalText);
    QCOMPARE((int)Range, proposal.proposalType);
}

void TrafficSimProposalsTest::LinkTrafficSimProposalTest1(){
    QString praefix = ":/Examples/";
    QString filename = praefix + "example1.trafficsim";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        qDebug()<<"file '"<<filename<<"' could not be opended!";
    QString docText(file.readAll());

    ComCreateTrafficSimProposals propCommand(docText,praefix);
    QString errorString;
    bool result = propCommand.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(3,propCommand.TrafficSimProposals().size());

    TrafficSimProposal proposal = propCommand.TrafficSimProposals().at(0);
    QCOMPARE(QString("_defaultPort"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.TrafficSimProposals().at(1);
    QCOMPARE(QString("pEvaluation"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.TrafficSimProposals().at(2);
    QCOMPARE(QString("ptrafficsim"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);
}

void TrafficSimProposalsTest::LinkTrafficSimProposalTest2(){
    QString praefix = ":/Examples/";
    QString filename = praefix + "example1_2.trafficsim";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        qDebug()<<"file '"<<filename<<"' could not be opended!";
    QString docText(file.readAll());

    ComCreateTrafficSimProposals propCommand(docText,praefix);
    QString errorString;
    bool result = propCommand.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(2,propCommand.TrafficSimProposals().size());

    TrafficSimProposal proposal = propCommand.TrafficSimProposals().at(0);
    QCOMPARE(QString("_defaultPort"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.TrafficSimProposals().at(1);
    QCOMPARE(QString("pRseApp"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

}

void TrafficSimProposalsTest::LinkTrafficSimProposalErrorTest(){
    QString praefix = ":/Examples/";
    QString filename = praefix + "example1_3.trafficsim";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        qDebug()<<"file '"<<filename<<"' could not be opended!";
    QString docText(file.readAll());

    ComCreateTrafficSimProposals propCommand(docText,praefix);
    QString errorString;
    bool result = propCommand.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(0,propCommand.TrafficSimProposals().size());
}

void TrafficSimProposalsTest::trafficsimProposalAfterCommentTest_1()
{
  QString docText("\n TrafficSim{\n name: myTrafficSim;\n\n /*comment*/ TestComponent{ ");

  ComCreateTrafficSimProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(1, propCommand.TrafficSimProposals().count());

  TrafficSimProposal proposal = propCommand.TrafficSimProposals().at(0);
  QCOMPARE(QString("name"), proposal.proposalText);
  QCOMPARE(proposal.proposalType, (int)Name);

  return;
}

void TrafficSimProposalsTest::trafficsimProposalAfterCommentTest_2()
{
  QString docText("/*it has to start with TrafficSim */");

  ComCreateTrafficSimProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(2, propCommand.TrafficSimProposals().count());

  TrafficSimProposal firstProposal = propCommand.TrafficSimProposals().at(0);
  QCOMPARE(QString("TrafficSim"), firstProposal.proposalText);
  QCOMPARE((int)TrafficSim, firstProposal.proposalType);

  TrafficSimProposal secProposal = propCommand.TrafficSimProposals().at(1);
  QCOMPARE(QString("import"), secProposal.proposalText);
  QCOMPARE((int)Import, secProposal.proposalType);

  return;
}

void TrafficSimProposalsTest::trafficsimProposalAfterCommentTest_3()
{
  QString docText("/*it has to start with 'TrafficSim' */");

  ComCreateTrafficSimProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(2, propCommand.TrafficSimProposals().count());

  TrafficSimProposal firstProposal = propCommand.TrafficSimProposals().at(0);
  QCOMPARE(QString("TrafficSim"), firstProposal.proposalText);
  QCOMPARE((int)TrafficSim, firstProposal.proposalType);

  TrafficSimProposal secProposal = propCommand.TrafficSimProposals().at(1);
  QCOMPARE(QString("import"), secProposal.proposalText);
  QCOMPARE((int)Import, secProposal.proposalType);

  return;
}

void TrafficSimProposalsTest::trafficsimProposalAfterCommentTest_4()
{
  QString docText("/*it has to start with \"TrafficSim\" */");

  ComCreateTrafficSimProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(2, propCommand.TrafficSimProposals().count());

  TrafficSimProposal firstProposal = propCommand.TrafficSimProposals().at(0);
  QCOMPARE(QString("TrafficSim"), firstProposal.proposalText);
  QCOMPARE((int)TrafficSim, firstProposal.proposalType);

  TrafficSimProposal secProposal = propCommand.TrafficSimProposals().at(1);
  QCOMPARE(QString("import"), secProposal.proposalText);
  QCOMPARE((int)Import, secProposal.proposalType);

  return;
}

void TrafficSimProposalsTest::trafficsimProposalWithinCommentTest_1()
{
  QString docText("\n TrafficSim{\n name: myTrafficSim;\n\n //comment  ");

  ComCreateTrafficSimProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(0, propCommand.TrafficSimProposals().count());

  return;
}

void TrafficSimProposalsTest::trafficsimProposalWithinCommentTest_2()
{
  QString docText("\n TrafficSim{\n name: myTrafficSim;\n\n /*comment \n further comment \n ");

  ComCreateTrafficSimProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(0, propCommand.TrafficSimProposals().count());

  return;
}

void TrafficSimProposalsTest::trafficsimProposalAfterPortDecl_1()
{
  QString docText("\n TrafficSim{\n name: myTrafficSim;\n\n //commenting something//\n  TestComponent{ ");

  ComCreateTrafficSimProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(1, propCommand.TrafficSimProposals().count());

  TrafficSimProposal proposal = propCommand.TrafficSimProposals().at(0);
  QCOMPARE(QString("name"), proposal.proposalText);
  QCOMPARE(proposal.proposalType, (int)Name);

  return;
}

QTEST_APPLESS_MAIN(TrafficSimProposalsTest)

#include "tst_trafficsimproposals.moc"
