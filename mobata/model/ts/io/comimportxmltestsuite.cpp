/*
 * This file is part of mobata.
 *
 * Copyright (C) 2019 ifak, https://www.ifak.eu/
 *
 * mobata is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * mobata is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License
 * along with mobata.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "comimportxmltestsuite.hpp"

#include "../testsuite.hpp"
#include "../testgroupitem.hpp"
#include "../sutitem.hpp"
#include "../testsystemitem.hpp"
#include "../testcaseitem.hpp"
#include "../sutcomponentitem.hpp"
#include "../testcomponentitem.hpp"

#include "readxmltestsuite.hpp"

#include <QXmlStreamReader>
#include <QStandardItem>
#include <QString>
#include <QFile>

using namespace model::base;
using namespace model::base::io;
using namespace model::ts;
using namespace model::ts::io;

class ComImportXmlTestSuite::Private
{
  friend class ComImportXmlTestSuite;

  const QString     _testSuiteFileName;
  TestSuite*        _testSuite;
  QXmlStreamReader  _testSuiteReader;

  Private(const QString& testSuiteFileName,
          TestSuite* testSuite)
    : _testSuiteFileName(testSuiteFileName),
      _testSuite(testSuite)
  {}

  bool readXmlTestSuite(QString* errorMessage);
  bool readXmlSut(QString* errorMessage);
  bool readXmlTestSystem(QString* errorMessage);
  bool readXmlTestCases(QString* errorMessage);
  bool readXmlTestCases(TestGroupItem* testGroup,
                        QString* errorMessage);
  bool readXmlTestGroups(QString* errorMessage);
};

bool ComImportXmlTestSuite::Private::readXmlTestSuite(QString *errorMessage)
{
  Q_ASSERT(this->_testSuiteReader.isStartElement()
           && this->_testSuiteReader.name() == "testsuite");

  QString testSuiteName;
  if(!readXmlStreamReaderAttribute<QString>(this->_testSuiteReader, QStringLiteral("name"),
                                            &testSuiteName, errorMessage))
    return false;
  this->_testSuite->setName(testSuiteName);

  while (this->_testSuiteReader.readNextStartElement())
  {
    bool result=true;
    if (this->_testSuiteReader.name() == QStringLiteral("types"))
    {
      result = readXmlDataTypes(&this->_testSuiteReader,
                                this->_testSuite,
                                errorMessage);
      if(!result)
        return false;
    }
    else if (this->_testSuiteReader.name() == QStringLiteral("signals"))
    {
      result = readXmlSignals(&this->_testSuiteReader,
                              this->_testSuite,
                              errorMessage);
      if(!result)
        return false;
    }
    else if (this->_testSuiteReader.name() == QStringLiteral("attributes"))
    {
      result = readXmlAttributes(&this->_testSuiteReader,
                                 this->_testSuite,
                                 errorMessage);
      if(!result)
        return false;
    }
    else if (this->_testSuiteReader.name() == QStringLiteral("sut"))
    {
      result = readXmlSut(errorMessage);
      if(!result)
        return false;
    }
    else if (this->_testSuiteReader.name() == QStringLiteral("testsystem"))
    {
      result = readXmlTestSystem(errorMessage);
      if(!result)
        return false;
    }
    else if (this->_testSuiteReader.name() == QStringLiteral("testcases"))
    {
      result = readXmlTestCases(errorMessage);
      if(!result)
        return false;
    }
    else if (this->_testSuiteReader.name() == QStringLiteral("testgroups"))
    {
      result = readXmlTestGroups(errorMessage);
      if(!result)
        return false;
    }
    else
    {
      if(errorMessage)
        *errorMessage += tr("unexpected xml element '%1' "
                            "within xml test suite file!")
                         .arg(this->_testSuiteReader.name().toString());
      return false;
    }
  }

  return true;
}

bool ComImportXmlTestSuite::Private::readXmlSut(QString* errorMessage)
{
  Q_ASSERT(this->_testSuiteReader.isStartElement()
           && this->_testSuiteReader.name() == QStringLiteral("sut"));

  SutItem* sutItem=this->_testSuite->sutItem();
  Q_ASSERT(sutItem);

  QString sutName;
  if(readXmlStreamReaderAttribute<QString>(this->_testSuiteReader,
                                           QStringLiteral("name"),
                                           &sutName,
                                           errorMessage))
    sutItem->setName(sutName);///optional

  while(this->_testSuiteReader.readNextStartElement())
  {
    if(this->_testSuiteReader.name() == QStringLiteral("components"))
    {
      bool result = msc::io::readXmlComponents<SutComponentItem, SutItem>(&this->_testSuiteReader,
                                                                          sutItem,
                                                                          errorMessage);
      if(!result)
        return false;
    }
    else
      this->_testSuiteReader.skipCurrentElement();
  }

  return true;
}

bool ComImportXmlTestSuite::Private::readXmlTestSystem(QString* errorMessage)
{
  Q_ASSERT(this->_testSuiteReader.isStartElement()
           && this->_testSuiteReader.name() == QStringLiteral("testsystem"));

  TestSystemItem* testSystemItem = this->_testSuite->testSystemItem();
  Q_ASSERT(testSystemItem);

  QString testSystemName;
  if(readXmlStreamReaderAttribute<QString>(this->_testSuiteReader, QStringLiteral("name"),
                                           &testSystemName, errorMessage))
    testSystemItem->setName(testSystemName);///optional

  while(this->_testSuiteReader.readNextStartElement())
  {
    if(this->_testSuiteReader.name() == QStringLiteral("components"))
    {
      bool result = msc::io::readXmlComponents<TestComponentItem,
          TestSystemItem>(&this->_testSuiteReader,
                          testSystemItem,
                          errorMessage);
      if(!result)
        return false;
    }
    else
      this->_testSuiteReader.skipCurrentElement();
  }

  return true;
}

bool ComImportXmlTestSuite::Private::readXmlTestCases(QString* errorMessage)
{
  return this->readXmlTestCases(0, errorMessage);
}

bool ComImportXmlTestSuite::Private::readXmlTestCases(TestGroupItem* testGroup,
                                                      QString* errorMessage)
{
  Q_ASSERT(this->_testSuiteReader.isStartElement()
           && this->_testSuiteReader.name() == QStringLiteral("testcases"));

  while (this->_testSuiteReader.readNextStartElement())
  {
    if(this->_testSuiteReader.name() == QStringLiteral("testcase"))
    {
      QString testCaseName;
      if(!base::io::readXmlStreamReaderAttribute<QString>(this->_testSuiteReader,
                                                          QStringLiteral("name"),
                                                          &testCaseName, errorMessage))
        return false;

      QUuid testCaseUuid;
      if(!base::io::readXmlStreamReaderAttribute<QUuid>(this->_testSuiteReader,
                                                        QStringLiteral("uuid"),
                                                        &testCaseUuid, errorMessage))
        return false;

      TestCaseItem* newTestCase = 0;
      if(testGroup)
        newTestCase = testGroup->addTestCase(testCaseName);
      else
        newTestCase = this->_testSuite->addTestCase(testCaseName);
      if(!newTestCase)
        return false;

      newTestCase->setUuid(testCaseUuid);
      bool result = readXmlTestCase(&this->_testSuiteReader,
                                    this->_testSuite,
                                    newTestCase,
                                    errorMessage);
      if(!result)
        return false;
    }
    else
      this->_testSuiteReader.skipCurrentElement();
  }

  return true;
}

bool ComImportXmlTestSuite::Private::readXmlTestGroups(QString* errorMessage)
{
  Q_ASSERT(this->_testSuiteReader.isStartElement()
           && this->_testSuiteReader.name() == QStringLiteral("testgroups"));

  while (this->_testSuiteReader.readNextStartElement())
  {
    if(this->_testSuiteReader.name() == QStringLiteral("testgroup"))
    {
      QString testGroupName;
      if(!base::io::readXmlStreamReaderAttribute<QString>(this->_testSuiteReader,
                                                          QStringLiteral("name"),
                                                          &testGroupName,
                                                          errorMessage))
        return false;

      TestGroupItem* newTestGroup = this->_testSuite->addTestGroup(testGroupName,
                                                                   errorMessage);
      if(newTestGroup)
        return false;

      while(this->_testSuiteReader.readNextStartElement())
      {
        if (this->_testSuiteReader.name() == QStringLiteral("testcases"))
        {
          bool result = readXmlTestCases(newTestGroup, errorMessage);
          if(!result)
            return false;
        }
        else
          this->_testSuiteReader.skipCurrentElement();
      }
    }
  }

  return true;
}

////command class///////////////
ComImportXmlTestSuite::ComImportXmlTestSuite(const QString& testSuiteFileName,
                                             TestSuite* testSuite,
                                             QObject *parent)
  :	QObject(parent),
    _d(new Private(testSuiteFileName, testSuite))
{
  Q_ASSERT(this->_d->_testSuite);
}

ComImportXmlTestSuite::~ComImportXmlTestSuite()
{
  delete this->_d;
}

bool ComImportXmlTestSuite::execute(QString* errorMessage)
{
  Q_ASSERT(this->_d->_testSuite);

  this->_d->_testSuite->reset();

  QFile testSuiteFile(this->_d->_testSuiteFileName);
  if (!testSuiteFile.open(QFile::ReadOnly | QFile::Text))
  {
    if(errorMessage)
      *errorMessage += tr("import test suite error: cannot read file %1:\n%2.")
                       .arg(this->_d->_testSuiteFileName)
                       .arg(testSuiteFile.errorString());
    return false;
  }

  this->_d->_testSuiteReader.setDevice(&testSuiteFile);
  if (this->_d->_testSuiteReader.readNextStartElement())
  {
    if (this->_d->_testSuiteReader.name() == "testsuite")
    {
      bool result = this->_d->readXmlTestSuite(errorMessage);
      if(!result)
        return false;
    }
    else
      this->_d->_testSuiteReader.raiseError(tr("The file '' is not a valid test suite xml file.")
                                            .arg(this->_d->_testSuiteFileName));
  }

  if(this->_d->_testSuiteReader.error())
  {
    if(errorMessage)
      *errorMessage += this->_d->_testSuiteReader.errorString();
    return false;
  }

  return true;
}
