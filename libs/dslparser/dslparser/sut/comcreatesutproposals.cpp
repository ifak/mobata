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

#include "comcreatesutproposals.hpp"

#include "combuildsutmodel.hpp"

#include <mobata/model/ts/testsuite.hpp>
#include <mobata/model/ts/sutitem.hpp>
#include <mobata/model/base/attributeitem.hpp>
#include <mobata/model/base/signalitem.hpp>
#include <mobata/model/base/portitem.hpp>

#include <mobata/utils/functors.hpp>

#include <QDebug>

#undef emit
#undef SIGNAL

#include <antlr4/antlr4-runtime.h>

#include "SutDeclParser.h"
#include "SutDeclLexer.h"
#include "SutDeclBaseListener.h"

using namespace utils;
using namespace model::ts;
using namespace model::base;
using namespace antlr4;

namespace dslparser {
namespace sut {

class SutProposalErrorListener
    : public BaseErrorListener
{
  std::size_t       _line;
  std::size_t       _posInLine;
  DslProposalList*  _sutProposals;
  SutItem*          _sutDeclModel;

public:
  SutProposalErrorListener(std::size_t line,
                           int posInLine,
                           DslProposalList* sutProposals,
                           SutItem* sutDeclModel = 0)
    : _line(line),
      _posInLine(posInLine),
      _sutProposals(sutProposals),
      _sutDeclModel(sutDeclModel)
  {}

protected:
  virtual void syntaxError(Recognizer* recognizer,
                           Token* offendingSymbol,
                           size_t line,
                           std::size_t charPositionInLine,
                           const std::string &msg,
                           std::exception_ptr /*e*/) override
  {
    Q_ASSERT(this->_sutProposals);
    Q_UNUSED(offendingSymbol);
    Q_UNUSED(msg);

    if(line != this->_line)
      return;

    if(charPositionInLine != this->_posInLine)
      return;

    SutDeclParser* parser = static_cast<SutDeclParser*>(recognizer);
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

    if(ruleIndex == SutDeclParser::RuleContextID)
    {
      if(RuleContext* parentRuleCtx = dynamic_cast<RuleContext*>(ruleCtx->parent))
      {
        if(parentRuleCtx->getRuleIndex() == SutDeclParser::RuleAttributeName)
          CalcRefAttributesProposals(this->_sutDeclModel, this->_sutProposals)();
      }
    }
    else
    {//keywords
      const dfa::Vocabulary& vocabulary = parser->getVocabulary();
      misc::IntervalSet expTokens = parser->getExpectedTokens();
      for (auto token : expTokens.toList())
      {
        if((ruleIndex == SutDeclParser::RuleTypeDecl
            || ruleIndex == SutDeclParser::RuleSignalDecl)
           && this->isContextID(token))
          continue;
        else if(token == SutDeclParser::ID)
          continue;//no contextID token as proposal

        QString displayName = QString::fromStdString(vocabulary.getDisplayName(token)).trimmed();
//        qDebug()<<"else - expected token name: "<<displayName;

        if(displayName.startsWith("'"))
          displayName.remove(0,1);
        if(displayName.endsWith("'"))
          displayName.remove(displayName.size()-1,1);

        this->_sutProposals->append(DslProposal(displayName,
                                                sutTokenType(token)));
      }
    }
    ///sort alphabetically
    qSort(this->_sutProposals->begin(), this->_sutProposals->end());

    return;
  }

  bool isContextID(std::size_t token)
  {
    if(isCommonContextID<SutDeclParser>(token))
      return true;

    return (token == SutDeclParser::SutComponentID
            || token == SutDeclParser::SutID);
  }
};

class ComCreateSutProposals::Private
{
  friend class ComCreateSutProposals;

  QString         _sutDocText;
  bool            _strictErrorHandling;
  DslProposalList _sutProposals;

  Private(const QString& sutDocText,
          bool strictErrorHandling)
    : _sutDocText(sutDocText),
      _strictErrorHandling(strictErrorHandling)
  {}
};

ComCreateSutProposals::ComCreateSutProposals(const QString& sutDocText,
                                             bool strictErrorHandling,
                                             QObject *parent)
  : QObject(parent), _d(new Private(sutDocText, strictErrorHandling))
{

}

ComCreateSutProposals::~ComCreateSutProposals()
{
  delete this->_d;
}

bool ComCreateSutProposals::execute(QString* errorString)
{
  //  qDebug() << "calculating proposals for: " << this->_d->_sutDocText;

  TestSuite testSuiteModel;
  SutItem* sutModel=testSuiteModel.sutItem();
  Q_ASSERT(sutModel);
  ComBuildSutModel buildCommand(this->_d->_sutDocText, sutModel);
  buildCommand.execute();

  ANTLRInputStream input(this->_d->_sutDocText.toStdString());
  SutDeclLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  SutDeclParser parser(&tokens);

  if(isWithinComment<SutDeclLexer>(this->_d->_sutDocText, tokens, errorString))
    return true; //is within comment -> no proposals

  parser.setBuildParseTree(false);
  parser.setErrorHandler(std::make_shared<DefaultErrorStrategy>());
  parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::LL);


  // calculating line and pos in line...
  QPair<std::size_t, int> linePos = utils::CalcPosInLine()(this->_d->_sutDocText);

  SutProposalErrorListener sutProposalErrorListener(linePos.first,
                                                    linePos.second,
                                                    &this->_d->_sutProposals,
                                                    sutModel);
  parser.removeErrorListeners();
  parser.addErrorListener(&sutProposalErrorListener);

  auto start = std::chrono::steady_clock::now();
  try
  {
    parser.sutDecl();
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

const DslProposalList& ComCreateSutProposals::sutProposals() const
{
  return this->_d->_sutProposals;
}

} // namespace common
} // namespace dslparser
