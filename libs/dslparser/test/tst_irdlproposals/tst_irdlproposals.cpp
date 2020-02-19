#include <QtTest>

#include <mobata/model/ts/ts.hpp>
#include <dslparser/irdl/combuildirdlmodel.hpp>
#include <dslparser/irdl/comcreateirdlproposals.hpp>
#include <mobata/model/base/attributeitem.hpp>
#include <mobata/model/base/base_types.hpp>
#include <mobata/model/msc/msc_types.hpp>
#include <mobata/model/msc/msccheckmessageitem.hpp>
#include <mobata/model/msc/msctimeoutitem.hpp>
#include <mobata/model/requirement/req.hpp>

using namespace dslparser::irdl;
using namespace dslparser;
using namespace model::irdl;

class IrdlProposalsTest
    : public QObject
{
  Q_OBJECT

public:
  IrdlProposalsTest();

private Q_SLOTS:
  void initTest();
  void cleanupTest();
  void irdlProposalEmptyTextTest_1();
  void irdlProposalTest_1();
  void irdlProposalTest_2();
  void irdlProposalTest_2_1();
  void irdlProposalTest_3();
  void irdlProposalTest_4();
  void irdlProposalTest_5();
  void irdlProposalTest_6();
  void irdlProposalTest_7();
  void irdlProposalTest_8();
  void irdlProposalTest_9();
  void irdlProposalTest_10();
  void irdlProposalTest_11();
  void irdlProposalTest_12();
  void irdlProposalTest_13();
  void irdlProposalTest_14();
  void irdlProposalTest_15();
  void irdlProposalTest_16();
  void irdlProposalTest_17();
  void includeIrdlProposalTest1();
  void includeIrdlProposalTest2();
  void includeIrdlProposalTest3();
  void includeIrdlProposalTest4();
  void includeIrdlProposalErrorTest();
  void irdlProposalAfterCommentTest_1();
  void irdlProposalAfterCommentTest_2();
  void irdlProposalAfterCommentTest_3();
  void irdlProposalAfterCommentTest_4();
  void irdlProposalWithinCommentTest_1();
  void irdlProposalWithinCommentTest_2();
};

IrdlProposalsTest::IrdlProposalsTest()
{}

void IrdlProposalsTest::initTest()
{}

void IrdlProposalsTest::cleanupTest()
{}

void IrdlProposalsTest::irdlProposalEmptyTextTest_1()
{
  QString docText("");

  ComCreateIrdlProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(2, command.irdlProposals().count());

  DslProposal firstProposal = command.irdlProposals().at(0);
  QCOMPARE(QString("Requirement"), firstProposal.proposalText);
  QCOMPARE((int)Requirement, firstProposal.proposalType);

  DslProposal secProposal = command.irdlProposals().at(1);
  QCOMPARE(QString("import"), secProposal.proposalText);
  QCOMPARE((int)Import, secProposal.proposalType);

  return;
}

void IrdlProposalsTest::irdlProposalTest_1()
{
  QString docText(L'\u2029');
  docText+=" ";
  docText+=QChar(L'\u2029');
  docText+=" ";

  ComCreateIrdlProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(2, command.irdlProposals().count());

  DslProposal firstProposal = command.irdlProposals().at(0);
  QCOMPARE(QString("Requirement"), firstProposal.proposalText);
  QCOMPARE((int)Requirement, firstProposal.proposalType);

  DslProposal secProposal = command.irdlProposals().at(1);
  QCOMPARE(QString("import"), secProposal.proposalText);
  QCOMPARE((int)Import, secProposal.proposalType);
  return;
}

void IrdlProposalsTest::irdlProposalTest_2()
{
  QString docText(L'\u2029');
  docText+=" ";
  docText+=QChar(L'\u2029');
  docText+=" Requirement";

  ComCreateIrdlProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.irdlProposals().count());

  return;
}

void IrdlProposalsTest::irdlProposalTest_2_1()
{
  QString docText("Requirement");

  ComCreateIrdlProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.irdlProposals().count());

  return;
}

void IrdlProposalsTest::irdlProposalTest_3()
{
  QString docText("Requirement{\n");

  ComCreateIrdlProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(1, command.irdlProposals().count());

  DslProposal firstProposal = command.irdlProposals().at(0);
  QCOMPARE(QString("Declaration"), firstProposal.proposalText);
  QCOMPARE((int)Declaration, firstProposal.proposalType);

  return;
}

void IrdlProposalsTest::irdlProposalTest_4()
{
  QString docText("Requirement{Declaration{name");

  ComCreateIrdlProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.irdlProposals().count());

  return;
}

void IrdlProposalsTest::irdlProposalTest_5()
{
  QString docText("Requirement{Declaration{name:");

  ComCreateIrdlProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.irdlProposals().count());

  return;
}

void IrdlProposalsTest::irdlProposalTest_6()
{
  QString docText("Requirement{\n"
                  "Declaration{\n"
                  "name:myIrdl; ");

  ComCreateIrdlProposals command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(7, command.irdlProposals().count());

  DslProposal proposal = command.irdlProposals().at(0);
  QCOMPARE(QString("Actor"), proposal.proposalText);
  QCOMPARE((int)Actor, proposal.proposalType);

  proposal = command.irdlProposals().at(1);
  QCOMPARE(QString("Attribute"), proposal.proposalText);
  QCOMPARE((int)Attribute, proposal.proposalType);

  proposal = command.irdlProposals().at(2);
  QCOMPARE(QString("Component"), proposal.proposalText);
  QCOMPARE((int)Component, proposal.proposalType);

  proposal = command.irdlProposals().at(3);
  QCOMPARE(QString("Signal"), proposal.proposalText);
  QCOMPARE((int)Signal, proposal.proposalType);

  proposal = command.irdlProposals().at(4);
  QCOMPARE(QString("Type"), proposal.proposalText);
  QCOMPARE((int)Type, proposal.proposalType);

  proposal = command.irdlProposals().at(5);
  QCOMPARE(QString("description"), proposal.proposalText);
  QCOMPARE((int)Description, proposal.proposalType);

  proposal = command.irdlProposals().at(6);
  QCOMPARE(QString("use"), proposal.proposalText);
  QCOMPARE((int)Use, proposal.proposalType);

  return;
}

void IrdlProposalsTest::irdlProposalTest_7()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_irdl_1.irdl";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  ComCreateIrdlProposals command(docText,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(10, command.irdlProposals().count());

  DslProposal proposal = command.irdlProposals().at(0);
  QCOMPARE(QString("Alt"), proposal.proposalText);
  QCOMPARE((int)Alt, proposal.proposalType);

  proposal = command.irdlProposals().at(1);
  QCOMPARE(QString("Duration"), proposal.proposalText);
  QCOMPARE((int)Duration, proposal.proposalType);

  proposal = command.irdlProposals().at(2);
  QCOMPARE(QString("ReceiveMessage"), proposal.proposalText);
  QCOMPARE((int)Check, proposal.proposalType);

  proposal = command.irdlProposals().at(3);
  QCOMPARE(QString("SendMessage"), proposal.proposalText);
  QCOMPARE((int)Message, proposal.proposalType);

  proposal = command.irdlProposals().at(4);
  QCOMPARE(QString("State"), proposal.proposalText);
  QCOMPARE((int)State, proposal.proposalType);

  proposal = command.irdlProposals().at(5);
  QCOMPARE(QString("Timer"), proposal.proposalText);
  QCOMPARE((int)Timer, proposal.proposalType);

  proposal = command.irdlProposals().at(6);
  QCOMPARE(QString("decl.globalAttribute"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.irdlProposals().at(7);
  QCOMPARE(QString("retValue"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.irdlProposals().at(8);
  QCOMPARE(QString("system.initialized"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.irdlProposals().at(9);
  QCOMPARE(QString("system1.initialized"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  return;
}

void IrdlProposalsTest::irdlProposalTest_8()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_irdl_2.irdl";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  ComCreateIrdlProposals command(docText,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(5, command.irdlProposals().count());//FIXME: no operational symbols as proposal

//  DslProposal proposal = command.irdlProposals().at(0);
//  QCOMPARE(QString("decl.globalAttribute"), proposal.proposalText);
//  QCOMPARE((int)Identifier, proposal.proposalType);

//  proposal = command.irdlProposals().at(1);
//  QCOMPARE(QString("msg.Gesamtanlage_Start"), proposal.proposalText);
//  QCOMPARE((int)Identifier, proposal.proposalType);

//  proposal = command.irdlProposals().at(2);
//  QCOMPARE(QString("retValue"), proposal.proposalText);
//  QCOMPARE((int)Identifier, proposal.proposalType);

//  proposal = command.irdlProposals().at(3);
//  QCOMPARE(QString("system.initialized"), proposal.proposalText);
//  QCOMPARE((int)Identifier, proposal.proposalType);

//  proposal = command.irdlProposals().at(4);
//  QCOMPARE(QString("system1.initialized"), proposal.proposalText);
//  QCOMPARE((int)Identifier, proposal.proposalType);

  return;
}

void IrdlProposalsTest::irdlProposalTest_9()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_irdl_3.irdl";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  ComCreateIrdlProposals command(docText,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(3, command.irdlProposals().count());

  DslProposal proposal = command.irdlProposals().at(0);
  QCOMPARE(QString("system"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.irdlProposals().at(1);
  QCOMPARE(QString("system1"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.irdlProposals().at(2);
  QCOMPARE(QString("user"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  return;
}

void IrdlProposalsTest::irdlProposalTest_10()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_irdl_4.irdl";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  ComCreateIrdlProposals command(docText,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(2, command.irdlProposals().count());

  DslProposal proposal = command.irdlProposals().at(0);
  QCOMPARE(QString("irdLDecl.system"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.irdlProposals().at(1);
  QCOMPARE(QString("irdLDecl.user"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  return;
}

void IrdlProposalsTest::irdlProposalTest_11()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_irdl_5.irdl";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  ComCreateIrdlProposals command(docText,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(6, command.irdlProposals().count());

  DslProposal proposal = command.irdlProposals().at(0);
  QCOMPARE(QString("decl.globalAttribute"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.irdlProposals().at(1);
  QCOMPARE(QString("irdLDecl.globalIrdlAttribute"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.irdlProposals().at(2);
  QCOMPARE(QString("irdLDecl.system.initialized"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);
  /*
  proposal = command.irdlProposals().at(3);
  QCOMPARE(QString("msg.retValue"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);
  */
  proposal = command.irdlProposals().at(3);
  QCOMPARE(QString("retValue"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.irdlProposals().at(4);
  QCOMPARE(QString("system.initialized"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.irdlProposals().at(5);
  QCOMPARE(QString("system1.initialized"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);
  return;
}

void IrdlProposalsTest::irdlProposalTest_12()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_irdl_6.irdl";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  ComCreateIrdlProposals command(docText,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(2, command.irdlProposals().count());

  DslProposal proposal = command.irdlProposals().at(0);
  QCOMPARE(QString("system"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.irdlProposals().at(1);
  QCOMPARE(QString("user"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);
  return;
}

void IrdlProposalsTest::irdlProposalTest_13()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_irdl_7.irdl";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  ComCreateIrdlProposals command(docText,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(2, command.irdlProposals().count());

  DslProposal proposal = command.irdlProposals().at(0);
  QCOMPARE(QString("globalIrdlAttribute"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.irdlProposals().at(1);
  QCOMPARE(QString("system.initialized"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  return;
}

void IrdlProposalsTest::irdlProposalTest_14()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_irdl_8.irdl";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  ComCreateIrdlProposals command(docText,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(1, command.irdlProposals().count());

  DslProposal proposal = command.irdlProposals().at(0);
  QCOMPARE(QString("initialized"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);
  return;
}

void IrdlProposalsTest::irdlProposalTest_15()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_irdl_9.irdl";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  ComCreateIrdlProposals command(docText,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(1, command.irdlProposals().count());

  DslProposal proposal = command.irdlProposals().at(0);
  QCOMPARE(QString("initialized"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);
  return;
}

void IrdlProposalsTest::irdlProposalTest_16()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_irdl_10.irdl";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  ComCreateIrdlProposals command(docText,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(8, command.irdlProposals().count());

  DslProposal proposal = command.irdlProposals().at(0);
  QCOMPARE(QString("checkByteValue_ActiveStep"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.irdlProposals().at(1);
  QCOMPARE(QString("confirmation"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.irdlProposals().at(2);
  QCOMPARE(QString("sendResponse"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.irdlProposals().at(3);
  QCOMPARE(QString("sendResponseBool"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.irdlProposals().at(4);
  QCOMPARE(QString("setButton"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.irdlProposals().at(5);
  QCOMPARE(QString("setButtonFM"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.irdlProposals().at(6);
  QCOMPARE(QString("setStart"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.irdlProposals().at(7);
  QCOMPARE(QString("setStop"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);
  return;
}

void IrdlProposalsTest::irdlProposalTest_17()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_irdl_11.irdl";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  ComCreateIrdlProposals command(docText,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(8, command.irdlProposals().count());

  DslProposal proposal = command.irdlProposals().at(0);
  QCOMPARE(QString("checkByteValue_ActiveStep"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.irdlProposals().at(1);
  QCOMPARE(QString("confirmation"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.irdlProposals().at(2);
  QCOMPARE(QString("sendResponse"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.irdlProposals().at(3);
  QCOMPARE(QString("sendResponseBool"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.irdlProposals().at(4);
  QCOMPARE(QString("setButton"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.irdlProposals().at(5);
  QCOMPARE(QString("setButtonFM"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.irdlProposals().at(6);
  QCOMPARE(QString("setStart"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = command.irdlProposals().at(7);
  QCOMPARE(QString("setStop"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);
  return;
}

void IrdlProposalsTest::includeIrdlProposalTest1(){
  QString praefix = ":/Examples/";
  QString filename = praefix + "testpath/example2.irdl";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();

  ComCreateIrdlProposals propCommand(docText,praefix);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(15,propCommand.irdlProposals().size());

  DslProposal proposal = propCommand.irdlProposals().at(0);
  QCOMPARE(QString(".."), proposal.proposalText);
  QCOMPARE((int)Range, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(1);
  QCOMPARE(QString("declaration.decl"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(2);
  QCOMPARE(QString("example_irdl_1.irdl"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(3);
  QCOMPARE(QString("example_irdl_10.irdl"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(4);
  QCOMPARE(QString("example_irdl_11.irdl"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(5);
  QCOMPARE(QString("example_irdl_2.irdl"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(6);
  QCOMPARE(QString("example_irdl_3.irdl"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(7);
  QCOMPARE(QString("example_irdl_4.irdl"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(8);
  QCOMPARE(QString("example_irdl_5.irdl"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(9);
  QCOMPARE(QString("example_irdl_6.irdl"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(10);
  QCOMPARE(QString("example_irdl_7.irdl"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(11);
  QCOMPARE(QString("example_irdl_8.irdl"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(12);
  QCOMPARE(QString("example_irdl_9.irdl"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(13);
  QCOMPARE(QString("irdlDeclaration.irdldecl"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(14);
  QCOMPARE(QString("testpath"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);
}

void IrdlProposalsTest::includeIrdlProposalTest2(){
  QString praefix = ":/Examples/";
  QString filename = praefix + "testpath/example3.irdl";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();

  ComCreateIrdlProposals propCommand(docText,praefix);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(8,propCommand.irdlProposals().size());

  DslProposal proposal = propCommand.irdlProposals().at(0);
  QCOMPARE(QString(".."), proposal.proposalText);
  QCOMPARE((int)Range, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(1);
  QCOMPARE(QString("example2.irdl"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(2);
  QCOMPARE(QString("example3.irdl"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(3);
  QCOMPARE(QString("example4.irdl"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(4);
  QCOMPARE(QString("example5.irdl"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(5);
  QCOMPARE(QString("sutExample2.sut"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(6);
  QCOMPARE(QString("sutExample3.sut"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(7);
  QCOMPARE(QString("sutExample4.sut"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);
}

void IrdlProposalsTest::includeIrdlProposalTest3(){
  QString praefix = ":/Examples/";
  QString filename = praefix + "testpath/example4.irdl";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();

  ComCreateIrdlProposals propCommand(docText,praefix);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(3,propCommand.irdlProposals().size());

  DslProposal proposal = propCommand.irdlProposals().at(0);
  QCOMPARE(QString("sutExample2.sut"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(1);
  QCOMPARE(QString("sutExample3.sut"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(2);
  QCOMPARE(QString("sutExample4.sut"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);
}

void IrdlProposalsTest::includeIrdlProposalTest4(){
  QString praefix = ":/Examples/";
  QString docText("import <testpath/../");

  ComCreateIrdlProposals propCommand(docText,praefix);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(15,propCommand.irdlProposals().size());

  DslProposal proposal = propCommand.irdlProposals().at(0);
  QCOMPARE(QString(".."), proposal.proposalText);
  QCOMPARE((int)Range, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(1);
  QCOMPARE(QString("declaration.decl"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(2);
  QCOMPARE(QString("example_irdl_1.irdl"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(3);
  QCOMPARE(QString("example_irdl_10.irdl"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(4);
  QCOMPARE(QString("example_irdl_11.irdl"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(5);
  QCOMPARE(QString("example_irdl_2.irdl"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(6);
  QCOMPARE(QString("example_irdl_3.irdl"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(7);
  QCOMPARE(QString("example_irdl_4.irdl"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(8);
  QCOMPARE(QString("example_irdl_5.irdl"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(9);
  QCOMPARE(QString("example_irdl_6.irdl"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(10);
  QCOMPARE(QString("example_irdl_7.irdl"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(11);
  QCOMPARE(QString("example_irdl_8.irdl"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(12);
  QCOMPARE(QString("example_irdl_9.irdl"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(13);
  QCOMPARE(QString("irdlDeclaration.irdldecl"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(14);
  QCOMPARE(QString("testpath"), proposal.proposalText);
  QCOMPARE((int)Identifier, proposal.proposalType);
}

void IrdlProposalsTest::includeIrdlProposalErrorTest(){
  QString praefix = ":/Examples/";
  QString docText("import <testpath/huivva/");

  ComCreateIrdlProposals propCommand(docText,praefix);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0,propCommand.irdlProposals().size());
}

void IrdlProposalsTest::irdlProposalAfterCommentTest_1()
{
  QString docText("\n Requirement{\n Declaration{ name: myIrdl;\n\n /*comment*/ ");

  ComCreateIrdlProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(7, propCommand.irdlProposals().count());

  DslProposal proposal = propCommand.irdlProposals().at(0);
  QCOMPARE(QString("Actor"), proposal.proposalText);
  QCOMPARE((int)Actor, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(1);
  QCOMPARE(QString("Attribute"), proposal.proposalText);
  QCOMPARE((int)Attribute, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(2);
  QCOMPARE(QString("Component"), proposal.proposalText);
  QCOMPARE((int)Component, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(3);
  QCOMPARE(QString("Signal"), proposal.proposalText);
  QCOMPARE((int)Signal, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(4);
  QCOMPARE(QString("Type"), proposal.proposalText);
  QCOMPARE((int)Type, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(5);
  QCOMPARE(QString("description"), proposal.proposalText);
  QCOMPARE((int)Description, proposal.proposalType);

  proposal = propCommand.irdlProposals().at(6);
  QCOMPARE(QString("use"), proposal.proposalText);
  QCOMPARE((int)Use, proposal.proposalType);
  return;
}

void IrdlProposalsTest::irdlProposalAfterCommentTest_2()
{
  QString docText("/*it has to start with Requirement */");

  ComCreateIrdlProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(2, propCommand.irdlProposals().count());

  DslProposal firstProposal = propCommand.irdlProposals().at(0);
  QCOMPARE(QString("Requirement"), firstProposal.proposalText);
  QCOMPARE((int)Requirement, firstProposal.proposalType);

  DslProposal secProposal = propCommand.irdlProposals().at(1);
  QCOMPARE(QString("import"), secProposal.proposalText);
  QCOMPARE((int)Import, secProposal.proposalType);

  return;
}

void IrdlProposalsTest::irdlProposalAfterCommentTest_3()
{
  QString docText("/*it has to start with 'Requirement' */");

  ComCreateIrdlProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(2, propCommand.irdlProposals().count());

  DslProposal firstProposal = propCommand.irdlProposals().at(0);
  QCOMPARE(QString("Requirement"), firstProposal.proposalText);
  QCOMPARE((int)Requirement, firstProposal.proposalType);

  DslProposal secProposal = propCommand.irdlProposals().at(1);
  QCOMPARE(QString("import"), secProposal.proposalText);
  QCOMPARE((int)Import, secProposal.proposalType);

  return;
}

void IrdlProposalsTest::irdlProposalAfterCommentTest_4()
{
  QString docText("/*it has to start with \"Requirement\" */");

  ComCreateIrdlProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(2, propCommand.irdlProposals().count());

  DslProposal firstProposal = propCommand.irdlProposals().at(0);
  QCOMPARE(QString("Requirement"), firstProposal.proposalText);
  QCOMPARE((int)Requirement, firstProposal.proposalType);

  DslProposal secProposal = propCommand.irdlProposals().at(1);
  QCOMPARE(QString("import"), secProposal.proposalText);
  QCOMPARE((int)Import, secProposal.proposalType);

  return;
}

void IrdlProposalsTest::irdlProposalWithinCommentTest_1()
{
  QString docText("\n Requirement{\n Declaration{name: myIrdl;\n\n //comment  ");

  ComCreateIrdlProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(0, propCommand.irdlProposals().count());

  return;
}

void IrdlProposalsTest::irdlProposalWithinCommentTest_2()
{
  QString docText("\n Requirement{\n name: myIrdl;\n\n /*comment \n further comment \n ");

  ComCreateIrdlProposals propCommand(docText);
  QString errorString;
  bool result = propCommand.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errorString: "<<errorString;
  QCOMPARE(0, propCommand.irdlProposals().count());

  return;
}

QTEST_APPLESS_MAIN(IrdlProposalsTest)

#include "tst_irdlproposals.moc"
