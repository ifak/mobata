#include "declgraphview.hpp"

#include "declscene.hpp"
#include "declplace.hpp"
#include "decltransition.hpp"
#include "decljunction.hpp"
#include "declarc.hpp"

#include <QAction>
#include <QStateMachine>
#include <QAbstractTransition>
#include <QDebug>
#include <QTimer>
#include <QMouseEvent>
#include <QTextCursor>
#include <QCommonStyle>

#include "../base/textitem.hpp"

#include <mobata/utils/functors.hpp>
#include "../graph/functors.hpp"
#include "../graph/graphviewstatemachine.hpp"

#include <mobata/memory_leak_start.hpp>

using namespace utils;

namespace view{
namespace spenat{

using namespace graph;

class SelectState : public AbstractViewState
{
public:
  SelectState(DeclGraphView* declGraphView,
              QState* parentState = 0)
    :	AbstractViewState(declGraphView, parentState)
  {}

public:
  void addItem(QPointF pos)
  {
    DeclScene* declScene = simple_cast<DeclScene*>(this->_graphView->graphScene());
    Q_ASSERT(declScene);

    graph::Edge* edge;
    graph::AbstractNode* node;

    QList<QGraphicsItem*> itemList = declScene->items(pos);

    if((edge = graph::getEdge(declScene->itemAt(pos,
                                                QTransform()))))
    {

      QPainterPath path = edge->path();
      for(int i = 0; i < path.elementCount(); i++)
      {
        QGraphicsRectItem rect(path.elementAt(i).x-10,
                               path.elementAt(i).y-10,
                               20,
                               20);

        if( i == 0 && rect.contains(pos))
        {
          if((node = graph::getNode(itemList)))
          {
            edge->setSource(node);
            path = edge->path();
            QPainterPath newPath = graph::makeRectPath(path);
            edge->updatePath(newPath);
          }
        }
        else if(i == path.elementCount()-1 && rect.contains(pos))
        {
          if((node = graph::getNode(itemList)))
          {
            AbstractNode* firstNode = graph::getNode(declScene->items(QPointF(path.elementAt(0).x,
                                                                              path.elementAt(0).y)));

            QString errorMessage;
            if(!declScene->isValidArc(firstNode, node, &errorMessage))
            {
              qWarning()<<errorMessage;

            }
            else
            {
              edge->setTarget(node);
              path = edge->path();
              QPainterPath newPath = graph::makeRectPath(path);
              edge->updatePath(newPath);
            }
          }
        }
      }
    }

    return;
  }
};

class SelectPressedState : public AbstractViewState
{
public:
  SelectPressedState(DeclGraphView* declGraphView,
                     QState* parentState = 0)
    :	AbstractViewState(declGraphView, parentState)
  {}

public:
  void addItem(QPointF pos)
  {
    Q_UNUSED(pos);

    return;
  }
};

class AddPlaceState : public AbstractViewState
{
public:
  AddPlaceState(DeclGraphView* declGraphView,
                QState* parentState = 0)
    :	AbstractViewState(declGraphView, parentState)
  {}

public:
  void addItem(QPointF pos)
  {
    DeclScene* declScene = simple_cast<DeclScene*>(this->_graphView->graphScene());
    Q_ASSERT(declScene);

    DeclPlace* newPlace=declScene->addPlace(pos);

    if(declScene->items().length()>1)
      newPlace->stackBefore(declScene->items().at(declScene->items().length()-2));

    setFocus(newPlace->notationItem());

    return;

  }
};

class AddTransitionState : public AbstractViewState
{
public:
  AddTransitionState(DeclGraphView* declGraphView,
                     QState* parentState = 0)
    :	AbstractViewState(declGraphView, parentState)
  {}

public:
  void addItem(QPointF pos)
  {
    DeclScene* declScene = simple_cast<DeclScene*>(this->_graphView->graphScene());
    Q_ASSERT(declScene);

    DeclTransition* newTransition=declScene->addTransition(pos);

    if(declScene->items().length()>1)
      newTransition->stackBefore(declScene->items().at(declScene->items().length()-2));

    newTransition->setNotation(QLatin1String("trigger[guard]\nactions;"));
    setFocus(newTransition->notationItem(), true);

    return;
  }
};

class AddJunctionState : public AbstractViewState
{
public:
  AddJunctionState(DeclGraphView* declGraphView,
                   QState* parentState = 0)
    :	AbstractViewState(declGraphView, parentState)
  {}

public:
  void addItem(QPointF pos)
  {
    DeclScene* declScene = simple_cast<DeclScene*>(this->_graphView->graphScene());
    Q_ASSERT(declScene);

    DeclJunction* newJunction = declScene->addJunction(pos);

    if(declScene->items().length()>1)
      newJunction->stackBefore(declScene->items().at(declScene->items().length()-2));

    return;
  }
};

class AddArcState : public AbstractViewState
{
public:
  AddArcState(DeclGraphView* declGraphView,
              QState* parentState = 0)
    :	AbstractViewState(declGraphView, parentState),
      _fromNode(0), _previewEdge(0)
  {}

public:
  void setPreviewEdge(QGraphicsPathItem* previewEdge)
  {
    this->_previewEdge=previewEdge;

    return;
  }

  void addItem(QPointF pos)
  {
    DeclScene* declScene = simple_cast<DeclScene*>(this->_graphView->graphScene());
    Q_ASSERT(declScene);

    if(graph::AbstractNode* node=graph::getNode(declScene->itemAt(pos, QTransform())))
    {
      if(!this->_fromNode)
      {
        this->_fromNode=node;

        QPainterPath edgePath(this->_fromNode->scenePos());
        edgePath.lineTo(pos+QPointF(1,1));
        this->_previewEdge->setPath(edgePath);

        this->_previewEdge->show();
      }
      else
      {
        QString errorMessage;
        if(!declScene->isValidArc(this->_fromNode, node, &errorMessage))
        {
          qWarning()<<errorMessage;
        }
        else
        {
          DeclArc* newArc=declScene->addArc(this->_fromNode, node,
                                            this->_previewEdge->path(), QLatin1String(""));

          QPainterPath newPath = newArc->path();
          //newPath = graph::makeNiceArcPoints(&newPath,50);
          declScene->removeArc(newArc);

          DeclArc* newArc2=declScene->addArc(this->_fromNode,
                                             node,
                                             graph::makeRectPath(newPath),
                                             QLatin1String(""));
          QColor col = Qt::red;
          newArc2->setPen(col);

          if(dynamic_cast<DeclPlace*>(this->_fromNode)
             && dynamic_cast<DeclPlace*>(node))
          {//transition
            newArc->setNotation(QLatin1String("trigger[guard]/\nactions;"));
            setFocus(newArc->notationItem(), true);
          }
          else if(dynamic_cast<DeclPlace*>(this->_fromNode)
                  && dynamic_cast<DeclJunction*>(node))
          {//junction trigger
            newArc->setNotation(QLatin1String("trigger"));
            setFocus(newArc->notationItem(), true);
          }
          else if(dynamic_cast<DeclJunction*>(this->_fromNode)
                  && dynamic_cast<DeclPlace*>(node))
          {//junction target
            newArc->setNotation(QLatin1String("[guard]/\nactions;"));
            setFocus(newArc->notationItem(), true);
          }
        }

        this->_fromNode=0;
        this->_previewEdge->hide();
      }
    }
    else
    {
      if(!this->_previewEdge->isVisible())
        return;

      if(declScene->items(pos).size()<2)
      {
        QPointF gridPos=declScene->onGrid(pos);
        QPainterPath previewEdgePath=this->_previewEdge->path();
        previewEdgePath.setElementPositionAt(previewEdgePath.elementCount()-1,
                                             gridPos.x(),
                                             gridPos.y());
        previewEdgePath.lineTo(gridPos+QPointF(1,1));

        this->_previewEdge->setPath(previewEdgePath);
      }
    }

    return;
  }

  void mouseMove(QPointF posF)
  {
    if(!this->_previewEdge->isVisible())
      return;

    DeclScene* declScene = simple_cast<DeclScene*>(this->_graphView->graphScene());
    Q_ASSERT(declScene);

    QPointF	mousePoint=this->_graphView->mapToScene(posF.toPoint());
    mousePoint=declScene->onGrid(mousePoint);

    QPainterPath edgePath=this->_previewEdge->path();
    edgePath.setElementPositionAt(edgePath.elementCount()-1,
                                  mousePoint.x(),
                                  mousePoint.y());
    this->_previewEdge->setPath(edgePath);

    return;
  }

  void onExit(QEvent * event)
  {
    Q_UNUSED(event);

    this->_fromNode=0;

    if(this->_previewEdge)
      this->_previewEdge->hide();

    return;
  }

private:
  graph::AbstractNode*	_fromNode;
  QGraphicsPathItem*		_previewEdge;
};

class InitMarkingState : public AbstractViewState
{
public:
  InitMarkingState(DeclGraphView* declGraphView,
                   QState* parentState = 0)
    :	AbstractViewState(declGraphView, parentState)
  {}

public:
  void addItem(QPointF pos)
  {
    DeclScene* declScene = simple_cast<DeclScene*>(this->_graphView->graphScene());
    Q_ASSERT(declScene);

    if(graph::AbstractNode* node=graph::getNode(declScene->itemAt(pos, QTransform())))
    {
      if(DeclPlace* initMarkingPlace=dynamic_cast<DeclPlace*>(node))
        declScene->changeInitMarking(initMarkingPlace);
    }

    return;
  }
};

class DeclGraphView::Private
{
  friend class DeclGraphView;

public:
  Private()
    : _stateMachine(0), _selectState(0), _addPlaceState(0), _addTransitionState(0),
      _addJunctionState(0), _addArcState(0), _initMarkingState(0),
      _selectAction(0), _addPlaceAction(0), _addTransitionAction(0),
      _addJunctionAction(0), _addArcAction(0), _initMarkingAction(0),
      _previewEdge(0)
  {}
  ~Private()
  {}

private:
  QStateMachine*			_stateMachine;
  SelectState*				_selectState;
  SelectPressedState*	_selectPressedState;
  AddPlaceState*			_addPlaceState;
  AddTransitionState*	_addTransitionState;
  AddJunctionState*		_addJunctionState;
  AddArcState*				_addArcState;
  InitMarkingState*		_initMarkingState;
  QAction*						_selectAction;
  QAction*            _addPlaceAction;
  QAction*            _addTransitionAction;
  QAction*            _addJunctionAction;
  QAction*            _addArcAction;
  QAction*            _initMarkingAction;
  QGraphicsPathItem*	_previewEdge;
};

DeclGraphView::DeclGraphView(QWidget* parent)
  : GraphView(parent), _d(new Private())
{
  this->createActions();
  this->createStateMachine();

  QTimer::singleShot(0, this->_d->_stateMachine, SLOT(start()));
}


DeclGraphView::~DeclGraphView()
{}

void DeclGraphView::createPreviewStuff()
{
  if(!this->scene())
    return;

  this->_d->_previewEdge=new QGraphicsPathItem(QPainterPath(QPointF(0,0)));
  this->_d->_previewEdge->setPen(QPen(Qt::darkRed, 2, Qt::DotLine));
  this->scene()->addItem(this->_d->_previewEdge);
  this->_d->_previewEdge->hide();
  this->_d->_addArcState->setPreviewEdge(this->_d->_previewEdge);

  return;
}

void DeclGraphView::createActions()
{
  this->_d->_selectAction = new QAction(QIcon(QLatin1String(":/mobata/images/select.png")),
                                        tr("select"),
                                        this);
  this->_d->_selectAction->setStatusTip(tr("select something"));
  this->_d->_selectAction->setToolTip(tr("select something"));
  this->_d->_selectAction->setCheckable(true);

  this->_d->_addPlaceAction = new QAction(QIcon(QLatin1String(":/mobata/images/spenat/place.png")),
                                          tr("add place"),
                                          this);
  this->_d->_addPlaceAction->setStatusTip(tr("add a place"));
  this->_d->_addPlaceAction->setToolTip(tr("add a place"));
  this->_d->_addPlaceAction->setCheckable(true);

  this->_d->_addTransitionAction = new QAction(QIcon(QLatin1String(":/mobata/images/spenat/transition.png")),
                                               tr("add transition"),
                                               this);
  this->_d->_addTransitionAction->setStatusTip(tr("add a transition"));
  this->_d->_addTransitionAction->setToolTip(tr("add a transition"));
  this->_d->_addTransitionAction->setCheckable(true);

  this->_d->_addJunctionAction = new QAction(QIcon(QLatin1String(":/mobata/images/spenat/junction.png")),
                                             tr("add junction"),
                                             this);
  this->_d->_addJunctionAction->setStatusTip(tr("add a junction"));
  this->_d->_addJunctionAction->setToolTip(tr("add a junction"));
  this->_d->_addJunctionAction->setCheckable(true);

  this->_d->_addArcAction = new QAction(QIcon(QLatin1String(":/mobata/images/spenat/arc.png")),
                                        tr("add arc"),
                                        this);
  this->_d->_addArcAction->setStatusTip(tr("add a arc"));
  this->_d->_addArcAction->setToolTip(tr("add a arc"));
  this->_d->_addArcAction->setCheckable(true);

  this->_d->_initMarkingAction = new QAction(QIcon(QLatin1String(":/mobata/images/spenat/marking.png")),
                                             tr("init marking"),
                                             this);
  this->_d->_initMarkingAction->setStatusTip(tr("set init marking of a place"));
  this->_d->_initMarkingAction->setToolTip(tr("set init marking of a place"));
  this->_d->_initMarkingAction->setCheckable(true);

  QActionGroup* exclActionGroup=new QActionGroup(this);
  exclActionGroup->setExclusive(true);
  exclActionGroup->addAction(this->_d->_selectAction);
  exclActionGroup->addAction(this->_d->_addPlaceAction);
  exclActionGroup->addAction(this->_d->_addTransitionAction);
  exclActionGroup->addAction(this->_d->_addJunctionAction);
  exclActionGroup->addAction(this->_d->_addArcAction);
  exclActionGroup->addAction(this->_d->_initMarkingAction);

  return;
}

void DeclGraphView::createStateMachine()
{
  this->_d->_stateMachine=new QStateMachine(this);

  this->_d->_selectState=new SelectState(this);
  this->_d->_selectState->assignProperty(this->_d->_selectAction, "checked", true);
  this->_d->_stateMachine->addState(this->_d->_selectState);
  this->_d->_stateMachine->setInitialState(this->_d->_selectState);

  QState* selectNormalState=new QState(this->_d->_selectState);
  this->_d->_selectState->setInitialState(selectNormalState);

  this->_d->_selectPressedState=new SelectPressedState(this, this->_d->_selectState);

  ////transitions for sub-state-machine of select-state/////////////
  MousePressTransition* mousePressTransition = new MousePressTransition();
  mousePressTransition->setTargetState(this->_d->_selectPressedState);
  selectNormalState->addTransition(mousePressTransition);

  MouseReleaseTransition* mouseReleaseTransition = new MouseReleaseTransition();
  mouseReleaseTransition->setTargetState(selectNormalState);
  this->_d->_selectPressedState->addTransition(mouseReleaseTransition);
  /////////////end transitions of sub-state-machine of select-state

  this->_d->_addPlaceState=new AddPlaceState(this);
  this->_d->_addPlaceState->assignProperty(this->_d->_addPlaceAction, "checked", true);
  this->_d->_stateMachine->addState(this->_d->_addPlaceState);

  this->_d->_addTransitionState=new AddTransitionState(this);
  this->_d->_addTransitionState->assignProperty(this->_d->_addTransitionAction, "checked", true);
  this->_d->_stateMachine->addState(this->_d->_addTransitionState);

  this->_d->_addJunctionState=new AddJunctionState(this);
  this->_d->_addJunctionState->assignProperty(this->_d->_addJunctionAction, "checked", true);
  this->_d->_stateMachine->addState(this->_d->_addJunctionState);

  this->_d->_addArcState=new AddArcState(this);
  this->_d->_addArcState->assignProperty(this->_d->_addArcAction, "checked", true);
  this->_d->_stateMachine->addState(this->_d->_addArcState);

  this->_d->_initMarkingState=new InitMarkingState(this);
  this->_d->_initMarkingState->assignProperty(this->_d->_initMarkingAction, "checked", true);
  this->_d->_stateMachine->addState(this->_d->_initMarkingState);

  foreach(QState* viewState,
          QList<QState*>()<< this->_d->_addPlaceState<<this->_d->_addTransitionState
          <<this->_d->_addJunctionState<<this->_d->_addArcState<<this->_d->_initMarkingState)
  {
    viewState->addTransition(this->_d->_selectAction,
                             SIGNAL(triggered()),
                             this->_d->_selectState);
    FocusOutTransition* focusLostTransition = new FocusOutTransition();
    focusLostTransition->setTargetState(this->_d->_selectState);
    viewState->addTransition(focusLostTransition);
  }

  foreach(QState* viewState,
          QList<QState*>()<< this->_d->_selectState<<this->_d->_addTransitionState
          <<this->_d->_addJunctionState<<this->_d->_addArcState<<this->_d->_initMarkingState)
    viewState->addTransition(this->_d->_addPlaceAction,
                             SIGNAL(triggered()),
                             this->_d->_addPlaceState);

  foreach(QState* viewState,
          QList<QState*>()<< this->_d->_selectState<<this->_d->_addPlaceState
          <<this->_d->_addJunctionState<<this->_d->_addArcState<<this->_d->_initMarkingState)
    viewState->addTransition(this->_d->_addTransitionAction,
                             SIGNAL(triggered()),
                             this->_d->_addTransitionState);

  foreach(QState* viewState,
          QList<QState*>()<< this->_d->_selectState<<this->_d->_addPlaceState
          <<this->_d->_addTransitionState<<this->_d->_addArcState<<this->_d->_initMarkingState)
    viewState->addTransition(this->_d->_addJunctionAction,
                             SIGNAL(triggered()),
                             this->_d->_addJunctionState);

  foreach(QState* viewState,
          QList<QState*>()<< this->_d->_selectState<<this->_d->_addPlaceState
          <<this->_d->_addTransitionState<<this->_d->_addJunctionState<<this->_d->_initMarkingState)
    viewState->addTransition(this->_d->_addArcAction,
                             SIGNAL(triggered()),
                             this->_d->_addArcState);

  foreach(QState* viewState,
          QList<QState*>()<< this->_d->_selectState<<this->_d->_addPlaceState
          <<this->_d->_addTransitionState<<this->_d->_addJunctionState<<this->_d->_addArcState)
    viewState->addTransition(this->_d->_initMarkingAction,
                             SIGNAL(triggered()),
                             this->_d->_initMarkingState);

  return;
}

DeclScene* DeclGraphView::declGraphScene()
{
  return simple_cast<DeclScene*>(this->scene());
}

void DeclGraphView::setDeclGraphScene(DeclScene *declGraphScene)
{
  this->setScene(declGraphScene);

  if(this->scene())
    this->createPreviewStuff();

  return;
}

void DeclGraphView::reset()
{
  if(!this->scene())
    return;

  this->declGraphScene()->reset();
  this->createPreviewStuff();
  this->updateSceneRect();

  return;
}

QAction *DeclGraphView::selectAction()
{
  return this->_d->_selectAction;
}

QAction* DeclGraphView::addPlaceAction()
{
  return this->_d->_addPlaceAction;
}

QAction* DeclGraphView::addTransitionAction()
{
  return this->_d->_addTransitionAction;
}

QAction* DeclGraphView::addJunctionAction()
{
  return this->_d->_addJunctionAction;
}

QAction* DeclGraphView::addArcAction()
{
  return this->_d->_addArcAction;
}

QAction *DeclGraphView::initMarkingAction()
{
  return this->_d->_initMarkingAction;
}

QList<QAction *> DeclGraphView::declGraphViewActions()
{
  return QList<QAction*>()<<this->_d->_selectAction
                         <<this->_d->_addPlaceAction
                        <<this->_d->_addTransitionAction
                       <<this->_d->_addJunctionAction
                      <<this->_d->_addArcAction
                     <<this->_d->_initMarkingAction;
}

void DeclGraphView::mousePressEvent(QMouseEvent *event)
{
  if(!(this->_d->_stateMachine
       &&this->scene()))
    return GraphView::mousePressEvent(event);

  this->_d->_stateMachine->postEvent(new QEvent(QEvent::MouseButtonPress));

  typedef QSet<QAbstractState*> StateSet;
  StateSet currentStates=this->_d->_stateMachine->configuration();
  if(currentStates.find(this->_d->_selectState)!=currentStates.end())
    return GraphView::mousePressEvent(event);

  this->declGraphScene()->clearSelection();

  return;
}

void DeclGraphView::mouseReleaseEvent(QMouseEvent *event)
{
  if(!(this->_d->_stateMachine
       &&this->scene()))
    return GraphView::mouseReleaseEvent(event);

  this->_d->_stateMachine->postEvent(new QEvent(QEvent::MouseButtonRelease));

  DeclScene* declScene=this->declGraphScene();
  Q_ASSERT(declScene);

  foreach(QAbstractState* abstractState,
          this->_d->_stateMachine->configuration())
  {
    AbstractViewState* viewState=dynamic_cast<AbstractViewState*>(abstractState);
    if(!viewState)
      continue;

    QPointF	mousePoint=this->mapToScene(event->pos());
    mousePoint=declScene->onGrid(mousePoint);

    viewState->addItem(mousePoint);
  }

  GraphView::mouseReleaseEvent(event);

  this->updateSceneRect();

  return;
}

void DeclGraphView::mouseMoveEvent(QMouseEvent* event)
{
  if(!(this->_d->_stateMachine
       &&this->scene()))
    return GraphView::mouseMoveEvent(event);

  foreach(QAbstractState* abstractState,
          this->_d->_stateMachine->configuration())
  {
    AbstractViewState* viewState=dynamic_cast<AbstractViewState*>(abstractState);
    if(!viewState)
      continue;

    viewState->mouseMove(event->pos());
  }

  return GraphView::mouseMoveEvent(event);
}

void DeclGraphView::focusOutEvent(QFocusEvent *event)
{
  if(this->_d->_stateMachine)
    this->_d->_stateMachine->postEvent(new QEvent(QEvent::FocusOut));

  return GraphView::focusOutEvent(event);
}

void DeclGraphView::resizeEvent(QResizeEvent *event)
{
  GraphView::resizeEvent(event);

  this->updateSceneRect();

  return;
}

void DeclGraphView::keyReleaseEvent(QKeyEvent *event)
{
  if(event->key()==Qt::Key_Delete)
  {
    DeclScene* declScene=this->declGraphScene();
    if(!declScene)
      return;

    foreach(QGraphicsItem* selectedItem, declScene->selectedItems())
      declScene->removeGraphItem(selectedItem);
  }

  return graph::GraphView::keyReleaseEvent(event);
}

}/// end namespace spenat
}/// end namespace view
