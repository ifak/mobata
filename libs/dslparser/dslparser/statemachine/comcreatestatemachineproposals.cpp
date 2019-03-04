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

#include "comcreatestatemachineproposals.hpp"

#include "combuildstatemachinemodel.hpp"

#include <mobata/model/statemachine/statemachinemodel.hpp>
#include <mobata/model/statemachine/abstractstateitem.hpp>
#include <mobata/model/statemachine/transitionitem.hpp>
#include <mobata/model/base/attributeitem.hpp>
#include <mobata/model/base/signalitem.hpp>
#include <mobata/model/base/portitem.hpp>
#include <mobata/model/base/datatypeitem.hpp>
#include <mobata/model/base/propdatatypes.hpp>
#include <mobata/model/base/functionitem.hpp>
#include <QDir>

#include <mobata/utils/functors.hpp>

#include <QDebug>

#undef emit
#undef SIGNAL

#include <antlr4/antlr4-runtime.h>

#include "StateMachineParser.h"
#include "StateMachineLexer.h"
#include "StateMachineBaseListener.h"

using namespace utils;
using namespace model::statemachine;
using namespace antlr4;

namespace dslparser {
namespace statemachine {

class StateMachineProposalErrorListener
    : public BaseErrorListener
{
  std::size_t                             _line;
  std::size_t                             _posInLine;
  DslProposalList*                        _stateMachineProposals;
  StateMachineModel*                      _stateMachineDeclModel;
  const model::base::ModelItem*           _currentSignalItem;
  model::statemachine::AbstractStateItem* _currentStateItem;

public:
  StateMachineProposalErrorListener(std::size_t line,
                                    int posInLine,
                                    DslProposalList* statemachineProposals,
                                    StateMachineModel* statemachineDeclModel = nullptr,
                                    model::base::ModelItem const*  currentSignalItem = nullptr,
                                    model::statemachine::AbstractStateItem* currentStateItem = nullptr)
    : _line(line),
      _posInLine(posInLine),
      _stateMachineProposals(statemachineProposals),
      _stateMachineDeclModel(statemachineDeclModel),
      _currentSignalItem(currentSignalItem),
      _currentStateItem(currentStateItem)

  {}

protected:
  virtual void syntaxError(Recognizer* recognizer,
                           Token* offendingSymbol,
                           size_t line,
                           std::size_t charPositionInLine,
                           const std::string &msg,
                           std::exception_ptr /*e*/) override
  {
    Q_ASSERT(this->_stateMachineProposals);
    Q_UNUSED(offendingSymbol);
    Q_UNUSED(msg);

    if(line != this->_line)
      return;

    if(charPositionInLine != this->_posInLine)
      return;

    StateMachineParser* parser = static_cast<StateMachineParser*>(recognizer);
    Q_ASSERT(parser);

    ParserRuleContext* ruleCtx = parser->getRuleContext();
    Q_ASSERT(ruleCtx);
    std::size_t ruleIndex = ruleCtx->getRuleIndex();

    TokenStream* stream = parser->getTokenStream();
    Token* lastToken = stream->get(stream->size()-1);

    if(ruleIndex == StateMachineParser::RuleContextID)
    {
      if(RuleContext* parentRuleCtx = dynamic_cast<RuleContext*>(ruleCtx->parent))
      {
        if(parentRuleCtx->getRuleIndex() == StateMachineParser::RuleAttributeName)
          CalcRefAttributesProposals(this->_stateMachineDeclModel, _stateMachineProposals)();
        else if(parentRuleCtx->getRuleIndex() == StateMachineParser::RuleAttributeIdPath)
        {
          auto mother = static_cast<StateMachineParser::AttributeIdPathContext*>(parentRuleCtx);
          if(mother && !mother->exception)
          {
            QStringList path = QString::fromStdString(stream->getText(mother->start,lastToken))
                .remove(QChar('\b')).remove(QChar('\t')).remove(QChar('\n')).remove(QChar('\r'))
                .remove(QChar('\\')).remove(QChar(' ')).split(QChar('.'));
            this->calcAttributes(path,_stateMachineProposals);
          }
        }
        else if(parentRuleCtx->getRuleIndex() == StateMachineParser::RuleSignalIdPath)
        {
          auto mother = static_cast<StateMachineParser::SignalIdPathContext*>(parentRuleCtx);
          if(mother && !mother->exception)
          {
            QStringList path = QString::fromStdString(stream->getText(mother->start,lastToken))
                .remove(QChar('\b')).remove(QChar('\t')).remove(QChar('\n')).remove(QChar('\r'))
                .remove(QChar('\\')).remove(QChar(' ')).split(QChar('.'));
            this->calcSignals(path,_stateMachineProposals);
          }
        }
        else if(parentRuleCtx->getRuleIndex() == StateMachineParser::RuleStateIdPath)
        {
          auto mother = static_cast<StateMachineParser::StateIdPathContext*>(parentRuleCtx);
          if(mother && !mother->exception)
            this->calcStateProposals(_currentStateItem);
        }
        else if(parentRuleCtx->getRuleIndex() == StateMachineParser::RuleToPortName)
        {
          auto mother = static_cast<StateMachineParser::ToPortNameContext*>(parentRuleCtx);
          if(mother && !mother->exception)
          {
            for(model::base::PortItem* item : _stateMachineDeclModel->ports())
              this->addUniqueProposal(_stateMachineProposals,DslProposal(item->name(),Identifier));
          }
        }
        else if(parentRuleCtx->getRuleIndex() == StateMachineParser::RuleSignalParamName)
        {
          if(_currentSignalItem)
          {
            for(auto param : static_cast<const model::base::SignalItem*>(_currentSignalItem)->params())
              addUniqueProposal(_stateMachineProposals,DslProposal(param->name(),Identifier));
          }
        }
      }
    }
    else
    {//keywords
      const dfa::Vocabulary& vocabulary = parser->getVocabulary();
      misc::IntervalSet expTokens = parser->getExpectedTokens();
      QStringList emptyCtx = {};
      bool alreadyGotContextID = false;
      for (auto token : expTokens.toList())
      {
        if(ruleIndex == StateMachineParser::RuleAtom && this->isContextID(token)){
          if(!alreadyGotContextID){
            QStringList path = QString::fromStdString(stream->getText(ruleCtx->start,lastToken))
                .remove(QChar('\b')).remove(QChar('\t')).remove(QChar('\n')).remove(QChar('\r'))
                .remove(QChar('\\')).remove(QChar(' ')).split(QChar('.'));
            calcAttributes(path,_stateMachineProposals);
            if(path.size()<2) calcLiteralValues(_stateMachineProposals);
            alreadyGotContextID = true;
          }
          continue;
        }
        else if(ruleIndex == StateMachineParser::RuleAttributeAssignStatement && this->isContextID(token)){
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
                  addUniqueProposal(_stateMachineProposals,DslProposal(param->name(),Identifier));
                }
              }
              calcLiteralValues(_stateMachineProposals);
            }
            QStringList pathList = path.split(QChar('.'));
            calcAttributes(pathList,_stateMachineProposals);
            alreadyGotContextID = true;
          }
          continue;
        }
        else if(ruleIndex == StateMachineParser::RuleLiteralValue && this->isContextID(token)){
          if(!alreadyGotContextID){
            calcLiteralValues(_stateMachineProposals);
            alreadyGotContextID = true;
          }

          continue;
        }
        else if(ruleIndex == StateMachineParser::RuleFunctionCallBody && this->isContextID(token)){
          if(!alreadyGotContextID){
            QStringList path = QString::fromStdString(stream->getText(ruleCtx->start,lastToken))
                .remove(QChar('\b')).remove(QChar('\t')).remove(QChar('\n')).remove(QChar('\r'))
                .remove(QChar('\\')).remove(QChar(' ')).split(QChar('.'));
            calcAttributes(path,_stateMachineProposals);
            if(path.size()<2) calcLiteralValues(_stateMachineProposals);
            if(_currentSignalItem){
              for(auto param : static_cast<const SignalItem*>(_currentSignalItem)->params())
                addUniqueProposal(_stateMachineProposals,DslProposal(QString("msg.%0").arg(param->name()),Identifier));
            }
            alreadyGotContextID = true;
          }
          continue;
        }
        else if(ruleIndex == StateMachineParser::RuleActionDecl && this->isContextID(token)){
          if(!alreadyGotContextID){
            QStringList path = QString::fromStdString(stream->getText(ruleCtx->start,lastToken))
                .remove(QChar('\b')).remove(QChar('\t')).remove(QChar('\n')).remove(QChar('\r'))
                .remove(QChar('\\')).remove(QChar(' ')).split(QChar('.'));
            calcAttributes(path,_stateMachineProposals);
            for(FunctionItem* func : _stateMachineDeclModel->functions()){
              addUniqueProposal(_stateMachineProposals,DslProposal(func->name(),Identifier));
            }
            alreadyGotContextID = true;
          }
          continue;
        }
        else if(ruleIndex == StateMachineParser::RuleExpression && this->isContextID(token)){
          if(!alreadyGotContextID){
            QStringList path = QString::fromStdString(stream->getText(ruleCtx->start,lastToken))
                .remove(QChar('\b')).remove(QChar('\t')).remove(QChar('\n')).remove(QChar('\r'))
                .remove(QChar('\\')).remove(QChar(' ')).split(QChar('.'));
            calcAttributes(path,_stateMachineProposals);
            if(_currentSignalItem){
              for(auto param : static_cast<const model::base::SignalItem*>(_currentSignalItem)->params()){
                addUniqueProposal(_stateMachineProposals,DslProposal(QString("msg.%0").arg(param->name()),Identifier));
              }
            }
            if(path.size()<2) calcLiteralValues(_stateMachineProposals);
            alreadyGotContextID = true;
          }
          continue;
        }
        else if(ruleIndex == StateMachineParser::RuleOperation && this->isContextID(token)){
          if(!alreadyGotContextID){
            QStringList path = QString::fromStdString(stream->getText(ruleCtx->start,lastToken))
                .remove(QChar('\b')).remove(QChar('\t')).remove(QChar('\n')).remove(QChar('\r'))
                .remove(QChar('\\')).remove(QChar(' ')).split(QChar('.'));
            calcAttributes(path,_stateMachineProposals);
            if(_currentSignalItem){
              for(auto param : static_cast<const model::base::SignalItem*>(_currentSignalItem)->params()){
                addUniqueProposal(_stateMachineProposals,DslProposal(QString("msg.%0").arg(param->name()),Identifier));
              }
            }
            if(path.size()<2) calcLiteralValues(_stateMachineProposals);
            alreadyGotContextID = true;
          }
          continue;
        }
        else if(ruleIndex == StateMachineParser::RuleExpressionOptional && this->isContextID(token)){
          if(!alreadyGotContextID){
            calcAttributes(emptyCtx,_stateMachineProposals);
            calcLiteralValues(_stateMachineProposals);
            alreadyGotContextID = true;
          }
          continue;
        }
        else if(ruleIndex == StateMachineParser::RuleAttributeAssignStatement && this->isContextID(token)){
          if(!alreadyGotContextID){
            QStringList path = QString::fromStdString(stream->getText(ruleCtx->start,lastToken))
                .remove(QChar('\b')).remove(QChar('\t')).remove(QChar('\n')).remove(QChar('\r'))
                .remove(QChar('\\')).remove(QChar(' ')).split(QChar('.'));
            calcAttributes(path,_stateMachineProposals);
            if(path.size()<2) calcLiteralValues(_stateMachineProposals);
            alreadyGotContextID = true;
          }
          continue;
        }
        else if(ruleIndex == StateMachineParser::RuleFunctionCall && this->isContextID(token)){
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
              calcAttributes(pathList,_stateMachineProposals); //only happens when contextID is empty
              calcLiteralValues(_stateMachineProposals);
            }
            else{
              calcSignals(emptyCtx,_stateMachineProposals); //only happens when contextID is empty
            }
            alreadyGotContextID = true;
          }
          continue;
        }
        else if(ruleIndex == StateMachineParser::RuleSendToStatement && this->isContextID(token)){
          if(!alreadyGotContextID){
            calcSignals(emptyCtx,_stateMachineProposals); //only happens when contextID is empty
            alreadyGotContextID = true;
          }
          continue;
        }
        else if(token == StateMachineParser::ID)
          continue;//no contextID token as proposal
        else if(token == StateMachineParser::MessageTrigger){
          if(_currentSignalItem && !(ruleIndex == StateMachineParser::RuleAtom)){
            for(auto param : static_cast<const model::base::SignalItem*>(_currentSignalItem)->params()){
              addUniqueProposal(_stateMachineProposals,DslProposal(QString("%0.%1").arg(QString::fromStdString(vocabulary.getDisplayName(token)).trimmed().remove(QChar('\'')),
                                                                                       param->name()),Identifier));
            }
          }
          continue;
        }
        else if((ruleIndex == StateMachineParser::RuleSignalDecl || ruleIndex == StateMachineParser::RuleTypeDecl)
                && this->isContextID(token)){
          continue;//TODO: return custom types
        }
        else if(nonEssentialToken(token) || (ruleIndex == StateMachineParser::RuleIntTypeDecl ||
                                             ruleIndex == StateMachineParser::RuleRealTypeDecl))
          continue;

        QString displayName = QString::fromStdString(vocabulary.getDisplayName(token)).trimmed();
//        qDebug()<<"else - expected token name: "<<displayName;

        if(displayName.startsWith("'"))
          displayName.remove(0,1);
        if(displayName.endsWith("'"))
          displayName.remove(displayName.size()-1,1);

        addUniqueProposal(_stateMachineProposals,DslProposal(displayName,requirementTokenType(token)));
      }
    }
    ///sort alphabetically
    qSort(_stateMachineProposals->begin(), _stateMachineProposals->end());
    return;
  }

  bool isContextID(std::size_t token)
  {
    if(isCommonContextID<StateMachineParser>(token))
      return true;

    return (token == StateMachineParser::ValueID
            || token == StateMachineParser::GuardID
            || token == StateMachineParser::RegionID
            || token == StateMachineParser::SourceStateID
            || token == StateMachineParser::TargetStateID);
  }



  bool nonEssentialToken(std::size_t token){
    return (token == StateMachineParser::ReturnID
            || token == StateMachineParser::ThisID
            || token == StateMachineParser::CaseID
            || token == StateMachineParser::SwitchID
            || token == StateMachineParser::DefaultID
            || token == StateMachineParser::IfID
            || token == StateMachineParser::ElseID
            || token == StateMachineParser::NotIdSymbol
            || token == StateMachineParser::AndIdSymbol
            || token == StateMachineParser::OrIdSymbol
            || token == StateMachineParser::NotIdWord
            || token == StateMachineParser::AndIdWord
            || token == StateMachineParser::OrIdWord
            || token == StateMachineParser::TrueID
            || token == StateMachineParser::FalseID
            || token == StateMachineParser::BREAK
            || token == StateMachineParser::ASSIGN
            || token == StateMachineParser::INT
            || token == StateMachineParser::REAL
            || token == StateMachineParser::STRING
            || token == StateMachineParser::LPAREN
            || token == StateMachineParser::RPAREN
            || token == StateMachineParser::LBRACE
            || token == StateMachineParser::RBRACE
            || token == StateMachineParser::LBRACKET
            || token == StateMachineParser::RBRACKET
            || token == StateMachineParser::LESSTHAN
            || token == StateMachineParser::GREATERTHAN
            || token == StateMachineParser::COLON
            || token == StateMachineParser::SEMI
            || token == StateMachineParser::COMMA
            || token == StateMachineParser::DOT
            || token == StateMachineParser::PLUS
            || token == StateMachineParser::MINUS
            || token == StateMachineParser::MULT
            || token == StateMachineParser::DIV
            || token == StateMachineParser::PIPE
            || token == StateMachineParser::REF
            || token == StateMachineParser::CONST
            || token == StateMachineParser::UNDER
            || token == StateMachineParser::AtID);
  }

  void calcLiteralValues(DslProposalList* dslProposalList){
    for(auto types : _stateMachineDeclModel->dataTypes())
      for(auto literal : types->literals())
        addUniqueProposal(dslProposalList,DslProposal(literal,Literal));
  }

  void calcAttributes(QStringList path, DslProposalList* dslProposalList){
    uint8_t sz = path.size();
    if(sz && path.last() == QString("")) --sz;
    QString importModelStr;
    QString compStr;

    switch (sz) {
    case 1:
      return;
      break;
    case 0:
      for(const model::base::AttributeItem* attribute : _stateMachineDeclModel->attributes()){
        addUniqueProposal(dslProposalList,DslProposal(QString("%0").arg(attribute->name()),Identifier));
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

    switch (sz) {
    case 1:
      return;
      break;
    case 0:
      for(const model::base::SignalItem* signal : _stateMachineDeclModel->getSignals()){
        addUniqueProposal(dslProposalList,DslProposal(QString("%0").arg(signal->name()),Identifier));
      }
      return;
      break;
    default:
      return;
      break;
    }
  }

  void addUniqueProposal(DslProposalList* dslProposalList, DslProposal proposal){
    if(!dslProposalList->contains(proposal)) dslProposalList->append(proposal);
  }

  void calcStateProposals(AbstractStateItem* startState)
  {
    if(!this->_stateMachineDeclModel)
      return;

    if(startState){
      for(AbstractStateItem const* existState : this->_stateMachineDeclModel->states())
        this->_stateMachineProposals->append(DslProposal(existState->name(),
                                                         State));
    }
    else{
      for(AbstractStateItem const* existState : this->_stateMachineDeclModel->states())
        this->_stateMachineProposals->append(DslProposal(existState->name(),
                                                         State));
    }
    return;
  }
};

class ComCreateStateMachineProposals::Private
{
  friend class ComCreateStateMachineProposals;

  QString             _stateMachineDocText;
  StateMachineModel*  _stateMachineModel;
  bool                _strictErrorHandling;
  DslProposalList     _proposals;

  Private(const QString& statemachineDocText,
          model::statemachine::StateMachineModel* statemachineModel,
          bool strictErrorHandling)
    : _stateMachineDocText(statemachineDocText),
      _stateMachineModel(statemachineModel),
      _strictErrorHandling(strictErrorHandling)
  {}

  DslProposalList filterProposals(const QString& existingProposalText);
  bool            executePrivate(QString* errorString);
};

DslProposalList ComCreateStateMachineProposals::Private::filterProposals(const QString& existingProposalText)
{
  DslProposalList filterList;

  for(const DslProposal& currentProposal : this->_proposals)
  {
    if(currentProposal.proposalText.startsWith(existingProposalText))
      filterList.append(currentProposal);
  }

  return filterList;
}

bool ComCreateStateMachineProposals::Private::executePrivate(QString* errorString)
{
  //  qDebug() << "calculating proposals for: " << this->_statemachineDocText;

  StateMachineModel statemachineDeclModel;
  ComBuildStateMachineModel buildCommand(this->_stateMachineDocText, &statemachineDeclModel);
  buildCommand.execute();

  ANTLRInputStream input(this->_stateMachineDocText.toStdString());
  StateMachineLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  StateMachineParser parser(&tokens);

  if(isWithinComment<StateMachineLexer>(this->_stateMachineDocText, tokens, errorString))
    return true; //is within comment -> no proposals

  parser.setBuildParseTree(false);
  parser.setErrorHandler(std::make_shared<DefaultErrorStrategy>());
  parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::LL);


  // calculating line and pos in line...
  QPair<std::size_t, int> linePos = utils::CalcPosInLine()(this->_stateMachineDocText);

  StateMachineProposalErrorListener statemachineProposalErrorListener(linePos.first,
                                                                      linePos.second,
                                                                      &this->_proposals,
                                                                      &statemachineDeclModel,
                                                                      buildCommand.currentSignalItem(),
                                                                      buildCommand.currentStatePathItem());
  parser.removeErrorListeners();
  parser.addErrorListener(&statemachineProposalErrorListener);

  auto start = std::chrono::steady_clock::now();
  try
  {
    parser.stateMachineDecl();
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

ComCreateStateMachineProposals::ComCreateStateMachineProposals(const QString& statemachineDocText,
                                                               model::statemachine::StateMachineModel* statemachineModel,
                                                               bool strictErrorHandling,
                                                               QObject *parent)
  : QObject(parent), _d(new Private(statemachineDocText, statemachineModel, strictErrorHandling))
{

}

ComCreateStateMachineProposals::~ComCreateStateMachineProposals()
{
  delete this->_d;
}

bool ComCreateStateMachineProposals::execute(QString* errorString)
{
  //  qDebug() << "calculating proposals for: " << this->_d->_stateMachineDocText;

  // approach for removing last string (if available) for better proposal of contextID-rule
  QString lastWordAtEndOfDocText(QLatin1String(""));
  if(this->_d->_stateMachineDocText.size())
  {
    int currentIndex = this->_d->_stateMachineDocText.size()-1;
    QChar currentChar=this->_d->_stateMachineDocText.at(currentIndex);
    while (currentChar.isLetterOrNumber()
           || currentChar == QLatin1Char('_'))
    {
      lastWordAtEndOfDocText.prepend(currentChar);
      --currentIndex;
      if(currentIndex>=0)
        currentChar=this->_d->_stateMachineDocText.at(currentIndex);
      else
        currentChar=QChar();
    }
  }
//  qDebug()<<"lastWordAtEndOfDocText: "<<lastWordAtEndOfDocText;

  int lastWordSize = lastWordAtEndOfDocText.size();

  if(lastWordSize)
    this->_d->_stateMachineDocText.remove(this->_d->_stateMachineDocText.size()-lastWordSize,
                                    lastWordSize);

  bool result = this->_d->executePrivate(errorString);
  if(!result)
    return false;

  if(!lastWordSize)
    return true;

  DslProposalList filterProposalList = this->_d->filterProposals(lastWordAtEndOfDocText);
  if(filterProposalList.size()==0)
  {// without modifications
    this->_d->_stateMachineDocText.append(lastWordAtEndOfDocText);
    if(errorString)
      errorString->clear();
    this->_d->_proposals.clear();

    return this->_d->executePrivate(errorString);
  }
  else if(filterProposalList.size()==1
          && filterProposalList.at(0).proposalText == lastWordAtEndOfDocText)
  {// without modifications
    this->_d->_stateMachineDocText.append(lastWordAtEndOfDocText);
    if(errorString)
      errorString->clear();
    this->_d->_proposals.clear();

    return this->_d->executePrivate(errorString);
  }
  else
    this->_d->_proposals = filterProposalList;

  return true;
}

const DslProposalList& ComCreateStateMachineProposals::statemachineProposals() const
{
  return this->_d->_proposals;
}

} // namespace common
} // namespace dslparser
