#include <QString>
#include <QtTest>
#include <modtrace/comcreatemodetrace.hpp>
#include "mobata/model/base/io/readhelpers.hpp"

using namespace modtrace;
using namespace model::base::io;

class ModtraceTest
    : public QObject
{
  Q_OBJECT

public:
  ModtraceTest();


private:
  QEventLoop*       _testEventLoop;


private Q_SLOTS:
  void init();
  void initTestCase();
  void cleanup();
  void cleanupTestCase();

  void modtraceTest();
  void invalidSpenatJson_Test();
  void invalidAts_Test();

private:
};

ModtraceTest::ModtraceTest()
{

}

void ModtraceTest::init()
{
  Q_INIT_RESOURCE(testdata);
}

void ModtraceTest::initTestCase()
{}

void ModtraceTest::cleanup()
{}

void ModtraceTest::cleanupTestCase()
{}

void ModtraceTest::modtraceTest()
{
  QString atsFilename = ":/testmodel.ats";
  QString spenatTracefilename = ":/testmodel.spenattrace";
  QString modelname = QStringLiteral("testModel1");

  ComCreateModeTrace tracer(spenatTracefilename,
                            atsFilename,
                            modelname);
  QString errorString("");
  bool result = tracer.execute(&errorString);
  QVERIFY2(result, errorString.toLatin1());

  QFile traceFile(modelname + QStringLiteral(".testcasetrace"));
  result = traceFile.open(QIODevice::ReadOnly | QIODevice::Text);
  QVERIFY(result);

  QByteArray traceFileContent = traceFile.readAll();
  traceFile.close();
  QJsonParseError err;
  QJsonDocument doc = QJsonDocument::fromJson(traceFileContent, &err);
  QCOMPARE(err.error, QJsonParseError::NoError);
  QJsonObject jsonObject = doc.object();

  int iteration;
  result = model::base::io::readProperty<int>(jsonObject, QStringLiteral("iteration"), &iteration, &errorString);
  QVERIFY2(result, errorString.toLatin1());
  QCOMPARE(iteration, 5);

  QJsonArray tcArray;
  result = model::base::io::readJsonArray(jsonObject, QStringLiteral("testcases"), &tcArray, &errorString);
  QVERIFY2(result, errorString.toLatin1());
  QCOMPARE(tcArray.size(), 3);
  QJsonValue tcValue1 = tcArray.at(0);
  QJsonObject tcObject1 = tcValue1.toObject();
  QString tcName1;
  result = model::base::io::readProperty<QString>(tcObject1, QStringLiteral("name"), &tcName1, &errorString);
  QVERIFY2(result, errorString.toLatin1());
  QCOMPARE(tcName1, QStringLiteral("tc_1"));

  QJsonArray jsonReqArray1;
  result = model::base::io::readJsonArray(tcObject1, QStringLiteral("requirements"), &jsonReqArray1, &errorString);
  QVERIFY2(result, errorString.toLatin1());
  QCOMPARE(jsonReqArray1.size(), 4);
  QJsonValue reqValue11 = jsonReqArray1.at(0);
  QCOMPARE(reqValue11.toString(), QStringLiteral("Req_Betriebsmodus"));
  QJsonValue reqValue12 = jsonReqArray1.at(1);
  QCOMPARE(reqValue12.toString(), QStringLiteral("Req_BetriebsmodusFeldbus"));
  QJsonValue reqValue13 = jsonReqArray1.at(2);
  QCOMPARE(reqValue13.toString(), QStringLiteral("Req_AufBetrieb"));
  QJsonValue reqValue14 = jsonReqArray1.at(3);
  QCOMPARE(reqValue14.toString(), QStringLiteral("Req_ZuBetrieb"));

  QJsonArray placeJsonArray1;
  result = model::base::io::readJsonArray(tcObject1, QStringLiteral("places"), &placeJsonArray1, &errorString);
  QVERIFY2(result, errorString.toLatin1());
  QCOMPARE(placeJsonArray1.size(), 4);
  QJsonValue placeValue11 = placeJsonArray1.at(0);
  QCOMPARE(placeValue11.toString(), QStringLiteral("init"));
  QJsonValue placeValue12 = placeJsonArray1.at(1);
  QCOMPARE(placeValue12.toString(), QStringLiteral("S1"));
  QJsonValue placeValue13 = placeJsonArray1.at(2);
  QCOMPARE(placeValue13.toString(), QStringLiteral("ZU"));
  QJsonValue placeValue14 = placeJsonArray1.at(3);
  QCOMPARE(placeValue14.toString(), QStringLiteral("AUF"));

  QJsonArray transJsonArray1;
  result = model::base::io::readJsonArray(tcObject1, QStringLiteral("transitions"), &transJsonArray1, &errorString);
  QVERIFY2(result, errorString.toLatin1());
  QCOMPARE(transJsonArray1.size(), 5);
  QJsonValue transValue11 = transJsonArray1.at(0);
  QCOMPARE(transValue11.toString(), QStringLiteral("setzeModus_T6"));
  QJsonValue transValue12 = transJsonArray1.at(1);
  QCOMPARE(transValue12.toString(), QStringLiteral("noTrigger_T8"));
  QJsonValue transValue13 = transJsonArray1.at(2);
  QCOMPARE(transValue13.toString(), QStringLiteral("StellbefehlAufZu_T2"));
  QJsonValue transValue14 = transJsonArray1.at(3);
  QCOMPARE(transValue14.toString(), QStringLiteral("StellbefehlAufZu_T3"));
  QJsonValue transValue15 = transJsonArray1.at(4);
  QCOMPARE(transValue15.toString(), QStringLiteral("StellbefehlAufZu_T1"));

  bool reqChanged1;
  result = model::base::io::readProperty<bool>(tcObject1, QStringLiteral("req_changed"), &reqChanged1, &errorString);
  QVERIFY(result);
  QCOMPARE(reqChanged1, true);

  QJsonValue tcValue2 = tcArray.at(1);
  QJsonObject tcObject2 = tcValue2.toObject();
  QString tcName2;
  result = model::base::io::readProperty<QString>(tcObject2, QStringLiteral("name"), &tcName2, &errorString);
  QVERIFY2(result, errorString.toLatin1());
  QCOMPARE(tcName2, QStringLiteral("tc_2"));

  QJsonArray jsonReqArray2;
  result = model::base::io::readJsonArray(tcObject2, QStringLiteral("requirements"), &jsonReqArray2, &errorString);
  QVERIFY2(result, errorString.toLatin1());
  QCOMPARE(jsonReqArray2.size(), 2);
  QJsonValue reqValue21 = jsonReqArray2.at(0);
  QCOMPARE(reqValue21.toString(), QStringLiteral("Req_Betriebsmodus"));
  QJsonValue reqValue22 = jsonReqArray2.at(1);
  QCOMPARE(reqValue22.toString(), QStringLiteral("Req_BetriebsmodusFeldbus"));

  QJsonArray placeJsonArray2;
  result = model::base::io::readJsonArray(tcObject2, QStringLiteral("places"), &placeJsonArray2, &errorString);
  QVERIFY2(result, errorString.toLatin1());
  QCOMPARE(placeJsonArray2.size(), 2);
  QJsonValue placeValue21 = placeJsonArray2.at(0);
  QCOMPARE(placeValue21.toString(), QStringLiteral("init"));
  QJsonValue placeValue22 = placeJsonArray2.at(1);
  QCOMPARE(placeValue22.toString(), QStringLiteral("S1"));

  QJsonArray transJsonArray2;
  result = model::base::io::readJsonArray(tcObject2, QStringLiteral("transitions"), &transJsonArray2, &errorString);
  QVERIFY2(result, errorString.toLatin1());
  QCOMPARE(transJsonArray2.size(), 3);
  QJsonValue transValue21 = transJsonArray2.at(0);
  QCOMPARE(transValue21.toString(), QStringLiteral("setzeModus_T7"));
  QJsonValue transValue22 = transJsonArray2.at(1);
  QCOMPARE(transValue22.toString(), QStringLiteral("noTrigger_T8"));
  QJsonValue transValue23 = transJsonArray2.at(2);
  QCOMPARE(transValue23.toString(), QStringLiteral("setzeModus_T5"));

  bool reqChanged2;
  result = model::base::io::readProperty<bool>(tcObject2, QStringLiteral("req_changed"), &reqChanged2, &errorString);
  QVERIFY(result);
  QCOMPARE(reqChanged2, false);

  QJsonValue tcValue3 = tcArray.at(2);
  QJsonObject tcObject3 = tcValue3.toObject();
  QString tcName3;
  result = model::base::io::readProperty<QString>(tcObject3, QStringLiteral("name"), &tcName3, &errorString);
  QVERIFY2(result, errorString.toLatin1());
  QCOMPARE(tcName3, QStringLiteral("tc_3"));

  QJsonArray jsonReqArray3;
  result = model::base::io::readJsonArray(tcObject3, QStringLiteral("requirements"), &jsonReqArray3, &errorString);
  QVERIFY2(result, errorString.toLatin1());
  QCOMPARE(jsonReqArray3.size(), 2);
  QJsonValue reqValue31 = jsonReqArray3.at(0);
  QCOMPARE(reqValue31.toString(), QStringLiteral("Req_BetriebsmodusFeldbus"));
  QJsonValue reqValue32 = jsonReqArray3.at(1);
  QCOMPARE(reqValue32.toString(), QStringLiteral("Req_Betriebsmodus"));

  QJsonArray placeJsonArray3;
  result = model::base::io::readJsonArray(tcObject3, QStringLiteral("places"), &placeJsonArray3, &errorString);
  QVERIFY2(result, errorString.toLatin1());
  QCOMPARE(placeJsonArray3.size(), 2);
  QJsonValue placeValue31 = placeJsonArray3.at(0);
  QCOMPARE(placeValue31.toString(), QStringLiteral("init"));
  QJsonValue placeValue32 = placeJsonArray3.at(1);
  QCOMPARE(placeValue32.toString(), QStringLiteral("S1"));

  QJsonArray transJsonArray3;
  result = model::base::io::readJsonArray(tcObject3, QStringLiteral("transitions"), &transJsonArray3, &errorString);
  QVERIFY2(result, errorString.toLatin1());
  QCOMPARE(transJsonArray3.size(), 3);
  QJsonValue transValue31 = transJsonArray3.at(0);
  QCOMPARE(transValue31.toString(), QStringLiteral("setzeModus_T4"));
  QJsonValue transValue32 = transJsonArray3.at(1);
  QCOMPARE(transValue32.toString(), QStringLiteral("setzeModus_T6"));
  QJsonValue transValue33 = transJsonArray3.at(2);
  QCOMPARE(transValue33.toString(), QStringLiteral("noTrigger_T8"));

  bool reqChanged3;
  result = model::base::io::readProperty<bool>(tcObject3, QStringLiteral("req_changed"), &reqChanged3, &errorString);
  QVERIFY(result);
  QCOMPARE(reqChanged3, false);
}

void ModtraceTest::invalidSpenatJson_Test()
{
  QString atsFilename = ":/testmodel.ats";
  QString spenatTracefilename = ":/testmodel_invalid.spenattrace";
  QString modelname = QStringLiteral("testModel2");

  ComCreateModeTrace tracer(spenatTracefilename,
                            atsFilename,
                            modelname);
  QString errorString("");
  bool result = tracer.execute(&errorString);
  QCOMPARE(result, false);

  QFile traceFile(modelname + QStringLiteral(".tctrace"));
  result = traceFile.open(QIODevice::ReadOnly | QIODevice::Text);
  QCOMPARE(result, false);
}

void ModtraceTest::invalidAts_Test()
{
  QString atsFilename = ":/testmodel_invalid.ats";
  QString spenatTracefilename = ":/testmodel.spenattrace";
  QString modelname = QStringLiteral("testModel3");

  ComCreateModeTrace tracer(spenatTracefilename,
                            atsFilename,
                            modelname);
  QString errorString("");
  bool result = tracer.execute(&errorString);
  QCOMPARE(result, false);

  QFile traceFile(modelname + QStringLiteral(".tctrace"));
  result = traceFile.open(QIODevice::ReadOnly | QIODevice::Text);
  QCOMPARE(result, false);
}

QTEST_GUILESS_MAIN(ModtraceTest)

#include "tst_modtracetest.moc"
