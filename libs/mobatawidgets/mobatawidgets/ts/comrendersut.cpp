#include "comrendersut.hpp"

#include <mobata/model/base/linkitem.hpp>

#include <mobata/model/ts/ts.hpp>

#include "sutscene.hpp"
#include "sutcomponent.hpp"

#include "../comp/comp.hpp"
#include "../comp/linkport.hpp"

#include <mobata/memory_leak_start.hpp>

namespace view {
namespace ts {

/// private class of command class ComRenderSut ////////////
class ComRenderSut::Private
{
  friend class ComRenderSut;

  typedef QList<model::base::ComponentItem const*>  ModelComponents;
  typedef QList<model::ts::PortItem const*>         ModelPorts;

  SutScene*                 _sutScene;
  model::ts::SutItem const* _sutItem;
  ModelComponents           _modelComponents;
  NodeOptions               _compOptions;
  NodeOptions               _portOptions;
  ArcOptions                _linkOptions;
  QBrush                    _sutBoxBrushOption;
  qreal                     _sutCompMarginSpace;
  qreal                     _sutBoxMarginSpace;
  qreal                     _sutBoxRadius;

  Private(SutScene* sutScene,
          model::ts::SutItem const* sutItem,
          const NodeOptions& compOptions,
          const NodeOptions& portOptions,
          const ArcOptions& linkOptions,
          const QBrush& sutBoxBrushOption,
          const qreal sutCompMarginSpace,
          const qreal sutBoxMarginSpace,
          const qreal sutBoxRadius)
    : _sutScene(sutScene),
      _sutItem(sutItem),
      _compOptions(compOptions),
      _portOptions(portOptions),
      _linkOptions(linkOptions),
      _sutBoxBrushOption(sutBoxBrushOption),
      _sutCompMarginSpace(sutCompMarginSpace),
      _sutBoxMarginSpace(sutBoxMarginSpace),
      _sutBoxRadius(sutBoxRadius)
  {}

  ModelComponents neighbours(model::base::ComponentItem const* component);
  ModelComponents targets(model::ts::PortItem const* port);
  void            layoutSutComponent(SutComponent* viewSutComponent);
  void            addLeftPorts(const ModelPorts& leftPorts,
                               SutComponent* viewSutComponent);
  void            addTopPorts(const ModelPorts& leftPorts,
                              SutComponent* viewSutComponent);
  void            addRightPorts(const ModelPorts& leftPorts,
                                SutComponent* viewSutComponent);
  void            addBottomPorts(const ModelPorts& leftPorts,
                                 SutComponent* viewSutComponent);
  void            renderSutBox();
};

ComRenderSut::Private::ModelComponents ComRenderSut::Private::neighbours(const model::base::ComponentItem* component)
{
  ModelComponents neighbours;

  foreach(model::ts::LinkItem const* linkItem,
          this->_sutItem->links())
  {
    model::ts::PortItem const* fromPort=linkItem->from();
    Q_ASSERT(fromPort);
    if(fromPort->ownerType()==model::ts::PortItem::Link)
      continue;

    model::ts::SutComponentItem const* fromComponent=dynamic_cast<model::ts::SutComponentItem const*>(fromPort->owner());
    Q_ASSERT(fromComponent);

    model::ts::PortItem const* toPort=linkItem->to();
    Q_ASSERT(toPort);
    if(toPort->ownerType()==model::ts::PortItem::Link)
      continue;

    model::ts::SutComponentItem const* toComponent=dynamic_cast<model::ts::SutComponentItem const*>(toPort->owner());
    Q_ASSERT(toComponent);

    if(fromComponent == component)
    {
      if(toComponent != component)
      {
        if(!neighbours.contains(toComponent))
          neighbours.append(toComponent);
      }
    }
    else if(toComponent == component)
    {
      if(fromComponent != component)
      {
        if(!neighbours.contains(fromComponent))
          neighbours.append(fromComponent);
      }
    }
  }

  return neighbours;
}

ComRenderSut::Private::ModelComponents ComRenderSut::Private::targets(const model::ts::PortItem* port)
{
  ModelComponents targets;

  foreach(model::ts::LinkItem const* linkItem,
          this->_sutItem->links())
  {
    model::ts::PortItem const* fromPort=linkItem->from();
    Q_ASSERT(fromPort);

    model::ts::PortItem const* toPort=linkItem->to();
    Q_ASSERT(toPort);

    if(fromPort==port)
    {
      model::ts::SutComponentItem const* toComponent=dynamic_cast<model::ts::SutComponentItem const*>(toPort->owner());
      Q_ASSERT(toComponent);

      if(!targets.contains(toComponent))
        targets.append(toComponent);
    }
    else if(toPort==port)
    {
      model::ts::SutComponentItem const* fromComponent=dynamic_cast<model::ts::SutComponentItem const*>(fromPort->owner());
      Q_ASSERT(fromComponent);

      if(!targets.contains(fromComponent))
        targets.append(fromComponent);
    }
  }

  return targets;
}

void ComRenderSut::Private::layoutSutComponent(SutComponent* viewSutComponent)
{
  Q_ASSERT(viewSutComponent);
  Q_ASSERT(this->_sutScene);

  qreal lastCompMarginX=0;
  if(this->_sutScene->sutComponents().size())
  {
    SutComponent* lastAddedComponent=this->_sutScene->sutComponents().last();
    Q_ASSERT(lastAddedComponent);
    QRectF lastAddedComponentRect=lastAddedComponent->childrenBoundingRect()
                                  | lastAddedComponent->boundingRect();
    lastCompMarginX=lastAddedComponent->pos().x()
                    + lastAddedComponentRect.width()/2;
    QRectF mscCompRect=viewSutComponent->childrenBoundingRect()
                       | viewSutComponent->boundingRect();
    viewSutComponent->setPos(lastCompMarginX
                             + this->_sutCompMarginSpace
                             + mscCompRect.width()/2,
                             lastAddedComponent->pos().y());
  }
  else
  {
    QRectF mscCompRect=viewSutComponent->rect();
    viewSutComponent->setPos(mscCompRect.width()/2,
                             mscCompRect.height()/2);
  }

  return;
}

void ComRenderSut::Private::addLeftPorts(const ModelPorts& leftPorts,
                                         SutComponent* viewSutComponent)
{
  Q_ASSERT(viewSutComponent);

  qreal compHeight=viewSutComponent->rect().height();

  int portCount=leftPorts.size();
  int index=0;
  foreach(model::ts::PortItem const* leftPort, leftPorts)
  {
    QPointF portPos=QPointF(viewSutComponent->rect().left(),
                            -compHeight/2 + (index+1)*compHeight/(portCount+1));
    comp::Port* viewPort=viewSutComponent->addPort(viewSutComponent->mapToScene(portPos),
                                                   leftPort->name(),
                                                   this->_portOptions);
    Q_ASSERT(viewPort);
    viewPort->setUuid(leftPort->uuid());

    //update port-notation-item
    if(!viewPort->notationItem())
      continue;

    QRectF portNotationRect=viewPort->notationItem()->boundingRect();
    QRectF viewPortRect=viewPort->boundingRect();
    QPointF portNotationPos=QPointF(viewPortRect.left() - portNotationRect.width(),
                                    viewPortRect.top() - portNotationRect.height());
    viewPort->notationItem()->setPos(portNotationPos);
    viewPort->notationItem()->hide();

    ++index;
  }

  return;
}

void ComRenderSut::Private::addTopPorts(const ModelPorts& topPorts,
                                        SutComponent* viewSutComponent)
{
  Q_ASSERT(viewSutComponent);

  qreal compWidth=viewSutComponent->rect().width();

  int portCount=topPorts.size();
  int index=0;
  foreach(model::ts::PortItem const* topPort, topPorts)
  {
    QPointF portPos=QPointF(-compWidth/2 + (index+1)*compWidth/(portCount+1),
                            viewSutComponent->rect().top());
    comp::Port* viewPort=viewSutComponent->addPort(viewSutComponent->mapToScene(portPos),
                                                   topPort->name(),
                                                   this->_portOptions);
    Q_ASSERT(viewPort);
    viewPort->setUuid(topPort->uuid());

    //update port-notation-item
    if(!viewPort->notationItem())
      continue;

    QRectF portNotationRect=viewPort->notationItem()->boundingRect();
    QRectF viewPortRect=viewPort->boundingRect();
    QPointF portNotationPos=QPointF(viewPortRect.right(),
                                    viewPortRect.top() - portNotationRect.height());
    viewPort->notationItem()->setPos(portNotationPos);
    viewPort->notationItem()->hide();

    ++index;
  }

  return;
}

void ComRenderSut::Private::addRightPorts(const ModelPorts& rightPorts,
                                          SutComponent* viewSutComponent)
{
  Q_ASSERT(viewSutComponent);

  qreal compHeight=viewSutComponent->rect().height();

  int portCount=rightPorts.size();
  int index=0;
  foreach(model::ts::PortItem const* rightPort, rightPorts)
  {
    QPointF portPos=QPointF(viewSutComponent->rect().right(),
                            -compHeight/2 + (index+1)*compHeight/(portCount+1));
    comp::Port* viewPort=viewSutComponent->addPort(viewSutComponent->mapToScene(portPos),
                                                   rightPort->name(),
                                                   this->_portOptions);
    Q_ASSERT(viewPort);
    viewPort->setUuid(rightPort->uuid());

    //update port-notation-item
    if(!viewPort->notationItem())
      continue;

    QRectF portNotationRect=viewPort->notationItem()->boundingRect();
    QRectF viewPortRect=viewPort->boundingRect();
    QPointF portNotationPos=QPointF(viewPortRect.right(),
                                    viewPortRect.top() - portNotationRect.height());
    viewPort->notationItem()->setPos(portNotationPos);
    viewPort->notationItem()->hide();

    ++index;
  }

  return;
}

void ComRenderSut::Private::addBottomPorts(const ModelPorts& bottomPorts,
                                           SutComponent* viewSutComponent)
{
  Q_ASSERT(viewSutComponent);

  qreal compWidth=viewSutComponent->rect().width();

  int portCount=bottomPorts.size();
  int index=0;
  foreach(model::ts::PortItem const* bottomPort, bottomPorts)
  {
    QPointF portPos=QPointF(-compWidth/2 + (index+1)*compWidth/(portCount+1),
                            viewSutComponent->rect().bottom());
    comp::Port* viewPort=viewSutComponent->addPort(viewSutComponent->mapToScene(portPos),
                                                   bottomPort->name(),
                                                   this->_portOptions);
    Q_ASSERT(viewPort);
    viewPort->setUuid(bottomPort->uuid());

    //update port-notation-item
    if(!viewPort->notationItem())
      continue;

    QRectF viewPortRect=viewPort->boundingRect();
    QPointF portNotationPos=QPointF(viewPortRect.right(),
                                    viewPortRect.bottom());
    viewPort->notationItem()->setPos(portNotationPos);
    viewPort->notationItem()->hide();

    ++index;
  }

  return;
}

void ComRenderSut::Private::renderSutBox()
{
  Q_ASSERT(this->_sutScene);

  SutBox* sutBox=const_cast<SutBox*>(this->_sutScene->sutBox());
  Q_ASSERT(sutBox);

  sutBox->setRadius(this->_sutBoxRadius);

  QRectF sutRect=sutBox->childrenBoundingRect();

  sutRect.setTopLeft(QPointF(sutRect.topLeft().x() - this->_sutBoxMarginSpace,
                             sutRect.topLeft().y() - this->_sutBoxMarginSpace));
  sutRect.setBottomRight(QPointF(sutRect.bottomRight().x() + this->_sutBoxMarginSpace,
                                 sutRect.bottomRight().y() + this->_sutBoxMarginSpace));

  sutBox->setRect(sutRect);
  sutBox->show();

  this->_sutScene->update(this->_sutScene->sceneRect());

  return;
}

///ComRenderSut///////////////////////
ComRenderSut::ComRenderSut(SutScene* sutScene,
                           model::ts::SutItem const* sutItem,
                           const NodeOptions& compOptions,
                           const NodeOptions& portOptions,
                           const ArcOptions& linkOptions,
                           const QBrush& sutBoxBrushOption,
                           const qreal compMarginSpace,
                           const qreal sutBoxMarginSpace,
                           const qreal sutBoxRadius)
  : _d(new Private(sutScene, sutItem, compOptions, portOptions, linkOptions, sutBoxBrushOption,
                   compMarginSpace, sutBoxMarginSpace, sutBoxRadius))
{}

ComRenderSut::~ComRenderSut()
{
  delete this->_d;
}

bool ComRenderSut::execute(QString* errorMessage)
{
  Q_ASSERT(this->_d->_sutScene);
  Q_ASSERT(this->_d->_sutItem);

  Q_UNUSED(errorMessage);

  this->_d->_sutScene->setSutBoxBrush(this->_d->_sutBoxBrushOption);
  this->_d->_sutScene->reset();

  ///fill stupid ranking of model-components
  for(model::base::ComponentItem const* modelSutComponent :
      this->_d->_sutItem->components())
  {
    if(!this->_d->_modelComponents.contains(modelSutComponent))
      this->_d->_modelComponents.append(modelSutComponent);

    for(model::base::ComponentItem const* neighbourComponent :
        this->_d->neighbours(modelSutComponent))
    {
      if(this->_d->_modelComponents.contains(neighbourComponent))
        continue;

      bool inserted=false;
      for(model::base::ComponentItem const* neighbourNeighbour :
          this->_d->neighbours(neighbourComponent))
      {
        if(neighbourNeighbour == modelSutComponent)
          continue;

        int index=this->_d->_modelComponents.indexOf(neighbourNeighbour);
        if(index==-1)
          continue;

        this->_d->_modelComponents.insert(index, neighbourComponent);
        inserted=true;
        break;
      }

      if(!inserted)
        this->_d->_modelComponents.append(neighbourComponent);
    }
  }

  ///add components
  int index=0;
  model::base::ComponentItem const* leftNeighbour=0;
  model::base::ComponentItem const* rightNeighbour=0;
  for(model::base::ComponentItem const* modelSutComponent :
      this->_d->_modelComponents)
  {
    leftNeighbour=0;
    rightNeighbour=0;

    if(index>0)
      leftNeighbour=this->_d->_modelComponents.at(index-1);
    if(index<this->_d->_modelComponents.size()-1)
      rightNeighbour=this->_d->_modelComponents.at(index+1);

    SutComponent* viewSutComponent=new SutComponent(modelSutComponent->name(),
                                                    this->_d->_compOptions);
    viewSutComponent->setUuid(modelSutComponent->uuid());

    //port sorting
    typedef QList<model::ts::PortItem const*> ModelPorts;
    ModelPorts leftPorts, rightPorts, topPorts, bottomPorts;
    foreach(model::ts::PortItem const* port,
            modelSutComponent->ports())
    {
      Private::ModelComponents targets=this->_d->targets(port);
      if(targets.contains(leftNeighbour))
        leftPorts.append(port);
      else if(targets.contains(rightNeighbour))
        rightPorts.append(port);
      else if(targets.size())
        bottomPorts.append(port);
      else//no targets
      {
        if(!leftNeighbour)
          leftPorts.append(port);
        else if(!rightNeighbour)
          rightPorts.append(port);
        else
          topPorts.append(port);
      }
    }

    //add-ports
    this->_d->addLeftPorts(leftPorts, viewSutComponent);
    this->_d->addTopPorts(topPorts, viewSutComponent);
    this->_d->addRightPorts(rightPorts, viewSutComponent);
    this->_d->addBottomPorts(bottomPorts, viewSutComponent);

    this->_d->layoutSutComponent(viewSutComponent);
    this->_d->_sutScene->addSutComponent(viewSutComponent);
    ++index;
  }

  ///add links
  foreach(model::ts::LinkItem const* linkItem,
          this->_d->_sutItem->links())
  {
    Port* fromPort=this->_d->_sutScene->port(linkItem->from()->uuid());
    Q_ASSERT(fromPort);
    Port* toPort=this->_d->_sutScene->port(linkItem->to()->uuid());
    Q_ASSERT(toPort);

    Link* newLink = new Link(fromPort, toPort,
                             linkItem->notation(),
                             linkItem->uuid(),
                             this->_d->_linkOptions);
    if(linkItem->port())
      newLink->linkPort()->setUuid(linkItem->port()->uuid());
    else
      newLink->linkPort()->hide();

    this->_d->_sutScene->addSutLink(newLink);
    newLink->linkPort()->notationItem()->hide();
  }

  this->_d->renderSutBox();

  return true;
}

} // namespace ts
} // namespace view

