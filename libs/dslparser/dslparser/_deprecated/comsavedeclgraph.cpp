#include "comsavedeclgraph.hpp"

#include "../../model/spenat/declmodel.hpp"
#include "../../model/spenat/placeitem.hpp"
#include "../../model/spenat/transitionitem.hpp"
#include "../../model/spenat/junctionitem.hpp"
#include "../../model/graph/arcitem.hpp"

#include "declscene.hpp"
#include "declplace.hpp"
#include "decltransition.hpp"
#include "decljunction.hpp"
#include "declarc.hpp"

#include "../base/textitem.hpp"

#include <QUuid>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include "../../memory_leak_start.hpp"

namespace view
{
namespace spenat
{

class ComSaveDeclGraph::Private
{
  friend class ComSaveDeclGraph;

  Private(model::spenat::DeclModel const* declModel,
          DeclScene const* graphScene,
          std::ofstream &graphOutputStream)
    :	_declModel(declModel),
      _graphScene(graphScene),
      _graphOutputStream(graphOutputStream)
  {}

public:
  ~Private()
  {}

private:
  model::spenat::DeclModel const* _declModel;
  DeclScene const*                _graphScene;
  std::ofstream&                  _graphOutputStream;
};

ComSaveDeclGraph::ComSaveDeclGraph(model::spenat::DeclModel const* declModel,
                                   DeclScene const* graphScene,
                                   std::ofstream &graphOutputStream)
  :	_d(new Private(declModel, graphScene, graphOutputStream))
{}

ComSaveDeclGraph::~ComSaveDeclGraph()
{}

void fillModelNodeJsonObject(model::graph::NodeItem const* modelNode,
                             QJsonObject& nodeJsonObject)
{
  Q_ASSERT(modelNode);

  nodeJsonObject["comment"]=modelNode->whatsThis();

  return;
}

void fillSceneNodeJsonObject(graph::AbstractNode const* sceneNode,
                             QJsonObject& nodeJsonObject)
{
  Q_ASSERT(sceneNode);

  nodeJsonObject["uuid"]=sceneNode->uuid().toString();

  QJsonObject json_declaration;
  json_declaration["text"]=sceneNode->notation();
  QJsonObject json_declPos;
  json_declPos["x"]=sceneNode->notationItem()->pos().x();
  json_declPos["y"]=sceneNode->notationItem()->pos().y();
  json_declaration["pos"]=json_declPos;
  nodeJsonObject["declaration"]=json_declaration;

  nodeJsonObject["color"]=sceneNode->brush().color().name();

  QJsonObject json_node_pos;
  json_node_pos["x"]=sceneNode->pos().x();
  json_node_pos["y"]=sceneNode->pos().y();
  nodeJsonObject["pos"]=json_node_pos;

  QJsonObject json_node_size;
  json_node_size["width"]=sceneNode->size().width();
  json_node_size["height"]=sceneNode->size().height();
  nodeJsonObject["size"]=json_node_size;

  return;
}

bool ComSaveDeclGraph::execute(QString* errorString)
{
  Q_UNUSED(errorString);

  QJsonObject json_declGraph;

  //////places//////////////////
  QJsonArray json_declPlaces;
  foreach(DeclPlace const* declPlace,
          this->_d->_graphScene->places())
  {
    QJsonObject json_place;

    fillSceneNodeJsonObject(declPlace, json_place);
    json_place["initMarking"]=declPlace->getInitMarking();

    //additional stuff for model-place, if available///
    ::model::spenat::PlaceItem const* modelPlace=this->_d->_declModel->place(declPlace->uuid());
    if(modelPlace)
      fillModelNodeJsonObject(modelPlace, json_place);

    json_declPlaces.push_back(json_place);
  }
  json_declGraph["places"]=json_declPlaces;

  //////transitions//////////////////
  QJsonArray json_declTransitions;
  foreach(DeclTransition const* declTransition,
          this->_d->_graphScene->transitions())
  {
    QJsonObject json_transition;

    fillSceneNodeJsonObject(declTransition, json_transition);

    //additional stuff for model-transition, if available///
    model::spenat::TransitionItem const* modelTransition=0;
    modelTransition=this->_d->_declModel->transition(declTransition->uuid());
    if(modelTransition)
      fillModelNodeJsonObject(modelTransition, json_transition);

    json_declTransitions.push_back(json_transition);
  }
  json_declGraph["transitions"]=json_declTransitions;

  //////junctions//////////////////
  QJsonArray json_declJunctions;
  foreach(DeclJunction const* declJunction,
          this->_d->_graphScene->junctions())
  {
    QJsonObject json_junction;

    fillSceneNodeJsonObject(declJunction, json_junction);

    //additional stuff for model-transition, if available///
    model::spenat::JunctionItem const* modelJunction=0;
    modelJunction=this->_d->_declModel->junction(declJunction->uuid());
    if(modelJunction)
      fillModelNodeJsonObject(modelJunction, json_junction);

    json_declJunctions.push_back(json_junction);
  }
  json_declGraph["junctions"]=json_declJunctions;

  //////arcs//////////////////
  QJsonArray json_declArcs;
  foreach(DeclArc const* declArc,
          this->_d->_graphScene->arcs())
  {
    QJsonObject json_arc;

    json_arc["uuid"]=declArc->uuid().toString();

    QJsonObject json_declaration;
    json_declaration["text"]=declArc->notation();
    QJsonObject json_declPos;
    json_declPos["x"]=declArc->notationItem()->pos().x();
    json_declPos["y"]=declArc->notationItem()->pos().y();
    json_declaration["pos"]=json_declPos;
    json_arc["declaration"]=json_declaration;

    json_arc["source_id"]=declArc->source()->uuid().toString();
    json_arc["target_id"]=declArc->target()->uuid().toString();

    json_arc["color"]=declArc->pen().color().name();

    QJsonArray json_arc_points;
    foreach(const QPointF& point, declArc->controlPointFs())
    {
      QJsonObject json_point;
      json_point["x"]=point.x();
      json_point["y"]=point.y();
      json_arc_points.push_back(json_point);
    }
    if(json_arc_points.size())
      json_arc["points"]=json_arc_points;

    //additional stuff for model-transition, if available///
    model::spenat::TransitionItem const* modelTransition=0;
    modelTransition=this->_d->_declModel->transition(declArc->uuid());
    if(modelTransition)
      fillModelNodeJsonObject(modelTransition, json_arc);

    json_declArcs.push_back(json_arc);
  }
  json_declGraph["arcs"]=json_declArcs;

  QJsonDocument declDocument(json_declGraph);
  this->_d->_graphOutputStream<<declDocument.toJson().toStdString();

  return true;
}

}//end namespace spenat
}//end namespace view
