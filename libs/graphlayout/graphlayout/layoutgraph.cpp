#include "layoutgraph.hpp"

#include <QtAlgorithms>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QTextStream>
#include <QFile>
#include <QString>

#include <stdexcept>

#include <mobata/memory_leak_start.hpp>

using namespace graphlayout;

class LayoutGraph::Private
{
  friend class LayoutGraph;

  QSizeF              _graphSize = QSizeF(0,0); ///<size of this layout-graph
  SplineEnum          _spline=line; ///<spline design of this layout-graph
  OverlapEnum         _overlap=default0; ///<overlap algorithm of this layout-graph
  QList<LayoutNode*>  _nodes;///<nodes of this layout-graph
  QList<LayoutEdge*>  _edges;///<edges of this layout-graph

  Private()
  {}
};

LayoutGraph::LayoutGraph(const QString &name, QObject *parent)
  :	QObject(parent), prop::NameProperty(name), _d(new Private())
{}

LayoutGraph::~LayoutGraph()
{
  this->clearGraph();
  delete this->_d;
}

void LayoutGraph::clearGraph()
{
  qDeleteAll(this->_d->_nodes);
  this->_d->_nodes.clear();
  qDeleteAll(this->_d->_edges);
  this->_d->_edges.clear();

  return;
}

QString LayoutGraph::splinesString() const
{
  switch (_d->_spline) {
    case 0:
      return "none";
    case 1:
      return "line";
    case 2:
      return "spline";
    case 3:
      return "ortho";
    case 4:
      return "polyline";
    case 5:
      return "curved";
    case 6:
      return "line";
    default:
      return "line";
  }
}

const SplineEnum& LayoutGraph::splines() const
{
  return  this->_d->_spline;
}

void LayoutGraph::setSplines(const SplineEnum& splines)
{
  this->_d->_spline=splines;
}

void LayoutGraph::setSplines(const QString& splines)
{
  if(splines == "none"){
    this->_d->_spline=SplineEnum::none;
  }else if(splines == "line"){
    this->_d->_spline=SplineEnum::line;
  }else if(splines == "spline"){
    this->_d->_spline=SplineEnum::spline;
  }else if(splines == "ortho"){
    this->_d->_spline=SplineEnum::ortho;
  }else if(splines == "polyline"){
    this->_d->_spline=SplineEnum::polyline;
  }else if(splines == "curved"){
    this->_d->_spline=SplineEnum::curved;
  }else if(splines == "straight"){
    this->_d->_spline=SplineEnum::straight;
  }
}

QString LayoutGraph::overlapString() const
{
  switch (_d->_overlap) {
    case 0:
      return "default";
    case 1:
      return "scale";
    case 2:
      return "prism";
    case 3:
      return "prism0";
    case 4:
      return "voronoi";
    case 5:
      return "vpsc";
    case 6:
      return "ortho";
    case 7:
      return "true";
    default:
      return "default";
  }
}
const OverlapEnum& LayoutGraph::overlap() const
{
  return this->_d->_overlap;
}
void LayoutGraph::setOverlap(const OverlapEnum& overlap)
{
  this->_d->_overlap=overlap;
}
void LayoutGraph::setOverlap(const QString& overlap)
{
  if(overlap == "default"){
    this->_d->_overlap=OverlapEnum::default0;
  }else if(overlap == "scale"){
    this->_d->_overlap=OverlapEnum::scale;
  }else if(overlap == "prism"){
    this->_d->_overlap=OverlapEnum::prism;
  }else if(overlap == "prism0"){
    this->_d->_overlap=OverlapEnum::prism0;
  }else if(overlap == "voronoi"){
    this->_d->_overlap=OverlapEnum::voronoi;
  }else if(overlap == "vpsc"){
    this->_d->_overlap=OverlapEnum::vpsc;
  }else if(overlap == "ortho"){
    this->_d->_overlap=OverlapEnum::orthoxy;
  }else if(overlap == "true"){
    this->_d->_overlap=OverlapEnum::allowed;
  }
}

void LayoutGraph::setGraphSize(const QSizeF size)
{
  this->_d->_graphSize.setHeight(size.height());
  this->_d->_graphSize.setWidth(size.width());
}

QSizeF LayoutGraph::graphSize() const
{
  return this->_d->_graphSize;
}

LayoutNode* LayoutGraph::addNode()
{
  LayoutNode* newLayoutNode=new LayoutNode();
  this->_d->_nodes.append(newLayoutNode);

  return newLayoutNode;
}

LayoutNode const* LayoutGraph::node(const QUuid& nodeUuid) const
{
  foreach(LayoutNode const* layoutNode, this->_d->_nodes)
    if(layoutNode->uuid() == nodeUuid){
      return layoutNode;
    }

  return 0;
}

int LayoutGraph::nodePos(const QUuid &nodeUuid) const
{
  std::size_t pos=0;
  foreach(LayoutNode const* layoutNode, this->_d->_nodes)
  {
    if(layoutNode->uuid()==nodeUuid)
      return (int)pos;
    ++pos;
  }

  return -1;
}

LayoutNode const* LayoutGraph::node(const std::size_t pos) const
{
  if(this->_d->_nodes.size()<=(int)pos)
    return 0;

  return this->_d->_nodes.at((int)pos);
}

const QList<LayoutNode*>& LayoutGraph::nodes() const
{
  return this->_d->_nodes;
}

QList<LayoutNode*> LayoutGraph::nodesFromList(QList<LayoutNode *> list) const
{
  QList<LayoutNode*> tmp;
  foreach(LayoutNode* node, list){
    tmp.append(node);
    if(node->nodes().isEmpty()==false){
      tmp.append(LayoutGraph::nodesFromList(node->nodes()));
    }
  }
  return tmp;
}

QList<LayoutNode*> LayoutGraph::allNodes() const
{
  return this->nodesFromList(this->_d->_nodes);
}

QList<LayoutNodePort*> LayoutGraph::allPorts() const
{
  QList<LayoutNodePort*> tmp;
  foreach (LayoutNode* node, this->allNodes()) {
    if(node->ports().isEmpty()==false){
      tmp.append(node->ports());
    }
  }
  return tmp;
}
QList<LayoutNodePort const*> LayoutGraph::allUsedPorts() const
{
  QList<LayoutNodePort const*> tmp;
  foreach (LayoutEdge* edge, this->_d->_edges){
    if(tmp.contains(edge->targetPort())==false && edge->targetPort()!=nullptr){
      tmp.append(edge->targetPort());
    }
    if(tmp.contains(edge->sourcePort())==false && edge->sourcePort()!=nullptr){
      tmp.append(edge->sourcePort());
    }
  }
  return tmp;
}
QList<LayoutNodePort const*> LayoutGraph::allUnusedPorts() const
{
  QList<LayoutNodePort const*> usedPorts = this->allUsedPorts();
  QList<LayoutNodePort const*> tmp;
  for(LayoutNodePort const* Port : this->allPorts()) {
    if(usedPorts.contains(Port)==false){
      tmp.append(Port);
    }
  }
  return tmp;
}
LayoutNode* LayoutGraph::portParentNode(QUuid portQUuid)
{
  foreach (LayoutNode* node, this->allNodes()) {
    if(node->ports().isEmpty()==false){
      foreach (LayoutNodePort* port, node->ports()) {
        if(port->externUuid()==portQUuid){
          return node;
        }
      }
    }
  }
  return nullptr;
}
LayoutNodePort* LayoutGraph::port(QUuid portUuid) {
  foreach (LayoutNodePort* port, allPorts()) {
    if(port->externUuid()==portUuid){
      return port;
    }
  }
  return nullptr;
}

LayoutNode* LayoutGraph::nodeByXLabel(QString xLabel)
{
  foreach (LayoutNode* node, this->allNodes()) {
    if(node->xLabel()==xLabel)
      return node;
  }
  return nullptr;
}
LayoutNode* LayoutGraph::nodeByLabel(QString Label)
{
  foreach (LayoutNode* node, this->allNodes()) {
    if(node->label()==Label)
      return node;
  }
  return nullptr;
}
LayoutNode* LayoutGraph::nodeByAnyLabel(QString Label)
{
  foreach (LayoutNode* node, this->allNodes()) {
    if(node->label()==Label || node->xLabel() == Label)
      return node;
  }
  return nullptr;
}

LayoutNode* LayoutGraph::nodeParentNode(QUuid nodeQUuid)
{
  foreach (LayoutNode* node, this->_d->_nodes) {
    if(node->uuid()==nodeQUuid || node->externUuid()==nodeQUuid)
      return nullptr;
  }
  foreach (LayoutNode* parentNode, this->allNodes()) {
    foreach (LayoutNode* node, parentNode->nodes()) {
      if(node->uuid()==nodeQUuid || node->externUuid()==nodeQUuid)
        return parentNode;
    }
  }
  return nullptr;
}

QList<LayoutEdge*> const LayoutGraph::edges() const
{
  return this->_d->_edges;
}

LayoutNode* LayoutGraph::nodeByExternUuid(const QUuid &nodeExternUuid)
{
  return this->nodeByExternUuidRec(nodeExternUuid,this->_d->_nodes);
}

LayoutNode *LayoutGraph::nodeByExternUuidRec(const QUuid &nodeExternUuid, QList<LayoutNode*> list)
{
  foreach (LayoutNode* node, list) {
    if(node->externUuid()==nodeExternUuid){
      return node;
    }
    if(node->nodes().length()!=0){
      LayoutNode* tmp = LayoutGraph::nodeByExternUuidRec(nodeExternUuid,node->nodes());
      if(tmp!=0){
        return tmp;
      }
    }
  }
  return nullptr;
}

LayoutNode* nodeByNameImpl(const QString& nodeName, const QList<LayoutNode*>& nodeList)
{
  for(LayoutNode* currNode : nodeList)
  {
    if(currNode->name() == nodeName)
      return currNode;

/* The following code was replaced by the method 'nodeByPath()' because the recursive getter implemented here will not always return the correct node.
 * Two or more nested nodes can have the same name. Therefore, a path definition is necesarry to retrieve the correct node*/
//    if(LayoutNode* subNode = nodeByNameImpl(nodeName, currNode->nodes()))
//      return subNode;
  }

  return nullptr;
}

LayoutNode* LayoutGraph::nodeByName(const QString& nodeName)
{
  return nodeByNameImpl(nodeName, this->_d->_nodes);
}

LayoutNode* LayoutGraph::nodeByPath(const QString& nodePath)
{
  QStringList nodePathList = nodePath.split(QStringLiteral("."));
  return nodeByPathImpl(nodePathList, this->_d->_nodes);
}

LayoutNode* LayoutGraph::nodeByPathImpl(const QStringList& nodePathList,
                                        const QList<LayoutNode*>& nodeList)
{
  for(QStringList::const_iterator it = nodePathList.cbegin(); it != nodePathList.cend(); it++){
    for(LayoutNode* currNode : nodeList)
    {
      if(currNode->name() == (*it)){
        if((*it) != nodePathList.back()){
          if(currNode->nodes().isEmpty())
            continue;
          QStringList localPathList = nodePathList;
          localPathList.pop_front();
          LayoutNode* nestedNode = nodeByPathImpl(localPathList,
                                                  currNode->nodes());
          if(nestedNode != nullptr)
            return nestedNode;
        }
        else
          return currNode;
      }
    }
  }

  return nullptr;
}

LayoutEdge* LayoutGraph::addEdge(LayoutNode const* source, LayoutNode const* target)
{
  if(!(source && target))
    return 0;

  LayoutEdge* newLayoutEdge=new LayoutEdge(source, target);
  this->_d->_edges.push_back(newLayoutEdge);

  return newLayoutEdge;
}

LayoutEdge const* LayoutGraph::edge(const std::size_t pos) const
{
  if(this->_d->_edges.size()<=(int)pos)
    return 0;

  return this->_d->_edges.at((int)pos);
}

LayoutEdge const* LayoutGraph::edge(const QUuid &edgeUuid) const
{
  foreach(LayoutEdge const* layoutEdge, this->_d->_edges)
    if(layoutEdge->uuid()==edgeUuid)
      return layoutEdge;

  return 0;
}
LayoutEdge* LayoutGraph::edgeByExternUuid(const QUuid& edgeUuid)
{
  foreach(LayoutEdge* layoutEdge, this->_d->_edges)
    if(layoutEdge->externUuid()==edgeUuid)
      return layoutEdge;

  return 0;
}

LayoutEdge* LayoutGraph::edgeByName(const QString& edgeName) const
{
  for(LayoutEdge* currLayoutEdge : this->_d->_edges)
  {
    if(currLayoutEdge->name() == edgeName)
      return currLayoutEdge;
  }

  return nullptr;
}

int LayoutGraph::edgePos(const QUuid &edgeUuid) const
{
  std::size_t pos=0;
  foreach(LayoutEdge * layoutEdge, this->_d->_edges)
  {
    if(layoutEdge->uuid()==edgeUuid)
      return (int)pos;
    ++pos;
  }

  return -1;
}

LayoutEdge const* LayoutGraph::edge(const QUuid &sourceUuid,
                                    const QUuid &targetUuid)
{
  foreach(LayoutEdge const* edge, this->_d->_edges)
    if(edge->source()->uuid()==sourceUuid
       && edge->target()->uuid()==targetUuid)
      return edge;

  return 0;
}

LayoutEdge const* LayoutGraph::edgeByExternNodeUuid(const QUuid &sourceExternUuid,
                                                    const QUuid &targetExternUuid)
{
  foreach(LayoutEdge const* edge, this->_d->_edges)
    if(edge->source()->externUuid()==sourceExternUuid
       && edge->target()->externUuid()==targetExternUuid)
      return edge;

  return 0;
}
const QPointF LayoutGraph::UuidToGlobalPos(QUuid uuid)
{
  QPointF pos(0,0);
  LayoutNode* node = this->nodeByExternUuid(uuid);
  if(node==nullptr){
    LayoutNodePort* port = this->port(uuid);
    if(port==nullptr){
      return QPointF(0,0);
    }else{
      pos = port->pos();
      node = this->portParentNode(uuid);
    }
  }else{
    pos = node->pos();
  }


  while (node->parentNode()!=nullptr) {
    pos += node->parentNode()->pos();
    node = node->parentNode();
  }
  return pos;
}

/*
void LayoutGraph::save(const QString& path)
{
  LayoutGraph* layoutGraph = this;
  if(!layoutGraph || path.isEmpty())
    return;

  QJsonObject json_graph;
  json_graph.insert(QStringLiteral("name"), layoutGraph->name());

  //////nodes//////////////////
  QJsonArray json_graph_nodes;
  foreach(LayoutNode const* node, layoutGraph->nodes())
  {
    QJsonObject json_node;

    json_node.insert(QStringLiteral("uuid"),node->uuid().toString());
    json_node.insert(QStringLiteral("extern_uuid"), node->externUuid().toString());

    QJsonObject json_node_pos;
    json_node_pos.insert(QStringLiteral("x"), node->pos().x());
    json_node_pos.insert(QStringLiteral("y"), node->pos().y());
    json_node.insert(QStringLiteral("pos"), json_node_pos);

    QJsonObject json_node_size;
    json_node_size.insert(QStringLiteral("width"), node->size().width());
    json_node_size.insert(QStringLiteral("height"), node->size().height());
    json_node.insert(QStringLiteral("size"), json_node_size);

    json_graph_nodes.push_back(json_node);
  }
  json_graph.insert(QStringLiteral("nodes"), json_graph_nodes);

  //////edges//////////////////
  QJsonArray json_graph_edges;
  foreach(LayoutEdge const* edge, layoutGraph->edges())
  {
    QJsonObject json_edge;

    json_edge.insert(QStringLiteral("source_uuid"),edge->source()->uuid().toString());
    json_edge.insert(QStringLiteral("target_uuid"),edge->target()->uuid().toString());

    QJsonArray json_edge_points;
    foreach(const QPointF& point, edge->getPoints())
    {
      QJsonObject json_point;
      json_point.insert(QStringLiteral("x"), point.x());
      json_point.insert(QStringLiteral("y"), point.y());
      json_edge_points.push_back(json_point);
    }
    json_edge.insert(QStringLiteral("control_points"), json_edge_points);

    json_graph_edges.push_back(json_edge);
  }
  json_graph.insert(QStringLiteral("edges"), json_graph_edges);

  QJsonDocument jsonDocument(json_graph);
  QFile outputFile(path);
  if(outputFile.open(QFile::WriteOnly))
  {
    QTextStream outputStream(&outputFile);
    outputStream<<jsonDocument.toJson();
    outputFile.close();
  }

  return;
}

inline
void readPos(const QJsonObject& posObject,
             QPointF* pos)
{
  Q_ASSERT(pos);

  QJsonObject::ConstIterator posIt=posObject.constBegin();
  QJsonObject::ConstIterator posEndIt=posObject.constEnd();

  for( ; posIt!=posEndIt; ++posIt)
  {
    if(posIt.key()==QStringLiteral("x"))
      pos->setX(posIt.value().toDouble());
    else if(posIt.key()==QStringLiteral("y"))
      pos->setY(posIt.value().toDouble());
  }

  return;
}

inline
void read_nodes(LayoutGraph* layoutGraph, const QJsonArray& nodesArray)
{
  if(!layoutGraph)
    return;

  foreach(const QJsonValue& nodeValue, nodesArray)
  {
    QJsonObject nodeObject=nodeValue.toObject();

    LayoutNode* newLayoutNode=layoutGraph->addNode();

    QJsonObject::ConstIterator objIt=nodeObject.constBegin();
    QJsonObject::ConstIterator endIt=nodeObject.constEnd();

    for( ; objIt!=endIt; ++objIt)
    {
      if(objIt.key()==QStringLiteral("uuid"))
        newLayoutNode->setUuid(QUuid(objIt.value().toString()));
      else if(objIt.key()==QStringLiteral("extern_uuid"))
        newLayoutNode->setExternUuid(QUuid(objIt.value().toString()));
      else if(objIt.key()==QStringLiteral("pos"))
      {
        QPointF pos;
        readPos(objIt.value().toObject(), &pos);
        newLayoutNode->setPos(pos);
      }
      else if(objIt.key()==QStringLiteral("size"))
      {
        QJsonObject sizeObject=objIt.value().toObject();
        QSizeF size;

        QJsonObject::ConstIterator sizeIt=sizeObject.constBegin();
        QJsonObject::ConstIterator sizeEndIt=sizeObject.constEnd();
        for( ; sizeIt!=sizeEndIt; ++sizeIt)
        {
          if(sizeIt.key()==QLatin1String("width"))
            size.setWidth(sizeIt.value().toDouble());
          else if(sizeIt.key()==QLatin1String("height"))
            size.setHeight(sizeIt.value().toDouble());
        }
        newLayoutNode->setSize(size);
      }
    }
  }

  return;
}

inline
void read_edges(LayoutGraph* layoutGraph, const QJsonArray& edgesArray)
{
  if(!layoutGraph)
    return;

  foreach(const QJsonValue& edgeValue, edgesArray)
  {
    QJsonObject edgeObject=edgeValue.toObject();

    LayoutNode const* sourceNode=0, *targetNode=0;
    LayoutEdge* newLayoutEdge=0;

    QJsonObject::const_iterator find_it;

    ///read source////
    find_it=edgeObject.find(QStringLiteral("source_uuid"));
    if(find_it!=edgeObject.end())
    {
      QUuid nodeUuid(find_it.value().toString());
      sourceNode=layoutGraph->getNode(nodeUuid);
      if(!sourceNode)
        throw std::runtime_error(QObject::tr("source graph node with uuid :'%1' not found.")
                                 .arg(nodeUuid.toString()).toStdString());
    }

    ///read target////
    find_it=edgeObject.find(QStringLiteral("target_uuid"));
    if(find_it!=edgeObject.end())
    {
      QUuid nodeUuid(find_it.value().toString());
      targetNode=layoutGraph->getNode(nodeUuid);
      if(!targetNode)
        throw std::runtime_error(QObject::tr("target graph node with uuid :'%1' not found.")
                                 .arg(nodeUuid.toString()).toStdString());
    }

    newLayoutEdge=layoutGraph->addEdge(sourceNode, targetNode);
    Q_ASSERT(newLayoutEdge);

    ///read control-points////
    find_it=edgeObject.find(QStringLiteral("control_points"));
    if(find_it!=edgeObject.end())
    {
      foreach(const QJsonValue& pointValue, find_it.value().toArray())
      {
        QPointF point;
        readPos(pointValue.toObject(), &point);
        newLayoutEdge->addPoint(point);
      }
    }
  }

  return;
}

inline
void read(LayoutGraph* layoutGraph, const QString& path)
{
  if(!layoutGraph)
    return;

  QFile layoutGraphFile(path);
  if(!layoutGraphFile.open(QFile::ReadOnly))
    throw std::runtime_error(QObject::tr("file '%1' could not be opened!")
                             .arg(path).toStdString());

  QJsonParseError parseError;
  QJsonDocument jsonDocument=QJsonDocument::fromJson(layoutGraphFile.readAll(),
                                                     &parseError);
  layoutGraphFile.close();

  if(parseError.error!=QJsonParseError::NoError)
    throw std::runtime_error(QObject::tr("Parser error: %1")
                             .arg(parseError.errorString())
                             .toStdString());

  if(jsonDocument.isArray()
     || jsonDocument.isEmpty()
     || jsonDocument.isNull())
    throw std::runtime_error(QObject::tr("layout graph json file should be an object!")
                             .toStdString());

  QJsonObject rootObject=jsonDocument.object();

  QJsonObject::const_iterator find_it;

  ///read name////
  find_it=rootObject.find(QStringLiteral("name"));
  if(find_it!=rootObject.end())
    layoutGraph->setName(find_it.value().toString());

  ///read nodes/////////
  find_it=rootObject.find(QStringLiteral("nodes"));
  if(find_it!=rootObject.end())
    read_nodes(layoutGraph, find_it.value().toArray());

  ///read edges/////////
  find_it=rootObject.find(QStringLiteral("edges"));
  if(find_it!=rootObject.end())
    read_edges(layoutGraph, find_it.value().toArray());

  return;
}
*/
