#include "comcreatediagnosisproposals.hpp"

#include "combuilddiagnosismodel.hpp"

#include <mobata/model/ts/ts.hpp>

#include <mobata/utils/functors.hpp>

#include <QDebug>
#include <QDir>

#undef emit
#undef SIGNAL

#include <antlr4/antlr4-runtime.h>
#include "DiagnosisDeclParser.h"
#include "DiagnosisDeclLexer.h"
#include "DiagnosisDeclBaseListener.h"
#include "diagnosismodellistener.hpp"
#include "mobata/model/msc/mscstepitem.hpp"
#include "mobata/model/diagnosis/diagnosisitem.hpp"

#include <mobata/memory_leak_start.hpp>

using namespace utils;
using namespace model;
using namespace model::ts;
using namespace model::base;
using namespace antlr4;

namespace dslparser {
namespace diagnosis {

class DiagnosisProposalErrorListener
        : public BaseErrorListener
{
    std::size_t         _line;
    std::size_t         _posInLine;
    bool         _inRecursivLoop = 0;
    QString             _RecursivRest = "";
    DiagnosisProposalList* _diagnosisProposals;
    QHash<QString, ModelItem *> _DiagnosisItems;
    model::diagnosis::DiagnosisItem*  _DiagnosisDeclModel;
    model::base::ModelItem *_currentSignalItem;
    model::base::ModelItem *_currentPathItem;
    ImportModelItem _importItems;
    QString _praefix;

public:
    DiagnosisProposalErrorListener(std::size_t line,
                                  int posInLine,
                                  DiagnosisProposalList* diagnosisProposals,
                                  const ImportModelItem& importItems,
                                  QHash<QString, ModelItem *> diagnosisItems,
                                  model::diagnosis::DiagnosisItem* DiagnosisDeclModel = 0,
                                  ModelItem* currentSignalItem = 0,
                                  ModelItem* currentPathItem = 0,
                                  const QString& praefix = "")
        : _line(line),
          _posInLine(posInLine),
          _diagnosisProposals(diagnosisProposals),
          _DiagnosisItems(diagnosisItems),
          _DiagnosisDeclModel(DiagnosisDeclModel),
          _currentSignalItem(currentSignalItem),
          _currentPathItem(currentPathItem),
          _importItems(importItems),
          _praefix(praefix)
    {}


protected:
    virtual void syntaxError(Recognizer* recognizer,
                             Token* offendingSymbol,
                             size_t line,
                             std::size_t charPositionInLine,
                             const std::string &msg,
                             std::exception_ptr /*e*/) override
    {
        Q_ASSERT(this->_diagnosisProposals);
        Q_UNUSED(offendingSymbol);
        Q_UNUSED(msg);

        if(line != this->_line)
            return;

        if(charPositionInLine != this->_posInLine)
            return;

        DiagnosisDeclParser* parser = static_cast<DiagnosisDeclParser*>(recognizer);
        Q_ASSERT(parser);

        const dfa::Vocabulary& vocabulary = parser->getVocabulary();
        misc::IntervalSet expTokens = parser->getExpectedTokens();
        TokenStream* stream = parser->getTokenStream();
        int i = stream->size();
        if(i>2 && !_inRecursivLoop){
            Token* lastToken = stream->get(--i);
            while(i && (lastToken->getCharPositionInLine() != _posInLine || lastToken->getLine() !=_line))
                lastToken = stream->get(--i);
            if(i) lastToken = stream->get(--i);
            while(i &&
                  (lastToken->getType() == DiagnosisDeclParser::WS
                   || lastToken->getType() == DiagnosisDeclParser::NEWLINE
                   || lastToken->getType() == DiagnosisDeclParser::IGNORE_NEWLINE))
                lastToken = stream->get(--i);
            if(lastToken->getType() == DiagnosisDeclParser::ID){
                Token* endToken = stream->get(i-1);
                while(i &&
                      (endToken->getType() == DiagnosisDeclParser::WS
                       || endToken->getType() == DiagnosisDeclParser::NEWLINE
                       || endToken->getType() == DiagnosisDeclParser::IGNORE_NEWLINE))
                    endToken = stream->get(--i);
                ANTLRInputStream input(stream->getText(stream->get(0),endToken));
                DiagnosisDeclLexer lexer(&input);
                CommonTokenStream tokens(&lexer);
                DiagnosisDeclParser parser(&tokens);
                parser.setBuildParseTree(false);
                parser.setErrorHandler(std::make_shared<DefaultErrorStrategy>());
                parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::LL);


                parser.removeErrorListeners();
                parser.addErrorListener(this);

                _line = endToken->getLine();
                _posInLine = endToken->getCharPositionInLine() + 1;
                _inRecursivLoop = true;
                _RecursivRest += QString::fromStdString(lastToken->getText());
                parser.diagnosisDecl();
                //didn't see a better solve...
            }
            else if(lastToken->getType() == DiagnosisDeclParser::COLON){
                while(i &&
                      (lastToken->getType() == DiagnosisDeclParser::WS
                       || lastToken->getType() == DiagnosisDeclParser::NEWLINE
                       || lastToken->getType() == DiagnosisDeclParser::IGNORE_NEWLINE))
                    lastToken = stream->get(--i);
            }
        }
        for (auto token : expTokens.toList())
        {
            if(token == DiagnosisDeclParser::ID && !_inRecursivLoop)
            {
                ParserRuleContext* ruleCtx = parser->getRuleContext();
                if(ruleCtx->getRuleIndex() == DiagnosisDeclParser::RuleNameDecl)
                    continue;
                else if(ruleCtx->getRuleIndex() == DiagnosisDeclParser::RuleMessageDecl)
                    this->modelLinkingDecl(stream,ruleCtx->getSourceInterval().a,0,false);
                else if(ruleCtx->getRuleIndex() == DiagnosisDeclParser::RuleIdPath)
                    this->portLinkingDecl(stream);
                //else if(ruleCtx->getRuleIndex() == DiagnosisDeclParser::RuleDataBody)
                //    this->modelLinkingDecl(stream,ruleCtx->getSourceInterval().a,_currentSignalItem,false);
                else if (ruleCtx->getRuleIndex() == DiagnosisDeclParser::RuleImportFileBody)
                    this->getFile(stream);
            }
            else
            {//keywords
                QString displayName = QString::fromStdString(vocabulary.getDisplayName(token)).trimmed();
                if(displayName.startsWith("'"))
                    displayName.remove(0,1);
                if(displayName.endsWith("'"))
                    displayName.remove(displayName.size()-1,1);
                if(canBeAutoCompleted(&displayName)){

                    this->_diagnosisProposals->append(DiagnosisProposal(displayName,
                                                                      diagnosisTokenType(token)));
                }
            }
        }
        ///sort alphabetically
        qSort(this->_diagnosisProposals->begin(), this->_diagnosisProposals->end());
        //    std::vector<std::string> ruleInvocationStack = parser->getRuleInvocationStack();
        //    for(const std::string& rule : ruleInvocationStack)
        //      qDebug()<<"rule-invocation: "<<rule.c_str();
        _inRecursivLoop = false;
        return;
    }


    bool canBeAutoCompleted(QString* completionTarget){
        if(!_inRecursivLoop) return true;
        int q_sz = _RecursivRest.size();
        QString test = *completionTarget;
        test.resize(q_sz);
        if(test != _RecursivRest) return false;
        completionTarget->remove(0,q_sz);
        return true;
    }

    //void signalLinkingDecl(TokenStream* tokens,int a){
    //    for(int i = a;i>0;i--){
    //        Token* token = tokens->get(i);
    //        if(token->getType() == DiagnosisDeclParser::SEMI)
    //            modelLinkingDecl(tokens,a,0);
    //        else if(token->getType() == DiagnosisDeclParser::RBRACE)
    //            modelLinkingDecl(tokens,a,0);
    //        else if(token->getType() == DiagnosisDeclParser::DataID)
    //            modelLinkingDecl(tokens,a,_currentSignalItem);
    //    }
    //}

    void modelLinkingDecl(TokenStream* tokens,int a,ModelItem* item,bool inSteps){
        int t_sz = tokens->size();
        int i = a;
        bool end = false;
        if(!this->_DiagnosisDeclModel)
            return;
        ModelItem* model = item;
        QString rest = "";
        bool failure = false;
        while(i<t_sz && !end){
            for(int j = i;j<t_sz;i++){
                Token* token = tokens->get(i);
                if(token->getType() == DiagnosisDeclParser::COMMA){
                    model = _currentSignalItem;
                    j = t_sz;
                }
                else if(token->getType() == DiagnosisDeclParser::ID){
                    if(token->getLine()>=this->_line
                            && (token->getText().size()+token->getCharPositionInLine())
                            >this->_posInLine){
                        end = true;
                        rest = QString::fromStdString(token->getText());
                    }
                    else{
                        QString modelname = QString::fromStdString(token->getText());
                        model = getComponent(model,modelname);
                        failure = !model;
                    }
                }
                j++;
            }
        }
        int q_sz = rest.size();
        if(failure) return;
        QHash<QString, ModelItem*> models = getComponents(model);
        foreach (QString option, models.keys()) {
            if(inSteps){
                if(!dynamic_cast<msc::MscStepItem*>(models.value(option)))
                    continue;
            }
            QString test = option;
            test.resize(q_sz);
            if(test == rest)
                this->_diagnosisProposals->append(
                        DiagnosisProposal(
                            option.remove(0,q_sz),Identifier));
        }
        return;
    }

    void portLinkingDecl(TokenStream* tokens){
        int t_sz = tokens->size();
        int i = t_sz-1;
        QStack<QString> components;
        while(tokens->get(i)->getType() != DiagnosisDeclParser::ID &&
              tokens->get(i)->getType() != DiagnosisDeclParser::DOT &&
              tokens->get(i)->getType() != DiagnosisDeclParser::COLON &&
              i>0
              ) i--;
        int dots = 0;
        while((tokens->get(i)->getType() == DiagnosisDeclParser::ID ||
               tokens->get(i)->getType() == DiagnosisDeclParser::DOT) &&
              i>0
              ){
            if(tokens->get(i)->getType() == DiagnosisDeclParser::ID){
                components.push_front(QString::fromStdString(tokens->get(i)->getText()));
            }
            else dots++;
            i--;
        }
        ModelItem* model = 0;
        bool failure = false;
        QString rest = "";
        while(components.size()>0 && dots>0 && !failure){
            QString modelname = components.at(0);
            model = getComponent(model,modelname);
            components.pop_front();
            dots--;
            failure = !model;
        }
        if(components.size()==1) rest = components.at(0);
        if(failure) return;
        int q_sz = rest.size();
        QHash<QString, ModelItem*> models = getComponents(model);
        foreach (QString option, models.keys()) {
            QString test = option;
            test.resize(q_sz);
            if(test == rest)
                this->_diagnosisProposals->append(
                        DiagnosisProposal(
                            option.remove(0,q_sz),Identifier));
        }
        return;
    }

    ModelItem* getComponent(ModelItem* model,QString name){
        QHash<QString, ModelItem*> models = getComponents(model);
        return models.value(name);
    }

    QHash<QString, ModelItem*> getComponents(ModelItem* model){
        QHash<QString, ModelItem*> models;
        if(!model){
            for (const QString& m : this->_importItems.keys()) {
                models.insert(m,_importItems.value(m));
            }
            for (const QString& m : this->_DiagnosisItems.keys()) {
                models.insert(m,_DiagnosisItems.value(m));
            }
            for (const auto& s_ignal : this->_DiagnosisDeclModel->getSignals()) {
                models.insert(s_ignal->name(),s_ignal);
            }
        }
        if(model::diagnosis::DiagnosisItem* item = dynamic_cast<model::diagnosis::DiagnosisItem*>(model)){
            auto s_ignals = item->getSignals();
            int sz = s_ignals.size();
            for(int i = 0;i<sz;i++){
                models.insert(s_ignals.at(i)->name(),s_ignals.at(i));
            }
        }
        else if(TestSystemItem* item = dynamic_cast<TestSystemItem*>(model)){
            auto components = item->components();
            int sz = components.size();
            for(int i = 0;i<sz;i++){
                models.insert(components.at(i)->name(),components.at(i));
            }
        }
        else if(TestComponentItem* item = dynamic_cast<TestComponentItem*>(model)){
            auto ports = item->ports();
            int sz = ports.size();
            for(int i = 0;i<sz;i++){
                models.insert(ports.at(i)->name(),ports.at(i));
            }
        }
        else if(SignalItem* item = dynamic_cast<SignalItem*>(model)){
            auto params = item->params();
            int sz = params.size();
            for(int i = 0;i<sz;i++){
                models.insert(params.at(i)->name(),params.at(i));
            }
        }
        else if(SutItem* item = dynamic_cast<SutItem*>(model)){
            auto components = item->components();
            int sz = components.size();
            for(int i = 0;i<sz;i++){
                models.insert(components.at(i)->name(),components.at(i));
            }
        }
        else if(SutComponentItem* item = dynamic_cast<SutComponentItem*>(model)){
            auto ports = item->ports();
            int sz = ports.size();
            for(int i = 0;i<sz;i++){
                models.insert(ports.at(i)->name(),ports.at(i));
            }
        }
        return models;
    }

    void getFile(TokenStream* tokens){
        bool end = false;
        QString curPath("");
        QStringList curList;
        int sz = tokens->size();
        int i = 0;
        while(i<sz && !end){
            for(int j=i;j<sz;i++){
                Token* token = tokens->get(i);
                if(token->getType() == DiagnosisDeclParser::ImportID){
                    j=sz;
                }
                if(token->getLine()>=this->_line
                        && token->getCharPositionInLine() > this->_posInLine){
                    break;
                }
                j++;
            }
            for(int j = i;j<sz;i++){
                Token* token = tokens->get(i);
                if(token->getType() == DiagnosisDeclParser::GREATERTHAN){
                    curPath.clear();
                    curList.clear();
                    j = sz;
                }
                else if(token->getType() == DiagnosisDeclParser::ID ||
                        token->getType() == DiagnosisDeclParser::RANGE){
                    if(token->getLine()>=this->_line
                            && (token->getText().size()+token->getCharPositionInLine())
                            >this->_posInLine){
                        end = true;
                        curPath = QString::fromStdString(token->getText());
                    }
                    else{
                        QString modelname = QString::fromStdString(token->getText());
                        curList.append(modelname);
                    }
                }
                j++;
            }
        }

        QDir homeDir(this->_praefix);
        int sz2 = curList.size();
        i = 0;
        bool test = true;
        while (i<sz2 && test) {
            test = homeDir.cd(curList.at(i));
            if(!test) curPath = curList.at(i);
            i++;
        }

        if(i < sz2 && !test) return;
        sz = curPath.size();
        QStringList list = homeDir.entryList();
        foreach (QString option, list) {
            QString test = option;
            test.resize(sz);
            if(test == curPath)
                this->_diagnosisProposals->append(
                        DiagnosisProposal(
                            option.remove(0,sz),RefSignal));
        }
    }
};

class ComCreateDiagnosisProposals::Private
{
    friend class ComCreateDiagnosisProposals;

    QString               _diagnosisDocText;
    QString               _praefix;
    bool                  _strictErrorHandling;
    DiagnosisProposalList  _diagnosisProposals;

    Private(const QString& diagnosisDocText,
            const QString& praefix,
            bool strictErrorHandling)
        : _diagnosisDocText(diagnosisDocText),
          _praefix(praefix),
          _strictErrorHandling(strictErrorHandling)
    {}
};

ComCreateDiagnosisProposals::ComCreateDiagnosisProposals(const QString& diagnosisDocText,
                                                       const QString& praefix,
                                                       bool strictErrorHandling,
                                                       QObject* parent)
    : QObject(parent), _d(new Private(diagnosisDocText, praefix, strictErrorHandling))
{

}

ComCreateDiagnosisProposals::~ComCreateDiagnosisProposals()
{
    delete this->_d;
}

bool isWithinComment(const QString& diagnosisText,
                     CommonTokenStream& tokens,
                     QString* errorString)
{
  if(diagnosisText.isEmpty())
    return false;

  uint pos = diagnosisText.size();
  if(diagnosisText.midRef(pos - 2, 2) == QStringLiteral("*/"))
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
        if(tokenType == DiagnosisDeclLexer::LINE_COMMENT
                || tokenType == DiagnosisDeclLexer::COMMENT)
        {
            if(token->getStartIndex() <= pos
                    && pos <= (token->getStopIndex()+1))
                return true;
        }
    }

    return false;
}

bool ComCreateDiagnosisProposals::execute(QString* errorString)
{
    //  qDebug() << "calculating proposals for: " << this->_d->_DiagnosisDocText;

    model::diagnosis::DiagnosisItem diagnosisModel("Diagnosis");


    ComBuildDiagnosisModel buildCommand(this->_d->_diagnosisDocText, &diagnosisModel,this->_d->_praefix);
    buildCommand.execute();

    ANTLRInputStream input(this->_d->_diagnosisDocText.toStdString());
    DiagnosisDeclLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    DiagnosisDeclParser parser(&tokens);

    if(isWithinComment(this->_d->_diagnosisDocText, tokens, errorString))
        return true; //is within comment -> no proposals

    parser.setBuildParseTree(false);
    parser.setErrorHandler(std::make_shared<DefaultErrorStrategy>());
    parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::LL);


    // calculating line and pos in line...
    QPair<std::size_t, int> linePos = utils::CalcPosInLine()(this->_d->_diagnosisDocText);

    DiagnosisProposalErrorListener diagnosisProposalErrorListener(linePos.first,
                                                                linePos.second,
                                                                &this->_d->_diagnosisProposals,
                                                                buildCommand.importItems(),
                                                                buildCommand.diagnosisItems(),
                                                                &diagnosisModel,
                                                                buildCommand.currentSignalItem(),
                                                                buildCommand.currentPathItem(),
                                                                this->_d->_praefix);
    parser.removeErrorListeners();
    parser.addErrorListener(&diagnosisProposalErrorListener);
    auto start = std::chrono::steady_clock::now();
    try
    {
        parser.diagnosisDecl();
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

const DiagnosisProposalList& ComCreateDiagnosisProposals::diagnosisProposals() const
{
    return this->_d->_diagnosisProposals;
}

} // namespace common
} // namespace dslparser
