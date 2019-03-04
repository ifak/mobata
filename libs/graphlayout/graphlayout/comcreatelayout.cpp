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

#include "comcreatelayout.hpp"

#include "layoutnode.hpp"
#include "layoutedge.hpp"
#include "comcreategraphvizfile.hpp"

#include "graphvizparser/graphvizgraph.hpp"
#include "graphvizparser/comcreategraphvizgraph.hpp"

#include <QTemporaryFile>
#include <QProcess>
#include <QStandardPaths>
#include <QDebug>

#include <stdexcept>

using namespace graphlayout;
using namespace graphvizparser;

class ComCreateLayout::ComCreateLayoutPrivate
{
public:
    ComCreateLayoutPrivate(LayoutGraph* layoutGraph,
                           GraphvizAlgorithm graphvizAlgorithm,
                           const QDir& graphvizBinDir=QDir());

public:
    bool execute(QString* errorString, QString *graphvizLog=nullptr);
    void cluster(LayoutNode* layoutNode);
    QString getGraphvizExeName(GraphvizAlgorithm graphvizAlgorithm);
private:
    LayoutGraph*      _layoutGraph;
    GraphvizAlgorithm _graphvizAlgorithm;
    const QDir        _graphvizBinDir;
};

ComCreateLayout::ComCreateLayoutPrivate::ComCreateLayoutPrivate(LayoutGraph *layoutGraph,
                                                                GraphvizAlgorithm graphvizAlgorithm,
                                                                const QDir& graphvizBinDir)
    :	_layoutGraph(layoutGraph),
      _graphvizAlgorithm(graphvizAlgorithm),
      _graphvizBinDir(graphvizBinDir)
{
}

QString ComCreateLayout::ComCreateLayoutPrivate::getGraphvizExeName(GraphvizAlgorithm graphvizAlgorithm)
{
    QString graphvizExeName=QStringLiteral("");

    if(graphvizAlgorithm==Dot)
        graphvizExeName=QStringLiteral("dot");
    else if(graphvizAlgorithm==Circo)
        graphvizExeName=QStringLiteral("circo");
    else if(graphvizAlgorithm==Fdp)
        graphvizExeName=QStringLiteral("fdp");
    else if(graphvizAlgorithm==Neato)
        graphvizExeName=QStringLiteral("neato");
    else if(graphvizAlgorithm==Osage)
        graphvizExeName=QStringLiteral("osage");
    else if(graphvizAlgorithm==Sfdp)
        graphvizExeName=QStringLiteral("sfdp");
    else if(graphvizAlgorithm==Twopi)
        graphvizExeName=QStringLiteral("twopi");
    else
        throw std::runtime_error("layout algorithm don't supported!");

#ifdef Q_OS_WIN
    if(!graphvizExeName.isEmpty())
        graphvizExeName+=QStringLiteral(".exe");
#endif

    return graphvizExeName;
}

bool ComCreateLayout::ComCreateLayoutPrivate::execute(QString* errorString, QString* graphvizLog)
{
    Q_ASSERT(this->_layoutGraph);

    QString graphvizExeName=getGraphvizExeName(this->_graphvizAlgorithm);
    QString graphvizProgram=QStandardPaths::findExecutable(graphvizExeName);
    if(graphvizProgram.isEmpty())
    {
        if(!this->_graphvizBinDir.exists(graphvizExeName))
        {
            if(errorString)
                *errorString+="Error: graphviz program doesn't exist!\n";
            return  false;
        }
        graphvizProgram=this->_graphvizBinDir.filePath(graphvizExeName);
    }

    for(LayoutEdge* edge: _layoutGraph->edges()) {
        edge->clearPoints();
    }

    QTemporaryFile tempGraphvizFile;
    //! tmpFileDebug
    tempGraphvizFile.setAutoRemove(true);

    if(!tempGraphvizFile.open())
    {
        *errorString+="Error: Temporary file '"
                +tempGraphvizFile.fileName()
                +"' for graphviz-input could not be created!\n";
        return  false;
    }

    QTextStream graphvizStream(&tempGraphvizFile);
    ComCreateGraphvizFile createGraphvizFileCommand(this->_layoutGraph);
    createGraphvizFileCommand.setAlgorithm(this->_graphvizAlgorithm);
    createGraphvizFileCommand.execute(graphvizStream);
    tempGraphvizFile.close();

    QTemporaryFile tempGraphvizOutputFile;
    //! tmpFileDebug
    tempGraphvizOutputFile.setAutoRemove(true);

    if(!tempGraphvizOutputFile.open())
    {
        *errorString+="Error: Temporary file '"
                +tempGraphvizOutputFile.fileName()
                +"' for graphviz-ouput could not be created!\n";
        return  false;
    }
    tempGraphvizOutputFile.close();

    QStringList arguments;
    arguments << "-Tdot" << tempGraphvizFile.fileName();
    arguments << "-o" << tempGraphvizOutputFile.fileName();

    QProcess graphvizProcess;
    graphvizProcess.start(graphvizProgram, arguments);
    if(!graphvizProcess.waitForFinished())
    {
        *errorString+="GraphvizProcessError:"+graphvizProcess.errorString();
        graphvizProcess.kill();

        return  false;
    }

    if(graphvizLog!=nullptr){
        *graphvizLog+=QString(graphvizProcess.readAllStandardError());
    }

    if(!tempGraphvizOutputFile.open())
    {
        *errorString+="Error: Temporary file"
                + tempGraphvizOutputFile.fileName()+
                "for graphviz-ouput could not be created!\n";
        return  false;
    }

    QString outputString=tempGraphvizOutputFile.readAll();
    tempGraphvizOutputFile.close();

    outputString = outputString.replace("STRICT","STRICTT",Qt::CaseSensitive);

    GraphvizGraph graphvizGraph;
    graphvizparser::ComCreateGraphvizGraph graphvizGraphCommand(outputString.toStdString(), _layoutGraph);
    graphvizGraphCommand.execute(errorString);

    for(LayoutNode* node: _layoutGraph->allNodes()){
        if(node->nodes().isEmpty()==true){
            node->setPos(QPointF(node->pos().x()-node->size().width()/2,node->pos().y()-node->size().height()/2));
        }
    }

    QPointF minPoint(10,70);
    QPointF relDist(0,0);
    for(LayoutNode* node: _layoutGraph->nodes()){
        if(node->pos().x()<minPoint.x()){
            if(minPoint.x()-node->pos().x()>relDist.x())
                relDist.setX(minPoint.x()-node->pos().x());
        }
        if(node->pos().y()<minPoint.y()){
            if(minPoint.y()-node->pos().y()>relDist.y())
                relDist.setY(minPoint.y()-node->pos().y());
        }
    }
    for(LayoutEdge* edge: _layoutGraph->edges()){
        for (QPointF* point: edge->points()) {
            if(point->x()<minPoint.x()){
                if(minPoint.x()-point->x()>relDist.x())
                    relDist.setX(minPoint.x()-point->x());
            }
            if(point->y()<minPoint.y()){
                if(minPoint.y()-point->y()>relDist.y())
                    relDist.setY(minPoint.y()-point->y());
            }
        }
        if(edge->labelPos().x()<minPoint.x()){
            if(minPoint.x()-edge->labelPos().x()>relDist.x())
                relDist.setX(minPoint.x()-edge->labelPos().x());
        }
        if(edge->labelPos().y()<minPoint.y()){
            if(minPoint.y()-edge->labelPos().y()>relDist.y())
                relDist.setY(minPoint.y()-edge->labelPos().y());
        }
    }




    for(LayoutNode* node: _layoutGraph->allNodes()){
        node->setPos(node->pos()+relDist);
        node->setLabelPos(node->labelPos()+relDist);
    }

    for(LayoutNode* node: _layoutGraph->nodes()){
        ComCreateLayout::ComCreateLayoutPrivate::cluster(node);
    }

    for (LayoutEdge* edge: _layoutGraph->edges()) {
        for (QPointF* point: edge->points()) {
            point->setX(point->x() + relDist.x());
            point->setY(point->y() + relDist.y());
        }
        edge->setLabelPos(edge->labelPos()+relDist);
    }
    QPointF fullSize(0,0);
    for (LayoutEdge* edge: _layoutGraph->edges()) {
        for (QPointF* point: edge->points()) {
            if(point->x()>fullSize.x())
                fullSize.setX(point->x());
            if(point->y()>fullSize.y())
                fullSize.setY(point->y());
        }
    }
    for(LayoutNode* node: _layoutGraph->allNodes()){
        if(node->pos().x()+node->size().width()>fullSize.x())
            fullSize.setX(node->pos().x()+node->size().width());
        if(node->pos().y()+node->size().height()>fullSize.y())
            fullSize.setY(node->pos().y()+node->size().height());
    }

    _layoutGraph->setGraphSize(QSizeF(fullSize.x()+50,fullSize.y()+50));
    return true;
}

void ComCreateLayout::ComCreateLayoutPrivate::cluster(LayoutNode* layoutNode){
    for(LayoutNode* intnode: layoutNode->nodes()){
        ComCreateLayout::ComCreateLayoutPrivate::cluster(intnode);
        intnode->setPos(intnode->pos()-layoutNode->pos());
    }
}
ComCreateLayout::ComCreateLayout(LayoutGraph *layoutGraph,
                                 GraphvizAlgorithm graphvizAlgorithm)
    : _d(new ComCreateLayoutPrivate(layoutGraph, graphvizAlgorithm, QDir()))
{}

ComCreateLayout::ComCreateLayout(LayoutGraph *layoutGraph,
                                 GraphvizAlgorithm graphvizAlgorithm,
                                 const QString &graphvizBinPath)
    : _d(new ComCreateLayoutPrivate(layoutGraph,
                                    graphvizAlgorithm,
                                    QDir(graphvizBinPath)))
{}

ComCreateLayout::ComCreateLayout(LayoutGraph *layoutGraph,
                                 GraphvizAlgorithm graphvizAlgorithm,
                                 const QDir& graphvizPath)
    : _d(new ComCreateLayoutPrivate(layoutGraph,
                                    graphvizAlgorithm,
                                    graphvizPath))
{}

ComCreateLayout::~ComCreateLayout()
{
    delete this->_d;
}



bool ComCreateLayout::execute(QString* errorString, QString *graphvizLog)
{
    return this->_d->execute(errorString, graphvizLog);
}
