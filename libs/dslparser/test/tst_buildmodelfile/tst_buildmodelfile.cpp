#include <QtTest>
#include <QString>
#include <QFile>
#include <QDebug>

#include <mobata/model/statemachine/statemachinemodel.hpp>
#include <dslparser/statemachine/combuildstatemachinemodel.hpp>
#include <dslparser/statemachine/combuildstatemachinefile.hpp>

#include <mobata/model/spenat/spenatdeclmodel.hpp>
#include <dslparser/spenat/combuildspenatmodel.hpp>
#include <dslparser/spenat/combuildspenatfile.hpp>

class BuildModelFileTest
    : public QObject
{
  Q_OBJECT

public:
  BuildModelFileTest();

private Q_SLOTS:
  void initTestCase();
  void cleanupTest();

  void buildStateMachineFileTest();
  void buildStateMachineFileOptionalTest();
  void buildStateMachineFile_NoPathTest();
  void buildStateMachineFile_WrongPathTest();
  void buildSpenatFileTest();
  void buildSpenatFileOptionalTest();
  void buildSpenatFile_NoPathTest();
  void buildSpenatFile_WrongPathTest();
};

BuildModelFileTest::BuildModelFileTest()
{}

void BuildModelFileTest::initTestCase()
{
  Q_INIT_RESOURCE(test_models);
}

void BuildModelFileTest::cleanupTest()
{}

void BuildModelFileTest::buildStateMachineFileTest()
{
  using namespace dslparser::statemachine;
  using namespace model::statemachine;
  StateMachineModel* model = new StateMachineModel();

  QString praefix = ":/test_models/";
  QString filename = praefix + "test_model.statemachine";
  QFile file(filename);
  bool fileResult = file.open(QFile::ReadOnly | QFile::Text);
  if(!fileResult)
      qDebug()<<"file '"<<filename<<"' could not be opended!";
  QCOMPARE(fileResult, true);

  QString readDocText(file.readAll());
  ComBuildStateMachineModel commandParse(readDocText,
                                         model,
                                         praefix);
  QString errorString;
  bool result = commandParse.execute(&errorString);
  QVERIFY2(result == true, errorString.toLatin1());
  errorString.clear();

  QString resultFilename("result.statemachine");
  ComBuildStateMachineFile commandWrite(resultFilename, model);
  result = commandWrite.execute(&errorString);
  QVERIFY2(result == true, errorString.toLatin1());

  QFile resultFile(resultFilename);
  bool fileResult2 = resultFile.open(QFile::ReadOnly | QFile::Text);
  if(!fileResult2)
      qDebug()<<"file '"<<resultFilename<<"' could not be opended!";
  QCOMPARE(fileResult, true);

  QString resultDocText(resultFile.readAll());
  readDocText = readDocText.simplified();
  qDebug()<<"read doc text: "<<readDocText;
  resultDocText = resultDocText.simplified();
  qDebug()<<"result doc text: "<<resultDocText;
  QCOMPARE(QString::compare(readDocText, resultDocText, Qt::CaseSensitive), 0);

  bool fileDelResult = resultFile.remove();
  QCOMPARE(fileDelResult, true);

  delete model;
  model = nullptr;

  return;
}

void BuildModelFileTest::buildStateMachineFileOptionalTest()
{
  using namespace dslparser::statemachine;
  using namespace model::statemachine;
  StateMachineModel* model = new StateMachineModel();

  QString praefix = ":/test_models/";
  QString filename = praefix + "test_model.statemachine";
  QFile file(filename);
  bool fileResult = file.open(QFile::ReadOnly | QFile::Text);
  if(!fileResult)
      qDebug()<<"file '"<<filename<<"' could not be opended!";
  QCOMPARE(fileResult, true);

  QString readDocText(file.readAll());
  ComBuildStateMachineModel commandParse(readDocText,
                                         model,
                                         praefix);
  QString errorString;
  bool result = commandParse.execute(&errorString);
  QVERIFY2(result == true, errorString.toLatin1());
  errorString.clear();

  QString writeDocText;
  QString resultFilename("result.statemachine");
  ComBuildStateMachineFile commandWrite(resultFilename, model);
  writeDocText = commandWrite.toDocText();
  QVERIFY2(!writeDocText.isEmpty(), errorString.toLatin1());
  bool localExecute = commandWrite.execute(&errorString);
  QCOMPARE(localExecute, true);

  writeDocText = writeDocText.simplified();
  readDocText= readDocText.simplified();
  QCOMPARE(QString::compare(readDocText, writeDocText, Qt::CaseSensitive), 0);

  QFile resultFile(resultFilename);
  fileResult = resultFile.open(QFile::ReadOnly | QFile::Text);
  QCOMPARE(fileResult, true);

  delete model;
  model = nullptr;

  return;
}

//path not defined
void BuildModelFileTest::buildStateMachineFile_NoPathTest()
{
  using namespace dslparser::statemachine;
  using namespace model::statemachine;
  StateMachineModel* model = new StateMachineModel();

  QString praefix = ":/test_models/";
  QString filename = praefix + "test_model.statemachine";
  QFile file(filename);
  bool fileResult = file.open(QFile::ReadOnly | QFile::Text);
  if(!fileResult)
      qDebug()<<"file '"<<filename<<"' could not be opended!";
  QCOMPARE(fileResult, true);

  QString readDocText(file.readAll());
  ComBuildStateMachineModel commandParse(readDocText,
                                         model,
                                         praefix);
  QString errorString;
  bool result = commandParse.execute(&errorString);
  QVERIFY2(result == true, errorString.toLatin1());
  errorString.clear();

  QString resultFilename("");
  ComBuildStateMachineFile commandWrite(resultFilename, model);
  result = commandWrite.execute(&errorString);
  QCOMPARE(result, false);
}

//path not defined
void BuildModelFileTest::buildStateMachineFile_WrongPathTest()
{
  using namespace dslparser::statemachine;
  using namespace model::statemachine;
  StateMachineModel* model = new StateMachineModel();

  QString praefix = ":/test_models/";
  QString filename = praefix + "test_model.statemachine";
  QFile file(filename);
  bool fileResult = file.open(QFile::ReadOnly | QFile::Text);
  if(!fileResult)
      qDebug()<<"file '"<<filename<<"' could not be opended!";
  QCOMPARE(fileResult, true);

  QString readDocText(file.readAll());
  ComBuildStateMachineModel commandParse(readDocText,
                                         model,
                                         praefix);
  QString errorString;
  bool result = commandParse.execute(&errorString);
  QVERIFY2(result == true, errorString.toLatin1());
  errorString.clear();

  QString resultFilename("/Lorem/ipsum/zz00/file.file");
  ComBuildStateMachineFile commandWrite(resultFilename, model);
  result = commandWrite.execute(&errorString);
  QCOMPARE(result, false);
}

void BuildModelFileTest::buildSpenatFileTest()
{
  using namespace dslparser::spenat;
  using namespace model::spenat;
  SpenatDeclModel* model = new SpenatDeclModel();

  QString praefix = ":/test_models/";
  QString filename = praefix + "test_model.spenat";
  QFile file(filename);
  bool fileResult = file.open(QFile::ReadOnly | QFile::Text);
  if(!fileResult)
      qDebug()<<"file '"<<filename<<"' could not be opended!";
  QCOMPARE(fileResult, true);

  QString readDocText(file.readAll());
  ComBuildSpenatModel commandParse(readDocText,
                                   model);
  QString errorString;
  bool result = commandParse.execute(&errorString);
  if(!result)
    qDebug() << errorString.toLatin1();
  QCOMPARE(result, true);
  errorString.clear();

  QString resultFilename("result.spenat");
  ComBuildSpenatFile commandWrite(resultFilename, model);
  result = commandWrite.execute(&errorString);
  QVERIFY2(result == true, errorString.toLatin1());

  QFile resultFile(resultFilename);
  bool fileResult2 = resultFile.open(QFile::ReadOnly | QFile::Text);
  if(!fileResult2)
      qDebug()<<"file '"<<resultFilename<<"' could not be opended!";
  QCOMPARE(fileResult, true);

  QString resultDocText(resultFile.readAll());
  readDocText = readDocText.simplified();
  resultDocText = resultDocText.simplified();
  QCOMPARE(QString::compare(readDocText, resultDocText, Qt::CaseSensitive), 0);

  bool fileDelResult = resultFile.remove();
  QCOMPARE(fileDelResult, true);

  delete model;
  model = nullptr;

  return;
}

void BuildModelFileTest::buildSpenatFileOptionalTest()
{
  using namespace dslparser::spenat;
  using namespace model::spenat;
  SpenatDeclModel* model = new SpenatDeclModel();

  QString praefix = ":/test_models/";
  QString filename = praefix + "test_model.spenat";
  QFile file(filename);
  bool fileResult = file.open(QFile::ReadOnly | QFile::Text);
  if(!fileResult)
      qDebug()<<"file '"<<filename<<"' could not be opended!";
  QCOMPARE(fileResult, true);

  QString readDocText(file.readAll());
  ComBuildSpenatModel commandParse(readDocText,
                                   model);
  QString errorString;
  bool result = commandParse.execute(&errorString);
  QVERIFY2(result == true, errorString.toLatin1());
  errorString.clear();

  QString writeDocText;
  QString resultFilename("result.spenat");
  ComBuildSpenatFile commandWrite(resultFilename, model);
  writeDocText = commandWrite.toDocText();
  QVERIFY2(!writeDocText.isEmpty(), errorString.toLatin1());

  writeDocText = writeDocText.simplified();
  readDocText= readDocText.simplified();
  QCOMPARE(QString::compare(readDocText, writeDocText, Qt::CaseSensitive), 0);

  QFile resultFile(resultFilename);
  fileResult = resultFile.open(QFile::ReadOnly | QFile::Text);
  QCOMPARE(fileResult, false);

  delete model;
  model = nullptr;

  return;
}


//path not defined
void BuildModelFileTest::buildSpenatFile_NoPathTest()
{
  using namespace dslparser::spenat;
  using namespace model::spenat;
  SpenatDeclModel* model = new SpenatDeclModel();

  QString praefix = ":/test_models/";
  QString filename = praefix + "test_model.spenat";
  QFile file(filename);
  bool fileResult = file.open(QFile::ReadOnly | QFile::Text);
  if(!fileResult)
      qDebug()<<"file '"<<filename<<"' could not be opended!";
  QCOMPARE(fileResult, true);

  QString readDocText(file.readAll());
  ComBuildSpenatModel commandParse(readDocText,
                                   model);
  QString errorString;
  bool result = commandParse.execute(&errorString);
  QVERIFY2(result == true, errorString.toLatin1());
  errorString.clear();

  QString resultFilename("");
  ComBuildSpenatFile commandWrite(resultFilename, model);
  result = commandWrite.execute(&errorString);
  QCOMPARE(result, false);
}

//path not defined
void BuildModelFileTest::buildSpenatFile_WrongPathTest()
{
  using namespace dslparser::spenat;
  using namespace model::spenat;
  SpenatDeclModel* model = new SpenatDeclModel();

  QString praefix = ":/test_models/";
  QString filename = praefix + "test_model.spenat";
  QFile file(filename);
  bool fileResult = file.open(QFile::ReadOnly | QFile::Text);
  if(!fileResult)
      qDebug()<<"file '"<<filename<<"' could not be opended!";
  QCOMPARE(fileResult, true);

  QString readDocText(file.readAll());
  ComBuildSpenatModel commandParse(readDocText,
                                   model);
  QString errorString;
  bool result = commandParse.execute(&errorString);
  QVERIFY2(result == true, errorString.toLatin1());
  errorString.clear();

  QString resultFilename("/Lorem/ipsum/zz00/file.file");
  ComBuildSpenatFile commandWrite(resultFilename, model);
  result = commandWrite.execute(&errorString);
  QCOMPARE(result, false);
}

QTEST_GUILESS_MAIN(BuildModelFileTest)

#include "tst_buildmodelfile.moc"
