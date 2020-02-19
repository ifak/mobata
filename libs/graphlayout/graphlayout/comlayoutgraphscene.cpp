#include "comlayoutgraphscene.hpp"

#include "layoutgraph.hpp"
#include "layoutnode.hpp"
#include "layoutedge.hpp"
#include "comcreatelayout.hpp"

#include <mobatawidgets/graph/abstractnode.hpp>
#include <mobatawidgets/graph/edge.hpp>
#include <mobatawidgets/base/textitem.hpp>
#include <mobatawidgets/graph/graphscene.hpp>

#include <mobata/memory_leak_start.hpp>

using namespace view::graph;

using namespace graphlayout;

typedef QHash<LayoutNode const*,AbstractNode*>  NodeMap;
typedef QHash<LayoutEdge const*,Edge*>          EdgeMap;

class ComLayoutGraphScene::Private
{
    friend class ComLayoutGraphScene;

    Private(GraphScene *graphScene,
            const QDir &graphvizBinDir)
        : _graphScene(graphScene),
          _graphvizBinDir(graphvizBinDir)
    {}

    void buildLayoutGraph(LayoutGraph& layoutGraph);

    GraphScene*   _graphScene;
    const QDir    _graphvizBinDir;
    NodeMap       _nodes;
    EdgeMap       _edges;
};

void ComLayoutGraphScene::Private::buildLayoutGraph(LayoutGraph &layoutGraph)
{
    foreach(AbstractNode* node, this->_graphScene->nodes())
    {
        LayoutNode* layoutNode=layoutGraph.addNode();
        layoutNode->setExternUuid(node->uuid());
        //layoutNode->setType(QStringLiteral("node"));
        layoutNode->setLabel(node->notation());

        this->_nodes.insert(layoutNode, node);
    }

    foreach(Edge* edge, this->_graphScene->edges())
    {
        AbstractNode* sourceNode=edge->source();
        AbstractNode* targetNode=edge->target();
        Q_ASSERT(sourceNode && targetNode);

        LayoutNode const* sourceLayoutNode = this->_nodes.key(sourceNode);
        Q_ASSERT(sourceLayoutNode);

        LayoutNode const* targetLayoutNode = this->_nodes.key(targetNode);
        Q_ASSERT(targetLayoutNode);

        LayoutEdge* layoutEdge=layoutGraph.addEdge(sourceLayoutNode, targetLayoutNode);
        layoutEdge->setExternUuid(edge->uuid());
        layoutEdge->setLabel(edge->notation());

        this->_edges.insert(layoutEdge, edge);
    }

    return;
}

ComLayoutGraphScene::ComLayoutGraphScene(GraphScene *graphScene,
                                         const QDir &graphvizBinDir,
                                         QObject* parent)
    : QObject(parent),
      _d(new Private(graphScene, graphvizBinDir))
{}

ComLayoutGraphScene::~ComLayoutGraphScene()
{
    delete this->_d;
}

bool ComLayoutGraphScene::execute(QString* errorString)
{
    Q_ASSERT(this->_d->_graphScene);

    LayoutGraph layoutGraph(this->_d->_graphScene->name());
    this->_d->buildLayoutGraph(layoutGraph);

    ComCreateLayout layoutCommand(&layoutGraph,
                                  Dot,
                                  this->_d->_graphvizBinDir);
    bool result=layoutCommand.execute(errorString);
    if(!result)
        return false;

    foreach(LayoutNode* layoutNode, layoutGraph.nodes())
    {
        AbstractNode* sceneNode=this->_d->_nodes.value(layoutNode);
        Q_ASSERT(sceneNode);
        sceneNode->setPos(QPointF(layoutNode->pos().x(),
                                  layoutNode->pos().y()));
        //    sceneNode->setSize(QSizeF(layoutNode->getSize().getWidth(),
        //                       layoutNode->getSize().getHeight()));
    }

    foreach(LayoutEdge* layoutEdge, layoutGraph.edges())
    {
        QVector<QPointF> controlPoints;
        Edge* sceneEdge=this->_d->_edges.value(layoutEdge);
        Q_ASSERT(sceneEdge);

        foreach(const QPointF& layoutPoint, layoutEdge->getPoints())
            controlPoints.append(QPointF(layoutPoint.x(), layoutPoint.y()));

        QPainterPath edgePath;
        if(controlPoints.size()%3==1)///spline arc
        {
            int currentPos=0;
            edgePath.moveTo(controlPoints.at(currentPos++));
            while(currentPos<controlPoints.size())
            {
                edgePath.cubicTo(controlPoints.at(currentPos),
                                 controlPoints.at(currentPos+1),
                                 controlPoints.at(currentPos+2));
                currentPos=currentPos+3;
            }
        }
        else
        {
            edgePath=QPainterPath(sceneEdge->source()->pos());
            edgePath.lineTo(sceneEdge->target()->pos());
        }

        sceneEdge->updatePath(edgePath);

        QPointF edgeSceneLabelPos(layoutEdge->labelPos().x(),layoutEdge->labelPos().y());
        QPointF	edgeLabelPos=sceneEdge->notationItem()->mapFromScene(edgeSceneLabelPos);

        qreal notationItemHeight=sceneEdge->notationItem()->boundingRect().height();
        qreal notationItemWidth=sceneEdge->notationItem()->boundingRect().width();
        QPointF adaptLabelPos(edgeLabelPos.x()-notationItemWidth/2,
                              edgeLabelPos.y()-notationItemHeight/2);

        sceneEdge->notationItem()->setPos(adaptLabelPos);
    }

    return true;
}
