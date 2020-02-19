#include "comcreatespenatproposals.hpp"

#include "combuildspenatmodel.hpp"

#include <mobata/model/spenat/spenatdeclmodel.hpp>
#include <mobata/model/spenat/placeitem.hpp>
#include <mobata/model/spenat/transitionitem.hpp>
#include <mobata/model/base/signalitem.hpp>
#include <mobata/model/base/attributeitem.hpp>
#include <mobata/model/base/portitem.hpp>

#include <mobata/utils/functors.hpp>

#include <QDebug>

#undef emit
#undef SIGNAL

#include <antlr4/antlr4-runtime.h>

#include "SpenatParser.h"
#include "SpenatLexer.h"
#include "SpenatBaseListener.h"

#include <mobata/memory_leak_start.hpp>

using namespace utils;
using namespace model::spenat;
using namespace antlr4;

namespace dslparser {
namespace spenat {

class SpenatProposalErrorListener
    : public BaseErrorListener
{
  std::size_t       _line;
  std::size_t       _posInLine;
  DslProposalList*  _spenatProposals;
  SpenatDeclModel*  _spenatDeclModel;

public:
  SpenatProposalErrorListener(std::size_t line,
                              int posInLine,
                              DslProposalList* spenatProposals,
                              SpenatDeclModel* spenatDeclModel = nullptr)
    : _line(line),
      _posInLine(posInLine),
      _spenatProposals(spenatProposals),
      _spenatDeclModel(spenatDeclModel)
  {}

protected:
  virtual void syntaxError(Recognizer* recognizer,
                           Token* offendingSymbol,
                           size_t line,
                           std::size_t charPositionInLine,
                           const std::string &msg,
                           std::exception_ptr /*e*/) override
  {
    Q_ASSERT(this->_spenatProposals);
    Q_UNUSED(offendingSymbol);
    Q_UNUSED(msg);

    if(line != this->_line)
      return;

    if(charPositionInLine != this->_posInLine)
      return;

    SpenatParser* parser = static_cast<SpenatParser*>(recognizer);
    Q_ASSERT(parser);
    ParserRuleContext* ruleCtx = parser->getRuleContext();
    Q_ASSERT(ruleCtx);
    std::size_t ruleIndex = ruleCtx->getRuleIndex();

    ////debug stuff
    //std::vector<std::string> ruleInvocationStack = parser->getRuleInvocationStack();
    //qDebug()<<"rule-invocation-stack-size: "<<ruleInvocationStack.size();
    //for(const std::string& rule : ruleInvocationStack)
    //  qDebug()<<"rule-invocation: "<<rule.c_str();
    //RuleContext* debugParentRuleCtx = dynamic_cast<RuleContext*>(ruleCtx->parent);
    //if(debugParentRuleCtx)
    //  qDebug()<<"parent-rule-context-string-tree: "<<QString::fromStdString(debugParentRuleCtx->toStringTree(parser));

    if(ruleIndex == SpenatParser::RuleContextID)
    {
      if(RuleContext* parentRuleCtx = dynamic_cast<RuleContext*>(ruleCtx->parent))
      {
        if(parentRuleCtx->getRuleIndex() == SpenatParser::RuleRefSignalDecl)
          CalcRefSignalsProposals(this->_spenatDeclModel, this->_spenatProposals)();
        else if(parentRuleCtx->getRuleIndex() == SpenatParser::RuleAttributeName)
          CalcRefAttributesProposals(this->_spenatDeclModel, this->_spenatProposals)();
        else if(parentRuleCtx->getRuleIndex() == SpenatParser::RuleRefPortDecl)
          CalcRefPortsProposals(this->_spenatDeclModel, this->_spenatProposals)();
        else if(parentRuleCtx->getRuleIndex() == SpenatParser::RulePreDecl)
          this->calcPrePlaceProposals();
        else if(parentRuleCtx->getRuleIndex() == SpenatParser::RulePostDecl)
          this->calcPostPlaceProposals();
      }
    }
    else if(ruleIndex == SpenatParser::RuleAttributeName){
          CalcRefAttributesProposals(this->_spenatDeclModel, this->_spenatProposals)();
    }
    else
    {//keywords
      const dfa::Vocabulary& vocabulary = parser->getVocabulary();
      misc::IntervalSet expTokens = parser->getExpectedTokens();
      for (auto token : expTokens.toList())
      {
        if((ruleIndex == SpenatParser::RuleTypeDecl
            || ruleIndex == SpenatParser::RuleSignalDecl)
           && this->isContextID(token))
          continue;
        else if(token == SpenatParser::ID)
          continue;//no contextID token as proposal
        else if(token == SpenatParser::MessageTrigger){
          //TODO: implement with current Signal!!
          /*
          if(_currentSignalItem){
            for(auto param : static_cast<const model::base::SignalItem*>(_currentSignalItem)->params()){
              addUniqueProposal(_requirementProposals,DslProposal(QString("%0.%1").arg(QString::fromStdString(vocabulary.getDisplayName(token)).trimmed().remove(QChar('\'')),
                                                                                       param->name()),Identifier));
            }
          }*/
          continue;
        }

        QString displayName = QString::fromStdString(vocabulary.getDisplayName(token)).trimmed();
//        qDebug()<<"else - expected token name: "<<displayName;

        if(displayName.startsWith("'"))
          displayName.remove(0,1);
        if(displayName.endsWith("'"))
          displayName.remove(displayName.size()-1,1);

        this->_spenatProposals->append(DslProposal(displayName,
                                                   spenatTokenType(token)));
      }
    }
    ///sort alphabetically
    qSort(this->_spenatProposals->begin(), this->_spenatProposals->end());

    return;
  }

  bool isContextID(std::size_t token)
  {
    if(isCommonContextID<SpenatParser>(token))
      return true;

    return (token == SpenatParser::ActionID
            || token == SpenatParser::SpenatID
            || token == SpenatParser::PlaceID
            || token == SpenatParser::SignalTransitionID
            || token == SpenatParser::TimeoutTransitionID
            || token == SpenatParser::RefSignalID
            || token == SpenatParser::RefPortID
            || token == SpenatParser::ValueID
            || token == SpenatParser::GuardID
            || token == SpenatParser::InitialID
            || token == SpenatParser::PreID
            || token == SpenatParser::PostID);
  }

  void calcPrePlaceProposals()
  {
    if(!this->_spenatDeclModel)
      return;

    for(PlaceItem const* existPlace : this->_spenatDeclModel->places())
      this->_spenatProposals->append(DslProposal(existPlace->name(),
                                                 RefPlace));

    return;
  }

  void calcPostPlaceProposals()
  {
    if(!this->_spenatDeclModel)
      return;

    for(PlaceItem const* existPlace : this->_spenatDeclModel->places())
      this->_spenatProposals->append(DslProposal(existPlace->name(),
                                                 RefPlace));

    return;
  }
};

class ComCreateSpenatProposals::Private
{
  friend class ComCreateSpenatProposals;

  QString         _spenatDocText;
  bool            _strictErrorHandling;
  DslProposalList _spenatProposals;

  Private(const QString& spenatDocText,
          bool strictErrorHandling)
    : _spenatDocText(spenatDocText),
      _strictErrorHandling(strictErrorHandling)
  {}

  DslProposalList  filterSpenatProposals(const QString& existingProposalText);
  bool             executePrivate(QString* errorString);
};

DslProposalList ComCreateSpenatProposals::Private::filterSpenatProposals(const QString& existingProposalText)
{
  DslProposalList filterList;

  for(const DslProposal& currentSpenatProposal : this->_spenatProposals)
  {
    if(currentSpenatProposal.proposalText.startsWith(existingProposalText))
      filterList.append(currentSpenatProposal);
  }

  return filterList;
}

bool ComCreateSpenatProposals::Private::executePrivate(QString* errorString)
{
  SpenatDeclModel spenatDeclModel;
  ComBuildSpenatModel buildCommand(this->_spenatDocText, &spenatDeclModel);
  buildCommand.execute();

  ANTLRInputStream input(this->_spenatDocText.toStdString());
  SpenatLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  SpenatParser parser(&tokens);

  if(isWithinComment<SpenatLexer>(this->_spenatDocText, tokens, errorString))
    return true; //is within comment -> no proposals

  parser.setBuildParseTree(false);
  parser.setErrorHandler(std::make_shared<DefaultErrorStrategy>());
  parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::LL);


  // calculating line and pos in line...
  QPair<std::size_t, int> linePos = utils::CalcPosInLine()(this->_spenatDocText);

  SpenatProposalErrorListener spenatProposalErrorListener(linePos.first,
                                                          linePos.second,
                                                          &this->_spenatProposals,
                                                          &spenatDeclModel);
  parser.removeErrorListeners();
  parser.addErrorListener(&spenatProposalErrorListener);

  auto start = std::chrono::steady_clock::now();
  try
  {
    parser.spenatDecl();
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

ComCreateSpenatProposals::ComCreateSpenatProposals(const QString& spenatDocText,
                                                   bool strictErrorHandling,
                                                   QObject *parent)
  : QObject(parent), _d(new Private(spenatDocText, strictErrorHandling))
{

}

ComCreateSpenatProposals::~ComCreateSpenatProposals()
{
  delete this->_d;
}

bool ComCreateSpenatProposals::execute(QString* errorString)
{
  //  qDebug() << "calculating proposals for: " << this->_d->_spenatDocText;

  // approach for removing last string (if available) for better proposal of contextID-rule
  QString lastWordAtEndOfDocText(QLatin1String(""));
  if(this->_d->_spenatDocText.size())
  {
    int currentIndex = this->_d->_spenatDocText.size()-1;
    QChar currentChar=this->_d->_spenatDocText.at(currentIndex);
    while (currentChar.isLetterOrNumber()
           || currentChar == QLatin1Char('_'))
    {
      lastWordAtEndOfDocText.prepend(currentChar);
      --currentIndex;
      if(currentIndex>=0)
        currentChar=this->_d->_spenatDocText.at(currentIndex);
      else
        currentChar=QChar();
    }
  }
//  qDebug()<<"lastWordAtEndOfDocText: "<<lastWordAtEndOfDocText;

  int lastWordSize = lastWordAtEndOfDocText.size();

  if(lastWordSize)
    this->_d->_spenatDocText.remove(this->_d->_spenatDocText.size()-lastWordSize,
                                    lastWordSize);

  bool result = this->_d->executePrivate(errorString);
  if(!result)
    return false;

  if(!lastWordSize)
    return true;

  DslProposalList filterProposalList = this->_d->filterSpenatProposals(lastWordAtEndOfDocText);
  if(filterProposalList.size()==0)
  {// without modifications
    this->_d->_spenatDocText.append(lastWordAtEndOfDocText);
    if(errorString)
      errorString->clear();
    this->_d->_spenatProposals.clear();

    return this->_d->executePrivate(errorString);
  }
  else if(filterProposalList.size()==1
          && filterProposalList.at(0).proposalText == lastWordAtEndOfDocText)
  {// without modifications
    this->_d->_spenatDocText.append(lastWordAtEndOfDocText);
    if(errorString)
      errorString->clear();
    this->_d->_spenatProposals.clear();

    return this->_d->executePrivate(errorString);
  }
  else
    this->_d->_spenatProposals = filterProposalList;

  return true;
}

const DslProposalList& ComCreateSpenatProposals::spenatProposals() const
{
  return this->_d->_spenatProposals;
}

} // namespace spenat
} // namespace dslparser
