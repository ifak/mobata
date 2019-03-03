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

#include "sutmodellistener.hpp"

#include <mobata/model/ts/sutcomponentitem.hpp>

#include <QStack>
#include <QDebug>

#include <exception>

using namespace model::ts;
using namespace model::base;
using namespace antlr4;

namespace dslparser {
namespace sut {

using common::addKeywordLocation;

class SutModelListener::Private
{
  friend class SutModelListener;

  ///parse data////
  QScopedPointer<SutComponentItem>  _currentComponentItem;

  Private()
    : _currentComponentItem(0)
  {}
};



SutModelListener::SutModelListener(SutItem* sutDeclModel,
                                   DslErrorList* sutErrors,
                                   TokenTextLocations* keywordTextLocations,
                                   ModelTextLocations* modelTextLocations)
  : BaseClass(sutDeclModel, sutErrors, keywordTextLocations, modelTextLocations),
    _d(new Private)
{
  Q_ASSERT(sutDeclModel);
}

SutModelListener::~SutModelListener()
{
  delete this->_d;
}

void SutModelListener::enterSutDecl(SutDeclParser::SutDeclContext* ctx)
{
  Q_UNUSED(ctx);

  this->_listenerStates.push(SutDeclState);

  return;
}

void SutModelListener::exitSutDecl(SutDeclParser::SutDeclContext *ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  this->_listenerStates.pop();

  typedef  tree::TerminalNode* (SutDeclParser::SutDeclContext::*KeywordFunction)();

  return addKeywordLocation<SutDeclParser::SutDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &SutDeclParser::SutDeclContext::SutID, this->_keywordTextLocations, Sut);
}

void SutModelListener::enterNameDecl(SutDeclParser::NameDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  typedef  tree::TerminalNode* (SutDeclParser::NameDeclContext::*KeywordFunction)();

  return addKeywordLocation<SutDeclParser::NameDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &SutDeclParser::NameDeclContext::NameID, this->_keywordTextLocations, Attribute);
}

void SutModelListener::exitNameDecl(SutDeclParser::NameDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  Q_ASSERT(ctx->contextID());

  QString name=QString::fromStdString(ctx->contextID()->getText());

  int currListenerState = this->currentListenerState();
  if(currListenerState==SutDeclState)
  {
    Q_ASSERT(this->_model);
    this->_model->setName(name);
    this->_model->setText(name);
  }
  else if(currListenerState==SutCompDeclState)
  {
    Q_ASSERT(this->_d->_currentComponentItem);
    this->_d->_currentComponentItem->setName(name);
    this->_d->_currentComponentItem->setText(name);

    QString errorString;
    bool result = this->_model->addComponent(this->_d->_currentComponentItem.data(),
                                             &errorString);
    if(!result)
      appendDslError(ctx->getStart(),
                     errorString);
  }

  return;
}

void SutModelListener::enterPortDecl(SutDeclParser::PortDeclContext *ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  typedef  tree::TerminalNode* (SutDeclParser::PortDeclContext::*KeywordFunction)();

  return addKeywordLocation<SutDeclParser::PortDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &SutDeclParser::PortDeclContext::PortID, this->_keywordTextLocations, Keyword);
}

void SutModelListener::exitPortDecl(SutDeclParser::PortDeclContext *ctx)
{
  Q_ASSERT(ctx);
  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  if(!this->_d->_currentComponentItem)
    return;//FIXME: this is not good
  Q_ASSERT(this->_d->_currentComponentItem);

  for(SutDeclParser::ContextIDContext* currContextID : ctx->contextID())
  {
    Token* portToken=currContextID->getStart();
    Q_ASSERT(portToken);

    QString portName=QString::fromStdString(currContextID->getText());
    QString errorString;
    PortItem* newPort = this->_d->_currentComponentItem->addPort(portName, &errorString);
    if(!newPort)
    {
      if(this->_errors)
        this->_errors->append(DslError(errorString,
                                       portToken->getLine(),
                                       portToken->getCharPositionInLine()));
    }
    else
    {
      this->_modelTextLocations->insert(newPort->index(),
                                        TokenTextLocation(portToken->getStartIndex(),
                                                          portToken->getStopIndex(),
                                                          Port));
    }
  }

  return;
}

void SutModelListener::enterSutCompDecl(SutDeclParser::SutCompDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  this->_listenerStates.push(SutCompDeclState);

  this->_d->_currentComponentItem.reset(new SutComponentItem(QStringLiteral("")));
  this->setAttributesModel(this->_d->_currentComponentItem.data());

  typedef  tree::TerminalNode* (SutDeclParser::SutCompDeclContext::*KeywordFunction)();

  addKeywordLocation<SutDeclParser::SutCompDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &SutDeclParser::SutCompDeclContext::SutComponentID, this->_keywordTextLocations, SutComponent);

  return;
}

void SutModelListener::exitSutCompDecl(SutDeclParser::SutCompDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  if(!this->_d->_currentComponentItem)
    return;//FIXME: this is not good
  Q_ASSERT(this->_d->_currentComponentItem);

  this->_modelTextLocations->insert(this->_d->_currentComponentItem->index(),
                                    TokenTextLocation(ctx->getStart()->getStartIndex(),
                                                      ctx->getStop()->getStopIndex(),
                                                      SutComponent));

  this->_d->_currentComponentItem.take();
  this->_listenerStates.pop();
  this->setAttributesModel(this->_model);

  return;
}

void SutModelListener::visitErrorNode(tree::ErrorNode* node)
{
  Q_UNUSED(node);
  return;
}

} // namespace sut
} // namespace dslparser
