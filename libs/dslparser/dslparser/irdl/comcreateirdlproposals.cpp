#include "comcreateirdlproposals.hpp"

#include "combuildirdlmodel.hpp"

#include <mobata/model/requirement/requirementsmodel.hpp>
#include <mobata/model/requirement/reqactorcomponentitem.hpp>
#include <mobata/model/requirement/requirementitem.hpp>
#include <mobata/model/msc/msc_types.hpp>
#include <mobata/model/msc/msccomponentitem.hpp>
#include <mobata/model/msc/msctimeritem.hpp>

#include <mobata/utils/functors.hpp>

#include <QDebug>

#undef emit
#undef SIGNAL

#include <antlr4/antlr4-runtime.h>

#include "IrdlParser.h"
#include "IrdlLexer.h"
#include "IrdlBaseListener.h"

#include <mobata/memory_leak_start.hpp>

#include <QDir>

using namespace utils;
using namespace model::base;
using namespace model::msc;
using namespace model::irdl;
using namespace antlr4;

namespace dslparser {
namespace irdl {

class IrdlProposalErrorListener
    : public BaseErrorListener
{
  std::size_t                         _line;
  std::size_t                         _posInLine;
  DslProposalList*                    _requirementProposals;
  QHash<QString,const model::msc::MscComponentItem *>         _requirementItems;
  RequirementsModel*                              _requirementDeclModel;
  const model::base::ModelItem*                   _currentSignalItem;
  QPair<model::base::ModelItem*,int>              _currentPathItem;
  ImportModelItem                                 _importItems;
  ImportModel                                     _importModels;
  QHash<QString,const model::msc::MscTimerItem *> _timerItems;
  QString                                         _praefix;

  //  linePos.first,
  //    linePos.second,
  //    &this->_d->_requirementProposals,
  //    buildCommand.importItems(),
  //    buildCommand.importModels(),
  //    buildCommand.requirementItems(),
  //    irdlDeclModel,
  //    buildCommand.currentSignalItem(),
  //    buildCommand.currentPathItem(),
  //    this->_d->_prefix

public:
  IrdlProposalErrorListener(std::size_t line,
                            int posInLine,
                            DslProposalList* irdlProposals,
                            const ImportModelItem& importItems,
                            const ImportModel& importModels,
                            QHash<QString,const model::msc::MscComponentItem *> requirementItems,
                            RequirementsModel* irdlDeclModel = nullptr,
                            const ModelItem* currentSignalItem = nullptr,
                            QPair<model::base::ModelItem*,int> currentPathItem = QPair<model::base::ModelItem*,int>(nullptr,0),
                            const QHash<QString,const model::msc::MscTimerItem *>& timerItems = QHash<QString,const model::msc::MscTimerItem *>(),
                            const QString& praefix = "")
    : _line(line),
      _posInLine(std::size_t(posInLine)),
      _requirementProposals(irdlProposals),
      _requirementItems(requirementItems),
      _requirementDeclModel(irdlDeclModel),
      _currentSignalItem(currentSignalItem),
      _currentPathItem(currentPathItem),
      _importItems(importItems),
      _importModels(importModels),
      _timerItems(timerItems),
      _praefix(praefix)
  {}

protected:
  enum PossibleModelClasses{
    AttributeItemModel = 0,
    AttributeItemModelInCheckItem,
    ComponentModel,
    PortModel,
    SignalModel,
    TimerModel,
    Any
  };
  virtual void syntaxError(Recognizer* recognizer,
                           Token* offendingSymbol,
                           size_t line,
                           std::size_t charPositionInLine,
                           const std::string &msg,
                           std::exception_ptr /*e*/) override
  {
    Q_ASSERT(this->_requirementProposals);
    Q_UNUSED(offendingSymbol);
    Q_UNUSED(msg);

    if(line != this->_line)
      return;

    if(charPositionInLine != this->_posInLine)
      return;

    //    _requirementProposals->clear();

    IrdlParser* parser = static_cast<IrdlParser*>(recognizer);
    Q_ASSERT(parser);

    ParserRuleContext* ruleCtx = parser->getRuleContext();
    Q_ASSERT(ruleCtx);
    int ruleIndex = int(ruleCtx->getRuleIndex());

    TokenStream* stream = parser->getTokenStream();
    Token* lastToken = stream->get(stream->size()-1);

    if(ruleIndex == IrdlParser::RuleContextID)
    {
      if(RuleContext* parentRuleCtx = dynamic_cast<RuleContext*>(ruleCtx->parent))
      {
        if(parentRuleCtx->getRuleIndex() == IrdlParser::RuleAttributeName)
          CalcRefAttributesProposals(this->_requirementDeclModel, _requirementProposals)();
        else if(parentRuleCtx->getRuleIndex() == IrdlParser::RuleImportFileBody){
          RuleContext* greatParentRuleCtx = parentRuleCtx;
          do{
            parentRuleCtx = greatParentRuleCtx;
            greatParentRuleCtx =  dynamic_cast<RuleContext*>(greatParentRuleCtx->parent);
          }
          while(greatParentRuleCtx->getRuleIndex() != IrdlParser::RuleImportPathBody);

          IrdlParser::ImportFileBodyContext* idPathCtx = dynamic_cast<IrdlParser::ImportFileBodyContext*>(parentRuleCtx);
          QString pathStr = QString::fromStdString(stream->getText(misc::Interval(idPathCtx->getStart()->getTokenIndex(),stream->size()-1)));
          pathStr.remove('\n');
          pathStr.remove(' ');
          pathStr.remove('\t');
          calcImportOptions(pathStr, _requirementProposals);
        }
        else if(parentRuleCtx->getRuleIndex() == IrdlParser::RuleAttributeIdPath){
          auto mother = static_cast<IrdlParser::AttributeIdPathContext*>(parentRuleCtx);
          if(mother && !mother->exception){
            QStringList path = QString::fromStdString(stream->getText(mother->start,lastToken))
                .remove(QChar('\b')).remove(QChar('\t')).remove(QChar('\n')).remove(QChar('\r'))
                .remove(QChar('\\')).remove(QChar(' ')).split(QChar('.'));
            calcAttributes(path,_requirementProposals);
          }
        }
        else if(parentRuleCtx->getRuleIndex() == IrdlParser::RuleSignalIdPath){
          auto mother = static_cast<IrdlParser::SignalIdPathContext*>(parentRuleCtx);
          if(mother && !mother->exception){
            QStringList path = QString::fromStdString(stream->getText(mother->start,lastToken))
                .remove(QChar('\b')).remove(QChar('\t')).remove(QChar('\n')).remove(QChar('\r'))
                .remove(QChar('\\')).remove(QChar(' ')).split(QChar('.'));
            calcSignals(path,_requirementProposals);
          }
        }
        else if(parentRuleCtx->getRuleIndex() == IrdlParser::RuleComponentIdPath){
          auto mother = static_cast<IrdlParser::ComponentIdPathContext*>(parentRuleCtx);
          if(mother && !mother->exception){
            QStringList path = QString::fromStdString(stream->getText(mother->start,lastToken))
                .remove(QChar('\b')).remove(QChar('\t')).remove(QChar('\n')).remove(QChar('\r'))
                .remove(QChar('\\')).remove(QChar(' ')).split(QChar('.'));
            calcComponents(path,_requirementProposals);
          }
        }
        else if(parentRuleCtx->getRuleIndex() == IrdlParser::RuleSignalParamName){
          if(_currentSignalItem){
            for(auto param : static_cast<const model::base::SignalItem*>(_currentSignalItem)->params()){
              addUniqueProposal(_requirementProposals,DslProposal(param->name(),Identifier));
            }
          }
        }
        else if(parentRuleCtx->getRuleIndex() == IrdlParser::RuleTimerNameID){
          for(QString timerName : _timerItems.keys())
            addUniqueProposal(_requirementProposals,DslProposal(timerName,Identifier));
        }
      }
    }
    else if(ruleIndex == IrdlParser::RuleImportFileBody){
      RuleContext* parentRuleCtx = ruleCtx;
      RuleContext* greatParentRuleCtx = parentRuleCtx;
      do{
        parentRuleCtx = greatParentRuleCtx;
        greatParentRuleCtx =  dynamic_cast<RuleContext*>(greatParentRuleCtx->parent);
      }
      while(greatParentRuleCtx->getRuleIndex() != IrdlParser::RuleImportPathBody);

      IrdlParser::ImportFileBodyContext* idPathCtx = dynamic_cast<IrdlParser::ImportFileBodyContext*>(parentRuleCtx);
      QString pathStr = QString::fromStdString(stream->getText(misc::Interval(idPathCtx->getStart()->getTokenIndex(),stream->size()-1)));
      pathStr.remove('\n');
      pathStr.remove(' ');
      pathStr.remove('\t');
      calcImportOptions(pathStr, _requirementProposals);
    }
    else if(ruleIndex == IrdlParser::RuleCheckDeclBody){
      calcAttributes(QStringList(),_requirementProposals);
    }
    else
    {//keywords
      const dfa::Vocabulary& vocabulary = parser->getVocabulary();
      misc::IntervalSet expTokens = parser->getExpectedTokens();
      QStringList emptyCtx = {};
      bool alreadyGotContextID = false;
      for (int token : expTokens.toList())
      {
        if(ruleIndex == IrdlParser::RuleAtom && this->isContextID(token)){
          if(!alreadyGotContextID){
            QStringList path = QString::fromStdString(stream->getText(ruleCtx->start,lastToken))
                .remove(QChar('\b')).remove(QChar('\t')).remove(QChar('\n')).remove(QChar('\r'))
                .remove(QChar('\\')).remove(QChar(' ')).split(QChar('.'));
            calcAttributes(path,_requirementProposals);
            if(path.size()<2) calcLiteralValues(_requirementProposals);
            alreadyGotContextID = true;
          }
          continue;
        }
        if(ruleIndex == IrdlParser::RuleMessageSignal && this->isContextID(token)){
          if(!alreadyGotContextID){
            QStringList path;
            calcAttributes(path,_requirementProposals);
            calcLiteralValues(_requirementProposals);
            alreadyGotContextID = true;
          }
          continue;
        }
        else if(ruleIndex == IrdlParser::RuleSequenceDecl && this->isContextID(token)){
          if(!alreadyGotContextID){
            QStringList path = QString::fromStdString(stream->getText(ruleCtx->start,lastToken))
                .remove(QChar('\b')).remove(QChar('\t')).remove(QChar('\n')).remove(QChar('\r'))
                .remove(QChar('\\')).remove(QChar(' ')).split(QChar('.'));
            calcAttributes(path,_requirementProposals);
            calcLiteralValues(_requirementProposals);
            alreadyGotContextID = true;
          }
          continue;
        }
        else if(ruleIndex == IrdlParser::RuleAttributeAssignStatement && this->isContextID(token)){
          if(!alreadyGotContextID){
            auto startToken = ruleCtx->start;
            QString path = QString::fromStdString(stream->getText(startToken,lastToken))
                .remove(QChar('\b')).remove(QChar('\t')).remove(QChar('\n')).remove(QChar('\r'))
                .remove(QChar('\\')).remove(QChar(' '));
            bool hasAssign = path.contains(QChar('='));
            if(hasAssign){
              path.remove(0,path.lastIndexOf(QChar('='))+1);
              if(_currentSignalItem){
                for(auto param : static_cast<const model::base::SignalItem*>(_currentSignalItem)->params()){
                  addUniqueProposal(_requirementProposals,DslProposal(param->name(),Identifier));
                }
              }
              calcLiteralValues(_requirementProposals);
            }
            QStringList pathList = path.split(QChar('.'));
            calcAttributes(pathList,_requirementProposals);
            alreadyGotContextID = true;
          }
          continue;
        }
        else if(ruleIndex == IrdlParser::RuleLiteralValue && this->isContextID(token)){
          if(!alreadyGotContextID){
            calcLiteralValues(_requirementProposals);
            alreadyGotContextID = true;
          }

          continue;
        }
        else if(ruleIndex == IrdlParser::RuleFunctionCallBody && this->isContextID(token)){
          if(!alreadyGotContextID){
            QStringList path = QString::fromStdString(stream->getText(ruleCtx->start,lastToken))
                .remove(QChar('\b')).remove(QChar('\t')).remove(QChar('\n')).remove(QChar('\r'))
                .remove(QChar('\\')).remove(QChar(' ')).split(QChar('.'));
            calcAttributes(path,_requirementProposals);
            if(path.size()<2) calcLiteralValues(_requirementProposals);
            alreadyGotContextID = true;
          }
          continue;
        }
        else if(ruleIndex == IrdlParser::RuleExpression && this->isContextID(token)){
          if(!alreadyGotContextID){
            QStringList path = QString::fromStdString(stream->getText(ruleCtx->start,lastToken))
                .remove(QChar('\b')).remove(QChar('\t')).remove(QChar('\n')).remove(QChar('\r'))
                .remove(QChar('\\')).remove(QChar(' ')).split(QChar('.'));
            calcAttributes(path,_requirementProposals);
            if(path.size()<2) calcLiteralValues(_requirementProposals);
            alreadyGotContextID = true;
          }
          continue;
        }
        else if(ruleIndex == IrdlParser::RuleExpressionOptional && this->isContextID(token)){
          if(!alreadyGotContextID){
            calcAttributes(emptyCtx,_requirementProposals);
            calcLiteralValues(_requirementProposals);
            alreadyGotContextID = true;
          }
          continue;
        }
        else if(ruleIndex == IrdlParser::RuleAltBody && this->isContextID(token)){
          if(!alreadyGotContextID){
            calcAttributes(emptyCtx,_requirementProposals);
            calcLiteralValues(_requirementProposals);
            for(QString timerName : _timerItems.keys())
              addUniqueProposal(_requirementProposals,DslProposal(timerName,Identifier));
            alreadyGotContextID = true;
          }
          continue;
        }
        else if(ruleIndex == IrdlParser::RuleAttributeAssignStatement && this->isContextID(token)){
          if(!alreadyGotContextID){
            QStringList path = QString::fromStdString(stream->getText(ruleCtx->start,lastToken))
                .remove(QChar('\b')).remove(QChar('\t')).remove(QChar('\n')).remove(QChar('\r'))
                .remove(QChar('\\')).remove(QChar(' ')).split(QChar('.'));
            calcAttributes(path,_requirementProposals);
            if(path.size()<2) calcLiteralValues(_requirementProposals);
            alreadyGotContextID = true;
          }
          continue;
        }
        else if(ruleIndex == IrdlParser::RuleCheckDeclBody && this->isContextID(token)){
          if(!alreadyGotContextID){
            QStringList path = QString::fromStdString(stream->getText(ruleCtx->start,lastToken))
                .remove(QChar('\b')).remove(QChar('\t')).remove(QChar('\n')).remove(QChar('\r'))
                .remove(QChar('\\')).remove(QChar(' ')).remove('[').remove(']').split(QChar('.'));
            calcAttributes(path,_requirementProposals);
            if(path.size()<2) calcLiteralValues(_requirementProposals);
            alreadyGotContextID = true;
          }
          continue;
        }
        else if(ruleIndex == IrdlParser::RuleFunctionCall && this->isContextID(token)){
          if(!alreadyGotContextID){
            auto startToken = ruleCtx->start;
            QString path = QString::fromStdString(stream->getText(startToken,lastToken))
                .remove(QChar('\b')).remove(QChar('\t')).remove(QChar('\n')).remove(QChar('\r'))
                .remove(QChar('\\')).remove(QChar(' '));
            bool hasAssign = path.contains(QChar('('));
            if(hasAssign){
              path.remove(0,path.lastIndexOf(QChar('('))+1);
              path.remove(0,path.lastIndexOf(QChar(','))+1);
              QStringList pathList = path.split(QChar('.'));
              calcAttributes(pathList,_requirementProposals); //only happens when contextID is empty
              calcLiteralValues(_requirementProposals);
            }
            else{
              calcSignals(emptyCtx,_requirementProposals); //only happens when contextID is empty
            }
            alreadyGotContextID = true;
          }
          continue;
        }
        else if(ruleIndex == IrdlParser::RuleSendToStatement && this->isContextID(token)){
          if(!alreadyGotContextID){
            calcSignals(emptyCtx,_requirementProposals); //only happens when contextID is empty
            alreadyGotContextID = true;
          }
          continue;
        }
        else if(ruleIndex == IrdlParser::RuleMessageDecl && this->isContextID(token)){
          if(!alreadyGotContextID){
            auto mother = static_cast<IrdlParser::MessageDeclContext*>(ruleCtx);
            //find out if component paths already exist!
            if(!mother) continue;
            else if(mother->componentIdPath().size() == 2){
              calcSignals(emptyCtx,_requirementProposals); //only happens when contextID is empty
              calcLiteralValues(_requirementProposals);
            }
            else{
              calcComponents(emptyCtx,_requirementProposals); //only happens when contextID is empty
            }
            alreadyGotContextID = true;
          }
          continue;
        }
        else if(ruleIndex == IrdlParser::RuleCheckDecl && this->isContextID(token)){
          if(!alreadyGotContextID){
            auto mother = static_cast<IrdlParser::CheckDeclContext*>(ruleCtx);
            //find out if component paths already exist!
            if(!mother) continue;
            else if(mother->componentIdPath().size() == 2)
              calcSignals(emptyCtx,_requirementProposals); //only happens when contextID is empty
            else{
              calcComponents(emptyCtx,_requirementProposals); //only happens when contextID is empty
            }
            alreadyGotContextID = true;
          }
          continue;
        }
        else if(ruleIndex == IrdlParser::RuleAliasDef && this->isContextID(token)){
          if(!alreadyGotContextID){
            calcComponents(emptyCtx,_requirementProposals); //only happens when contextID is empty
            alreadyGotContextID = true;
          }
          continue;
        }
        else if(ruleIndex == IrdlParser::RuleLifelineList && this->isContextID(token)){
          if(!alreadyGotContextID){
            calcComponents(emptyCtx,_requirementProposals); //only happens when contextID is empty
            alreadyGotContextID = true;
          }
          continue;
        }
        else if(ruleIndex == IrdlParser::RuleLifelineListOptional && this->isContextID(token)){
          if(!alreadyGotContextID){
            calcComponents(emptyCtx,_requirementProposals); //only happens when contextID is empty
            alreadyGotContextID = true;
          }
          continue;
        }
        else if(ruleIndex == IrdlParser::RuleTimerDecl && this->isContextID(token)){
          if(!alreadyGotContextID){
            calcComponents(emptyCtx,_requirementProposals); //only happens when contextID is empty
            alreadyGotContextID = true;
          }
          continue;
        }
        else if(token == IrdlParser::ID)
          continue;//no contextID token as proposal
        else if(token == IrdlParser::MessageTrigger){
          if(_currentSignalItem && !(ruleIndex == IrdlParser::RuleAtom)){
            for(auto param : static_cast<const model::base::SignalItem*>(_currentSignalItem)->params()){
              addUniqueProposal(_requirementProposals,DslProposal(QString("%0.%1").arg(QString::fromStdString(vocabulary.getDisplayName(token)).trimmed().remove(QChar('\'')),
                                                                                       param->name()),Identifier));
            }
          }
          continue;
        }
        else if((ruleIndex == IrdlParser::RuleSignalDecl || ruleIndex == IrdlParser::RuleTypeDecl)
                && this->isContextID(token)){
          continue;//TODO: return custom types
        }
        else if(nonEssentialToken(token) || (ruleIndex == IrdlParser::RuleIntTypeDecl ||
                                             ruleIndex == IrdlParser::RuleRealTypeDecl))
          continue;

        QString displayName = QString::fromStdString(vocabulary.getDisplayName(token)).trimmed();
//        qDebug()<<"else - expected token name: "<<displayName;

        if(displayName.startsWith("'"))
          displayName.remove(0,1);
        if(displayName.endsWith("'"))
          displayName.remove(displayName.size()-1,1);
        if(displayName == "CheckID")
          addUniqueProposal(_requirementProposals,DslProposal("ReceiveMessage",requirementTokenType(token)));
        else if(displayName == "MessageID")
          addUniqueProposal(_requirementProposals,DslProposal("SendMessage",requirementTokenType(token)));
        else
          addUniqueProposal(_requirementProposals,DslProposal(displayName,requirementTokenType(token)));
      }
    }
    ///sort alphabetically
    qSort(_requirementProposals->begin(), _requirementProposals->end());
    return;
  }

  bool isContextID(int token)
  {
    if(isCommonContextID<IrdlParser>(token))
      return true;

    return (token == IrdlParser::TimeOutID
            || token == IrdlParser::SignalTransitionID
            || token == IrdlParser::TimeoutTransitionID
            || token == IrdlParser::ComponentID
            || token == IrdlParser::DeclarationID
            || token == IrdlParser::DescriptionID
            || token == IrdlParser::MilliSekID
            || token == IrdlParser::SekID
            || token == IrdlParser::ToID);
  }

  bool nonEssentialToken(std::size_t token){
    return (token == IrdlParser::ReturnID
            || token == IrdlParser::ThisID
            || token == IrdlParser::CaseID
            || token == IrdlParser::DefaultID
            || token == IrdlParser::IfID
            || token == IrdlParser::ElseID
            || token == IrdlParser::NotIdSymbol
            || token == IrdlParser::AndIdSymbol
            || token == IrdlParser::OrIdSymbol
            || token == IrdlParser::NotIdWord
            || token == IrdlParser::AndIdWord
            || token == IrdlParser::OrIdWord
            || token == IrdlParser::TrueID
            || token == IrdlParser::FalseID
            || token == IrdlParser::BREAK
            || token == IrdlParser::ASSIGN
            || token == IrdlParser::INT
            || token == IrdlParser::REAL
            || token == IrdlParser::STRING
            || token == IrdlParser::LPAREN
            || token == IrdlParser::RPAREN
            || token == IrdlParser::LBRACE
            || token == IrdlParser::RBRACE
            || token == IrdlParser::LBRACKET
            || token == IrdlParser::RBRACKET
            || token == IrdlParser::LESSTHAN
            || token == IrdlParser::GREATERTHAN
            || token == IrdlParser::COLON
            || token == IrdlParser::SEMI
            || token == IrdlParser::COMMA
            || token == IrdlParser::DOT
            || token == IrdlParser::PLUS
            || token == IrdlParser::MINUS
            || token == IrdlParser::MULT
            || token == IrdlParser::DIV
            || token == IrdlParser::PIPE
            || token == IrdlParser::REF
            || token == IrdlParser::CONST
            || token == IrdlParser::UNDER
            || token == IrdlParser::AtID);
  }

  void calcLiteralValues(DslProposalList* dslProposalList){
    for(auto types : _requirementDeclModel->dataTypes())
      for(auto literal : types->literals())
        addUniqueProposal(dslProposalList,DslProposal(literal,Literal));
  }

  void calcAttributes(QStringList path, DslProposalList* dslProposalList){
    uint8_t sz = path.size();
    if(sz && path.last() == QString("")) --sz;
    QString importModelStr;
    QString compStr;

    switch (sz) {
    case 2:
      importModelStr = path.at(0);
      if(const model::irdl::RequirementsModel* reqModel = _importModels.value(importModelStr)){
        compStr = path.at(1);
        if(const model::base::ComponentItem* comp = reqModel->component(compStr)){
          for(const model::base::AttributeItem* attribute : comp->attributes()){
            addUniqueProposal(dslProposalList,DslProposal(attribute->name(),Identifier));
          }
        }
      }
      break;
    case 1:
      compStr = path.at(0);
      if(const model::base::ComponentItem* comp = _requirementDeclModel->component(compStr)){
        for(const model::base::AttributeItem* attribute : comp->attributes()){
          addUniqueProposal(dslProposalList,DslProposal(attribute->name(),Identifier));
        }
      }
      if(const model::msc::MscComponentItem* comp = _requirementItems.value(compStr)){
        for(const model::base::AttributeItem* attribute : comp->attributes()){
          addUniqueProposal(dslProposalList,DslProposal(attribute->name(),Identifier));
        }
      }
      importModelStr = compStr;
      if(model::base::BaseModel* reqModel = _requirementDeclModel->importedModels().value(importModelStr)){
        for(const model::base::AttributeItem* attribute : reqModel->attributes()){
          addUniqueProposal(dslProposalList,DslProposal(attribute->name(),Identifier));
        }
      }
      if(model::irdl::RequirementsModel* reqModel = _importModels.value(importModelStr)){
        for(auto comp : reqModel->components()){
          for(const model::base::AttributeItem* attribute : comp->attributes()){
            addUniqueProposal(dslProposalList,DslProposal(QString("%0.%1").arg(comp->name(),attribute->name()),Identifier));
          }
        }
      }

      if(model::irdl::RequirementsModel* reqModel = _importModels.value(QString("this"))){
        for(const model::base::AttributeItem* attribute : reqModel->attributes()){
          addUniqueProposal(dslProposalList,DslProposal(QString("%0").arg(attribute->name()),Identifier));
        }
        for(auto comp : reqModel->components()){
          for(const model::base::AttributeItem* attribute : comp->attributes()){
            addUniqueProposal(dslProposalList,DslProposal(QString("%0.%1").arg(comp->name(),attribute->name()),Identifier));
          }
        }
      }

      if(_timerItems.contains(compStr))
        addUniqueProposal(_requirementProposals,DslProposal(QString("timeout()"),Identifier));
      return;
      break;
    case 0:
      for(const model::base::AttributeItem* attribute : _requirementDeclModel->attributes()){
        addUniqueProposal(dslProposalList,DslProposal(QString("%0").arg(attribute->name()),Identifier));
      }
      for(auto comp : _requirementDeclModel->components()){
        for(const model::base::AttributeItem* attribute : comp->attributes()){
          addUniqueProposal(dslProposalList,DslProposal(QString("%0.%1").arg(comp->name(),attribute->name()),Identifier));
        }
      }
      for(const model::msc::MscComponentItem* comp : _requirementItems.values()){
        for(const model::base::AttributeItem* attribute : comp->attributes()){
          addUniqueProposal(dslProposalList,DslProposal(QString("%0.%1").arg(
                                                          _requirementItems.key(comp),
                                                          attribute->name()),Identifier));
        }
      }
      for(auto reqModel : _importModels.values()){
        if(_importModels.key(reqModel) != QString("this")){
          for(auto comp : reqModel->components()){
            for(const model::base::AttributeItem* attribute : comp->attributes()){
              addUniqueProposal(dslProposalList,DslProposal(QString("%0.%1.%2").arg(_importModels.key(reqModel),comp->name(),attribute->name()),Identifier));
            }
          }
          for(const model::base::AttributeItem* attribute : reqModel->attributes()){
            addUniqueProposal(dslProposalList,DslProposal(QString("%0.%1").arg(_requirementDeclModel->importedModels().key(reqModel),attribute->name()),Identifier));
          }
        }
      }
      if(auto reqModel = _importModels.value(QString("this"))){
        for(auto comp : reqModel->components()){
          for(const model::base::AttributeItem* attribute : comp->attributes()){
            addUniqueProposal(dslProposalList,DslProposal(QString("%0.%1.%2").arg(_importModels.key(reqModel),comp->name(),attribute->name()),Identifier));
          }
        }
        for(const model::base::AttributeItem* attribute : reqModel->attributes()){
          addUniqueProposal(dslProposalList,DslProposal(QString("%0.%1").arg(_requirementDeclModel->importedModels().key(reqModel),attribute->name()),Identifier));
        }
      }
      for(auto reqModel : _requirementDeclModel->importedModels()){
        if(_requirementDeclModel->importedModels().key(reqModel) != QString("this"))
          for(const model::base::AttributeItem* attribute : reqModel->attributes()){
            addUniqueProposal(dslProposalList,DslProposal(QString("%0.%1").arg(_requirementDeclModel->importedModels().key(reqModel),attribute->name()),Identifier));
          }
      }
      if(auto reqModel = _requirementDeclModel->importedModels().value(QString("this"))){
        for(const model::base::AttributeItem* attribute : reqModel->attributes()){
          addUniqueProposal(dslProposalList,DslProposal(QString("%0").arg(attribute->name()),Identifier));
        }
      }
      return;
      break;
    default:
      return;
      break;
    }
  }

  void calcSignals(QStringList path, DslProposalList* dslProposalList){
    uint8_t sz = path.size();
    if(sz && path.last() == QString("")) --sz;
    QString compStr;

    switch (sz) {
    case 1:
      compStr = path.at(0);
      if(model::base::BaseModel* reqModel = _requirementDeclModel->importedModels().value(compStr)){
        for(const model::base::SignalItem* signal : reqModel->getSignals()){
          addUniqueProposal(dslProposalList,DslProposal(QString("%0").arg(signal->name()),Identifier));
        }
      }
      return;
      break;
    case 0:
      for(const model::base::SignalItem* signal : _requirementDeclModel->getSignals()){
        addUniqueProposal(dslProposalList,DslProposal(QString("%0").arg(signal->name()),Identifier));
      }
      for(model::base::BaseModel* reqModel : _requirementDeclModel->importedModels()){
        if(_requirementDeclModel->importedModels().key(reqModel) != QString("this"))
          for(const model::base::SignalItem* signal : reqModel->getSignals()){
            addUniqueProposal(dslProposalList,DslProposal(QString("%0.%1").arg(_requirementDeclModel->importedModels().key(reqModel),signal->name()),Identifier));
          }
      }
      if(model::base::BaseModel* reqModel = _requirementDeclModel->importedModels().value(QString("this"))){
        for(const model::base::SignalItem* signal : reqModel->getSignals()){
          addUniqueProposal(dslProposalList,DslProposal(QString("%0").arg(signal->name()),Identifier));
        }
      }
      return;
      break;
    default:
      return;
      break;
    }
  }

  void calcComponents(QStringList path, DslProposalList* dslProposalList){
    uint8_t sz = path.size();
    if(sz && path.last() == QString("")) --sz;
    QString compStr;
    QString reqStr;

    switch (sz) {
    case 2:
      reqStr = path.at(0);
      compStr = path.at(1);
      if(auto reqModel = _importModels.value(reqStr)){
        if(auto comp = reqModel->component(compStr)){
          for(auto port : comp->ports()){
            addUniqueProposal(dslProposalList,DslProposal(QString("%0").arg(port->name()),Identifier));
          }
        }
      }
      return;
      break;
    case 1:
      compStr = path.at(0);
      if(auto reqModel = _importModels.value(compStr)){
        for(auto comp : reqModel->components()){
          if(_importModels.key(reqModel) != QString("this"))
            addUniqueProposal(dslProposalList,DslProposal(QString("%0").arg(comp->name()),Identifier));
        }
      }
      if(auto comp = _requirementItems.value(compStr)){
        for(auto port : comp->ports()){
          addUniqueProposal(dslProposalList,DslProposal(QString("%0").arg(port->name()),Identifier));
        }
      }
      if(auto comp = _requirementDeclModel->component(compStr)){
        for(auto port : comp->ports()){
          addUniqueProposal(dslProposalList,DslProposal(QString("%0").arg(port->name()),Identifier));
        }
      }
      if(model::irdl::RequirementsModel* reqModel = _importModels.value(QString("this"))){
        for(auto comp : reqModel->components()){
          addUniqueProposal(dslProposalList,DslProposal(QString("%0").arg(comp->name()),Identifier));
        }
      }
      return;
      break;
    case 0:
      for(auto comp : _requirementDeclModel->components()){
        addUniqueProposal(dslProposalList,DslProposal(QString("%0").arg(comp->name()),Identifier));
      }
      for(auto reqModel : _importModels.values()){
        for(auto comp : reqModel->components()){
          if(_importModels.key(reqModel) != QString("this"))
            addUniqueProposal(dslProposalList,DslProposal(QString("%0.%1").arg(_importModels.key(reqModel),comp->name()),Identifier));
        }
      }
      if(model::irdl::RequirementsModel* reqModel = _importModels.value(QString("this"))){
        for(auto comp : reqModel->components()){
          addUniqueProposal(dslProposalList,DslProposal(QString("%0").arg(comp->name()),Identifier));
        }
      }
      for(auto compName : _requirementItems.keys()){
        addUniqueProposal(dslProposalList,DslProposal(QString("%0").arg(compName),Identifier));
      }
      return;
      break;
    default:
      return;
      break;
    }
  }

  void calcImportOptions(const QString& path, DslProposalList* dslProposalList){
    auto pathParts = path.split(QChar('/'));
    QDir homeDir(this->_praefix);
    QString curPath("");
    int sz2 = pathParts.size();
    int i = 0;
    bool test = true;

    while (i<sz2 && test) {
      test = homeDir.cd(pathParts.at(i));
      if(!test) curPath = pathParts.at(i); // get partString where error occurs
      i++;
    }

    int sz = curPath.size();
    QStringList list = homeDir.entryList();
    foreach (QString option, list) {
      QString test = option;
      test.resize(sz);
      if(test == curPath)
        addUniqueProposal(dslProposalList,DslProposal(option,Identifier));
    }
    if(!sz) addUniqueProposal(dslProposalList,DslProposal(QString(".."),Range));
  }

  void addUniqueProposal(DslProposalList* dslProposalList, DslProposal proposal){
    if(!dslProposalList->contains(proposal)) dslProposalList->append(proposal);
  }
};

class ComCreateIrdlProposals::Private
{
  friend class ComCreateIrdlProposals;

  QString             _irdlDocText;
  QString             _prefix;
  RequirementsModel*  _irdlModel;
  bool                _strictErrorHandling;
  DslProposalList     _irdlProposals;

  Private(const QString& irdlDocText,
          model::irdl::RequirementsModel* irdlModel,
          const QString& prefix,
          bool strictErrorHandling)
    : _irdlDocText(irdlDocText),
      _prefix(prefix),
      _irdlModel(irdlModel),
      _strictErrorHandling(strictErrorHandling)
  {}
  DslProposalList filterIrdlProposals(const QString& existingProposalText);
  bool executePrivate(QString* errorString);
};

DslProposalList ComCreateIrdlProposals::Private::filterIrdlProposals(const QString& existingProposalText)
{
  DslProposalList filterList;

  for(const DslProposal& currentIrdlProposal : this->_irdlProposals)
  {
    if(currentIrdlProposal.proposalText.startsWith(existingProposalText))
      filterList.append(currentIrdlProposal);
  }

  return filterList;
}

bool ComCreateIrdlProposals::Private::executePrivate(QString* errorString)
{
  RequirementsModel irdlDeclModel;
  ComBuildIrdlModel buildCommand(this->_irdlDocText, &irdlDeclModel,_prefix);
  buildCommand.execute();

  ANTLRInputStream input(this->_irdlDocText.toStdString());
  IrdlLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  IrdlParser parser(&tokens);

  if(isWithinComment<IrdlLexer>(this->_irdlDocText, tokens, errorString))
    return true; //is within comment -> no proposals

  parser.setBuildParseTree(false);
  parser.setErrorHandler(std::make_shared<DefaultErrorStrategy>());
  parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::LL);


  // calculating line and pos in line...
  QPair<std::size_t, int> linePos = utils::CalcPosInLine()(this->_irdlDocText);

  IrdlProposalErrorListener irdlProposalErrorListener(linePos.first,
                                                      linePos.second,
                                                      &this->_irdlProposals,
                                                      buildCommand.importItems(),
                                                      buildCommand.importModels(),
                                                      buildCommand.requirementCompItems(),
                                                      &irdlDeclModel,
                                                      buildCommand.currentSignalItem(),
                                                      buildCommand.currentPathItem(),
                                                      buildCommand.timerItems(),
                                                      _prefix);
  parser.removeErrorListeners();
  parser.addErrorListener(&irdlProposalErrorListener);

  auto start = std::chrono::steady_clock::now();
  try
  {
    parser.irdlDecl();
  }
  catch (RecognitionException& re)
  {
    AddPtrString(errorString)<<"RecognitionException: "<<re.what();
    AddPtrString(errorString) << "expected tokens: "<<re.getExpectedTokens().toString().c_str();

    if(this->_strictErrorHandling)
      return false;
  }
  catch (ParseCancellationException &pce)
  {
    AddPtrString(errorString)<<"ParseCancellationException: "<<pce.what();

    if(this->_strictErrorHandling)
      return false;
  }
  catch (std::exception& exc)
  {
    AddPtrString(errorString)<<"std::exception: "<<exc.what();

    if(this->_strictErrorHandling)
      return false;
  }

  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start);
  qDebug() << "Proposal time: " << duration.count() / 1000.0 << " ms";

  return true;
}

ComCreateIrdlProposals::ComCreateIrdlProposals(const QString& irdlDocText,
                                               const QString& prefix,
                                               model::irdl::RequirementsModel* irdlModel,
                                               bool strictErrorHandling,
                                               QObject *parent)
  : QObject(parent), _d(new Private(irdlDocText, irdlModel, prefix, strictErrorHandling))
{

}

ComCreateIrdlProposals::~ComCreateIrdlProposals()
{
  delete this->_d;
}

bool ComCreateIrdlProposals::execute(QString* errorString)
{
  //  qDebug() << "calculating proposals for: " << this->_d->_irdlDocText;

  // approach for removing last string (if available) for better proposal of contextID-rule
  QString lastWordAtEndOfDocText(QLatin1String(""));
  if(this->_d->_irdlDocText.size())
  {
    int currentIndex = this->_d->_irdlDocText.size()-1;
    QChar currentChar=this->_d->_irdlDocText.at(currentIndex);
    while (currentChar.isLetterOrNumber()
           || currentChar == QLatin1Char('_'))
    {
      lastWordAtEndOfDocText.prepend(currentChar);
      --currentIndex;
      if(currentIndex>=0)
        currentChar=this->_d->_irdlDocText.at(currentIndex);
      else
        currentChar=QChar();
    }
  }
//  qDebug()<<"lastWordAtEndOfDocText: "<<lastWordAtEndOfDocText;

  int lastWordSize = lastWordAtEndOfDocText.size();

  if(lastWordSize)
    this->_d->_irdlDocText.remove(this->_d->_irdlDocText.size()-lastWordSize,
                                  lastWordSize);

  bool result = this->_d->executePrivate(errorString);
  if(!result)
    return false;

  if(!lastWordSize)
    return true;

  DslProposalList filterProposalList = this->_d->filterIrdlProposals(lastWordAtEndOfDocText);
  if(filterProposalList.size()==0)
  {// without modifications
    this->_d->_irdlDocText.append(lastWordAtEndOfDocText);
    if(errorString)
      errorString->clear();
    this->_d->_irdlProposals.clear();

    return this->_d->executePrivate(errorString);
  }
  else if(filterProposalList.size()==1
          && filterProposalList.at(0).proposalText == lastWordAtEndOfDocText)
  {// without modifications
    this->_d->_irdlDocText.append(lastWordAtEndOfDocText);
    if(errorString)
      errorString->clear();
    this->_d->_irdlProposals.clear();

    return this->_d->executePrivate(errorString);
  }
  else
    this->_d->_irdlProposals = filterProposalList;

  return true;
}

const DslProposalList& ComCreateIrdlProposals::irdlProposals() const
{
  return this->_d->_irdlProposals;
}

} // namespace common
} // namespace dslparser
