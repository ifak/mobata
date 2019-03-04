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

#include "comcreategraphvizfile.hpp"

#include "layoutnode.hpp"
#include "layoutedge.hpp"

#include <QDebug>
#include <fstream>
#include <QHash>

namespace graphlayout{

typedef QHash<LayoutNode*, QString>	GraphvizNodes;

class ComCreateGraphvizFile::Private
{
  friend class ComCreateGraphvizFile;

public:
  Private(LayoutGraph const* layoutGraph):_layoutGraph(layoutGraph)
  {}

private:
  LayoutGraph const*  _layoutGraph;
  GraphvizNodes       _graphvizNodes;
  GraphvizAlgorithm   _algorithm = Dot;
  int nodeCounter;
  int clusterCounter;
  bool fixed = false;
  QHash<LayoutNode*, QString> _clusterList;
};


ComCreateGraphvizFile::ComCreateGraphvizFile(LayoutGraph const* layoutGraph)
  :	_d(new Private(layoutGraph))
{}

ComCreateGraphvizFile::~ComCreateGraphvizFile()
{
  delete this->_d;
}
void ComCreateGraphvizFile::setFixed(bool wert){
  this->_d->fixed=wert;
}
void ComCreateGraphvizFile::setAlgorithm(GraphvizAlgorithm algorithm){
  this->_d->_algorithm=algorithm;
}

void ComCreateGraphvizFile::nodes(QList<LayoutNode*> list, QTextStream& graphvizFileStream){
  for(LayoutNode* layoutNode: list){
    if(layoutNode->nodes().isEmpty()==false){
      QString node_string="subgraph ";
      this->_d->_clusterList.insert(layoutNode,"cluster"+QString("%1").arg(this->_d->clusterCounter));
      QString graphvizNodeName="cluster"+QString("%1").arg(this->_d->clusterCounter++);
      this->_d->_graphvizNodes.insert(layoutNode, graphvizNodeName);

      node_string += graphvizNodeName;
      node_string += "{";

      ///label//////////////
      QString label=layoutNode->label();
      label.replace(QStringLiteral("\n"), QStringLiteral("\\n"));
      label=label.trimmed();
      if(!label.isEmpty())
      {
        if(node_string.at(node_string.size()-1)!='{')
          node_string += ", ";
        node_string += "label=\""+label+"\"";
      }

      node_string+="\n";

      graphvizFileStream << node_string;

      nodes(layoutNode->nodes(), graphvizFileStream);

      graphvizFileStream << "};\n";

    }else{
      QString node_string="";

      QString graphvizNodeName="n"+QString("%1").arg(this->_d->nodeCounter++);
      this->_d->_graphvizNodes.insert(layoutNode, graphvizNodeName);

      node_string += graphvizNodeName;
      node_string += "[";
      node_string += "shape=";
      ///////shape///////////////

      if(layoutNode->shape()==RoundedRect)
        node_string += "rect, style=rounded";
      else
        node_string += ShapeEnumToString(layoutNode->shape());

      ///label (centered)//////////////
      QString label=layoutNode->xLabel();
      label.replace(QStringLiteral("\n"), QStringLiteral("\\n"));
      label.replace("\""," ");
      label.replace(","," ");
      label.replace("["," ");
      label.replace("]"," ");
      label.replace("{"," ");
      label=label.trimmed();
      if(!label.isEmpty())
      {
        if(node_string.at(node_string.size()-1)!='[')
          node_string += ", ";
        node_string += "label=\""+label+"\"";
      }

      ///xlabel (flying)/////////////
      if(layoutNode->staticLabels()==false){
        QString xlabel=layoutNode->label();
        xlabel.replace(QStringLiteral("\n"), QStringLiteral("\\n"));
        xlabel.replace("\"","");
        xlabel.replace(",","");
        xlabel.replace("[","");
        xlabel.replace("]","");
        xlabel.replace("{","");
        xlabel=xlabel.trimmed();
        if(!xlabel.isEmpty())
        {
          if(node_string.at(node_string.size()-1)!='[')
            node_string += ", ";
          node_string += "xlabel=\""+xlabel+"\"";
        }
      }
      ///fixed pos and size/////////////
      if(this->_d->fixed==true){
        if(node_string.at(node_string.size()-1)!='[')
          node_string += ", ";
        node_string += "pos=\"" +
            QString::number(layoutNode->pos().x()/72) + "," +
            QString::number(layoutNode->pos().y()/72) + "!\"";
        if(layoutNode->shape() != Point){
          if(node_string.at(node_string.size()-1)!='[')
            node_string += ", ";
          node_string += "width=\"" + QString::number(layoutNode->size().width()/72) + "\",";
          node_string += "height=\"" + QString::number(layoutNode->size().height()/72) + "\"";
        }
      }else if(layoutNode->fixedPos()==true){
        if(node_string.at(node_string.size()-1)!='[')
          node_string += ", ";
        node_string += "pos=\"" +
            QString::number(layoutNode->pos().x()/72) + "," +
            QString::number(layoutNode->pos().y()/72) + "!\"";
        if(layoutNode->shape() != Point){
          if(node_string.at(node_string.size()-1)!='[')
            node_string += ", ";
          node_string += "width=\"" + QString::number(layoutNode->size().width()/72) + "\",";
          node_string += "height=\"" + QString::number(layoutNode->size().height()/72) + "\"";
        }
      }
      ///all the rest/////////
      if(node_string.at(node_string.size()-1)!='[')
        node_string += ", ";
      if(layoutNode->xLabel()!=""){
        node_string += "fontsize=" + QString::number(layoutNode->xLabelTextSize()+1);
      }else{
        node_string += "fontsize=" + QString::number(layoutNode->labelTextSize()+1);
      }
      node_string += "];\n";

      graphvizFileStream << node_string;
    }
  }
  return;
}

void ComCreateGraphvizFile::execute(QTextStream& graphvizFileStream)
{
  if(!this->_d->_layoutGraph)
    return;

  this->_d->nodeCounter=0;
  this->_d->clusterCounter=0;

  graphvizFileStream << "digraph layoutGraph{"<<"\n";
  graphvizFileStream << "rankdir=\"TB\";" << "\n";
  graphvizFileStream << "compound = \"true\";" << "\n";
  graphvizFileStream << "forcelabels = true;" << "\n";
  if(this->_d->fixed==true){
    graphvizFileStream << "sep = 0;" << "\n";
    graphvizFileStream << "esep = \"+10\";" << "\n";
    graphvizFileStream << "fixedsize = true;" << "\n";
    graphvizFileStream << "pin = true;" << "\n";
  }else{
    graphvizFileStream << "sep = \"+50\";" << "\n";
    graphvizFileStream << "esep = \"+70\";" << "\n";
  }
  if(_d->_layoutGraph->overlapString()!="default"){
    graphvizFileStream << "overlap = \""<< _d->_layoutGraph->overlapString() << "\";" << "\n";
  }
  graphvizFileStream << "splines = \""<< _d->_layoutGraph->splinesString() << "\";" << "\n";

  ComCreateGraphvizFile::nodes(this->_d->_layoutGraph->nodes(), graphvizFileStream);

  graphvizFileStream << QStringLiteral("\n");

  for(LayoutEdge* layoutEdge: this->_d->_layoutGraph->edges())
  {
    LayoutNode* sourceCluster = nullptr;
    LayoutNode* sourceNode=const_cast<LayoutNode*>(layoutEdge->source());
    if(sourceNode->nodes().isEmpty()==false){
      sourceCluster = sourceNode;
      sourceNode = sourceCluster->nodes().last();
      if(sourceNode->nodes().isEmpty()==false){
        sourceNode = sourceCluster->firstSimpleNode(false);
        if(sourceNode==nullptr){
          continue;
        }
      }
    }

    LayoutNode* targetCluster = nullptr;
    LayoutNode* targetNode=const_cast<LayoutNode*>(layoutEdge->target());
    if(targetNode->nodes().isEmpty()==false){
      targetCluster = targetNode;
      targetNode = targetCluster->firstSimpleNode(true);
      if(targetNode==nullptr){
        targetNode = targetCluster->firstSimpleNode(false);
        if(targetNode==nullptr){
          continue;
        }
      }
    }

    QString sourceNodeName=this->_d->_graphvizNodes.value(sourceNode);
    QString targetNodeName=this->_d->_graphvizNodes.value(targetNode);

    Q_ASSERT(!sourceNodeName.isEmpty() && !targetNodeName.isEmpty());


    graphvizFileStream << sourceNodeName << " -> " << targetNodeName;
    int edgePos=this->_d->_layoutGraph->edgePos(layoutEdge->uuid());
    Q_ASSERT(edgePos>=0);

    QString label = "";
    if(layoutEdge->staticLabel()==false)
      label += layoutEdge->label();
    label.replace("\"","");
    label.replace(",","");
    label.replace("[","");
    label.replace("]","");
    label.replace("{","");
    label.replace("\n","\\n");


    QString edgeLabel=QString("%1").arg(edgePos)+QStringLiteral(" ")+label+QStringLiteral(" ");
    graphvizFileStream << QStringLiteral("[label = \"") << edgeLabel << QStringLiteral("\"");
    graphvizFileStream << QStringLiteral(", fontsize=")<< QString::number(layoutEdge->labelTextSize() + 1);
    if(this->_d->_algorithm==Dot){
      if(sourceCluster!=nullptr){
        graphvizFileStream << ",ltail=" << this->_d->_clusterList.value(sourceCluster);
      }
      if(targetCluster!=nullptr){
        graphvizFileStream << ",lhead=" << this->_d->_clusterList.value(targetCluster);
      }
      if(layoutEdge->constraint()==true){
      }else{
        graphvizFileStream << QStringLiteral(", constraint=false");
      }
      if(layoutEdge->weight() == -1){
      }else{
        graphvizFileStream << QStringLiteral(", weight=") << QString::number(layoutEdge->weight());
      }
      if(layoutEdge->minLen() == -1){
      }else{
        graphvizFileStream << QStringLiteral(", minlen=\"") << QString::number(layoutEdge->minLen()) << "\"";
      }
      if(layoutEdge->rank() == ""){
      }else{
        graphvizFileStream << QStringLiteral(", rank=") << layoutEdge->rank();
      }
    }
    graphvizFileStream << QStringLiteral("];\n");
  }

  graphvizFileStream << QStringLiteral("}")<<QStringLiteral("\n");

  return;
}

LayoutNode* ComCreateGraphvizFile::layoutNode(const QString &graphvizNodeName) const
{
  return this->_d->_graphvizNodes.key(graphvizNodeName, 0);
}

QString const* ComCreateGraphvizFile::graphvizNodeName(LayoutNode* layoutNode) const
{
  if(this->_d->_graphvizNodes.contains(layoutNode))
    return &this->_d->_graphvizNodes[layoutNode];

  return 0;
}

}//end namespace graphlayout
