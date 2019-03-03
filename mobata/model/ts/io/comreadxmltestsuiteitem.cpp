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

#include "comreadxmltestsuiteitem.hpp"

#include "../testsuiteitem.hpp"
#include "../sutitem.hpp"
#include "../testsystemitem.hpp"
#include "../testcaseitem.hpp"
#include "../sutcomponentitem.hpp"

#include "readxmltestsuite.hpp"

#include <QFileInfo>
#include <QXmlStreamReader>

using namespace model::base;
using namespace model::base::io;
using namespace model::ts;
using namespace model::ts::io;

class ComReadXmlTestSuiteItem::Private
{
  friend class ComReadXmlTestSuiteItem;

  const QString     _testSuiteFileName;
  TestSuiteItem*    _testSuiteItem;
  QXmlStreamReader  _testSuiteItemReader;

  Private(const QString& testSuiteFileName,
          TestSuiteItem* testSuiteItem)
    : _testSuiteFileName(testSuiteFileName),
      _testSuiteItem(testSuiteItem)
  {}

  bool readXmlTestSuiteItem(QString* errorMessage);
  bool readXmlSut(QString* errorMessage);
  bool readXmlTestSystem(QString* errorMessage);
  bool readXmlTestCases(QString* errorMessage);
};

bool ComReadXmlTestSuiteItem::Private::readXmlTestSuiteItem(QString *errorMessage)
{
  Q_ASSERT(this->_testSuiteItemReader.isStartElement()
           && this->_testSuiteItemReader.name() == "testsuite");

  QString testSuiteName;
  if(!readXmlStreamReaderAttribute<QString>(this->_testSuiteItemReader, QStringLiteral("name"),
                                            &testSuiteName, errorMessage))
    return false;
  this->_testSuiteItem->setName(testSuiteName);
  this->_testSuiteItem->setText(testSuiteName);

  while (this->_testSuiteItemReader.readNextStartElement())
  {
    bool result=true;
    if (this->_testSuiteItemReader.name() == QStringLiteral("types"))
    {
      result = readXmlDataTypes(&this->_testSuiteItemReader,
                                this->_testSuiteItem,
                                errorMessage);
      if(!result)
        return false;
    }
    else if (this->_testSuiteItemReader.name() == QStringLiteral("signals"))
    {
      result = readXmlSignals(&this->_testSuiteItemReader,
                              this->_testSuiteItem,
                              errorMessage);
      if(!result)
        return false;
    }
    else if (this->_testSuiteItemReader.name() == QStringLiteral("attributes"))
    {
      result = readXmlAttributes(&this->_testSuiteItemReader,
                                 this->_testSuiteItem,
                                 errorMessage);
      if(!result)
        return false;
    }
    else if (this->_testSuiteItemReader.name() == QStringLiteral("sut"))
    {
      result = readXmlSut(errorMessage);
      if(!result)
        return false;
    }
    else if (this->_testSuiteItemReader.name() == QStringLiteral("testsystem"))
    {
      result = readXmlTestSystem(errorMessage);
      if(!result)
        return false;
    }
    else if (this->_testSuiteItemReader.name() == QStringLiteral("testcases"))
    {
      result = readXmlTestCases(errorMessage);
      if(!result)
        return false;
    }
    else if (this->_testSuiteItemReader.name() == QStringLiteral("testgroups"))
    {
      utils::AddPtrString(errorMessage)<<tr("test groups are currently not supported "
                                            "for reading test suite item of file '%1'!")
                                         .arg(this->_testSuiteFileName);
      return false;
    }
    else
    {
      if(errorMessage)
        *errorMessage += tr("unexpected xml element '%1' "
                            "within xml test suite file!")
                         .arg(this->_testSuiteItemReader.name().toString());
      return false;
    }
  }

  return true;
}

bool ComReadXmlTestSuiteItem::Private::readXmlSut(QString* errorMessage)
{
  Q_ASSERT(this->_testSuiteItemReader.isStartElement()
           && this->_testSuiteItemReader.name() == QStringLiteral("sut"));

  SutItem* sutItem=this->_testSuiteItem->sutItem();
  Q_ASSERT(sutItem);

  QString sutName;
  if(readXmlStreamReaderAttribute<QString>(this->_testSuiteItemReader,
                                           QStringLiteral("name"),
                                           &sutName,
                                           errorMessage))
    sutItem->setName(sutName);///optional

  while(this->_testSuiteItemReader.readNextStartElement())
  {
    if(this->_testSuiteItemReader.name() == QStringLiteral("components"))
    {
      bool result = msc::io::readXmlComponents<SutComponentItem, SutItem>(&this->_testSuiteItemReader,
                                                                          sutItem,
                                                                          errorMessage);
      if(!result)
        return false;
    }
    else
      this->_testSuiteItemReader.skipCurrentElement();
  }

  return true;
}

bool ComReadXmlTestSuiteItem::Private::readXmlTestSystem(QString* errorMessage)
{
  Q_ASSERT(this->_testSuiteItemReader.isStartElement()
           && this->_testSuiteItemReader.name() == QStringLiteral("testsystem"));

  TestSystemItem* testSystemItem = this->_testSuiteItem->testSystemItem();
  Q_ASSERT(testSystemItem);

  QString testSystemName;
  if(readXmlStreamReaderAttribute<QString>(this->_testSuiteItemReader, QStringLiteral("name"),
                                           &testSystemName, errorMessage))
    testSystemItem->setName(testSystemName);///optional

  while(this->_testSuiteItemReader.readNextStartElement())
  {
    if(this->_testSuiteItemReader.name() == QStringLiteral("components"))
    {
      bool result = msc::io::readXmlComponents<TestComponentItem,
          TestSystemItem>(&this->_testSuiteItemReader,
                          testSystemItem,
                          errorMessage);
      if(!result)
        return false;
    }
    else
      this->_testSuiteItemReader.skipCurrentElement();
  }

  return true;
}

bool ComReadXmlTestSuiteItem::Private::readXmlTestCases(QString* errorMessage)
{
  Q_ASSERT(this->_testSuiteItemReader.isStartElement()
           && this->_testSuiteItemReader.name() == QStringLiteral("testcases"));

  while (this->_testSuiteItemReader.readNextStartElement())
  {
    if(this->_testSuiteItemReader.name() == QStringLiteral("testcase"))
    {
      QString testCaseName;
      if(!base::io::readXmlStreamReaderAttribute<QString>(this->_testSuiteItemReader,
                                                          QStringLiteral("name"),
                                                          &testCaseName, errorMessage))
        return false;

      QUuid testCaseUuid;
      if(!base::io::readXmlStreamReaderAttribute<QUuid>(this->_testSuiteItemReader,
                                                        QStringLiteral("uuid"),
                                                        &testCaseUuid, errorMessage))
        return false;

      TestCaseItem* newTestCase = this->_testSuiteItem->addTestCase(testCaseName);
      Q_ASSERT(newTestCase);

      newTestCase->setUuid(testCaseUuid);
      bool result = readXmlTestCase(&this->_testSuiteItemReader,
                                    this->_testSuiteItem,
                                    newTestCase,
                                    errorMessage);
      if(!result)
        return false;
    }
    else
      this->_testSuiteItemReader.skipCurrentElement();
  }

  return true;
}

////command class///////////////
ComReadXmlTestSuiteItem::ComReadXmlTestSuiteItem(const QString& testSuiteFileName,
                                                 TestSuiteItem* testSuiteItem,
                                                 QObject *parent)
  : QObject(parent),
    _d(new Private(testSuiteFileName, testSuiteItem))
{
  Q_ASSERT(this->_d->_testSuiteItem);
}

ComReadXmlTestSuiteItem::~ComReadXmlTestSuiteItem()
{
  delete this->_d;
}

bool ComReadXmlTestSuiteItem::execute(QString* errorMessage)
{
  Q_ASSERT(this->_d->_testSuiteItem);

  if(!QFileInfo(this->_d->_testSuiteFileName).exists())
  {
    utils::AddPtrString(errorMessage)<<tr("test suite file '%1' does not exist!")
                                       .arg(this->_d->_testSuiteFileName);
    return false;
  }

  this->_d->_testSuiteItem->reset();

  QFile testSuiteFile(this->_d->_testSuiteFileName);
  if (!testSuiteFile.open(QFile::ReadOnly | QFile::Text))
  {
    utils::AddPtrString(errorMessage)<<tr("import test suite error: cannot read file %1:\n%2.")
                                       .arg(this->_d->_testSuiteFileName)
                                       .arg(testSuiteFile.errorString());
    return false;
  }

  this->_d->_testSuiteItemReader.setDevice(&testSuiteFile);
  if (this->_d->_testSuiteItemReader.readNextStartElement())
  {
    if (this->_d->_testSuiteItemReader.name() == "testsuite")
    {
      bool result = this->_d->readXmlTestSuiteItem(errorMessage);
      if(!result)
        return false;
    }
    else
      this->_d->_testSuiteItemReader.raiseError(tr("The file '' is not a valid test suite xml file.")
                                                .arg(this->_d->_testSuiteFileName));
  }

  if(this->_d->_testSuiteItemReader.error())
  {
    if(errorMessage)
      *errorMessage += this->_d->_testSuiteItemReader.errorString();
    return false;
  }

  return true;
}
