#include <QtTest>

#include <dslparser/sut/comcreatesutproposals.hpp>
#include <dslparser/sut/combuildsutmodel.hpp>

#include <mobata/model/ts/sutitem.hpp>

#include <mobata/memory_leak_start.hpp>

using namespace dslparser;
using namespace dslparser::sut;
using namespace model::ts;

class SutProposalsTest
    : public QObject
{
  Q_OBJECT

public:
  SutProposalsTest();

private Q_SLOTS:
  void initTest();
  void cleanupTest();
  void sutProposalEmptyTextTest_1();
  void sutProposalTest_1();
  void sutProposalTest_2();
  void sutProposalTest_2_1();
  void sutProposalTest_3();
  void sutProposalTest_4();
  void sutProposalTest_5();
  void sutProposalTest_6();
  void sutProposalTest_7();
  void sutProposalTest_8();
  void sutProposalTest_9();
  void sutProposalTest_10();
  void sutProposalTest_11();
  void sutProposalAfterCommentTest_1();
  void sutProposalAfterCommentTest_2();
  void sutProposalAfterCommentTest_3();
  void sutProposalAfterCommentTest_4();
  void sutProposalWithinCommentTest_1();
  void sutProposalWithinCommentTest_2();
  void sutProposalAfterPortDecl_1();
};

SutProposalsTest::SutProposalsTest()
{}

void SutProposalsTest::initTest()
{}

void SutProposalsTest::cleanupTest()
{}

void SutProposalsTest::sutProposalEmptyTextTest_1()
{
  QString docText("");

  ComCreateSutProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(1, command.sutProposals().count());

  DslProposal firstProposal = command.sutProposals().at(0);
  QCOMPARE(QString("Sut"), firstProposal.proposalText);
  QCOMPARE((int)Sut, firstProposal.proposalType);

  return;
}

void SutProposalsTest::sutProposalTest_1()
{
  QString docText(L'\u2029');
  docText+=" ";
  docText+=QChar(L'\u2029');
  docText+=" ";

  ComCreateSutProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(1, command.sutProposals().count());

  DslProposal firstProposal = command.sutProposals().at(0);
  QCOMPARE(QString("Sut"), firstProposal.proposalText);
  QCOMPARE((int)Sut, firstProposal.proposalType);

  return;
}

void SutProposalsTest::sutProposalTest_2()
{
  QString docText(L'\u2029');
  docText+=" ";
  docText+=QChar(L'\u2029');
  docText+=" Sut";

  ComCreateSutProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(1, command.sutProposals().count());

  DslProposal firstProposal = command.sutProposals().at(0);
  QCOMPARE(QString("{"), firstProposal.proposalText);
  QCOMPARE((int)LeftBrace, firstProposal.proposalType);

  return;
}

void SutProposalsTest::sutProposalTest_2_1()
{
  QString docText("Sut");

  ComCreateSutProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(1, command.sutProposals().count());

  DslProposal firstProposal = command.sutProposals().at(0);
  QCOMPARE(QString("{"), firstProposal.proposalText);
  QCOMPARE((int)LeftBrace, firstProposal.proposalType);

  return;
}

void SutProposalsTest::sutProposalTest_3()
{
  QString docText("Sut{");

  ComCreateSutProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(1, command.sutProposals().count());

  DslProposal firstProposal = command.sutProposals().at(0);
  QCOMPARE(QString("name"), firstProposal.proposalText);
  QCOMPARE((int)Name, firstProposal.proposalType);

  return;
}

void SutProposalsTest::sutProposalTest_4()
{
  QString docText("Sut{name");

  ComCreateSutProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(1, command.sutProposals().count());

  DslProposal firstProposal = command.sutProposals().at(0);
  QCOMPARE(QString(":"), firstProposal.proposalText);
  QCOMPARE((int)Colon, firstProposal.proposalType);

  return;
}

void SutProposalsTest::sutProposalTest_5()
{
  QString docText("Sut{name:");

  ComCreateSutProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(command.sutProposals().count(), 0);

  return;
}

void SutProposalsTest::sutProposalTest_6()
{
  QString docText("Sut{name:mySut; ");

  ComCreateSutProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(3, command.sutProposals().count());

  DslProposal proposal = command.sutProposals().at(0);
  QCOMPARE(QString("Attribute"), proposal.proposalText);
  QCOMPARE((int)Attribute, proposal.proposalType);

  proposal = command.sutProposals().at(1);
  QCOMPARE(QString("SutComponent"), proposal.proposalText);
  QCOMPARE((int)SutComponent, proposal.proposalType);

  proposal = command.sutProposals().at(2);
  QCOMPARE(QString("}"), proposal.proposalText);
  QCOMPARE((int)RightBrace, proposal.proposalType);

  return;
}

void SutProposalsTest::sutProposalTest_7()
{
  QString docText("Sut{name:mySut; SutComponent{name: comp1;} ");

  ComCreateSutProposals command(docText);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(3, command.sutProposals().count());

  DslProposal proposal = command.sutProposals().at(0);
  QCOMPARE(QString("Attribute"), proposal.proposalText);
  QCOMPARE((int)Attribute, proposal.proposalType);

  proposal = command.sutProposals().at(1);
  QCOMPARE(QString("SutComponent"), proposal.proposalText);
  QCOMPARE((int)SutComponent, proposal.proposalType);

  proposal = command.sutProposals().at(2);
  QCOMPARE(QString("}"), proposal.proposalText);
  QCOMPARE((int)RightBrace, proposal.proposalType);

  return;
}

void SutProposalsTest::sutProposalTest_8()
{
  QString docText("Sut{name:mySut; SutComponent{name: p1;");

  ComCreateSutProposals command(docText);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(3, command.sutProposals().count());

  DslProposal proposal = command.sutProposals().at(0);
  QCOMPARE(QString("Attribute"), proposal.proposalText);
  QCOMPARE((int)Attribute, proposal.proposalType);

  proposal = command.sutProposals().at(1);
  QCOMPARE(QString("Port"), proposal.proposalText);
  QCOMPARE((int)Port, proposal.proposalType);

  proposal = command.sutProposals().at(2);
  QCOMPARE(QString("}"), proposal.proposalText);
  QCOMPARE((int)RightBrace, proposal.proposalType);

  return;
}

void SutProposalsTest::sutProposalTest_9()
{
  QString docText("Sut{name:mySut; SutComponent{name: comp1; Port p1");

  ComCreateSutProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(2, propCommand.sutProposals().count());

  DslProposal proposal = propCommand.sutProposals().at(0);
  QCOMPARE(QString(","), proposal.proposalText);
  QCOMPARE((int)Comma, proposal.proposalType);

  proposal = propCommand.sutProposals().at(1);
  QCOMPARE(QString(";"), proposal.proposalText);
  QCOMPARE((int)Semi, proposal.proposalType);

  return;
}

void SutProposalsTest::sutProposalTest_10()
{
  QString docText("Sut{name:mySut; SutComponent{name: comp1; Port p1,p2");

  ComCreateSutProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(2, propCommand.sutProposals().count());

  DslProposal proposal = propCommand.sutProposals().at(0);
  QCOMPARE(QString(","), proposal.proposalText);
  QCOMPARE((int)Comma, proposal.proposalType);

  proposal = propCommand.sutProposals().at(1);
  QCOMPARE(QString(";"), proposal.proposalText);
  QCOMPARE((int)Semi, proposal.proposalType);

  return;
}

void SutProposalsTest::sutProposalTest_11()
{
  QString docText("Sut{name:mySut; SutComponent{name: comp1; Port p1;");

  ComCreateSutProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(3, propCommand.sutProposals().count());

  DslProposal proposal = propCommand.sutProposals().at(0);
  QCOMPARE(QString("Attribute"), proposal.proposalText);
  QCOMPARE((int)Attribute, proposal.proposalType);

  proposal = propCommand.sutProposals().at(1);
  QCOMPARE(QString("Port"), proposal.proposalText);
  QCOMPARE((int)Port, proposal.proposalType);

  proposal = propCommand.sutProposals().at(2);
  QCOMPARE(QString("}"), proposal.proposalText);
  QCOMPARE((int)RightBrace, proposal.proposalType);

  return;
}

void SutProposalsTest::sutProposalAfterCommentTest_1()
{
  QString docText("\n Sut{\n name: mySut;\n\n /*comment*/ SutComponent{ ");

  ComCreateSutProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(1, propCommand.sutProposals().count());

  DslProposal proposal = propCommand.sutProposals().at(0);
  QCOMPARE(QString("name"), proposal.proposalText);
  QCOMPARE(proposal.proposalType, (int)Name);

  return;
}

void SutProposalsTest::sutProposalAfterCommentTest_2()
{
  QString docText("/*it has to start with Sut */");

  ComCreateSutProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(1, propCommand.sutProposals().count());

  DslProposal proposal = propCommand.sutProposals().at(0);
  QCOMPARE(QString("Sut"), proposal.proposalText);
  QCOMPARE(proposal.proposalType, (int)Sut);

  return;
}

void SutProposalsTest::sutProposalAfterCommentTest_3()
{
  QString docText("/*it has to start with 'Sut' */");

  ComCreateSutProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(1, propCommand.sutProposals().count());

  DslProposal proposal = propCommand.sutProposals().at(0);
  QCOMPARE(QString("Sut"), proposal.proposalText);
  QCOMPARE(proposal.proposalType, (int)Sut);

  return;
}

void SutProposalsTest::sutProposalAfterCommentTest_4()
{
  QString docText("/*it has to start with \"Sut\" */");

  ComCreateSutProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(1, propCommand.sutProposals().count());

  DslProposal proposal = propCommand.sutProposals().at(0);
  QCOMPARE(QString("Sut"), proposal.proposalText);
  QCOMPARE(proposal.proposalType, (int)Sut);

  return;
}

void SutProposalsTest::sutProposalWithinCommentTest_1()
{
  QString docText("\n Sut{\n name: mySut;\n\n //comment  ");

  ComCreateSutProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(0, propCommand.sutProposals().count());

  return;
}

void SutProposalsTest::sutProposalWithinCommentTest_2()
{
  QString docText("\n Sut{\n name: mySut;\n\n /*comment \n further comment \n ");

  ComCreateSutProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(0, propCommand.sutProposals().count());

  return;
}

void SutProposalsTest::sutProposalAfterPortDecl_1()
{
  QString docText("\n Sut{\n name: mySut;\n\n //commenting something//\n  SutComponent{ ");

  ComCreateSutProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(1, propCommand.sutProposals().count());

  DslProposal proposal = propCommand.sutProposals().at(0);
  QCOMPARE(QString("name"), proposal.proposalText);
  QCOMPARE(proposal.proposalType, (int)Name);

  return;
}

QTEST_GUILESS_MAIN(SutProposalsTest)

#include "tst_sutproposals.moc"
