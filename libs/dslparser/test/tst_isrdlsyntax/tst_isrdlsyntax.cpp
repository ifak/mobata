#include <QtTest>

#include <mobata/model/isrdl/isrdlitem.hpp>
#include <mobata/model/isrdl/isrdlmodel.hpp>
#include <mobata/model/isrdl/isrdlattackdescription.h>
#include <mobata/model/isrdl/isrdlattackimpact.h>
#include <dslparser/isrdl/combuildisrdlmodel.hpp>

class IsrdlSyntaxTest
    : public QObject
{
  Q_OBJECT

public:
  IsrdlSyntaxTest();

private Q_SLOTS:
  void initIsrdlResource();
  void initTest();
  void cleanupTest();
  void isrdlTest1();
  void isrdlTest2();
  void isrdlTest3();
  void isrdlTest4();
  void isrdlTest5();
  void isrdlTest6();
  void isrdlTest7();
  void isrdlTest8();
  void isrdlTest9();
  void isrdlKeywordTest();
  void isrdlTestErrorTest1();
  void isrdlTestErrorTest2();
  void isrdlTestErrorTest3();
  void isrdlTestErrorTest4();
};

IsrdlSyntaxTest::IsrdlSyntaxTest()
{}

void IsrdlSyntaxTest::initIsrdlResource()
{
  Q_INIT_RESOURCE(complexexamples);
}

void IsrdlSyntaxTest::initTest()
{}

void IsrdlSyntaxTest::cleanupTest()
{}

void IsrdlSyntaxTest::isrdlTest1()
{
  QString docText("");
  model::isrdl::IsrdlModel isrdlModel;
  //QVERIFY(isrdlModel);
  dslparser::isrdl::ComBuildIsrdlModel command(docText, &isrdlModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  //IMPORTANT ONLY ONE ERROR!!!!
  return;
}

void IsrdlSyntaxTest::isrdlTest2()
{
  QString docText("SecurityRequirement{}");
  model::isrdl::IsrdlModel isrdlModel;
  //QVERIFY(isrdlModel);
  dslparser::isrdl::ComBuildIsrdlModel command(docText, &isrdlModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  //IMPORTANT ONLY ONE ERROR!!!!
  return;
}

void IsrdlSyntaxTest::isrdlTest3()
{
  QString docText("SecurityRequirement{"
                  "name : myIsrdl;"
                  "ImpactThreat{"
                  "}"
                  "}");
  model::isrdl::IsrdlModel isrdlModel;
  //QVERIFY(isrdlModel);
  dslparser::isrdl::ComBuildIsrdlModel command(docText, &isrdlModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  QCOMPARE(command.errors().first().message(),QString("You need to specify at least one attack impact!"));
  return;
}

void IsrdlSyntaxTest::isrdlTest4()
{
  QString docText("SecurityRequirement{"
                  "name : myIsrdl;"
                  "ImpactThreat{"
                    "confidentiality : Broken;"
                  "}"
                  "}");
  model::isrdl::IsrdlModel isrdlModel;
  //QVERIFY(isrdlModel);
  dslparser::isrdl::ComBuildIsrdlModel command(docText, &isrdlModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());

  auto item = isrdlModel.isrdlItems().first();
  QCOMPARE(item->attackImpact()->confidentiality(),true);
  return;
}

void IsrdlSyntaxTest::isrdlTest5()
{
  QString docText("SecurityRequirement{"
                  "name : myIsrdl;"
                  "ImpactThreat{"
                    "confidentiality : Intact;"
                  "}"
                  "}");
  model::isrdl::IsrdlModel isrdlModel;
  //QVERIFY(isrdlModel);
  dslparser::isrdl::ComBuildIsrdlModel command(docText, &isrdlModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  //IMPORTANT ONLY ONE ERROR!!!!
  return;
}

void IsrdlSyntaxTest::isrdlTest6()
{
  QString docText("SecurityRequirement{"
                  "name : myIsrdl;"
                  "ImpactThreat{"
                    "confidentiality : Broken;"
                    "integrity : NoDamage;"
                  "}"
                  "}");
  model::isrdl::IsrdlModel isrdlModel;
  //QVERIFY(isrdlModel);
  dslparser::isrdl::ComBuildIsrdlModel command(docText, &isrdlModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());

  auto item = isrdlModel.isrdlItems().first();
  QCOMPARE(item->attackImpact()->confidentiality(),true);
  QCOMPARE(item->attackImpact()->integrity(),false);
  return;
}

void IsrdlSyntaxTest::isrdlTest7()
{
  QString docText("SecurityRequirement{"
                  "name : myIsrdl;"
                  "ImpactThreat{"
                    "confidentiality : Intact;"
                    "integrity : NoDamage;"
                  "}"
                  "}");
  model::isrdl::IsrdlModel isrdlModel;
  //QVERIFY(isrdlModel);
  dslparser::isrdl::ComBuildIsrdlModel command(docText, &isrdlModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  return;
}

void IsrdlSyntaxTest::isrdlTest8()
{
  QString docText("SecurityRequirement{"
                  "name : myIsrdl;"
                  "ImpactThreat{"
                    "confidentiality : Broken;"
                    "integrity : Affected;"
                  "}"
                  "}");
  model::isrdl::IsrdlModel isrdlModel;
  //QVERIFY(isrdlModel);
  dslparser::isrdl::ComBuildIsrdlModel command(docText, &isrdlModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());

  auto item = isrdlModel.isrdlItems().first();
  QCOMPARE(item->attackImpact()->confidentiality(),true);
  QCOMPARE(item->attackImpact()->integrity(),true);
  return;
}

void IsrdlSyntaxTest::isrdlTest9()
{
  QString docText("SecurityRequirement{"
                  "name : myIsrdl;"
                  "ImpactThreat{"
                    "confidentiality : Broken;"
                    "integrity : Affected;"
                    "timeout : 3600 s;"
                  "}"
                  "}");
  model::isrdl::IsrdlModel isrdlModel;
  //QVERIFY(isrdlModel);
  dslparser::isrdl::ComBuildIsrdlModel command(docText, &isrdlModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());

  auto item = isrdlModel.isrdlItems().first();
  QCOMPARE(item->attackImpact()->confidentiality(),true);
  QCOMPARE(item->attackImpact()->integrity(),true);
  QCOMPARE(item->attackImpact()->timeout(),3600000);
  return;
}

void IsrdlSyntaxTest::isrdlKeywordTest()
{
  QString docText("SecurityRequirement{"
                  "name : myIsrdl;"
                  "AttackDescription{"
                    "source: Local;"
                    "privileges: Edit, Save, Install, UnInstall;"
                  "}"
                  "ImpactThreat{"
                    "confidentiality : Broken;"
                    "integrity : Affected;"
                    "timeout : 3600 s;"
                  "}"
                  "}");
  model::isrdl::IsrdlModel isrdlModel;
  //QVERIFY(isrdlModel);
  dslparser::isrdl::ComBuildIsrdlModel command(docText, &isrdlModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());

  auto item = isrdlModel.isrdlItems().first();
  QCOMPARE(item->attackImpact()->confidentiality(),true);
  QCOMPARE(item->attackImpact()->integrity(),true);
  QCOMPARE(item->attackImpact()->timeout(),3600000);

  QList<model::isrdl::AttackPrivileges> privList = item->attackDescription()->attackPrivileges();
  QCOMPARE(item->attackDescription()->attackVector(),model::isrdl::Local);
  QCOMPARE(privList.at(0),model::isrdl::Uninstall);
  QCOMPARE(privList.at(1),model::isrdl::Install);
  QCOMPARE(privList.at(2),model::isrdl::Save);
  QCOMPARE(privList.at(3),model::isrdl::Edit);

  int keywordsSz = command.keywordTextLocations().size();
  QCOMPARE(keywordsSz,16);
  return;
}

void IsrdlSyntaxTest::isrdlTestErrorTest1()
{
  QString docText("{"
                  "name : myIsrdl;"
                  "ImpactThreat{"
                    "confidentiality : Intact;"
                    "integrity : NoDamage;"
                  "}"
                  "}");
  model::isrdl::IsrdlModel isrdlModel;
  //QVERIFY(isrdlModel);
  dslparser::isrdl::ComBuildIsrdlModel command(docText, &isrdlModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, false);
  QCOMPARE(2, command.errors().count());
  return;
}

void IsrdlSyntaxTest::isrdlTestErrorTest2()
{
  QString docText("SecurityRequirement{"
                  "name : myIsrdl;"
                  "AttackDescription{"
                    "source: Local;"
                    "privileges: Edit, Save, Install, UnInstall;"
                  "}"
                  "ImpactThreat{"
                    "confidentiality  Broken;"
                    "integrity : Affected;"
                    "timeout : 3600 s;"
                  "}"
                  "}");
  model::isrdl::IsrdlModel isrdlModel;
  //QVERIFY(isrdlModel);
  dslparser::isrdl::ComBuildIsrdlModel command(docText, &isrdlModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  return;
}

void IsrdlSyntaxTest::isrdlTestErrorTest3()
{
  QString docText("SecurityRequirement{"
                  "name : myIsrdl;"
                  "AttackDescription{"
                    "source: Local;"
                    "privileges: Edit, None, Install, UnInstall;"
                  "}"
                  "ImpactThreat{"
                    "confidentiality : Broken;"
                    "integrity : Affected;"
                    "timeout : 3600 s;"
                  "}"
                  "}");
  model::isrdl::IsrdlModel isrdlModel;
  //QVERIFY(isrdlModel);
  dslparser::isrdl::ComBuildIsrdlModel command(docText, &isrdlModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  return;
}

void IsrdlSyntaxTest::isrdlTestErrorTest4()
{
  QString docText("SecurityRequirement{"
                  "name : myIsrdl;"
                  "AttackDescription{"
                    "privileges: Edit Save, Install, UnInstall;"
                  "}"
                  "ImpactThreat{"
                    "confidentiality : Broken;"
                  "}"
                  "}");
  model::isrdl::IsrdlModel isrdlModel;
  dslparser::isrdl::ComBuildIsrdlModel command(docText, &isrdlModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  QCOMPARE(command.errors().first().message(),QString("no viable alternative at input 'Save'"));
  return;
}

QTEST_GUILESS_MAIN(IsrdlSyntaxTest)

#include "tst_isrdlsyntax.moc"
