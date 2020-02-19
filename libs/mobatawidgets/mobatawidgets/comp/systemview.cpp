#include "systemview.hpp"

#include "systemscene.hpp"
#include "component.hpp"
#include "port.hpp"
#include "link.hpp"

#include <mobata/utils/functors.hpp>
#include "../graph/functors.hpp"

#include <QActionGroup>
#include <QToolBar>
#include <QMouseEvent>
#include <QMessageBox>
#include <QDebug>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace comp{

///helper methods////////////
template<class CompType>
CompType* getCompType(QGraphicsItem* pointItem)
{
  if(!pointItem)
    return 0;

  CompType* compTypeInstance=0;

  if((compTypeInstance=dynamic_cast<CompType*>(pointItem)))
    return compTypeInstance;
  else if((compTypeInstance=dynamic_cast<CompType*>(pointItem->parentItem())))
    return compTypeInstance;

  return 0;
}


Link* getLink(QGraphicsItem* pointItem)
{
  if(!pointItem)
    return 0;

  Link *link = 0;

  if((link = dynamic_cast<Link*>(pointItem)))
    return link;
  else if((link = dynamic_cast<Link*>(pointItem->parentItem())))
    return link;

  return 0;
}

SystemView::SystemView(SystemScene* systemScene,
                       QWidget* parent)
  : graph::GraphView(systemScene, parent),
    _preViewComponent(0),
    _preViewLink(0),
    _fromPort(0),
    _compOptions(),
    _portOptions(),
    _linkOptions()
{
  this->_mode=SELECT;

  this->_compOptions=NodeOptions().setSize(100,75);
  this->_portOptions=NodeOptions().setSize(15,15).setColor(Qt::white).setPen(QPen(Qt::black, 3));

  this->_preViewComponent=systemScene->addRect(-50, -50, 100, 100, QPen(Qt::darkRed, 3, Qt::DashDotLine));
  this->_preViewComponent->hide();

  this->_preViewLink=systemScene->addPath(QPainterPath(), QPen(Qt::darkGreen, 3, Qt::DotLine));
  this->_preViewLink->hide();

  this->_actionGroup=new QActionGroup(this);
  this->_actionGroup->setExclusive(true);

  ///////actions//////////////////////////////
  QAction* setSelectModeAct = new QAction(QIcon(":/mobata/images/select.png"),
                                          tr("select an object"),
                                          this);
  setSelectModeAct->setCheckable(true);
  setSelectModeAct->setChecked(true);
  setSelectModeAct->setStatusTip(tr("select an object"));
  setSelectModeAct->setData(SELECT);
  connect(setSelectModeAct, SIGNAL(triggered()),
          this, SLOT(setSelectModeSlot()));
  this->_actionGroup->addAction(setSelectModeAct);

  QAction* setAddComponentModeAct = new QAction(QIcon(":/mobata/images/comp/component.png"),
                                                tr("add component"),
                                                this);
  setAddComponentModeAct->setCheckable(true);
  setAddComponentModeAct->setStatusTip(tr("add component to this system"));
  setAddComponentModeAct->setData(ADDCOMPONENT);
  connect(setAddComponentModeAct, SIGNAL(triggered()),
          this, SLOT(setAddComponentModeSlot()));
  this->_actionGroup->addAction(setAddComponentModeAct);

  QAction* setAddPortModeAct = new QAction(QIcon(":/mobata/images/comp/port.png"),
                                           tr("add port"),
                                           this);
  setAddPortModeAct->setCheckable(true);
  setAddPortModeAct->setStatusTip(tr("add port to a component of this system model"));
  setAddPortModeAct->setData(ADDPORT);
  connect(setAddPortModeAct, SIGNAL(triggered()),
          this, SLOT(setAddPortModeSlot()));
  this->_actionGroup->addAction(setAddPortModeAct);

  QAction* setAddLinkModeAct = new QAction(QIcon(":/mobata/images/comp/link.png"),
                                           tr("add link"),
                                           this);
  setAddLinkModeAct->setCheckable(true);
  setAddLinkModeAct->setStatusTip(tr("add link between two ports of this system model"));
  setAddLinkModeAct->setData(ADDLINK);
  connect(setAddLinkModeAct, SIGNAL(triggered()),
          this, SLOT(setAddLinkModeSlot()));
  this->_actionGroup->addAction(setAddLinkModeAct);
}

SystemView::~SystemView()
{}

SystemScene* SystemView::systemScene()
{
  return utils::simple_cast<SystemScene*>(this->scene());
}

QAction*SystemView::action(const QVariant& actionData)
{
  if(actionData.isNull()
     || !actionData.isValid())
    return 0;

  foreach(QAction* action, this->_actionGroup->actions())
    if(action->data()==actionData)
      return action;

  return 0;
}

QList<QAction*> SystemView::systemViewActions()
{
  return this->_actionGroup->actions();
}

void SystemView::setSelectModeSlot()
{
  this->_mode=SELECT;
  QAction* modeAction=this->action(SELECT);
  Q_ASSERT(modeAction);
  modeAction->setChecked(true);

  this->_preViewComponent->hide();
  this->_fromPort=0;
  this->_preViewLink->hide();

  this->setCursor(QCursor(Qt::ArrowCursor));

  return;
}

void SystemView::setAddComponentModeSlot()
{
  this->_mode=ADDCOMPONENT;
  QAction* modeAction=this->action(ADDCOMPONENT);
  Q_ASSERT(modeAction);
  modeAction->setChecked(true);

  this->_fromPort=0;
  this->_preViewLink->hide();

  this->setCursor(QCursor(QPixmap(":/mobata/images/comp/componentcursor.png")));

  return;
}

void SystemView::setAddPortModeSlot()
{
  this->_mode = ADDPORT;
  QAction* modeAction = this->action(ADDPORT);
  Q_ASSERT(modeAction);
  modeAction->setChecked(true);

  this->_preViewComponent->hide();
  this->_fromPort = 0;
  this->_preViewLink->hide();

  this->setCursor(QCursor(QPixmap(":/mobata/images/comp/portcursor.png")));

  return;
}

void SystemView::setAddLinkModeSlot()
{
  this->_mode = ADDLINK;
  QAction* modeAction = this->action(ADDLINK);
  Q_ASSERT(modeAction);
  modeAction->setChecked(true);

  this->_preViewComponent->hide();
  this->_fromPort = 0;

  this->setCursor(QCursor(QPixmap(":/mobata/images/comp/linkcursor.gif")));

  return;
}

void SystemView::keyReleaseEvent(QKeyEvent* event)
{
  if(!event)
    return;

  if(event->key()==Qt::Key_Delete)
  {
    SystemScene* systemScene=this->systemScene();
    Q_ASSERT(systemScene);
    QList<QGraphicsItem*> selectedItems=systemScene->selectedItems();
    this->removeCompItems(selectedItems);
  }

  return;
}

void SystemView::removeCompItems(QList<QGraphicsItem*>& graphicsItems)
{
  SystemScene* systemScene=this->systemScene();
  Q_ASSERT(systemScene);

  foreach(QGraphicsItem* currItem, graphicsItems)
  {
    if(currItem->isEnabled())
    {
      if(Link* link = dynamic_cast<Link*>(currItem)){
        systemScene->removeLink(link);
      } else if(Port* port = getCompType<Port>(currItem)){
        systemScene->removePort(port);
      } else if(Component* component = getCompType<Component>(currItem)){
        systemScene->removeComponent(component);
      }
    }
  }

  return;
}

void SystemView::mouseReleaseEvent(QMouseEvent* event)
{
  if(this->_mode==ADDCOMPONENT)
  {
    Component* newComponent=new Component("newComponent",
                                          this->_compOptions);
    this->systemScene()->addComponent(newComponent,
                                      this->mapToScene(event->pos()));
    this->setSelectModeSlot();
  }
  else if(_mode==ADDPORT)
  {
    if(Component* component=getCompType<Component>(this->itemAt(event->pos())))
    {
      this->systemScene()->addPort(component,
                                   this->mapToScene(event->pos()),
                                   this->_portOptions);
      this->setSelectModeSlot();
    }
  }
  else if(_mode==ADDLINK)
  {
    if((this->_fromPort=getCompType<Port>(this->itemAt(event->pos()))))
    {
      this->_mode=ADDLINKTARGET;

      QPainterPath linkerPath(this->_fromPort->scenePos());
      linkerPath.lineTo(this->mapToScene(event->pos())+QPointF(1,1));
      this->_preViewLink->setPath(linkerPath);

      this->_preViewLink->show();
    }
  }
  else if(_mode==ADDLINKTARGET)
  {
    if(Port* targetPort=getCompType<Port>(this->itemAt(event->pos())))
    {
      if(this->_fromPort==targetPort)
      {
        QMessageBox::critical(this,
                              "Error",
                              "Link with same port as source and target are not allowed. "
                              "Please chose another port as target for this link.");
        return;
      }
      this->systemScene()->addLink(this->_fromPort,
                                   targetPort,
                                   this->_preViewLink->path(),
                                   this->_linkOptions);
      this->setSelectModeSlot();
    }
    else if(this->items(event->pos()).size()<2)
    {
      QPainterPath linkerPath=this->_preViewLink->path();

      QPointF	mousePoint=this->mapToScene(event->pos());
      linkerPath.setElementPositionAt(linkerPath.elementCount()-1, mousePoint.x(), mousePoint.y());

      linkerPath.lineTo(this->mapToScene(event->pos())+QPointF(1,1));

      this->_preViewLink->setPath(linkerPath);
      this->_preViewLink->show();
    }
  }

  return QGraphicsView::mouseReleaseEvent(event);
}

void SystemView::mouseMoveEvent(QMouseEvent* event)
{
  if(this->_mode==ADDCOMPONENT)
  {
    this->_preViewComponent->setPos(this->mapToScene(event->pos()));
    if(!this->_preViewComponent->isVisible())
      this->_preViewComponent->show();
  }
  else if(_mode==ADDLINKTARGET)
  {
    QPainterPath linkerPath=this->_preViewLink->path();

    QPointF	mousePoint=this->mapToScene(event->pos());
    linkerPath.setElementPositionAt(linkerPath.elementCount()-1, mousePoint.x(), mousePoint.y());

    this->_preViewLink->setPath(linkerPath);
  }

  return QGraphicsView::mouseMoveEvent(event);
}

void SystemView::focusOutEvent(QFocusEvent *event)
{
  this->setSelectModeSlot();

  return QGraphicsView::focusOutEvent(event);
}

void SystemView::setCompNodeOptions(NodeOptions options)
{
  this->_compOptions = options;
  return;
}

void SystemView::setPortNodeOptions(NodeOptions options)
{
  this->_portOptions = options;
  return;
}

void SystemView::setLinkArcOptions(ArcOptions options)
{
  this->_linkOptions = options;
  return;
}

}////end namespace comp
}/// end namespace view
