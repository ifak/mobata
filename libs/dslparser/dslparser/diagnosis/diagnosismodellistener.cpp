#include "diagnosismodellistener.hpp"
#include "DiagnosisDeclLexer.h"

#include <mobata/model/ts/ts.hpp>
#include <mobata/model/msc/msccheckmessageitem.hpp>
#include <dslparser/diagnosis/combuilddiagnosismodel.hpp>
#include <dslparser/testsystem/combuildtestsystemmodel.hpp>
#include <mobata/model/msc/msc_types.hpp>
#include <mobata/model/msc/mscsequenceitem.hpp>
#include <mobata/model/msc/msctimeoutitem.hpp>
#include <mobata/model/diagnosis/diagcomponentitem.hpp>
#include <mobata/model/diagnosis/diagnosisitem.hpp>
#include <mobata/model/diagnosis/diagsequenceruleitem.hpp>
#include <mobata/model/msc/mscloopfragmentitem.hpp>
#include <mobata/model/diagnosis/diagsignalitem.hpp>
#include <mobata/prop/nameproperty.hpp>

#include <QStack>
#include <QDebug>
#include <QFile>
#include <QFileInfo>

#include <mobata/memory_leak_start.hpp>

using namespace model::ts;
using namespace model::base;
using namespace antlr4;

namespace dslparser {
namespace diagnosis {

using common::addKeywordLocation;

class DiagnosisModelListener::Private
{
    friend class DiagnosisModelListener;

    //imported files
    QString*                                    _importedSutFileName;
    QString*                                    _importedTestSystemFileName;

    ///parse data////
    ModelItem*                                  _currentItem = 0;
    ModelItem*                                  _currentRuleItem;
    ModelItem*                                  _currentPathItem;
    QStack<model::msc::MscFragmentRegionItem*>  _currentReg;
    QStack<model::msc::MscFragmentItem*>        _currentArea;
    ImportModelItem                             _importItems;
    QString                                     _praefix;
    bool                                        _isInData = false;
    bool                                        _isInDecl = false;
    QHash<model::base::ModelItem*,QVector<int>> _modelPositionOfCheck;
    QHash<QString,model::base::ModelItem*>      _diagnosisItems;
    model::base::ModelItem*                     _currentSignal = 0;

    Private(QString* importedSutFileName,
            QString* importedTestSystemFileName,
            const QString& praefix)
        : _importedSutFileName(importedSutFileName),
          _importedTestSystemFileName(importedTestSystemFileName),
          _currentRuleItem(0),
          _currentPathItem(0),
          _importItems(),
          _praefix(praefix)
    {}
};



DiagnosisModelListener::DiagnosisModelListener(model::diagnosis::DiagnosisItem* diagnosisDeclModel,
                                               DslErrorList* diagnosisErrors,
                                               QString* importedSutFileName,
                                               QString* importedTestSystemFileName,
                                               const QString& praefix,
                                               TokenTextLocations* keywordTextLocations,
                                               ModelTextLocations* modelTextLocations)
    : BaseClass(diagnosisDeclModel, diagnosisErrors, keywordTextLocations, modelTextLocations),
      _d(new Private(importedSutFileName, importedTestSystemFileName, praefix))
{}


DiagnosisModelListener::~DiagnosisModelListener()
{
    delete this->_d;
}

ModelItem* DiagnosisModelListener::currentPathItem()
{
    return this->_d->_currentPathItem;
}

ModelItem* DiagnosisModelListener::currentSignalItem()
{
    return this->_d->_currentSignal;
}

const QHash<QString, ModelItem*>& DiagnosisModelListener::diagnosisItems()
{
    return this->_d->_diagnosisItems;
}

const ImportModelItem& DiagnosisModelListener::importItems()
{
    return this->_d->_importItems;
}

void DiagnosisModelListener::enterDiagnosisDecl(DiagnosisDeclParser::DiagnosisDeclContext* ctx)
{
    Q_UNUSED(ctx);
    this->_model->addComponent(new model::diagnosis::DiagComponentItem(QStringLiteral("Any")));
    this->_listenerStates.push(DiagnosisDeclState);

    return;
}

void DiagnosisModelListener::enterRuleBody(DiagnosisDeclParser::RuleBodyContext *ctx)
{
    Q_UNUSED(ctx);
    model::diagnosis::DiagnosisSequenceRuleItem* rule = new model::diagnosis::DiagnosisSequenceRuleItem(QStringLiteral("testrule"));
    _d->_currentRuleItem = rule;
    _d->_currentItem = rule;
    _model->addRule(rule);
}

void DiagnosisModelListener::exitRuleDecl(DiagnosisDeclParser::RuleDeclContext *ctx)
{
    Q_ASSERT(ctx);

    if(ctx->exception)
        return;//an error occured! -> but still handled by error listener!

    this->_listenerStates.pop();

    Q_ASSERT(_d->_currentRuleItem);
    this->_modelTextLocations->insert(_d->_currentRuleItem->index(),
                                      TokenTextLocation(ctx->getStart()->getStartIndex(),
                                                        ctx->getStop()->getStopIndex(),
                                                        Rule));


    typedef  tree::TerminalNode* (DiagnosisDeclParser::RuleDeclContext::*KeywordFunction)();

    return addKeywordLocation<DiagnosisDeclParser::RuleDeclContext, KeywordFunction, TokenTextLocations>
            (ctx, &DiagnosisDeclParser::RuleDeclContext::RuleID, this->_keywordTextLocations, Diagnosis);
}

void DiagnosisModelListener::exitDescriptionDecl(DiagnosisDeclParser::DescriptionDeclContext *ctx)
{
    typedef  tree::TerminalNode* (DiagnosisDeclParser::DescriptionDeclContext::*KeywordFunction)();

    addKeywordLocation<DiagnosisDeclParser::DescriptionDeclContext, KeywordFunction, TokenTextLocations>
            (ctx, &DiagnosisDeclParser::DescriptionDeclContext::DescriptionID, this->_keywordTextLocations, Description);
}

void DiagnosisModelListener::exitRuleBody(DiagnosisDeclParser::RuleBodyContext *ctx)
{
    if(!ctx || ctx->exception) return;
    Q_ASSERT(_d->_currentRuleItem);
    ((model::diagnosis::DiagnosisSequenceRuleItem*)_d->_currentRuleItem)->setDescription(QString::fromStdString(ctx->descriptionDecl()->STRING()->getText()).remove("\""));
    typedef  tree::TerminalNode* (DiagnosisDeclParser::RuleBodyContext::*KeywordFunction)();

    addKeywordLocation<DiagnosisDeclParser::RuleBodyContext, KeywordFunction, TokenTextLocations>
            (ctx, &DiagnosisDeclParser::RuleBodyContext::DeclarationID, this->_keywordTextLocations, Declaration);

}

void DiagnosisModelListener::exitBasetypeDecl(DiagnosisDeclParser::BasetypeDeclContext *ctx)
{
    typedef  tree::TerminalNode* (DiagnosisDeclParser::BasetypeDeclContext::*KeywordFunction)();

    addKeywordLocation<DiagnosisDeclParser::BasetypeDeclContext, KeywordFunction, TokenTextLocations>
            (ctx, &DiagnosisDeclParser::BasetypeDeclContext::BasetypeID, this->_keywordTextLocations, Basetype);

}

void DiagnosisModelListener::exitCheckDecl(DiagnosisDeclParser::CheckDeclContext *ctx)
{
    typedef  tree::TerminalNode* (DiagnosisDeclParser::CheckDeclContext::*KeywordFunction)();
    if(ctx->ConditionID()){
        addKeywordLocation<DiagnosisDeclParser::CheckDeclContext, KeywordFunction, TokenTextLocations>
                (ctx, &DiagnosisDeclParser::CheckDeclContext::ConditionID, this->_keywordTextLocations, Check);
    }

}

void DiagnosisModelListener::exitSequenceDecl(DiagnosisDeclParser::SequenceDeclContext *ctx)
{
    typedef  tree::TerminalNode* (DiagnosisDeclParser::SequenceDeclContext::*KeywordFunction)();

    addKeywordLocation<DiagnosisDeclParser::SequenceDeclContext, KeywordFunction, TokenTextLocations>
            (ctx, &DiagnosisDeclParser::SequenceDeclContext::SequenceID, this->_keywordTextLocations, Sequence);

}

void DiagnosisModelListener::enterDeclarations(DiagnosisDeclParser::DeclarationsContext *ctx)
{
    if(ctx->exception)
        return;
    _d->_isInDecl = true;
}

void DiagnosisModelListener::exitDeclarations(DiagnosisDeclParser::DeclarationsContext *ctx)
{
    if(ctx->exception)
        return;
    _d->_isInDecl = false;
}

void DiagnosisModelListener::enterNameDecl(DiagnosisDeclParser::NameDeclContext* ctx)
{
    Q_ASSERT(ctx);

    if(ctx->exception)
        return;//an error occured! -> but still handled by error listener!

    typedef  tree::TerminalNode* (DiagnosisDeclParser::NameDeclContext::*KeywordFunction)();

    return addKeywordLocation<DiagnosisDeclParser::NameDeclContext, KeywordFunction, TokenTextLocations>
            (ctx, &DiagnosisDeclParser::NameDeclContext::NameID, this->_keywordTextLocations, Attribute);
}

void DiagnosisModelListener::exitNameDecl(DiagnosisDeclParser::NameDeclContext* ctx)
{
    Q_ASSERT(ctx);

    if(ctx->exception)
        return;//an error occured! -> but still handled by error listener!

    Q_ASSERT(ctx->ID());

    QString name=QString::fromStdString(ctx->ID()->getText());
    if(this->_d->_currentItem){
        if(prop::NameProperty* item = dynamic_cast<prop::NameProperty*>(_d->_currentItem)){
            item->setName(name);
        }
        else{
            Token* startToken = ctx->getStart();
            Token* stopToken = ctx->getStop();
            Q_ASSERT(startToken);
            Q_ASSERT(stopToken);
            if(this->_errors){
                this->_errors->append(DslError(QString("Tried to declare a name for a non-existing modelitem!"),
                                               startToken->getLine(),
                                               startToken->getCharPositionInLine()));
            }
        }
    }
    return;
}

void DiagnosisModelListener::exitEnabledDecl(DiagnosisDeclParser::EnabledDeclContext *ctx)
{
    Q_ASSERT(ctx);

    if(ctx->exception)
        return;//an error occured! -> but still handled by error listener!
    bool en = (!ctx->FalseID());
    if(_d->_currentItem) {
        _d->_currentItem->setEnabled(en);
        _d->_currentItem = 0;
    }
    else{
        Token* startToken = ctx->getStart();
        Token* stopToken = ctx->getStop();
        Q_ASSERT(startToken);
        Q_ASSERT(stopToken);
        if(this->_errors){
            this->_errors->append(DslError(QString("Tried to declare a enabled for a non-existing modelitem!"),
                                           startToken->getLine(),
                                           startToken->getCharPositionInLine()));
        }
        return;
    }

    typedef  tree::TerminalNode* (DiagnosisDeclParser::EnabledDeclContext::*KeywordFunction)();

    addKeywordLocation<DiagnosisDeclParser::EnabledDeclContext, KeywordFunction, TokenTextLocations>
            (ctx, &DiagnosisDeclParser::EnabledDeclContext::EnabledID, this->_keywordTextLocations, Enabled);

}

void DiagnosisModelListener::exitImportPathBody(DiagnosisDeclParser::ImportPathBodyContext *ctx)
{
    if(ctx->exception || !ctx->importFileBody())
        return;
    typedef  tree::TerminalNode* (DiagnosisDeclParser::ImportPathBodyContext::*KeywordFunction)();

    addKeywordLocation<DiagnosisDeclParser::ImportPathBodyContext, KeywordFunction, TokenTextLocations>
            (ctx, &DiagnosisDeclParser::ImportPathBodyContext::ImportID, this->_keywordTextLocations, Import);

    QString path = QString::fromStdString(ctx->importFileBody()->getText());
    path = _d->_praefix + path;
    QFile file(path);
    if(!file.open(QFile::ReadOnly))
        qDebug()<<"file '"<<path<<"' could not be opened!";
    QString docText(file.readAll());
    file.close();

    if(path.endsWith(QString("components")))
    {
        QString name;
        if(ctx->importAs() && ctx->importAs()->ID()){
            name = QString::fromStdString(ctx->importAs()->ID()->getText());
        }
        else{
            name = path;
        }
        model::diagnosis::DiagnosisItem* diagModel = new model::diagnosis::DiagnosisItem(name/*,_model*/);
        dslparser::diagnosis::ComBuildDiagnosisModel command(docText, diagModel,_d->_praefix);
        QString errorString;
        bool result = command.execute(&errorString,dslparser::diagnosis::ComBuildDiagnosisModel::FileType::Components);
        if(result){
            this->_d->_importItems.insert(name,diagModel);
            this->_model->addImportItem(diagModel);
        }
        else
        {
            Token* startToken = ctx->getStart();
            Token* stopToken = ctx->getStop();
            Q_ASSERT(startToken);
            Q_ASSERT(stopToken);
            if(this->_errors){
                this->_errors->append(DslError(QString("Import File contains errors..."),
                                               startToken->getLine(),
                                               startToken->getCharPositionInLine()));
                this->_errors->append(command.errors());
            }
        }
    }
    else if(path.endsWith(QString("signals")))
    {
        QString name;
        if(ctx->importAs() && ctx->importAs()->ID()){
            name = QString::fromStdString(ctx->importAs()->ID()->getText());
        }
        else{
            name = path;
        }
        model::diagnosis::DiagnosisItem* diagModel = new model::diagnosis::DiagnosisItem(name/*,_model*/);
        dslparser::diagnosis::ComBuildDiagnosisModel command(docText, diagModel,_d->_praefix);
        QString errorString;
        bool result = command.execute(&errorString,dslparser::diagnosis::ComBuildDiagnosisModel::FileType::Signals);
        if(result){
            this->_d->_importItems.insert(name,diagModel);
            this->_model->addImportItem(diagModel);
        }
        else
        {
            Token* startToken = ctx->getStart();
            Token* stopToken = ctx->getStop();
            Q_ASSERT(startToken);
            Q_ASSERT(stopToken);
            if(this->_errors){
                this->_errors->append(DslError(QString("Import File contains errors..."),
                                               startToken->getLine(),
                                               startToken->getCharPositionInLine()));
                this->_errors->append(command.errors());
            }
        }
    }
    else if(path.endsWith(QString("decl"))){

    }

}

void DiagnosisModelListener::exitAliasDef(DiagnosisDeclParser::AliasDefContext *ctx)
{
    if(ctx->exception)
        return;
    if(getItemFromPath(ctx->idPath())){
        _d->_diagnosisItems.insert(QString::fromStdString(ctx->ID()->getText()),_d->_currentPathItem);
    }

    typedef  tree::TerminalNode* (DiagnosisDeclParser::AliasDefContext::*KeywordFunction)();

    return addKeywordLocation<DiagnosisDeclParser::AliasDefContext, KeywordFunction, TokenTextLocations>
            (ctx, &DiagnosisDeclParser::AliasDefContext::UseID, this->_keywordTextLocations, Use);

}



void DiagnosisModelListener::exitParallelDecl(DiagnosisDeclParser::ParallelDeclContext *ctx)
{
    if(!ctx)
        return;
    this->_modelTextLocations->insert(this->_d->_currentArea.at(0)->index(),
                                      TokenTextLocation(ctx->getStart()->getStartIndex(),
                                                        ctx->getStop()->getStopIndex(),
                                                        Parallel));
    _d->_currentArea.pop_front();


    typedef  tree::TerminalNode* (DiagnosisDeclParser::ParallelDeclContext::*KeywordFunction)();

    addKeywordLocation<DiagnosisDeclParser::ParallelDeclContext, KeywordFunction, TokenTextLocations>
            (ctx, &DiagnosisDeclParser::ParallelDeclContext::ParallelID, this->_keywordTextLocations, Parallel);

}

void DiagnosisModelListener::enterParallelBody(DiagnosisDeclParser::ParallelBodyContext *ctx)
{
    if(!ctx)
        return;
    _d->_currentReg.push_front(new model::msc::MscFragmentRegionItem(""));
    _d->_currentArea.at(0)->addRegion(_d->_currentReg.at(0));
}

void DiagnosisModelListener::exitParallelBody(DiagnosisDeclParser::ParallelBodyContext *ctx)
{
    if(ctx->exception)
        return;
    this->_modelTextLocations->insert(_d->_currentReg.at(0)->index(),
                                      TokenTextLocation(ctx->getStart()->getStartIndex(),
                                                        ctx->getStop()->getStopIndex(),
                                                        Region));

    _d->_currentReg.pop_front();
    typedef  tree::TerminalNode* (DiagnosisDeclParser::ParallelBodyContext::*KeywordFunction)();

    addKeywordLocation<DiagnosisDeclParser::ParallelBodyContext, KeywordFunction, TokenTextLocations>
            (ctx, &DiagnosisDeclParser::ParallelBodyContext::ParallelSequenceID, this->_keywordTextLocations, ParallelSequence);

}

void DiagnosisModelListener::enterParallelDecl(DiagnosisDeclParser::ParallelDeclContext *ctx)
{
    if(!ctx)
        return;
    _d->_currentArea.push_front(new model::msc::MscFragmentItem(model::msc::FragmentType::ParallelFragment));
    if(model::diagnosis::DiagnosisSequenceRuleItem* rule = dynamic_cast<model::diagnosis::DiagnosisSequenceRuleItem*>(_d->_currentRuleItem))
        if(_d->_currentReg.size()){
            _d->_currentReg.at(0)->addFragment(_d->_currentArea.at(0));
        }
        else rule->addFragment(_d->_currentArea.at(0));
    else{
        Token* startToken = ctx->getStart();
        Token* stopToken = ctx->getStop();
        Q_ASSERT(startToken);
        Q_ASSERT(stopToken);
        if(this->_errors)
            this->_errors->append(DslError(QString("Sequence-Object \"Parallel\" can't be added to non-sequence Rule!"),
                                           startToken->getLine(),
                                           startToken->getCharPositionInLine()));
        return;
    }
    typedef  tree::TerminalNode* (DiagnosisDeclParser::ParallelDeclContext::*KeywordFunction)();

    addKeywordLocation<DiagnosisDeclParser::ParallelDeclContext, KeywordFunction, TokenTextLocations>
            (ctx, &DiagnosisDeclParser::ParallelDeclContext::ParallelID, this->_keywordTextLocations, Parallel);

}

void DiagnosisModelListener::enterLoopDecl(DiagnosisDeclParser::LoopDeclContext *ctx)
{
    if(!ctx)
        return;
    QString condtion = QString::fromStdString(ctx->getText());
    int i = 0;
    bool open = false;
    while((i<condtion.size())&&condtion.at(i)!=QStringLiteral("]")){
        if(!open){
            open = condtion.at(0)==QStringLiteral("[");
            condtion.remove(0,1);
        }
        else i++;
    }
    condtion.chop(condtion.size() - i);
    _d->_currentArea.push_front((model::msc::MscFragmentItem*)new model::msc::MscLoopFragmentItem(condtion));
    if(model::diagnosis::DiagnosisSequenceRuleItem* rule = dynamic_cast<model::diagnosis::DiagnosisSequenceRuleItem*>(_d->_currentRuleItem)){
        if(_d->_currentReg.size()){
            _d->_currentReg.at(0)->addFragment(_d->_currentArea.at(0));
        }
        else rule->addFragment(_d->_currentArea.at(0));
        _d->_currentReg.append(_d->_currentArea.at(0)->regions().at(0));
    }
    else{
        Token* startToken = ctx->getStart();
        Token* stopToken = ctx->getStop();
        Q_ASSERT(startToken);
        Q_ASSERT(stopToken);
        if(this->_errors)
            this->_errors->append(DslError(QString("Sequence-Object \"Loop\" can't be added to non-sequence Rule!"),
                                           startToken->getLine(),
                                           startToken->getCharPositionInLine()));
        return;
    }
}

void DiagnosisModelListener::exitLoopDecl(DiagnosisDeclParser::LoopDeclContext *ctx)
{
    if(!ctx)
        return;
    this->_modelTextLocations->insert(this->_d->_currentArea.at(0)->index(),
                                      TokenTextLocation(ctx->getStart()->getStartIndex(),
                                                        ctx->getStop()->getStopIndex(),
                                                        Loop));
    _d->_currentArea.pop_front();
    _d->_currentReg.pop_front();

    typedef  tree::TerminalNode* (DiagnosisDeclParser::LoopDeclContext::*KeywordFunction)();

    addKeywordLocation<DiagnosisDeclParser::LoopDeclContext, KeywordFunction, TokenTextLocations>
            (ctx, &DiagnosisDeclParser::LoopDeclContext::LoopID, this->_keywordTextLocations, Loop);
}

void DiagnosisModelListener::exitMessageDecl(DiagnosisDeclParser::MessageDeclContext *ctx)
{
    if(ctx->exception)
        return;
    if(!ctx->idPath()){
        Token* startToken = ctx->getStart();
        Token* stopToken = ctx->getStop();
        Q_ASSERT(startToken);
        Q_ASSERT(stopToken);
        if(this->_errors)
            this->_errors->append(DslError(QString("Every Message must have a Signal!"),
                                           startToken->getLine(),
                                           startToken->getCharPositionInLine()));
        return;
    }
    getItemFromPath(ctx->idPath());
    model::base::SignalItem* signal = 0;
    if((signal = dynamic_cast<model::base::SignalItem*>(_d->_currentPathItem)));
    else{
        Token* startToken = ctx->getStart();
        Token* stopToken = ctx->getStop();
        Q_ASSERT(startToken);
        Q_ASSERT(stopToken);
        if(this->_errors)
            this->_errors->append(DslError(QString("Item isn't a Signal!"),
                                           startToken->getLine(),
                                           startToken->getCharPositionInLine()));
        return;
    }
    PortItem* source = 0;
    PortItem* target = 0;

    DiagnosisDeclParser::IdPathContext* from = findCompareValue(ctx->expression(),DiagnosisDeclParser::FromID);
    if(getItemFromPath(from)){
        if(PortItem* item = dynamic_cast<PortItem*>(_d->_currentPathItem)){
            source = item;
        }
        else if(model::msc::MscComponentItem* item = dynamic_cast<model::msc::MscComponentItem*>(_d->_currentPathItem)){
            source = (PortItem*)item->defaultPort();
        }
        else{
            Token* startToken = ctx->getStart();
            Token* stopToken = ctx->getStop();
            Q_ASSERT(startToken);
            Q_ASSERT(stopToken);
            if(this->_errors)
                this->_errors->append(DslError(QString("Couldn't convert source to \'PortItem\'"),
                                               startToken->getLine(),
                                               startToken->getCharPositionInLine()));
            return;
        }
    }
    else{
        Token* startToken = ctx->getStart();
        Token* stopToken = ctx->getStop();
        Q_ASSERT(startToken);
        Q_ASSERT(stopToken);
        if(this->_errors)
            this->_errors->append(DslError(QString("Couldn't find source at Path"),
                                           startToken->getLine(),
                                           startToken->getCharPositionInLine()));
        return;
    }

    DiagnosisDeclParser::IdPathContext* to = findCompareValue(ctx->expression(),DiagnosisDeclLexer::ToID);
    if(getItemFromPath(to)){
        if(PortItem* item = dynamic_cast<PortItem*>(_d->_currentPathItem)){
            target = item;
        }
        else if(model::msc::MscComponentItem* item = dynamic_cast<model::msc::MscComponentItem*>(_d->_currentPathItem)){
            target = (PortItem*)item->defaultPort();
        }
        else{
            Token* startToken = ctx->getStart();
            Token* stopToken = ctx->getStop();
            Q_ASSERT(startToken);
            Q_ASSERT(stopToken);
            if(this->_errors)
                this->_errors->append(DslError(QString("Couldn't convert target to \'PortItem\'"),
                                               startToken->getLine(),
                                               startToken->getCharPositionInLine()));
            return;
        }
    }
    else{
        Token* startToken = ctx->getStart();
        Token* stopToken = ctx->getStop();
        Q_ASSERT(startToken);
        Q_ASSERT(stopToken);
        if(this->_errors)
            this->_errors->append(DslError(QString("Couldn't find target at Path"),
                                           startToken->getLine(),
                                           startToken->getCharPositionInLine()));
        return;
    }
    CheckMessageItem* check = 0;
    QString guard = getExpression(ctx->expression());
    if(source && target){
        check = new CheckMessageItem(source,target,guard);
        check->setSignal(signal);

    }
    else{
        Token* startToken = ctx->getStart();
        Token* stopToken = ctx->getStop();
        Q_ASSERT(startToken);
        Q_ASSERT(stopToken);
        if(this->_errors)
            this->_errors->append(DslError(QString("Message needs a source AND target!"),
                                           startToken->getLine(),
                                           startToken->getCharPositionInLine()));
        return;
    }
    if(_d->_currentReg.size()){
        _d->_currentReg.at(0)->addMessage((model::msc::MscMessageItem*)check);
    }
    else{
        if(model::diagnosis::DiagnosisSequenceRuleItem* rule = dynamic_cast<model::diagnosis::DiagnosisSequenceRuleItem*>(_d->_currentRuleItem))
            rule->addMessage((model::msc::MscMessageItem*)check);
        else{
            Token* startToken = ctx->getStart();
            Token* stopToken = ctx->getStop();
            Q_ASSERT(startToken);
            Q_ASSERT(stopToken);
            if(this->_errors)
                this->_errors->append(DslError(QString("Sequence-Object \"CheckMessage\" can't be added to non-sequence Rule!"),
                                               startToken->getLine(),
                                               startToken->getCharPositionInLine()));
            return;
        }
    }
    this->_modelTextLocations->insert(check->index(),
                                      TokenTextLocation(ctx->getStart()->getStartIndex(),
                                                        ctx->getStop()->getStopIndex(),
                                                        Message));


    typedef  tree::TerminalNode* (DiagnosisDeclParser::MessageDeclContext::*KeywordFunction)();

    return addKeywordLocation<DiagnosisDeclParser::MessageDeclContext, KeywordFunction, TokenTextLocations>
            (ctx, &DiagnosisDeclParser::MessageDeclContext::MessageID, this->_keywordTextLocations, Message);

}

void DiagnosisModelListener::enterComponentDecl(DiagnosisDeclParser::ComponentDeclContext *ctx)
{
    Q_UNUSED(ctx);
    _d->_currentItem = 0;
}

void DiagnosisModelListener::exitComponentDecl(DiagnosisDeclParser::ComponentDeclContext *ctx)
{
    if(ctx->exception)
        return;
    DiagnosisDeclParser::ComponentBodyContext* body = ctx->componentBody();
    QHash<QString,QString> stringmap;
    model::diagnosis::DiagComponentItem* baseitem = 0;
    QString necguard = "";
    QString suffguard = "";
    QString name = QString::fromStdString(ctx->nameDecl()->ID()->getText());
    while(body){
        if(body->checkDecl()){
            necguard = getExpression(body->checkDecl()->necExp);
            suffguard = getExpression(body->checkDecl()->suffExp);
        }
        else if(body->basetypeDecl()){
            getItemFromPath(body->basetypeDecl()->idPath());
            if((baseitem = dynamic_cast<model::diagnosis::DiagComponentItem*>(_d->_currentPathItem)));
            else{
                Token* startToken = ctx->getStart();
                Token* stopToken = ctx->getStop();
                Q_ASSERT(startToken);
                Q_ASSERT(stopToken);
                if(this->_errors)
                    this->_errors->append(DslError(QString("BaseComponent has incompatible type!"),
                                                   startToken->getLine(),
                                                   startToken->getCharPositionInLine()));
                return;
            }
        }
        else if(body->aliasDef()){
            QString key = "";
            QString val = "";
            if(body->aliasDef()->INT()){
                key = QString::fromStdString(body->aliasDef()->INT()->getText());
            }
            else{
                key = QString::fromStdString(body->aliasDef()->idPath()->getText());
            }
            val = QString::fromStdString(body->aliasDef()->ID()->getText());
            stringmap.insert(key,val);
        }
        body = body->componentBody();
    }
    model::diagnosis::DiagComponentItem* item = new model::diagnosis::DiagComponentItem(name,necguard,suffguard);
    if(!item) return;
    if(baseitem) item->setBaseComponent(baseitem);
    for(QString key : stringmap.keys()){
        item->addAlias(key,stringmap.value(key));
    }
    if(_d->_currentRuleItem){
        ((model::diagnosis::DiagnosisSequenceRuleItem*)_d->_currentRuleItem)->addComponent(item);
    }
    else{
        _model->addComponent(item);
    }
    this->_modelTextLocations->insert(item->index(),
                                      TokenTextLocation(ctx->getStart()->getStartIndex(),
                                                        ctx->getStop()->getStopIndex(),
                                                        Component));


    typedef  tree::TerminalNode* (DiagnosisDeclParser::ComponentDeclContext::*KeywordFunction)();

    return addKeywordLocation<DiagnosisDeclParser::ComponentDeclContext, KeywordFunction, TokenTextLocations>
            (ctx, &DiagnosisDeclParser::ComponentDeclContext::ComponentID, this->_keywordTextLocations, Component);

}

void DiagnosisModelListener::enterDiagnosisSignalDecl(DiagnosisDeclParser::DiagnosisSignalDeclContext *ctx)
{
    Q_UNUSED(ctx);
    _d->_currentItem = 0;
}

void DiagnosisModelListener::exitDiagnosisSignalDecl(DiagnosisDeclParser::DiagnosisSignalDeclContext *ctx)
{
    if(ctx->exception)
        return;
    DiagnosisDeclParser::DiagnosisSignalBodyContext* body = ctx->diagnosisSignalBody();
    QHash<QString,QString> stringmap;
    model::diagnosis::DiagSignalItem* baseitem = 0;
    QString necguard = "";
    QString suffguard = "";
    QString name = QString::fromStdString(ctx->nameDecl()->ID()->getText());
    while(body){
        if(body->checkDecl()){
            necguard = getExpression(body->checkDecl()->necExp);
            suffguard = getExpression(body->checkDecl()->suffExp);
        }
        else if(body->basetypeDecl()){
            getItemFromPath(body->basetypeDecl()->idPath());
            if((baseitem = dynamic_cast<model::diagnosis::DiagSignalItem*>(_d->_currentPathItem)));
            else{
                Token* startToken = ctx->getStart();
                Token* stopToken = ctx->getStop();
                Q_ASSERT(startToken);
                Q_ASSERT(stopToken);
                if(this->_errors)
                    this->_errors->append(DslError(QString("BaseSignal has incompatible type!"),
                                                   startToken->getLine(),
                                                   startToken->getCharPositionInLine()));
                return;
            }
        }
        else if(body->aliasDef()){
            QString key = "";
            QString val = "";
            if(body->aliasDef()->INT()){
                key = QString::fromStdString(body->aliasDef()->INT()->getText());
            }
            else{
                key = QString::fromStdString(body->aliasDef()->idPath()->getText());
            }
            val = QString::fromStdString(body->aliasDef()->ID()->getText());
            stringmap.insert(key,val);
        }
        body = body->diagnosisSignalBody();
    }
    model::diagnosis::DiagSignalItem* item = new model::diagnosis::DiagSignalItem(name,necguard,suffguard);
    if(!item) return;
    if(baseitem) item->setBaseSignal(baseitem);
    for(QString key : stringmap.keys()){
        item->addAlias(key,stringmap.value(key));
    }
    if(_d->_currentRuleItem){
        ((model::diagnosis::DiagnosisSequenceRuleItem*)_d->_currentRuleItem)->addSignal((SignalItem*)item);
    }
    else{
        _model->addSignal((SignalItem*)item);
    }
    this->_modelTextLocations->insert(((SignalItem*)item)->index(),
                                      TokenTextLocation(ctx->getStart()->getStartIndex(),
                                                        ctx->getStop()->getStopIndex(),
                                                        Signal));


    typedef  tree::TerminalNode* (DiagnosisDeclParser::DiagnosisSignalDeclContext::*KeywordFunction)();

    return addKeywordLocation<DiagnosisDeclParser::DiagnosisSignalDeclContext, KeywordFunction, TokenTextLocations>
            (ctx, &DiagnosisDeclParser::DiagnosisSignalDeclContext::SignalID, this->_keywordTextLocations, Signal);

}

bool DiagnosisModelListener::getItemFromPath(DiagnosisDeclParser::IdPathContext* path, ModelItem* mItem){
    this->_d->_currentPathItem = mItem;
    if(!path || path->exception) return false;

    return false;//FIXME: next lines are temporarely comment out

//    while(path){
//        if(!path->ID()){
//            Token* startToken = path->getStart();
//            Token* stopToken = path->getStop();
//            Q_ASSERT(startToken);
//            Q_ASSERT(stopToken);
//            if(this->_errors)
//                this->_errors->append(DslError(QString("No Path There!"),
//                                               startToken->getLine(),
//                                               startToken->getCharPositionInLine()));
//            return 0;
//        }
//        QString name = QString::fromStdString(path->ID()->getText());
//        if(name == "this" || name == "timeout"){
//            path = path->idPath();
//            continue;
//        }
//        if(!this->_d->_currentPathItem){
//            if(this->_d->_importItems.contains(name)){
//                this->_d->_currentPathItem = this->_d->_importItems.value(name);
//                path = path->idPath();
//                continue;
//            }
//            else if(this->_d->_diagnosisItems.contains(name)){
//                this->_d->_currentPathItem = this->_d->_diagnosisItems.value(name);
//                path = path->idPath();
//                continue;
//            }
//            else{
//                this->_d->_currentPathItem = this->_model;
//            }
//        }
//        if(model::diagnosis::DiagnosisItem* item = dynamic_cast<model::diagnosis::DiagnosisItem*>(this->_d->_currentPathItem)){
//            auto rules = item->rules();
//            int sz = rules.size();
//            bool test = false;
//            for(int i = 0;i<sz;i++){
//                if(static_cast<model::diagnosis::DiagnosisSequenceRuleItem*>(rules.at(i))->name() == name){
//                    this->_d->_currentPathItem = (ModelItem*) rules.at(i);
//                    i = sz;
//                    test = true;
//                }
//            }
//            auto attributes = item->attributes();
//            int sz2 = attributes.size();
//            for(int i = 0;i<sz2 && !test;i++){
//                if(attributes.at(i)->name() == name){
//                    this->_d->_currentPathItem = (ModelItem*) attributes.at(i);
//                    test = true;
//                    i = sz2;
//                }
//            }
//            auto components = item->components();
//            int sz3 = components.size();
//            test = false;
//            for(int i = 0;i<sz3;i++){
//                if(components.at(i)->name() == name){
//                    this->_d->_currentPathItem = components.at(i);
//                    i = sz3;
//                    test = true;
//                }
//            }
//            auto compSignals = item->getSignals();
//            int sz4 = compSignals.size();
//            for(int i = 0;i<sz4;i++){
//                if(compSignals.at(i)->name() == name){
//                    this->_d->_currentPathItem = (ModelItem*) compSignals.at(i);
//                    i = sz4;
//                    test = true;
//                }
//            }
//            if(test) {
//                path = path->idPath();
//                continue;
//            }
//            if(_d->_currentRuleItem)  this->_d->_currentPathItem = (ModelItem*) _d->_currentRuleItem;
//        }
//        if(SignalItem* item = dynamic_cast<SignalItem*>(this->_d->_currentPathItem)){
//            auto attributes = item->params();
//            int sz2 = attributes.size();
//            bool test = false;
//            for(int i = 0;i<sz2 && !test;i++){
//                if(attributes.at(i)->name() == name){
//                    this->_d->_currentPathItem = (ModelItem*) attributes.at(i);
//                    test = true;
//                }
//            }
//            //If Attributes wasn't found!!
//            if(!test){
//                Token* startToken = path->getStart();
//                Token* stopToken = path->getStop();
//                Q_ASSERT(startToken);
//                Q_ASSERT(stopToken);
//                if(this->_errors)
//                    this->_errors->append(DslError(QString("No Attribute with this name!"),
//                                                   startToken->getLine(),
//                                                   startToken->getCharPositionInLine()));
//                return 0;
//            }
//        }
//        else if(TestSystemItem* item = dynamic_cast<TestSystemItem*>(this->_d->_currentPathItem)){
//            auto components = item->components();
//            int sz = components.size();
//            bool test = false;
//            for(int i = 0;i<sz;i++){
//                if(components.at(i)->name() == name){
//                    this->_d->_currentPathItem = components.at(i);
//                    i = sz;
//                    test = true;
//                }
//            }
//            //If Component wasn't found!!
//            if(!test){
//                Token* startToken = path->getStart();
//                Token* stopToken = path->getStop();
//                Q_ASSERT(startToken);
//                Q_ASSERT(stopToken);
//                if(this->_errors)
//                    this->_errors->append(DslError(QString("Incorrect Path to Component!"),
//                                                   startToken->getLine(),
//                                                   startToken->getCharPositionInLine()));
//                return false;
//            }
//        }
//        else if(TestComponentItem* item = dynamic_cast<TestComponentItem*>(this->_d->_currentPathItem)){
//            auto ports = item->ports();
//            int sz = ports.size();
//            bool test = false;
//            for(int i = 0;i<sz;i++){
//                if(ports.at(i)->name() == name){
//                    this->_d->_currentPathItem = ports.at(i);
//                    i = sz;
//                    test = true;
//                }
//            }
//            //If Port wasn't found!!
//            if(!test){
//                Token* startToken = path->getStart();
//                Token* stopToken = path->getStop();
//                Q_ASSERT(startToken);
//                Q_ASSERT(stopToken);
//                if(this->_errors)
//                    this->_errors->append(DslError(QString("Incorrect Path to Port!"),
//                                                   startToken->getLine(),
//                                                   startToken->getCharPositionInLine()));
//                return false;
//            }
//        }
//        else if(SutItem* item = dynamic_cast<SutItem*>(this->_d->_currentPathItem)){
//            auto components = item->components();
//            int sz = components.size();
//            bool test = false;
//            for(int i = 0;i<sz;i++){
//                if(components.at(i)->name() == name){
//                    this->_d->_currentPathItem = components.at(i);
//                    i = sz;
//                    test = true;
//                }
//            }
//            //If Component wasn't found!!
//            if(!test){
//                Token* startToken = path->getStart();
//                Token* stopToken = path->getStop();
//                Q_ASSERT(startToken);
//                Q_ASSERT(stopToken);
//                if(this->_errors)
//                    this->_errors->append(DslError(QString("Incorrect Path to Port!"),
//                                                   startToken->getLine(),
//                                                   startToken->getCharPositionInLine()));
//                return false;
//            }
//        }
//        else if(SutComponentItem* item = dynamic_cast<SutComponentItem*>(this->_d->_currentPathItem)){
//            auto ports = item->ports();
//            int sz = ports.size();
//            bool test = false;
//            for(int i = 0;i<sz;i++){
//                if(ports.at(i)->name() == name){
//                    this->_d->_currentPathItem = ports.at(i);
//                    i = sz;
//                    test = true;
//                }
//            }
//            //If Port wasn't found!!
//            if(!test){
//                Token* startToken = path->getStart();
//                Token* stopToken = path->getStop();
//                Q_ASSERT(startToken);
//                Q_ASSERT(stopToken);
//                if(this->_errors)
//                    this->_errors->append(DslError(QString("Incorrect Path to Port!"),
//                                                   startToken->getLine(),
//                                                   startToken->getCharPositionInLine()));
//                return false;
//            }
//        }
//        else if(model::diagnosis::DiagnosisSequenceRuleItem* item = dynamic_cast<model::diagnosis::DiagnosisSequenceRuleItem*>(this->_d->_currentPathItem)){
//            auto diagsignals = item->getSignals();
//            int sz = diagsignals.size();
//            bool test = false;
//            for(int i = 0;!test && i<sz;i++){
//                if(diagsignals.at(i)->name() == name){
//                    this->_d->_currentPathItem = diagsignals.at(i);
//                    test = true;
//                }
//            }
//            auto components = item->components();
//            int sz2 = components.size();
//            for(int i = 0;!test && i<sz2;i++){
//                if(components.at(i)->name() == name){
//                    this->_d->_currentPathItem = components.at(i);
//                    test = true;
//                }
//            }

//            //If Component wasn't found!!
//            if(!test){
//                Token* startToken = path->getStart();
//                Token* stopToken = path->getStop();
//                Q_ASSERT(startToken);
//                Q_ASSERT(stopToken);
//                if(this->_errors)
//                    this->_errors->append(DslError(QString("Incorrect Path to Component!"),
//                                                   startToken->getLine(),
//                                                   startToken->getCharPositionInLine()));
//                return false;
//            }
//        }
//        else{
//            return false;
//        }
//        path = path->idPath();
//    }
//    return true;
}

QString DiagnosisModelListener::getExpression(DiagnosisDeclParser::ExpressionContext *ctx)
{
    if(!ctx)
        return "";
    const misc::Interval interval(ctx->getStart()->getStartIndex(),ctx->getStop()->getStopIndex());
    return QString::fromStdString(ctx->getStart()->
                                  getInputStream()->
                                  getText(interval));
}

DiagnosisDeclParser::IdPathContext *DiagnosisModelListener::findCompareValue(DiagnosisDeclParser::ExpressionContext *ctx, uint token)
{
    if(!ctx) return 0;
    if(ctx->atom()){
        if(ctx->atom()->idPath()){
            if(ctx->expressionOptional()->ASSIGN().size() == 2 &&
                    ctx->expressionOptional()->expression()->atom()){
                if(ctx->expressionOptional()->expression()->atom()->getStart()->getType() == token){
                    return ctx->atom()->idPath();
                }
            }
        }
        if(ctx->atom()->getStart()->getType() == token){
            if(ctx->expressionOptional()->ASSIGN().size() == 2 &&
                    ctx->expressionOptional()->expression()->atom()){
                if(ctx->expressionOptional()->expression()->atom()->idPath()){
                    return ctx->expressionOptional()->expression()->atom()->idPath();
                }
            }
        }
        if(ctx->expressionOptional()->expression()){
            return findCompareValue(ctx->expressionOptional()->expression(),token);
        }
    }
    if(ctx->expression()){
        return findCompareValue(ctx->expressionOptional()->expression(),token);
    }
    return 0;
}

model::msc::MscComponentItem *DiagnosisModelListener::getOwner(AttributeItem *item)
{
    QStack<BaseComponentItem*> componentTree;
    foreach (auto attribute, _model->attributes()) {
        if(item->index() == attribute->index()){
            return (BaseComponentItem*)_model;
        }
    }
    int sz = _d->_importItems.size();
    auto it = _d->_importItems.begin();
    for(int i = 0;i<sz;i++){
        if(TestSystemItem* currentTestSystemModel = dynamic_cast<TestSystemItem*>(it.value())){
            foreach (auto comp, currentTestSystemModel->components()) {
                componentTree.push_front((BaseComponentItem*)comp);
            }
        }
        else componentTree.push_front(dynamic_cast<BaseComponentItem*>(it.value()));
        it++;
    }
    while(componentTree.size()){
        BaseComponentItem* currentModel = componentTree.at(0);
        foreach (auto attribute, currentModel->attributes()) {
            if(item->index() == attribute->index()){
                return currentModel;
            }
        }
        componentTree.pop_front();
    }
    return 0;
}

void DiagnosisModelListener::visitErrorNode(tree::ErrorNode* node)
{
    Q_UNUSED(node);
    return;
}

} // namespace diagnosis
} // namespace dslparser
