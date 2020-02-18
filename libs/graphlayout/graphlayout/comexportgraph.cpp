#include "comexportgraph.hpp"
using namespace graphlayout;

class ComExportGraph::Private{
  friend class ComExportGraph;
  //! Generate Settings
  LayoutGraph const*  _layoutGraph = nullptr;
  QString*            _graphString = nullptr;
  bool                _withEdgeLabels = true;
  QColor              _backgroundColor = QColor("white");

  int nodeCounter;
  int clusterCounter;
  QHash<LayoutNode*, QString> _clusterList;
  QHash<LayoutNode*, QString> _nodeList;

  Private(LayoutGraph const* layoutGraph,
          QString *graphString)
    : _layoutGraph(layoutGraph),
      _graphString(graphString)
  {}
};

ComExportGraph::ComExportGraph(LayoutGraph const* layoutGraph,
                               QString *graphString)
  :_d(new Private(layoutGraph, graphString))
{
  Q_ASSERT(this->_d->_layoutGraph);
}

ComExportGraph::~ComExportGraph()
{
  delete this->_d;
}

bool ComExportGraph::execute(QString* errorString)
{
  Q_ASSERT(this->_d->_layoutGraph);

  utils::AddPtrString(this->_d->_graphString) << "digraph layoutGraph{"<<"\n";
  utils::AddPtrString(this->_d->_graphString) << "rankdir=\"TB\";" << "\n";
  utils::AddPtrString(this->_d->_graphString) << "compound = \"true\";" << "\n";
  utils::AddPtrString(this->_d->_graphString) << "forcelabels = true;" << "\n";
  utils::AddPtrString(this->_d->_graphString) << "sep = \"+50\";" << "\n";
  utils::AddPtrString(this->_d->_graphString) << "esep = \"+70\";" << "\n";
  utils::AddPtrString(this->_d->_graphString) << "splines = \""<< _d->_layoutGraph->splinesString() << "\";" << "\n";

  utils::AddPtrString(this->_d->_graphString) << "\n";

  for(LayoutNode* node : this->_d->_layoutGraph->nodes()){
    bool result = this->addNode(node);
    if(result == false){
      qDebug()<<node<<" failed";
      return false;
    }
  }

  utils::AddPtrString(this->_d->_graphString) << "\n";

  for(LayoutEdge* edge : this->_d->_layoutGraph->edges()){
    bool result = this->addEdge(edge, errorString);
    if(result == false){
      qDebug()<<edge<<" failed";
      return false;
    }
  }
  utils::AddPtrString(this->_d->_graphString) << "\n";
  utils::AddPtrString(this->_d->_graphString) << "}\n";

  return true;
}

bool ComExportGraph::addNode(LayoutNode* node){
  if(node->nodes().isEmpty() == false){
    QString node_string="subgraph ";
    QString graphvizNodeName="cluster"+QString("%1").arg(this->_d->clusterCounter++);
    this->_d->_clusterList.insert(node, graphvizNodeName);
    this->_d->_nodeList.insert(node, graphvizNodeName);

    node_string += graphvizNodeName;
    node_string += "{";

    ///label//////////////
    QString label=node->label();
    label.replace("\\", "\\\\");
    label.replace("\"","\\\"");
    label=label.trimmed();

    node_string += "label=\""+label+"\"\n";
    node_string += "style=\"filled\"\n";
    node_string += "fillcolor=\""+this->colorToHtml(node->color())+"\"\n";
    node_string += "color=\""+this->colorToHtml(node->borderColor())+"\"\n";
    node_string += "penwidth=\""+QString::number(node->borderWidth())+"\"\n";
    node_string += "fontcolor=\""+this->colorToHtml(node->labelColor())+"\"\n";

    utils::AddPtrString(this->_d->_graphString) << node_string;

    for(LayoutNode* intnode : node->nodes()){
      this->addNode(intnode);
    }
    utils::AddPtrString(this->_d->_graphString) << "};\n";
  }else{
    QString node_string = "";
    QString graphvizNodeName="n"+QString("%1").arg(this->_d->nodeCounter++);
    this->_d->_nodeList.insert(node, graphvizNodeName);
    node_string += graphvizNodeName;
    node_string += "[";
    node_string += "shape=";
    if(node->shape()==RoundedRect)
      node_string += "rect, style=rounded";
    else
      node_string += ShapeEnumToString(node->shape());

    QString label=node->xLabel();
    label.replace("\\","\\\\");
    label.replace("\"","\\\"");
    label=label.trimmed();
    if(!label.isEmpty())
    {
      if(node->token()==false){
        node_string += ", label=\""+label+"\"";
      }else{
        node_string += ", label=\"■\\n"+label+"\"";
      }
    }

    QString xlabel=node->label();
    xlabel.replace("\\","\\\\");
    xlabel.replace("\"","\\\"");
    xlabel=xlabel.trimmed();
    if(!xlabel.isEmpty())
      node_string += ", xlabel=\""+xlabel+"\"";

    node_string += ", style=\"filled\"";
    node_string += ", penwidth=\"" + QString::number(node->borderWidth()) + "\"";
    node_string += ", color=\"" + this->colorToHtml(node->borderColor()) + "\"";
    node_string += ", fillcolor=\"" + this->colorToHtml(node->color()) + "\"";
    node_string += ", fontcolor=\"" + this->colorToHtml(node->labelColor()) + "\"";
    node_string += ", fontsize=" + QString::number(node->labelTextSize());
    node_string += "];\n";

    utils::AddPtrString(this->_d->_graphString)<<node_string;
  }
  return true;
}

bool ComExportGraph::addEdge(LayoutEdge* edge, QString* errorString){
  LayoutNode* sourceCluster = nullptr;
  LayoutNode* sourceNode=const_cast<LayoutNode*>(edge->source());
  if(sourceNode->nodes().isEmpty()==false){
    sourceCluster = sourceNode;
    sourceNode = sourceCluster->nodes().last();
    if(sourceNode->nodes().isEmpty()==false){
      sourceNode = sourceCluster->firstSimpleNode(false);
      if(sourceNode==nullptr){
        utils::AddPtrString(errorString)<<"sourceNode error";
        return false;
      }
    }
  }

  LayoutNode* targetCluster = nullptr;
  LayoutNode* targetNode=const_cast<LayoutNode*>(edge->target());
  if(targetNode->nodes().isEmpty()==false){
    targetCluster = targetNode;
    targetNode = targetCluster->firstSimpleNode(true);
    if(targetNode==nullptr){
      targetNode = targetCluster->firstSimpleNode(false);
      if(targetNode==nullptr){
        utils::AddPtrString(errorString)<<"targetNode error";
        return false;
      }
    }
  }

  QString sourceNodeName=this->_d->_nodeList.value(sourceNode);
  QString targetNodeName=this->_d->_nodeList.value(targetNode);

  if(sourceNodeName == "" || targetNodeName == ""){
    utils::AddPtrString(errorString)<<"source/target error";
    return false;
  }

  QString edge_string = "";
  edge_string += sourceNodeName + " -> " + targetNodeName;
  int edgePos=this->_d->_layoutGraph->edgePos(edge->uuid());
  Q_ASSERT(edgePos>=0);

  QString label = edge->label();
  label.replace("\\","\\\\");
  label.replace("\n","\\n");
  label.replace("\"","\\\"");

  QString edgeLabel = "";
  if(this->_d->_withEdgeLabels == true){
    edgeLabel=label;
  }
  edge_string += "[label = \"" + edgeLabel + "\"";
  edge_string += ", fontsize=" + QString::number(edge->labelTextSize());

  if(sourceCluster!=nullptr){
    edge_string += ",ltail=" + this->_d->_clusterList.value(sourceCluster);
  }
  if(targetCluster!=nullptr){
    edge_string += ",lhead=" + this->_d->_clusterList.value(targetCluster);
  }
  edge_string += ",color=\"" + this->colorToHtml(edge->color()) + "\"";
  edge_string += ",fontcolor=\"" + this->colorToHtml(edge->labelColor()) + "\"";

  edge_string += "];\n";
  utils::AddPtrString(this->_d->_graphString)<<edge_string;
  return true;
}

void ComExportGraph::setWithEdgeLabels(const bool withEdgeLabels)
{
  this->_d->_withEdgeLabels = withEdgeLabels;
  return;
}

QString ComExportGraph::colorToHtml(const QColor& color)
{
  QString colorString = "#" +
      QString("%1").arg(color.red(), 2, 16, QLatin1Char('0')) +
      QString("%1").arg(color.green(), 2, 16, QLatin1Char('0')) +
      QString("%1").arg(color.blue(), 2, 16, QLatin1Char('0'));
  return colorString;
}
