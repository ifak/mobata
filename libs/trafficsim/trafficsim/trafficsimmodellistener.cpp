#include "trafficsimmodellistener.hpp"

#include "trafficsimmodel.hpp"

#include <QStack>
#include <QDebug>

using namespace trafficsim;
using namespace model::base;
using namespace antlr4;
using namespace dslparser;

namespace trafficsim {

using common::addKeywordLocation;

class TrafficSimModelListener::Private
{
    friend class TrafficSimModelListener;

    ///parse data////
    TrafficSimModel* _trafficsimModel;  // quick fix because CommonModel != TrafficSimModel
    DslErrorList* _dslErrors;
    TokenTextLocations* _keywordTextLocations;
    ModelTextLocations* _modelTextLocations;

    Private(TrafficSimModel* trafficsimDeclModel,
            DslErrorList* trafficsimErrors,
            TokenTextLocations* keywordTextLocations,
            ModelTextLocations* modelTextLocations)
        : _trafficsimModel(trafficsimDeclModel),
          _dslErrors(trafficsimErrors),
          _keywordTextLocations(keywordTextLocations),
          _modelTextLocations(modelTextLocations)
    {}
};



TrafficSimModelListener::TrafficSimModelListener(TrafficSimModel* trafficsimDeclModel,
                                   DslErrorList* trafficsimErrors,
                                   TokenTextLocations* keywordTextLocations,
                                   ModelTextLocations* modelTextLocations)
    : _d(new Private(trafficsimDeclModel,trafficsimErrors,keywordTextLocations,modelTextLocations))
{}

TrafficSimModelListener::~TrafficSimModelListener()
{
    delete this->_d;
}
/*
void TrafficSimModelListener::exittrafficsimDecl(trafficsimDeclParser::trafficsimDeclContext *ctx)
{
    typedef  tree::TerminalNode* (trafficsimDeclParser::trafficsimDeclContext::*KeywordFunction)();

    return addKeywordLocation<trafficsimDeclParser::trafficsimDeclContext, KeywordFunction, TokenTextLocations>
            (ctx, &trafficsimDeclParser::trafficsimDeclContext::trafficsimID, this->_d->_keywordTextLocations, trafficsim);
}

void TrafficSimModelListener::exitNameDecl(trafficsimDeclParser::NameDeclContext *ctx)
{
    typedef  tree::TerminalNode* (trafficsimDeclParser::NameDeclContext::*KeywordFunction)();

    return addKeywordLocation<trafficsimDeclParser::NameDeclContext, KeywordFunction, TokenTextLocations>
            (ctx, &trafficsimDeclParser::NameDeclContext::NameID, this->_d->_keywordTextLocations, Name);
}

void TrafficSimModelListener::exitPortDecl(trafficsimDeclParser::PortDeclContext *ctx)
{
    typedef  tree::TerminalNode* (trafficsimDeclParser::PortDeclContext::*KeywordFunction)();

    return addKeywordLocation<trafficsimDeclParser::PortDeclContext, KeywordFunction, TokenTextLocations>
            (ctx, &trafficsimDeclParser::PortDeclContext::PortID, this->_d->_keywordTextLocations, Port);
}

void TrafficSimModelListener::exittrafficsimCompDecl(trafficsimDeclParser::trafficsimCompDeclContext *ctx)
{
    if(this->_d->_trafficsimModel->components().size()>this->_d->_keywordTextLocations->count(trafficsimComponent)){
        typedef  tree::TerminalNode* (trafficsimDeclParser::trafficsimCompDeclContext::*KeywordFunction)();

        addKeywordLocation<trafficsimDeclParser::trafficsimCompDeclContext, KeywordFunction, TokenTextLocations>
                (ctx, &trafficsimDeclParser::trafficsimCompDeclContext::trafficsimComponentID, this->_d->_keywordTextLocations, trafficsimComponent);


        this->_d->_modelTextLocations->insert(
                    this->_d->_trafficsimModel->components().at(this->_d->_trafficsimModel->components().size()-1)->index(),
                    TokenTextLocation(
                        ctx->getStart()->getStartIndex(),
                        ctx->getStop()->getStopIndex(),
                        trafficsimComponent)
                    );
    }
}



void TrafficSimModelListener::exittrafficsimBody(trafficsimDeclParser::trafficsimBodyContext *ctx)
{
    QString name = "";
    if(ctx->nameDecl() && ctx->nameDecl()->ID()){
        name=QString::fromStdString(ctx->nameDecl()->ID()->getText());
    }
    else{
        DslError err("Name wasn't defined!",ctx->getStart()->getLine(),0,QString::fromStdString(ctx->getText()),DslError::ParserErrorType::AmbiguityError);
        this->_d->_dslErrors->append(err);
    }
    this->_d->_trafficsimModel->setName(name);
    return;
}


void TrafficSimModelListener::exittrafficsimCompBody(trafficsimDeclParser::trafficsimCompBodyContext *ctx)
{
    if(ctx->exception)
        return;//an error occured! -> but still handled by error listener!
    QString name=QString::fromStdString(ctx->nameDecl()->ID()->getText());
    trafficsimComponentItem* sitem = new trafficsimComponentItem(name);
    QString errorString;
    bool result = this->_d->_trafficsimModel->addComponent(sitem,&errorString);
    if(!result)
    {
        DslError err(errorString,
                     ctx->getStart()->getLine());
        this->_d->_dslErrors->append(err);

        return;
    }

    if(ctx->portDecl()){
        this->makePorts(ctx->portDecl(),sitem);
        trafficsimDeclParser::PortDeclOptionalContext * pCtx = ctx->portDeclOptional();
        while(pCtx){
            if(pCtx->portDecl()){
                this->makePorts(pCtx->portDecl(),sitem);
                pCtx = pCtx->portDeclOptional();
            }
            else break;
        }
    }
    return;
}

void TrafficSimModelListener::makePorts(trafficsimDeclParser::PortDeclContext* ctx,
                                 trafficsimComponentItem* model)
{    
    //____________________________________________________________________________
    //First ID
    tree::TerminalNode* t = ctx->ID();
    trafficsimDeclParser::IdConcatOptionalContext *idCtx = ctx->idConcatOptional();

    QString errorStr = "";
    QString name = QString::fromStdString(t->getText());
    PortItem* portItem = model->addPort(name,
                                        &errorStr);
    Token* portToken = t->getSymbol();
    Q_ASSERT(portToken);
    if(!portItem)
    {
        DslError err(errorStr,
                     ctx->getStart()->getLine(),
                     portToken->getStartIndex(),
                     QString::fromStdString(t->getText()),
                     DslError::ParserErrorType::AmbiguityError);
        this->_d->_dslErrors->append(err);

        return;
    }

    this->_d->_modelTextLocations->insert(portItem->index(),
                                          TokenTextLocation(portToken->getStartIndex(),
                                                            portToken->getStopIndex(),
                                                            Port));
    //______________________________________________________________________________________________
    while(idCtx){
        t = idCtx->ID();
        if(!t) break;

        QString errorStr = "";
        PortItem* portItem = model->addPort(QString::fromStdString(t->getText()),
                                            &errorStr);
        Token* portToken = t->getSymbol();
        Q_ASSERT(portToken);
        if(!portItem)
        {
            DslError err(errorStr,
                         ctx->getStart()->getLine(),
                         portToken->getStartIndex(),
                         QString::fromStdString(t->getText()),
                         DslError::ParserErrorType::AmbiguityError);
            this->_d->_dslErrors->append(err);

            return;
        }

        if(!this->_d->_modelTextLocations)
            continue;

        this->_d->_modelTextLocations->insert(portItem->index(),
                                              TokenTextLocation(portToken->getStartIndex(),
                                                                portToken->getStopIndex(),
                                                                Port));
        idCtx = idCtx->idConcatOptional();
    }
}

void TrafficSimModelListener::visitErrorNode(tree::ErrorNode* node)
{
    Q_UNUSED(node);
    return;
}
*/
} // namespace trafficsim
