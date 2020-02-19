#include "converttrace.h"
#include "mobata/model/base/io/readhelpers.hpp"
#include "mobata/utils/functors.hpp"

#include <QFile>
#include <QTextStream>
#include <QJsonObject>

using namespace convert::statemachine;

class ConvertTrace::Private
{
  friend class ConvertTrace;

  const QString     _modelName;
  QString     _tracePath;
  QJsonObject _statemachineTrace;
  QJsonObject _spenatTrace;
  QJsonArray  _states;
  QJsonArray  _statemachineTransitions;
  QJsonArray  _places;
  QJsonArray  _spenatTransitions;

  Private(const QString modelName, const QString tracePath)
    : _modelName(modelName),
      _tracePath(tracePath)
  {}
};

ConvertTrace::ConvertTrace(const QString modelName, const QString tracePath)
  : _d(new Private(modelName, tracePath))
{}

ConvertTrace::~ConvertTrace()
{
  delete this->_d;
}

bool ConvertTrace::loadStatemachineTrace(QString smTraceDoc, QString* errorString)
{
  QJsonParseError jsonError;
  QJsonDocument json_smTraceDoc = QJsonDocument::fromJson(smTraceDoc.toLatin1(), &jsonError);
  if(jsonError.error != QJsonParseError::NoError)
  {
    utils::AddPtrString(errorString) << jsonError.errorString();
    return false;
  }

  this->_d->_statemachineTrace = json_smTraceDoc.object();

  bool result = model::base::io::readJsonArray(this->_d->_statemachineTrace, QString("states"),
                                               &this->_d->_states, errorString);
  if(!result)
    return false;

  result = model::base::io::readJsonArray(this->_d->_statemachineTrace, QString("transitions"),
                                          &this->_d->_statemachineTransitions, errorString);
  if(!result)
    return false;

  return true;
}

bool ConvertTrace::loadStatemachineTraceFromFile(QString* errorString)
{
  QString filepath = this->_d->_tracePath;
  filepath.append(this->_d->_modelName);
  filepath.append(".statemachinetrace");

  QFile inputFile(filepath);
  if (!inputFile.open(QIODevice::ReadOnly
                      | QIODevice::Text))
  {
    utils::AddPtrString(errorString) << "statemachine trace file '" << filepath << "' could not be loaded!";
    return false;
  }

  QString statemachineTraceDoc = QString::fromStdString(inputFile.readAll().toStdString());
  if(statemachineTraceDoc.isEmpty())
  {
    utils::AddPtrString(errorString) << QString("Statemachine traceability file is empty!");
    return false;
  }

  this->loadStatemachineTrace(statemachineTraceDoc, errorString);
  inputFile.close();

  return true;
}

bool ConvertTrace::appendPlaceTrace(const QString placeName, QString* errorString)
{
  //init states are not part of the tracefile
  if(placeName == QStringLiteral("init"))
    return true;

  for(const QJsonValue& jsonValue : this->_d->_states)
  {
    if(!jsonValue.isObject())
      return false;
    QJsonObject jsonObject = jsonValue.toObject();
    QString stateName;
    bool result = model::base::io::readProperty<QString>(jsonObject,
                                                         QStringLiteral("name"),
                                                         &stateName,
                                                         errorString);
    if(!result)
    {
      utils::AddPtrString(errorString) << "Can't read property name from statemachine trace file json!";
      return false;
    }

    if(stateName == placeName)
    {
      this->_d->_places.append(jsonObject);
      return true;
    }
  }

  utils::AddPtrString(errorString) << "Can't find place" <<  placeName << " in statemachine trace!";
  return false;
}

bool ConvertTrace::appendTransitionTrace(const QString spenatTransName,
                                         QStringList smTransitionNameList)
{
  QJsonObject spenatTransition;
  spenatTransition[QString("name")] = spenatTransName;
  bool requirementChanged = false;
  QJsonArray requirements;

  for(QString smTransitionName : smTransitionNameList)
  {
    for(const QJsonValue& jsonValue : this->_d->_statemachineTransitions)
    {
      if(!jsonValue.isObject())
        return false;
      QJsonObject jsonObject=jsonValue.toObject();
      QString propName;
      bool result = model::base::io::readProperty<QString>(jsonObject,
                                                           QStringLiteral("name"),
                                                           &propName);
      if(!result)
        return false;

      if(propName == smTransitionName)
      {
        bool transitionReqChanged;
        result = model::base::io::readProperty<bool>(jsonObject,
                                                     QStringLiteral("req_changed"),
                                                     &transitionReqChanged);
        if(!result)
          return false;

        if(transitionReqChanged)
          requirementChanged = true;

        QJsonArray propRequirements;
        result = model::base::io::readJsonArray(jsonObject,
                                                QString("requirements"),
                                                &propRequirements);
        if(!result)
          return false;
        copyRequirements(propRequirements, requirements);
      }
    }
  }

  spenatTransition[QString("req_changed")] = requirementChanged;
  spenatTransition[QString("requirements")] = requirements;
  this->_d->_spenatTransitions.append(spenatTransition);

  return true;
}

QJsonDocument ConvertTrace::createJsonDocument(QString* errorString)
{
  int iterations;
  bool result = model::base::io::readProperty<int>(this->_d->_statemachineTrace,
                                                   QStringLiteral("iteration"),
                                                   &iterations,
                                                   errorString);
  if(!result)
    return QJsonDocument();

  this->_d->_spenatTrace[QString("iteration")] = iterations;
  this->_d->_spenatTrace[QString("places")] = this->_d->_places;
  this->_d->_spenatTrace[QString("transitions")] = this->_d->_spenatTransitions;

  QJsonDocument jsonDocument(this->_d->_spenatTrace);

  return jsonDocument;
}

void ConvertTrace::copyRequirements(const QJsonArray smRequirements, QJsonArray& spenatRequirements)
{
  for(const QJsonValue& requirement : smRequirements)
  {
    if(!spenatRequirements.contains(requirement.toString()))
      spenatRequirements.append(requirement.toString());
  }
}
