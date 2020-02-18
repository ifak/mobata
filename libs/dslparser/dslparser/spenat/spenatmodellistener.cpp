#include "spenatmodellistener.hpp"

#include <mobata/model/base/portitem.hpp>
#include <mobata/model/base/signalitem.hpp>
#include <mobata/model/base/signaltriggeritem.hpp>
#include <mobata/model/base/timeouttriggeritem.hpp>

#include <mobata/model/spenat/spenatdeclmodel.hpp>
#include <mobata/model/spenat/placeitem.hpp>
#include <mobata/model/spenat/transitionitem.hpp>

#include <QStack>
#include <QDebug>

using namespace model::base;
using namespace model::spenat;
using namespace antlr4;

namespace dslparser {
namespace spenat {

using common::addKeywordLocation;

class SpenatModelListener::Private
{
  friend class SpenatModelListener;

  ///parse data////
  QScopedPointer<PlaceItem>      _currentPlace;
  QScopedPointer<TransitionItem> _currentTransition;
  bool                           _currentPlaceIsInit;

  Private()
    : _currentPlace(nullptr),
      _currentTransition(nullptr)
  {}
};

SpenatModelListener::SpenatModelListener(SpenatDeclModel* spenatDeclModel,
                                         DslErrorList* spenatErrors,
                                         TokenTextLocations* keywordTextLocations,
                                         ModelTextLocations* modelTextLocations)
  : common::CommonModelListener<SpenatBaseListener, SpenatParser, SpenatDeclModel>(spenatDeclModel,
                                                                             spenatErrors,
                                                                             keywordTextLocations,
                                                                             modelTextLocations),
    _d(new Private)
{}

SpenatModelListener::~SpenatModelListener()
{
  delete this->_d;
}

void SpenatModelListener::enterSpenatDecl(SpenatParser::SpenatDeclContext* ctx)
{
  this->_listenerStates.push(SpenatDeclState);

  typedef  tree::TerminalNode* (SpenatParser::SpenatDeclContext::*KeywordFunction)();

  return addKeywordLocation<SpenatParser::SpenatDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &SpenatParser::SpenatDeclContext::SpenatID, this->_keywordTextLocations, Spenat);

}

void SpenatModelListener::exitSpenatDecl(SpenatParser::SpenatDeclContext* /*ctx*/)
{
  this->_listenerStates.pop();
  return;
}

void SpenatModelListener::enterPortDecl(SpenatParser::PortDeclContext *ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  typedef  tree::TerminalNode* (SpenatParser::PortDeclContext::*KeywordFunction)();

  return addKeywordLocation<SpenatParser::PortDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &SpenatParser::PortDeclContext::PortID, this->_keywordTextLocations, Port);
}

void SpenatModelListener::exitPortDecl(SpenatParser::PortDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  for(SpenatParser::ContextIDContext* currContextID : ctx->contextID())
  {
    Token* portToken=currContextID->getStart();
    Q_ASSERT(portToken);

    QString portName=QString::fromStdString(currContextID->getText());
    QString errorString;
    PortItem* newPort = this->_model->addPort(portName, &errorString);
    if(!newPort)
    {
      if(this->_errors)
        this->_errors->append(DslError(errorString,
                                       portToken->getLine(),
                                       portToken->getCharPositionInLine()));
    }
    else
    {
      this->_modelTextLocations->insert(newPort->index(),
                                        TokenTextLocation(portToken->getStartIndex(),
                                                          portToken->getStopIndex(),
                                                          Port));
    }
  }

  return;
}

void SpenatModelListener::enterPlaceDecl(SpenatParser::PlaceDeclContext* ctx)
{
  this->_listenerStates.push(PlaceDeclState);
  this->_d->_currentPlaceIsInit = false;

  this->_d->_currentPlace.reset(new model::spenat::PlaceItem(QStringLiteral("")));

  typedef  tree::TerminalNode* (SpenatParser::PlaceDeclContext::*KeywordFunction)();

  return addKeywordLocation<SpenatParser::PlaceDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &SpenatParser::PlaceDeclContext::PlaceID, this->_keywordTextLocations, Place);
}

void SpenatModelListener::exitPlaceDecl(SpenatParser::PlaceDeclContext* placeDeclCtx)
{
  Q_ASSERT(placeDeclCtx);

  if(placeDeclCtx->exception)
    return;//an error occured! -> but still handled by error listener!

  if(!this->_d->_currentPlace)
    return;//an error occured! -> but still handled by error listener!

  Token* startToken = placeDeclCtx->getStart();
  Token* stopToken = placeDeclCtx->getStop();
  Q_ASSERT(startToken);
  Q_ASSERT(stopToken);

  PlaceItem* takenPlace = this->_d->_currentPlace.take();

  QString errorString;

  bool result = this->_model->addPlace(takenPlace,
                                       &errorString);

  if(!result)
  {
    if(this->_errors)
      this->_errors->append(DslError(errorString,
                                     startToken->getLine(),
                                     startToken->getCharPositionInLine()));
    delete takenPlace;
  }
  else
  {
    if(this->_d->_currentPlaceIsInit)
    {
      result=this->_model->addInitPlace(takenPlace, &errorString);
      Q_ASSERT(result);
      if(!result)
      {
        if(this->_errors)
          this->_errors->append(DslError(errorString,
                                         startToken->getLine(),
                                         startToken->getCharPositionInLine()));
      }
    }
    if(this->_modelTextLocations)
      this->_modelTextLocations->insert(takenPlace->index(),
                                        TokenTextLocation(startToken->getStartIndex(),
                                                          stopToken->getStopIndex(),
                                                          Place));
  }

  this->_d->_currentPlaceIsInit=false;
  this->_d->_currentPlace.reset();
  this->_listenerStates.pop();

  return;
}

void SpenatModelListener::enterTransitionDecl(SpenatParser::TransitionDeclContext*)
{
  this->_listenerStates.push(TransitionDeclState);

  this->_d->_currentTransition.reset(new model::spenat::TransitionItem(QStringLiteral("")));

  return;
}

void SpenatModelListener::exitTransitionDecl(SpenatParser::TransitionDeclContext* transDeclCtx)
{
  Q_ASSERT(transDeclCtx);

  if(transDeclCtx->exception)
    return;//an error occured! -> but still handled by error listener!

  if(!this->_d->_currentTransition)
    return;//an error occured! -> but still handled by error listener!

  Token* startToken = transDeclCtx->getStart();
  Token* stopToken = transDeclCtx->getStop();
  Q_ASSERT(startToken);
  Q_ASSERT(stopToken);

  int transitionType = SignalTransition;
  if(transDeclCtx->timeoutTransitionDecl())
    transitionType = TimeoutTransition;

  TransitionItem* takenTransition=this->_d->_currentTransition.take();
  QString errorString;
  bool result = this->_model->addTransition(takenTransition,
                                            &errorString);
  if(!result)
  {
    if(this->_errors)
      this->_errors->append(DslError(errorString,
                                     startToken->getLine(),
                                     startToken->getCharPositionInLine()));
    delete takenTransition;
  }
  else
  {
    if(this->_modelTextLocations)
    {
      this->_modelTextLocations->insert(takenTransition->index(),
                                        TokenTextLocation(startToken->getStartIndex(),
                                                          stopToken->getStopIndex(),
                                                          transitionType));
    }
  }

  this->_d->_currentTransition.reset();
  this->_listenerStates.pop();

  return;
}

void SpenatModelListener::enterSignalTransitionDecl(SpenatParser::SignalTransitionDeclContext* ctx)
{
  typedef  tree::TerminalNode* (SpenatParser::SignalTransitionDeclContext::*KeywordFunction)();

  return addKeywordLocation<SpenatParser::SignalTransitionDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &SpenatParser::SignalTransitionDeclContext::SignalTransitionID, this->_keywordTextLocations, SignalTransition);
}

void SpenatModelListener::exitSignalTransitionDecl(SpenatParser::SignalTransitionDeclContext* ctx)
{
  Q_ASSERT(ctx);

  this->_currentMessageSignalItem=nullptr;

  if(ctx->exception)//an error occured, handled by error listener, current transition is set to 0 for next rules!
    this->_d->_currentTransition.reset();

  return;
}

void SpenatModelListener::enterTimeoutTransitionDecl(SpenatParser::TimeoutTransitionDeclContext* ctx)
{
  typedef  tree::TerminalNode* (SpenatParser::TimeoutTransitionDeclContext::*KeywordFunction)();

  return addKeywordLocation<SpenatParser::TimeoutTransitionDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &SpenatParser::TimeoutTransitionDeclContext::TimeoutTransitionID, this->_keywordTextLocations, TimeoutTransition);
}

void SpenatModelListener::exitTimeoutTransitionDecl(SpenatParser::TimeoutTransitionDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)//an error occured, handled by error listener, current transition is set to 0 for next rules!
    this->_d->_currentTransition.reset();

  return;
}

void SpenatModelListener::enterNameDecl(SpenatParser::NameDeclContext* ctx)
{
  typedef  tree::TerminalNode* (SpenatParser::NameDeclContext::*KeywordFunction)();

  return addKeywordLocation<SpenatParser::NameDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &SpenatParser::NameDeclContext::NameID, this->_keywordTextLocations, Attribute);
}

void SpenatModelListener::exitNameDecl(SpenatParser::NameDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  Q_ASSERT(ctx->contextID());

  QString name=QString::fromStdString(ctx->contextID()->getText());

  int currListenerState = this->currentListenerState();
  if(currListenerState==SpenatDeclState)
  {
    Q_ASSERT(this->_model);
    this->_model->setName(name);
  }
  else if(currListenerState==PlaceDeclState)
  {
    Q_ASSERT(this->_d->_currentPlace);
    this->_d->_currentPlace->setName(name);
  }
  else if(currListenerState==TransitionDeclState)
  {
    Q_ASSERT(this->_d->_currentTransition);
    this->_d->_currentTransition->setName(name);
  }

  return;
}

void SpenatModelListener::enterRefSignalDecl(SpenatParser::RefSignalDeclContext* ctx)
{
  typedef  tree::TerminalNode* (SpenatParser::RefSignalDeclContext::*KeywordFunction)();

  return addKeywordLocation<SpenatParser::RefSignalDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &SpenatParser::RefSignalDeclContext::RefSignalID, this->_keywordTextLocations, Attribute);
}

void SpenatModelListener::exitRefSignalDecl(SpenatParser::RefSignalDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  Q_ASSERT(ctx->contextID());

  QString signalName=QString::fromStdString(ctx->contextID()->getText());

  int currListenerState = this->currentListenerState();
  if(currListenerState==TransitionDeclState)
  {
    Q_ASSERT(this->_d->_currentTransition);

    model::spenat::SignalItem* triggerSignal = this->_model->signal(signalName);
    if(!triggerSignal)
    {
      QString errorString = QObject::tr("there is no signal '%1' available!")
                            .arg(signalName);
      appendDslError(ctx->contextID()->getStart(),
                     errorString);
      return;
    }

    this->_currentMessageSignalItem=triggerSignal;
    this->_d->_currentTransition->setTriggerItem(new SignalTriggerItem(triggerSignal));
  }

  return;
}

void SpenatModelListener::enterRefPortDecl(SpenatParser::RefPortDeclContext* ctx)
{
  typedef  tree::TerminalNode* (SpenatParser::RefPortDeclContext::*KeywordFunction)();

  return addKeywordLocation<SpenatParser::RefPortDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &SpenatParser::RefPortDeclContext::RefPortID, this->_keywordTextLocations, Attribute);
}

void SpenatModelListener::exitRefPortDecl(SpenatParser::RefPortDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  Q_ASSERT(ctx->contextID());

  QString portName=QString::fromStdString(ctx->contextID()->getText());

  int currListenerState = this->currentListenerState();
  if(currListenerState==TransitionDeclState)
  {
    Q_ASSERT(this->_d->_currentTransition);

    model::spenat::PortItem const* triggerPort = this->_model->port(portName);
    if(!triggerPort)
    {
      QString errorString = QObject::tr("there is no port '%1' available!")
                            .arg(portName);
      appendDslError(ctx->contextID()->getStart(),
                     errorString);
      return;
    }

    ATriggerItem const* triggerItem = this->_d->_currentTransition->triggerItem();
    if(!triggerItem)
    {
      QString errorString = QObject::tr("port '%1' needs a signal as tranisition trigger!")
                            .arg(portName);
      appendDslError(ctx->contextID()->getStart(),
                     errorString);
      return;
    }

    Q_ASSERT(triggerItem->triggerType() == ATriggerItem::EventTrigger);
    SignalTriggerItem const* signalTriggerItem = static_cast<SignalTriggerItem const*>(triggerItem);
    const_cast<SignalTriggerItem*>(signalTriggerItem)->setPort(triggerPort);
  }

  return;
}

void SpenatModelListener::enterTimeoutDecl(SpenatParser::TimeoutDeclContext* ctx)
{
  Q_ASSERT(ctx);

  typedef  tree::TerminalNode* (SpenatParser::TimeoutDeclContext::*KeywordFunction)();

  return addKeywordLocation<SpenatParser::TimeoutDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &SpenatParser::TimeoutDeclContext::ValueID, this->_keywordTextLocations, Attribute);
}

void SpenatModelListener::exitTimeoutDecl(SpenatParser::TimeoutDeclContext *ctx)
{
  Q_ASSERT(ctx);
  Q_ASSERT(this->_d->_currentTransition);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  double timeout = QString::fromStdString(ctx->REAL()->getText()).toDouble();

  this->_d->_currentTransition->setTriggerItem(new TimeoutTriggerItem(timeout));
}

void SpenatModelListener::enterInitialDecl(SpenatParser::InitialDeclContext* ctx)
{
  Q_ASSERT(ctx);

  typedef  tree::TerminalNode* (SpenatParser::InitialDeclContext::*KeywordFunction)();

  return addKeywordLocation<SpenatParser::InitialDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &SpenatParser::InitialDeclContext::InitialID, this->_keywordTextLocations, Attribute);
}

void SpenatModelListener::exitInitialDecl(SpenatParser::InitialDeclContext* ctx)
{
  Q_ASSERT(ctx);
  Q_ASSERT(this->_d->_currentPlace);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  if(ctx->TrueID())
    this->_d->_currentPlaceIsInit = true;

  return;
}

void SpenatModelListener::enterGuardDecl(SpenatParser::GuardDeclContext* ctx)
{
  typedef  tree::TerminalNode* (SpenatParser::GuardDeclContext::*KeywordFunction)();

  return addKeywordLocation<SpenatParser::GuardDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &SpenatParser::GuardDeclContext::GuardID, this->_keywordTextLocations, Attribute);
}

void SpenatModelListener::exitGuardDecl(SpenatParser::GuardDeclContext *ctx)
{
  Q_ASSERT(ctx);
  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!
  QString res = "";
  if(ctx->expression()){
    const misc::Interval interval(ctx->expression()->getStart()->getStartIndex(),ctx->expression()->getStop()->getStopIndex());
    res = QString::fromStdString(ctx->expression()->getStart()->
                                 getInputStream()->
                                 getText(interval));
  }
  else if (ctx->multiExpression()) {
    const misc::Interval interval(ctx->multiExpression()->getStart()->getStartIndex()+1,ctx->multiExpression()->getStop()->getStopIndex()-1);
    res = QString::fromStdString(ctx->multiExpression()->getStart()->
                                 getInputStream()->
                                 getText(interval));
  }
  res = res.trimmed();
  _d->_currentTransition->setGuard(res);
}

void SpenatModelListener::exitAtom(SpenatParser::AtomContext *ctx)
{
  if(auto literalValueCtx = ctx->literalValue())
  {
    if(auto literalValueIdCtx = literalValueCtx->contextID())
    {
      QString literalValueId = QString::fromStdString(literalValueIdCtx->getText());
      if(!this->_model->hasEnumValue(literalValueId))
      {
        QString errorString = QObject::tr("Enum Value '%1' does not exist!")
                              .arg(literalValueId);
        appendDslError(literalValueIdCtx->getStart(),
                       errorString);
        return;
      }
    }
  }

  if(auto attrCtx = ctx->attributeName())
  {
    if(attrCtx->thisDecl())
    {
      QString attrName = QString::fromStdString(attrCtx->contextID()->getText());
      if(!_model->attribute(attrName))
      {
        QString errorString = QObject::tr("Attribute '%1' does not exist!")
                              .arg(attrName);
        appendDslError(attrCtx->contextID()->getStart(),
                       errorString);
        return;
      }
    }
    else
    {
      QString contextIdString = QString::fromStdString(attrCtx->contextID()->getText());
      if(!this->_model->attribute(contextIdString)
         && !this->_model->hasEnumValue(contextIdString))
      {
        QString errorString = QObject::tr("attribute or enum value '%1' does not exist!")
                              .arg(contextIdString);
        appendDslError(attrCtx->contextID()->getStart(),
                       errorString);
        return;
      }
    }
  }
  if(auto attrCtx = ctx->signalParamName()) {
    QString attrName = QString::fromStdString(attrCtx->contextID()->getText());
    if(auto signalTrig = dynamic_cast<const SignalTriggerItem*>(_d->_currentTransition->triggerItem())){
      if(auto signal = signalTrig->triggerSignal()){
        if(!signal->parameter(attrName)){
          QString errorString = QObject::tr("Signal '%1' has no parameter '%2' available!")
                                .arg(signal->name()).arg(attrName);
          appendDslError(attrCtx->contextID()->getStart(),
                         errorString);
          return;
        }
      }
      else{
        QString errorString = QObject::tr("SignalTrigger has no Signal!");
        appendDslError(attrCtx->getStart(),
                       errorString);
        return;
      }
    }
    else{
      QString errorString = QObject::tr("Transition '%1' is not a SignalTransition!")
                            .arg(_d->_currentTransition->name());
      appendDslError(attrCtx->contextID()->getStart(),
                     errorString);
      return;
    }
  }
}

void SpenatModelListener::enterActionDecl(SpenatParser::ActionDeclContext* ctx)
{
  typedef  tree::TerminalNode* (SpenatParser::ActionDeclContext::*KeywordFunction)();

  return addKeywordLocation<SpenatParser::ActionDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &SpenatParser::ActionDeclContext::ActionID, this->_keywordTextLocations, Attribute);
}

void SpenatModelListener::exitActionDecl(SpenatParser::ActionDeclContext *ctx)
{
  Q_ASSERT(ctx);
  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  QString res = "";
  if(ctx->singleAssignment())
  {
    if(ctx->singleAssignment()->attributeAssignStatement())
    {
      const misc::Interval interval(ctx->singleAssignment()->attributeAssignStatement()->getStart()->getStartIndex(),
                                    ctx->singleAssignment()->attributeAssignStatement()->getStop()->getStopIndex());
      res = QString::fromStdString(ctx->getStart()->
                                   getInputStream()->
                                   getText(interval));
    }
    else if(ctx->singleAssignment()->sendToStatement())
    {
      const misc::Interval interval(ctx->singleAssignment()->sendToStatement()->getStart()->getStartIndex(),
                                    ctx->singleAssignment()->sendToStatement()->getStop()->getStopIndex());
      res = QString::fromStdString(ctx->getStart()->
                                   getInputStream()->
                                   getText(interval));
    }
  }
  else if (ctx->multiAssignment())
  {
    const misc::Interval interval(ctx->multiAssignment()->getStart()->getStartIndex()+1,
                                  ctx->multiAssignment()->getStop()->getStopIndex()-1);
    res = QString::fromStdString(ctx->multiAssignment()->getStart()->
                                 getInputStream()->
                                 getText(interval));
  }
  res = res.trimmed();
  _d->_currentTransition->setActions(res);
}

void SpenatModelListener::enterPreDecl(SpenatParser::PreDeclContext* ctx)
{
  Q_ASSERT(ctx);

  typedef  tree::TerminalNode* (SpenatParser::PreDeclContext::*KeywordFunction)();

  return addKeywordLocation<SpenatParser::PreDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &SpenatParser::PreDeclContext::PreID, this->_keywordTextLocations, Attribute);
}

void SpenatModelListener::exitPreDecl(SpenatParser::PreDeclContext* ctx)
{
  Q_ASSERT(ctx);
  Q_ASSERT(this->_d->_currentTransition);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  for(SpenatParser::ContextIDContext* currContextID : ctx->contextID())
  {
    QString preName=QString::fromStdString(currContextID->getText());
    PlaceItem* prePlace = this->_model->place(preName);
    if(!prePlace)
    {
      QString errorString = QObject::tr("there is no place '%1' as pre-place for transition '%2' available!")
                            .arg(preName).arg(this->_d->_currentTransition->name());
      appendDslError(currContextID->getStart(),
                     errorString);
      return;
    }

    if(!this->_d->_currentTransition->addPrePlaceArc(prePlace))
    {
      QString errorString = QObject::tr("there is already an arc between place '%1' and transition '%2' available!")
                            .arg(preName).arg(this->_d->_currentTransition->name());
      appendDslError(currContextID->getStart(),
                     errorString);
      return;
    }
  }

  return;
}

void SpenatModelListener::enterPostDecl(SpenatParser::PostDeclContext* ctx)
{
  Q_ASSERT(ctx);

  typedef  tree::TerminalNode* (SpenatParser::PostDeclContext::*KeywordFunction)();

  return addKeywordLocation<SpenatParser::PostDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &SpenatParser::PostDeclContext::PostID, this->_keywordTextLocations, Attribute);
}

void SpenatModelListener::exitPostDecl(SpenatParser::PostDeclContext* ctx)
{
  Q_ASSERT(ctx);
  Q_ASSERT(this->_d->_currentTransition);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  for(SpenatParser::ContextIDContext* currContextID : ctx->contextID())
  {
    QString postPlaceName=QString::fromStdString(currContextID->getText());
    PlaceItem* postPlace = this->_model->place(postPlaceName);
    if(!postPlace)
    {
      QString errorString = QObject::tr("there is no place '%1' as post-place for transition '%2' available!")
                            .arg(postPlaceName).arg(this->_d->_currentTransition->name());
      appendDslError(currContextID->getStart(),
                     errorString);
      return;
    }

    if(!this->_d->_currentTransition->addPostPlaceArc(postPlace))
    {
      QString errorString = QObject::tr("there is already an arc between transition '%1' and place '%2' available!")
                            .arg(this->_d->_currentTransition->name()).arg(postPlaceName);
      appendDslError(currContextID->getStart(),
                     errorString);
      return;
    }
  }

  return;
}

void SpenatModelListener::visitErrorNode(tree::ErrorNode* node)
{
  Q_UNUSED(node);

  //  qDebug()<<"SpenatModelListener::visitErrorNode() "
  //            "state: "<<this->_d->_listenerStates.top()
  //         <<"error node: "<<node->toString().c_str();

  return;
}

} // namespace spenat
} // namespace dslparser
