#include <QtTest>

#include <dslparser/importreader/combuildimportreadermodel.hpp>

class ImportReaderTest
    : public QObject
{
  Q_OBJECT

public:
  ImportReaderTest();

private Q_SLOTS:
  void initTestCase();
  void initTest();
  void cleanupTest();

  void simpleImportReaderTest_1();
  void simpleImportReaderTest_2();
  void simpleImportReaderTest_3();
  void simpleImportReaderTest_4();
  void simpleImportReaderTest_5();
};

ImportReaderTest::ImportReaderTest()
{}

void ImportReaderTest::initTestCase()
{
  Q_INIT_RESOURCE(importreader);
}

void ImportReaderTest::initTest()
{}

void ImportReaderTest::cleanupTest()
{}

void ImportReaderTest::simpleImportReaderTest_1()
{
  QString docText("\nimport <sut_example.sut> as sut\n");

  dslparser::importreader::ComBuildImportReaderModel command(docText,
                                                             QStringLiteral(":/importreader"));

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);
  QCOMPARE(command.errors().size(), 0);
  QCOMPARE(command.importedFiles().size(), 1);

  QCOMPARE(command.importedFiles().value(QStringLiteral("sut")),
           QFileInfo(QLatin1String(":/importreader")+"/sut_example.sut").canonicalFilePath());

  return;
}

void ImportReaderTest::simpleImportReaderTest_2()
{
  QString docText("\nimport <sut_example.sut> as sut\n");

  dslparser::importreader::ComBuildImportReaderModel command(docText, QStringLiteral("/"));

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(command.errors().size(), 1);
  QCOMPARE(command.errors().at(0).errorType(), dslparser::DslError::FileError);
  QCOMPARE(int(command.errors().at(0).line()), 2);
  QCOMPARE(command.errors().at(0).charPositionInLine(), 8);
  QCOMPARE(command.importedFiles().size(), 0);

  return;
}

void ImportReaderTest::simpleImportReaderTest_3()
{
  QString docText("\nimport <sut_example.sut> as sut\nimport <sut_example.sut> as decl");

  dslparser::importreader::ComBuildImportReaderModel command(docText,
                                                             QStringLiteral(":/importreader"));

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);
  QCOMPARE(command.errors().size(), 0);
  QCOMPARE(command.importedFiles().size(), 2);

  QCOMPARE(command.importedFiles().value(QStringLiteral("sut")),
           QFileInfo(QLatin1String(":/importreader")+"/sut_example.sut").canonicalFilePath());
  QCOMPARE(command.importedFiles().value(QStringLiteral("decl")),
           QFileInfo(QLatin1String(":/importreader")+"/sut_example.sut").canonicalFilePath());

  return;
}

void ImportReaderTest::simpleImportReaderTest_4()
{
  QString docText("\nimport <sut_example.sut> as sut\nimport <sut_example.sut> as decl"
                  "\n\n blah blah blah\n");

  dslparser::importreader::ComBuildImportReaderModel command(docText,
                                                             QStringLiteral(":/importreader"));

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);
  QCOMPARE(command.errors().size(), 0);
  QCOMPARE(command.importedFiles().size(), 2);

  QCOMPARE(command.importedFiles().value(QStringLiteral("sut")),
           QFileInfo(QLatin1String(":/importreader")+"/sut_example.sut").canonicalFilePath());
  QCOMPARE(command.importedFiles().value(QStringLiteral("decl")),
           QFileInfo(QLatin1String(":/importreader")+"/sut_example.sut").canonicalFilePath());

  return;
}

void ImportReaderTest::simpleImportReaderTest_5()
{
  QString docText("\nimport <sut_example.sut> as sut\nimport <sut_example.sut> as decl"
                  "\n\nimport <sut_example.sut> as sut"
                  "\n\n blah blah blah\n");

  dslparser::importreader::ComBuildImportReaderModel command(docText,
                                                             QStringLiteral(":/importreader"));

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(errorString.isEmpty(), true);
  QCOMPARE(command.errors().size(), 1);
  QCOMPARE(command.importedFiles().size(), 2);

  QCOMPARE(command.importedFiles().value(QStringLiteral("sut")),
           QFileInfo(QLatin1String(":/importreader")+"/sut_example.sut").canonicalFilePath());
  QCOMPARE(command.importedFiles().value(QStringLiteral("decl")),
           QFileInfo(QLatin1String(":/importreader")+"/sut_example.sut").canonicalFilePath());

  QCOMPARE(command.errors().at(0).errorType(), dslparser::DslError::SyntaxError);
  QCOMPARE(int(command.errors().at(0).line()), 5);
  QCOMPARE(command.errors().at(0).charPositionInLine(), 28);

  return;
}

QTEST_GUILESS_MAIN(ImportReaderTest)

#include "tst_importreader.moc"
