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

#include "comcreateirdldeclproposals.hpp"

#include "combuildirdldeclmodel.hpp"

#include <mobata/model/irdl/requirementsmodel.hpp>
#include <mobata/model/irdl/reqactorcomponentitem.hpp>
#include <mobata/model/irdl/requirementitem.hpp>
#include <mobata/model/msc/msc_types.hpp>
#include <mobata/model/msc/msccomponentitem.hpp>
#include <mobata/model/msc/msctimeritem.hpp>

#include <mobata/utils/functors.hpp>

#include <QDebug>

#undef emit
#undef SIGNAL

#include <antlr4/antlr4-runtime.h>

#include "IrdlCommonDeclParser.h"
#include "IrdlCommonDeclLexer.h"
#include "IrdlCommonDeclBaseListener.h"

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
  bool                                _inRecursivLoop = 0;
  QString                             _recursivRest = "";
  DslProposalList*                    _requirementProposals;
  QHash<QString, model::msc::MscComponentItem *>         _requirementItems;
  RequirementsModel*                  _requirementDeclModel;
  model::base::ModelItem*             _currentSignalItem;
  QPair<model::base::ModelItem*,int>  _currentPathItem;
  ImportModelItem                     _importItems;
  ImportModel                         _importModels;
  QString                             _praefix;

  //  linePos.first,
  //    linePos.second,
  //    &this->_d->_requirementProposals,
  //    buildCommand.importItems(),
  //    buildCommand.importModels(),
  //    buildCommand.requirementItems(),
  //    IrdlCommonDeclModel,
  //    buildCommand.currentSignalItem(),
  //    buildCommand.currentPathItem(),
  //    this->_d->_prefix

public:
  IrdlProposalErrorListener(std::size_t line,
                            int posInLine,
                            DslProposalList* irdldeclProposals,
                            const ImportModelItem& importItems,
                            const ImportModel& importModels,
                            QHash<QString, model::msc::MscComponentItem *> requirementItems,
                            RequirementsModel* IrdlCommonDeclModel = 0,
                            ModelItem* currentSignalItem = 0,
                            QPair<model::base::ModelItem*,int> currentPathItem = QPair<model::base::ModelItem*,int>(0,0),
                            const QString& praefix = "")
    : _line(line),
      _posInLine(posInLine),
      _requirementProposals(irdldeclProposals),
      _requirementItems(requirementItems),
      _requirementDeclModel(IrdlCommonDeclModel),
      _currentSignalItem(currentSignalItem),
      _currentPathItem(currentPathItem),
      _importItems(importItems),
      _importModels(importModels),
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

    IrdlCommonDeclParser* parser = static_cast<IrdlCommonDeclParser*>(recognizer);
    Q_ASSERT(parser);

    ParserRuleContext* ruleCtx = parser->getRuleContext();
    Q_ASSERT(ruleCtx);
    std::size_t ruleIndex = ruleCtx->getRuleIndex();

    //<recursive>
    // THIS IS for completion of Tokens which are partly writen in Text and for that reason missidentified as ContextID
    // Thats why a new parsing without the partly written Token is needed!
    TokenStream* stream = parser->getTokenStream();
    int i = stream->size();
    if(i>2 && !_inRecursivLoop){
      Token* lastToken = stream->get(--i);
      while(i && (lastToken->getCharPositionInLine() != _posInLine || lastToken->getLine() !=_line))
        lastToken = stream->get(--i);
      if(i) lastToken = stream->get(--i);
      while(i &&
            (lastToken->getType() == IrdlCommonDeclParser::WS
             || lastToken->getType() == IrdlCommonDeclParser::NEWLINE
             || lastToken->getType() == IrdlCommonDeclParser::IGNORE_NEWLINE))
        lastToken = stream->get(--i);
      if(isContextID(lastToken->getType())){
        Token* endToken = stream->get(i-1);
        while(i &&
              (endToken->getType() == IrdlCommonDeclParser::WS
               || endToken->getType() == IrdlCommonDeclParser::NEWLINE
               || endToken->getType() == IrdlCommonDeclParser::IGNORE_NEWLINE))
          endToken = stream->get(--i);
        ANTLRInputStream input(stream->getText(stream->get(0),endToken));
        IrdlCommonDeclLexer lexer(&input);
        CommonTokenStream tokens(&lexer);
        IrdlCommonDeclParser parser(&tokens);
        parser.setBuildParseTree(false);
        parser.setErrorHandler(std::make_shared<DefaultErrorStrategy>());
        parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::LL);


        parser.removeErrorListeners();
        parser.addErrorListener(this);

        _line = endToken->getLine();
        _posInLine = endToken->getCharPositionInLine() + 1;
        _inRecursivLoop = true;
        _recursivRest += QString::fromStdString(lastToken->getText());
        parser.irdlCommonDecl();
        //didn't see a better solve...
      }
    }
    //</recursive>

    if(ruleIndex == IrdlCommonDeclParser::RuleContextID)
    {
      if(RuleContext* parentRuleCtx = dynamic_cast<RuleContext*>(ruleCtx->parent))
      {
        if(parentRuleCtx->getRuleIndex() == IrdlCommonDeclParser::RuleAttributeName)
          CalcRefAttributesProposals(this->_requirementDeclModel, _requirementProposals)();
        else if(parentRuleCtx->getRuleIndex() == IrdlCommonDeclParser::RuleImportFileBody){
          RuleContext* greatParentRuleCtx = parentRuleCtx;
          do{
            parentRuleCtx = greatParentRuleCtx;
            greatParentRuleCtx =  dynamic_cast<RuleContext*>(greatParentRuleCtx->parent);
          }
          while(greatParentRuleCtx->getRuleIndex() != IrdlCommonDeclParser::RuleImportPathBody);

          IrdlCommonDeclParser::ImportFileBodyContext* idPathCtx = dynamic_cast<IrdlCommonDeclParser::ImportFileBodyContext*>(parentRuleCtx);
          QString pathStr = QString::fromStdString(stream->getText(misc::Interval(idPathCtx->getStart()->getTokenIndex(),stream->size()-1)));
          pathStr.remove('\n');
          pathStr.remove(' ');
          pathStr.remove('\t');
          calcImportOptions(pathStr, _requirementProposals);
        }
        else if(parentRuleCtx->getRuleIndex() == IrdlCommonDeclParser::RuleIdPath){
          if(RuleContext* greatParentRuleCtx = dynamic_cast<RuleContext*>(parentRuleCtx->parent)){

            IrdlCommonDeclParser::IdPathContext* idPathCtx = dynamic_cast<IrdlCommonDeclParser::IdPathContext*>(parentRuleCtx);
            QString pathStr = QString::fromStdString(stream->getText(misc::Interval(idPathCtx->getStart()->getTokenIndex(),stream->size()-1)));
            pathStr.remove('\n');
            pathStr.remove(' ');
            pathStr.remove('\t');
            if(greatParentRuleCtx->getRuleIndex() == IrdlCommonDeclParser::RuleAliasDef){
              addPossiblePaths(pathStr,
                               _requirementProposals,QList<PossibleModelClasses>({Any}));
            }
            else if(greatParentRuleCtx->getRuleIndex() == IrdlCommonDeclParser::RuleMessageDecl ||
                    greatParentRuleCtx->getRuleIndex() == IrdlCommonDeclParser::RuleCheckDecl){
              addPossiblePaths(pathStr,
                               _requirementProposals,QList<PossibleModelClasses>({ComponentModel,PortModel}));
            }
            else if(greatParentRuleCtx->getRuleIndex() == IrdlCommonDeclParser::RuleTimerDecl){
              addPossiblePaths(pathStr,
                               _requirementProposals,QList<PossibleModelClasses>({ComponentModel}));
            }
            else if(greatParentRuleCtx->getRuleIndex() == IrdlCommonDeclParser::RuleFunctionCall){
              if(RuleContext* greatGreatParentRuleCtx = dynamic_cast<RuleContext*>(greatParentRuleCtx->parent))
              {
                if(greatGreatParentRuleCtx->getRuleIndex() == IrdlCommonDeclParser::RuleMessageDecl){
                  addPossiblePaths(pathStr,
                                   _requirementProposals,QList<PossibleModelClasses>({SignalModel}));
                }
              }
            }
          }
        }
        else if(parentRuleCtx->getRuleIndex() == IrdlCommonDeclParser::RuleCheckDecl){ //TODO: must be corrected when import of .decl files is possible!
          for(auto curSignal: this->_requirementDeclModel->getSignals()) {
            if(!_requirementProposals->contains(DslProposal(curSignal->name(),Identifier)))
              addUniqueProposal(_requirementProposals,DslProposal(curSignal->name(),Identifier));
          }
        }
        else if(parentRuleCtx->getRuleIndex() == IrdlCommonDeclParser::RuleExpressionOptional)
        {
          if(RuleContext* greatParentRuleCtx = dynamic_cast<RuleContext*>(parentRuleCtx->parent)){
            if(auto expCtx = dynamic_cast<IrdlCommonDeclParser::ExpressionContext*>(greatParentRuleCtx)){
              if(expCtx->operation()
                 && expCtx->operation()->atom())
              {
                IrdlCommonDeclParser::AtomContext* idPathCtx = dynamic_cast<IrdlCommonDeclParser::AtomContext*>(expCtx->operation()->atom());
                QString pathStr = QString::fromStdString(stream->getText(misc::Interval(idPathCtx->getStart()->getTokenIndex(),stream->size()-1)));
                pathStr.remove('\n');
                pathStr.remove(' ');
                pathStr.remove('\t');
                addPossiblePaths(pathStr,
                                 _requirementProposals,QList<PossibleModelClasses>({AttributeItemModelInCheckItem}));
              }
            }
          }
        }
      }
    }
    else if(ruleIndex == IrdlCommonDeclParser::RuleImportFileBody){
      RuleContext* parentRuleCtx = ruleCtx;
      RuleContext* greatParentRuleCtx = parentRuleCtx;
      do{
        parentRuleCtx = greatParentRuleCtx;
        greatParentRuleCtx =  dynamic_cast<RuleContext*>(greatParentRuleCtx->parent);
      }
      while(greatParentRuleCtx->getRuleIndex() != IrdlCommonDeclParser::RuleImportPathBody);

      IrdlCommonDeclParser::ImportFileBodyContext* idPathCtx = dynamic_cast<IrdlCommonDeclParser::ImportFileBodyContext*>(parentRuleCtx);
      QString pathStr = QString::fromStdString(stream->getText(misc::Interval(idPathCtx->getStart()->getTokenIndex(),stream->size()-1)));
      pathStr.remove('\n');
      pathStr.remove(' ');
      pathStr.remove('\t');
      calcImportOptions(pathStr, _requirementProposals);
    }
    else
    {//keywords
      const dfa::Vocabulary& vocabulary = parser->getVocabulary();
      misc::IntervalSet expTokens = parser->getExpectedTokens();
      for (auto token : expTokens.toList())
      {
        if((ruleIndex == IrdlCommonDeclParser::RuleTypeDecl
            || ruleIndex == IrdlCommonDeclParser::RuleSignalDecl)
           && this->isContextID(token))
          continue;
        else if(token == IrdlCommonDeclParser::ID)
          continue;//no contextID token as proposal

        QString displayName = QString::fromStdString(vocabulary.getDisplayName(token)).trimmed();
        //            qDebug()<<"else - expected token name: "<<displayName;

        if(displayName.startsWith("'"))
          displayName.remove(0,1);
        if(displayName.endsWith("'"))
          displayName.remove(displayName.size()-1,1);

        if(canBeAutoCompleted(&displayName)){
          addUniqueProposal(_requirementProposals,DslProposal(displayName,requirementTokenType(token)));
        }
      }
    }
    ///sort alphabetically
    qSort(_requirementProposals->begin(), _requirementProposals->end());
    _inRecursivLoop = false;
    return;
  }

  bool isContextID(std::size_t token)
  {
    if(isCommonContextID<IrdlCommonDeclParser>(token))
      return true;

    return (token == IrdlCommonDeclParser::MessageID
            || token == IrdlCommonDeclParser::TimeOutID
            || token == IrdlCommonDeclParser::CheckID
            || token == IrdlCommonDeclParser::SignalTransitionID
            || token == IrdlCommonDeclParser::TimeoutTransitionID
            || token == IrdlCommonDeclParser::AltID
            || token == IrdlCommonDeclParser::TimerID
            || token == IrdlCommonDeclParser::ComponentID
            || token == IrdlCommonDeclParser::DeclarationID);
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

    if((i < sz2  || _inRecursivLoop) && !test) return; // if error in middle of String

    if(_inRecursivLoop) curPath = _recursivRest;
    int sz = curPath.size();
    QStringList list = homeDir.entryList();
    for(QString option: list) {
      QString test = option;
      test.resize(sz);
      if(test == curPath)
        addUniqueProposal(dslProposalList,DslProposal(option.remove(0,sz),Identifier));
    }
    addUniqueProposal(dslProposalList,DslProposal(QString(".."),Range));
  }

  void addPossiblePaths(const QString& path, DslProposalList* dslProposalList, QList<PossibleModelClasses> listOfWanted){
    ModelItem* currentPathItem = _currentPathItem.first;
    int errorAtPos =_currentPathItem.second;
    //this->_d->_currentPathItem = mItem;
    QString newPath = _inRecursivLoop ? path + _recursivRest : path;
    QStringList pathList = newPath.split('.');
    QString name = pathList.last();
    if(!errorAtPos || !newPath.size()){
      QString thisStr("this");
      thisStr.resize(name.size());
      if(name == thisStr){
        addUniqueProposal(dslProposalList,DslProposal(QString("this").remove(0,name.size())  + QString("."),This));
      }
      for(auto option: this->_importItems.keys()) {
        QString testStr = option;
        ModelItem* item = _importItems.value(option);
        testStr.resize(name.size());
        if(testStr == name){
          addProposalsFromModelItem(dslProposalList,name,listOfWanted,item,false,option);
        }
      }

      for(auto option: this->_importModels.keys()) {
        QString testStr = option;
        RequirementsModel* item = _importModels.value(option);
        testStr.resize(name.size());
        if(testStr == name){
          if(addProposalsFromModel(dslProposalList,name,listOfWanted,item,true)){
            addUniqueProposal(dslProposalList, DslProposal(option.remove(0,name.size()) + QString(".")));
          }
        }
      }

      addProposalsFromModel(dslProposalList,name,listOfWanted,_requirementDeclModel,false);

      for(auto option: this->_requirementItems.keys()) {
        QString testStr = option;
        ModelItem* item = _requirementItems.value(option);
        testStr.resize(name.size());
        if((testStr == name)){
          if((listOfWanted.contains(Any)))
            addUniqueProposal(dslProposalList, DslProposal(option.remove(0,name.size())));
          else if((listOfWanted.contains(ComponentModel) || listOfWanted.contains(PortModel))
                  && dynamic_cast<MscComponentItem*>(item)){
            addUniqueProposal(dslProposalList, DslProposal(option.remove(0,name.size()) + QString(".")));
          }
          else if((listOfWanted.contains(AttributeItemModel))
                  && dynamic_cast<AttributeItem*>(item)){
            addUniqueProposal(dslProposalList, DslProposal(option.remove(0,name.size()) + QString(".")));
          }
          else if((listOfWanted.contains(AttributeItemModelInCheckItem))
                  && dynamic_cast<model::msc::ParamItem*>(item)){
            addUniqueProposal(dslProposalList, DslProposal(option.remove(0,name.size()) + QString(".")));
          }
          else if((listOfWanted.contains(SignalModel))
                  && dynamic_cast<model::msc::SignalItem*>(item)){
            addUniqueProposal(dslProposalList, DslProposal(option.remove(0,name.size()) + QString(".")));
          }
          else if((listOfWanted.contains(TimerModel))
                  && dynamic_cast<TimerItem*>(item)){
            addUniqueProposal(dslProposalList, DslProposal(option.remove(0,name.size()) + QString(".")));
          }
        }
      }
      for(RequirementItem* req: _requirementDeclModel->requirements()) {
        addProposalsFromRequirementItem(dslProposalList,name,listOfWanted,req,false);
      }

      return;
    } //if error is in first position
    else if(pathList.size()>errorAtPos+1) return; // error occurs before current position!
    else if(pathList.size()==errorAtPos+1){
      addProposalsFromModelItem(dslProposalList,name,listOfWanted,currentPathItem,true,QString(""));
    } //if error in current position
    else {
      addUniqueProposal(dslProposalList,DslProposal(QString("."),Dot));
    } // if path doesn't contains an error yet path needs to be continued to be semanticly correct
  }

  bool addProposalsFromModel(DslProposalList* dslProposalList,QString precurser, QList<PossibleModelClasses> listOfWanted, RequirementsModel* tItem, bool finished){
    auto components = tItem->components();
    int precSz = precurser.size();
    int sz = components.size();
    for(int i = 0;i<sz;i++){
      QString option = components.at(i)->name();
      QString testStr = option;
      testStr.resize(precSz);
      if(testStr == precurser){
        if(listOfWanted.contains(ComponentModel) ||
           listOfWanted.contains(Any)
           ){
          addUniqueProposal(dslProposalList,DslProposal(option.remove(0,precSz),Identifier));
        }
        if(listOfWanted.contains(PortModel)){
          if(finished) return true;
          else addUniqueProposal(dslProposalList,DslProposal(option.remove(0,precSz) + QString("."),Identifier));
        }
      }
    }
    auto attributes = tItem->attributes();
    int sz3 = attributes.size();
    for(int i = 0;i<sz3 ;i++){
      QString option(attributes.at(i)->name());
      QString testStr = option;
      testStr.resize(precurser.size());
      if(testStr == precurser){
        if(listOfWanted.contains(AttributeItemModel) ||
           listOfWanted.contains(AttributeItemModelInCheckItem)||
           listOfWanted.contains(Any)
           ){
          if(finished) return true;
          else addUniqueProposal(dslProposalList,DslProposal(option.remove(0,precSz),Identifier));
        }
      }
    }
    auto compSignals = tItem->getSignals();
    int sz2 = compSignals.size();
    for(int i = 0;i<sz2;i++){
      QString option = compSignals.at(i)->name();
      QString testStr = option;
      testStr.resize(precSz);
      if(testStr == precurser){
        if(listOfWanted.contains(SignalModel)||
           listOfWanted.contains(Any)
           ){
          if(finished) return true;
          else addUniqueProposal(dslProposalList,DslProposal(option.remove(0,precSz),Identifier));
        }
        if(compSignals.at(i)->params().size()
           && (listOfWanted.contains(AttributeItemModel) ||
               listOfWanted.contains(AttributeItemModelInCheckItem))
           ){
          if(finished) return true;
          else addUniqueProposal(dslProposalList,DslProposal(option.remove(0,precSz) + QString("."),Identifier));
        }
      }
    }
    return false;
  }
  void addProposalsFromModelItem(DslProposalList* dslProposalList,QString precurser, QList<PossibleModelClasses> listOfWanted, ModelItem* tItem, bool finished, QString option){
    if(RequirementItem* item = dynamic_cast<RequirementItem*>(tItem)){
      if(addProposalsFromRequirementItem(dslProposalList, precurser, listOfWanted, item,!finished) && !finished){
        //param "finished" indicates if ModelItem is already written
        //or if it needs to be proposed (consequently if it needs to
        //be proposed the children doesn't need to be proposed [yet])
        addUniqueProposal(dslProposalList,DslProposal(option.remove(0,precurser.size())
                                                      + (listOfWanted.contains(Any) ? QString("") : QString("."))
                                                      ,Identifier));
      }
    }
    else if(model::msc::SignalItem* item = dynamic_cast<model::msc::SignalItem*>(tItem)){
      if(addProposalsFromSignalItem(dslProposalList, precurser, listOfWanted, item,!finished) && !finished){
        addUniqueProposal(dslProposalList,DslProposal(option.remove(0,precurser.size())
                                                      + (listOfWanted.contains(Any) ? QString("") : QString("."))
                                                      ,Identifier));
      }
    }
    else if(MscComponentItem* item = dynamic_cast<MscComponentItem*>(tItem)){
      if(addProposalsFromMscComponentItem(dslProposalList, precurser, listOfWanted, item,!finished) && !finished){
        addUniqueProposal(dslProposalList,DslProposal(option.remove(0,precurser.size())
                                                      + (listOfWanted.contains(Any) ? QString("") : QString("."))
                                                      ,Identifier));
      }
    }
    else if(ReqActorComponentItem* item = dynamic_cast<ReqActorComponentItem*>(tItem)){
      if(addProposalsFromReqActorComponentItem(dslProposalList, precurser, listOfWanted, item,!finished) && !finished){
        addUniqueProposal(dslProposalList,DslProposal(option.remove(0,precurser.size())
                                                      + (listOfWanted.contains(Any) ? QString("") : QString("."))
                                                      ,Identifier));
      }
    }
  }
  bool addProposalsFromRequirementItem(DslProposalList* dslProposalList,QString precurser, QList<PossibleModelClasses> listOfWanted, RequirementItem* item, bool finished){
    auto components = item->componentItems();
    int precSz = precurser.size();
    int sz = components.size();
    for(int i = 0;i<sz;i++){
      QString option = components.at(i)->name();
      QString testStr = option;
      testStr.resize(precSz);
      if(testStr == precurser){
        if(listOfWanted.contains(ComponentModel) ||
           listOfWanted.contains(Any)
           ){
          if(finished) return true;
          else addUniqueProposal(dslProposalList,DslProposal(option.remove(0,precSz),Identifier));
        }
        if(listOfWanted.contains(PortModel)){
          if(finished) return true;
          else addUniqueProposal(dslProposalList,DslProposal(option.remove(0,precSz) + QString("."),Identifier));
        }
      }
    }

    //    auto actors = item->componentItems<model::requirement::ReqActorComponentItem>();
    //    int precSz = precurser.size();
    //    int szComp = actors.size();
    //    for(int i = 0;i<szComp;i++){
    //        QString option = actors.at(i)->name();
    //        QString testStr = option;
    //        testStr.resize(precSz);
    //        if(testStr == precurser){
    //            if(listOfWanted.contains(ComponentModel) ||
    //                    listOfWanted.contains(Any)
    //                    ){
    //                if(finished) return true;
    //                else addUniqueProposal(dslProposalList,DslProposal(option.remove(0,precSz),Identifier));
    //            }
    //            if(listOfWanted.contains(PortModel)){
    //                if(finished) return true;
    //                else addUniqueProposal(dslProposalList,DslProposal(option.remove(0,precSz) + QString("."),Identifier));
    //            }
    //        }
    //    }
    auto attributes = item->attributes();
    int sz3 = attributes.size();
    for(int i = 0;i<sz3 ;i++){
      QString option(attributes.at(i)->name());
      QString testStr = option;
      testStr.resize(precurser.size());
      if(testStr == precurser){
        if(listOfWanted.contains(AttributeItemModel) ||
           listOfWanted.contains(AttributeItemModelInCheckItem)||
           listOfWanted.contains(Any)
           ){
          if(finished) return true;
          else addUniqueProposal(dslProposalList,DslProposal(option.remove(0,precSz),Identifier));
        }
      }
    }
    auto compSignals = item->getSignals();
    int sz2 = compSignals.size();
    for(int i = 0;i<sz2;i++){
      QString option = compSignals.at(i)->name();
      QString testStr = option;
      testStr.resize(precSz);
      if(testStr == precurser){
        if(listOfWanted.contains(SignalModel)||
           listOfWanted.contains(Any)
           ){
          if(finished) return true;
          else addUniqueProposal(dslProposalList,DslProposal(option.remove(0,precSz),Identifier));
        }
        if(compSignals.at(i)->params().size()
           && (listOfWanted.contains(AttributeItemModel) ||
               listOfWanted.contains(AttributeItemModelInCheckItem))
           ){
          if(finished) return true;
          else addUniqueProposal(dslProposalList,DslProposal(option.remove(0,precSz) + QString("."),Identifier));
        }
      }
    }
    return false;
  }
  bool addProposalsFromRequirementModel(DslProposalList* dslProposalList,QString precurser, QList<PossibleModelClasses> listOfWanted, RequirementsModel* item, bool finished){
    auto components = item->components();
    int precSz = precurser.size();
    int sz = components.size();
    for(int i = 0;i<sz;i++){
      QString option = components.at(i)->name();
      QString testStr = option;
      testStr.resize(precSz);
      if(testStr == precurser){
        if(listOfWanted.contains(ComponentModel) ||
           listOfWanted.contains(Any)
           ){
          if(finished) return true;
          else addUniqueProposal(dslProposalList,DslProposal(option.remove(0,precSz),Identifier));
        }
        if(listOfWanted.contains(PortModel)){
          if(finished) return true;
          else addUniqueProposal(dslProposalList,DslProposal(option.remove(0,precSz) + QString("."),Identifier));
        }
      }
    }
    auto attributes = item->attributes();
    int sz3 = attributes.size();
    for(int i = 0;i<sz3 ;i++){
      QString option(attributes.at(i)->name());
      QString testStr = option;
      testStr.resize(precurser.size());
      if(testStr == precurser){
        if(listOfWanted.contains(AttributeItemModel) ||
           listOfWanted.contains(AttributeItemModelInCheckItem)||
           listOfWanted.contains(Any)
           ){
          if(finished) return true;
          else addUniqueProposal(dslProposalList,DslProposal(option.remove(0,precSz),Identifier));
        }
      }
    }
    auto compSignals = item->getSignals();
    int sz2 = compSignals.size();
    for(int i = 0;i<sz2;i++){
      QString option = compSignals.at(i)->name();
      QString testStr = option;
      testStr.resize(precSz);
      if(testStr == precurser){
        if(listOfWanted.contains(SignalModel)||
           listOfWanted.contains(Any)
           ){
          if(finished) return true;
          else addUniqueProposal(dslProposalList,DslProposal(option.remove(0,precSz),Identifier));
        }
        if(compSignals.at(i)->params().size()
           && (listOfWanted.contains(AttributeItemModel) ||
               listOfWanted.contains(AttributeItemModelInCheckItem))
           ){
          if(finished) return true;
          else addUniqueProposal(dslProposalList,DslProposal(option.remove(0,precSz) + QString("."),Identifier));
        }
      }
    }
    return false;
  }
  bool addProposalsFromSignalItem(DslProposalList* dslProposalList,QString precurser, QList<PossibleModelClasses> listOfWanted, model::msc::SignalItem* item, bool finished){
    auto attributes = item->params();
    int precSz = precurser.size();
    int sz2 = attributes.size();
    bool test = false;
    for(int i = 0;i<sz2 && !test;i++){
      QString option = attributes.at(i)->name();
      QString testStr = option;
      testStr.resize(precSz);
      if(testStr == precurser){
        if(listOfWanted.contains(AttributeItemModel)||
           listOfWanted.contains(AttributeItemModelInCheckItem)||
           listOfWanted.contains(Any)
           ){
          if(finished) return true;
          else addUniqueProposal(dslProposalList,DslProposal(option.remove(0,precSz),Identifier));
        }
      }
    }
    return false;
  }
  bool addProposalsFromMscComponentItem(DslProposalList* dslProposalList,QString precurser, QList<PossibleModelClasses> listOfWanted, MscComponentItem* item, bool finished){
    auto ports = item->ports();
    int precSz = precurser.size();
    int sz = ports.size();
    for(int i = 0;i<sz;i++){
      QString option = ports.at(i)->name();
      QString testStr = option;
      testStr.resize(precSz);
      if(testStr == precurser){
        if(listOfWanted.contains(PortModel)){
          if(finished) return true;
          else addUniqueProposal(dslProposalList,DslProposal(option.remove(0,precSz),Identifier));
        }
      }
    }
    return false;
  }
  bool addProposalsFromReqActorComponentItem(DslProposalList* dslProposalList,QString precurser, QList<PossibleModelClasses> listOfWanted, ReqActorComponentItem* item, bool finished){
    auto ports = item->ports();
    int precSz = precurser.size();
    int sz = ports.size();
    for(int i = 0;i<sz;i++){
      QString option = ports.at(i)->name();
      QString testStr = option;
      testStr.resize(precSz);
      if(testStr == precurser){
        if(listOfWanted.contains(PortModel)){
          if(precSz){
            if(finished) return true;
            else addUniqueProposal(dslProposalList,DslProposal(option.remove(0,precSz) + QString("."),Identifier));
          }
          else{
            if(finished) return true;
            else addUniqueProposal(dslProposalList,DslProposal(QString("."), Dot));
          }
        }
      }
    }
    return false;
  }

  void addUniqueProposal(DslProposalList* dslProposalList, DslProposal proposal){
    if(!dslProposalList->contains(proposal)) dslProposalList->append(proposal);
  }

  bool canBeAutoCompleted(QString* completionTarget){
    if(!_inRecursivLoop) return true;
    int q_sz = _recursivRest.size();
    QString test = *completionTarget;
    test.resize(q_sz);
    if(test != _recursivRest) return false;
    completionTarget->remove(0,q_sz);
    return completionTarget->size();
  }
};

class ComCreateIrdlDeclProposals::Private
{
  friend class ComCreateIrdlDeclProposals;

  QString                   _requirementDocText;
  QString                   _prefix;
  RequirementsModel*        _requirementModel;
  bool                      _strictErrorHandling;
  DslProposalList           _requirementProposals;

  Private(const QString& irdldeclDocText,
          model::irdl::RequirementsModel* irdldeclModel,
          const QString& prefix,
          bool strictErrorHandling)
    : _requirementDocText(irdldeclDocText),
      _prefix(prefix),
      _requirementModel(irdldeclModel),
      _strictErrorHandling(strictErrorHandling)
  {}
};

ComCreateIrdlDeclProposals::ComCreateIrdlDeclProposals(const QString& irdldeclDocText,
                                                       model::irdl::RequirementsModel* irdldeclModel,
                                                       QString prefix,
                                                       bool strictErrorHandling,
                                                       QObject *parent)
  : QObject(parent), _d(new Private(irdldeclDocText, irdldeclModel, prefix, strictErrorHandling))
{

}

ComCreateIrdlDeclProposals::~ComCreateIrdlDeclProposals()
{
  delete this->_d;
}

bool ComCreateIrdlDeclProposals::execute(QString* errorString)
{
  //  qDebug() << "calculating proposals for: " << this->_d->_irdldeclDocText;

  RequirementsModel IrdlCommonDeclModel;
  ComBuildIrdlDeclModel buildCommand(this->_d->_requirementDocText, &IrdlCommonDeclModel);
  buildCommand.execute();

  ANTLRInputStream input(this->_d->_requirementDocText.toStdString());
  IrdlCommonDeclLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  IrdlCommonDeclParser parser(&tokens);

  if(isWithinComment<IrdlCommonDeclLexer>(this->_d->_requirementDocText, tokens, errorString))
    return true; //is within comment -> no proposals

  parser.setBuildParseTree(false);
  parser.setErrorHandler(std::make_shared<DefaultErrorStrategy>());
  parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::LL);


  // calculating line and pos in line...
  QPair<std::size_t, int> linePos = utils::CalcPosInLine()(this->_d->_requirementDocText);

  IrdlProposalErrorListener irdldeclProposalErrorListener(linePos.first,
                                                          linePos.second,
                                                          &this->_d->_requirementProposals,
                                                          buildCommand.importItems(),
                                                          buildCommand.importModels(),
                                                          buildCommand.requirementCompItems(),
                                                          &IrdlCommonDeclModel,
                                                          buildCommand.currentSignalItem(),
                                                          buildCommand.currentPathItem(),
                                                          this->_d->_prefix);
  parser.removeErrorListeners();
  parser.addErrorListener(&irdldeclProposalErrorListener);

  auto start = std::chrono::steady_clock::now();
  try
  {
    parser.irdlCommonDecl();
  }
  catch (RecognitionException& re)
  {
    AddPtrString(errorString)<<"RecognitionException: "<<re.what();
    AddPtrString(errorString) << "expected tokens: "<<re.getExpectedTokens().toString().c_str();

    if(this->_d->_strictErrorHandling)
      return false;
  }
  catch (ParseCancellationException &pce)
  {
    AddPtrString(errorString)<<"ParseCancellationException: "<<pce.what();

    if(this->_d->_strictErrorHandling)
      return false;
  }
  catch (std::exception& exc)
  {
    AddPtrString(errorString)<<"std::exception: "<<exc.what();

    if(this->_d->_strictErrorHandling)
      return false;
  }

  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start);
  qDebug() << "Proposal time: " << duration.count() / 1000.0 << " ms";

  return true;
}

const DslProposalList& ComCreateIrdlDeclProposals::irdldeclProposals() const
{
  return this->_d->_requirementProposals;
}

} // namespace common
} // namespace dslparser
