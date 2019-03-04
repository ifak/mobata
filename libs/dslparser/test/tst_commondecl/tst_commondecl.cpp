#include <QtTest>

#include <mobata/model/base/signalitem.hpp>
#include <mobata/model/base/portitem.hpp>
#include <mobata/model/base/basemodel.hpp>
#include <mobata/model/base/datatypeitem.hpp>
#include <mobata/model/base/attributeitem.hpp>

#include <dslparser/common/comcreatecommontokens.hpp>
#include <dslparser/common/combuildbasemodel.hpp>

class CommonDeclTest
    : public QObject
{
  Q_OBJECT

public:
  CommonDeclTest();

private Q_SLOTS:
  void initTest();
  void cleanupTest();
  void commonTokenCreationTest_1();
  void commonTokenCreationTest_2();
  void lineCommentTokenTest_1();
  void lineCommentTokenTest_2();
  void lineCommentTokenTest_3();
  void lineCommentTokenTest_4();
  void multiLineCommentTokenTest_1();
  void multiLineCommentTokenTest_2();
  void signalDeclTest_1();
  void signalDeclTest_2();
  void signalDeclTest_3();
  void signalDeclTest_4();
  void signalDeclTest_5();
  void signalDeclTest_6();
  void signalDeclTest_7();
  void typeDeclTest_1();
  void typeDeclTest_2();
  void typeDeclTest_3();
  void typeDeclTest_4();
  void attributeDeclTest_1();
  void attributeDeclTest_2();
  void attributeDeclTest_3();
  void attributeDeclTest_4();
  void attributeDeclTest_5();
  void stringTest_1();
  void stringTest_2();
  void stringTest_3();
};

CommonDeclTest::CommonDeclTest()
{}

void CommonDeclTest::initTest()
{}

void CommonDeclTest::cleanupTest()
{}

void CommonDeclTest::commonTokenCreationTest_1()
{
  QString docText(L'\u2029');
  docText+=" ";
  docText+=QChar(L'\u2029');
  docText+=" Spenat{ ";
  docText+=QChar(L'\u2029');
  docText+=" name: mySpenat; }";

  dslparser::common::ComCreateCommonTokens command(docText);

  bool result = command.execute();
  QCOMPARE(result, true);
  QCOMPARE(command.commonTokenList().count(), 7);

  dslparser::TokenTextLocation tokenLocation = command.commonTokenList().at(0);
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 4);
  QCOMPARE(tokenLocation.end(), 9);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::Identifier));

  tokenLocation = command.commonTokenList().at(1);
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 10);
  QCOMPARE(tokenLocation.end(), 10);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::LeftBrace));

  tokenLocation = command.commonTokenList().at(2);
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 14);
  QCOMPARE(tokenLocation.end(), 17);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::Name));

  tokenLocation = command.commonTokenList().at(3);
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 18);
  QCOMPARE(tokenLocation.end(), 18);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::Colon));

  tokenLocation = command.commonTokenList().at(4);
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 20);
  QCOMPARE(tokenLocation.end(), 27);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::Identifier));

  tokenLocation = command.commonTokenList().at(5);
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 28);
  QCOMPARE(tokenLocation.end(), 28);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::Semi));

  tokenLocation = command.commonTokenList().at(6);
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 30);
  QCOMPARE(tokenLocation.end(), 30);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::RightBrace));

  return;
}

void CommonDeclTest::commonTokenCreationTest_2()
{
  QString docText(L'\u2029');
  docText+=" ";
  docText+=QChar(L'\u2029');
  docText+=" Spenat{ ";
  docText+=QChar(L'\u2029');
  docText+=" name: mySpenat; }";

  dslparser::common::ComCreateCommonTokens command(docText);

  QString errorString;
  bool result = command.execute(true, &errorString);
  QCOMPARE(result, true);
  QCOMPARE(command.commonTokenList().count(), 16);

  dslparser::TokenTextLocation tokenLocation = command.commonTokenList().at(0);
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 0);
  QCOMPARE(tokenLocation.end(), 0);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::NewLine));

  tokenLocation = command.commonTokenList().at(1);
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 1);
  QCOMPARE(tokenLocation.end(), 1);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::WhiteSpace));

  tokenLocation = command.commonTokenList().at(2);
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 2);
  QCOMPARE(tokenLocation.end(), 2);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::NewLine));

  tokenLocation = command.commonTokenList().at(3);
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 3);
  QCOMPARE(tokenLocation.end(), 3);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::WhiteSpace));

  tokenLocation = command.commonTokenList().at(4);
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 4);
  QCOMPARE(tokenLocation.end(), 9);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::Identifier));

  tokenLocation = command.commonTokenList().at(5);
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 10);
  QCOMPARE(tokenLocation.end(), 10);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::LeftBrace));

  tokenLocation = command.commonTokenList().at(6);
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 11);
  QCOMPARE(tokenLocation.end(), 11);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::WhiteSpace));

  tokenLocation = command.commonTokenList().at(7);
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 12);
  QCOMPARE(tokenLocation.end(), 12);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::NewLine));

  tokenLocation = command.commonTokenList().at(8);
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 13);
  QCOMPARE(tokenLocation.end(), 13);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::WhiteSpace));

  tokenLocation = command.commonTokenList().at(9);
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 14);
  QCOMPARE(tokenLocation.end(), 17);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::Name));

  tokenLocation = command.commonTokenList().at(10);
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 18);
  QCOMPARE(tokenLocation.end(), 18);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::Colon));

  tokenLocation = command.commonTokenList().at(11);
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 19);
  QCOMPARE(tokenLocation.end(), 19);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::WhiteSpace));

  tokenLocation = command.commonTokenList().at(12);
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 20);
  QCOMPARE(tokenLocation.end(), 27);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::Identifier));

  tokenLocation = command.commonTokenList().at(13);
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 28);
  QCOMPARE(tokenLocation.end(), 28);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::Semi));

  tokenLocation = command.commonTokenList().at(14);
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 29);
  QCOMPARE(tokenLocation.end(), 29);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::WhiteSpace));

  tokenLocation = command.commonTokenList().at(15);
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 30);
  QCOMPARE(tokenLocation.end(), 30);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::RightBrace));

  return;
}

void CommonDeclTest::lineCommentTokenTest_1()
{
  QString docText("  //commenting something \n");

  dslparser::common::ComCreateCommonTokens command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(command.commonTokenList().count(), 1);

  dslparser::TokenTextLocation tokenLocation = command.commonTokenList().at(0);
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 2);
  QCOMPARE(tokenLocation.end(), 25);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::LineComment));

  return;
}

void CommonDeclTest::lineCommentTokenTest_2()
{
  QString docText("  //commenting something\n");

  dslparser::common::ComCreateCommonTokens command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(command.commonTokenList().count(), 1);

  dslparser::TokenTextLocation tokenLocation = command.commonTokenList().at(0);
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 2);
  QCOMPARE(tokenLocation.end(), 24);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::LineComment));

  return;
}

void CommonDeclTest::lineCommentTokenTest_3()
{
  QString docText("  //commenting something//\n");

  dslparser::common::ComCreateCommonTokens command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(command.commonTokenList().count(), 1);

  dslparser::TokenTextLocation tokenLocation = command.commonTokenList().at(0);
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 2);
  QCOMPARE(tokenLocation.end(), 26);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::LineComment));

  return;
}

void CommonDeclTest::lineCommentTokenTest_4()
{
  QString docText("  //commenting something//");

  dslparser::common::ComCreateCommonTokens command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(command.commonTokenList().count(), 1);

  dslparser::TokenTextLocation tokenLocation = command.commonTokenList().at(0);
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 2);
  QCOMPARE(tokenLocation.end(), 25);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::LineComment));

  return;
}

void CommonDeclTest::multiLineCommentTokenTest_1()
{
  QString docText("  /*commenting something \n"
                  " else here \n"
                  "*/");

  dslparser::common::ComCreateCommonTokens command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(command.commonTokenList().count(), 1);

  dslparser::TokenTextLocation tokenLocation = command.commonTokenList().at(0);
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 2);
  QCOMPARE(tokenLocation.end(), 39);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::MultiLineComment));

  return;
}

void CommonDeclTest::multiLineCommentTokenTest_2()
{
  QString docText("  /*commenting something \n"
                  " else here \n");

  dslparser::common::ComCreateCommonTokens command(docText);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(command.commonTokenList().count(), 1);

  dslparser::TokenTextLocation tokenLocation = command.commonTokenList().at(0);
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 2);
  QCOMPARE(tokenLocation.end(), 37);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::MultiLineComment));

  return;
}

void CommonDeclTest::signalDeclTest_1()
{
  QString docText("Signal mySignal;");

  model::base::BaseModel baseDeclModel;
  dslparser::common::ComBuildBaseModel command(docText, &baseDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());

  QCOMPARE(1, baseDeclModel.getSignals().count());
  QCOMPARE(QString("mySignal"), baseDeclModel.getSignals().at(0)->name());

  QCOMPARE(1, command.keywordTextLocations().size());
  QCOMPARE(1, command.modelTextLocations().size());

  return;
}

void CommonDeclTest::signalDeclTest_2()
{
  QString docText("Signal mySignal; "
                  "Signal mySignal;");

  model::base::BaseModel baseDeclModel;
  dslparser::common::ComBuildBaseModel command(docText, &baseDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());

  dslparser::DslError firstError = command.errors().at(0);
  QCOMPARE(1, int(firstError.line()));
  QCOMPARE(24, firstError.charPositionInLine());
  QCOMPARE(QString(""), firstError.offendingText());

  QCOMPARE(1, baseDeclModel.getSignals().count());
  QCOMPARE(QString("mySignal"), baseDeclModel.getSignals().at(0)->name());

  QCOMPARE(2, command.keywordTextLocations().size());
  QCOMPARE(1, command.modelTextLocations().size());

  return;
}

void CommonDeclTest::signalDeclTest_3()
{
  QString docText("Signal mySignal_1; "
                  "Signal mySignal_1; "
                  "Signal mySignal_2;");

  model::base::BaseModel baseDeclModel;
  dslparser::common::ComBuildBaseModel command(docText, &baseDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());

  dslparser::DslError firstError = command.errors().at(0);
  QCOMPARE(1, int(firstError.line()));
  QCOMPARE(26, firstError.charPositionInLine());
  QCOMPARE(QString(""), firstError.offendingText());

  QCOMPARE(2, baseDeclModel.getSignals().count());
  QCOMPARE(QString("mySignal_1"), baseDeclModel.getSignals().at(0)->name());
  QCOMPARE(QString("mySignal_2"), baseDeclModel.getSignals().at(1)->name());

  QCOMPARE(3, command.keywordTextLocations().size());
  QCOMPARE(2, command.modelTextLocations().size());

  return;
}

void CommonDeclTest::signalDeclTest_4()
{
  QString docText("Signal mySignal_1(int x); \n"
                  "Signal mySignal_1;");

  model::base::BaseModel baseDeclModel;
  dslparser::common::ComBuildBaseModel command(docText, &baseDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());

  dslparser::DslError dslerror = command.errors().at(0);
  qDebug()<<"first error: "<<dslerror.message();
  QCOMPARE(2, int(dslerror.line()));
  QCOMPARE(7, dslerror.charPositionInLine());
  QCOMPARE(QString(""), dslerror.offendingText());

  QCOMPARE(1, baseDeclModel.getSignals().count());

  model::base::SignalItem* signal_1=baseDeclModel.getSignals().at(0);
  QVERIFY(signal_1);
  QCOMPARE(QString("mySignal_1"), signal_1->name());
  QCOMPARE(1, signal_1->params().size());

  model::base::ParamItem* param_1=signal_1->params().at(0);
  QVERIFY(param_1);
  QCOMPARE(QString("x"), param_1->name());
  QCOMPARE(QString("int"), param_1->dataType());

  QCOMPARE(3, command.keywordTextLocations().size());
  QCOMPARE(1, command.modelTextLocations().size());

  return;
}

void CommonDeclTest::signalDeclTest_5()
{
  QString docText("Attribute int(-3..10) attr_1 = 0; \n"
                  "Signal mySignal_1(int(-3..10) x1);");

  model::base::BaseModel baseDeclModel;
  dslparser::common::ComBuildBaseModel command(docText, &baseDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());

  QCOMPARE(5, baseDeclModel.dataTypes().count());

  QCOMPARE(QString("int_1_type"), baseDeclModel.dataTypes().at(4)->name());
  QCOMPARE(prop::Int, baseDeclModel.dataTypes().at(4)->typeEnum());
  QCOMPARE(baseDeclModel.dataTypes().at(4)->lowest(), QStringLiteral("-3"));
  QCOMPARE(baseDeclModel.dataTypes().at(4)->highest(), QStringLiteral("10"));

  QCOMPARE(1, baseDeclModel.attributes().count());

  model::base::AttributeItem* attribute_1 = baseDeclModel.attributes().at(0);
  QVERIFY(attribute_1);
  QCOMPARE(QString("attr_1"), attribute_1->name());
  QCOMPARE(baseDeclModel.dataTypes().at(4)->name(), attribute_1->dataType());
  QCOMPARE(QString("int_1_type"), attribute_1->dataType());
  QCOMPARE(QString("0"), attribute_1->initValue());

  QCOMPARE(1, baseDeclModel.getSignals().count());

  model::base::SignalItem* signal_1=baseDeclModel.getSignals().at(0);
  QVERIFY(signal_1);
  QCOMPARE(QString("mySignal_1"), signal_1->name());
  QCOMPARE(1, signal_1->params().count());

  model::base::ParamItem* param_1=signal_1->params().at(0);
  QVERIFY(param_1);
  QCOMPARE(QString("x1"), param_1->name());
  QCOMPARE(QString("int_1_type"), param_1->dataType());

  QCOMPARE(4, command.keywordTextLocations().size());
  QCOMPARE(3, command.modelTextLocations().size());

  return;
}

void CommonDeclTest::signalDeclTest_6()
{
  QString docText("Type int(-3..10) myIntType; \n"
                  "Signal mySignal_1(int x1, int(-3..10) x2, bool x3);");

  model::base::BaseModel baseDeclModel;
  dslparser::common::ComBuildBaseModel command(docText, &baseDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(true, result);
  QCOMPARE(command.errors().count(), 0);

  QCOMPARE(5, baseDeclModel.dataTypes().count());

  QCOMPARE(baseDeclModel.dataTypes().at(4)->name(), QString("myIntType"));
  QCOMPARE(baseDeclModel.dataTypes().at(4)->typeEnum(), prop::Int);
  QCOMPARE(baseDeclModel.dataTypes().at(4)->lowest(), QStringLiteral("-3"));
  QCOMPARE(baseDeclModel.dataTypes().at(4)->highest(), QStringLiteral("10"));

  QCOMPARE(baseDeclModel.attributes().count(), 0);
  QCOMPARE(baseDeclModel.getSignals().count(), 1);

  model::base::SignalItem* signal_1=baseDeclModel.getSignals().at(0);
  QVERIFY(signal_1);
  QCOMPARE(signal_1->name(), QString("mySignal_1"));
  QCOMPARE(signal_1->params().count(), 3);

  model::base::ParamItem* param=signal_1->params().at(0);
  QVERIFY(param);
  QCOMPARE(param->name(), QString("x1"));
  QCOMPARE(param->dataType(), QString("int"));

  param=signal_1->params().at(1);
  QVERIFY(param);
  QCOMPARE(param->name(), QString("x2"));
  QCOMPARE(param->dataType(), QString("myIntType"));

  param=signal_1->params().at(2);
  QVERIFY(param);
  QCOMPARE(param->name(), QString("x3"));
  QCOMPARE(param->dataType(), QString("bool"));

  QCOMPARE(6, command.keywordTextLocations().size());
  QCOMPARE(2, command.modelTextLocations().size());

  return;
}

void CommonDeclTest::signalDeclTest_7()
{
  QString docText("Type int(-3..10) myIntType; \n"
                  "Signal mySignal_1(int x1, ");

  model::base::BaseModel baseDeclModel;
  dslparser::common::ComBuildBaseModel command(docText, &baseDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(false, result);
  QCOMPARE(command.errors().count(), 3);
  QCOMPARE(command.errors().at(0).errorType(), dslparser::DslError::SyntaxError);

  return;
}

void CommonDeclTest::typeDeclTest_1()
{
  QString docText("Type int MyInt;");

  model::base::BaseModel baseDeclModel;
  dslparser::common::ComBuildBaseModel command(docText, &baseDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());

  QCOMPARE(5, baseDeclModel.dataTypes().count());

  QCOMPARE(QString("int"), baseDeclModel.dataTypes().at(0)->name());
  QCOMPARE(prop::Int, baseDeclModel.dataTypes().at(0)->typeEnum());
  QCOMPARE(QString("real"), baseDeclModel.dataTypes().at(1)->name());
  QCOMPARE(prop::Real, baseDeclModel.dataTypes().at(1)->typeEnum());
  QCOMPARE(QString("bool"), baseDeclModel.dataTypes().at(2)->name());
  QCOMPARE(prop::Bool, baseDeclModel.dataTypes().at(2)->typeEnum());
  QCOMPARE(QString("string"), baseDeclModel.dataTypes().at(3)->name());
  QCOMPARE(prop::String, baseDeclModel.dataTypes().at(3)->typeEnum());

  QCOMPARE(QString("MyInt"), baseDeclModel.dataTypes().at(4)->name());
  QCOMPARE(prop::Int, baseDeclModel.dataTypes().at(4)->typeEnum());

  QCOMPARE(2, command.keywordTextLocations().size());
  QCOMPARE(1, command.modelTextLocations().size());

  return;
}

void CommonDeclTest::typeDeclTest_2()
{
  QString docText("Type int MyInt;"
                  "Type int(-4..10) MyRangeInt;");

  model::base::BaseModel baseDeclModel;
  dslparser::common::ComBuildBaseModel command(docText, &baseDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());

  QCOMPARE(6, baseDeclModel.dataTypes().count());
  QCOMPARE(QString("MyInt"), baseDeclModel.dataTypes().at(4)->name());
  QCOMPARE(prop::Int, baseDeclModel.dataTypes().at(4)->typeEnum());

  QCOMPARE(QString("MyRangeInt"), baseDeclModel.dataTypes().at(5)->name());
  QCOMPARE(prop::Int, baseDeclModel.dataTypes().at(5)->typeEnum());
  QCOMPARE(baseDeclModel.dataTypes().at(5)->lowest(), QStringLiteral("-4"));
  QCOMPARE(baseDeclModel.dataTypes().at(5)->highest(), QStringLiteral("10"));

  QCOMPARE(4, command.keywordTextLocations().size());
  QCOMPARE(2, command.modelTextLocations().size());

  return;
}

void CommonDeclTest::typeDeclTest_3()
{
  QString docText("Type int MyInt;"
                  "Type int(-4..10) MyRangeInt;"
                  "Type real MyReal;"
                  "Type real(-3.32..34.98) MyRangeReal;"
                  "Type bool MyBool;"
                  "Type string MyString;");

  model::base::BaseModel baseDeclModel;
  dslparser::common::ComBuildBaseModel command(docText, &baseDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());

  QCOMPARE(10, baseDeclModel.dataTypes().count());

  QCOMPARE(QString("MyInt"), baseDeclModel.dataTypes().at(4)->name());
  QCOMPARE(prop::Int, baseDeclModel.dataTypes().at(4)->typeEnum());

  QCOMPARE(QString("MyRangeInt"), baseDeclModel.dataTypes().at(5)->name());
  QCOMPARE(prop::Int, baseDeclModel.dataTypes().at(5)->typeEnum());
  QCOMPARE(baseDeclModel.dataTypes().at(5)->lowest(), QStringLiteral("-4"));
  QCOMPARE(baseDeclModel.dataTypes().at(5)->highest(), QStringLiteral("10"));

  QCOMPARE(QString("MyReal"), baseDeclModel.dataTypes().at(6)->name());
  QCOMPARE(prop::Real, baseDeclModel.dataTypes().at(6)->typeEnum());

  QCOMPARE(QString("MyRangeReal"), baseDeclModel.dataTypes().at(7)->name());
  QCOMPARE(prop::Real, baseDeclModel.dataTypes().at(7)->typeEnum());
  QCOMPARE(baseDeclModel.dataTypes().at(7)->lowest(), QStringLiteral("-3.32"));
  QCOMPARE(baseDeclModel.dataTypes().at(7)->highest(), QStringLiteral("34.98"));

  QCOMPARE(QString("MyBool"), baseDeclModel.dataTypes().at(8)->name());
  QCOMPARE(prop::Bool, baseDeclModel.dataTypes().at(8)->typeEnum());

  QCOMPARE(QString("MyString"), baseDeclModel.dataTypes().at(9)->name());
  QCOMPARE(prop::String, baseDeclModel.dataTypes().at(9)->typeEnum());

  return;
}

void CommonDeclTest::typeDeclTest_4()
{
  QString docText("Type enum (one, two, three) MyEnum;");

  model::base::BaseModel baseDeclModel;
  dslparser::common::ComBuildBaseModel command(docText, &baseDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());

  QCOMPARE(5, baseDeclModel.dataTypes().count());

  auto datatype = baseDeclModel.dataTypes().at(4);
  QCOMPARE(QString("MyEnum"), datatype->name());
  QCOMPARE(3,datatype->literals().count());
  QVERIFY(datatype->literals().contains(QString("one")));
  QVERIFY(datatype->literals().contains(QString("two")));
  QVERIFY(datatype->literals().contains(QString("three")));

}

void CommonDeclTest::attributeDeclTest_1()
{
  QString docText("Attribute int attr = 0;");

  model::base::BaseModel baseDeclModel;
  dslparser::common::ComBuildBaseModel command(docText, &baseDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());

  QCOMPARE(1, baseDeclModel.attributes().count());
  model::base::AttributeItem* attribute_1 = baseDeclModel.attributes().at(0);
  QVERIFY(attribute_1);
  QCOMPARE(QLatin1String("attr"), attribute_1->name());
  QCOMPARE(QLatin1String("int"), attribute_1->dataType());

  QCOMPARE(2, command.keywordTextLocations().size());
  dslparser::TokenTextLocation   tokenLocation = command.keywordTextLocations().at(0);
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 0);
  QCOMPARE(tokenLocation.end(), 8);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::Attribute));

  tokenLocation = command.keywordTextLocations().at(1);
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 10);
  QCOMPARE(tokenLocation.end(), 12);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::Type));

  QCOMPARE(1, command.modelTextLocations().size());
  tokenLocation = command.modelTextLocations().value(attribute_1->index());
  QCOMPARE(tokenLocation.isValid(), true);
  QCOMPARE(tokenLocation.start(), 0);
  QCOMPARE(tokenLocation.end(), 22);
  QCOMPARE(tokenLocation.tokenType(), int(dslparser::Attribute));

  return;
}

void CommonDeclTest::attributeDeclTest_2()
{
  QString docText("Attribute int(-3..10) attr = 0;");

  model::base::BaseModel baseDeclModel;
  dslparser::common::ComBuildBaseModel command(docText, &baseDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());

  QCOMPARE(5, baseDeclModel.dataTypes().count());

  QCOMPARE(QLatin1String("int_1_type"), baseDeclModel.dataTypes().at(4)->name());
  QCOMPARE(prop::Int, baseDeclModel.dataTypes().at(4)->typeEnum());
  QCOMPARE(baseDeclModel.dataTypes().at(4)->lowest(), QStringLiteral("-3"));
  QCOMPARE(baseDeclModel.dataTypes().at(4)->highest(), QStringLiteral("10"));

  QCOMPARE(1, baseDeclModel.attributes().count());
  model::base::AttributeItem* attribute_1 = baseDeclModel.attributes().at(0);
  QVERIFY(attribute_1);
  QCOMPARE(QString("attr"), attribute_1->name());
  QCOMPARE(baseDeclModel.dataTypes().at(4)->name(), attribute_1->dataType());
  QCOMPARE(QString("int_1_type"), attribute_1->dataType());

  QCOMPARE(2, command.keywordTextLocations().size());
  QCOMPARE(2, command.modelTextLocations().size());

  return;
}

void CommonDeclTest::attributeDeclTest_3()
{
  QString docText("Attribute int(-3..10) attr_1 = 0;"
                  "Attribute int(-3..10) attr_2 = 0;");

  model::base::BaseModel baseDeclModel;
  dslparser::common::ComBuildBaseModel command(docText, &baseDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());

  QCOMPARE(5, baseDeclModel.dataTypes().count());

  QCOMPARE(QString("int_1_type"), baseDeclModel.dataTypes().at(4)->name());
  QCOMPARE(prop::Int, baseDeclModel.dataTypes().at(4)->typeEnum());
  QCOMPARE(baseDeclModel.dataTypes().at(4)->lowest(), QStringLiteral("-3"));
  QCOMPARE(baseDeclModel.dataTypes().at(4)->highest(), QStringLiteral("10"));

  QCOMPARE(2, baseDeclModel.attributes().count());

  model::base::AttributeItem* attribute_1 = baseDeclModel.attributes().at(0);
  QVERIFY(attribute_1);
  QCOMPARE(QString("attr_1"), attribute_1->name());
  QCOMPARE(baseDeclModel.dataTypes().at(4)->name(), attribute_1->dataType());
  QCOMPARE(QString("int_1_type"), attribute_1->dataType());

  model::base::AttributeItem* attribute_2 = baseDeclModel.attributes().at(1);
  QVERIFY(attribute_2);
  QCOMPARE(QString("attr_2"), attribute_2->name());
  QCOMPARE(baseDeclModel.dataTypes().at(4)->name(), attribute_2->dataType());
  QCOMPARE(QString("int_1_type"), attribute_2->dataType());

  QCOMPARE(4, command.keywordTextLocations().size());
  QCOMPARE(3, command.modelTextLocations().size());

  return;
}

void CommonDeclTest::attributeDeclTest_4()
{
  QString docText("Type int(-3..10) MyIntType;"
                  "Attribute int(-3..10) attr_1 = 0;");

  model::base::BaseModel baseDeclModel;
  dslparser::common::ComBuildBaseModel command(docText, &baseDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  QCOMPARE(5, baseDeclModel.dataTypes().count());

  QCOMPARE(QString("MyIntType"), baseDeclModel.dataTypes().at(4)->name());
  QCOMPARE(prop::Int, baseDeclModel.dataTypes().at(4)->typeEnum());
  QCOMPARE(baseDeclModel.dataTypes().at(4)->lowest(), QStringLiteral("-3"));
  QCOMPARE(baseDeclModel.dataTypes().at(4)->highest(), QStringLiteral("10"));

  QCOMPARE(1, baseDeclModel.attributes().count());

  model::base::AttributeItem* attribute_1 = baseDeclModel.attributes().at(0);
  QVERIFY(attribute_1);
  QCOMPARE(QString("attr_1"), attribute_1->name());
  QCOMPARE(baseDeclModel.dataTypes().at(4)->name(), attribute_1->dataType());
  QCOMPARE(QString("MyIntType"), attribute_1->dataType());

  QCOMPARE(4, command.keywordTextLocations().size());
  QCOMPARE(2, command.modelTextLocations().size());

  return;
}

void CommonDeclTest::attributeDeclTest_5()
{
  QString docText("Type int(-3..-4) MyWrongIntType;"
                  "Attribute int(4..2) wrongAttr = 0;");

  model::base::BaseModel baseDeclModel;
  dslparser::common::ComBuildBaseModel command(docText, &baseDeclModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  qDebug()<<"errror-string: "<<errorString;
  QCOMPARE(0, command.errors().count());
  QCOMPARE(6, baseDeclModel.dataTypes().count());

  QCOMPARE(QString("MyWrongIntType"), baseDeclModel.dataTypes().at(4)->name());
  QCOMPARE(prop::Int, baseDeclModel.dataTypes().at(4)->typeEnum());
  QCOMPARE(baseDeclModel.dataTypes().at(4)->lowest(), QStringLiteral("-3"));
  QCOMPARE(baseDeclModel.dataTypes().at(4)->highest(), QStringLiteral("-4"));

  QCOMPARE(1, baseDeclModel.attributes().count());

  model::base::AttributeItem* attribute_1 = baseDeclModel.attributes().at(0);
  QVERIFY(attribute_1);
  QCOMPARE(QString("wrongAttr"), attribute_1->name());
  QCOMPARE(baseDeclModel.dataTypes().at(5)->name(), attribute_1->dataType());
  QCOMPARE(QString("int_2_type"), attribute_1->dataType());
  QCOMPARE(baseDeclModel.dataTypes().at(5)->lowest(), QStringLiteral("4"));
  QCOMPARE(baseDeclModel.dataTypes().at(5)->highest(), QStringLiteral("2"));

  QCOMPARE(4, command.keywordTextLocations().size());
  QCOMPARE(3, command.modelTextLocations().size());
}

void CommonDeclTest::stringTest_1(){
    QString docText("Attribute string attr_1 = \"hallo\";");

    model::base::BaseModel baseDeclModel;
    dslparser::common::ComBuildBaseModel command(docText, &baseDeclModel);

    QString errorString;
    bool result = command.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(0, command.errors().count());
}

void CommonDeclTest::stringTest_2(){
    QString docText("Attribute string attr_1 = \"hal\nlo\";");

    model::base::BaseModel baseDeclModel;
    dslparser::common::ComBuildBaseModel command(docText, &baseDeclModel);

    QString errorString;
    bool result = command.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(0, command.errors().count());
}

void CommonDeclTest::stringTest_3(){
    QString docText("Attribute string attr_1 = \"\\\"stuff\\\"\";");

    model::base::BaseModel baseDeclModel;
    dslparser::common::ComBuildBaseModel command(docText, &baseDeclModel);

    QString errorString;
    bool result = command.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(0, command.errors().count());
}

QTEST_GUILESS_MAIN(CommonDeclTest)

#include "tst_commondecl.moc"
