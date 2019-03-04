/*
 * This file is part of mobata.
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

#include "comcreatemodetrace.hpp"
#include "mobata/model/base/io/readhelpers.hpp"
#include "mobata/utils/functors.hpp"
#include <QDomDocument>
#include <QJsonArray>
#include <QJsonParseError>
#include <QFile>
#include <QTextStream>

using namespace modtrace;

class ComCreateModeTrace::Private
{
  friend class ComCreateModeTrace;

  const QString _spenatTraceFilePath;
  const QString _atsFilePath;
  const QString _targetPath;
  const QString _filename;

  QStringList                _testcaseList;
  QHash<QString,QStringList> _placesRequirements;
  QHash<QString,QStringList> _transitionsRequirements;
  QHash<QString,bool>        _placesRequirementsChange;
  QHash<QString,bool>        _transitionsRequirementsChange;

  QHash<QString,QStringList> _testcaseRequirements;
  QHash<QString,QStringList> _testcasePlaces;
  QHash<QString,QStringList> _testcaseTransitions;
  QHash<QString,bool>        _testcaseChanged;
  int                        _iteration;

  Private(const QString spenatTraceFilePath,
          const QString atsFilePath,
          const QString filename,
          const QString targetPath
          )
    : _spenatTraceFilePath(spenatTraceFilePath),
      _atsFilePath(atsFilePath),
      _filename(filename),
      _targetPath(targetPath)
  {}
};

ComCreateModeTrace::ComCreateModeTrace(const QString& spenatTraceFilePath,
                                       const QString& atsFilePath,
                                       const QString& filename,
                                       const QString& targetPath):
  _d(new Private(spenatTraceFilePath, atsFilePath, filename, targetPath))
{
}

bool ComCreateModeTrace::execute(QString* errorString)
{
  QFile spenatInputFile(this->_d->_spenatTraceFilePath);
  if (!spenatInputFile.open(QIODevice::ReadOnly
                            | QIODevice::Text))
  {
    utils::AddPtrString(errorString) << "Spenat trace file '" << this->_d->_spenatTraceFilePath << "' could not be loaded!";
    return false;
  }
  QByteArray spenatFileContent = spenatInputFile.readAll();
  spenatInputFile.close();

  QFile atsInputFile(this->_d->_atsFilePath);
  if (!atsInputFile.open(QIODevice::ReadOnly
                         | QIODevice::Text))
  {
    utils::AddPtrString(errorString) << "Ats file '" << this->_d->_atsFilePath << "' could not be loaded!";
    return false;
  }
  QByteArray atsFileContent = atsInputFile.readAll();
  atsInputFile.close();

  QJsonParseError err;
  QJsonDocument doc = QJsonDocument::fromJson(spenatFileContent, &err);
  if(err.error != QJsonParseError::NoError)
  {
    utils::AddPtrString(errorString) << err.errorString();
    return false;
  }

  QJsonObject jsonObject = doc.object();
  if(!model::base::io::readProperty<int>(jsonObject, QStringLiteral("iteration"), &this->_d->_iteration, errorString))
    return false;

  if(!readRequirements(QStringLiteral("places"), jsonObject, errorString))
    return false;

  if(!readRequirements(QStringLiteral("transitions"), jsonObject, errorString))
    return false;

  QDomDocument ats("ats");
  if (!ats.setContent(atsFileContent, false, errorString))
    return false;

  QDomElement atsElement = ats.firstChildElement();
  QDomNodeList testcases = atsElement.elementsByTagName(QStringLiteral("testcase"));
  for(int tcit=0; tcit < testcases.length(); tcit++)
  {
    QDomNode testcase = testcases.item(tcit);
    if(!testcase.isElement())
    {
      utils::AddPtrString(errorString) << "Error: Testcase node is not a XML element!";
      return false;
    }
    QString testcaseName;
    if(!readAttribute(testcase, QStringLiteral("name"), &testcaseName, errorString))
      return false;

    this->_d->_testcaseList.append(testcaseName);

    bool testcaseChanged = false;
    QStringList placeList, transitionList;
    QDomNodeList messages = testcase.childNodes();
    for(int mit=0; mit < messages.length(); mit++)
    {
      QDomNode message = messages.item(mit);
      QDomNodeList messageChildNodes = message.childNodes();

      for(int mcit=0; mcit < messageChildNodes.length(); mcit++)
      {
        QDomNode messageChildNode=messageChildNodes.item(mcit);
        if(messageChildNode.nodeName() != QStringLiteral("coverages"))
          continue;

        QDomNodeList coverageNodes=messageChildNode.childNodes();
        for(int cit=0; cit < coverageNodes.length(); cit++)
        {
          QDomNode coverage = coverageNodes.item(cit);
          QString itemType, itemName;
          if(!readAttribute(coverage, QStringLiteral("name"), &itemName, errorString))
            return false;
          if(!readAttribute(coverage, QStringLiteral("type"), &itemType, errorString))
            return false;
          if(itemType == QString("PlaceCoverageItem"))
          {
            if(!this->_d->_placesRequirements.contains(itemName)
               || !this->_d->_placesRequirementsChange.contains(itemName))
            {
              utils::AddPtrString(errorString) << "Place coverage item '"<< itemName << "'from ats file does not exist in spenat trace file!";
              return false;
            }
            if(placeList.contains(itemName))
              continue;

            placeList.append(itemName);
            if(this->_d->_placesRequirementsChange.value(itemName))
              testcaseChanged = true;
            QStringList reqList = this->_d->_placesRequirements.value(itemName);
            mergeRequirementsLists(reqList, testcaseName);
          }
          else if(itemType == QString("TransitionCoverageItem"))
          {
            if(!this->_d->_transitionsRequirements.contains(itemName)
               || !this->_d->_transitionsRequirementsChange.contains(itemName))
            {
              utils::AddPtrString(errorString) << "Transition coverage item '"<< itemName << "'from ats file does not exist in spenat trace file!";
              return false;
            }

            if(transitionList.contains(itemName))
              continue;

            transitionList.append(itemName);
            if(this->_d->_transitionsRequirementsChange.value(itemName))
              testcaseChanged = true;
            QStringList reqList = this->_d->_transitionsRequirements.value(itemName);
            mergeRequirementsLists(reqList, testcaseName);
          }
        }
      }
    }
    this->_d->_testcasePlaces.insert(testcaseName, placeList);
    this->_d->_testcaseTransitions.insert(testcaseName, transitionList);
    this->_d->_testcaseChanged.insert(testcaseName, testcaseChanged);
  }

  if(!saveToJsonFile(errorString))
    return false;

  return true;
}

bool ComCreateModeTrace::saveToJsonFile(QString* errorString)
{
  QJsonObject testcaseTrace;
  testcaseTrace[QString("iteration")] = this->_d->_iteration;

  QJsonArray testcaseArray;
  for(QString testcase : this->_d->_testcaseList)
  {
    QJsonObject testcaseObject;
    bool reqChanged = this->_d->_testcaseChanged.value(testcase);
    QJsonArray requirements = QJsonArray::fromStringList(this->_d->_testcaseRequirements.value(testcase));
    QJsonArray places = QJsonArray::fromStringList(this->_d->_testcasePlaces.value(testcase));
    QJsonArray transitions = QJsonArray::fromStringList(this->_d->_testcaseTransitions.value(testcase));

    testcaseObject[QString("name")] = testcase;
    testcaseObject[QString("req_changed")] = reqChanged;
    testcaseObject[QString("requirements")] = requirements;
    testcaseObject[QString("places")] = places;
    testcaseObject[QString("transitions")] = transitions;

    testcaseArray.append(testcaseObject);
  }

  testcaseTrace[QString("testcases")] = testcaseArray;

  QJsonDocument jsonDocument(testcaseTrace);

  QString filepath;
  if(!this->_d->_targetPath.isEmpty())
    filepath = this->_d->_targetPath + QStringLiteral("/");
  filepath.append(this->_d->_filename);
  filepath.append(".testcasetrace");
  QFile outputFile(filepath);
  if (!outputFile.open(QIODevice::WriteOnly
                       | QIODevice::Text))
  {
    utils::AddPtrString(errorString) << "spenat model trace could not be saved to " << filepath;
    return false;
  }

  QTextStream outputStream(&outputFile);
  outputStream << jsonDocument.toJson(QJsonDocument::Indented);

  return true;
}

bool ComCreateModeTrace::readRequirements(const QString& arrayKey, const QJsonObject& jsonObject, QString* errorString)
{
  QJsonArray jsonArray;
  if(model::base::io::readJsonArray(jsonObject, arrayKey, &jsonArray, errorString))
  {
    for(QJsonValue elementValue : jsonArray)
    {
      QJsonObject elementObject = elementValue.toObject();
      QString elementName;
      QStringList reqList;
      QJsonArray jsonReqArray;
      if(model::base::io::readProperty<QString>(elementObject, QStringLiteral("name"), &elementName, errorString))
      {
        if(model::base::io::readJsonArray(elementObject, QStringLiteral("requirements"), &jsonReqArray, errorString))
        {
          for(QJsonValue reqValue : jsonReqArray)
            reqList.append(reqValue.toString());
        }
      }
      bool reqChanged;
      if(!model::base::io::readProperty<bool>(elementObject, QStringLiteral("req_changed"), &reqChanged, errorString))
        return false;

      if(arrayKey == QStringLiteral("places"))
      {
        this->_d->_placesRequirements.insert(elementName, reqList);
        this->_d->_placesRequirementsChange.insert(elementName, reqChanged);
      }
      else if(arrayKey == QStringLiteral("transitions"))
      {
        this->_d->_transitionsRequirements.insert(elementName, reqList);
        this->_d->_transitionsRequirementsChange.insert(elementName, reqChanged);
      }
      else
      {
        utils::AddPtrString(errorString) << "Array key is wrong!";
        return false;
      }
    }
  }

  return true;
}

void ComCreateModeTrace::mergeRequirementsLists(const QStringList& reqList, const QString& jsonTestcaseName)
{
  if(this->_d->_testcaseRequirements.contains(jsonTestcaseName))
  {
    QStringList oldReqList = this->_d->_testcaseRequirements.value(jsonTestcaseName);
    for(QString valStr : reqList)
    {
      if(!oldReqList.contains(valStr))
      {
        oldReqList.append(valStr);
      }
    }
    this->_d->_testcaseRequirements.insert(jsonTestcaseName,oldReqList);
  }
  else{
    this->_d->_testcaseRequirements.insert(jsonTestcaseName, reqList);
  }
}

bool ComCreateModeTrace::readAttribute(const QDomNode& node, const QString& attribute, QString* property, QString* errorString)
{
  const QDomElement element = node.toElement();
  if(!element.hasAttribute(attribute))
  {
    utils::AddPtrString(errorString) << "XML element has no attribute '" << attribute << "'!";
    return false;
  }
  utils::AddPtrString(property) << element.attribute(attribute);
  return true;
}
