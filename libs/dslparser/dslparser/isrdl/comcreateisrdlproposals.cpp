#include "comcreateisrdlproposals.hpp"

#include "combuildisrdlmodel.hpp"

#include <mobata/model/isrdl/isrdlmodel.hpp>
#include <mobata/model/isrdl/isrdlitem.hpp>
#include <mobata/model/base/attributeitem.hpp>
#include <mobata/model/base/signalitem.hpp>
#include <mobata/model/base/portitem.hpp>

#include <mobata/utils/functors.hpp>

#include <QDebug>

#undef emit
#undef SIGNAL

#include <antlr4/antlr4-runtime.h>

#include "IsrdlParser.h"
#include "IsrdlLexer.h"
#include "IsrdlBaseListener.h"

#include <mobata/memory_leak_start.hpp>

using namespace utils;
using namespace model::isrdl;
using namespace model::base;
using namespace antlr4;

namespace dslparser {
namespace isrdl {

class IsrdlProposalErrorListener
    : public BaseErrorListener
{
  std::size_t       _line;
  std::size_t       _posInLine;
  DslProposalList*  _isrdlProposals;
  IsrdlModel*       _isrdlDeclModel;

public:
  IsrdlProposalErrorListener(std::size_t line,
                           int posInLine,
                           DslProposalList* isrdlProposals,
                           IsrdlModel* isrdlDeclModel = 0)
    : _line(line),
      _posInLine(posInLine),
      _isrdlProposals(isrdlProposals),
      _isrdlDeclModel(isrdlDeclModel)
  {}

protected:
  virtual void syntaxError(Recognizer* recognizer,
                           Token* offendingSymbol,
                           size_t line,
                           std::size_t charPositionInLine,
                           const std::string &msg,
                           std::exception_ptr /*e*/) override
  {
    Q_ASSERT(this->_isrdlProposals);
    Q_UNUSED(offendingSymbol);
    Q_UNUSED(msg);

    if(line != this->_line)
      return;

    if(charPositionInLine != this->_posInLine)
      return;

    IsrdlParser* parser = static_cast<IsrdlParser*>(recognizer);
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

    if(ruleIndex == IsrdlParser::RuleContextID)
    {
      if(RuleContext* parentRuleCtx = dynamic_cast<RuleContext*>(ruleCtx->parent))
      {
        if(parentRuleCtx->getRuleIndex() == IsrdlParser::RuleAttributeName)
          CalcRefAttributesProposals(this->_isrdlDeclModel, this->_isrdlProposals)();
      }
    }
    else
    {//keywords
      const dfa::Vocabulary& vocabulary = parser->getVocabulary();
      misc::IntervalSet expTokens = parser->getExpectedTokens();
      for (auto token : expTokens.toList())
      {
        if((ruleIndex == IsrdlParser::RuleTypeDecl
            || ruleIndex == IsrdlParser::RuleSignalDecl))
          continue;
        else if(token == IsrdlParser::ID)
          continue;//no contextID token as proposal
        else if(nonEssentialToken(token))
          continue;

        QString displayName = QString::fromStdString(vocabulary.getDisplayName(token)).trimmed();
        qDebug()<<"else - expected token name: "<<displayName;

        if(displayName.startsWith("'"))
          displayName.remove(0,1);
        if(displayName.endsWith("'"))
          displayName.remove(displayName.size()-1,1);

        this->_isrdlProposals->append(DslProposal(displayName,
                                                isrdlTokenType(token)));
      }
    }
    ///sort alphabetically
    qSort(this->_isrdlProposals->begin(), this->_isrdlProposals->end());

    return;
  }

  bool nonEssentialToken(std::size_t token){
    return (token == IsrdlParser::ReturnID
            || token == IsrdlParser::ThisID
            || token == IsrdlParser::CaseID
            || token == IsrdlParser::DefaultID
            || token == IsrdlParser::IfID
            || token == IsrdlParser::ElseID
            || token == IsrdlParser::NotIdSymbol
            || token == IsrdlParser::AndIdSymbol
            || token == IsrdlParser::OrIdSymbol
            || token == IsrdlParser::NotIdWord
            || token == IsrdlParser::AndIdWord
            || token == IsrdlParser::OrIdWord
            || token == IsrdlParser::TrueID
            || token == IsrdlParser::FalseID
            || token == IsrdlParser::BREAK
            || token == IsrdlParser::ASSIGN
            || token == IsrdlParser::INT
            || token == IsrdlParser::REAL
            || token == IsrdlParser::STRING
            || token == IsrdlParser::LPAREN
            || token == IsrdlParser::RPAREN
            || token == IsrdlParser::LBRACE
            || token == IsrdlParser::RBRACE
            || token == IsrdlParser::LBRACKET
            || token == IsrdlParser::RBRACKET
            || token == IsrdlParser::LESSTHAN
            || token == IsrdlParser::GREATERTHAN
            || token == IsrdlParser::COLON
            || token == IsrdlParser::SEMI
            || token == IsrdlParser::COMMA
            || token == IsrdlParser::DOT
            || token == IsrdlParser::PLUS
            || token == IsrdlParser::MINUS
            || token == IsrdlParser::MULT
            || token == IsrdlParser::DIV
            || token == IsrdlParser::PIPE
            || token == IsrdlParser::REF
            || token == IsrdlParser::CONST
            || token == IsrdlParser::UNDER
            || token == IsrdlParser::AtID);
  }
};

class ComCreateIsrdlProposals::Private
{
  friend class ComCreateIsrdlProposals;

  QString         _isrdlDocText;
  bool            _strictErrorHandling;
  DslProposalList _isrdlProposals;

  Private(const QString& isrdlDocText,
          bool strictErrorHandling)
    : _isrdlDocText(isrdlDocText),
      _strictErrorHandling(strictErrorHandling)
  {}
};

ComCreateIsrdlProposals::ComCreateIsrdlProposals(const QString& isrdlDocText,
                                             bool strictErrorHandling,
                                             QObject *parent)
  : QObject(parent), _d(new Private(isrdlDocText, strictErrorHandling))
{

}

ComCreateIsrdlProposals::~ComCreateIsrdlProposals()
{
  delete this->_d;
}

bool isWithinComment(const QString& isrdlText,
                     CommonTokenStream& tokens,
                     QString* errorString)
{
  if(isrdlText.isEmpty())
    return false;

  std::size_t pos = isrdlText.size();
  if(isrdlText.midRef(pos - 2, 2) == QStringLiteral("*/"))
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
    if(tokenType == IsrdlLexer::LINE_COMMENT
       || tokenType == IsrdlLexer::COMMENT)
    {
      if(token->getStartIndex() <= pos
         && pos <= (token->getStopIndex()+1))
        return true;
    }
  }

  return false;
}

bool ComCreateIsrdlProposals::execute(QString* errorString)
{
  //  qDebug() << "calculating proposals for: " << this->_d->_isrdlDocText;

  IsrdlModel isrdlModel;
  ComBuildIsrdlModel buildCommand(this->_d->_isrdlDocText, &isrdlModel);
  buildCommand.execute();

  ANTLRInputStream input(this->_d->_isrdlDocText.toStdString());
  IsrdlLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  IsrdlParser parser(&tokens);

  if(isWithinComment(this->_d->_isrdlDocText, tokens, errorString))
    return true; //is within comment -> no proposals

  parser.setBuildParseTree(false);
  parser.setErrorHandler(std::make_shared<DefaultErrorStrategy>());
  parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::LL);


  // calculating line and pos in line...
  QPair<std::size_t, int> linePos = utils::CalcPosInLine()(this->_d->_isrdlDocText);

  IsrdlProposalErrorListener isrdlProposalErrorListener(linePos.first,
                                                    linePos.second,
                                                    &this->_d->_isrdlProposals,
                                                    &isrdlModel);
  parser.removeErrorListeners();
  parser.addErrorListener(&isrdlProposalErrorListener);

  auto start = std::chrono::steady_clock::now();
  try
  {
    parser.secRequirement();
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

const DslProposalList& ComCreateIsrdlProposals::isrdlProposals() const
{
  return this->_d->_isrdlProposals;
}

} // namespace common
} // namespace dslparser
