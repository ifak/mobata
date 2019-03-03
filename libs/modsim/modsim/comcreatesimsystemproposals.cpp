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

#include "comcreatesimsystemproposals.hpp"

#include "combuildsimsystemmodel.hpp"

#include "simsystemmodel.hpp"
#include "simsystemitem.hpp"
#include <mobata/model/msc/msc_types.hpp>
#include <mobata/model/msc/msccomponentitem.hpp>
#include <mobata/model/msc/msctimeritem.hpp>

#include <mobata/utils/functors.hpp>

#include <QDebug>

#undef emit
#undef SIGNAL

#include <antlr4/antlr4-runtime.h>

#include <dslparser/simsystem/SimSystemDeclParser.h>
#include <dslparser/simsystem/SimSystemDeclLexer.h>
#include <dslparser/simsystem/SimSystemDeclBaseListener.h>

#include <mobata/model/spenat/spenatdeclmodel.hpp>
#include <mobata/model/statemachine/statemachinemodel.hpp>

#include <QDir>

using namespace utils;
using namespace model::base;
using namespace model::msc;
using namespace antlr4;
using namespace dslparser;

namespace modsim {

typedef QHash<QString, model::spenat::SpenatDeclModel*>         ImportSpenatModelList;
typedef QHash<QString, model::statemachine::StateMachineModel*> ImportStatemachineModelList;

class SimSystemProposalErrorListener
    : public BaseErrorListener
{
  std::size_t                                     _line;
  std::size_t                                     _posInLine;
  DslProposalList*                                _simSystemProposals;
  SimSystemModel*                                 _simSystemModel;
  ImportSpenatModelList                           _importSpenatModels;
  ImportStatemachineModelList                     _importStatemachineModels;
  QString                                         _praefix;

public:
  SimSystemProposalErrorListener(std::size_t line,
                                 int posInLine,
                                 DslProposalList* simSystemProposals,
                                 const ImportSpenatModelList& importSpenatModels,
                                 const ImportStatemachineModelList& importStatemachineModels,
                                 SimSystemModel* simSystemModel = nullptr,
                                 const QString& praefix = "")
    : _line(line),
      _posInLine(posInLine),
      _simSystemProposals(simSystemProposals),
      _simSystemModel(simSystemModel),
      _importSpenatModels(importSpenatModels),
      _importStatemachineModels(importStatemachineModels),
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
    Q_ASSERT(this->_simSystemProposals);
    Q_UNUSED(offendingSymbol);
    Q_UNUSED(msg);

    if(line != this->_line)
      return;

    if(charPositionInLine != this->_posInLine)
      return;

    //    _simSystemProposals->clear();

    SimSystemDeclParser* parser = static_cast<SimSystemDeclParser*>(recognizer);
    Q_ASSERT(parser);

    ParserRuleContext* ruleCtx = parser->getRuleContext();
    Q_ASSERT(ruleCtx);
    std::size_t ruleIndex = ruleCtx->getRuleIndex();

    TokenStream* stream = parser->getTokenStream();
    Token* lastToken = stream->get(stream->size()-1);

    if(ruleIndex == SimSystemDeclParser::RuleContextID)
    {
      if(RuleContext* parentRuleCtx = dynamic_cast<RuleContext*>(ruleCtx->parent))
      {
        if(parentRuleCtx->getRuleIndex() == SimSystemDeclParser::RuleAttributeName)
          CalcRefAttributesProposals(this->_simSystemModel, _simSystemProposals)();
        else if(parentRuleCtx->getRuleIndex() == SimSystemDeclParser::RuleImportFileBody){
          RuleContext* greatParentRuleCtx = parentRuleCtx;
          do{
            parentRuleCtx = greatParentRuleCtx;
            greatParentRuleCtx =  dynamic_cast<RuleContext*>(greatParentRuleCtx->parent);
          }
          while(greatParentRuleCtx->getRuleIndex() != SimSystemDeclParser::RuleImportPathBody);

          SimSystemDeclParser::ImportFileBodyContext* idPathCtx = dynamic_cast<SimSystemDeclParser::ImportFileBodyContext*>(parentRuleCtx);
          QString pathStr = QString::fromStdString(stream->getText(misc::Interval(idPathCtx->getStart()->getTokenIndex(),stream->size()-1)));
          pathStr.remove('\n');
          pathStr.remove(' ');
          pathStr.remove('\t');
          calcImportOptions(pathStr, _simSystemProposals);
        }
        else if(parentRuleCtx->getRuleIndex() == SimSystemDeclParser::RuleComponentIdPath){
          auto mother = static_cast<SimSystemDeclParser::ComponentIdPathContext*>(parentRuleCtx);
          if(mother && !mother->exception){
            QStringList path = QString::fromStdString(stream->getText(mother->start,lastToken))
                               .remove(QChar('\b')).remove(QChar('\t')).remove(QChar('\n')).remove(QChar('\r'))
                               .remove(QChar('\\')).remove(QChar(' ')).split(QChar('.'));
            calcComponents(path,_simSystemProposals);
          }
        }
        else if(parentRuleCtx->getRuleIndex() == SimSystemDeclParser::RuleStartSequenceDecl){
          for(auto modelName : _importSpenatModels.keys()){
            addUniqueProposal(_simSystemProposals,DslProposal(modelName,Identifier));
          }
          for(auto modelName : _importStatemachineModels.keys()){
            addUniqueProposal(_simSystemProposals,DslProposal(modelName,Identifier));
          }
        }
      }
    }
    else if(ruleIndex == SimSystemDeclParser::RuleImportFileBody){
      RuleContext* parentRuleCtx = ruleCtx;
      RuleContext* greatParentRuleCtx = parentRuleCtx;
      do{
        parentRuleCtx = greatParentRuleCtx;
        greatParentRuleCtx =  dynamic_cast<RuleContext*>(greatParentRuleCtx->parent);
      }
      while(greatParentRuleCtx->getRuleIndex() != SimSystemDeclParser::RuleImportPathBody);

      SimSystemDeclParser::ImportFileBodyContext* idPathCtx = dynamic_cast<SimSystemDeclParser::ImportFileBodyContext*>(parentRuleCtx);
      QString pathStr = QString::fromStdString(stream->getText(misc::Interval(idPathCtx->getStart()->getTokenIndex(),stream->size()-1)));
      pathStr.remove('\n');
      pathStr.remove(' ');
      pathStr.remove('\t');
      calcImportOptions(pathStr, _simSystemProposals);
    }
    else
    {//keywords
      const dfa::Vocabulary& vocabulary = parser->getVocabulary();
      misc::IntervalSet expTokens = parser->getExpectedTokens();
      QStringList emptyCtx = {};
      bool alreadyGotContextID = false;
      for (auto token : expTokens.toList())
      {
        if(ruleIndex == SimSystemDeclParser::RuleLiteralValue && this->isContextID(token)){
          if(!alreadyGotContextID){
            calcLiteralValues(_simSystemProposals);
            alreadyGotContextID = true;
          }

          continue;
        }
        else if(token == SimSystemDeclParser::ID)
          continue;//no contextID token as proposal
        else if((ruleIndex == SimSystemDeclParser::RuleSignalDecl || ruleIndex == SimSystemDeclParser::RuleTypeDecl)
                && this->isContextID(token)){
          continue;//TODO: return custom types
        }
        else if(nonEssentialToken(token) || (ruleIndex == SimSystemDeclParser::RuleIntTypeDecl ||
                                             ruleIndex == SimSystemDeclParser::RuleRealTypeDecl))
          continue;

        QString displayName = QString::fromStdString(vocabulary.getDisplayName(token)).trimmed();
        //        qDebug()<<"else - expected token name: "<<displayName;

        if(displayName.startsWith("'"))
          displayName.remove(0,1);
        if(displayName.endsWith("'"))
          displayName.remove(displayName.size()-1,1);

        addUniqueProposal(_simSystemProposals,DslProposal(displayName,simSystemTokenType(token)));
      }
    }
    ///sort alphabetically
    qSort(_simSystemProposals->begin(), _simSystemProposals->end());
    return;
  }

  bool isContextID(std::size_t token)
  {
    if(isCommonContextID<SimSystemDeclParser>(token))
      return true;

    return (token == SimSystemDeclParser::SignalTransitionID
            || token == SimSystemDeclParser::TimeoutTransitionID
            || token == SimSystemDeclParser::DeclarationID
            || token == SimSystemDeclParser::DescriptionID
            || token == SimSystemDeclParser::ToID);
  }

  bool nonEssentialToken(std::size_t token){
    return (token == SimSystemDeclParser::ReturnID
            || token == SimSystemDeclParser::ThisID
            || token == SimSystemDeclParser::CaseID
            || token == SimSystemDeclParser::DefaultID
            || token == SimSystemDeclParser::IfID
            || token == SimSystemDeclParser::ElseID
            || token == SimSystemDeclParser::NotIdSymbol
            || token == SimSystemDeclParser::AndIdSymbol
            || token == SimSystemDeclParser::OrIdSymbol
            || token == SimSystemDeclParser::NotIdWord
            || token == SimSystemDeclParser::AndIdWord
            || token == SimSystemDeclParser::OrIdWord
            || token == SimSystemDeclParser::TrueID
            || token == SimSystemDeclParser::FalseID
            || token == SimSystemDeclParser::BREAK
            || token == SimSystemDeclParser::ASSIGN
            || token == SimSystemDeclParser::INT
            || token == SimSystemDeclParser::REAL
            || token == SimSystemDeclParser::STRING
            || token == SimSystemDeclParser::LPAREN
            || token == SimSystemDeclParser::RPAREN
            || token == SimSystemDeclParser::LBRACE
            || token == SimSystemDeclParser::RBRACE
            || token == SimSystemDeclParser::LBRACKET
            || token == SimSystemDeclParser::RBRACKET
            || token == SimSystemDeclParser::LESSTHAN
            || token == SimSystemDeclParser::GREATERTHAN
            || token == SimSystemDeclParser::COLON
            || token == SimSystemDeclParser::SEMI
            || token == SimSystemDeclParser::COMMA
            || token == SimSystemDeclParser::DOT
            || token == SimSystemDeclParser::PLUS
            || token == SimSystemDeclParser::MINUS
            || token == SimSystemDeclParser::MULT
            || token == SimSystemDeclParser::DIV
            || token == SimSystemDeclParser::PIPE
            || token == SimSystemDeclParser::REF
            || token == SimSystemDeclParser::CONST
            || token == SimSystemDeclParser::UNDER
            || token == SimSystemDeclParser::AtID);
  }

  void calcLiteralValues(DslProposalList* dslProposalList){
    for(auto types : _simSystemModel->dataTypes())
      for(auto literal : types->literals())
        addUniqueProposal(dslProposalList,DslProposal(literal,Literal));
  }

  void calcComponents(QStringList path, DslProposalList* dslProposalList){
    uint8_t sz = path.size();
    if(sz && path.last() == QString("")) --sz;
    QString compStr;

    switch (sz) {
    case 1:
      compStr = path.at(0);
      if(_importSpenatModels.contains(compStr)){
        for(auto port : _importSpenatModels.value(compStr)->ports()){
          addUniqueProposal(dslProposalList,DslProposal(port->name(),Identifier));
        }
      }
      if(_importStatemachineModels.contains(compStr)){
        for(auto port : _importStatemachineModels.value(compStr)->ports()){
          addUniqueProposal(dslProposalList,DslProposal(port->name(),Identifier));
        }
      }
      return;
      break;
    case 0:
      for(auto model : _importSpenatModels.values()){
        for(auto port : model->ports()){
          addUniqueProposal(dslProposalList,DslProposal(QString("%0.%1").arg(_importSpenatModels.key(model),port->name()),Identifier));
        }
      }
      for(auto model : _importStatemachineModels.values()){
        for(auto port : model->ports()){
          addUniqueProposal(dslProposalList,DslProposal(QString("%0.%1").arg(_importStatemachineModels.key(model),port->name()),Identifier));
        }
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
    for (QString option: list) {
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

class ComCreateSimSystemProposals::Private
{
  friend class ComCreateSimSystemProposals;

  QString         _simSystemDocText;
  QString         _prefix;
  SimSystemModel* _simSystemModel;
  bool            _strictErrorHandling;
  DslProposalList _simSystemProposals;

  Private(const QString& simSystemDocText,
          SimSystemModel* simSystemModel,
          const QString& prefix,
          bool strictErrorHandling)
    : _simSystemDocText(simSystemDocText),
      _prefix(prefix),
      _simSystemModel(simSystemModel),
      _strictErrorHandling(strictErrorHandling)
  {}
  DslProposalList filterSimSystemProposals(const QString& existingProposalText);
  bool executePrivate(QString* errorString);
};

DslProposalList ComCreateSimSystemProposals::Private::filterSimSystemProposals(const QString& existingProposalText)
{
  DslProposalList filterList;

  for(const DslProposal& currentSimSystemProposal : this->_simSystemProposals)
  {
    if(currentSimSystemProposal.proposalText.startsWith(existingProposalText))
      filterList.append(currentSimSystemProposal);
  }

  return filterList;
}

bool ComCreateSimSystemProposals::Private::executePrivate(QString* errorString)
{
  SimSystemModel simSystemModel;
  ComBuildSimSystemModel buildCommand(this->_simSystemDocText, simSystemModel.simSystemItem(),_prefix);
  buildCommand.execute();

  ANTLRInputStream input(this->_simSystemDocText.toStdString());
  SimSystemDeclLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  SimSystemDeclParser parser(&tokens);

  if(isWithinComment<SimSystemDeclLexer>(this->_simSystemDocText, tokens, errorString))
    return true; //is within comment -> no proposals

  parser.setBuildParseTree(false);
  parser.setErrorHandler(std::make_shared<DefaultErrorStrategy>());
  parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::LL);


  // calculating line and pos in line...
  QPair<std::size_t, int> linePos = utils::CalcPosInLine()(this->_simSystemDocText);

  SimSystemProposalErrorListener simSystemProposalErrorListener(linePos.first,
                                                                linePos.second,
                                                                &this->_simSystemProposals,
                                                                buildCommand.importedSpenatModels(),
                                                                buildCommand.importedStatemachineModels(),
                                                                &simSystemModel,
                                                                _prefix);
  parser.removeErrorListeners();
  parser.addErrorListener(&simSystemProposalErrorListener);

  auto start = std::chrono::steady_clock::now();
  try
  {
    parser.simSystemDecl();
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

ComCreateSimSystemProposals::ComCreateSimSystemProposals(const QString& simSystemDocText,
                                                         const QString& prefix,
                                                         SimSystemModel* simSystemModel,
                                                         bool strictErrorHandling,
                                                         QObject *parent)
  : QObject(parent), _d(new Private(simSystemDocText, simSystemModel, prefix, strictErrorHandling))
{

}

ComCreateSimSystemProposals::~ComCreateSimSystemProposals()
{
  delete this->_d;
}

bool ComCreateSimSystemProposals::execute(QString* errorString)
{
  //  qDebug() << "calculating proposals for: " << this->_d->_simSystemDocText;

  // approach for removing last string (if available) for better proposal of contextID-rule
  QString lastWordAtEndOfDocText(QLatin1String(""));
  if(this->_d->_simSystemDocText.size())
  {
    int currentIndex = this->_d->_simSystemDocText.size()-1;
    QChar currentChar=this->_d->_simSystemDocText.at(currentIndex);
    while (currentChar.isLetterOrNumber()
           || currentChar == QLatin1Char('_'))
    {
      lastWordAtEndOfDocText.prepend(currentChar);
      --currentIndex;
      if(currentIndex>=0)
        currentChar=this->_d->_simSystemDocText.at(currentIndex);
      else
        currentChar=QChar();
    }
  }
  //  qDebug()<<"lastWordAtEndOfDocText: "<<lastWordAtEndOfDocText;

  int lastWordSize = lastWordAtEndOfDocText.size();

  if(lastWordSize)
    this->_d->_simSystemDocText.remove(this->_d->_simSystemDocText.size()-lastWordSize,
                                       lastWordSize);

  bool result = this->_d->executePrivate(errorString);
  if(!result)
    return false;

  if(!lastWordSize)
    return true;

  DslProposalList filterProposalList = this->_d->filterSimSystemProposals(lastWordAtEndOfDocText);
  if(filterProposalList.size()==0)
  {// without modifications
    this->_d->_simSystemDocText.append(lastWordAtEndOfDocText);
    if(errorString)
      errorString->clear();
    this->_d->_simSystemProposals.clear();

    return this->_d->executePrivate(errorString);
  }
  else if(filterProposalList.size()==1
          && filterProposalList.at(0).proposalText == lastWordAtEndOfDocText)
  {// without modifications
    this->_d->_simSystemDocText.append(lastWordAtEndOfDocText);
    if(errorString)
      errorString->clear();
    this->_d->_simSystemProposals.clear();

    return this->_d->executePrivate(errorString);
  }
  else
    this->_d->_simSystemProposals = filterProposalList;

  return true;
}

const DslProposalList& ComCreateSimSystemProposals::simSystemProposals() const
{
  return this->_d->_simSystemProposals;
}

} // namespace modsim
