#include <QtTest>

#include <modsim/simsystemmodel.hpp>
#include <modsim/simsystemitem.hpp>
#include <modsim/simconnectionitem.hpp>
#include <modsim/simconfigitem.hpp>
#include <modsim/comcreatesimsystemproposals.hpp>

#include <dslparser/dslparser_types.hpp>

#include <mobata/model/base/attributeitem.hpp>
#include <mobata/model/base/base_types.hpp>

#include <QList>

class SimSystemProposalTest
    : public QObject
{
  Q_OBJECT

public:
  SimSystemProposalTest();

private Q_SLOTS:
  void initTest();
  void cleanupTest();
  void simpleSimSystemProposalTest_1();
  void simpleSimSystemProposalTest_2();
  void simpleSimSystemProposalTest_3();
  void simpleSimSystemProposalTest_4();
  void simpleSimSystemProposalTest_5();
  void simpleSimSystemProposalTest_6();
  void simpleSimSystemProposalTest_7();
  void simpleSimSystemProposalTest_8();
  void simpleSimSystemProposalTest_9();
  void simpleSimSystemProposalTest_10();
  void simpleSimSystemProposalTest_11();
  void simpleSimSystemProposalTest_12();
  void simpleSimSystemProposalTest_13();
  void simpleSimSystemProposalTest_14();
  void simpleSimSystemProposalTest_15();
  void simpleSimSystemProposalTest_16();
};

SimSystemProposalTest::SimSystemProposalTest()
{}

void SimSystemProposalTest::initTest()
{}

void SimSystemProposalTest::cleanupTest()
{}

void SimSystemProposalTest::simpleSimSystemProposalTest_1()
{
  QString docText("import <statemachine_example.statemachine> as machine\n"
                  "import <spenat_example1.spenat> as spenat1\n"
                  "import <spenat_example2.spenat> as spenat2\n"
                  "SimSystem mySimSystem{\n"
                    "Connection{\n"
                      "machine.defaultPort <-> spenat.defaultPort;\n"
                    "}\n"
                    "Config{\n"
                      "startSequence: m");
  QString prefix = ":/Examples/";
  modsim::SimSystemModel simSystemModel;
  modsim::ComCreateSimSystemProposals command(docText, prefix, &simSystemModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  const dslparser::DslProposalList& simSystemProposals = command.simSystemProposals();
  QCOMPARE(simSystemProposals.size(),1);
  QCOMPARE(simSystemProposals.at(0).proposalType,int(dslparser::Identifier));
  QCOMPARE(simSystemProposals.at(0).proposalText,QString("machine"));

  return;
}

void SimSystemProposalTest::simpleSimSystemProposalTest_2()
{
  QString docText("import <statemachine_example.statemachine> as machine\n"
                  "import <spenat_example1.spenat> as spenat1\n"
                  "import <spenat_example2.spenat> as spenat2\n"
                  "SimSystem mySimSystem{\n"
                    "Connection{\n"
                      "machine.defaultPort <-> spenat.defaultPort;\n"
                    "}\n"
                    "Config{\n"
                      "startSequence: ");
  QString prefix = ":/Examples/";
  modsim::SimSystemModel simSystemModel;
  modsim::ComCreateSimSystemProposals command(docText, prefix, &simSystemModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  const dslparser::DslProposalList simSystemProposals = command.simSystemProposals();
  QCOMPARE(simSystemProposals.size(),3);
  QCOMPARE(simSystemProposals.at(0).proposalType,int(dslparser::Identifier));
  QCOMPARE(simSystemProposals.at(0).proposalText,QString("machine"));

  QCOMPARE(simSystemProposals.at(1).proposalType,int(dslparser::Identifier));
  QCOMPARE(simSystemProposals.at(1).proposalText,QString("spenat1"));

  QCOMPARE(simSystemProposals.at(2).proposalType,int(dslparser::Identifier));
  QCOMPARE(simSystemProposals.at(2).proposalText,QString("spenat2"));

  return;
}

void SimSystemProposalTest::simpleSimSystemProposalTest_3()
{
  QString docText("import <statemachine_example.statemachine> as machine\n"
                  "import <spenat_example1.spenat> as spenat1\n"
                  "import <spenat_example2.spenat> as spenat2\n"
                  "SimSystem mySimSystem{\n"
                    "Connection{\n"
                      "machine.defaultPort <-> spenat.defaultPort;\n"
                    "}\n"
                    "Config{\n"
                      "startSeque");
  QString prefix = ":/Examples/";
  modsim::SimSystemModel simSystemModel;
  modsim::ComCreateSimSystemProposals command(docText, prefix, &simSystemModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  const dslparser::DslProposalList simSystemProposals = command.simSystemProposals();
  QCOMPARE(simSystemProposals.size(),1);
  QCOMPARE(simSystemProposals.at(0).proposalType,int(dslparser::StartSequence));
  QCOMPARE(simSystemProposals.at(0).proposalText,QString("startSequence"));
  return;
}

void SimSystemProposalTest::simpleSimSystemProposalTest_4()
{
  QString docText("import <statemachine_example.statemachine> as machine\n"
                  "import <spenat_example1.spenat> as spenat1\n"
                  "import <spenat_example2.spenat> as spenat2\n"
                  "SimSystem mySimSystem{\n"
                    "Connection{\n"
                      "machine.defaultPort <-> spenat.defaultPort;\n"
                    "}\n"
                    "Config{\n"
                    );
  QString prefix = ":/Examples/";
  modsim::SimSystemModel simSystemModel;
  modsim::ComCreateSimSystemProposals command(docText, prefix, &simSystemModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  const dslparser::DslProposalList simSystemProposals = command.simSystemProposals();
  QCOMPARE(simSystemProposals.size(),3);//Actor, startSequence, Startup

  return;
}

void SimSystemProposalTest::simpleSimSystemProposalTest_5()
{
  QString docText("import <statemachine_example.statemachine> as machine\n"
                  "import <spenat_example1.spenat> as spenat1\n"
                  "import <spenat_example2.spenat> as spenat2\n"
                  "SimSystem mySimSystem{\n"
                    "Connection{\n"
                      "machine.defaultPort <-> spenat.defaultPort;\n"
                    "}\n"
                    );
  QString prefix = ":/Examples/";
  modsim::SimSystemModel simSystemModel;
  modsim::ComCreateSimSystemProposals command(docText, prefix, &simSystemModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  const dslparser::DslProposalList simSystemProposals = command.simSystemProposals();
  QCOMPARE(simSystemProposals.size(),1);
  QCOMPARE(simSystemProposals.at(0).proposalType,int(dslparser::Config));
  QCOMPARE(simSystemProposals.at(0).proposalText,QString("Config"));

  return;
}

void SimSystemProposalTest::simpleSimSystemProposalTest_6()
{
  QString docText("import <statemachine_example.statemachine> as machine\n"
                  "import <spenat_example1.spenat> as spenat1\n"
                  "import <spenat_example2.spenat> as spenat2\n"
                  "SimSystem mySimSystem{\n"
                    "Connection{\n"
                      "machine.defaultPort <-> spenat1.defa");
  QString prefix = ":/Examples/";
  modsim::SimSystemModel simSystemModel;
  modsim::ComCreateSimSystemProposals command(docText, prefix, &simSystemModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  const dslparser::DslProposalList simSystemProposals = command.simSystemProposals();
  QCOMPARE(simSystemProposals.size(),3);
  QCOMPARE(simSystemProposals.at(0).proposalType,int(dslparser::Identifier));
  QCOMPARE(simSystemProposals.at(0).proposalText,QString("defaultPort1_1"));

  QCOMPARE(simSystemProposals.at(1).proposalType,int(dslparser::Identifier));
  QCOMPARE(simSystemProposals.at(1).proposalText,QString("defaultPort1_2"));

  QCOMPARE(simSystemProposals.at(2).proposalType,int(dslparser::Identifier));
  QCOMPARE(simSystemProposals.at(2).proposalText,QString("defaultPort1_3"));

  return;
}

void SimSystemProposalTest::simpleSimSystemProposalTest_7()
{
  QString docText("import <statemachine_example.statemachine> as machine\n"
                  "import <spenat_example1.spenat> as spenat1\n"
                  "import <spenat_example2.spenat> as spenat2\n"
                  "SimSystem mySimSystem{\n"
                    "Connection{\n"
                      "machine.defaultPort <-> spena");
  QString prefix = ":/Examples/";
  modsim::SimSystemModel simSystemModel;
  modsim::ComCreateSimSystemProposals command(docText, prefix, &simSystemModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  const dslparser::DslProposalList simSystemProposals = command.simSystemProposals();
  QCOMPARE(simSystemProposals.size(),6);
  QCOMPARE(simSystemProposals.at(0).proposalType,int(dslparser::Identifier));
  QCOMPARE(simSystemProposals.at(0).proposalText,QString("spenat1.defaultPort1_1"));

  QCOMPARE(simSystemProposals.at(1).proposalType,int(dslparser::Identifier));
  QCOMPARE(simSystemProposals.at(1).proposalText,QString("spenat1.defaultPort1_2"));

  QCOMPARE(simSystemProposals.at(2).proposalType,int(dslparser::Identifier));
  QCOMPARE(simSystemProposals.at(2).proposalText,QString("spenat1.defaultPort1_3"));

  QCOMPARE(simSystemProposals.at(3).proposalType,int(dslparser::Identifier));
  QCOMPARE(simSystemProposals.at(3).proposalText,QString("spenat2.defaultPort2_1"));

  QCOMPARE(simSystemProposals.at(4).proposalType,int(dslparser::Identifier));
  QCOMPARE(simSystemProposals.at(4).proposalText,QString("spenat2.defaultPort2_2"));

  QCOMPARE(simSystemProposals.at(5).proposalType,int(dslparser::Identifier));
  QCOMPARE(simSystemProposals.at(5).proposalText,QString("spenat2.defaultPort2_3"));

  return;
}

void SimSystemProposalTest::simpleSimSystemProposalTest_8()
{
  QString docText("import <statemachine_example.statemachine> as machine\n"
                  "import <spenat_example1.spenat> as spenat1\n"
                  "import <spenat_example2.spenat> as spenat2\n"
                  "SimSystem mySimSystem{\n"
                    "Connection{\n"
                    );
  QString prefix = ":/Examples/";
  modsim::SimSystemModel simSystemModel;
  modsim::ComCreateSimSystemProposals command(docText, prefix, &simSystemModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  const dslparser::DslProposalList simSystemProposals = command.simSystemProposals();
  QCOMPARE(simSystemProposals.size(),7);
  QCOMPARE(simSystemProposals.at(0).proposalType,int(dslparser::Identifier));
  QCOMPARE(simSystemProposals.at(0).proposalText,QString("machine.defaultPort"));

  QCOMPARE(simSystemProposals.at(1).proposalType,int(dslparser::Identifier));
  QCOMPARE(simSystemProposals.at(1).proposalText,QString("spenat1.defaultPort1_1"));

  QCOMPARE(simSystemProposals.at(2).proposalType,int(dslparser::Identifier));
  QCOMPARE(simSystemProposals.at(2).proposalText,QString("spenat1.defaultPort1_2"));

  QCOMPARE(simSystemProposals.at(3).proposalType,int(dslparser::Identifier));
  QCOMPARE(simSystemProposals.at(3).proposalText,QString("spenat1.defaultPort1_3"));

  QCOMPARE(simSystemProposals.at(4).proposalType,int(dslparser::Identifier));
  QCOMPARE(simSystemProposals.at(4).proposalText,QString("spenat2.defaultPort2_1"));

  QCOMPARE(simSystemProposals.at(5).proposalType,int(dslparser::Identifier));
  QCOMPARE(simSystemProposals.at(5).proposalText,QString("spenat2.defaultPort2_2"));

  QCOMPARE(simSystemProposals.at(6).proposalType,int(dslparser::Identifier));
  QCOMPARE(simSystemProposals.at(6).proposalText,QString("spenat2.defaultPort2_3"));

  return;
}

void SimSystemProposalTest::simpleSimSystemProposalTest_9()
{
  QString docText("import <statemachine_example.statemachine> as machine\n"
                  "import <spenat_example1.spenat> as spenat1\n"
                  "import <spenat_example2.spenat> as spenat2\n"
                  "SimSystem mySimSystem{\n"
                    );
  QString prefix = ":/Examples/";
  modsim::SimSystemModel simSystemModel;
  modsim::ComCreateSimSystemProposals command(docText, prefix, &simSystemModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  const dslparser::DslProposalList simSystemProposals = command.simSystemProposals();
  QCOMPARE(simSystemProposals.size(),1);
  QCOMPARE(simSystemProposals.at(0).proposalType,int(dslparser::Connection));
  QCOMPARE(simSystemProposals.at(0).proposalText,QString("Connection"));

  return;
}

void SimSystemProposalTest::simpleSimSystemProposalTest_10()
{
  QString docText("import <statemachine_example.statemachine> as machine\n"
                  "import <spenat_example1.spenat> as spenat1\n"
                  "import <spenat_example2.spenat> as spenat2\n"
                  );
  QString prefix = ":/Examples/";
  modsim::SimSystemModel simSystemModel;
  modsim::ComCreateSimSystemProposals command(docText, prefix, &simSystemModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  const dslparser::DslProposalList simSystemProposals = command.simSystemProposals();
  QCOMPARE(simSystemProposals.size(),2);

  QCOMPARE(simSystemProposals.at(0).proposalType,int(dslparser::SimSystem));
  QCOMPARE(simSystemProposals.at(0).proposalText,QString("SimSystem"));

  QCOMPARE(simSystemProposals.at(1).proposalType,int(dslparser::Import));
  QCOMPARE(simSystemProposals.at(1).proposalText,QString("import"));
  return;
}

void SimSystemProposalTest::simpleSimSystemProposalTest_11()
{
  QString docText("import <statemachine_example.statemachine> as machine\n"
                  "import <spenat_example1.spenat> as spenat1\n"
                  "import <spen");
  QString prefix = ":/Examples/";
  modsim::SimSystemModel simSystemModel;
  modsim::ComCreateSimSystemProposals command(docText, prefix, &simSystemModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  const dslparser::DslProposalList simSystemProposals = command.simSystemProposals();
  QCOMPARE(simSystemProposals.size(),2);
  QCOMPARE(simSystemProposals.at(0).proposalType,int(dslparser::Identifier));
  QCOMPARE(simSystemProposals.at(0).proposalText,QString("spenat_example1.spenat"));

  QCOMPARE(simSystemProposals.at(1).proposalType,int(dslparser::Identifier));
  QCOMPARE(simSystemProposals.at(1).proposalText,QString("spenat_example2.spenat"));

  return;
}

void SimSystemProposalTest::simpleSimSystemProposalTest_12()
{
  QString docText("import <");
  QString prefix = ":/Examples/";
  modsim::SimSystemModel simSystemModel;
  modsim::ComCreateSimSystemProposals command(docText, prefix, &simSystemModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  const dslparser::DslProposalList simSystemProposals = command.simSystemProposals();
  QCOMPARE(simSystemProposals.size(),4);
  QCOMPARE(simSystemProposals.at(0).proposalType,int(dslparser::Range));
  QCOMPARE(simSystemProposals.at(0).proposalText,QString(".."));

  QCOMPARE(simSystemProposals.at(1).proposalType,int(dslparser::Identifier));
  QCOMPARE(simSystemProposals.at(1).proposalText,QString("spenat_example1.spenat"));

  QCOMPARE(simSystemProposals.at(2).proposalType,int(dslparser::Identifier));
  QCOMPARE(simSystemProposals.at(2).proposalText,QString("spenat_example2.spenat"));

  QCOMPARE(simSystemProposals.at(3).proposalType,int(dslparser::Identifier));
  QCOMPARE(simSystemProposals.at(3).proposalText,QString("statemachine_example.statemachine"));
  return;
}

void SimSystemProposalTest::simpleSimSystemProposalTest_13()
{
  QString docText("import <Ping.statemachine> as ping\n"
                  "import <Pong.statemachine> as pong\n"
                  "SimSystem ping_pong{\n"
                    "Connection{\n"
                      "ping.p_pong <-> pong.p_ping;\n"
                    "}\n"
                    "Config{\n"
                      "Actor user{\n"
                        "Port port;\n"
                      "}"
                      "startSequence: pong, ping;\n"
                      "Startup{\n"
                        "Message(user.port->pong.p_ext): start();\n");
  QString prefix = ":/Examples/";
  modsim::SimSystemModel simSystemModel;
  modsim::ComCreateSimSystemProposals command(docText, prefix, &simSystemModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  const dslparser::DslProposalList simSystemProposals = command.simSystemProposals();
  QCOMPARE(simSystemProposals.size(),1);
  QCOMPARE(simSystemProposals.at(0).proposalType,int(dslparser::Message));
  QCOMPARE(simSystemProposals.at(0).proposalText,QString("Message"));
  return;
}

void SimSystemProposalTest::simpleSimSystemProposalTest_14()
{
  QString docText("import <Ping.statemachine> as ping\n"
                  "import <Pong.statemachine> as pong\n"
                  "SimSystem ping_pong{\n"
                    "Connection{\n"
                      "ping.p_pong <-> pong.p_ping;\n"
                    "}\n"
                    "Config{\n"
                      "Act");
  QString prefix = ":/Examples/";
  modsim::SimSystemModel simSystemModel;
  modsim::ComCreateSimSystemProposals command(docText, prefix, &simSystemModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  const dslparser::DslProposalList simSystemProposals = command.simSystemProposals();
  QCOMPARE(simSystemProposals.size(),1);
  QCOMPARE(simSystemProposals.at(0).proposalType,int(dslparser::SimSystemActor));
  QCOMPARE(simSystemProposals.at(0).proposalText,QString("Actor"));

  return;
}

void SimSystemProposalTest::simpleSimSystemProposalTest_15()
{
  QString docText("import <Ping.statemachine> as ping\n"
                  "import <Pong.statemachine> as pong\n"
                  "SimSystem ping_pong{\n"
                    "Connection{\n"
                      "ping.p_pong <-> pong.p_ping;\n"
                    "}\n"
                    "Config{\n"
                      "Actor user{\n"
                        "Port port;\n"
                      "}"
                      "startS");
  QString prefix = ":/Examples/";
  modsim::SimSystemModel simSystemModel;
  modsim::ComCreateSimSystemProposals command(docText, prefix, &simSystemModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  const dslparser::DslProposalList simSystemProposals = command.simSystemProposals();
  QCOMPARE(simSystemProposals.size(),1);
  QCOMPARE(simSystemProposals.at(0).proposalType,int(dslparser::StartSequence));
  QCOMPARE(simSystemProposals.at(0).proposalText,QString("startSequence"));
  return;
}

void SimSystemProposalTest::simpleSimSystemProposalTest_16()
{
  QString docText("import <Ping.statemachine> as ping\n"
                  "import <Pong.statemachine> as pong\n"
                  "SimSystem ping_pong{\n"
                    "Connection{\n"
                      "ping.p_pong <-> pong.p_ping;\n"
                    "}\n"
                    "Config{\n"
                      "Actor user{\n"
                        "Port port;\n"
                      "}"
                      "startSequence: pong, ping;\n");
  QString prefix = ":/Examples/";
  modsim::SimSystemModel simSystemModel;
  modsim::ComCreateSimSystemProposals command(docText, prefix, &simSystemModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  const dslparser::DslProposalList simSystemProposals = command.simSystemProposals();
  QCOMPARE(simSystemProposals.size(),1);
  QCOMPARE(simSystemProposals.at(0).proposalType,int(dslparser::Startup));
  QCOMPARE(simSystemProposals.at(0).proposalText,QString("Startup"));
  return;
}

QTEST_GUILESS_MAIN(SimSystemProposalTest)

#include "tst_simsystemproposals.moc"
