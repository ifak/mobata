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

#include "comcreatetestcaseproposals.hpp"

#include "combuildtestcasemodel.hpp"

#include <mobata/model/ts/ts.hpp>

#include <mobata/utils/functors.hpp>

#include <QDebug>
#include <QDir>

#undef emit
#undef SIGNAL

#include <antlr4/antlr4-runtime.h>
#include "TestCaseDeclParser.h"
#include "TestCaseDeclLexer.h"
#include "TestCaseDeclBaseListener.h"
#include "testcasemodellistener.hpp"

#include <mobata/model/msc/mscstepitem.hpp>

#include <QList>

using namespace utils;
using namespace model;
using namespace model::ts;
using namespace model::base;
using namespace antlr4;

namespace dslparser {
namespace testcase {

class TestCaseProposalErrorListener
    : public BaseErrorListener
{
  std::size_t                         _line;
  std::size_t                         _posInLine;
  bool                                _inRecursivLoop = 0;
  QString                             _recursivRest = "";
  DslProposalList*                    _testCaseProposals;
  QHash<QString, ModelItem *>         _testCaseItems;
  TestCaseItem*                       _testCaseDeclModel;
  model::base::ModelItem*             _currentSignalItem;
  QPair<model::base::ModelItem*,int>  _currentPathItem;
  ImportModelItem                     _importItems;
  QString                             _praefix;

public:
  TestCaseProposalErrorListener(std::size_t line,
                                int posInLine,
                                DslProposalList* testcaseProposals,
                                const ImportModelItem& importItems,
                                QHash<QString, ModelItem *> testCaseItems,
                                TestCaseItem* TestCaseDeclModel = nullptr,
                                ModelItem* currentSignalItem = nullptr,
                                QPair<model::base::ModelItem*,int> currentPathItem = QPair<model::base::ModelItem*,int>(0,0),
                                const QString& praefix = "")
    : _line(line),
      _posInLine(posInLine),
      _testCaseProposals(testcaseProposals),
      _testCaseItems(testCaseItems),
      _testCaseDeclModel(TestCaseDeclModel),
      _currentSignalItem(currentSignalItem),
      _currentPathItem(currentPathItem),
      _importItems(importItems),
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
    Q_ASSERT(_testCaseProposals);
    Q_UNUSED(offendingSymbol);
    Q_UNUSED(msg);

    if(line != this->_line)
      return;

    if(charPositionInLine != this->_posInLine)
      return;

    TestCaseDeclParser* parser = static_cast<TestCaseDeclParser*>(recognizer);
    Q_ASSERT(parser);

    TokenStream* stream = parser->getTokenStream();
    Q_ASSERT(stream);

    ParserRuleContext* ruleCtx = parser->getRuleContext();
    Q_ASSERT(ruleCtx);
    std::size_t ruleIndex = ruleCtx->getRuleIndex();

    if(ruleIndex == TestCaseDeclParser::RuleContextID)
    {
      if(RuleContext* parentRuleCtx = dynamic_cast<RuleContext*>(ruleCtx->parent))
      {
        if(parentRuleCtx->getRuleIndex() == TestCaseDeclParser::RuleImportFileBody){
          RuleContext* greatParentRuleCtx = parentRuleCtx;
          do{
            parentRuleCtx = greatParentRuleCtx;
            greatParentRuleCtx =  dynamic_cast<RuleContext*>(greatParentRuleCtx->parent);
          }
          while(greatParentRuleCtx->getRuleIndex() != TestCaseDeclParser::RuleImportPathBody);

          TestCaseDeclParser::ImportFileBodyContext* idPathCtx = dynamic_cast<TestCaseDeclParser::ImportFileBodyContext*>(parentRuleCtx);
          Q_ASSERT(idPathCtx);
          QString pathStr = QString::fromStdString(stream->getText(misc::Interval(idPathCtx->getStart()->getTokenIndex(),stream->size()-1)));
          pathStr.remove('\r');
          pathStr.remove('\n');
          pathStr.remove(' ');
          pathStr.remove('\t');
          calcImportOptions(pathStr, _testCaseProposals);
        }
        else if(parentRuleCtx->getRuleIndex() == TestCaseDeclParser::RuleCheckDecl){ //TODO: must be corrected when import of .decl files is possible!
          for (auto curSignal : this->_testCaseDeclModel->getSignals()) {
            if(!_testCaseProposals->contains(DslProposal(curSignal->name(),Identifier)))
              addUniqueProposal(_testCaseProposals,DslProposal(curSignal->name(),Identifier));
          }
        }
        else if(parentRuleCtx->getRuleIndex() == TestCaseDeclParser::RuleIdPath){
          if(RuleContext* greatParentRuleCtx = dynamic_cast<RuleContext*>(parentRuleCtx->parent)){

            TestCaseDeclParser::IdPathContext* idPathCtx = dynamic_cast<TestCaseDeclParser::IdPathContext*>(parentRuleCtx);
            Q_ASSERT(idPathCtx);
            QString pathStr = QString::fromStdString(stream->getText(misc::Interval(idPathCtx->getStart()->getTokenIndex(),stream->size()-1)));
            pathStr.remove('\r');
            pathStr.remove('\n');
            pathStr.remove(' ');
            pathStr.remove('\t');
            if(greatParentRuleCtx->getRuleIndex() == TestCaseDeclParser::RuleAliasDef){
              addPossiblePaths(pathStr,
                               _testCaseProposals,
                               QList<PossibleModelClasses>({Any}));
            }
            else if(greatParentRuleCtx->getRuleIndex() == TestCaseDeclParser::RuleIdStatement){
              addPossiblePaths(pathStr,
                               _testCaseProposals,
                               QList<PossibleModelClasses>({AttributeItemModel}));
            }
            else if(greatParentRuleCtx->getRuleIndex() == TestCaseDeclParser::RuleMessageDecl ||
                    greatParentRuleCtx->getRuleIndex() == TestCaseDeclParser::RuleCheckDecl){
              addPossiblePaths(pathStr,
                               _testCaseProposals,
                               QList<PossibleModelClasses>({ComponentModel,PortModel}));
            }
            else if(greatParentRuleCtx->getRuleIndex() == TestCaseDeclParser::RuleTimerDecl){
              addPossiblePaths(pathStr,
                               _testCaseProposals,
                               QList<PossibleModelClasses>({ComponentModel}));
            }
            else if(greatParentRuleCtx->getRuleIndex() == TestCaseDeclParser::RuleFunctionCall){
              if(RuleContext* greatGreatParentRuleCtx = dynamic_cast<RuleContext*>(greatParentRuleCtx->parent))
              {
                if(greatGreatParentRuleCtx->getRuleIndex() == TestCaseDeclParser::RuleMessageDecl){
                  addPossiblePaths(pathStr,
                                   _testCaseProposals,
                                   QList<PossibleModelClasses>({SignalModel}));
                }
                else if(greatGreatParentRuleCtx->getRuleIndex() == TestCaseDeclParser::RuleIdStatement){
                  addPossiblePaths(pathStr,
                                   _testCaseProposals,
                                   QList<PossibleModelClasses>({TimerModel}));
                  QString defaultProp("defaultTimer.timeout()");
                  QString currentStr = pathStr;
                  QString test = defaultProp;
                  int sz = currentStr.size();
                  test.resize(sz);
                  if(test == currentStr)
                    addUniqueProposal(_testCaseProposals,DslProposal(defaultProp.remove(0,sz),Identifier));
                }
              }
            }
          }
        }
        else if(parentRuleCtx->getRuleIndex() == TestCaseDeclParser::RuleExpressionOptional)
        {
          if(RuleContext* greatParentRuleCtx = dynamic_cast<RuleContext*>(parentRuleCtx->parent)){
            if(auto expCtx = dynamic_cast<TestCaseDeclParser::ExpressionContext*>(greatParentRuleCtx)){
              if(expCtx->operation()
                 && expCtx->operation()->atom())
              {
                TestCaseDeclParser::AtomContext* idPathCtx = dynamic_cast<TestCaseDeclParser::AtomContext*>(expCtx->operation()->atom());
                Q_ASSERT(idPathCtx);
                QString pathStr = QString::fromStdString(stream->getText(misc::Interval(idPathCtx->getStart()->getTokenIndex(),stream->size()-1)));
                pathStr.remove('\r');
                pathStr.remove('\n');
                pathStr.remove(' ');
                pathStr.remove('\t');
                addPossiblePaths(pathStr,
                                 _testCaseProposals,
                                 QList<PossibleModelClasses>({AttributeItemModelInCheckItem}));
              }
            }
          }
        }
      }
    }
    else if(ruleIndex == TestCaseDeclParser::RuleAttributeName)
      CalcRefAttributesProposals(this->_testCaseDeclModel, _testCaseProposals)();
    else if(ruleIndex == TestCaseDeclParser::RuleIdPath){
      auto parentRuleCtx = ruleCtx;
      if(RuleContext* greatParentRuleCtx = dynamic_cast<RuleContext*>(parentRuleCtx->parent)){

        TestCaseDeclParser::IdPathContext* idPathCtx = dynamic_cast<TestCaseDeclParser::IdPathContext*>(parentRuleCtx);
        Q_ASSERT(idPathCtx);
        QString pathStr = QString::fromStdString(stream->getText(misc::Interval(idPathCtx->getStart()->getTokenIndex(),stream->size()-1)));
        pathStr.remove('\r');
        pathStr.remove('\n');
        pathStr.remove(' ');
        pathStr.remove('\t');
        if(greatParentRuleCtx->getRuleIndex() == TestCaseDeclParser::RuleAliasDef){
          addPossiblePaths(pathStr,
                           _testCaseProposals,QList<PossibleModelClasses>({Any}));
        }
        else if(greatParentRuleCtx->getRuleIndex() == TestCaseDeclParser::RuleIdStatement){
          addPossiblePaths(pathStr,
                           _testCaseProposals,
                           QList<PossibleModelClasses>({AttributeItemModel}));
        }
        else if(greatParentRuleCtx->getRuleIndex() == TestCaseDeclParser::RuleMessageDecl ||
                greatParentRuleCtx->getRuleIndex() == TestCaseDeclParser::RuleCheckDecl){
          addPossiblePaths(pathStr,
                           _testCaseProposals,
                           QList<PossibleModelClasses>({ComponentModel,PortModel}));
        }
        else if(greatParentRuleCtx->getRuleIndex() == TestCaseDeclParser::RuleTimerDecl){
          addPossiblePaths(pathStr,
                           _testCaseProposals,QList<PossibleModelClasses>({ComponentModel}));
        }
        else if(greatParentRuleCtx->getRuleIndex() == TestCaseDeclParser::RuleFunctionCall){
          if(RuleContext* greatGreatParentRuleCtx = dynamic_cast<RuleContext*>(greatParentRuleCtx->parent))
          {
            if(greatGreatParentRuleCtx->getRuleIndex() == TestCaseDeclParser::RuleMessageDecl){
              addPossiblePaths(pathStr,
                               _testCaseProposals,
                               QList<PossibleModelClasses>({SignalModel}));
            }
            else if(greatGreatParentRuleCtx->getRuleIndex() == TestCaseDeclParser::RuleIdStatement){
              addPossiblePaths(pathStr,
                               _testCaseProposals,
                               QList<PossibleModelClasses>({TimerModel}));
              QString defaultProp("defaultTimer.timeout()");
              QString currentStr = pathStr;
              QString test = defaultProp;
              int sz = currentStr.size();
              test.resize(sz);
              if(test == currentStr)
                addUniqueProposal(_testCaseProposals,DslProposal(defaultProp.remove(0,sz),Identifier));
            }
          }
        }
      }
    }
    else if(ruleIndex == TestCaseDeclParser::RuleImportFileBody){
      RuleContext* parentRuleCtx = ruleCtx;
      RuleContext* greatParentRuleCtx = parentRuleCtx;
      do{
        parentRuleCtx = greatParentRuleCtx;
        greatParentRuleCtx =  dynamic_cast<RuleContext*>(greatParentRuleCtx->parent);
        Q_ASSERT(greatParentRuleCtx);
      }
      while(greatParentRuleCtx->getRuleIndex() != TestCaseDeclParser::RuleImportPathBody);

      TestCaseDeclParser::ImportFileBodyContext* idPathCtx = dynamic_cast<TestCaseDeclParser::ImportFileBodyContext*>(parentRuleCtx);
      QString pathStr = QString::fromStdString(stream->getText(misc::Interval(idPathCtx->getStart()->getTokenIndex(),stream->size()-1)));
      pathStr.remove('\r');
      pathStr.remove('\n');
      pathStr.remove(' ');
      pathStr.remove('\t');
      calcImportOptions(pathStr, _testCaseProposals);
    }
    else
    {//keywords
      const dfa::Vocabulary& vocabulary = parser->getVocabulary();
      misc::IntervalSet expTokens = parser->getExpectedTokens();
      for (auto token : expTokens.toList())
      {
        if((ruleIndex == TestCaseDeclParser::RuleTypeDecl
            || ruleIndex == TestCaseDeclParser::RuleSignalDecl)
           && this->isContextID(token))
          continue;
        else if(token == TestCaseDeclParser::ID)
          continue;//no contextID token as proposal

        QString displayName = QString::fromStdString(vocabulary.getDisplayName(token)).trimmed();
        //        qDebug()<<"else - expected token name: "<<displayName;

        if(displayName.startsWith("'"))
          displayName.remove(0,1);
        if(displayName.endsWith("'"))
          displayName.remove(displayName.size()-1,1);

        if(canBeAutoCompleted(&displayName)){
          addUniqueProposal(_testCaseProposals,DslProposal(displayName,testCaseTokenType(token)));
        }
      }
    }
    ///sort alphabetically
    qSort(_testCaseProposals->begin(), _testCaseProposals->end());
    _inRecursivLoop = false;
    return;
  }

  bool isContextID(std::size_t token)
  {
    if(isCommonContextID<TestCaseDeclParser>(token))
      return true;

    return (token == TestCaseDeclParser::MessageID
            || token == TestCaseDeclParser::TimeOutID
            || token == TestCaseDeclParser::CheckID
            || token == TestCaseDeclParser::SignalTransitionID
            || token == TestCaseDeclParser::TimeoutTransitionID
            || token == TestCaseDeclParser::AltID
            || token == TestCaseDeclParser::TimerID
            || token == TestCaseDeclParser::ComponentID
            || token == TestCaseDeclParser::DeclarationID);
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
    if(!errorAtPos || !newPath.size())
    {
      QString thisStr("this");
      thisStr.resize(name.size());
      if(name == thisStr){
        addUniqueProposal(dslProposalList,DslProposal(QString("this").remove(0,name.size())  + QString("."),This));
      }
      for (auto option : this->_importItems.keys())
      {
        QString testStr = option;
        ModelItem* item = _importItems.value(option);
        testStr.resize(name.size());
        if(testStr == name)
          addProposalsFromModelItem(dslProposalList,name,listOfWanted,item,false,option);
      }

      for(auto option: this->_testCaseItems.keys()) {
        QString testStr = option;
        ModelItem* item = _testCaseItems.value(option);
        testStr.resize(name.size());
        if((testStr == name)){
          if((listOfWanted.contains(Any)))
            addUniqueProposal(dslProposalList, DslProposal(option.remove(0,name.size())));
          else if((listOfWanted.contains(ComponentModel) || listOfWanted.contains(PortModel))
                  && dynamic_cast<msc::MscComponentItem*>(item)){
            addUniqueProposal(dslProposalList, DslProposal(option.remove(0,name.size()) + QString(".")));
          }
          else if((listOfWanted.contains(AttributeItemModel))
                  && dynamic_cast<AttributeItem*>(item)){
            addUniqueProposal(dslProposalList, DslProposal(option.remove(0,name.size()) + QString(".")));
          }
          else if((listOfWanted.contains(AttributeItemModelInCheckItem))
                  && dynamic_cast<ParamItem*>(item)){
            addUniqueProposal(dslProposalList, DslProposal(option.remove(0,name.size()) + QString(".")));
          }
          else if((listOfWanted.contains(SignalModel))
                  && dynamic_cast<SignalItem*>(item)){
            addUniqueProposal(dslProposalList, DslProposal(option.remove(0,name.size()) + QString(".")));
          }
          else if((listOfWanted.contains(TimerModel))
                  && dynamic_cast<TimerItem*>(item)){
            addUniqueProposal(dslProposalList, DslProposal(option.remove(0,name.size()) + QString(".")));
          }
        }
      }

      addProposalsFromTestCaseItem(dslProposalList,name,listOfWanted,_testCaseDeclModel,false);
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

  void addProposalsFromModelItem(DslProposalList* dslProposalList,
                                 QString precurser,
                                 QList<PossibleModelClasses> listOfWanted,
                                 ModelItem* tItem,
                                 bool finished,
                                 QString option)
  {
    if(TestCaseItem* item = dynamic_cast<TestCaseItem*>(tItem))
    {
      if(addProposalsFromTestCaseItem(dslProposalList, precurser, listOfWanted, item,!finished) && !finished){
        //param "finished" indicates if ModelItem is already written
        //or if it needs to be proposed (consequently if it needs to
        //be proposed the children doesn't need to be proposed [yet])
        addUniqueProposal(dslProposalList,DslProposal(option.remove(0,precurser.size())
                                                      + (listOfWanted.contains(Any) ? QString("") : QString(".")),
                                                      Identifier));
      }
    }
    else if(SignalItem* item = dynamic_cast<SignalItem*>(tItem)){
      if(addProposalsFromSignalItem(dslProposalList, precurser, listOfWanted, item,!finished) && !finished){
        addUniqueProposal(dslProposalList,DslProposal(option.remove(0,precurser.size())
                                                      + (listOfWanted.contains(Any) ? QString("") : QString(".")),
                                                      Identifier));
      }
    }
    else if(TestSystemItem* item = dynamic_cast<TestSystemItem*>(tItem)){
      if(addProposalsFromTestSystemItem(dslProposalList, precurser, listOfWanted, item,!finished) && !finished){
        addUniqueProposal(dslProposalList,DslProposal(option.remove(0,precurser.size())
                                                      + (listOfWanted.contains(Any) ? QString("") : QString(".")),
                                                      Identifier));
      }
    }
    else if(TestComponentItem* item = dynamic_cast<TestComponentItem*>(tItem)){
      if(addProposalsFromTestComponentItem(dslProposalList, precurser, listOfWanted, item,!finished) && !finished){
        addUniqueProposal(dslProposalList,DslProposal(option.remove(0,precurser.size())
                                                      + (listOfWanted.contains(Any) ? QString("") : QString(".")),
                                                      Identifier));
      }
    }
    else if(SutItem* item = dynamic_cast<SutItem*>(tItem)){
      if(addProposalsFromSutItem(dslProposalList, precurser, listOfWanted, item,!finished) && !finished){
        addUniqueProposal(dslProposalList,DslProposal(option.remove(0,precurser.size())
                                                      + (listOfWanted.contains(Any) ? QString("") : QString(".")),
                                                      Identifier));
      }
    }
    else if(SutComponentItem* item = dynamic_cast<SutComponentItem*>(tItem)){
      if(addProposalsFromSutComponentItem(dslProposalList, precurser, listOfWanted, item,!finished) && !finished){
        addUniqueProposal(dslProposalList,DslProposal(option.remove(0,precurser.size())
                                                      + (listOfWanted.contains(Any) ? QString("") : QString(".")),
                                                      Identifier));
      }
    }
  }
  bool addProposalsFromTestCaseItem(DslProposalList* dslProposalList,QString precurser, QList<PossibleModelClasses> listOfWanted, TestCaseItem* item, bool finished){
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
  bool addProposalsFromSignalItem(DslProposalList* dslProposalList,QString precurser, QList<PossibleModelClasses> listOfWanted, SignalItem* item, bool finished){
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
  bool addProposalsFromTestSystemItem(DslProposalList* dslProposalList,QString precurser, QList<PossibleModelClasses> listOfWanted, TestSystemItem* item, bool finished){
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
    return false;
  }
  bool addProposalsFromTestComponentItem(DslProposalList* dslProposalList,QString precurser, QList<PossibleModelClasses> listOfWanted, TestComponentItem* item, bool finished){
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
  bool addProposalsFromSutItem(DslProposalList* dslProposalList,QString precurser, QList<PossibleModelClasses> listOfWanted, SutItem* item, bool finished){
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
    return false;
  }
  bool addProposalsFromSutComponentItem(DslProposalList* dslProposalList,QString precurser, QList<PossibleModelClasses> listOfWanted, SutComponentItem* item, bool finished){
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

class ComCreateTestCaseProposals::Private
{
  friend class ComCreateTestCaseProposals;

  QString               _testCaseDocText;
  QString               _praefix;
  bool                  _strictErrorHandling;
  DslProposalList       _testCaseProposals;

  Private(const QString& testCaseDocText,
          const QString& praefix,
          bool strictErrorHandling)
    : _testCaseDocText(testCaseDocText),
      _praefix(praefix),
      _strictErrorHandling(strictErrorHandling)
  {}

  DslProposalList  filterProposals(const QString& existingProposalText);
  bool             executePrivate(QString* errorString);
};

DslProposalList ComCreateTestCaseProposals::Private::filterProposals(const QString& existingProposalText)
{
  DslProposalList filterList;

  for(const DslProposal& currentProposal : this->_testCaseProposals)
  {
    if(currentProposal.proposalText.startsWith(existingProposalText))
      filterList.append(currentProposal);
  }

  return filterList;
}

bool ComCreateTestCaseProposals::Private::executePrivate(QString* errorString)
{
  TestSuite testSuiteModel;
  TestCaseItem* testcaseModel= testSuiteModel.addTestCase("test");
  Q_ASSERT(testcaseModel);

  ComBuildTestCaseModel buildCommand(this->_testCaseDocText,
                                     testcaseModel,
                                     this->_praefix);
  buildCommand.execute();

  ANTLRInputStream input(this->_testCaseDocText.toStdString());
  TestCaseDeclLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  TestCaseDeclParser parser(&tokens);

  if(isWithinComment<TestCaseDeclLexer>(this->_testCaseDocText, tokens, errorString))
    return true; //is within comment -> no proposals

  parser.setBuildParseTree(false);
  parser.setErrorHandler(std::make_shared<DefaultErrorStrategy>());
  parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::LL);


  // calculating line and pos in line...
  QPair<std::size_t, int> linePos = utils::CalcPosInLine()(this->_testCaseDocText);

  TestCaseProposalErrorListener testcaseProposalErrorListener(linePos.first,
                                                              linePos.second,
                                                              &this->_testCaseProposals,
                                                              buildCommand.importItems(),
                                                              buildCommand.testCaseItems(),
                                                              testcaseModel,
                                                              buildCommand.currentSignalItem(),
                                                              buildCommand.currentPathItem(),
                                                              this->_praefix);
  parser.removeErrorListeners();
  parser.addErrorListener(&testcaseProposalErrorListener);
  auto start = std::chrono::steady_clock::now();
  try
  {
    parser.testCaseDecl();
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

ComCreateTestCaseProposals::ComCreateTestCaseProposals(const QString& testCaseDocText,
                                                       const QString& praefix,
                                                       bool strictErrorHandling,
                                                       QObject* parent)
  : QObject(parent), _d(new Private(testCaseDocText, praefix, strictErrorHandling))
{}

ComCreateTestCaseProposals::~ComCreateTestCaseProposals()
{
  delete this->_d;
}

bool ComCreateTestCaseProposals::execute(QString* errorString)
{
  //  qDebug() << "calculating proposals for: " << this->_d->_TestCaseDocText;

  // approach for removing last string (if available) for better proposal of contextID-rule
  QString lastWordAtEndOfDocText(QLatin1String(""));
  if(this->_d->_testCaseDocText.size())
  {
    int currentIndex = this->_d->_testCaseDocText.size()-1;
    QChar currentChar=this->_d->_testCaseDocText.at(currentIndex);
    while (currentChar.isLetterOrNumber()
           || currentChar == QLatin1Char('_'))
    {
      lastWordAtEndOfDocText.prepend(currentChar);
      --currentIndex;
      if(currentIndex>=0)
        currentChar=this->_d->_testCaseDocText.at(currentIndex);
      else
        currentChar=QChar();
    }
  }
  //  qDebug()<<"lastWordAtEndOfDocText: "<<lastWordAtEndOfDocText;

  int lastWordSize = lastWordAtEndOfDocText.size();

  if(lastWordSize)
    this->_d->_testCaseDocText.remove(this->_d->_testCaseDocText.size()-lastWordSize,
                                      lastWordSize);

  bool result = this->_d->executePrivate(errorString);
  if(!result)
    return false;

  if(!lastWordSize)
    return true;

  DslProposalList filterProposalList = this->_d->filterProposals(lastWordAtEndOfDocText);
  if(filterProposalList.size()==0)
  {// without modifications
    this->_d->_testCaseDocText.append(lastWordAtEndOfDocText);
    if(errorString)
      errorString->clear();
    this->_d->_testCaseProposals.clear();

    return this->_d->executePrivate(errorString);
  }
  else if(filterProposalList.size()==1
          && filterProposalList.at(0).proposalText == lastWordAtEndOfDocText)
  {// without modifications
    this->_d->_testCaseDocText.append(lastWordAtEndOfDocText);
    if(errorString)
      errorString->clear();
    this->_d->_testCaseProposals.clear();

    return this->_d->executePrivate(errorString);
  }
  else
    this->_d->_testCaseProposals = filterProposalList;

  return true;
}

const DslProposalList &ComCreateTestCaseProposals::testCaseProposals() const
{
  return this->_d->_testCaseProposals;
}

} // namespace common
} // namespace dslparser
