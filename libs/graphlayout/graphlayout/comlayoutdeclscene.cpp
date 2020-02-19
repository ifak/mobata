#include "comlayoutdeclscene.hpp"

#include <mobatawidgets/spenat/declscene.hpp>
#include <mobatawidgets/spenat/declplace.hpp>
#include <mobatawidgets/spenat/decltransition.hpp>
#include <mobatawidgets/spenat/decljunction.hpp>
#include <mobatawidgets/spenat/declarc.hpp>
#include <mobatawidgets/base/textitem.hpp>

#include "layoutgraph.hpp"
#include "layoutnode.hpp"
#include "layoutedge.hpp"
#include "comcreatelayout.hpp"

#include <QDir>
#include <QDebug>

#include <mobata/memory_leak_start.hpp>

using namespace view::graph;
using namespace view::spenat;

using namespace graphlayout;

typedef QHash<LayoutNode const*,DeclPlace*>       PlaceMap;
typedef QHash<LayoutNode const*,DeclTransition*>  TransitionMap;
typedef QHash<LayoutNode const*,DeclJunction*>    JunctionMap;
typedef QHash<LayoutEdge const*,DeclArc*>         ArcMap;

class ComLayoutDeclScene::Private
{
    friend class ComLayoutDeclScene;

    Private(DeclScene *declScene,
            const QString &graphvizPath)
        :	_declScene(declScene), _graphvizPath(graphvizPath)
    {}

public:
    ~Private()
    {}

private:
    void buildLayoutGraph(LayoutGraph& layoutGraph);

private:
    DeclScene*    _declScene;
    const QString _graphvizPath;
    PlaceMap      _placeMap;
    TransitionMap _transitionMap;
    JunctionMap   _junctionMap;
    ArcMap        _arcMap;
};

void ComLayoutDeclScene::Private::buildLayoutGraph(LayoutGraph& layoutGraph)
{
    if(!this->_declScene)
        return;

    foreach(DeclPlace* declPlace, this->_declScene->places())
    {
        LayoutNode* layoutPlaceNode=layoutGraph.addNode();
        layoutPlaceNode->setExternUuid(declPlace->uuid());
        //layoutPlaceNode->setType("place");
        layoutPlaceNode->setLabel(declPlace->notation());

        this->_placeMap.insert(layoutPlaceNode, declPlace);
    }

    foreach(DeclTransition* declTransition, this->_declScene->transitions())
    {
        LayoutNode* layoutTransitionNode=layoutGraph.addNode();
        layoutTransitionNode->setExternUuid(declTransition->uuid());
        //layoutTransitionNode->setType("transition");
        layoutTransitionNode->setLabel(declTransition->notation());

        this->_transitionMap.insert(layoutTransitionNode, declTransition);
    }

    foreach(DeclJunction* declJunction, this->_declScene->junctions())
    {
        LayoutNode* junctionNode=layoutGraph.addNode();
        junctionNode->setExternUuid(declJunction->uuid());
        //junctionNode->setType("junction");

        this->_junctionMap.insert(junctionNode, declJunction);
    }

    foreach(DeclArc* declArc, this->_declScene->arcs())
    {
        AbstractNode const* sourceDeclNode=declArc->source();
        AbstractNode const* targetDeclNode=declArc->target();
        Q_ASSERT(sourceDeclNode && targetDeclNode);

        LayoutNode const* sourceLayoutNode = layoutGraph.nodeByExternUuid(sourceDeclNode->uuid());
        if(!sourceLayoutNode)
            throw std::runtime_error("Source node '"
                                     +sourceDeclNode->notation().toStdString()+
                                     "' not found!");

        LayoutNode const* targetLayoutNode = layoutGraph.nodeByExternUuid(targetDeclNode->uuid());
        if(!targetLayoutNode)
            throw std::runtime_error("Target node '"
                                     +targetDeclNode->notation().toStdString()+
                                     "' not found!");

        LayoutEdge* layoutEdge=layoutGraph.addEdge(sourceLayoutNode, targetLayoutNode);
        layoutEdge->setExternUuid(declArc->uuid());
        layoutEdge->setType(Arrow);
        layoutEdge->setLabel(declArc->notation());

        this->_arcMap.insert(layoutEdge, declArc);
    }

    return;
}

ComLayoutDeclScene::ComLayoutDeclScene(DeclScene *declScene,
                                       const QString &graphvizPath)
    :	_d(new Private(declScene, graphvizPath))
{}

ComLayoutDeclScene::~ComLayoutDeclScene()
{
    delete this->_d;
}

bool ComLayoutDeclScene::execute(QString* errorString)
{
    Q_ASSERT(this->_d->_declScene);

    LayoutGraph layoutGraph(this->_d->_declScene->name());

    this->_d->buildLayoutGraph(layoutGraph);

    ComCreateLayout layoutCommand(&layoutGraph,
                                  Dot,
                                  this->_d->_graphvizPath);
    bool result=layoutCommand.execute(errorString);
    if(!result)
        return  false;

    foreach(LayoutNode* layoutNode, layoutGraph.nodes())
    {
        if(layoutNode/*->type()=="place"*/)
        {
            DeclPlace* declPlace=this->_d->_placeMap.value(layoutNode);
            Q_ASSERT(declPlace);
            declPlace->setPos(QPointF(layoutNode->pos().x(),
                                      layoutNode->pos().y()));
            //			declPlace->setSize(QSizeF(layoutNode->getSize().getWidth(),
            //																layoutNode->getSize().getHeight()));
        }
        else if(layoutNode/*->type()=="transition"*/)
        {
            DeclTransition* declTransition=this->_d->_transitionMap.value(layoutNode);
            Q_ASSERT(declTransition);
            declTransition->setPos(QPointF(layoutNode->pos().x(),
                                           layoutNode->pos().y()));
            //			declTransition->setSize(QSizeF(layoutNode->getSize().getWidth(),
            //																		 layoutNode->getSize().getHeight()));
        }
        else if(layoutNode/*->type()=="junction"*/)
        {
            DeclJunction* declJunction=this->_d->_junctionMap.value(layoutNode);
            Q_ASSERT(declJunction);
            declJunction->setPos(QPointF(layoutNode->pos().x(),
                                         layoutNode->pos().y()));
            //			declJunction->setSize(QSizeF(layoutNode->getSize().getWidth(),
            //																	 layoutNode->getSize().getHeight()));
        }
        else
        {
            if(errorString)
                *errorString+="unknown node type '";
                    //+layoutNode->type()
                    //+"'!";
            return  false;
        }
    }

    foreach(LayoutEdge* layoutEdge, layoutGraph.edges())
    {
        QVector<QPointF> controlPoints;
        DeclArc* declArc=this->_d->_arcMap.value(layoutEdge);
        Q_ASSERT(declArc);

        foreach(const QPointF& layoutPoint, layoutEdge->getPoints())
            controlPoints.append(QPointF(layoutPoint.x(), layoutPoint.y()));

        QPainterPath arcPath;
        if(controlPoints.size()%3==1)///spline arc
        {
            int currentPos=0;
            arcPath.moveTo(controlPoints.at(currentPos++));
            while(currentPos<controlPoints.size())
            {
                arcPath.cubicTo(controlPoints.at(currentPos),
                                controlPoints.at(currentPos+1),
                                controlPoints.at(currentPos+2));
                currentPos=currentPos+3;
            }
        }
        else
        {
            arcPath=QPainterPath(declArc->source()->pos());
            arcPath.lineTo(declArc->target()->pos());
        }

        declArc->updatePath(arcPath);

        QPointF arcSceneLabelPos(layoutEdge->labelPos().x(),layoutEdge->labelPos().y());
        QPointF	arcLabelPos=declArc->notationItem()->mapFromScene(arcSceneLabelPos);

        qreal notationItemHeight=declArc->notationItem()->boundingRect().height();
        qreal notationItemWidth=declArc->notationItem()->boundingRect().width();
        QPointF adaptLabelPos(arcLabelPos.x()-notationItemWidth/2,
                              arcLabelPos.y()-notationItemHeight/2);

        declArc->notationItem()->setPos(adaptLabelPos);
    }

    return true;
}
