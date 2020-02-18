#include "spenatmodel.hpp"

#include "../graph/arcitem.hpp"
#include "transitionitem.hpp"
#include "placeitem.hpp"
#include "preplacearc.hpp"
#include "postplacearc.hpp"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

#include "../../memory_leak_start.hpp"

namespace model{
namespace spenat{

SpenatModel::SpenatModel(QObject *parent)
  : SpenatBaseModel(parent)
{}

SpenatModel::SpenatModel(const QString& spenatName, QObject* parent)
  : SpenatBaseModel(spenatName, parent)
{}

SpenatModel::~SpenatModel()
{}

void serializeArcs(SpenatModel const* spenatModel, QJsonObject* json_spenatModel)
{
  Q_ASSERT(spenatModel && json_spenatModel);

  QJsonArray json_arcs;
  foreach(TransitionItem const* transItem, spenatModel->transitions())
  {
    foreach(PrePlaceArc const* prePlaceArc, transItem->prePlaceArcs())
    {
      QJsonObject json_arc;
      json_arc["sourceUuid"]=prePlaceArc->place()->uuid().toString();
      json_arc["targetUuid"]=transItem->uuid().toString();
      json_arc["uuid"]=prePlaceArc->uuid().toString();

      json_arcs.push_back(json_arc);
    }

    foreach(PostPlaceArc const* postPlaceArc, transItem->postPlaceArcs())
    {
      QJsonObject json_arc;
      json_arc["sourceUuid"]=transItem->uuid().toString();
      json_arc["targetUuid"]=postPlaceArc->place()->uuid().toString();
      json_arc["uuid"]=postPlaceArc->uuid().toString();

      json_arcs.push_back(json_arc);
    }
  }

  (*json_spenatModel)["arcs"]=json_arcs;

  return;
}

JsonObjectPtr SpenatModel::createJson() const
{
  JsonObjectPtr json_baseModelPtr=BaseClass::createJson();
  serializeArcs(this, json_baseModelPtr.data());

  return json_baseModelPtr;
}

JsonDocPtr SpenatModel::createJsonDocument() const
{
  JsonObjectPtr jsonSpenatModel=this->createJson();

  if(jsonSpenatModel)
    return JsonDocPtr(new QJsonDocument(*jsonSpenatModel.data()));

  return JsonDocPtr();
}

}///end namespace model
}///end namespace spenat
