#include <QtTest>

#include <modsim/simsystemmodel.hpp>
#include <modsim/simsystemitem.hpp>
#include <modsim/simconnectionitem.hpp>
#include <modsim/simconfigitem.hpp>
#include <modsim/combuildsimsystemmodel.hpp>
#include <mobata/model/base/attributeitem.hpp>
#include <mobata/model/base/base_types.hpp>

using namespace modsim;

class SimSystemSyntaxTest
    : public QObject
{
  Q_OBJECT

public:
  SimSystemSyntaxTest();

private Q_SLOTS:
  void initTest();
  void cleanupTest();
  void simpleSimSystemDeclTest_1();
  void simpleSimSystemDeclTest_2();
  void simpleSimSystemDeclTest_3();
  void simpleSimSystemDeclErrorTest1();
  void simpleSimSystemDeclErrorTest2();
  void simpleSimSystemDeclErrorTest3();
  void simpleSimSystemDeclErrorTest4();
  void simpleSimSystemDeclErrorTest5();
  void simpleSimSystemDeclErrorTest6();

  void simpleSimSystemDeclErrorSyntaxTest1();
  void simpleSimSystemDeclErrorSyntaxTest2();
  void simpleSimSystemDeclErrorSyntaxTest3();
  void simpleSimSystemDeclErrorSyntaxTest4();
  void simpleSimSystemDeclErrorSyntaxTest5();
  void simpleSimSystemDeclErrorSyntaxTest6();
  void simpleSimSystemDeclErrorSyntaxTest7();
};

SimSystemSyntaxTest::SimSystemSyntaxTest()
{}

void SimSystemSyntaxTest::initTest()
{}

void SimSystemSyntaxTest::cleanupTest()
{}

void SimSystemSyntaxTest::simpleSimSystemDeclTest_1()
{
  QString docText("import <spenat_example.spenat> as spenat\n"
                  "import <statemachine_example.statemachine> as machine\n"
                  "SimSystem mySimSystem{\n"
                    "Connection{\n"
                      "machine.defaultPort <-> spenat.defaultPort;\n"
                    "}\n"
                    "Config{\n"
                      "startSequence: machine, spenat;\n"
                    "}\n"
                  "}\n");
  QString prefix = ":/Examples/";
  SimSystemModel simSystemModel;
  SimSystemItem* simSystemItem=simSystemModel.simSystemItem();
  QVERIFY(simSystemItem);
  modsim::ComBuildSimSystemModel command(docText, simSystemItem, prefix);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("mySimSystem"), simSystemItem->name());
  SimConfigItem *localSimConfigItem = simSystemItem->simConfigItem();
  QVERIFY(localSimConfigItem);
  QCOMPARE(QStringList({QString("machine"), QString("spenat")}),localSimConfigItem->startSequence());
  QList<SimConnectionItem *> localSimConnnetionItems = simSystemItem->simConnnetionItems();
  QCOMPARE(1,localSimConnnetionItems.size());
  SimConnectionItem * conItem = localSimConnnetionItems[0];
  QCOMPARE(QString("machine"),conItem->sourceModel());
  QCOMPARE(QString("defaultPort"),conItem->sourcePort());
  QCOMPARE(QString("spenat"),conItem->targetModel());
  QCOMPARE(QString("defaultPort"),conItem->targetPort());
  QList<SimModelItem *> localSimModelItems = simSystemItem->simModelItems();
  QCOMPARE(localSimModelItems.size(), 2);

  return;
}

void SimSystemSyntaxTest::simpleSimSystemDeclTest_2()
{
  QString docText("import <spenat_example.spenat> as machine\n"
                  "import <statemachine_example.statemachine> as spenat\n"
                  "SimSystem mySimSystem{\n"
                    "Connection{\n"
                      "machine.defaultPort <-> spenat.defaultPort;\n"
                    "}\n"
                    "Config{\n"
                      "startSequence: machine, spenat;\n"
                    "}\n"
                  "}\n");
  QString prefix = ":/Examples/";
  SimSystemModel simSystemModel;
  SimSystemItem* simSystemItem=simSystemModel.simSystemItem();
  QVERIFY(simSystemItem);
  modsim::ComBuildSimSystemModel command(docText, simSystemItem, prefix);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("mySimSystem"), simSystemItem->name());
  SimConfigItem *localSimConfigItem = simSystemItem->simConfigItem();
  QVERIFY(localSimConfigItem);
  QCOMPARE(QStringList({QString("machine"), QString("spenat")}),localSimConfigItem->startSequence());
  QList<SimConnectionItem *> localSimConnnetionItems = simSystemItem->simConnnetionItems();
  QCOMPARE(1,localSimConnnetionItems.size());
  SimConnectionItem * conItem = localSimConnnetionItems[0];
  QCOMPARE(QString("machine"),conItem->sourceModel());
  QCOMPARE(QString("defaultPort"),conItem->sourcePort());
  QCOMPARE(QString("spenat"),conItem->targetModel());
  QCOMPARE(QString("defaultPort"),conItem->targetPort());
  return;
}

void SimSystemSyntaxTest::simpleSimSystemDeclTest_3()
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
                        "Message(user.port->pong.p_ext): start();\n"
                        "Message(user.port->ping.p_ext): start();\n"
                       "}\n"
                    "}\n"
                  "}\n");
  QString prefix = ":/Examples/";
  SimSystemModel simSystemModel;
  SimSystemItem* simSystemItem=simSystemModel.simSystemItem();
  QVERIFY(simSystemItem);
  modsim::ComBuildSimSystemModel command(docText, simSystemItem, prefix);

  QString errorString;
  bool result = command.execute(&errorString);
  if(!result)
    qDebug()<<"error: "<<errorString;
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("ping_pong"), simSystemItem->name());
  SimConfigItem *localSimConfigItem = simSystemItem->simConfigItem();
  QVERIFY(localSimConfigItem);
  QCOMPARE(QStringList({QString("pong"), QString("ping")}),localSimConfigItem->startSequence());
  QList<SimConnectionItem *> localSimConnnetionItems = simSystemItem->simConnnetionItems();
  QCOMPARE(1,localSimConnnetionItems.size());
  SimConnectionItem * conItem = localSimConnnetionItems[0];
  QCOMPARE(QString("ping"),conItem->sourceModel());
  QCOMPARE(QString("p_pong"),conItem->sourcePort());
  QCOMPARE(QString("pong"),conItem->targetModel());
  QCOMPARE(QString("p_ping"),conItem->targetPort());

  return;
}

void SimSystemSyntaxTest::simpleSimSystemDeclErrorTest1()
{
  QString docText("import <spenat_example.spenat> as spenat\n"
                  "import <statemachine_example.statemachine> as machine1\n"
                  "SimSystem mySimSystem{\n"
                    "Connection{\n"
                      "machine.defaultPort <-> spenat.defaultPort;\n"
                    "}\n"
                    "Config{\n"
                      "startSequence: machine, spenat;\n"
                    "}\n"
                  "}\n");
  QString prefix = ":/Examples/";
  SimSystemModel simSystemModel;
  SimSystemItem* simSystemItem=simSystemModel.simSystemItem();
  QVERIFY(simSystemItem);
  modsim::ComBuildSimSystemModel command(docText, simSystemItem, prefix);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  return;
}

void SimSystemSyntaxTest::simpleSimSystemDeclErrorTest2()
{
  QString docText("import <spenat_example.spenat> as spenat1\n"
                  "import <statemachine_example.statemachine> as machine\n"
                  "SimSystem mySimSystem{\n"
                    "Connection{\n"
                      "machine.defaultPort <-> spenat.defaultPort;\n"
                    "}\n"
                    "Config{\n"
                      "startSequence: machine, spenat;\n"
                    "}\n"
                  "}\n");
  QString prefix = ":/Examples/";
  SimSystemModel simSystemModel;
  SimSystemItem* simSystemItem=simSystemModel.simSystemItem();
  QVERIFY(simSystemItem);
  modsim::ComBuildSimSystemModel command(docText, simSystemItem, prefix);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  return;
}

void SimSystemSyntaxTest::simpleSimSystemDeclErrorTest3()
{
  QString docText("import <spenat_example.spenat> as spenat\n"
                  "import <statemachine_example.statemachine> as machine\n"
                  "SimSystem mySimSystem{\n"
                    "Connection{\n"
                      "machine.defaultPort1 <-> spenat.defaultPort;\n"
                    "}\n"
                    "Config{\n"
                      "startSequence: machine, spenat;\n"
                    "}\n"
                  "}\n");
  QString prefix = ":/Examples/";
  SimSystemModel simSystemModel;
  SimSystemItem* simSystemItem=simSystemModel.simSystemItem();
  QVERIFY(simSystemItem);
  modsim::ComBuildSimSystemModel command(docText, simSystemItem, prefix);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  return;
}

void SimSystemSyntaxTest::simpleSimSystemDeclErrorTest4()
{
  QString docText("import <spenat_example.spenat> as spenat\n"
                  "import <statemachine_example.statemachine> as machine\n"
                  "SimSystem mySimSystem{\n"
                    "Connection{\n"
                      "machine.defaultPort <-> spenat.defaultPort1;\n"
                    "}\n"
                    "Config{\n"
                      "startSequence: machine, spenat;\n"
                    "}\n"
                  "}\n");
  QString prefix = ":/Examples/";
  SimSystemModel simSystemModel;
  SimSystemItem* simSystemItem=simSystemModel.simSystemItem();
  QVERIFY(simSystemItem);
  modsim::ComBuildSimSystemModel command(docText, simSystemItem, prefix);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  return;
}

void SimSystemSyntaxTest::simpleSimSystemDeclErrorTest5()
{
  QString docText("import <spenat_example.spenat> as spenat\n"
                  "import <statemachine_example.statemachine> as machine\n"
                  "SimSystem mySimSystem{\n"
                    "Connection{\n"
                      "machine.defaultPort <-> spenat.defaultPort;\n"
                    "}\n"
                    "Config{\n"
                      "startSequence: machine1, spenat;\n"
                    "}\n"
                  "}\n");
  QString prefix = ":/Examples/";
  SimSystemModel simSystemModel;
  SimSystemItem* simSystemItem=simSystemModel.simSystemItem();
  QVERIFY(simSystemItem);
  modsim::ComBuildSimSystemModel command(docText, simSystemItem, prefix);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  return;
}

void SimSystemSyntaxTest::simpleSimSystemDeclErrorTest6()
{
  QString docText("import <spenat_example.spenat> as spenat\n"
                  "import <statemachine_example.statemachine> as machine\n"
                  "SimSystem mySimSystem{\n"
                    "Connection{\n"
                      "machine.defaultPort <-> spenat.defaultPort;\n"
                    "}\n"
                    "Config{\n"
                      "startSequence: machine, spenat1;\n"
                    "}\n"
                  "}\n");
  QString prefix = ":/Examples/";
  SimSystemModel simSystemModel;
  SimSystemItem* simSystemItem=simSystemModel.simSystemItem();
  QVERIFY(simSystemItem);
  modsim::ComBuildSimSystemModel command(docText, simSystemItem, prefix);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  return;
}

void SimSystemSyntaxTest::simpleSimSystemDeclErrorSyntaxTest1()
{
  QString docText("import <spenat_example.spenat> as spenat\n"
                  "import <statemachine_example.statemachine> as machine\n"
                  "SimSystem mySimSystem{\n"
                    "Connection{\n"
                      "machine.defaultPort <-> spenat.defaultPort;\n"
                    "}\n"
                    "Config{\n"
                      "startSequence: machine, spenat;\n"
                    "}\n"
                  "\n");
  QString prefix = ":/Examples/";
  SimSystemModel simSystemModel;
  SimSystemItem* simSystemItem=simSystemModel.simSystemItem();
  QVERIFY(simSystemItem);
  modsim::ComBuildSimSystemModel command(docText, simSystemItem, prefix);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  return;
}

void SimSystemSyntaxTest::simpleSimSystemDeclErrorSyntaxTest2()
{
  QString docText("import <spenat_example.spenat> as spenat\n"
                  "import <statemachine_example.statemachine> as machine\n"
                  "SimSystem mySimSystem{\n"
                    "Connection{\n"
                      "machine.defaultPort <-> spenat.defaultPort;\n"
                    "}\n"
                    "Config{\n"
                      "sartSequence: machine, spenat;\n"
                    "}\n"
                  "}\n");
  QString prefix = ":/Examples/";
  SimSystemModel simSystemModel;
  SimSystemItem* simSystemItem=simSystemModel.simSystemItem();
  QVERIFY(simSystemItem);
  modsim::ComBuildSimSystemModel command(docText, simSystemItem, prefix);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  return;
}

void SimSystemSyntaxTest::simpleSimSystemDeclErrorSyntaxTest3()
{
  QString docText("import <spenat_example.spenat> as spenat\n"
                  "import <statemchine_example.statemachine> as machine\n"
                  "SimSystem mySimSystem{\n"
                    "Connection{\n"
                      "machine.defaultPort <-> spenat.defaultPort;\n"
                    "}\n"
                    "Config{\n"
                      "startSequence: machine, spenat;\n"
                    "}\n"
                  "}\n");
  QString prefix = ":/Examples/";
  SimSystemModel simSystemModel;
  SimSystemItem* simSystemItem=simSystemModel.simSystemItem();
  QVERIFY(simSystemItem);
  modsim::ComBuildSimSystemModel command(docText, simSystemItem, prefix);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(2, command.errors().count());
  return;
}

void SimSystemSyntaxTest::simpleSimSystemDeclErrorSyntaxTest4()
{
  QString docText("import <spenat_example.spenat> as spenat\n"
                  "import <statemachine_example.statemachine> as machine\n"
                  "SimSystem mySimSystem{\n"
                    "Connection{\n"
                      "machine.defaultPort \n"
                    "}\n"
                    "Config{\n"
                      "startSequence: machine, spenat;\n"
                    "}\n"
                  "}\n");
  QString prefix = ":/Examples/";
  SimSystemModel simSystemModel;
  SimSystemItem* simSystemItem=simSystemModel.simSystemItem();
  QVERIFY(simSystemItem);
  modsim::ComBuildSimSystemModel command(docText, simSystemItem, prefix);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  for(auto error : command.errors())
    qDebug()<<"error: "<<error.message();
  QCOMPARE(1, command.errors().count());
  return;
}

void SimSystemSyntaxTest::simpleSimSystemDeclErrorSyntaxTest5()
{
  QString docText("import <spenat_example.spenat> as spenat\n"
                  "import <statemachine_example.statemachine> as machine\n"
                  "SimSystem mySimSystem{\n"
                    "Connection{\n"
                      " <-> spenat.defaultPort;\n"
                    "}\n"
                    "Config{\n"
                      "startSequence: machine, spenat;\n"
                    "}\n"
                  "}\n");
  QString prefix = ":/Examples/";
  SimSystemModel simSystemModel;
  SimSystemItem* simSystemItem=simSystemModel.simSystemItem();
  QVERIFY(simSystemItem);
  modsim::ComBuildSimSystemModel command(docText, simSystemItem, prefix);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(2, command.errors().count());
  return;
}

void SimSystemSyntaxTest::simpleSimSystemDeclErrorSyntaxTest6()
{
  QString docText("import <spenat_example.spenat> as spenat\n"
                  "import <statemachine_example.statemachine> as machine\n"
                  "SimSystem mySimSystem{\n"
                    "Connection{\n"
                      "machine.defaultPort spenat.defaultPort;\n"
                    "}\n"
                    "Config{\n"
                      "startSequence: machine, spenat;\n"
                    "}\n"
                  "}\n");
  QString prefix = ":/Examples/";
  SimSystemModel simSystemModel;
  SimSystemItem* simSystemItem=simSystemModel.simSystemItem();
  QVERIFY(simSystemItem);
  modsim::ComBuildSimSystemModel command(docText, simSystemItem, prefix);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  return;
}

void SimSystemSyntaxTest::simpleSimSystemDeclErrorSyntaxTest7()
{
  QString docText("import <spenat_example.spenat> as spenat\n"
                  "import <statemachine_example.statemachine> as machine\n"
                  "SimSystem mySimSystem{\n"
                    "Connection{\n"
                      "machine.defaultPort <-> spenat.defaultPort;\n"
                    "}\n"
                    "Config{\n"
                      "startSequence: machine, machine;\n"
                    "}\n"
                  "}\n");
  QString prefix = ":/Examples/";
  SimSystemModel simSystemModel;
  SimSystemItem* simSystemItem=simSystemModel.simSystemItem();
  QVERIFY(simSystemItem);
  modsim::ComBuildSimSystemModel command(docText, simSystemItem, prefix);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  return;
}


QTEST_GUILESS_MAIN(SimSystemSyntaxTest)

#include "tst_simsystemsyntax.moc"
