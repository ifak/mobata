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

#include "comcreatelayoutedgesonly.hpp"

#include "comcreategraphvizfile.hpp"
#include "layoutnode.hpp"
#include "layoutedge.hpp"

#include "graphvizparser/graphvizgraph.hpp"
#include "graphvizparser/comcreategraphvizgraph.hpp"

#include <QTemporaryFile>
#include <QProcess>
#include <QStandardPaths>
#include <QDebug>

#include <stdexcept>

using namespace graphlayout;
using namespace graphvizparser;

class ComCreateLayoutEdgesOnly::ComCreateLayoutEdgesOnlyPrivate
{
public:
  ComCreateLayoutEdgesOnlyPrivate(LayoutGraph* layoutGraph,
                                  GraphvizAlgorithm graphvizAlgorithm,
                                  const QDir& graphvizBinDir=QDir());
  ~ComCreateLayoutEdgesOnlyPrivate(){
  }

public:
  bool execute(QString* errorString, QString *graphvizLog=nullptr);
  void graphToTmpgraph();
  void tmpgraphToGraph();
  void cluster(LayoutNode* layoutNode);
  QString getGraphvizExeName(GraphvizAlgorithm graphvizAlgorithm);
private:
  LayoutGraph*      _layoutGraph;
  LayoutGraph*      _tempLayoutGraph;
  GraphvizAlgorithm _graphvizAlgorithm;
  const QDir        _graphvizBinDir;
  double _factor = 0.90;
};

ComCreateLayoutEdgesOnly::ComCreateLayoutEdgesOnlyPrivate::ComCreateLayoutEdgesOnlyPrivate(LayoutGraph *layoutGraph,
                                                                                           GraphvizAlgorithm graphvizAlgorithm,
                                                                                           const QDir& graphvizBinDir)
  :	_layoutGraph(layoutGraph),
    _graphvizAlgorithm(graphvizAlgorithm),
    _graphvizBinDir(graphvizBinDir)
{
}

QString ComCreateLayoutEdgesOnly::ComCreateLayoutEdgesOnlyPrivate::getGraphvizExeName(GraphvizAlgorithm graphvizAlgorithm){
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

void ComCreateLayoutEdgesOnly::ComCreateLayoutEdgesOnlyPrivate::tmpgraphToGraph(){
  for (LayoutEdge* edge: _layoutGraph->edges()) {
    edge->clearPoints();
    LayoutEdge* tmpedge = _tempLayoutGraph->edgeByExternUuid(edge->externUuid());
    edge->setLabelPos(tmpedge->labelPos());
    edge->setLabelTextSize(tmpedge->labelTextSize());
    for (QPointF* point: tmpedge->points()) {
      edge->addPoint(QPointF(point->x(),point->y()));
    }
  }
  for(LayoutNode* node: _layoutGraph->allNodes()) {
    LayoutNode* tmpNode = _tempLayoutGraph->nodeByExternUuid(node->externUuid());
    if(tmpNode!=nullptr){
      node->setPos(tmpNode->pos());
      node->setLabelPos(tmpNode->labelPos());
      node->setLabelTextSize(tmpNode->labelTextSize());
      if(node->nodes().isEmpty()==false){
        node->setSize(tmpNode->size());
      }
    }
  }
  for(LayoutNodePort const* layoutPort: _layoutGraph->allUsedPorts()) {
    LayoutNode* tmpNode = _tempLayoutGraph->nodeByExternUuid(layoutPort->externUuid());
    if(tmpNode!=nullptr){
      LayoutNodePort* port=const_cast<LayoutNodePort*>(layoutPort);
      Q_ASSERT(port);
      port->setPos(tmpNode->pos());
      port->setLabelPos(tmpNode->labelPos());
      port->setLabelSize(tmpNode->labelTextSize());
      port->setPos(QPointF(port->pos().x(),-port->pos().y()));
    }
  }
}

void ComCreateLayoutEdgesOnly::ComCreateLayoutEdgesOnlyPrivate::graphToTmpgraph(){

  _tempLayoutGraph->setSplines(_layoutGraph->splines());
  _tempLayoutGraph->setOverlap(default0);

  for(LayoutNode* node: _layoutGraph->nodes()) {
    LayoutNode* newNode = _tempLayoutGraph->addNode();
    newNode->setUuid(node->uuid());
    newNode->setExternUuid(node->externUuid());
    newNode->setShape(node->shape());
    newNode->setLabel(node->label());
    newNode->setXLabel(node->xLabel());
    QPointF tmpPoint(node->pos());
    tmpPoint += QPointF(node->size().width()/2,node->size().height()/2);
    tmpPoint = QPointF(tmpPoint.x(),-tmpPoint.y());
    newNode->setPos(tmpPoint);
    newNode->setSize(node->size()*_factor);

    for(LayoutNode* intnode: node->nodes()) {
      LayoutNode* newIntNode = newNode->addNode();
      newIntNode->setUuid(intnode->uuid());
      newIntNode->setExternUuid(intnode->externUuid());
      newIntNode->setShape(intnode->shape());
      newIntNode->setLabel(intnode->label());
      QPointF tmpPoint(intnode->pos());
      tmpPoint += QPointF(intnode->size().width()/2,intnode->size().height()/2);
      tmpPoint = QPointF(tmpPoint.x(),-tmpPoint.y());
      newIntNode->setPos(QPointF(tmpPoint.x(),tmpPoint.y()));
      newIntNode->setSize(intnode->size()*_factor);
    }
  }

  for(LayoutNodePort const* port : _layoutGraph->allUsedPorts()) {
    LayoutNode* acNode = _layoutGraph->portParentNode(port->externUuid())->parentNode();
    if(acNode == nullptr){
      LayoutNode* newNode = _tempLayoutGraph->addNode();
      newNode->setUuid(port->uuid());
      newNode->setExternUuid(port->externUuid());
      newNode->setShape(Point);
      newNode->setLabel(port->label());
      QPointF tmpPoint(port->pos());
      tmpPoint += QPointF(port->size().width()/2,port->size().height()/2);
      tmpPoint = QPointF(tmpPoint.x(),-tmpPoint.y());
      newNode->setPos(tmpPoint);
      newNode->setSize(QSizeF(1,1));
    }else{
      LayoutNode* newNode = _tempLayoutGraph->nodeByExternUuid(acNode->externUuid())->addNode();
      newNode->setUuid(port->uuid());
      newNode->setExternUuid(port->externUuid());
      newNode->setShape(Point);
      newNode->setLabel(port->label());
      QPointF tmpPoint(port->pos());
      //tmpPoint -= QPointF(0,acNode->pos().y());
      tmpPoint += QPointF(port->size().width()/2,port->size().height()/2);
      tmpPoint = QPointF(tmpPoint.x(),-tmpPoint.y());
      newNode->setPos(tmpPoint);
      newNode->setSize(QSizeF(1,1));
    }
  }
  for(LayoutEdge* edge: _layoutGraph->edges()) {
    if(edge->sourcePort()==nullptr && edge->targetPort()==nullptr){
      LayoutEdge* newEdge = _tempLayoutGraph->addEdge(
                              _tempLayoutGraph->nodeByExternUuid(edge->source()->externUuid()),
                              _tempLayoutGraph->nodeByExternUuid(edge->target()->externUuid()));
      newEdge->setExternUuid(edge->externUuid());
      newEdge->setUuid(edge->uuid());
      newEdge->setLabel(edge->label());
    }else if(edge->sourcePort()==nullptr && edge->targetPort()!=nullptr){
      LayoutEdge* newEdge = _tempLayoutGraph->addEdge(
                              _tempLayoutGraph->nodeByExternUuid(edge->source()->externUuid()),
                              _tempLayoutGraph->nodeByExternUuid(edge->targetPort()->externUuid()));
      newEdge->setExternUuid(edge->externUuid());
      newEdge->setUuid(edge->uuid());
      newEdge->setLabel(edge->label());
    }else if(edge->sourcePort()!=nullptr && edge->targetPort()==nullptr){
      LayoutEdge* newEdge = _tempLayoutGraph->addEdge(
                              _tempLayoutGraph->nodeByExternUuid(edge->sourcePort()->externUuid()),
                              _tempLayoutGraph->nodeByExternUuid(edge->target()->externUuid()));
      newEdge->setExternUuid(edge->externUuid());
      newEdge->setUuid(edge->uuid());
      newEdge->setLabel(edge->label());
    }else if(edge->sourcePort()!=nullptr && edge->targetPort()!=nullptr){
      LayoutEdge* newEdge = _tempLayoutGraph->addEdge(
                              _tempLayoutGraph->nodeByExternUuid(edge->sourcePort()->externUuid()),
                              _tempLayoutGraph->nodeByExternUuid(edge->targetPort()->externUuid()));
      newEdge->setExternUuid(edge->externUuid());
      newEdge->setUuid(edge->uuid());
      newEdge->setLabel(edge->label());
    }
  }
}

bool ComCreateLayoutEdgesOnly::ComCreateLayoutEdgesOnlyPrivate::execute(QString* errorString, QString* graphvizLog)
{
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

  this->_tempLayoutGraph = new LayoutGraph("");

  graphToTmpgraph();

  QTemporaryFile tempGraphvizFile;
  //! tmpFileDebug
  tempGraphvizFile.setAutoRemove(false);

  if(!tempGraphvizFile.open())
  {
    *errorString+="Error: Temporary file '"
                  +tempGraphvizFile.fileName()
                  +"' for graphviz-input could not be created!\n";
    delete this->_tempLayoutGraph;
    return  false;
  }

  QTextStream graphvizStream(&tempGraphvizFile);
  ComCreateGraphvizFile createGraphvizFileCommand(this->_tempLayoutGraph);
  createGraphvizFileCommand.setFixed(true);
  createGraphvizFileCommand.execute(graphvizStream);
  tempGraphvizFile.close();

  QTemporaryFile tempGraphvizOutputFile;
  //! tmpFileDebug
  tempGraphvizOutputFile.setAutoRemove(false);

  if(!tempGraphvizOutputFile.open())
  {
    *errorString+="Error: Temporary file '"
                  +tempGraphvizOutputFile.fileName()
                  +"' for graphviz-ouput could not be created!\n";
    delete this->_tempLayoutGraph;
    return  false;
  }
  tempGraphvizOutputFile.close();

  QStringList arguments;
  arguments << "-s 1";
  arguments << "-Tdot" << tempGraphvizFile.fileName();
  arguments << "-o" << tempGraphvizOutputFile.fileName();

  QProcess graphvizProcess;
  graphvizProcess.start(graphvizProgram, arguments);
  if(!graphvizProcess.waitForFinished())
  {
    *errorString+="GraphvizProcessError:"+graphvizProcess.errorString();
    graphvizProcess.kill();
    delete this->_tempLayoutGraph;
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
    delete this->_tempLayoutGraph;
    return  false;
  }

  QString outputString=tempGraphvizOutputFile.readAll();
  tempGraphvizOutputFile.close();

  outputString = outputString.replace("STRICT","STRICTT",Qt::CaseSensitive);

  GraphvizGraph graphvizGraph;
  graphvizparser::ComCreateGraphvizGraph graphvizGraphCommand(outputString.toStdString(), _tempLayoutGraph);
  graphvizGraphCommand.execute(errorString);

  for(LayoutNode* node: _tempLayoutGraph->allNodes()){
    if(node->nodes().isEmpty()==true){
      if(node->shape()!=Point){
        node->setSize(node->size()/_factor);
        node->setPos(QPointF(node->pos().x()-node->size().width()/2,node->pos().y()-node->size().height()/2));
      }
    }else{
      node->setPos(node->pos()-QPointF(10,10));
      node->setSize(node->size()+QSizeF(20,10));
    }
  }

  QPointF minPoint(10,70);
  QPointF relDist(0,0);
  for(LayoutNode* node: _tempLayoutGraph->nodes()){
    if(node->pos().x()<minPoint.x()){
      if(minPoint.x()-node->pos().x()>relDist.x())
        relDist.setX(minPoint.x()-node->pos().x());
    }
    if(node->pos().y()<minPoint.y()){
      if(minPoint.y()-node->pos().y()>relDist.y())
        relDist.setY(minPoint.y()-node->pos().y());
    }
  }
  for(LayoutNode* node: _tempLayoutGraph->allNodes()){
    node->setPos(node->pos()+relDist);
    node->setLabelPos(node->labelPos()+relDist);
  }

  for(LayoutNode* node: _tempLayoutGraph->nodes()){
    ComCreateLayoutEdgesOnly::ComCreateLayoutEdgesOnlyPrivate::cluster(node);
  }

  for(LayoutEdge* edge: _tempLayoutGraph->edges()) {
    for(QPointF* point: edge->points()) {
      point->setX(point->x() + relDist.x());
      point->setY(point->y() + relDist.y());
    }
    edge->setLabelPos(edge->labelPos()+relDist);
  }
  QPointF fullSize(0,0);
  for(LayoutEdge* edge: _layoutGraph->edges()) {
    for(QPointF* point: edge->points()) {
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

  tmpgraphToGraph();

  delete this->_tempLayoutGraph;
  return true;
}

void ComCreateLayoutEdgesOnly::ComCreateLayoutEdgesOnlyPrivate::cluster(LayoutNode* layoutNode){
  for(LayoutNode* intnode: layoutNode->nodes()){
    ComCreateLayoutEdgesOnly::ComCreateLayoutEdgesOnlyPrivate::cluster(intnode);
    intnode->setPos(intnode->pos()-layoutNode->pos());
  }
}

ComCreateLayoutEdgesOnly::ComCreateLayoutEdgesOnly(LayoutGraph *layoutGraph,
                                                   GraphvizAlgorithm graphvizAlgorithm)
  : _d(new ComCreateLayoutEdgesOnlyPrivate(layoutGraph, graphvizAlgorithm, QDir()))
{}

ComCreateLayoutEdgesOnly::ComCreateLayoutEdgesOnly(LayoutGraph *layoutGraph,
                                                   GraphvizAlgorithm graphvizAlgorithm,
                                                   const QString &graphvizBinPath)
  : _d(new ComCreateLayoutEdgesOnlyPrivate(layoutGraph,
                                           graphvizAlgorithm,
                                           QDir(graphvizBinPath)))
{}

ComCreateLayoutEdgesOnly::ComCreateLayoutEdgesOnly(LayoutGraph *layoutGraph,
                                                   GraphvizAlgorithm graphvizAlgorithm,
                                                   const QDir& graphvizPath)
  : _d(new ComCreateLayoutEdgesOnlyPrivate(layoutGraph,
                                           graphvizAlgorithm,
                                           graphvizPath))
{}

ComCreateLayoutEdgesOnly::~ComCreateLayoutEdgesOnly()
{
  delete this->_d;
}



bool ComCreateLayoutEdgesOnly::execute(QString* errorString, QString *graphvizLog)
{
  return this->_d->execute(errorString, graphvizLog);
}
