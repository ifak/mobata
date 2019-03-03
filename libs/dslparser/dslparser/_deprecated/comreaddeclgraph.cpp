#include "comreaddeclgraph.hpp"

#include "declscene.hpp"
#include "declplace.hpp"
#include "decltransition.hpp"
#include "decljunction.hpp"
#include "declarc.hpp"

#include "../../model/spenat/declmodel.hpp"
#include "../../model/spenat/placeitem.hpp"
#include "../../model/spenat/transitionitem.hpp"
#include "../../model/spenat/junctionitem.hpp"

#include "../base/textitem.hpp"

#include <QUuid>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include "../../memory_leak_start.hpp"

namespace view {

namespace spenat
{

class ComReadDeclGraph::Private
{
  friend class ComReadDeclGraph;

  Private(const QByteArray &graphJsonData,
          model::spenat::DeclModel *declModel,
          DeclScene *graphScene)
    :	_graphJsonData(graphJsonData),
      _declModel(declModel),
      _graphScene(graphScene)
  {}

public:
  ~Private()
  {}

private:
  const QByteArray&         _graphJsonData;
  model::spenat::DeclModel* _declModel;
  DeclScene*                _graphScene;
};

ComReadDeclGraph::ComReadDeclGraph(const QByteArray &graphJsonData,
                                   model::spenat::DeclModel *declModel,
                                   DeclScene *graphScene)
  :	_d(new Private(graphJsonData, declModel, graphScene))
{}

ComReadDeclGraph::~ComReadDeclGraph()
{}

template<class OptionType>
void readNode(const QJsonObject& nodeObject,
              QUuid* id, QPointF* pos, QString* name,
              QString* label, QPointF* labelPos,
              QString* comment, OptionType* options)
{
  Q_ASSERT(id&&pos&&name&&label&&labelPos&&comment&&options);

  QJsonObject::ConstIterator nodeIterator = nodeObject.begin();
  for( ; nodeIterator!=nodeObject.end(); ++nodeIterator)
  {
    if(nodeIterator.key()=="uuid")
      *id=QUuid(nodeIterator.value().toString());
    else if(nodeIterator.key()=="declaration")
    {
      QJsonObject declObject=nodeIterator.value().toObject();
      QJsonObject::ConstIterator nodeLabelIterator=declObject.begin();
      for( ; nodeLabelIterator!=declObject.end(); ++nodeLabelIterator)
      {
        if(nodeLabelIterator.key()=="text")
          *label=nodeLabelIterator.value().toString();
        else if(nodeLabelIterator.key()=="pos")
        {
          QJsonObject posObject=nodeLabelIterator.value().toObject();
          QJsonObject::ConstIterator labelPosIterator=posObject.begin();
          for( ; labelPosIterator!=posObject.end(); ++labelPosIterator)
          {
            if(labelPosIterator.key()=="x")
              labelPos->setX(labelPosIterator.value().toDouble());
            else if(labelPosIterator.key()=="y")
              labelPos->setY(labelPosIterator.value().toDouble());
          }
        }
      }
    }
    else if(nodeIterator.key()=="name")
      *name=nodeIterator.value().toString();
    else if(nodeIterator.key()=="comment")
      *comment=nodeIterator.value().toString();
    else if(nodeIterator.key()=="color")
      options->setColor(nodeIterator.value().toString());
    else if(nodeIterator.key()=="pos")
    {
      QJsonObject posObject=nodeIterator.value().toObject();
      QJsonObject::ConstIterator posObjIterator=posObject.begin();
      for( ; posObjIterator!=posObject.end(); ++posObjIterator)
      {
        if(posObjIterator.key()=="x")
          pos->setX(posObjIterator.value().toDouble());
        else if(posObjIterator.key()=="y")
          pos->setY(posObjIterator.value().toDouble());
      }
    }
    else if(nodeIterator.key()=="size")
    {
      double width=1.0, height=1.0;
      QJsonObject sizeObject=nodeIterator.value().toObject();
      QJsonObject::ConstIterator sizeObjIterator=sizeObject.begin();
      for( ; sizeObjIterator!=sizeObject.end(); ++sizeObjIterator)
      {
        if(sizeObjIterator.key()=="width")
          width=sizeObjIterator.value().toDouble();
        else if(sizeObjIterator.key()=="height")
          height=sizeObjIterator.value().toDouble();
      }
      options->setSize(QSizeF(width,height));
    }
  }

  return;
}

void readPlaces(const QJsonArray& placesArray,
                model::spenat::DeclModel*	declModel,
                DeclScene* graphScene)
{
  Q_ASSERT(declModel&&graphScene);

  for(int i=0; i<placesArray.size(); ++i)
  {
    QJsonObject placeObject=placesArray.at(i).toObject();

    QUuid placeID; QString placeName;
    QString placeLabel, placeComment;
    QPointF placePos, labelPos;
    PlaceOptions placeOptions;
    readNode(placeObject,
             &placeID, &placePos, &placeName,
             &placeLabel, &labelPos,
             &placeComment, &placeOptions);

    model::spenat::PlaceItem* newPlaceItem=declModel->addPlace(placeName);
    Q_ASSERT(newPlaceItem);
    newPlaceItem->setUuid(placeID);
    newPlaceItem->setWhatsThis(placeComment);

    DeclPlace* newScenePlace=graphScene->addPlace(placePos,
                                                  placeLabel,
                                                  placeOptions,
                                                  placeID);
    newScenePlace->notationItem()->setPos(labelPos);

    ///init marking////
    QJsonObject::const_iterator find_it=placeObject.find("initMarking");
    if(find_it!=placeObject.end())
    {
      bool initMarking=find_it.value().toBool();

      if(initMarking)
        declModel->addInitPlace(newPlaceItem);

      newScenePlace->setInitMarking(initMarking);
      newScenePlace->setMarking(newScenePlace->getInitMarking());
    }
  }

  return;
}

void readTransitions(const QJsonArray& transArray,
                     model::spenat::DeclModel*	declModel,
                     DeclScene* graphScene)
{
  Q_ASSERT(declModel&&graphScene);

  foreach(const QJsonValue& transValue,
          transArray)
  {
    QUuid transID; QString transName;
    QString transDecl, transComment;
    QPointF transPos, transDeclPos;
    TransitionOptions transOptions;
    readNode(transValue.toObject(),
             &transID, &transPos, &transName,
             &transDecl, &transDeclPos,
             &transComment, &transOptions);

    declModel->addTransitionSlot(transName, transID, transDecl);
    model::spenat::TransitionItem* transModelItem=declModel->transition(transID);
    Q_ASSERT(transModelItem);
    transModelItem->setWhatsThis(transComment);

    DeclTransition* newDeclTransition=graphScene->addTransition(transPos,
                                                                transDecl,
                                                                transDeclPos,
                                                                transOptions,
                                                                transID);
    newDeclTransition->setNotation(transDecl);
  }

  return;
}

template<class OptionType>
void readArc(const QJsonObject& arcObject, QUuid* arcID,
             QUuid* sourceID, QUuid* targetID, QString* arcName,
             QString* label,QPointF* labelPos,QString* comment,
             QList<QPointF>* controlPoints, OptionType* /*options*/)
{
  Q_ASSERT(arcID&&sourceID&&targetID
           &&arcName&&label&&labelPos
           &&comment&&controlPoints/*&&options*/);

  QJsonObject::ConstIterator arcOjbIterator=arcObject.begin();
  for( ; arcOjbIterator!=arcObject.end(); ++arcOjbIterator)
  {
    if(arcOjbIterator.key()=="uuid")
      *arcID=QUuid(arcOjbIterator.value().toString());
    else if(arcOjbIterator.key()=="source_id")
      *sourceID=QUuid(arcOjbIterator.value().toString());
    else if(arcOjbIterator.key()=="target_id")
      *targetID=QUuid(arcOjbIterator.value().toString());
    else if(arcOjbIterator.key()=="name")
      *arcName=arcOjbIterator.value().toString();
    else if(arcOjbIterator.key()=="declaration")
    {
      QJsonObject arcLabelObject=arcOjbIterator.value().toObject();
      QJsonObject::ConstIterator arcLabelIterator=arcLabelObject.begin();
      for( ; arcLabelIterator!=arcLabelObject.end(); ++arcLabelIterator)
      {
        if(arcLabelIterator.key()=="text")
          *label=arcLabelIterator.value().toString();
        else if(arcLabelIterator.key()=="pos")
        {
          QJsonObject labelPosObject=arcLabelIterator.value().toObject();
          QJsonObject::ConstIterator labelPosIterator=labelPosObject.begin();
          for( ; labelPosIterator!=labelPosObject.end(); ++labelPosIterator)
          {
            if(labelPosIterator.key()=="x")
              labelPos->setX(labelPosIterator.value().toDouble());
            else if(labelPosIterator.key()=="y")
              labelPos->setY(labelPosIterator.value().toDouble());
          }
        }

      }
    }
    else if(arcOjbIterator.key()=="comment")
      *comment=arcOjbIterator.value().toString();
    else if(arcOjbIterator.key()=="points")
    {
      foreach(const QJsonValue& pointValue,
              arcOjbIterator.value().toArray())
      {
        QPointF point;
        QJsonObject pointObject=pointValue.toObject();
        QJsonObject::ConstIterator pointOjbIterator=pointObject.begin();
        for( ; pointOjbIterator!=pointObject.end(); ++pointOjbIterator)
        {
          if(pointOjbIterator.key()=="x")
            point.setX(pointOjbIterator.value().toDouble());
          else if(pointOjbIterator.key()=="y")
            point.setY(pointOjbIterator.value().toDouble());
        }
        controlPoints->push_back(point);
      }
    }
  }

  return;
}

void readJunctions(const QJsonArray& junctionsArray,
                   model::spenat::DeclModel*	declModel,
                   DeclScene* graphScene)
{
  Q_ASSERT(declModel&&graphScene);

  foreach(const QJsonValue& junctionValue,
          junctionsArray)
  {
    QUuid junctionID; QString junctionName;
    QString junctionLabel, junctionComment;
    QPointF junctionPos, junctionLabelPos;
    graph::NodeOptions junctionOptions;
    readNode(junctionValue.toObject(),
             &junctionID, &junctionPos, &junctionName,
             &junctionLabel, &junctionLabelPos,
             &junctionComment, &junctionOptions);

    model::spenat::JunctionItem* newModelJunc=declModel->addJunction(junctionID);
    newModelJunc->setWhatsThis(junctionComment);

    DeclJunction* newJunction=graphScene->addJunction(junctionPos, junctionID);
    newJunction->setNotation(junctionLabel);
    newJunction->notationItem()->setPos(junctionLabelPos);
  }

  return;
}

QPainterPath buildPainterPath(graph::AbstractNode* sourceNode,
                              graph::AbstractNode* targetNode,
                              QList<QPointF>& controlPoints)
{
  QPainterPath path;

  path.moveTo(sourceNode->pos());
  foreach(QPointF controlPoint, controlPoints)
    path.lineTo(controlPoint);
  path.lineTo(targetNode->pos());

  return path;
}

bool readArcs(const QJsonArray& arcsArray,
              model::spenat::DeclModel*	declModel,
              DeclScene* graphScene,
              QString* errorString)
{
  Q_ASSERT(declModel&&graphScene);

  foreach(const QJsonValue& arcValue, arcsArray)
  {
    QUuid arcID, sourceID, targetID;
    QString arcName, arcDecl, arcComment;
    QPointF arcDeclPos;
    QList<QPointF> controlPoints;
    ArcOptions arcOptions;
    readArc(arcValue.toObject(),
            &arcID,&sourceID,&targetID,
            &arcName, &arcDecl, &arcDeclPos,
            &arcComment,&controlPoints,&arcOptions);

    bool result = declModel->addArcSlot(arcName, arcID,sourceID,targetID,arcDecl,errorString);
    if(!result)
      return false;

    if(model::spenat::TransitionItem* transItem=declModel->transition(arcID))
      transItem->setWhatsThis(arcComment);

    graph::AbstractNode* sourceNode=graphScene->node(sourceID);
    if(!sourceNode)
    {
      if(errorString)
        *errorString+="source graph node with id :'"
                      +sourceID.toString()
                      +"' not found!";
      return false;
    }

    graph::AbstractNode* targetNode=graphScene->node(targetID);
    if(!targetNode)
    {
      if(errorString)
        *errorString+="target graph node with id :'"
                      +targetID.toString()
                      +"' not found!";
      return false;
    }

    QPainterPath arcPath=buildPainterPath(sourceNode, targetNode, controlPoints);
    graphScene->addArc(sourceNode,
                       targetNode,
                       arcPath,
                       arcDecl,
                       arcDeclPos,
                       arcOptions,
                       arcID);
  }

  return true;
}

bool ComReadDeclGraph::execute(QString* errorString)
{
  Q_ASSERT(this->_d->_declModel);
  Q_ASSERT(this->_d->_graphScene);

  QJsonParseError parseError;
  QJsonDocument declGraphDocument=QJsonDocument::fromJson(this->_d->_graphJsonData,
                                                          &parseError);
  if(declGraphDocument.isEmpty())
  {
    if(errorString)
      *errorString+=parseError.errorString();
    return  false;
  }

  if(!declGraphDocument.isObject())
  {
    if(errorString)
      *errorString+=parseError.errorString();
    return  false;
  }

  QJsonObject rootObject=declGraphDocument.object();

  QJsonObject::ConstIterator find_it;

  ///read name////
  find_it=rootObject.find("name");
  if(find_it!=rootObject.end())
  {
    QString modelName=find_it.value().toString();
    this->_d->_declModel->setName(modelName);
    this->_d->_graphScene->setName(modelName);
  }

  ///read places/////////
  find_it=rootObject.find("places");
  if(find_it!=rootObject.end())
    readPlaces(find_it.value().toArray(),
               this->_d->_declModel,
               this->_d->_graphScene);

  ///read transitions/////////
  find_it=rootObject.find("transitions");
  if(find_it!=rootObject.end())
    readTransitions(find_it.value().toArray(),
                    this->_d->_declModel,
                    this->_d->_graphScene);

  ///read junctions/////////
  find_it=rootObject.find("junctions");
  if(find_it!=rootObject.end())
    readJunctions(find_it.value().toArray(),
                  this->_d->_declModel,
                  this->_d->_graphScene);

  ///read arcs/////////
  find_it=rootObject.find("arcs");
  if(find_it!=rootObject.end())
  {
    bool result=readArcs(find_it.value().toArray(),
                         this->_d->_declModel,
                         this->_d->_graphScene,
                         errorString);
    if(!result)
      return  false;
  }

  return true;
}

}//end namespace spenat

}//end namespace view
