#include "isrdlmodellistener.hpp"
#include "mobata/model/isrdl/isrdlattackdescription.h"
#include "mobata/model/isrdl/isrdlattackimpact.h"

#include <QStack>
#include <QDebug>

#include <exception>

#include <mobata/memory_leak_start.hpp>

using namespace model::isrdl;
using namespace model::base;
using namespace antlr4;

namespace dslparser {
namespace isrdl {

using common::addKeywordLocation;
using common::addSimpleKeywordLocation;

class IsrdlModelListener::Private
{
  friend class IsrdlModelListener;

  IsrdlItem*              _requirementItem = nullptr;
  IsrdlAttackImpact*      _impact = nullptr;
  IsrdlAttackDescription* _description = nullptr;
  Private()
  {}
};



IsrdlModelListener::IsrdlModelListener(IsrdlModel* isrdlDeclModel,
                                       DslErrorList* isrdlErrors,
                                       TokenTextLocations* keywordTextLocations,
                                       ModelTextLocations* modelTextLocations)
  : common::CommonModelListener<IsrdlBaseListener, IsrdlParser, model::isrdl::IsrdlModel> (isrdlDeclModel,
                                                                                           isrdlErrors,
                                                                                           keywordTextLocations,
                                                                                           modelTextLocations),
    _d(new Private)
{
  Q_ASSERT(isrdlDeclModel);
}

IsrdlModelListener::~IsrdlModelListener()
{
  delete this->_d;
}

void IsrdlModelListener::enterSecRequirement(IsrdlParser::SecRequirementContext* ctx)
{
  Q_UNUSED(ctx);
  _d->_requirementItem = new IsrdlItem();
  _d->_description = _d->_requirementItem->attackDescription();
  _d->_impact = _d->_requirementItem->attackImpact();
  _model->addIsrdlItem(_d->_requirementItem);
  this->_listenerStates.push(IsrdlState);

  return;
}

void IsrdlModelListener::exitSecRequirement(IsrdlParser::SecRequirementContext *ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception || _errors->size())
    return;//an error occured! -> but still handled by error listener!

  this->_listenerStates.pop();

  this->_modelTextLocations->insert(this->_model->invisibleRootItem()->index(),
                                    TokenTextLocation(ctx->getStart()->getStartIndex(),
                                                      ctx->getStop()->getStopIndex(),
                                                      SecurityRequirement));

  //  typedef  tree::TerminalNode* (IsrdlParser::SecRequirementContext::*KeywordFunction)();

  return addSimpleKeywordLocation<TokenTextLocations>
      (ctx->SecurityRequirementID(), this->_keywordTextLocations, SecurityRequirement);
}

void IsrdlModelListener::enterAttackDescriptionDecl(IsrdlParser::AttackDescriptionDeclContext *ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception || _errors->size())
    return;//an error occured! -> but still handled by error listener!
}

void IsrdlModelListener::exitAttackDescriptionDecl(IsrdlParser::AttackDescriptionDeclContext *ctx)
{

  Q_ASSERT(ctx);

  if(ctx->exception || _errors->size())
    return;//an error occured! -> but still handled by error listener!

  this->_modelTextLocations->insert(this->_model->invisibleRootItem()->index(),
                                    TokenTextLocation(ctx->getStart()->getStartIndex(),
                                                      ctx->getStop()->getStopIndex(),
                                                      Description));

  addSimpleKeywordLocation<TokenTextLocations>
      (ctx->AttackDescriptionID(), this->_keywordTextLocations, Description);
}

void IsrdlModelListener::enterAttackImpactDecl(IsrdlParser::AttackImpactDeclContext *ctx)
{

  if(!_d->_description->attackPrivileges().size()){
    _d->_description->addAttackPrivilege(NoPrivileges);
  }
  Q_ASSERT(ctx);

  if(ctx->exception || _errors->size())
    return;//an error occured! -> but still handled by error listener!
}

void IsrdlModelListener::exitAttackImpactDecl(IsrdlParser::AttackImpactDeclContext *ctx)
{
  if(!_d->_impact->confidentiality() && !_d->_impact->integrity() && _d->_impact->timeout()<0){
    appendDslError(ctx->start,QString("You need to specify at least one attack impact!"));
  }
  addSimpleKeywordLocation<TokenTextLocations>
      (ctx->ImpactID(), this->_keywordTextLocations, Impact);
}

void IsrdlModelListener::exitAttackVectorDecl(IsrdlParser::AttackVectorDeclContext *ctx)
{

  Q_ASSERT(ctx);

  if(ctx->exception || _errors->size())
    return;//an error occured! -> but still handled by error listener!

  if(auto vecEnum = ctx->attackVectorEnum()){
    if(vecEnum->InternetID()){
      _d->_description->setAttackVector(AttackVector::Internet);
      addSimpleKeywordLocation<TokenTextLocations>
          (vecEnum->InternetID(), this->_keywordTextLocations, AttackVectorEnum);
    }
    else if(vecEnum->LocalID()){
      _d->_description->setAttackVector(AttackVector::Local);
      addSimpleKeywordLocation<TokenTextLocations>
          (vecEnum->LocalID(), this->_keywordTextLocations, AttackVectorEnum);
    }
    else if(vecEnum->PhysicalID()){
      _d->_description->setAttackVector(AttackVector::Physical);
      addSimpleKeywordLocation<TokenTextLocations>
          (vecEnum->PhysicalID(), this->_keywordTextLocations, AttackVectorEnum);
    }
    else{
      appendDslError(vecEnum->start,QString("No viable option for attack vector!"));
    }
  }

  _d->_description->update();

  addSimpleKeywordLocation<TokenTextLocations>
      (ctx->SourceID(), this->_keywordTextLocations, Source);
}

void IsrdlModelListener::exitAttackPrivileges(IsrdlParser::AttackPrivilegesContext *ctx)
{
  addSimpleKeywordLocation<TokenTextLocations>
      (ctx->PrivilegesID(), this->_keywordTextLocations, Privileges);
}

void IsrdlModelListener::exitPrivilegesEnum(IsrdlParser::PrivilegesEnumContext *ctx)
{

  Q_ASSERT(ctx);

  if(ctx->exception || _errors->size())
    return;//an error occured! -> but still handled by error listener!

  if(ctx->AdministratorID()){
    if(!_d->_description->attackPrivileges().contains(AttackPrivileges::NoPrivileges))
      _d->_description->setAttackPrivileges(QList<AttackPrivileges>({AttackPrivileges::Administrator}));
    else{
      appendDslError(ctx->start,QString("You are not allowed to specify ’NoPrivileges' and 'Administrator'."));
    }
    addSimpleKeywordLocation<TokenTextLocations>
        (ctx->AdministratorID(), this->_keywordTextLocations, PrivilegesEnum);
  }
  else if(ctx->EditAllowedID()){
    if(!_d->_description->attackPrivileges().contains(AttackPrivileges::NoPrivileges)){
      if(!_d->_description->attackPrivileges().contains(AttackPrivileges::Administrator))
        _d->_description->addAttackPrivilege(AttackPrivileges::Edit);
      else
        _d->_description->setAttackPrivileges(QList<AttackPrivileges>({AttackPrivileges::Administrator}));
    }
    else{
      appendDslError(ctx->start,QString("You are not allowed to specify ’NoPrivileges' and 'Edit'."));
    }
    addSimpleKeywordLocation<TokenTextLocations>
        (ctx->EditAllowedID(), this->_keywordTextLocations, PrivilegesEnum);
  }
  else if(ctx->InstallAllowedID()){
    if(!_d->_description->attackPrivileges().contains(AttackPrivileges::NoPrivileges))
      if(!_d->_description->attackPrivileges().contains(AttackPrivileges::Administrator))
        _d->_description->addAttackPrivilege(AttackPrivileges::Install);
      else
        _d->_description->setAttackPrivileges(QList<AttackPrivileges>({AttackPrivileges::Administrator}));
    else{
      appendDslError(ctx->start,QString("You are not allowed to specify ’NoPrivileges' and 'Install'."));
    }
    addSimpleKeywordLocation<TokenTextLocations>
        (ctx->InstallAllowedID(), this->_keywordTextLocations, PrivilegesEnum);
  }
  else if(ctx->SaveAllowedID()){
    if(!_d->_description->attackPrivileges().contains(AttackPrivileges::NoPrivileges))
      if(!_d->_description->attackPrivileges().contains(AttackPrivileges::Administrator))
        _d->_description->addAttackPrivilege(AttackPrivileges::Save);
      else
        _d->_description->setAttackPrivileges(QList<AttackPrivileges>({AttackPrivileges::Administrator}));
    else{
      appendDslError(ctx->start,QString("You are not allowed to specify ’NoPrivileges' and 'Save'."));
    }
    addSimpleKeywordLocation<TokenTextLocations>
        (ctx->SaveAllowedID(), this->_keywordTextLocations, PrivilegesEnum);
  }
  else if(ctx->UnInstallAllowedID()){
    if(!_d->_description->attackPrivileges().contains(AttackPrivileges::NoPrivileges))
      if(!_d->_description->attackPrivileges().contains(AttackPrivileges::Administrator))
        _d->_description->addAttackPrivilege(AttackPrivileges::Uninstall);
      else
        _d->_description->setAttackPrivileges(QList<AttackPrivileges>({AttackPrivileges::Administrator}));
    else{
      appendDslError(ctx->start,QString("You are not allowed to specify ’NoPrivileges' and 'UnInstall'."));
    }
    addSimpleKeywordLocation<TokenTextLocations>
        (ctx->UnInstallAllowedID(), this->_keywordTextLocations, PrivilegesEnum);
  }
  else if(ctx->NoneID()){
    if(!_d->_description->attackPrivileges().length())
      _d->_description->setAttackPrivileges(QList<AttackPrivileges>({AttackPrivileges::NoPrivileges}));
    else{
      appendDslError(ctx->start,QString("You are not allowed to specify ’NoPrivileges' and any other Privilege."));
    }
    addSimpleKeywordLocation<TokenTextLocations>
        (ctx->NoneID(), this->_keywordTextLocations, PrivilegesEnum);
  }
  else{
    appendDslError(ctx->start,QString("No viable option for attack privileges!"));
  }

  _d->_description->update();
}

void IsrdlModelListener::exitConfidentialityThreatDecl(IsrdlParser::ConfidentialityThreatDeclContext *ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception || !_d->_impact)
    return;//an error occured! -> but still handled by error listener!

  if(auto confEnum = ctx->confidentialityEnum()){
    if(confEnum->BrokenID()){
      _d->_impact->setConfidentiality(true);
      addSimpleKeywordLocation<TokenTextLocations>
          (confEnum->BrokenID(), this->_keywordTextLocations, ConfidentialityEnum);
    }
    else if(confEnum->IntactID()){
      _d->_impact->setConfidentiality(false);
      addSimpleKeywordLocation<TokenTextLocations>
          (confEnum->IntactID(), this->_keywordTextLocations, ConfidentialityEnum);
    }
    else{
      appendDslError(confEnum->start,QString("No viable option for confidentiality impact!"));
    }
  }

  _d->_impact->update();

  return addSimpleKeywordLocation<TokenTextLocations>
      (ctx->ConfidentialityThreatID(), this->_keywordTextLocations, ConfidentialityThreat);
}

void IsrdlModelListener::exitIntegrityThreatDecl(IsrdlParser::IntegrityThreatDeclContext *ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception || !_d->_impact)
    return;//an error occured! -> but still handled by error listener!

  if(auto integEnum = ctx->integrityEnum()){
    if(integEnum->AffectedID()){
      _d->_impact->setIntegrity(true);
      addSimpleKeywordLocation<TokenTextLocations>
          (integEnum->AffectedID(), this->_keywordTextLocations, IntegrityEnum);
    }
    else if(integEnum->NoDamageID()){
      _d->_impact->setIntegrity(false);
      addSimpleKeywordLocation<TokenTextLocations>
          (integEnum->NoDamageID(), this->_keywordTextLocations, IntegrityEnum);
    }
    else{
      appendDslError(integEnum->start,QString("No viable option for integrity impact!"));
    }
  }

  _d->_impact->update();

  return addSimpleKeywordLocation<TokenTextLocations>
      (ctx->IntegrityThreatID(), this->_keywordTextLocations, IntegrityThreat);
}

void IsrdlModelListener::exitAvailabilityThreatDecl(IsrdlParser::AvailabilityThreatDeclContext *ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception || !_d->_impact)
    return;//an error occured! -> but still handled by error listener!

  int num = -1;
  if(ctx->INT()){
    num = QString::fromStdString(ctx->INT()->getText()).toInt();
    if(ctx->SekID()) num*=1000;
  }

  if(num>=0){
    _d->_impact->setTimeout(num);
  }
  else {
    _d->_impact->setTimeout(-1);
  }

  _d->_impact->update();

  return addSimpleKeywordLocation<TokenTextLocations>
      (ctx->TimeoutID(), this->_keywordTextLocations, Timeout);
}

void IsrdlModelListener::enterNameDecl(IsrdlParser::NameDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  return addSimpleKeywordLocation<TokenTextLocations>
      (ctx->NameID(), this->_keywordTextLocations, Attribute);
}

void IsrdlModelListener::exitNameDecl(IsrdlParser::NameDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  Q_ASSERT(ctx->ID());

  QString name=QString::fromStdString(ctx->ID()->getText());

  int currListenerState = this->currentListenerState();
  if(currListenerState==IsrdlState)
  {
    Q_ASSERT(this->_model);
    this->_model->setName(name);
    this->_d->_requirementItem->setText(name);
  }
  return;
}

void IsrdlModelListener::visitErrorNode(tree::ErrorNode* node)
{
  Q_UNUSED(node);
  return;
}

} // namespace isrdl
} // namespace dslparser
