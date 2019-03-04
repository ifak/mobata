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

#include "comcreatespenatmodel.hpp"

#include "spenatdeclmodel.hpp"
#include "spenatmodel.hpp"
#include "spenat2declmapping.hpp"
#include "placeitem.hpp"
#include "transitionitem.hpp"
#include "preplacearc.hpp"
#include "postplacearc.hpp"
#include "junctionitem.hpp"
#include "junctionarc.hpp"

#include "../base/datatypeitem.hpp"
#include "../base/signalitem.hpp"
#include "../base/portitem.hpp"
#include "../base/attributeitem.hpp"
#include "../base/paramitem.hpp"
#include "../base/signaltriggeritem.hpp"
#include "../base/timeouttriggeritem.hpp"

#include "../graph/arcitem.hpp"

#include <QSet>
#include <QDebug>

#include <stdexcept>

namespace model{

using namespace base;

namespace spenat{

typedef ComCreateSpenatModel::SpenatModelPtr        SpenatModelPtr;
typedef ComCreateSpenatModel::Spenat2DeclMappingPtr Spenat2DeclMappingPtr;

ComCreateSpenatModel::ComCreateSpenatModel(const SpenatDeclModel* declModel)
  : _declModel(declModel)
{}

bool ComCreateSpenatModel::execute(QString* errorString)
{
  Q_ASSERT(this->_declModel);

  this->_spenatModel=SpenatModelPtr(new SpenatModel(this->_declModel->name()));
  this->_spenat2DeclMapping=Spenat2DeclMappingPtr(new Spenat2DeclMapping(this->_spenatModel.data(),
                                                                         this->_declModel));

  for(base::DataTypeItem const* declTypeItem: this->_declModel->dataTypes())
  {
    base::DataTypeItem* spenatTypeItem=this->_spenatModel->addDataType(declTypeItem->name(),
                                                                       declTypeItem->uuid(),
                                                                       errorString);
    if(!spenatTypeItem)
      return false;
    spenatTypeItem->setTypeEnum(declTypeItem->typeEnum());
    spenatTypeItem->setLowest(declTypeItem->lowest());
    spenatTypeItem->setHighest(declTypeItem->highest());
    for(const QString& literal: declTypeItem->literals())
      spenatTypeItem->addLiteral(literal);
    spenatTypeItem->setText(spenatTypeItem->typeDeclString());
    //    spenatTypeItem->setText(spenatTypeItem->name());

    this->_spenat2DeclMapping->addTypeMapping(spenatTypeItem, declTypeItem);
  }

  for(SignalItem const* declSignalItem: this->_declModel->getSignals())
  {
    SignalItem* spenatSignalItem=this->_spenatModel->addSignal(declSignalItem->name(),
                                                               errorString);
    if(!spenatSignalItem)
      return false;

    spenatSignalItem->setUuid(declSignalItem->uuid());
    for(ParamItem const* declParam: declSignalItem->params())
    {
      ParamItem* paramItem=spenatSignalItem->addParameter(declParam->name(),
                                                          declParam->dataType(),
                                                          errorString);
      Q_ASSERT(paramItem);
    }

    this->_spenat2DeclMapping->addSignalMapping(spenatSignalItem, declSignalItem);
  }

  for(PortItem const* declPortItem : this->_declModel->ports())
  {
    PortItem* spenatPortItem=this->_spenatModel->addPort(declPortItem->name(),
                                                         errorString);
    if(!spenatPortItem)
      return false;
    spenatPortItem->setUuid(declPortItem->uuid());
    this->_spenat2DeclMapping->addPortMapping(spenatPortItem, declPortItem);
  }

  for(AttributeItem const* declAttrItem : this->_declModel->attributes())
  {
    AttributeItem* spenatAttrItem=this->_spenatModel->addAttribute(declAttrItem->name(),
                                                                   declAttrItem->dataType(),
                                                                   declAttrItem->initValue(),
                                                                   errorString);
    if(!spenatAttrItem)
      return false;

    spenatAttrItem->setUuid(declAttrItem->uuid());
    this->_spenat2DeclMapping->addAttributeMapping(spenatAttrItem, declAttrItem);
  }

  for(PlaceItem const* declPlaceItem : this->_declModel->places())
  {
    PlaceItem* spenatPlaceItem=this->_spenatModel->addPlace(declPlaceItem->name());
    spenatPlaceItem->setUuid(declPlaceItem->uuid());
    if(this->_declModel->isInitPlace(declPlaceItem))
      this->_spenatModel->addInitPlace(spenatPlaceItem);
    this->_spenat2DeclMapping->addPlaceMapping(spenatPlaceItem, declPlaceItem);
  }

  for(TransitionItem const* declTransItem : this->_declModel->transitions())
  {
    TransitionItem* spenatTrans = 0;
    if(declTransItem->triggerItem())
    {
      if(declTransItem->triggerItem()->triggerType() == ATriggerItem::EventTrigger)
      {
        SignalTriggerItem const* signalTrigger = static_cast<SignalTriggerItem const*>(declTransItem->triggerItem());
        Q_ASSERT(signalTrigger);
        spenatTrans = this->_spenatModel->addSignalTransition(declTransItem->name(),
                                                              signalTrigger->triggerSignal(),
                                                              signalTrigger->port(),
                                                              declTransItem->guard(),
                                                              declTransItem->actions(),
                                                              declTransItem->uuid());
      }
      else if(declTransItem->triggerItem()->triggerType() == ATriggerItem::TimeoutTrigger)
      {
        TimeoutTriggerItem const* timeoutTrigger = static_cast<TimeoutTriggerItem const*>(declTransItem->triggerItem());
        Q_ASSERT(timeoutTrigger);
        spenatTrans = this->_spenatModel->addTimeoutTransition(declTransItem->name(),
                                                               timeoutTrigger->value(),
                                                               declTransItem->guard(),
                                                               declTransItem->actions(),
                                                               declTransItem->uuid());
      }
      else
        Q_ASSERT(false);
    }
    else
    {
      spenatTrans = this->_spenatModel->addSignalTransition(declTransItem->name(),
                                                            nullptr, nullptr,
                                                            declTransItem->guard(),
                                                            declTransItem->actions(),
                                                            declTransItem->uuid());
    }

    Q_ASSERT(spenatTrans);

    for(PrePlaceArc const* declPrePlaceArc : declTransItem->prePlaceArcs())
    {
      PlaceItem* preSpenatPlace=this->_spenatModel->place(declPrePlaceArc->place()->uuid());
      Q_ASSERT(preSpenatPlace);
      PrePlaceArc* preSpenatPlaceArc=spenatTrans->addPrePlaceArc(preSpenatPlace,
                                                                 declPrePlaceArc->uuid());
      Q_ASSERT(preSpenatPlaceArc);
    }

    for(PostPlaceArc const* declPostPlaceArc : declTransItem->postPlaceArcs())
    {
      PlaceItem* postSpenatPlace=this->_spenatModel->place(declPostPlaceArc->place()->uuid());
      Q_ASSERT(postSpenatPlace);
      PostPlaceArc* postSpenatPlaceArc=spenatTrans->addPostPlaceArc(postSpenatPlace,
                                                                    declPostPlaceArc->uuid());
      Q_ASSERT(postSpenatPlaceArc);
    }

    this->_spenat2DeclMapping->addTransitionMapping(spenatTrans, declTransItem);
  }

  for(JunctionItem const* declJunctionItem : this->_declModel->junctions())
  {
    bool result = this->processJunction(declJunctionItem, errorString);
    if(!result)
      return false;
  }

  //  for(PlaceItem const* initPlaceItem: this->_declModel->initPlaces())
  //    this->_spenatModel->addInitPlace(initPlaceItem);

  return true;
}

bool ComCreateSpenatModel::processJunction(JunctionItem const* /*declJunctionItem*/,
                                           QString* errorString)
{
  utils::AddPtrString(errorString)<<"junctions are currently not processable "
                                    "for transformation to spenat model!";
  return false;

  //  for(JunctionArc const* junctionSourceArc:
  //          declJunctionItem->sources())
  //  {
  //    PlaceItem const* preDeclPlace=junctionSourceArc->place();
  //    Q_ASSERT(preDeclPlace);

  //    PlaceItem* preSpenatPlace=this->_spenatModel->place(preDeclPlace->uuid());
  //    Q_ASSERT(preSpenatPlace);

  //    ///possible else-transition///////////////
  //    TransitionItem* elseSpenatTransItem=0;
  //    JunctionArc const* elseDeclJuncTarget=0;
  //    QVector<QString> guardStrings;

  //    for(JunctionArc const* juncTarget: declJunctionItem->targets())
  //    {
  //      QString guardString=juncTarget->getGuard().trimmed();
  //      qDebug()<<"junction target guard:"<<guardString;
  //      if(guardString==QLatin1String("else"))
  //      {
  //        if(elseSpenatTransItem)
  //        {
  //          utils::AddPtrString(errorString)<<QString(QStringLiteral("Junction '%1'  has more "
  //                                                                   "than one 'else'-branch!"))
  //                                            .arg(declJunctionItem->toString());
  //          return false;
  //        }

  //        TransitionProperties transProperties;
  //        bool result = BuildTransProperties()(junctionSourceArc->trigger(),&transProperties,
  //                                             this->_spenatModel.data(), errorString);
  //        if(!result)
  //          return false;

  //        elseSpenatTransItem=new TransitionItem(QString("t_%1").arg(QUuid::createUuid().toString()),
  //                                               transProperties.trigger.take(),
  //                                               QStringLiteral("")/*empty guard*/,
  //                                               juncTarget->getActions(),
  //                                               juncTarget->uuid());

  //        result = this->_spenatModel->addTransition(elseSpenatTransItem, errorString);
  //        if(!result)
  //        {
  //          delete elseSpenatTransItem;
  //          return false;
  //        }

  //        elseSpenatTransItem->addPrePlaceArc(preSpenatPlace, junctionSourceArc->uuid());

  //        PlaceItem const* postDeclPlace=juncTarget->place();
  //        Q_ASSERT(postDeclPlace);
  //        PlaceItem* postSpenatPlace=this->_spenatModel->place(postDeclPlace->uuid());
  //        Q_ASSERT(postSpenatPlace);
  //        elseSpenatTransItem->addPostPlaceArc(postSpenatPlace, juncTarget->uuid());

  //        elseDeclJuncTarget=juncTarget;
  //      }
  //      else
  //      {
  //        guardStrings.push_back(juncTarget->getGuard());

  //        TransitionProperties transProperties;
  //        bool result = BuildTransProperties()(junctionSourceArc->trigger(),&transProperties,
  //                                             this->_spenatModel.data(), errorString);
  //        if(!result)
  //          return false;

  //        TransitionItem* newSpenatTrans=new TransitionItem(QString("t_%1").arg(QUuid::createUuid().toString()),
  //                                                          transProperties.trigger.take(),
  //                                                          juncTarget->getGuard(),
  //                                                          juncTarget->getActions(),
  //                                                          juncTarget->uuid());

  //        result = this->_spenatModel->addTransition(newSpenatTrans, errorString);
  //        if(!result)
  //        {
  //          delete newSpenatTrans;
  //          return false;
  //        }

  //        newSpenatTrans->addPrePlaceArc(preSpenatPlace, junctionSourceArc->uuid());

  //        PlaceItem const* postDeclPlace=juncTarget->place();
  //        Q_ASSERT(postDeclPlace);
  //        PlaceItem* postSpenatPlace=this->_spenatModel->place(postDeclPlace->uuid());
  //        Q_ASSERT(postSpenatPlace);
  //        newSpenatTrans->addPostPlaceArc(postSpenatPlace,juncTarget->uuid());

  //        this->_spenat2DeclMapping->addTransitionMapping(newSpenatTrans, declJunctionItem);
  //        this->_spenat2DeclMapping->addTransitionMapping(newSpenatTrans, juncTarget);
  //      }
  //    }

  //    if(!elseSpenatTransItem)
  //      return true;

  //    ///build else-guard (not (guard1 or guard2 or ...))
  //    QString elseGuardString;
  //    if(guardStrings.size()==0)
  //      elseGuardString=QLatin1String("");
  //    else if(guardStrings.size()==1)
  //      elseGuardString=QLatin1String("not(")
  //                      +guardStrings.at(0)
  //                      +QLatin1String(")");
  //    else
  //    {
  //      QString orGuards;
  //      std::size_t pos=0;
  //      for(const QString& guard: guardStrings)
  //      {
  //        if(pos==0)
  //          orGuards=QLatin1String("(")
  //                   +guard
  //                   +QLatin1String(")");
  //        else
  //          orGuards+=QLatin1String("or(")
  //                    +guard
  //                    +QLatin1String(")");
  //        ++pos;
  //      }
  //      elseGuardString=QLatin1String("not(")
  //                      +orGuards
  //                      +QLatin1String(")");
  //    }
  //    qDebug()<<"transformed else-guard:"<<elseGuardString;
  //    elseSpenatTransItem->setGuard(elseGuardString);
  //    elseSpenatTransItem->setText(elseSpenatTransItem->toString());

  //    this->_spenat2DeclMapping->addTransitionMapping(elseSpenatTransItem, declJunctionItem);
  //    this->_spenat2DeclMapping->addTransitionMapping(elseSpenatTransItem, elseDeclJuncTarget);
  //  }

  //  return true;
}

const SpenatModelPtr& ComCreateSpenatModel::spenatModel() const
{
  return this->_spenatModel;
}

const Spenat2DeclMappingPtr& ComCreateSpenatModel::spenat2DeclMapping() const
{
  return this->_spenat2DeclMapping;
}

}///end namespace model
}///end namespace spenat
