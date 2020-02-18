#include "comcreatetrafficsimproposals.hpp"

#include "combuildtrafficsimmodel.hpp"

#include "trafficsimmodel.hpp"
#include <mobata/model/base/signalitem.hpp>
#include <mobata/model/base/portitem.hpp>

#include <mobata/utils/functors.hpp>

#include <QDebug>

#undef emit
#undef SIGNAL

#include <antlr4/antlr4-runtime.h>

#include <dslparser/trafficsim/TrafficSimDeclParser.h>
#include <dslparser/trafficsim/TrafficSimDeclLexer.h>
#include <dslparser/trafficsim/TrafficSimDeclBaseListener.h>

#include <mobata/memory_leak_start.hpp>

using namespace utils;
using namespace trafficsim;
using namespace model::base;
using namespace antlr4;
using namespace dslparser;


class TrafficSimProposalErrorListener
    : public BaseErrorListener
{
  std::size_t             _line;
  std::size_t             _posInLine;
  TrafficSimProposalList* _trafficSimProposals;
  TrafficSimModel*        _trafficSimDeclModel;

public:
  TrafficSimProposalErrorListener(std::size_t line,
                                  int posInLine,
                                  TrafficSimProposalList* trafficSimProposals,
                                  TrafficSimModel* trafficSimDeclModel = 0)
    : _line(line),
      _posInLine(posInLine),
      _trafficSimProposals(trafficSimProposals),
      _trafficSimDeclModel(trafficSimDeclModel)
  {}

protected:
  virtual void syntaxError(Recognizer* recognizer,
                           Token* offendingSymbol,
                           size_t line,
                           std::size_t charPositionInLine,
                           const std::string &msg,
                           std::exception_ptr /*e*/) override
  {
    Q_ASSERT(this->_trafficSimProposals);
    Q_UNUSED(offendingSymbol);
    Q_UNUSED(msg);

    if(line != this->_line)
      return;

    if(charPositionInLine != this->_posInLine)
      return;

    TrafficSimDeclParser* parser = static_cast<TrafficSimDeclParser*>(recognizer);
    Q_ASSERT(parser);

    const dfa::Vocabulary& vocabulary = parser->getVocabulary();
    misc::IntervalSet expTokens = parser->getExpectedTokens();
    for (auto token : expTokens.toList())
    {
      if(token == TrafficSimDeclParser::ID)
      {
        //ParserRuleContext* ruleCtx = parser->getRuleContext();
        //if(ruleCtx->getRuleIndex() == TrafficSimDeclParser::Rule)
        // continue;
        //        else if(ruleCtx->getRuleIndex() == TrafficSimDeclParser::RuleTrafficSimDecl)
        //            this->calcTrafficSimDecl();
        //        else if(ruleCtx->getRuleIndex() == TrafficSimDeclParser::RuleTrafficSimCompDecl)
        //            this->calcTrafficSimCompDecl();
      }
      else
      {//keywords
        QString displayName = QString::fromStdString(vocabulary.getDisplayName(token)).trimmed();

        if(displayName.startsWith("'"))
          displayName.remove(0,1);
        if(displayName.endsWith("'"))
          displayName.remove(displayName.size()-1,1);

        this->_trafficSimProposals->append(TrafficSimProposal(displayName,
                                                              trafficsimTokenType(token)));
      }
    }
    ///sort alphabetically
    qSort(this->_trafficSimProposals->begin(), this->_trafficSimProposals->end());

    //    std::vector<std::string> ruleInvocationStack = parser->getRuleInvocationStack();
    //    for(const std::string& rule : ruleInvocationStack)
    //      qDebug()<<"rule-invocation: "<<rule.c_str();

    return;
  }

};

class ComCreateTrafficSimProposals::Private
{
  friend class ComCreateTrafficSimProposals;

  QString                 _trafficsimDocText;
  bool                    _strictErrorHandling;
  TrafficSimProposalList  _trafficsimProposals;

  Private(const QString& trafficsimDocText,
          bool strictErrorHandling)
    : _trafficsimDocText(trafficsimDocText),
      _strictErrorHandling(strictErrorHandling)
  {}
};

ComCreateTrafficSimProposals::ComCreateTrafficSimProposals(const QString& trafficsimDocText,
                                                           bool strictErrorHandling,
                                                           QObject *parent)
  : QObject(parent), _d(new Private(trafficsimDocText, strictErrorHandling))
{

}

ComCreateTrafficSimProposals::~ComCreateTrafficSimProposals()
{
  delete this->_d;
}

bool isWithinComment(const QString& trafficsimText,
                     CommonTokenStream& tokens,
                     QString* errorString)
{
  if(trafficsimText.isEmpty())
    return false;

  std::size_t pos = trafficsimText.size();
  if(trafficsimText.midRef(pos - 2, 2) == QStringLiteral("*/"))
    return false;//end of multi line comment

  try
  {
    tokens.fill();
  } catch (IllegalStateException &)
  {
    AddPtrString(errorString)<<"Error: illegal state found, probably unfinished string.";
    return false;
  }

  for (auto token : tokens.getTokens())
  {
    if(token->getChannel() != Token::HIDDEN_CHANNEL)
      continue;

    int tokenType = token->getType();
    if(tokenType == TrafficSimDeclLexer::LINE_COMMENT
       || tokenType == TrafficSimDeclLexer::COMMENT)
    {
      if(token->getStartIndex() <= pos
         && pos <= (token->getStopIndex()+1))
        return true;
    }
  }

  return false;
}

bool ComCreateTrafficSimProposals::execute(QString* errorString)
{
  //  qDebug() << "calculating proposals for: " << this->_d->_trafficsimDocText;

  TrafficSimModel trafficsimDeclModel;
  ComBuildTrafficSimModel buildCommand(this->_d->_trafficsimDocText, &trafficsimDeclModel);
  buildCommand.execute();

  ANTLRInputStream input(this->_d->_trafficsimDocText.toStdString());
  TrafficSimDeclLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  TrafficSimDeclParser parser(&tokens);

  if(isWithinComment(this->_d->_trafficsimDocText, tokens, errorString))
    return true; //is within comment -> no proposals

  parser.setBuildParseTree(false);
  parser.setErrorHandler(std::make_shared<DefaultErrorStrategy>());
  parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::LL);


  // calculating line and pos in line...
  QPair<std::size_t, int> linePos = utils::CalcPosInLine()(this->_d->_trafficsimDocText);

  TrafficSimProposalErrorListener TrafficSimProposalErrorListener(linePos.first,
                                                                  linePos.second,
                                                                  &this->_d->_trafficsimProposals,
                                                                  &trafficsimDeclModel);
  parser.removeErrorListeners();
  parser.addErrorListener(&TrafficSimProposalErrorListener);

  auto start = std::chrono::steady_clock::now();
  try
  {
    parser.trafficSimulation();
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

const TrafficSimProposalList& ComCreateTrafficSimProposals::trafficsimProposals() const
{
  return this->_d->_trafficsimProposals;
}
