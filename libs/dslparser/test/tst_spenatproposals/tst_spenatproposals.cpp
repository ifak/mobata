#include <QtTest>

#include <dslparser/spenat/comcreatespenatproposals.hpp>
#include <dslparser/spenat/combuildspenatmodel.hpp>

#include <mobata/model/spenat/spenatmodel.hpp>

#include <mobata/memory_leak_start.hpp>

using namespace dslparser;
using namespace dslparser::spenat;
using namespace model::spenat;

class SpenatProposalsTest
    : public QObject
{
  Q_OBJECT

public:
  SpenatProposalsTest();

private Q_SLOTS:
  void initTest();
  void cleanupTest();
  void spenatProposalEmptyTextTest_1();
  void spenatProposalTest_1();
  void spenatProposalTest_2();
  void spenatProposalTest_2_1();
  void spenatProposalTest_2_2();
  void spenatProposalTest_3();
  void spenatProposalTest_4();
  void spenatProposalTest_5();
  void spenatProposalTest_6();
  void spenatProposalTest_7();
  void spenatProposalTest_8();
  void spenatProposalTest_9();
  void spenatProposalTest_10();
  void spenatProposalTest_10_01();
  void spenatProposalTest_11();
  void spenatProposalTest_12();
  void spenatProposalTest_13();
  void spenatProposalTest_14();
  void spenatProposalTest_15();
  void spenatProposalTest_16();
  void spenatProposalTest_17();
  void spenatProposalTest_18();
  void spenatProposalTest_19();
  void spenatProposalTest_20();
  void spenatProposalTest_21();
  void spenatProposalTest_22();
  void spenatProposalTest_23();
  void spenatProposalTest_24();
  void spenatProposalTest_25();
  void spenatProposalTest_26();
  void spenatProposalTest_27();
  void spenatProposalTest_28();
  void spenatProposalTest_29();
  void spenatProposalAfterCommentTest_1();
  void spenatProposalAfterCommentTest_2();
  void spenatProposalAfterCommentTest_3();
  void spenatProposalAfterCommentTest_4();
  void spenatProposalWithinCommentTest_1();
  void spenatProposalWithinCommentTest_2();
  void spenatProposalAfterPortDecl_1();
  void spenatProposalSignalTest_1();
  void spenatProposalSignalTest_2();
  void spenatProposalAttributeTest_1();
  void spenatProposalAttributeTest_2();
};

SpenatProposalsTest::SpenatProposalsTest()
{}

void SpenatProposalsTest::initTest()
{}

void SpenatProposalsTest::cleanupTest()
{}

void SpenatProposalsTest::spenatProposalEmptyTextTest_1()
{
  QString docText("");

  ComCreateSpenatProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(1, command.spenatProposals().count());

  DslProposal firstProposal = command.spenatProposals().at(0);
  QCOMPARE(QString("Spenat"), firstProposal.proposalText);
  QCOMPARE((int)Spenat, firstProposal.proposalType);

  return;
}

void SpenatProposalsTest::spenatProposalTest_1()
{
  QString docText(L'\u2029');
  docText+=" ";
  docText+=QChar(L'\u2029');
  docText+=" ";

  ComCreateSpenatProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(1, command.spenatProposals().count());

  DslProposal firstProposal = command.spenatProposals().at(0);
  QCOMPARE(QString("Spenat"), firstProposal.proposalText);
  QCOMPARE((int)Spenat, firstProposal.proposalType);

  return;
}

void SpenatProposalsTest::spenatProposalTest_2()
{
  QString docText(L'\u2029');
  docText+=" ";
  docText+=QChar(L'\u2029');
  docText+=" Spenat";

  ComCreateSpenatProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(1, command.spenatProposals().count());

  DslProposal firstProposal = command.spenatProposals().at(0);
  QCOMPARE(QString("{"), firstProposal.proposalText);
  QCOMPARE((int)LeftBrace, firstProposal.proposalType);

  return;
}

void SpenatProposalsTest::spenatProposalTest_2_1()
{
  std::string stdDocText="\r\n";
  stdDocText+=" Spenat \r\n ";

  QString docText=QString::fromStdString(stdDocText);

  ComCreateSpenatProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(1, command.spenatProposals().count());

  DslProposal firstProposal = command.spenatProposals().at(0);
  QCOMPARE(QString("{"), firstProposal.proposalText);
  QCOMPARE((int)LeftBrace, firstProposal.proposalType);

  return;
}

void SpenatProposalsTest::spenatProposalTest_2_2()
{
  QString docText("Spenat");

  ComCreateSpenatProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(1, command.spenatProposals().count());

  DslProposal firstProposal = command.spenatProposals().at(0);
  QCOMPARE(QString("{"), firstProposal.proposalText);
  QCOMPARE((int)LeftBrace, firstProposal.proposalType);

  return;
}

void SpenatProposalsTest::spenatProposalTest_3()
{
  QString docText("Spenat{");

  ComCreateSpenatProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(1, command.spenatProposals().count());

  DslProposal firstProposal = command.spenatProposals().at(0);
  QCOMPARE(QString("name"), firstProposal.proposalText);
  QCOMPARE((int)Name, firstProposal.proposalType);

  return;
}

void SpenatProposalsTest::spenatProposalTest_4()
{
  QString docText("Spenat{name");

  ComCreateSpenatProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(1, command.spenatProposals().count());

  DslProposal firstProposal = command.spenatProposals().at(0);
  QCOMPARE(QString(":"), firstProposal.proposalText);
  QCOMPARE((int)Colon, firstProposal.proposalType);

  return;
}

void SpenatProposalsTest::spenatProposalTest_5()
{
  QString docText("Spenat{name:");

  ComCreateSpenatProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.spenatProposals().count());

  return;
}

void SpenatProposalsTest::spenatProposalTest_6()
{
  QString docText("Spenat{name:mySpenat; ");

  ComCreateSpenatProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(9, command.spenatProposals().count());

  DslProposal proposal = command.spenatProposals().at(0);
  QCOMPARE(QString("Attribute"), proposal.proposalText);
  QCOMPARE((int)Attribute, proposal.proposalType);

  proposal = command.spenatProposals().at(1);
  QCOMPARE(QString("Function"), proposal.proposalText);
  QCOMPARE((int)Function, proposal.proposalType);

  proposal = command.spenatProposals().at(2);
  QCOMPARE(QString("Place"), proposal.proposalText);
  QCOMPARE((int)Place, proposal.proposalType);

  proposal = command.spenatProposals().at(3);
  QCOMPARE(QString("Port"), proposal.proposalText);
  QCOMPARE((int)Port, proposal.proposalType);

  proposal = command.spenatProposals().at(4);
  QCOMPARE(QString("Signal"), proposal.proposalText);
  QCOMPARE((int)Signal, proposal.proposalType);

  proposal = command.spenatProposals().at(5);
  QCOMPARE(QString("SignalTransition"), proposal.proposalText);
  QCOMPARE((int)SignalTransition, proposal.proposalType);

  proposal = command.spenatProposals().at(6);
  QCOMPARE(QString("TimeoutTransition"), proposal.proposalText);
  QCOMPARE((int)TimeoutTransition, proposal.proposalType);

  proposal = command.spenatProposals().at(7);
  QCOMPARE(QString("Type"), proposal.proposalText);
  QCOMPARE((int)Type, proposal.proposalType);

  proposal = command.spenatProposals().at(8);
  QCOMPARE(QString("}"), proposal.proposalText);
  QCOMPARE((int)RightBrace, proposal.proposalType);

  return;
}

void SpenatProposalsTest::spenatProposalTest_7()
{
  QString docText("Spenat{name:mySpenat; Place{name: p1;} ");

  ComCreateSpenatProposals command(docText);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(9, command.spenatProposals().count());

  DslProposal proposal = command.spenatProposals().at(0);
  QCOMPARE(QString("Attribute"), proposal.proposalText);
  QCOMPARE((int)Attribute, proposal.proposalType);

  proposal = command.spenatProposals().at(1);
  QCOMPARE(QString("Function"), proposal.proposalText);
  QCOMPARE((int)Function, proposal.proposalType);

  proposal = command.spenatProposals().at(2);
  QCOMPARE(QString("Place"), proposal.proposalText);
  QCOMPARE((int)Place, proposal.proposalType);

  proposal = command.spenatProposals().at(3);
  QCOMPARE(QString("Port"), proposal.proposalText);
  QCOMPARE((int)Port, proposal.proposalType);

  proposal = command.spenatProposals().at(4);
  QCOMPARE(QString("Signal"), proposal.proposalText);
  QCOMPARE((int)Signal, proposal.proposalType);

  proposal = command.spenatProposals().at(5);
  QCOMPARE(QString("SignalTransition"), proposal.proposalText);
  QCOMPARE((int)SignalTransition, proposal.proposalType);

  proposal = command.spenatProposals().at(6);
  QCOMPARE(QString("TimeoutTransition"), proposal.proposalText);
  QCOMPARE((int)TimeoutTransition, proposal.proposalType);

  proposal = command.spenatProposals().at(7);
  QCOMPARE(QString("Type"), proposal.proposalText);
  QCOMPARE((int)Type, proposal.proposalType);

  proposal = command.spenatProposals().at(8);
  QCOMPARE(QString("}"), proposal.proposalText);
  QCOMPARE((int)RightBrace, proposal.proposalType);

  return;
}

void SpenatProposalsTest::spenatProposalTest_8()
{
  QString docText("Spenat{name:mySpenat; Place{name: p1;");

  ComCreateSpenatProposals command(docText);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(2, command.spenatProposals().count());

  DslProposal proposal = command.spenatProposals().at(0);
  QCOMPARE(QString("initial"), proposal.proposalText);
  QCOMPARE((int)Initial, proposal.proposalType);

  proposal = command.spenatProposals().at(1);
  QCOMPARE(QString("}"), proposal.proposalText);
  QCOMPARE((int)RightBrace, proposal.proposalType);

  return;
}

void SpenatProposalsTest::spenatProposalTest_9()
{
  QString docText("Spenat{name:mySpenat; SignalTransition{name: t1; signal:");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(0, propCommand.spenatProposals().count());

  return;
}

void SpenatProposalsTest::spenatProposalTest_10()
{
  QString docText("Spenat{name:mySpenat; Signal inputSignal; SignalTransition{name: t1; signal:");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(1, propCommand.spenatProposals().count());

  DslProposal proposal = propCommand.spenatProposals().at(0);
  QCOMPARE(QString("inputSignal"), proposal.proposalText);
  QCOMPARE((int)RefSignal, proposal.proposalType);

  return;
}

void SpenatProposalsTest::spenatProposalTest_10_01()
{
  QString docText("Spenat{name:mySpenat; Signal inputSignal; SignalTransition{name: t1; signal: in");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(1, propCommand.spenatProposals().count());

  DslProposal proposal = propCommand.spenatProposals().at(0);
  QCOMPARE(QString("inputSignal"), proposal.proposalText);
  QCOMPARE((int)RefSignal, proposal.proposalType);

  return;
}

void SpenatProposalsTest::spenatProposalTest_11()
{
  QString docText("Spenat{name:mySpenat; Signal inputSignal; SignalTransition{name: t1; "
                  "signal: inputSignal; ");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(1, propCommand.spenatProposals().count());

  DslProposal proposal = propCommand.spenatProposals().at(0);
  QCOMPARE(QString("port"), proposal.proposalText);
  QCOMPARE((int)RefPort, proposal.proposalType);

  return;
}

void SpenatProposalsTest::spenatProposalTest_12()
{
  QString docText("Spenat{name:mySpenat; Signal inputSignal; SignalTransition{name: t1; "
                  "signal: inputSignal; port: ");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(0, propCommand.spenatProposals().count());

  return;
}

void SpenatProposalsTest::spenatProposalTest_13()
{
  QString docText("Spenat{name:mySpenat; Signal inputSignal; Port p_in; SignalTransition{name: t1; "
                  "signal: inputSignal; port: ");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(1, propCommand.spenatProposals().count());

  DslProposal proposal = propCommand.spenatProposals().at(0);
  QCOMPARE(QString("p_in"), proposal.proposalText);
  QCOMPARE((int)RefPort, proposal.proposalType);

  return;
}

void SpenatProposalsTest::spenatProposalTest_14()
{
  QString docText("Spenat{name:mySpenat; Signal inputSignal; Port p_in_1, p_in_2; "
                  "SignalTransition{name: t1; signal: inputSignal; port: ");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(2, propCommand.spenatProposals().count());

  DslProposal proposal = propCommand.spenatProposals().at(0);
  QCOMPARE(QString("p_in_1"), proposal.proposalText);
  QCOMPARE((int)RefPort, proposal.proposalType);

  proposal = propCommand.spenatProposals().at(1);
  QCOMPARE(QString("p_in_2"), proposal.proposalText);
  QCOMPARE((int)RefPort, proposal.proposalType);

  return;
}

void SpenatProposalsTest::spenatProposalTest_15()
{
  QString docText("Spenat{name:mySpenat; SignalTransition{name: t1; "
                  "pre: ");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(0, propCommand.spenatProposals().count());

  return;
}

void SpenatProposalsTest::spenatProposalTest_16()
{
  QString docText("Spenat{name:mySpenat; Place{name: p1;} SignalTransition{name: t1; "
                  "pre: ");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(1, propCommand.spenatProposals().count());

  DslProposal proposal = propCommand.spenatProposals().at(0);
  QCOMPARE(QString("p1"), proposal.proposalText);
  QCOMPARE((int)RefPlace, proposal.proposalType);

  return;
}

void SpenatProposalsTest::spenatProposalTest_17()
{
  QString docText("Spenat{name:mySpenat; Place{name: p1;} Place{name: p2;} "
                  "SignalTransition{name: t1; pre: ");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(2, propCommand.spenatProposals().count());

  DslProposal proposal = propCommand.spenatProposals().at(0);
  QCOMPARE(QString("p1"), proposal.proposalText);
  QCOMPARE((int)RefPlace, proposal.proposalType);

  proposal = propCommand.spenatProposals().at(1);
  QCOMPARE(QString("p2"), proposal.proposalText);
  QCOMPARE((int)RefPlace, proposal.proposalType);

  return;
}

void SpenatProposalsTest::spenatProposalTest_18()
{
  QString docText("Spenat{name:mySpenat; Place{name: p1;} Place{name: p2;} "
                  "SignalTransition{name: t1; pre: p1");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(2, propCommand.spenatProposals().count());

  DslProposal proposal = propCommand.spenatProposals().at(0);
  QCOMPARE(QString(","), proposal.proposalText);
  QCOMPARE((int)Comma, proposal.proposalType);

  proposal = propCommand.spenatProposals().at(1);
  QCOMPARE(QString(";"), proposal.proposalText);
  QCOMPARE((int)Semi, proposal.proposalType);

  return;
}

void SpenatProposalsTest::spenatProposalTest_19()
{
  QString docText("Spenat{name:mySpenat; Place{name: p1;} Place{name: p2;} "
                  "SignalTransition{name: t1; pre: p1, ");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(2, propCommand.spenatProposals().count());

  DslProposal proposal = propCommand.spenatProposals().at(0);
  QCOMPARE(QString("p1"), proposal.proposalText);
  QCOMPARE((int)RefPlace, proposal.proposalType);

  proposal = propCommand.spenatProposals().at(1);
  QCOMPARE(QString("p2"), proposal.proposalText);
  QCOMPARE((int)RefPlace, proposal.proposalType);

  return;
}

void SpenatProposalsTest::spenatProposalTest_20()
{
  QString docText("Spenat{name:mySpenat; SignalTransition{name: t1; "
                  "post: ");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(0, propCommand.spenatProposals().count());

  return;
}

void SpenatProposalsTest::spenatProposalTest_21()
{
  QString docText("Spenat{name:mySpenat; Place{name: p1;} SignalTransition{name: t1; "
                  "post: ");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(1, propCommand.spenatProposals().count());

  DslProposal proposal = propCommand.spenatProposals().at(0);
  QCOMPARE(QString("p1"), proposal.proposalText);
  QCOMPARE((int)RefPlace, proposal.proposalType);

  return;
}

void SpenatProposalsTest::spenatProposalTest_22()
{
  QString docText("Spenat{name:mySpenat; Place{name: p1;} Place{name: p2;} "
                  "SignalTransition{name: t1; post: ");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(2, propCommand.spenatProposals().count());

  DslProposal proposal = propCommand.spenatProposals().at(0);
  QCOMPARE(QString("p1"), proposal.proposalText);
  QCOMPARE((int)RefPlace, proposal.proposalType);

  proposal = propCommand.spenatProposals().at(1);
  QCOMPARE(QString("p2"), proposal.proposalText);
  QCOMPARE((int)RefPlace, proposal.proposalType);

  return;
}

void SpenatProposalsTest::spenatProposalTest_23()
{
  QString docText("Spenat{name:mySpenat; Place{name: p1;} Place{name: p2;} "
                  "SignalTransition{name: t1; post: p1");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(2, propCommand.spenatProposals().count());

  DslProposal proposal = propCommand.spenatProposals().at(0);
  QCOMPARE(QString(","), proposal.proposalText);
  QCOMPARE((int)Comma, proposal.proposalType);

  proposal = propCommand.spenatProposals().at(1);
  QCOMPARE(QString(";"), proposal.proposalText);
  QCOMPARE((int)Semi, proposal.proposalType);

  return;
}

void SpenatProposalsTest::spenatProposalTest_24()
{
  QString docText("Spenat{name:mySpenat; Place{name: p1;} Place{name: p2;} "
                  "SignalTransition{name: t1; post: p1, ");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(2, propCommand.spenatProposals().count());

  DslProposal proposal = propCommand.spenatProposals().at(0);
  QCOMPARE(QString("p1"), proposal.proposalText);
  QCOMPARE((int)RefPlace, proposal.proposalType);

  proposal = propCommand.spenatProposals().at(1);
  QCOMPARE(QString("p2"), proposal.proposalText);
  QCOMPARE((int)RefPlace, proposal.proposalType);

  return;
}

void SpenatProposalsTest::spenatProposalTest_25()
{
  QString docText("Spenat{name:mySpenat; Place{name: p1; initial");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(1, propCommand.spenatProposals().count());

  DslProposal proposal = propCommand.spenatProposals().at(0);
  QCOMPARE(QString(":"), proposal.proposalText);
  QCOMPARE((int)Colon, proposal.proposalType);

  return;
}

void SpenatProposalsTest::spenatProposalTest_26()
{
  QString docText("Spenat{name:mySpenat; Place{name: p1; initial:");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(2, propCommand.spenatProposals().count());

  DslProposal proposal = propCommand.spenatProposals().at(0);
  QCOMPARE(QString("false"), proposal.proposalText);
  QCOMPARE((int)False, proposal.proposalType);

  proposal = propCommand.spenatProposals().at(1);
  QCOMPARE(QString("true"), proposal.proposalText);
  QCOMPARE((int)True, proposal.proposalType);

  return;
}

void SpenatProposalsTest::spenatProposalTest_27()
{
    QString docText("Spenat{name:mySpenat; Signal inputSignal; Port p_in_1,p_in_2");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(2, propCommand.spenatProposals().count());

  DslProposal proposal = propCommand.spenatProposals().at(0);
  QCOMPARE(QString(","), proposal.proposalText);
  QCOMPARE((int)Comma, proposal.proposalType);

  proposal = propCommand.spenatProposals().at(1);
  QCOMPARE(QString(";"), proposal.proposalText);
  QCOMPARE((int)Semi, proposal.proposalType);

  return;
}

void SpenatProposalsTest::spenatProposalTest_28()
{
  QString docText("Spenat{name:mySpenat; Place{name: p1;} Place{name: p2;} "
                  "SignalTransition{name: t1; post: p1,p2 ");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(2, propCommand.spenatProposals().count());

  DslProposal proposal = propCommand.spenatProposals().at(0);
  QCOMPARE(QString(","), proposal.proposalText);
  QCOMPARE((int)Comma, proposal.proposalType);

  proposal = propCommand.spenatProposals().at(1);
  QCOMPARE(QString(";"), proposal.proposalText);
  QCOMPARE((int)Semi, proposal.proposalType);

  return;
}

void SpenatProposalsTest::spenatProposalTest_29()
{
  QString docText("Spenat{name:mySpenat; Place{name: p1;} Place{name: p2;} "
                  "SignalTransition{name: t1; pre: p1,p2 ");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(2, propCommand.spenatProposals().count());

  DslProposal proposal = propCommand.spenatProposals().at(0);
  QCOMPARE(QString(","), proposal.proposalText);
  QCOMPARE((int)Comma, proposal.proposalType);

  proposal = propCommand.spenatProposals().at(1);
  QCOMPARE(QString(";"), proposal.proposalText);
  QCOMPARE((int)Semi, proposal.proposalType);

  return;
}

void SpenatProposalsTest::spenatProposalAfterCommentTest_1()
{
  QString docText("\n Spenat{\n name: mySpenat;\n\n /*comment*/ Place{ ");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(1, propCommand.spenatProposals().count());

  DslProposal proposal = propCommand.spenatProposals().at(0);
  QCOMPARE(QString("name"), proposal.proposalText);
  QCOMPARE(proposal.proposalType, (int)Name);

  return;
}

void SpenatProposalsTest::spenatProposalAfterCommentTest_2()
{
  QString docText("/*it has to start with Spenat */");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(1, propCommand.spenatProposals().count());

  DslProposal proposal = propCommand.spenatProposals().at(0);
  QCOMPARE(QString("Spenat"), proposal.proposalText);
  QCOMPARE(proposal.proposalType, (int)Spenat);

  return;
}

void SpenatProposalsTest::spenatProposalAfterCommentTest_3()
{
  QString docText("/*it has to start with 'Spenat' */");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(1, propCommand.spenatProposals().count());

  DslProposal proposal = propCommand.spenatProposals().at(0);
  QCOMPARE(QString("Spenat"), proposal.proposalText);
  QCOMPARE(proposal.proposalType, (int)Spenat);

  return;
}

void SpenatProposalsTest::spenatProposalAfterCommentTest_4()
{
  QString docText("/*it has to start with \"Spenat\" */");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(1, propCommand.spenatProposals().count());

  DslProposal proposal = propCommand.spenatProposals().at(0);
  QCOMPARE(QString("Spenat"), proposal.proposalText);
  QCOMPARE(proposal.proposalType, (int)Spenat);

  return;
}

void SpenatProposalsTest::spenatProposalWithinCommentTest_1()
{
  QString docText("\n Spenat{\n name: mySpenat;\n\n //comment  ");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(0, propCommand.spenatProposals().count());

  return;
}

void SpenatProposalsTest::spenatProposalWithinCommentTest_2()
{
  QString docText("\n Spenat{\n name: mySpenat;\n\n /*comment \n further comment \n ");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(0, propCommand.spenatProposals().count());

  return;
}

void SpenatProposalsTest::spenatProposalAfterPortDecl_1()
{
  QString docText("\n Spenat{\n name: mySpenat;\n\n //commenting something//\n  Port p_in; \n Place{ ");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(1, propCommand.spenatProposals().count());

  DslProposal proposal = propCommand.spenatProposals().at(0);
  QCOMPARE(QString("name"), proposal.proposalText);
  QCOMPARE(proposal.proposalType, (int)Name);

  return;
}

void SpenatProposalsTest::spenatProposalSignalTest_1()
{
  QString docText("\n Spenat{\n name: mySpenat;\n\n Signal mySignal(");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(propCommand.spenatProposals().count(), 6);

  DslProposal proposal = propCommand.spenatProposals().at(0);
  QCOMPARE(proposal.proposalText, QString(")"));
  QCOMPARE(proposal.proposalType, (int)RightParen);

  proposal = propCommand.spenatProposals().at(1);
  QCOMPARE(proposal.proposalText, QString("bool"));
  QCOMPARE(proposal.proposalType, (int)Type);

  proposal = propCommand.spenatProposals().at(2);
  QCOMPARE(proposal.proposalText, QString("enum"));
  QCOMPARE(proposal.proposalType, (int)Type);

  proposal = propCommand.spenatProposals().at(3);
  QCOMPARE(proposal.proposalText, QString("int"));
  QCOMPARE(proposal.proposalType, (int)Type);

  proposal = propCommand.spenatProposals().at(4);
  QCOMPARE(proposal.proposalText, QString("real"));
  QCOMPARE(proposal.proposalType, (int)Type);

  proposal = propCommand.spenatProposals().at(5);
  QCOMPARE(proposal.proposalText, QString("string"));
  QCOMPARE(proposal.proposalType, (int)Type);

  return;
}

void SpenatProposalsTest::spenatProposalSignalTest_2()
{
  QString docText("\n Spenat{\n name: mySpenat;\n\n Signal mySignal(int x,");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(propCommand.spenatProposals().count(), 5);

  DslProposal proposal = propCommand.spenatProposals().at(0);
  QCOMPARE(proposal.proposalText, QString("bool"));
  QCOMPARE(proposal.proposalType, (int)Type);

  proposal = propCommand.spenatProposals().at(1);
  QCOMPARE(proposal.proposalText, QString("enum"));
  QCOMPARE(proposal.proposalType, (int)Type);

  proposal = propCommand.spenatProposals().at(2);
  QCOMPARE(proposal.proposalText, QString("int"));
  QCOMPARE(proposal.proposalType, (int)Type);

  proposal = propCommand.spenatProposals().at(3);
  QCOMPARE(proposal.proposalText, QString("real"));
  QCOMPARE(proposal.proposalType, (int)Type);

  proposal = propCommand.spenatProposals().at(4);
  QCOMPARE(proposal.proposalText, QString("string"));
  QCOMPARE(proposal.proposalType, (int)Type);

  return;
}

void SpenatProposalsTest::spenatProposalAttributeTest_1()
{
  QString docText("Spenat{name: mySpenat; \n"
                  "Attribute int attr1 = 0;\n"
                  "Port in_port;\n"
                  "Signal input(int in);\n"
                  "SignalTransition{name: t1;\n"
                                   "signal: input;\n"
                                   "port: in_port;\n"
                                   "guard: trigger.in>20; \n"
                                   "action: send output(this.");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(propCommand.spenatProposals().count(), 1);

  DslProposal proposal = propCommand.spenatProposals().at(0);
  QCOMPARE(proposal.proposalText, QString("attr1"));
  QCOMPARE(proposal.proposalType, (int)Attribute);

  return;
}

void SpenatProposalsTest::spenatProposalAttributeTest_2()
{
  QString docText("Spenat{name: mySpenat; \n"
                  "Attribute int attr1 = 0;\n"
                  "Port in_port;\n"
                  "Signal input(int in);\n"
                  "SignalTransition{name: t1;\n"
                                   "signal: input;\n"
                                   "port: in_port;\n"
                                   "guard: trigger.in>20; \n"
                                   "action: send output(this.");

  ComCreateSpenatProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(propCommand.spenatProposals().count(), 1);

  DslProposal proposal = propCommand.spenatProposals().at(0);
  QCOMPARE(proposal.proposalText, QString("attr1"));
  QCOMPARE(proposal.proposalType, (int)Attribute);

  return;
}

QTEST_GUILESS_MAIN(SpenatProposalsTest)

#include "tst_spenatproposals.moc"
