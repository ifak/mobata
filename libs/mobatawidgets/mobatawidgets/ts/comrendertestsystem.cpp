#include "comrendertestsystem.hpp"

#include "testsystemscene.hpp"
#include "sutcomponent.hpp"
#include "testcomponent.hpp"

#include "../comp/linkport.hpp"

#include <mobata/model/base/linkitem.hpp>
#include <mobata/model/msc/msccomponentitem.hpp>
#include <mobata/model/ts/ts.hpp>

#include <QDebug>

#include <mobata/memory_leak_start.hpp>

namespace view {
namespace ts {

typedef QList<model::ts::BaseComponentItem const*>  ModelComponents;
typedef QList<model::ts::PortItem const*>           ModelPorts;

struct TestSystemMargins
{
  //margins
  qreal leftLeft_X;
  qreal leftRight_X;
  qreal rightLeft_X;
  qreal rightRight_X;

  qreal leftBottom_Y;
  qreal middleTopBottom_Y;
  qreal middleTopTop_Y;
  qreal rightBottom_Y;
  qreal middleBottomTop_Y;//should be 0
  qreal middleBottomBottom_Y;// should be o

  TestSystemMargins()
    : leftLeft_X(qInf()),
      leftRight_X(qInf()),
      rightLeft_X(qInf()),
      rightRight_X(qInf()),
      leftBottom_Y(qInf()),
      middleTopBottom_Y(qInf()),
      middleTopTop_Y(qInf()),
      rightBottom_Y(qInf()),
      middleBottomTop_Y(qInf()), //should stay 0
      middleBottomBottom_Y(qInf())// should stay 0
  {}
};

enum SutBoxBorder
{
  Left,
  Top,
  Right,
  Bottom
};

SutBoxBorder  calcSutBoxBorder(const QPointF& testCompPos,
                               const QRectF& sutBoxRect)
{
  Q_ASSERT(!testCompPos.isNull());
  Q_ASSERT(!sutBoxRect.isEmpty());

  SutBoxBorder result=Top;

  if(testCompPos.x() < sutBoxRect.left())
    result=Left;
  else if(testCompPos.x() > sutBoxRect.right())
    result=Right;
  else if(testCompPos.y() > sutBoxRect.bottom())
    result=Bottom;
  else
    result=Top;

  return result;
}

/// private class of command class ComRenderTestSystem ////////////
class ComRenderTestSystem::Private
{
  friend class ComRenderTestSystem;

  TestSystemScene*                  _testSystemScene;
  model::ts::TestSystemItem const*  _testSystemItem;
  NodeOptions                       _sutCompOptions;
  NodeOptions                       _sutPortOptions;
  ArcOptions                        _sutLinkOptions;
  QBrush                            _sutBoxBrushOption;
  qreal                             _sutCompMarginSpace;
  qreal                             _sutBoxMarginSpace;
  qreal                             _sutBoxRadius;
  NodeOptions                       _testSystemCompOptions;
  NodeOptions                       _testSystemPortOptions;
  ArcOptions                        _testSystemLinkOptions;
  qreal                             _spaceToSutBox;
  NodeOptions                       _testSystemBoxOptions;
  qreal                             _testSystemBoxMarginSpace;
  qreal                             _testSystemBoxRadius;

  Private(TestSystemScene* testSystemScene,
          model::ts::TestSystemItem const* testSystemItem,
          const NodeOptions& sutCompOptions,
          const NodeOptions& sutPortOptions,
          const ArcOptions& sutLinkOptions,
          const QBrush& sutBoxBrushOption,
          const qreal sutCompMarginSpace,
          const qreal sutBoxMarginSpace,
          const qreal sutBoxRadius,
          const NodeOptions& testSystemCompOptions,
          const NodeOptions& testSystemPortOptions,
          const ArcOptions& testSystemLinkOptions,
          const qreal spaceToSutBox,
          const NodeOptions& testSystemBoxOptions,
          const qreal testSystemBoxMarginSpace,
          const qreal testSystemBoxRadius)
    : _testSystemScene(testSystemScene),
      _testSystemItem(testSystemItem),
      _sutCompOptions(sutCompOptions),
      _sutPortOptions(sutPortOptions),
      _sutLinkOptions(sutLinkOptions),
      _sutBoxBrushOption(sutBoxBrushOption),
      _sutCompMarginSpace(sutCompMarginSpace),
      _sutBoxMarginSpace(sutBoxMarginSpace),
      _sutBoxRadius(sutBoxRadius),
      _testSystemCompOptions(testSystemCompOptions),
      _testSystemPortOptions(testSystemPortOptions),
      _testSystemLinkOptions(testSystemLinkOptions),
      _spaceToSutBox(spaceToSutBox),
      _testSystemBoxOptions(testSystemBoxOptions),
      _testSystemBoxMarginSpace(testSystemBoxMarginSpace),
      _testSystemBoxRadius(testSystemBoxRadius)
  {}

  ModelComponents             neighbours(model::ts::BaseComponentItem const* component);
  ModelComponents             targets(model::ts::PortItem const* port);
  model::ts::PortItem const*  sutTargetPort(model::ts::PortItem const* testComponentPort);
  SutBoxBorder                sutBoxBorder(Port* viewSutPort);
  void                        updatePortNotationItem(Port* viewPort,
                                                     const SutBoxBorder sutBoxBorder,
                                                     bool hide);
  void                        layoutOtherPorts(TestComponent* viewTestComponent,
                                               const SutBoxBorder sutBoxBorder,
                                               const ModelPorts& otherPorts);
  void                        addViewComponents();
  void                        addViewLinks();
  TestSystemMargins           calcTestSystemMargins(SutBox const* sutBox);
  void                        renderTestSystemBox();
};

ModelComponents ComRenderTestSystem::Private::neighbours(const model::ts::BaseComponentItem* component)
{
  ModelComponents neighbours;

  foreach(model::ts::LinkItem const* linkItem,
          this->_testSystemItem->links())
  {
    model::ts::PortItem const* fromPort=linkItem->from();
    Q_ASSERT(fromPort);
    if(fromPort->ownerType()==model::ts::PortItem::Link)
      continue;

    model::ts::BaseComponentItem const* fromComponent=dynamic_cast<model::ts::BaseComponentItem const*>(fromPort->owner());
    Q_ASSERT(fromComponent);

    model::ts::PortItem const* toPort=linkItem->to();
    Q_ASSERT(toPort);
    if(toPort->ownerType()==model::ts::PortItem::Link)
      continue;

    model::ts::BaseComponentItem const* toComponent=dynamic_cast<model::ts::BaseComponentItem const*>(toPort->owner());
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

ModelComponents ComRenderTestSystem::Private::targets(const model::ts::PortItem* port)
{
  ModelComponents targets;

  foreach(model::ts::LinkItem const* linkItem,
          this->_testSystemItem->links())
  {
    model::ts::PortItem const* fromPort=linkItem->from();
    Q_ASSERT(fromPort);

    model::ts::PortItem const* toPort=linkItem->to();
    Q_ASSERT(toPort);

    if(fromPort==port)
    {
      model::ts::BaseComponentItem const* toComponent=dynamic_cast<model::ts::BaseComponentItem const*>(toPort->owner());
      Q_ASSERT(toComponent);

      if(!targets.contains(toComponent))
        targets.append(toComponent);
    }
    else if(toPort==port)
    {
      model::ts::BaseComponentItem const* fromComponent=dynamic_cast<model::ts::BaseComponentItem const*>(fromPort->owner());
      Q_ASSERT(fromComponent);

      if(!targets.contains(fromComponent))
        targets.append(fromComponent);
    }
  }

  return targets;
}

model::base::PortItem const* ComRenderTestSystem::Private::sutTargetPort(model::base::PortItem const* testComponentPort)
{
  using namespace utils;

  if(!testComponentPort)
    return 0;

  foreach(model::base::LinkItem const* testLink,
          this->_testSystemItem->links())
  {
    model::base::PortItem const* fromPort=testLink->from();
    Q_ASSERT(fromPort);
    model::base::PortItem const* toPort=testLink->to();
    Q_ASSERT(toPort);

    if(fromPort==testComponentPort)
    {
      if(toPort->ownerType()==model::base::PortItem::Component)
      {
        model::ts::SutComponentItem const* portComponent=simple_cast<model::ts::SutComponentItem const*>(toPort->owner());
        Q_ASSERT(portComponent);

        if(this->_testSystemItem->sutItem()->components().contains(portComponent))
          return toPort;
      }
      else if(toPort->ownerType()==model::base::PortItem::Link)
      {
        model::base::LinkItem const* portLink=simple_cast<model::base::LinkItem const*>(toPort->owner());
        Q_ASSERT(portLink);

        if(this->_testSystemItem->sutItem()->links().contains(portLink))
          return toPort;
      }
    }
    else if(toPort==testComponentPort)
    {
      if(fromPort->ownerType()==model::base::PortItem::Component)
      {
        model::ts::SutComponentItem const* portComponent=simple_cast<model::ts::SutComponentItem const*>(fromPort->owner());
        Q_ASSERT(portComponent);

        if(this->_testSystemItem->sutItem()->components().contains(portComponent))
          return fromPort;
      }
      else if(fromPort->ownerType()==model::base::PortItem::Link)
      {
        model::base::LinkItem const* portLink=simple_cast<model::base::LinkItem const*>(fromPort->owner());
        Q_ASSERT(portLink);

        if(this->_testSystemItem->sutItem()->links().contains(portLink))
          return fromPort;
      }
    }
  }

  return 0;
}

SutBoxBorder  ComRenderTestSystem::Private::sutBoxBorder(Port* viewSutPort)
{
  Q_ASSERT(viewSutPort);

  SutBoxBorder result=Top;

  if(SutComponent* viewSutComponent=qgraphicsitem_cast<SutComponent*>(viewSutPort->parentItem()))
  {
    QPointF portPos=viewSutPort->pos();

    qreal shortestDistance=qAbs(viewSutComponent->rect().left() - portPos.x());
    result = Left;

    qreal topDistance=qAbs(viewSutComponent->rect().top() - portPos.y());
    if(topDistance<shortestDistance)
    {
      shortestDistance=topDistance;
      result=Top;
    }

    qreal rightDistance=qAbs(viewSutComponent->rect().right() - portPos.x());
    if(rightDistance < shortestDistance)
    {
      shortestDistance=rightDistance;
      result=Right;
    }

    qreal bottomDistance=qAbs(viewSutComponent->rect().bottom() - portPos.x());
    if(bottomDistance < shortestDistance)
    {
      shortestDistance=bottomDistance;
      result=Bottom;
    }

    //plausability check
    if(result==Left
       && this->_testSystemScene->sutComponents().first() != viewSutComponent)
      result=Top;
    else if(result==Right
            && this->_testSystemScene->sutComponents().last() != viewSutComponent)
      result=Top;
  }

  return result;
}

void ComRenderTestSystem::Private::updatePortNotationItem(view::ts::Port* viewPort,
                                                          const SutBoxBorder sutBoxBorder,
                                                          bool hide)
{
  Q_ASSERT(viewPort);

  if(!viewPort->notationItem())
    return;

  QRectF portNotationRect=viewPort->notationItem()->boundingRect();
  QRectF viewPortRect=viewPort->boundingRect();

  if(sutBoxBorder==Left)
  {
    QPointF portNotationPos=QPointF(viewPortRect.left() - portNotationRect.width(),
                                    viewPortRect.top() - portNotationRect.height());
    viewPort->notationItem()->setPos(portNotationPos);
  }
  else if(sutBoxBorder==Top)
  {
    QPointF portNotationPos=QPointF(viewPortRect.left() - portNotationRect.width(),
                                    viewPortRect.top() - portNotationRect.height());
    viewPort->notationItem()->setPos(portNotationPos);
  }
  else if(sutBoxBorder==Right)
  {
    QPointF portNotationPos=QPointF(viewPortRect.left() - portNotationRect.width(),
                                    viewPortRect.top() - portNotationRect.height());
    viewPort->notationItem()->setPos(portNotationPos);
  }
  else
  {//sutBoxBorder::Bottom, should not happen
    Q_ASSERT(false);
  }

  if(hide)
    viewPort->notationItem()->hide();
  else
    viewPort->notationItem()->show();

  return;
}

void ComRenderTestSystem::Private::layoutOtherPorts(TestComponent* viewTestComponent,
                                                    const SutBoxBorder sutBoxBorder,
                                                    const ModelPorts& otherPorts)
{
  Q_ASSERT(viewTestComponent);
  Q_UNUSED(sutBoxBorder);
  Q_ASSERT(this->_testSystemItem);
  Q_ASSERT(this->_testSystemItem->sutItem());

  using namespace model::ts;

  if(otherPorts.empty())
    return;

  ModelPorts sutPorts, testPorts, emptyPorts;
  foreach(model::ts::PortItem const* modelPortItem,
          otherPorts)
  {
    bool inserted=false;

    ///first: sut-component as target?
    foreach(model::ts::BaseComponentItem const* targetComponent,
            this->targets(modelPortItem))
    {
      if(targetComponent->compType()==SutComponentType)
      {
        SutComponentItem const* sutTargetComponent = utils::simple_cast<SutComponentItem const*>(targetComponent);
        if(this->_testSystemItem->sutItem()->components().contains(sutTargetComponent))
        {
          sutPorts.append(modelPortItem);
          inserted=true;
          break;
        }
      }
    }

    ///now: test-component as target?
    foreach(model::ts::BaseComponentItem const* targetComponent,
            this->targets(modelPortItem))
    {
      if(targetComponent->compType()==TestComponentType)
      {
        TestComponentItem const* testTargetComponent = utils::simple_cast<TestComponentItem const*>(targetComponent);
        if(this->_testSystemItem->components().contains(testTargetComponent))
        {
          testPorts.append(modelPortItem);
          inserted=true;
          break;
        }
      }
    }

    ///no relevant target
    if(!inserted)
      emptyPorts.append(modelPortItem);
  }

  ///now all ports can be layouted... hopefully... ;)
  if(sutBoxBorder==Left)
  {

  }
  else if(sutBoxBorder==Top)
  {

  }
  else if(sutBoxBorder==Right)
  {

  }
  else if(sutBoxBorder==Bottom)
  {

  }
  else
  {

  }

  return;
}

void ComRenderTestSystem::Private::addViewComponents()
{
  //components with no interaction with the sut
  ModelComponents internTestComponents;

  ///iterating test components/////////
  foreach(model::base::ComponentItem const* modelComponent,
          this->_testSystemItem->components())
  {
    int compType = modelComponent->compType();
    Q_ASSERT(compType==model::ts::TestComponentType);
    model::ts::TestComponentItem const* modelTestComponent = utils::simple_cast<model::ts::TestComponentItem const*>(modelComponent);
    Q_ASSERT(modelTestComponent);

    ModelPorts otherPorts;

    //first sut-target wins => filling other ports
    model::base::PortItem const* testCompPort=0;
    model::base::PortItem const* sutCompPort=0;
    foreach(model::base::PortItem const* portItem,
            modelTestComponent->ports())
    {
      if(model::base::PortItem const* sutPort=this->sutTargetPort(portItem))
      {
        testCompPort=portItem;
        sutCompPort=sutPort;
      }
      else
        otherPorts.append(portItem);
    }

    if(!sutCompPort)
    {
      internTestComponents.append(modelTestComponent);
      continue;
    }

    //get view-sut-port
    Port* viewSutCompPort=this->_testSystemScene->port(sutCompPort->uuid());
    Q_ASSERT(viewSutCompPort);

    QPointF viewSutCompPortScenePoint=viewSutCompPort->parentItem()->mapToScene(viewSutCompPort->pos());
    SutBoxBorder sutBoxBorder=this->sutBoxBorder(viewSutCompPort);
    if(sutBoxBorder==Left)
    {
      qreal testCompX= this->_testSystemScene->sutBox()->boundingRect().left()
                       -this->_spaceToSutBox
                       -this->_testSystemBoxMarginSpace
                       -this->_testSystemCompOptions.size().width()/2;
      qreal testCompY=viewSutCompPortScenePoint.y();
      TestComponent* viewTestComponent=new TestComponent(modelTestComponent->name(),
                                                         this->_testSystemCompOptions);
      viewTestComponent->setPos(testCompX, testCompY);
      this->_testSystemScene->addTestComponent(viewTestComponent);

      Port* viewTestCompPort=viewTestComponent->addPort(QPointF(testCompX
                                                                +this->_testSystemCompOptions.size().width()/2,
                                                                testCompY),
                                                        testCompPort->name(),
                                                        this->_testSystemPortOptions);
      Q_ASSERT(viewTestCompPort);
      viewTestCompPort->setUuid(testCompPort->uuid());

      this->updatePortNotationItem(viewTestCompPort, Left, true);
      this->layoutOtherPorts(viewTestComponent, sutBoxBorder, otherPorts);
    }
    else if(sutBoxBorder==Top)
    {
      qreal testCompX=viewSutCompPortScenePoint.x();
      qreal testCompY= this->_testSystemScene->sutBox()->boundingRect().top()
                       -this->_spaceToSutBox
                       -this->_testSystemBoxMarginSpace
                       -this->_testSystemCompOptions.size().height()/2;
      TestComponent* viewTestComponent=new TestComponent(modelTestComponent->name(),
                                                         this->_testSystemCompOptions);
      viewTestComponent->setPos(testCompX, testCompY);
      this->_testSystemScene->addTestComponent(viewTestComponent);

      Port* viewTestCompPort=viewTestComponent->addPort(QPointF(testCompX,
                                                                testCompY
                                                                +this->_testSystemCompOptions.size().height()/2),
                                                        testCompPort->name(),
                                                        this->_testSystemPortOptions);
      Q_ASSERT(viewTestCompPort);
      viewTestCompPort->setUuid(testCompPort->uuid());

      this->updatePortNotationItem(viewTestCompPort, Top, true);
      this->layoutOtherPorts(viewTestComponent, sutBoxBorder, otherPorts);
    }
    else if(sutBoxBorder==Right)
    {
      qreal testCompX= this->_testSystemScene->sutBox()->boundingRect().right()
                       +this->_spaceToSutBox
                       +this->_testSystemBoxMarginSpace
                       +this->_testSystemCompOptions.size().width()/2;
      qreal testCompY=viewSutCompPortScenePoint.y();
      TestComponent* viewTestComponent=new TestComponent(modelTestComponent->name(),
                                                         this->_testSystemCompOptions);
      viewTestComponent->setPos(testCompX, testCompY);
      this->_testSystemScene->addTestComponent(viewTestComponent);

      Port* viewTestCompPort=viewTestComponent->addPort(QPointF(testCompX
                                                                -this->_testSystemCompOptions.size().width()/2,
                                                                testCompY),
                                                        testCompPort->name(),
                                                        this->_testSystemPortOptions);
      Q_ASSERT(viewTestCompPort);
      viewTestCompPort->setUuid(testCompPort->uuid());

      this->updatePortNotationItem(viewTestCompPort, Right, true);
      this->layoutOtherPorts(viewTestComponent, sutBoxBorder, otherPorts);
    }
    else// should not happen
    {
      internTestComponents.append(modelTestComponent);
      continue;
    }

  }

  return;
}

void ComRenderTestSystem::Private::addViewLinks()
{
  Q_ASSERT(this->_testSystemItem);
  Q_ASSERT(this->_testSystemScene);

  foreach(model::ts::LinkItem const* modelLinkItem,
          this->_testSystemItem->links())
  {
    model::ts::PortItem const* modelFromPort=modelLinkItem->from();
    Q_ASSERT(modelFromPort);
    model::ts::PortItem const* modelToPort=modelLinkItem->to();
    Q_ASSERT(modelToPort);

    Port* fromViewPort=this->_testSystemScene->port(modelFromPort->uuid());
    if(!fromViewPort)
      qWarning()<<"view port representation of port:"<<modelFromPort->toString()<<"not found yet!";
    Port* toViewPort=this->_testSystemScene->port(modelToPort->uuid());
    if(!toViewPort)
      qWarning()<<"view port representation of port:"<<modelToPort->toString()<<"not found yet!";

    Link* newLink = new Link(fromViewPort, toViewPort,
                             modelLinkItem->notation(),
                             modelLinkItem->uuid(),
                             this->_testSystemLinkOptions);
    this->_testSystemScene->addTestSystemLink(newLink);
    newLink->linkPort()->notationItem()->hide();
    newLink->linkPort()->hide();
  }

  return;
}

TestSystemMargins ComRenderTestSystem::Private::calcTestSystemMargins(SutBox const* sutBox)
{
  Q_ASSERT(sutBox);

  TestSystemMargins testSystemMargins;

  QRectF sutBoxRect=sutBox->boundingRect();

  foreach(TestComponent const* testComponent,
          this->_testSystemScene->testComponents())
  {
    QPointF testCompPos=testComponent->pos();
    if(testComponent->parentItem())
      testCompPos=testComponent->parentItem()->mapToScene(testComponent->pos());

    QRectF testCompRect=testComponent->rect();

    //component + box space margins
    qreal leftComp_X=testCompPos.x()    - testCompRect.width()/2  - this->_testSystemBoxMarginSpace;
    qreal rightComp_X=testCompPos.x()   + testCompRect.width()/2  + this->_testSystemBoxMarginSpace;
    qreal topComp_Y=testCompPos.y()     - testCompRect.height()/2 - this->_testSystemBoxMarginSpace;
    qreal bottomComp_Y=testCompPos.y()  + testCompRect.height()/2 + this->_testSystemBoxMarginSpace;

    SutBoxBorder sutBoxBorder=calcSutBoxBorder(testCompPos,
                                               sutBoxRect);

    if(sutBoxBorder==Left)
    {
      if(qIsInf(testSystemMargins.leftLeft_X))
        testSystemMargins.leftLeft_X=leftComp_X;
      else if(leftComp_X < testSystemMargins.leftLeft_X)
        testSystemMargins.leftLeft_X=leftComp_X;

      if(qIsInf(testSystemMargins.leftRight_X))
        testSystemMargins.leftRight_X=rightComp_X;
      else if(rightComp_X > testSystemMargins.leftRight_X)
        testSystemMargins.leftRight_X=rightComp_X;

      if(qIsInf(testSystemMargins.rightRight_X))
        testSystemMargins.rightRight_X=rightComp_X;
      else if(rightComp_X > testSystemMargins.rightRight_X)
        testSystemMargins.rightRight_X=rightComp_X;

      if(qIsInf(testSystemMargins.middleTopTop_Y))
        testSystemMargins.middleTopTop_Y=topComp_Y;
      else if(topComp_Y < testSystemMargins.middleTopTop_Y)
        testSystemMargins.middleTopTop_Y=topComp_Y;

      if(qIsInf(testSystemMargins.leftBottom_Y))
        testSystemMargins.leftBottom_Y=bottomComp_Y;
      else if(bottomComp_Y > testSystemMargins.leftBottom_Y)
        testSystemMargins.leftBottom_Y=bottomComp_Y;
    }
    else if(sutBoxBorder==Top)
    {
      if(qIsInf(testSystemMargins.leftLeft_X))
        testSystemMargins.leftLeft_X=leftComp_X;
      else if(leftComp_X < testSystemMargins.leftLeft_X)
        testSystemMargins.leftLeft_X=leftComp_X;

      if(qIsInf(testSystemMargins.rightRight_X))
        testSystemMargins.rightRight_X=rightComp_X;
      else if(rightComp_X > testSystemMargins.rightRight_X)
        testSystemMargins.rightRight_X=rightComp_X;

      if(qIsInf(testSystemMargins.middleTopTop_Y))
        testSystemMargins.middleTopTop_Y=topComp_Y;
      else if(topComp_Y < testSystemMargins.middleTopTop_Y)
        testSystemMargins.middleTopTop_Y=topComp_Y;

      if(qIsInf(testSystemMargins.middleTopBottom_Y))
        testSystemMargins.middleTopBottom_Y=bottomComp_Y;
      else if(bottomComp_Y > testSystemMargins.middleTopBottom_Y)
        testSystemMargins.middleTopBottom_Y=bottomComp_Y;
    }
    else if(sutBoxBorder==Right)
    {
      if(qIsInf(testSystemMargins.leftLeft_X))
        testSystemMargins.leftLeft_X=leftComp_X;
      else if(leftComp_X < testSystemMargins.leftLeft_X)
        testSystemMargins.leftLeft_X=leftComp_X;

      if(qIsInf(testSystemMargins.rightLeft_X))
        testSystemMargins.rightLeft_X=leftComp_X;
      else if(leftComp_X < testSystemMargins.rightLeft_X)
        testSystemMargins.rightLeft_X=leftComp_X;

      if(qIsInf(testSystemMargins.rightRight_X))
        testSystemMargins.rightRight_X=rightComp_X;
      else if(rightComp_X > testSystemMargins.rightRight_X)
        testSystemMargins.rightRight_X=rightComp_X;

      if(qIsInf(testSystemMargins.middleTopTop_Y))
        testSystemMargins.middleTopTop_Y=topComp_Y;
      else if(topComp_Y < testSystemMargins.middleTopTop_Y)
        testSystemMargins.middleTopTop_Y=topComp_Y;

      if(qIsInf(testSystemMargins.rightBottom_Y))
        testSystemMargins.rightBottom_Y=bottomComp_Y;
      else if(bottomComp_Y > testSystemMargins.rightBottom_Y)
        testSystemMargins.rightBottom_Y=bottomComp_Y;
    }
    else if(sutBoxBorder==Bottom)
    {
      if(qIsInf(testSystemMargins.leftLeft_X))
        testSystemMargins.leftLeft_X=leftComp_X;
      else if(leftComp_X < testSystemMargins.leftLeft_X)
        testSystemMargins.leftLeft_X=leftComp_X;

      if(qIsInf(testSystemMargins.rightRight_X))
        testSystemMargins.rightRight_X=rightComp_X;
      else if(rightComp_X > testSystemMargins.rightRight_X)
        testSystemMargins.rightRight_X=rightComp_X;

      if(qIsInf(testSystemMargins.middleBottomTop_Y))
        testSystemMargins.middleBottomTop_Y=topComp_Y;
      else if(topComp_Y < testSystemMargins.middleBottomTop_Y)
        testSystemMargins.middleBottomTop_Y=topComp_Y;

      if(qIsInf(testSystemMargins.middleBottomBottom_Y))
        testSystemMargins.middleBottomBottom_Y=bottomComp_Y;
      else if(bottomComp_Y > testSystemMargins.middleBottomBottom_Y)
        testSystemMargins.middleBottomBottom_Y=bottomComp_Y;
    }
    else
      Q_ASSERT(false);
  }

  return testSystemMargins;
}

void ComRenderTestSystem::Private::renderTestSystemBox()
{
  Q_ASSERT(this->_testSystemScene);

  if(this->_testSystemScene->testComponents().isEmpty())
    return;

  TestSystemMargins testSystemMargins=this->calcTestSystemMargins(this->_testSystemScene->sutBox());

  QPainterPath testSystemBoxPath;

  if(qIsInf(testSystemMargins.leftLeft_X))
    return;

  if(qIsInf(testSystemMargins.middleTopTop_Y))
    return;

  testSystemBoxPath.moveTo(testSystemMargins.leftLeft_X,
                             testSystemMargins.middleTopTop_Y);

  if(!qIsInf(testSystemMargins.leftLeft_X)
     && !qIsInf(testSystemMargins.leftBottom_Y))
  {
    testSystemBoxPath.lineTo(testSystemMargins.leftLeft_X,
                             testSystemMargins.leftBottom_Y - this->_testSystemBoxRadius);
    testSystemBoxPath.quadTo(testSystemMargins.leftLeft_X, testSystemMargins.leftBottom_Y,
                             testSystemMargins.leftLeft_X + this->_testSystemBoxRadius,
                             testSystemMargins.leftBottom_Y);
  }

  if(!qIsInf(testSystemMargins.leftRight_X)
     && !qIsInf(testSystemMargins.leftBottom_Y))
  {
    testSystemBoxPath.lineTo(testSystemMargins.leftRight_X - this->_testSystemBoxRadius,
                             testSystemMargins.leftBottom_Y);
    testSystemBoxPath.quadTo(testSystemMargins.leftRight_X, testSystemMargins.leftBottom_Y,
                             testSystemMargins.leftRight_X,
                             testSystemMargins.leftBottom_Y - this->_testSystemBoxRadius);
  }

  if(!qIsInf(testSystemMargins.leftRight_X)
     && !qIsInf(testSystemMargins.middleTopBottom_Y))
  {
    testSystemBoxPath.lineTo(testSystemMargins.leftRight_X,
                             testSystemMargins.middleTopBottom_Y  + this->_testSystemBoxRadius);
    testSystemBoxPath.quadTo(testSystemMargins.leftRight_X, testSystemMargins.middleTopBottom_Y,
                             testSystemMargins.leftRight_X + this->_testSystemBoxRadius,
                             testSystemMargins.middleTopBottom_Y);
  }

  if(!qIsInf(testSystemMargins.rightLeft_X)
     && !qIsInf(testSystemMargins.middleTopBottom_Y))
  {
    testSystemBoxPath.lineTo(testSystemMargins.rightLeft_X  - this->_testSystemBoxRadius,
                             testSystemMargins.middleTopBottom_Y);
    testSystemBoxPath.quadTo(testSystemMargins.rightLeft_X, testSystemMargins.middleTopBottom_Y,
                             testSystemMargins.rightLeft_X,
                             testSystemMargins.middleTopBottom_Y + this->_testSystemBoxRadius);
  }

  if(!qIsInf(testSystemMargins.rightLeft_X)
     && !qIsInf(testSystemMargins.rightBottom_Y))
  {
    testSystemBoxPath.lineTo(testSystemMargins.rightLeft_X,
                             testSystemMargins.rightBottom_Y - this->_testSystemBoxRadius);
    testSystemBoxPath.quadTo(testSystemMargins.rightLeft_X, testSystemMargins.rightBottom_Y,
                             testSystemMargins.rightLeft_X + this->_testSystemBoxRadius,
                             testSystemMargins.rightBottom_Y);
  }

  if(!qIsInf(testSystemMargins.rightRight_X)
     && !qIsInf(testSystemMargins.rightBottom_Y))
  {
    testSystemBoxPath.lineTo(testSystemMargins.rightRight_X  - this->_testSystemBoxRadius,
                             testSystemMargins.rightBottom_Y);
    testSystemBoxPath.quadTo(testSystemMargins.rightRight_X, testSystemMargins.rightBottom_Y,
                             testSystemMargins.rightRight_X,
                             testSystemMargins.rightBottom_Y - this->_testSystemBoxRadius);
  }

  if(!qIsInf(testSystemMargins.rightRight_X)
     && !qIsInf(testSystemMargins.middleTopTop_Y))
  {
    testSystemBoxPath.lineTo(testSystemMargins.rightRight_X,
                             testSystemMargins.middleTopTop_Y  + this->_testSystemBoxRadius);
    testSystemBoxPath.quadTo(testSystemMargins.rightRight_X, testSystemMargins.middleTopTop_Y,
                             testSystemMargins.rightRight_X  - this->_testSystemBoxRadius,
                             testSystemMargins.middleTopTop_Y);
  }

  ///notation item/////////////
  base::TextItem* testSystemNotationItem=const_cast<base::TextItem*>(this->_testSystemScene->testSystemNotationItem());
  Q_ASSERT(testSystemNotationItem);

  testSystemNotationItem->setDefaultTextColor(this->_testSystemBoxOptions.textColor());
  testSystemNotationItem->setFont(this->_testSystemBoxOptions.textFont());

  QRectF testSystemNotationRect=testSystemNotationItem->boundingRect();

  testSystemBoxPath.lineTo(testSystemMargins.leftLeft_X
                           + testSystemNotationRect.width(),
                           testSystemMargins.middleTopTop_Y);
  testSystemBoxPath.lineTo(testSystemMargins.leftLeft_X
                           + testSystemNotationRect.width(),
                           testSystemMargins.middleTopTop_Y
                           - testSystemNotationRect.height());
  testSystemBoxPath.lineTo(testSystemMargins.leftLeft_X,
                           testSystemMargins.middleTopTop_Y
                           - testSystemNotationRect.height());
  testSystemBoxPath.lineTo(testSystemMargins.leftLeft_X,
                           testSystemMargins.middleTopTop_Y);
  testSystemNotationItem->setPos(testSystemMargins.leftLeft_X,
                                 testSystemMargins.middleTopTop_Y
                                 - testSystemNotationRect.height());

  testSystemNotationItem->show();
  ///end notation item/////////////

  testSystemBoxPath.lineTo(testSystemMargins.leftLeft_X,
                           testSystemMargins.middleTopTop_Y);

  this->_testSystemScene->testSystemBox()->setPath(testSystemBoxPath);
  this->_testSystemScene->testSystemBox()->setBrush(this->_testSystemBoxOptions.getColor());
  this->_testSystemScene->testSystemBox()->setPen(this->_testSystemBoxOptions.pen());
  this->_testSystemScene->testSystemBox()->show();

  return;
}

///ComRenderTestSystem///////////////////////
ComRenderTestSystem::ComRenderTestSystem(TestSystemScene* testSystemScene,
                                         model::ts::TestSystemItem const* testSystemItem,
                                         const NodeOptions& sutCompOptions,
                                         const NodeOptions& sutPortOptions,
                                         const ArcOptions& sutLinkOptions,
                                         const QBrush& sutBoxBrushOption,
                                         const qreal sutCompMarginSpace,
                                         const qreal sutBoxMarginSpace,
                                         const qreal sutBoxRadius,
                                         const NodeOptions& testSystemCompOptions,
                                         const NodeOptions& testSystemPortOptions,
                                         const ArcOptions& testSystemLinkOptions,
                                         const qreal spaceToSutBox,
                                         const NodeOptions& testSystemBoxOptions,
                                         const qreal testSystemBoxMarginSpace,
                                         const qreal testSystemBoxRadius)
  : _d(new Private(testSystemScene, testSystemItem,
                   sutCompOptions, sutPortOptions, sutLinkOptions, sutBoxBrushOption, sutCompMarginSpace,
                   sutBoxMarginSpace, sutBoxRadius,
                   testSystemCompOptions, testSystemPortOptions, testSystemLinkOptions,
                   spaceToSutBox, testSystemBoxOptions,
                   testSystemBoxMarginSpace, testSystemBoxRadius))
{}

ComRenderTestSystem::~ComRenderTestSystem()
{
  delete this->_d;
}

bool ComRenderTestSystem::execute(QString* errorMessage)
{
  Q_ASSERT(this->_d->_testSystemScene);
  Q_ASSERT(this->_d->_testSystemItem);

  Q_UNUSED(errorMessage);

  this->_d->_testSystemScene->setSutBoxBrush(this->_d->_sutBoxBrushOption);
  this->_d->_testSystemScene->reset();

  model::ts::SutItem const* sutItem=this->_d->_testSystemItem->sutItem();
  Q_ASSERT(sutItem);

  ComRenderSut renderSutCommand(this->_d->_testSystemScene,
                                sutItem,
                                this->_d->_sutCompOptions,
                                this->_d->_sutPortOptions,
                                this->_d->_sutLinkOptions,
                                this->_d->_sutBoxBrushOption,
                                this->_d->_sutCompMarginSpace,
                                this->_d->_sutBoxMarginSpace,
                                this->_d->_sutBoxRadius);
  bool result=renderSutCommand.execute(errorMessage);
  if(!result)
    return false;

  this->_d->addViewComponents();
  this->_d->addViewLinks();
  this->_d->renderTestSystemBox();

  return true;
}

} // namespace ts
} // namespace view

