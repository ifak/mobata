#include <QtTest>

#include <mobata/model/base/portitem.hpp>
#include <mobata/model/base/signalitem.hpp>
#include <mobata/model/spenat/spenatdeclmodel.hpp>
#include <mobata/model/spenat/placeitem.hpp>
#include <mobata/model/spenat/transitionitem.hpp>
#include <mobata/model/base/timeouttriggeritem.hpp>

#include <dslparser/spenat/combuildspenatmodel.hpp>

class SpenatSyntaxTest
    : public QObject
{
  Q_OBJECT

public:
  SpenatSyntaxTest();

private Q_SLOTS:
  void initTest();
  void cleanupTest();
  void helloSpenatParserTest();
  void simpleSpenatDeclTest();
  void simpleSpenatDeclErrorTest_1();
  void simpleSpenatDeclErrorTest_2();
  void spenatPlaceDeclTest_1();
  void spenatPlaceDeclTest_2();
  void spenatPlaceDeclTest_3();
  void spenatPlaceDeclTest_4();
  void spenatTransitionDeclTest_1();
  void spenatTransitionDeclTest_1_1();
  void spenatTransitionDeclTest_1_2();
  void spenatTransitionDeclTest_2();
  void spenatTransitionDeclTest_3();
  void spenatTransitionDeclTest_4();
  void spenatTransitionDeclTest_5();
  void spenatTransitionDeclTest_6();
  void spenatTransitionDeclTest_7();
  void spenatTransitionDeclQualityTest_1();
  void spenatTransitionDeclQualityTest_2();
  void spenatTransitionDeclQualityTest_3();
  void spenatTransitionDeclQualityTest_4();
  void spenatTransitionDeclQualityTest_5();
  void spenatTransitionDeclQualityTest_6();
  void spenatTransitionDeclQualityTest_7();
  void spenatTransitionDeclQualityTest_8();
  void spenatTransitionDeclQualityTest_9();
  void spenatTransitionDeclQualityTest_10();
  void spenatTransitionDeclQualityTest_11();
  void spenatTransitionDeclQualityTest_12();
  void spenatSignalDeclTest_1();
  void spenatSignalDeclTest_2();
  void spenatSignalDeclTest_3();
  void spenatSignalDeclTest_4();
  void spenatSignalDeclTest_5();
  void spenatSignalDeclTest_6();
  void spenatPortDeclTest_1();
  void spenatPortDeclTest_2();
  void spenatPortDeclTest_3();
  void spenatPortDeclTest_4();
};

SpenatSyntaxTest::SpenatSyntaxTest()
{}

void SpenatSyntaxTest::initTest()
{}

void SpenatSyntaxTest::cleanupTest()
{}

void SpenatSyntaxTest::helloSpenatParserTest()
{
  QString docText(L'\u2029');
  docText+=" ";
  docText+=QChar(L'\u2029');
  docText+=" what ";
  docText+=QChar(L'\u2029');
  docText+=" is up!";

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());

  dslparser::DslError firstError = command.errors().at(0);
  QCOMPARE(3, int(firstError.line()));
  QCOMPARE(1, firstError.charPositionInLine());
  QCOMPARE(QString(
"what"), firstError.offendingText());
  QCOMPARE(0, spenatDeclModel.places().count());
  QCOMPARE(0, spenatDeclModel.transitions().count());
  //  QVERIFY2(errorMessage.isEmpty(), errorMessage.toLatin1());

  QCOMPARE(0, command.keywordTextLocations().size());
  QCOMPARE(0, command.modelTextLocations().size());

  return;
}

void SpenatSyntaxTest::simpleSpenatDeclTest()
{
  QString docText(L'\u2029');
  docText+=" ";
  docText+=QChar(L'\u2029');
  docText+=" Spenat{ ";
  docText+=QChar(L'\u2029');
  docText+=" name: mySpenat;}";

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());

  QCOMPARE(QString("mySpenat"), spenatDeclModel.name());

  QCOMPARE(0, spenatDeclModel.places().count());
  QCOMPARE(0, spenatDeclModel.transitions().count());

  QCOMPARE(2, command.keywordTextLocations().size());
  QCOMPARE(command.keywordTextLocations().at(0).start(), 4);
  QCOMPARE(command.keywordTextLocations().at(0).length(), 6);
  QCOMPARE(command.keywordTextLocations().at(1).start(), 14);
  QCOMPARE(command.keywordTextLocations().at(1).length(), 4);
  QCOMPARE(0, command.modelTextLocations().size());

  return;
}

void SpenatSyntaxTest::simpleSpenatDeclErrorTest_1()
{
  QString docText(L'\u2029');
  docText+=" ";
  docText+=QChar(L'\u2029');
  docText+=" Spenat{ ";
  docText+=QChar(L'\u2029');
  docText+=" name: mySp\nenat;}";

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());

  dslparser::DslError firstError = command.errors().at(0);
  QCOMPARE(5, int(firstError.line()));
  QCOMPARE(0, firstError.charPositionInLine());
  QCOMPARE(QString("enat"), firstError.offendingText());

  QCOMPARE(0, spenatDeclModel.places().count());
  QCOMPARE(0, spenatDeclModel.transitions().count());

  QCOMPARE(2, command.keywordTextLocations().size());
  QCOMPARE(command.keywordTextLocations().at(0).start(), 4);
  QCOMPARE(command.keywordTextLocations().at(0).length(), 6);
  QCOMPARE(command.keywordTextLocations().at(1).start(), 14);
  QCOMPARE(command.keywordTextLocations().at(1).length(), 4);
  QCOMPARE(0, command.modelTextLocations().size());

  return;
}

void SpenatSyntaxTest::simpleSpenatDeclErrorTest_2()
{
  QString docText(L'\u2029');
  docText+=" ";
  docText+=QChar(L'\u2029');
  docText+=" Spenat{ ";
  docText+=QChar(L'\u2029');
  docText+=" name: mySpenat;";

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());

  dslparser::DslError firstError = command.errors().at(0);
  QCOMPARE(4, int(firstError.line()));
  QCOMPARE(16, firstError.charPositionInLine());
  QCOMPARE(QString("<EOF>"), firstError.offendingText());

  QCOMPARE(0, spenatDeclModel.places().count());
  QCOMPARE(0, spenatDeclModel.transitions().count());

  QCOMPARE(2, command.keywordTextLocations().size());
  QCOMPARE(command.keywordTextLocations().at(0).start(), 4);
  QCOMPARE(command.keywordTextLocations().at(0).length(), 6);
  QCOMPARE(command.keywordTextLocations().at(1).start(), 14);
  QCOMPARE(command.keywordTextLocations().at(1).length(), 4);
  QCOMPARE(0, command.modelTextLocations().size());

  return;
}

void SpenatSyntaxTest::spenatPlaceDeclTest_1()
{
  QString docText("Spenat{name: mySpenat; Place{name: p1;}}");

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());

  QCOMPARE(1, spenatDeclModel.places().count());
  QCOMPARE(QString("p1"), spenatDeclModel.places().at(0)->name());
  QCOMPARE(0, spenatDeclModel.transitions().count());

  QCOMPARE(4, command.keywordTextLocations().size());
  QCOMPARE(command.keywordTextLocations().at(0).start(), 0);
  QCOMPARE(command.keywordTextLocations().at(0).length(), 6);
  QCOMPARE(command.keywordTextLocations().at(1).start(), 7);
  QCOMPARE(command.keywordTextLocations().at(1).length(), 4);
  QCOMPARE(command.keywordTextLocations().at(2).start(), 23);
  QCOMPARE(command.keywordTextLocations().at(2).length(), 5);
  QCOMPARE(command.keywordTextLocations().at(3).start(), 29);
  QCOMPARE(command.keywordTextLocations().at(3).length(), 4);
  QCOMPARE(1, command.modelTextLocations().size());

  return;
}

void SpenatSyntaxTest::spenatPlaceDeclTest_2()
{
  QString docText("Spenat{name: mySpenat; Place{name: p1;} Place{name: p1;} }");

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());

  dslparser::DslError firstError = command.errors().at(0);
  QCOMPARE(1, int(firstError.line()));
  QCOMPARE(firstError.charPositionInLine(), 40);
  QCOMPARE(QString(""), firstError.offendingText());

  QCOMPARE(1, spenatDeclModel.places().count());
  QCOMPARE(QString("p1"), spenatDeclModel.places().at(0)->name());
  QCOMPARE(0, spenatDeclModel.transitions().count());

  QCOMPARE(6, command.keywordTextLocations().size());
  QCOMPARE(1, command.modelTextLocations().size());

  return;
}

void SpenatSyntaxTest::spenatPlaceDeclTest_3()
{
  QString docText("Spenat{name: mySpenat; Place{name: p1;} Place{name: p1;} Place{name: p2;} }");

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());

  dslparser::DslError firstError = command.errors().at(0);
  QCOMPARE(1, int(firstError.line()));
  QCOMPARE(40, firstError.charPositionInLine());
  QCOMPARE(QString(""), firstError.offendingText());

  QCOMPARE(2, spenatDeclModel.places().count());
  QCOMPARE(QString("p1"), spenatDeclModel.places().at(0)->name());
  QCOMPARE(QString("p2"), spenatDeclModel.places().at(1)->name());
  QCOMPARE(0, spenatDeclModel.transitions().count());

  QCOMPARE(8, command.keywordTextLocations().size());
  QCOMPARE(2, command.modelTextLocations().size());

  return;
}

void SpenatSyntaxTest::spenatPlaceDeclTest_4()
{
  QString docText("Spenat{name: mySpenat; Place }");

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());

  dslparser::DslError firstError = command.errors().at(0);
  QCOMPARE(1, int(firstError.line()));
  QCOMPARE(29, firstError.charPositionInLine());
  QCOMPARE(QString("}"), firstError.offendingText());

  QCOMPARE(0, spenatDeclModel.places().count());
  QCOMPARE(0, spenatDeclModel.transitions().count());

  QCOMPARE(3, command.keywordTextLocations().size());
  QCOMPARE(0, command.modelTextLocations().size());

  return;
}

void SpenatSyntaxTest::spenatTransitionDeclTest_1()
{
  QString docText("Spenat{name: mySpenat; SignalTransition{name: t1;}}");

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());

  QCOMPARE(0, spenatDeclModel.places().count());
  QCOMPARE(1, spenatDeclModel.transitions().count());
  QCOMPARE(QString("t1"), spenatDeclModel.transitions().at(0)->name());

  QCOMPARE(4, command.keywordTextLocations().size());
  QCOMPARE(1, command.modelTextLocations().size());

  return;
}

void SpenatSyntaxTest::spenatTransitionDeclTest_1_1()
{
  QString docText("Spenat{name: mySpenat; SignalTransition }");

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());

  QCOMPARE(0, spenatDeclModel.places().count());
  QCOMPARE(0, spenatDeclModel.transitions().count());

  QCOMPARE(3, command.keywordTextLocations().size());
  QCOMPARE(0, command.modelTextLocations().size());

  return;
}

void SpenatSyntaxTest::spenatTransitionDeclTest_1_2()
{
  QString docText("Spenat{name: mySpenat; TimeoutTransition }");

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());

  QCOMPARE(0, spenatDeclModel.places().count());
  QCOMPARE(0, spenatDeclModel.transitions().count());

  QCOMPARE(3, command.keywordTextLocations().size());
  QCOMPARE(0, command.modelTextLocations().size());

  return;
}

void SpenatSyntaxTest::spenatTransitionDeclTest_2()
{
  QString docText("Spenat{name: mySpenat; "
                  "SignalTransition{name: t1;} "
                  "TimeoutTransition{name: t1;} }");

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());

  dslparser::DslError firstError = command.errors().at(0);
  QCOMPARE(1, int(firstError.line()));
  QCOMPARE(51, firstError.charPositionInLine());
  QCOMPARE(QString(""), firstError.offendingText());

  QCOMPARE(0, spenatDeclModel.places().count());
  QCOMPARE(1, spenatDeclModel.transitions().count());
  QCOMPARE(QString("t1"), spenatDeclModel.transitions().at(0)->name());

  QCOMPARE(6, command.keywordTextLocations().size());
  QCOMPARE(1, command.modelTextLocations().size());

  return;
}

void SpenatSyntaxTest::spenatTransitionDeclTest_3()
{
  QString docText("Spenat{name: mySpenat; \n"
                  "Port in_port, out_port;\n"
                  "Attribute int attr1 = 0;\n"
                  "Attribute int attr2 = 0;\n"
                  "Signal input(int in);\n"
                  "Signal output(int out);\n"
                  "SignalTransition{name: t1;\n"
                                   "signal: input;\n"
                                   "port: in_port;\n"
                                   "guard: trigger.in>20; \n"
                                   "action:{ \n"
                                        "this.attr2=trigger.in; \n"
                                        "send output(this.attr2) to out_port; }} \n"
                  "TimeoutTransition{name: t2; value: 10.0;\n"
                  "guard: {this.attr1 > 0}\n"
                  "action:{\n"
                    "send output(this.attr1) to out_port;}}\n"
                  "}");

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());

  QCOMPARE(0, spenatDeclModel.places().count());
  QCOMPARE(2, spenatDeclModel.transitions().count());
  QCOMPARE(QString("t1"), spenatDeclModel.transitions().at(0)->name());
  QCOMPARE(QString("trigger.in>20"), spenatDeclModel.transitions().at(0)->guard());
  QCOMPARE(QString("this.attr2=trigger.in; \nsend output(this.attr2) to out_port;"), spenatDeclModel.transitions().at(0)->actions());
  QCOMPARE(QString("t2"), spenatDeclModel.transitions().at(1)->name());
  QCOMPARE(10.0, ((model::base::TimeoutTriggerItem*)spenatDeclModel.transitions().at(1)->triggerItem())->value());
  QCOMPARE(QString("this.attr1 > 0"), spenatDeclModel.transitions().at(1)->guard());
  QCOMPARE(QString("send output(this.attr1) to out_port;"), spenatDeclModel.transitions().at(1)->actions());

  QCOMPARE(command.keywordTextLocations().size(), 32);
  QCOMPARE(command.modelTextLocations().size(), 8);

  return;
}

void SpenatSyntaxTest::spenatTransitionDeclTest_4()
{
  QString docText("Spenat{name: mySpenat; "
                  "SignalTransition{name: t1;} "
                  "TimeoutTransition{name: t1;} "
                  "TimeoutTransition{name: t2;} }");

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());

  dslparser::DslError firstError = command.errors().at(0);
  QCOMPARE(1, int(firstError.line()));
  QCOMPARE(51, firstError.charPositionInLine());
  QCOMPARE(QString(""), firstError.offendingText());

  QCOMPARE(0, spenatDeclModel.places().count());
  QCOMPARE(2, spenatDeclModel.transitions().count());
  QCOMPARE(QString("t1"), spenatDeclModel.transitions().at(0)->name());
  QCOMPARE(QString("t2"), spenatDeclModel.transitions().at(1)->name());

  QCOMPARE(8, command.keywordTextLocations().size());
  QCOMPARE(2, command.modelTextLocations().size());

  return;
}

void SpenatSyntaxTest::spenatTransitionDeclTest_5()
{
  QString docText("Spenat{name: mySpenat; \n"
                  "Port in_port, out_port;\n"
                  "Attribute int attr1 = 0;\n"
                  "Signal input(int in);\n"
                  "Signal output(int out);\n"
                  "SignalTransition{name: t1;\n"
                                   "signal: input;\n"
                                   "port: in_port;\n"
                                   "guard: trigger.in>20; \n"
                                   "action: this.attr1=10;\n"
                  "} \n"
                  "TimeoutTransition{name: t2; value: 10.0;\n"
                  "guard: {this.attr1 > 0}\n"
                  "action:{\n"
                    "send output(this.attr1) to out_port;}}\n"
                  "}");

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, true);
  QCOMPARE(command.errors().count(), 0);

  QCOMPARE(spenatDeclModel.places().count(), 0);
  QCOMPARE(spenatDeclModel.transitions().count(), 2);
  QCOMPARE(spenatDeclModel.transitions().at(0)->name(), QString("t1"));
  QCOMPARE(spenatDeclModel.transitions().at(0)->guard(), QString("trigger.in>20"));
  QCOMPARE(spenatDeclModel.transitions().at(0)->actions(), QString("this.attr1=10;"));
  QCOMPARE(spenatDeclModel.transitions().at(1)->name(), QString("t2"));
  QVERIFY(spenatDeclModel.transitions().at(1)->triggerItem());
  QCOMPARE(spenatDeclModel.transitions().at(1)->triggerItem()->triggerType(), model::base::ATriggerItem::TimeoutTrigger);
  QCOMPARE(((model::base::TimeoutTriggerItem*)spenatDeclModel.transitions().at(1)->triggerItem())->value(), 10.0);
  QCOMPARE(spenatDeclModel.transitions().at(1)->guard(), QString("this.attr1 > 0"));
  QCOMPARE(spenatDeclModel.transitions().at(1)->actions(), QString("send output(this.attr1) to out_port;"));

  QCOMPARE(command.keywordTextLocations().size(), 26);
  QCOMPARE(command.modelTextLocations().size(), 7);

  return;
}

void SpenatSyntaxTest::spenatTransitionDeclTest_6()
{
  QString docText("Spenat{name: mySpenat; \n"
                  "Attribute int attr1 = 0;\n"
                  "Port in_port, out_port;\n"
                  "Signal input(int in);\n"
                  "Signal output(int out);\n"
                  "SignalTransition{name: t1;\n"
                                   "signal: input;\n"
                                   "port: in_port;\n"
                                   "guard: trigger.in>20; \n"
                                   "action: attr1=10;\n"
                  "} \n"
                  "TimeoutTransition{name: t2; value: 10.0;\n"
                  "guard: {this.attr1 > 0}\n"
                  "action:{\n"
                    "send output(this.attr1) to out_port;}}\n"
                  "}");

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, true);
  QCOMPARE(command.errors().count(), 0);

  QCOMPARE(spenatDeclModel.places().count(), 0);
  QCOMPARE(spenatDeclModel.transitions().count(), 2);
  QCOMPARE(spenatDeclModel.transitions().at(0)->name(), QString("t1"));
  QCOMPARE(spenatDeclModel.transitions().at(0)->guard(), QString("trigger.in>20"));
  QCOMPARE(spenatDeclModel.transitions().at(0)->actions(), QString("attr1=10;"));
  QCOMPARE(spenatDeclModel.transitions().at(1)->name(), QString("t2"));
  QVERIFY(spenatDeclModel.transitions().at(1)->triggerItem());
  QCOMPARE(spenatDeclModel.transitions().at(1)->triggerItem()->triggerType(), model::base::ATriggerItem::TimeoutTrigger);
  QCOMPARE(((model::base::TimeoutTriggerItem*)spenatDeclModel.transitions().at(1)->triggerItem())->value(), 10.0);
  QCOMPARE(spenatDeclModel.transitions().at(1)->guard(), QString("this.attr1 > 0"));
  QCOMPARE(spenatDeclModel.transitions().at(1)->actions(), QString("send output(this.attr1) to out_port;"));

  QCOMPARE(command.keywordTextLocations().size(), 25);
  QCOMPARE(command.modelTextLocations().size(), 7);

  return;
}

void SpenatSyntaxTest::spenatTransitionDeclTest_7()
{
  QString docText("Spenat{name: mySpenat; \n"
                  "Attribute int attr1 = 0;\n"
                  "Port in_port, out_port;\n"
                  "Signal input(int in);\n"
                  "Signal output(int out);\n"
                  "SignalTransition{name: t1;\n"
                                   "signal: input;\n"
                                   "port: in_port;\n"
                                   "guard: trigger.in>20; \n"
                                   "action: send output(this.attr1) to out_port;\n"
                  "} \n"
                  "TimeoutTransition{name: t2; value: 10.0;\n"
                  "guard: {this.attr1 > 0}\n"
                  "action:{\n"
                    "send output(this.attr1) to out_port;}}\n"
                  "}");

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, true);
  QCOMPARE(command.errors().count(), 0);

  QCOMPARE(spenatDeclModel.places().count(), 0);
  QCOMPARE(spenatDeclModel.transitions().count(), 2);
  QCOMPARE(spenatDeclModel.transitions().at(0)->name(), QString("t1"));
  QCOMPARE(spenatDeclModel.transitions().at(0)->guard(), QString("trigger.in>20"));
  QCOMPARE(spenatDeclModel.transitions().at(0)->actions(), QString("send output(this.attr1) to out_port;"));
  QCOMPARE(spenatDeclModel.transitions().at(1)->name(), QString("t2"));
  QVERIFY(spenatDeclModel.transitions().at(1)->triggerItem());
  QCOMPARE(spenatDeclModel.transitions().at(1)->triggerItem()->triggerType(), model::base::ATriggerItem::TimeoutTrigger);
  QCOMPARE(((model::base::TimeoutTriggerItem*)spenatDeclModel.transitions().at(1)->triggerItem())->value(), 10.0);
  QCOMPARE(spenatDeclModel.transitions().at(1)->guard(), QString("this.attr1 > 0"));
  QCOMPARE(spenatDeclModel.transitions().at(1)->actions(), QString("send output(this.attr1) to out_port;"));

  QCOMPARE(command.keywordTextLocations().size(), 28);
  QCOMPARE(command.modelTextLocations().size(), 7);

  return;
}

void SpenatSyntaxTest::spenatTransitionDeclQualityTest_1()
{
    QString docText("Spenat{name: mySpenat; \n"
                    "Attribute int attr2 = 0;\n"
                    "Port out_port;\n"
                    "Signal input(int in);\n"
                    "SignalTransition{name: t1;\n"
                                     "signal: input;\n"
                                     "guard: trigger.in>20; \n"
                                     "action:{ \n"
                                          "this.attr2=trigger.in; \n"
                                          "send output(this.attr2) to out_port; }} \n"
                    "TimeoutTransition{name: t2; value: 10.0;\n"
                    "guard: {this.attr1 > 0}\n"
                    "action:{\n"
                      "send output(this.attr1) to out_port;}}\n"
                    "}");

    model::spenat::SpenatDeclModel spenatDeclModel;
    dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

    QString errorString;
    bool result = command.execute(&errorString);
    for(const dslparser::DslError& error : command.errors())
      qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

    QCOMPARE(result, false);
    QCOMPARE(6, command.errors().count());

  return;
}

void SpenatSyntaxTest::spenatTransitionDeclQualityTest_2()
{
    QString docText("Spenat{name: mySpenat; \n"
                    "Attribute int attr1 = 0;\n"
                    "Attribute int attr2 = 0;\n"
                    "Port in_port, out_port;\n"
                    "Signal input(int in);\n"
                    "SignalTransition{name: t1;\n"
                                     "signal: input;\n"
                                     "port: in_port;\n"
                                     "guard: trigger.in>20; \n"
                                     "action:{ \n"
                                          "this.attr2=trigger.in; \n"
                                          "send output(this.attr2) to out_port; }} \n"
                    "TimeoutTransition{name: t2; value: 10.0;\n"
                    "guard: {this.attr1 > 0}\n"
                    "action:{\n"
                      "send output(this.attr2) to out_port;}}\n"
                    "}");

    model::spenat::SpenatDeclModel spenatDeclModel;
    dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

    QString errorString;
    bool result = command.execute(&errorString);
    for(const dslparser::DslError& error : command.errors())
      qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

    QCOMPARE(result, false);
    QCOMPARE(2, command.errors().count());

  return;
}

void SpenatSyntaxTest::spenatTransitionDeclQualityTest_3()
{
    QString docText("Spenat{name: mySpenat; \n"
                    "Attribute int attr1 = 0;\n"
                    "Attribute int attr2 = 0;\n"
                    "Port in_port, out_port;\n"
                    "Signal input(int in);\n"
                    "Signal output(int out);\n"
                    "SignalTransition{name: t1;\n"
                                     "signal: input;\n"
                                     "port: in_port;\n"
                                     "guard: trigger.attr1>20; \n"
                                     "action:{ \n"
                                          "this.attr2=trigger.in; \n"
                                          "send output(this.attr2) to out_port; }} \n"
                    "TimeoutTransition{name: t2; value: 10.0;\n"
                    "guard: {msg.attr1 > 0}\n"
                    "action:{\n"
                      "send output(this.attr2) to out_port;}}\n"
                    "}");

    model::spenat::SpenatDeclModel spenatDeclModel;
    dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

    QString errorString;
    bool result = command.execute(&errorString);
    for(const dslparser::DslError& error : command.errors())
      qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

    QCOMPARE(result, false);
    QCOMPARE(4, command.errors().count());

  return;
}

void SpenatSyntaxTest::spenatTransitionDeclQualityTest_4()
{
    QString docText("Spenat{name: mySpenat; \n"
                    "Attribute int attr1 = 0;\n"
                    "Attribute int attr2 = 0;\n"
                    "Port in_port, out_port;\n"
                    "Signal input(int in);\n"
                    "SignalTransition{name: t1;\n"
                                     "signal: input;\n"
                                     "port: in_port;\n"
                                     "guard: trigger.in>20; \n"
                                     "action:{ \n"
                                          "this.attr2=trigger.attr2; \n"
                                          "send output(this.attr2) to out_port; }} \n"
                    "TimeoutTransition{name: t2; value: 10.0;\n"
                    "guard: {msg.in > 0}\n"
                    "action:{\n"
                      "send output(this.attr2) to out_port;}}\n"
                    "}");

    model::spenat::SpenatDeclModel spenatDeclModel;
    dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

    QString errorString;
    bool result = command.execute(&errorString);
    for(const dslparser::DslError& error : command.errors())
      qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

    QCOMPARE(result, false);
    QCOMPARE(6, command.errors().count());

  return;
}

void SpenatSyntaxTest::spenatTransitionDeclQualityTest_5()
{
    QString docText("Spenat{name: mySpenat; \n"
                    "Attribute int attr1 = 0;\n"
                    "Attribute int attr2 = 0;\n"
                   "Port in_port, out_port;\n"
                    "Signal input(int in);\n"
                    "SignalTransition{name: t1;\n"
                                     "signal: input;\n"
                                     "port: in_port;\n"
                                     "guard: trigger.in>20; \n"
                                     "action:{ \n"
                                          "this.attr2=trigger.in; \n"
                                          "send output(this.attr2) to out_port; }} \n"
                    "TimeoutTransition{name: t2; value: 10.0;\n"
                    "guard: {msg.in > 0}\n"
                    "action:{\n"
                      "send output(trigger.in) to out_port1;}}\n"
                    "}");

    model::spenat::SpenatDeclModel spenatDeclModel;
    dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

    QString errorString;
    bool result = command.execute(&errorString);
    for(const dslparser::DslError& error : command.errors())
      qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

    QCOMPARE(result, false);
    QCOMPARE(5, command.errors().count());

  return;
}

void SpenatSyntaxTest::spenatTransitionDeclQualityTest_6()
{
    QString docText("Spenat{name: mySpenat; \n"
                    "Attribute int attr1 = 0;\n"
                    "Attribute int attr2 = 0;\n"
                    "Port in_port, out_port;\n"
                    "Signal input(int in);\n"
                    "SignalTransition{name: t1;\n"
                                     "signal: input;\n"
                                     "port: in_port;\n"
                                     "guard: trigger.in>20; \n"
                                     "action:{ \n"
                                          "this.attr2=trigger.in; \n"
                                          "send output(this.attr2,trigger.in) to out_port; }} \n"
                    "TimeoutTransition{name: t2; value: 10.0;\n"
                    "guard: {msg.in > 0}\n"
                    "action:{\n"
                      "send outpu(this.attr2) to out_port;}}\n"
                    "}");

    model::spenat::SpenatDeclModel spenatDeclModel;
    dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

    QString errorString;
    bool result = command.execute(&errorString);
    for(const dslparser::DslError& error : command.errors())
      qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

    QCOMPARE(result, false);
    QCOMPARE(4, command.errors().count());

    return;
}

void SpenatSyntaxTest::spenatTransitionDeclQualityTest_7()
{
  QString docText("Spenat{name: mySpenat; \n"
                  "Type enum(MCountReset,\n"
                  "          MCountStart,\n"
                  "          MCountIncremented,\n"
                  "          MCountHighest) MCountType;\n"
                  "Attribute MCountType old_MCount = MCountReset;\n"
                  "Attribute MCountType MCount = MCountReset;\n"
                  "SignalTransition{name: t1;\n"
                                   "guard: this.MCount == MCountReset; \n"
                                   "action:{ \n"
                                        "this.old_MCount = MCountReset; \n"
                                        "this.MCount = MCountStart;\n"
                                    "}"
                                  "}"
                  "}");

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());

  return;
}

void SpenatSyntaxTest::spenatTransitionDeclQualityTest_8()
{
  QString docText("Spenat{name: mySpenat; \n"
                  "Type enum(MCountReset,\n"
                  "          MCountStart,\n"
                  "          MCountIncremented,\n"
                  "          MCountHighest) MCountType;\n"
                  "Attribute MCountType old_MCount = MCountReset;\n"
                  "Attribute MCountType MCount = MCountReset;\n"
                  "SignalTransition{name: t1;\n"
                                   "guard: this.MCount == MCountReset_; \n"
                                   "action:{ \n"
                                        "this.old_MCount = MCountReset; \n"
                                        "this.MCount = MCountStart;\n"
                                    "}"
                                  "}"
                  "}");

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, false);
  QCOMPARE(2, command.errors().count());

  return;
}

void SpenatSyntaxTest::spenatTransitionDeclQualityTest_9()
{
  QString docText("Spenat{name: mySpenat; \n"
                  "Type enum(MCountReset,\n"
                  "          MCountStart,\n"
                  "          MCountIncremented,\n"
                  "          MCountHighest) MCountType;\n"
                  "Attribute MCountType old_MCount = MCountReset;\n"
                  "Attribute MCountType MCount = MCountReset;\n"
                  "SignalTransition{name: t1;\n"
                                   "guard: this.MCount == MCountReset; \n"
                                   "action:{ \n"
                                        "old_MCount_ = MCountReset; \n"
                                        "this.MCount = MCountStart;\n"
                                    "}"
                                  "}"
                  "}");

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());

  return;
}

void SpenatSyntaxTest::spenatTransitionDeclQualityTest_10()
{
  QString docText("Spenat{name: mySpenat; \n"
                  "Type enum(MCountReset,\n"
                  "          MCountStart,\n"
                  "          MCountIncremented,\n"
                  "          MCountHighest) MCountType;\n"
                  "Attribute MCountType old_MCount = MCountReset;\n"
                  "Attribute MCountType MCount = MCountReset;\n"
                  "SignalTransition{name: t1;\n"
                                   "guard: this.MCount == MCountReset; \n"
                                   "action:{ \n"
                                        "old_MCount = MCountReset; \n"
                                        "MCount_ = MCountStart;\n"
                                    "}"
                                  "}"
                  "}");

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());

  return;
}

void SpenatSyntaxTest::spenatTransitionDeclQualityTest_11()
{
  QString docText("Spenat{name: mySpenat; \n"
                  "Type enum(MCountReset,\n"
                  "          MCountStart,\n"
                  "          MCountIncremented,\n"
                  "          MCountHighest) MCountType;\n"
                  "Attribute MCountType old_MCount = MCountReset;\n"
                  "Attribute MCountType MCount = MCountReset;\n"
                  "SignalTransition{name: t1;\n"
                                   "guard: this.MCount == MCountReset; \n"
                                   "action:{ \n"
                                        "old_MCount = MCountReset_; \n"
                                        "MCount = MCountStart;\n"
                                    "}"
                                  "}"
                  "}");

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, false);
  QCOMPARE(2, command.errors().count());

  return;
}

void SpenatSyntaxTest::spenatTransitionDeclQualityTest_12()
{
  QString docText("Spenat{name: mySpenat; \n"
                  "Type enum(MCountReset,\n"
                  "          MCountStart,\n"
                  "          MCountIncremented,\n"
                  "          MCountHighest) MCountType;\n"
                  "Attribute MCountType old_MCount = MCountReset;\n"
                  "Attribute MCountType MCount = MCountReset;\n"
                  "SignalTransition{name: t1;\n"
                                   "guard: this.MCount == MCountReset; \n"
                                   "action:{ \n"
                                        "old_MCount = MCountReset; \n"
                                        "MCount = MCountStart_;\n"
                                    "}"
                                  "}"
                  "}");

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, false);
  QCOMPARE(2, command.errors().count());

  return;
}

void SpenatSyntaxTest::spenatSignalDeclTest_1()
{
  QString docText("Spenat{name: mySpenat; "
                  "Signal mySignal;}");

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());

  QCOMPARE(1, spenatDeclModel.getSignals().count());
  QCOMPARE(0, spenatDeclModel.places().count());
  QCOMPARE(0, spenatDeclModel.transitions().count());
  QCOMPARE(QString("mySignal"), spenatDeclModel.getSignals().at(0)->name());

  QCOMPARE(3, command.keywordTextLocations().size());
  QCOMPARE(1, command.modelTextLocations().size());

  return;
}

void SpenatSyntaxTest::spenatSignalDeclTest_2()
{
  QString docText("Spenat{name: mySpenat; "
                  "Signal mySignal; "
                  "Signal mySignal; }");

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());

  dslparser::DslError firstError = command.errors().at(0);
  QCOMPARE(1, int(firstError.line()));
  QCOMPARE(47, firstError.charPositionInLine());
  QCOMPARE(QString(""), firstError.offendingText());

  QCOMPARE(1, spenatDeclModel.getSignals().count());
  QCOMPARE(0, spenatDeclModel.places().count());
  QCOMPARE(0, spenatDeclModel.transitions().count());
  QCOMPARE(QString("mySignal"), spenatDeclModel.getSignals().at(0)->name());

  QCOMPARE(4, command.keywordTextLocations().size());
  QCOMPARE(1, command.modelTextLocations().size());

  return;
}

void SpenatSyntaxTest::spenatSignalDeclTest_3()
{
  QString docText("Spenat{name: mySpenat; "
                  "Signal mySignal_1; "
                  "Signal mySignal_1; "
                  "Signal mySignal_2; }");

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());

  dslparser::DslError firstError = command.errors().at(0);
  QCOMPARE(1, int(firstError.line()));
  QCOMPARE(49, firstError.charPositionInLine());
  QCOMPARE(QString(""), firstError.offendingText());

  QCOMPARE(2, spenatDeclModel.getSignals().count());
  QCOMPARE(0, spenatDeclModel.places().count());
  QCOMPARE(0, spenatDeclModel.transitions().count());
  QCOMPARE(QString("mySignal_1"), spenatDeclModel.getSignals().at(0)->name());
  QCOMPARE(QString("mySignal_2"), spenatDeclModel.getSignals().at(1)->name());

  QCOMPARE(5, command.keywordTextLocations().size());
  QCOMPARE(2, command.modelTextLocations().size());

  return;
}

void SpenatSyntaxTest::spenatSignalDeclTest_4()
{
  QString docText("Spenat{name: mySpenat; "
                  "Signal mySignal_1(int x);}");

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(true, result);
  QCOMPARE(command.errors().count(), 0);

  QCOMPARE(1, spenatDeclModel.getSignals().count());
  QCOMPARE(0, spenatDeclModel.places().count());
  QCOMPARE(0, spenatDeclModel.transitions().count());
  QCOMPARE(QString("mySignal_1"), spenatDeclModel.getSignals().at(0)->name());

  QCOMPARE(command.keywordTextLocations().size(), 4);
  QCOMPARE(command.modelTextLocations().size(), 1);

  return;
}

void SpenatSyntaxTest::spenatSignalDeclTest_5()
{
  QString docText("Spenat{name: mySpenat; "
                  "Signal mySignal_1(int x, ");

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(false, result);
  QCOMPARE(command.errors().count(), 3);

  QCOMPARE(0, spenatDeclModel.getSignals().count());
  QCOMPARE(0, spenatDeclModel.places().count());
  QCOMPARE(0, spenatDeclModel.transitions().count());

  QCOMPARE(command.keywordTextLocations().size(), 4);
  QCOMPARE(command.modelTextLocations().size(), 0);

  return;
}

void SpenatSyntaxTest::spenatSignalDeclTest_6()
{
  QString docText("Spenat{ \n"
                  "  name: mySpenat;\n"
                  "  Attribute int attr_1 = 0;\n"
                  "  Attribute int attr_2 = 0;\n"
                  "\n"
                  "  Signal input(int in,");

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(false, result);
  QCOMPARE(command.errors().count(), 3);

  QCOMPARE(spenatDeclModel.dataTypes().count(), 3);
  QCOMPARE(spenatDeclModel.attributes().count(), 2);
  QCOMPARE(spenatDeclModel.getSignals().count(), 0);
  QCOMPARE(spenatDeclModel.places().count(), 0);
  QCOMPARE(spenatDeclModel.transitions().count(), 0);

  QCOMPARE(command.keywordTextLocations().size(), 8);
  QCOMPARE(command.modelTextLocations().size(), 2);

  return;
}

void SpenatSyntaxTest::spenatPortDeclTest_1()
{
  QString docText("Spenat{name: mySpenat; "
                  "Port _p_1;}");

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());

  QCOMPARE(0, spenatDeclModel.getSignals().count());
  QCOMPARE(1, spenatDeclModel.ports().count());
  QCOMPARE(0, spenatDeclModel.places().count());
  QCOMPARE(0, spenatDeclModel.transitions().count());

  model::base::PortItem* port = spenatDeclModel.ports().at(0);
  QCOMPARE(QString("_p_1"), port->name());

  QCOMPARE(3, command.keywordTextLocations().size());
  QCOMPARE(1, command.modelTextLocations().size());

  return;
}

void SpenatSyntaxTest::spenatPortDeclTest_2()
{
  QString docText("Spenat{name: mySpenat; "
                  "Port _p_1; "
                  "Port _p_1; }");

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());

  dslparser::DslError firstError = command.errors().at(0);
  QCOMPARE(1, int(firstError.line()));
  QCOMPARE(39, firstError.charPositionInLine());
  QCOMPARE(QString(""), firstError.offendingText());

  QCOMPARE(0, spenatDeclModel.getSignals().count());
  QCOMPARE(1, spenatDeclModel.ports().count());
  QCOMPARE(0, spenatDeclModel.places().count());
  QCOMPARE(0, spenatDeclModel.transitions().count());

  model::base::PortItem* port = spenatDeclModel.ports().at(0);
  QCOMPARE(QString("_p_1"), port->name());

  QCOMPARE(4, command.keywordTextLocations().size());
  QCOMPARE(1, command.modelTextLocations().size());

  return;
}

void SpenatSyntaxTest::spenatPortDeclTest_3()
{
  QString docText("Spenat{name: mySpenat; "
                  "Port _p_1; "
                  "Port _p_1; "
                  "Port p2; }");

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());

  dslparser::DslError firstError = command.errors().at(0);
  QCOMPARE(1, int(firstError.line()));
  QCOMPARE(39, firstError.charPositionInLine());
  QCOMPARE(QString(""), firstError.offendingText());

  QCOMPARE(0, spenatDeclModel.getSignals().count());
  QCOMPARE(2, spenatDeclModel.ports().count());
  QCOMPARE(0, spenatDeclModel.places().count());
  QCOMPARE(0, spenatDeclModel.transitions().count());
  QCOMPARE(QString("_p_1"), spenatDeclModel.ports().at(0)->name());
  QCOMPARE(QString("p2"), spenatDeclModel.ports().at(1)->name());

  model::base::PortItem* port1 = spenatDeclModel.ports().at(0);
  QCOMPARE(QString("_p_1"), port1->name());

  model::base::PortItem* port2 = spenatDeclModel.ports().at(1);
  QCOMPARE(QString("p2"), port2->name());

  QCOMPARE(5, command.keywordTextLocations().size());
  QCOMPARE(2, command.modelTextLocations().size());

  return;
}

void SpenatSyntaxTest::spenatPortDeclTest_4()
{
  QString docText("Spenat{name: mySpenat; "
                  "Port p1; "
                  "Port p2, p1, p3, p2, p3, p4; "
                  "Port p5; }");

  model::spenat::SpenatDeclModel spenatDeclModel;
  dslparser::spenat::ComBuildSpenatModel command(docText, &spenatDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(3, command.errors().count());

  dslparser::DslError firstError = command.errors().at(0);
  QCOMPARE(1, int(firstError.line()));
  QCOMPARE(41, firstError.charPositionInLine());
  QCOMPARE(QString(""), firstError.offendingText());

  dslparser::DslError secondError = command.errors().at(1);
  QCOMPARE(1, int(secondError.line()));
  QCOMPARE(49, secondError.charPositionInLine());
  QCOMPARE(QString(""), secondError.offendingText());

  dslparser::DslError thirdError = command.errors().at(2);
  QCOMPARE(1, int(thirdError.line()));
  QCOMPARE(53, thirdError.charPositionInLine());
  QCOMPARE(QString(""), thirdError.offendingText());

  QCOMPARE(0, spenatDeclModel.getSignals().count());
  QCOMPARE(5, spenatDeclModel.ports().count());
  QCOMPARE(0, spenatDeclModel.places().count());
  QCOMPARE(0, spenatDeclModel.transitions().count());
  QCOMPARE(QString("p1"), spenatDeclModel.ports().at(0)->name());
  QCOMPARE(QString("p2"), spenatDeclModel.ports().at(1)->name());
  QCOMPARE(QString("p3"), spenatDeclModel.ports().at(2)->name());
  QCOMPARE(QString("p4"), spenatDeclModel.ports().at(3)->name());
  QCOMPARE(QString("p5"), spenatDeclModel.ports().at(4)->name());

  model::base::PortItem* port1 = spenatDeclModel.ports().at(0);
  QCOMPARE(QString("p1"), port1->name());

  model::base::PortItem* port2 = spenatDeclModel.ports().at(1);
  QCOMPARE(QString("p2"), port2->name());

  model::base::PortItem* port3 = spenatDeclModel.ports().at(2);
  QCOMPARE(QString("p3"), port3->name());

  model::base::PortItem* port4 = spenatDeclModel.ports().at(3);
  QCOMPARE(QString("p4"), port4->name());

  model::base::PortItem* port5 = spenatDeclModel.ports().at(4);
  QCOMPARE(QString("p5"), port5->name());

  QCOMPARE(5, command.keywordTextLocations().size());
  dslparser::TokenTextLocation keywordTextLocation = command.keywordTextLocations().at(0);
  QCOMPARE(0, keywordTextLocation.start());
  QCOMPARE(6, keywordTextLocation.length());
  QCOMPARE((int)dslparser::Spenat, keywordTextLocation.tokenType());

  keywordTextLocation = command.keywordTextLocations().at(1);
  QCOMPARE(7, keywordTextLocation.start());
  QCOMPARE(10, keywordTextLocation.end());
  QCOMPARE(4, keywordTextLocation.length());
  QCOMPARE(int(dslparser::Attribute), keywordTextLocation.tokenType());

  keywordTextLocation = command.keywordTextLocations().at(2);
  QCOMPARE(23, keywordTextLocation.start());
  QCOMPARE(26, keywordTextLocation.end());
  QCOMPARE(4, keywordTextLocation.length());
  QCOMPARE((int)dslparser::Port, keywordTextLocation.tokenType());

  keywordTextLocation = command.keywordTextLocations().at(3);
  QCOMPARE(32, keywordTextLocation.start());
  QCOMPARE(35, keywordTextLocation.end());
  QCOMPARE((int)dslparser::Port, keywordTextLocation.tokenType());

  keywordTextLocation = command.keywordTextLocations().at(4);
  QCOMPARE(61, keywordTextLocation.start());
  QCOMPARE(64, keywordTextLocation.end());
  QCOMPARE((int)dslparser::Port, keywordTextLocation.tokenType());

  QCOMPARE(5, command.modelTextLocations().size());
  dslparser::TokenTextLocation modelTextLocation = command.modelTextLocations().value(port1->index());
  QCOMPARE(28, modelTextLocation.start());
  QCOMPARE(29, modelTextLocation.end());
  QCOMPARE((int)dslparser::Port, modelTextLocation.tokenType());

  modelTextLocation = command.modelTextLocations().value(port2->index());
  QCOMPARE(37, modelTextLocation.start());
  QCOMPARE(38, modelTextLocation.end());
  QCOMPARE((int)dslparser::Port, modelTextLocation.tokenType());

  modelTextLocation = command.modelTextLocations().value(port3->index());
  QCOMPARE(45, modelTextLocation.start());
  QCOMPARE(46, modelTextLocation.end());
  QCOMPARE((int)dslparser::Port, modelTextLocation.tokenType());

  modelTextLocation = command.modelTextLocations().value(port4->index());
  QCOMPARE(57, modelTextLocation.start());
  QCOMPARE(58, modelTextLocation.end());
  QCOMPARE((int)dslparser::Port, modelTextLocation.tokenType());

  modelTextLocation = command.modelTextLocations().value(port5->index());
  QCOMPARE(66, modelTextLocation.start());
  QCOMPARE(67, modelTextLocation.end());
  QCOMPARE((int)dslparser::Port, modelTextLocation.tokenType());

  return;
}

QTEST_GUILESS_MAIN(SpenatSyntaxTest)

#include "tst_spenatsyntax.moc"
