#include "declgraphmodel.hpp"

#include "junctionitem.hpp"
#include "junctionarc.hpp"
#include "placeitem.hpp"
#include "transitionitem.hpp"
#include "preplacearc.hpp"
#include "postplacearc.hpp"
#include "functors.hpp"

#include "../base/statichelpers.hpp"
#include "../base/signalitem.hpp"
#include "../base/portitem.hpp"

#include "../../utils/functors.hpp"

#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

#include "../../memory_leak_start.hpp"

using namespace utils;

namespace model{
namespace spenat{

TransitionItem* createTransition(const QString& transName,
                                 const QString& transitionText,
                                 const QUuid& transUuid,
                                 DeclGraphModel* declGraphModel,
                                 QString* errorString)
{
  Q_ASSERT(declGraphModel);

  TransitionProperties transProperties;
  bool result = BuildTransProperties()(transitionText, &transProperties, declGraphModel, errorString);
  if(!result)
    return 0;

  TransitionItem* newTransItem = new TransitionItem(transName,
                                                    transProperties.trigger.take(),
                                                    transProperties.guard,
                                                    transProperties.actions,
                                                    transUuid);
  if(!declGraphModel->addTransition(newTransItem, errorString))
  {
    delete newTransItem;
    return 0;
  }

  return newTransItem;
}

class DeclGraphModel::Private
{
  friend class DeclGraphModel;

  Private()	:	_junctionsParentItem(0)
  {}

public:
  ~Private()
  {}

private:
  QStandardItem*	_junctionsParentItem;
  std::size_t     _transitionCounter;
};


DeclGraphModel::DeclGraphModel(QObject *parent)
  : BaseClass(parent),
    _d(new Private())
{}

DeclGraphModel::DeclGraphModel(const QString& name, QObject* parent)
  : BaseClass(name, parent),
    _d(new Private())
{}

DeclGraphModel::~DeclGraphModel()
{
  delete this->_d;
}

void DeclGraphModel::reset()
{
  BaseClass::reset();

  return;
}

void DeclGraphModel::resetGraphDecl()
{
  BaseClass::resetGraphDecl();

  return;
}

JsonObjectPtr DeclGraphModel::createJson() const
{
  return BaseClass::createJson();
}

void DeclGraphModel::removePlaceSlot(const QUuid& placeUuid)
{
  PlaceItem* placeItem=FindByUuid<PlaceSet>()(placeUuid, this->places());
  if(!placeItem)
    return;

  foreach(JunctionItem* juncItem, this->junctions())
  {
    juncItem->removeSource(placeItem);
    juncItem->removeTarget(placeItem);
  }

  foreach(TransitionItem* transItem, this->transitions())
  {
    transItem->removePrePlace(placeItem);
    transItem->removePostPlace(placeItem);
  }

  this->removePlace(placeItem);

  return;
}

void DeclGraphModel::addJunctionSlot(const QUuid &uuid)
{
  if(FindByUuid<JunctionSet>()(uuid, this->junctions()))
    return;

  this->addJunction(uuid);

  return;
}

void DeclGraphModel::removeJunctionSlot(QUuid junctionID)
{
  if(!this->_d->_junctionsParentItem)
    return;

  typedef FindByUuid<JunctionSet> FindFunc;

  JunctionItem* juncItem=FindFunc()(junctionID,
                                    this->junctions());
  if(!juncItem)
    return;

  this->_d->_junctionsParentItem->removeRow(juncItem->row());

  return;
}

bool DeclGraphModel::addArcSlot(const QString& name,
                           QUuid arcUuid,
                           QUuid sourceID,
                           QUuid targetID,
                           const QString &arcText,
                           QString* errorString)
{
  if(this->arc(arcUuid))
  {
    AddPtrString(errorString)<<"arc '"<<arcUuid.toString()<<"' is still available!";
    return false;
  }

  if (this->transition(arcUuid))
  {
    AddPtrString(errorString)<<"transisition '"<<arcUuid.toString()<<"' is still available!";
    return false;
  }

  NodeItem* sourceNode=this->node(sourceID);
  Q_ASSERT(sourceNode);
  NodeItem* targetNode=this->node(targetID);
  Q_ASSERT(targetNode);

  if(!isValidArc(sourceNode,targetNode,errorString))
    return false;

  ///source place
  if(PlaceItem* sourcePlace=dynamic_cast<PlaceItem*>(sourceNode))
  {
    if(PlaceItem* targetPlace=dynamic_cast<PlaceItem*>(targetNode))
    {///transition
      TransitionItem* newTransItem=createTransition(name,arcText,arcUuid,this,errorString);
      if(!newTransItem)
        return false;

      newTransItem->addPrePlaceArc(sourcePlace, arcUuid);
      newTransItem->addPostPlaceArc(targetPlace, arcUuid);
      newTransItem->setText(newTransItem->toString());
    }
    else if(TransitionItem* targetTrans=dynamic_cast<TransitionItem*>(targetNode))
    {///arc
      typedef TransitionItem::PrePlaceArcSet	PlaceArcSet;
      if(FindByPlace<PlaceArcSet>()(sourcePlace, targetTrans->prePlaceArcs()))
      {
        AddPtrString(errorString)<<"arc from place '"
                                <<sourcePlace->toString()
                               <<"' to transition '"
                              <<targetTrans->toString()
                             <<"' is still available!";
        return false;
      }

      PrePlaceArc* prePlaceArc=targetTrans->addPrePlaceArc(sourcePlace, arcUuid);
      Q_ASSERT(prePlaceArc);
      prePlaceArc->setText(prePlaceArc->toString());
      targetTrans->setText(targetTrans->toString());
    }
    else if(JunctionItem* targetJunct=dynamic_cast<JunctionItem*>(targetNode))
    {///junction trigger
      JunctionArc* juncSource=targetJunct->addSource(sourcePlace);
      juncSource->setTrigger(arcText);
      juncSource->setUuid(arcUuid);
      targetJunct->updateText();
    }
  }
  ///source transition
  else if(TransitionItem* sourceTrans=dynamic_cast<TransitionItem*>(sourceNode))
  {
    if(PlaceItem* targetPlace=dynamic_cast<PlaceItem*>(targetNode))
    {///arc
      typedef TransitionItem::PostPlaceArcSet	PlaceArcSet;
      if(FindByPlace<PlaceArcSet>()(targetPlace, sourceTrans->postPlaceArcs()))
      {
        AddPtrString(errorString)<<"arc from transition '"
                                <<sourceTrans->toString()
                               <<"' to place '"
                              <<targetPlace->toString()
                             <<"' is still available!";
        return false;
      }

      PostPlaceArc* postPlaceArc=sourceTrans->addPostPlaceArc(targetPlace, arcUuid);
      Q_ASSERT(postPlaceArc);
      sourceTrans->setText(sourceTrans->toString());
    }
    else
      Q_ASSERT(false);
  }
  ///source junction
  else if(JunctionItem* sourceJunc=dynamic_cast<JunctionItem*>(sourceNode))
  {
    if(PlaceItem* targetPlace=dynamic_cast<PlaceItem*>(targetNode))
    {///junction target

      JunctionArc* juncTarget=sourceJunc->addTarget(targetPlace);
      Q_ASSERT(juncTarget);
      juncTarget->setUuid(arcUuid);

      ////parse arc notation////////////////////
      QString errorString;
      TransitionProperties transProperties;
      bool result = BuildTransProperties()(arcText, &transProperties,
                                           this, &errorString);
      if(!result || transProperties.trigger)
      {//trigger is not allowed!

        emit error(QString(QLatin1String("arc notation '%1' from junction to place '%2' "
                                         "is not well formed! Error: '%3'!"))
                   .arg(arcText).arg(targetPlace->name()).arg(errorString));
      }

      juncTarget->setGuard(transProperties.guard);
      juncTarget->setActions(transProperties.actions);

      sourceJunc->updateText();
    }
    else if(JunctionItem* targetJunct=dynamic_cast<JunctionItem*>(targetNode))
    {///junction trigger
      JunctionArc* juncSource=targetJunct->addSource(sourceJunc);
      juncSource->setTrigger(arcText);
      juncSource->setUuid(arcUuid);
      targetJunct->updateText();
    }
    else
      Q_ASSERT(false);
  }

  return true;
}

void DeclGraphModel::changeArcSlot(QUuid arcUuid,
                              QUuid sourceID,
                              QUuid targetID,
                              const QString &arcText)
{
  Q_UNUSED(sourceID);
  Q_UNUSED(targetID);

  if(TransitionItem* transItem=this->transition(arcUuid))
  {
    ////parse arc notation////////////////////
    TransitionProperties transProperties;
    QString errorString;
    bool result = BuildTransProperties()(arcText, &transProperties, this, &errorString);
    if(!result)
    {
      transItem->resetTransProps();
      emit error(errorString);
      return;
    }

    transItem->setTriggerItem(transProperties.trigger.take());
    transItem->setGuard(transProperties.guard);
    transItem->setActions(transProperties.actions);
  }
  else
  {
    foreach(JunctionItem* junction, this->junctions())
    {
      foreach(JunctionArc const* junctionSource, junction->sources())
      {
        if(junctionSource->uuid()==arcUuid)
        {
          const_cast<JunctionArc*>(junctionSource)->setTrigger(arcText);
          return;
        }
      }
      foreach(JunctionArc* juncTargetArc, junction->targets())
      {
        if(juncTargetArc->uuid()==arcUuid)
        {
          ////parse arc notation////////////////////
          QString errorString;
          TransitionProperties transProperties;
          bool result = BuildTransProperties()(arcText, &transProperties,
                                               this, &errorString);
          if(!result || transProperties.trigger)
          {//trigger is not allowed!

            emit error(QString(QLatin1String("arc notation '%1' from node '%2' to node '%3' "
                                             "is not well formed! Error: '%4'!"))
                       .arg(arcText)
                       .arg(juncTargetArc->source()->toString())
                       .arg(juncTargetArc->target()->toString())
                       .arg(errorString));
          }

          juncTargetArc->setGuard(transProperties.guard);
          juncTargetArc->setActions(transProperties.actions);

          junction->updateText();

          return;
        }
      }
    }
  }

  return;
}

void DeclGraphModel::removeArcSlot(QUuid arcID,
                              QUuid sourceID,
                              QUuid targetID)
{
  if(TransitionItem* transItem=this->transition(arcID))
  {
    this->removeTransitionSlot(transItem->uuid());
    return;
  }

  foreach(JunctionItem* junction, this->junctions())
  {
    foreach(JunctionArc const* junctionSourceArc,
            junction->sources())
    {
      if(junctionSourceArc->uuid()==arcID)
      {
        junction->removeSource(junctionSourceArc->source());
        return;
      }
    }
    foreach(JunctionArc const* junctionTargetArc,
            junction->targets())
    {
      if(junctionTargetArc->uuid()==arcID)
      {
        junction->removeTarget(junctionTargetArc->target());
        return;
      }
    }
  }

  NodeItem const* sourceNode=this->node(sourceID);
  if(!sourceNode)
    return;
  NodeItem const* targetNode=this->node(targetID);
  if(!targetNode)
    return;

  if(PlaceItem const* sourcePlace=dynamic_cast<PlaceItem const*>(sourceNode))
  {
    if(TransitionItem const* targetTransition=dynamic_cast<TransitionItem const*>(targetNode))
    {
      const_cast<TransitionItem*>(targetTransition)->removePrePlace(sourcePlace);
      return;
    }
  }
  else if(TransitionItem const* sourceTransition=dynamic_cast<TransitionItem const*>(sourceNode))
  {
    if(PlaceItem const* targetPlace=dynamic_cast<PlaceItem const*>(targetNode))
    {
      const_cast<TransitionItem*>(sourceTransition)->removePostPlace(targetPlace);
      return;
    }
  }

  return;
}

void DeclGraphModel::addPlaceSlot(QUuid placeID,
                             const QString& placeText)
{
  if(FindByUuid<PlaceSet>()(placeID, this->places()))
    return;

  try
  {
    PlaceItem* newPlace=this->addPlace(placeText);
    newPlace->setUuid(placeID);
  }
  catch(const std::exception& exc)
  {
    emit error(QLatin1String(exc.what()));
  }

  return;
}

void DeclGraphModel::addTransitionSlot(const QString& name,
                                  QUuid transitionID,
                                  const QString &transitionText)
{
  Q_ASSERT(!this->transition(transitionID));
  Q_ASSERT(!this->transition(name));

  TransitionItem* newTransItem=0;
  TransitionProperties transProperties;
  QString errorString;
  bool result = BuildTransProperties()(transitionText,&transProperties,this,&errorString);
  if(!result)
  {
    newTransItem=this->addSignalTransition(name, 0, 0,
                                           QLatin1String(""),
                                           QLatin1String(""),
                                           transitionID);
    Q_ASSERT(newTransItem);
    emit error(errorString);

    return;
  }

  newTransItem = new TransitionItem(name,
                                    transProperties.trigger.take(),
                                    transProperties.guard,
                                    transProperties.actions);
  result = this->addTransition(newTransItem, &errorString);
  if(!result)
  {
    delete newTransItem;
    newTransItem=this->addSignalTransition(name, 0, 0,
                                           QLatin1String(""),
                                           QLatin1String(""),
                                           transitionID);
    Q_ASSERT(newTransItem);
    emit error(errorString);

    return;
  }

  return;
}

void DeclGraphModel::changePlaceSlot(QUuid placeID,
                                const QString &placeText,
                                bool initMarking)
{
  PlaceItem* placeItem=FindByUuid<PlaceSet>()(placeID, this->places());
  if(!placeItem)
    return;

  placeItem->setName(placeText);

  if(initMarking)
    this->addInitPlace(placeItem);
  else
    this->removeInitPlace(placeItem);

  return;
}

void DeclGraphModel::changeTransitionSlot(QUuid transitionID,
                                     const QString &transitionText)
{
  typedef FindByUuid<TransitionSet> FindFunc;

  TransitionItem* transItem=FindFunc()(transitionID,
                                       this->transitions());
  if(!transItem)
    return;

  TransitionProperties transProperties;
  QString errorString;
  bool result = BuildTransProperties()(transitionText,&transProperties,this,&errorString);
  if(!result)
  {
    transItem->resetTransProps();
    emit error(errorString);

    return;
  }

  transItem->setTriggerItem(transProperties.trigger.take());
  transItem->setGuard(transProperties.guard);
  transItem->setActions(transProperties.actions);

  return;
}

void DeclGraphModel::removeTransitionSlot(QUuid transitionID)
{
  typedef FindByUuid<TransitionSet> FindFunc;

  TransitionItem* transItem=FindFunc()(transitionID,
                                       this->transitions());
  if(!transItem)
    return;

  this->removeTransition(transItem);

  return;
}

}///end namespace model
}///end namespace spenat
