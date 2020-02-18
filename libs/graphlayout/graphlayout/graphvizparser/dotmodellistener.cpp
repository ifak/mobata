#include "dotmodellistener.h"

#include "layoutnode.hpp"
#include "layoutedge.hpp"

#include <QDebug>

DotModelListener::DotModelListener()
{
}
void DotModelListener::setGraph(graphlayout::LayoutGraph* graph){
  _graph=graph;
}

void DotModelListener::enterSubgraph(DOTParser::SubgraphContext *ctx) {
  if(_graph==nullptr){
    qDebug()<<"no graph set for DotModelListener";
    return;
  }
  QString input = QString::fromStdString(ctx->getText());
  //!remove additional nodes and subgraphs from string
  if (input.contains(";")){
    input = input.split(";").first();
  }
  input = input.replace('\"',"");
  input = input.replace('}',"");

  if (input.contains("{")==false){
    return;
  }
  QStringList tmplist = input.split("{");
  QString tmp = tmplist.first();
  tmp = tmp.replace("subgraphcluster","");
  int subgraphNumber = tmp.toInt();

  //select node
  int nodeCounter = 0;
  graphlayout::LayoutNode* actualNode=nullptr;
  foreach (graphlayout::LayoutNode* node, _graph->allNodes()) {
    if(node->nodes().isEmpty()==false){
      if(nodeCounter==subgraphNumber){
        actualNode=node;
      }
      nodeCounter++;
    }
  }
  if(actualNode==nullptr){
    qDebug()<<"no node found";
    return;
  }
  //add data

  tmp = tmplist[1];
  tmp = tmp.replace("graph","");
  tmp = tmp.replace("[","");
  tmp = tmp.replace("]","");
  tmplist=tmp.split(",");

  foreach (QString line, tmplist) {
    if(line.split("=").first()=="bb"){
      if(line.split("=").length()>=2){
        int lineIndex = tmplist.indexOf(line);
        tmp = line.split("=")[1];
        float number = tmp.toFloat();
        actualNode->setPos(QPointF(number,-tmplist[lineIndex+1].toFloat()));
        actualNode->setSize(QSizeF(tmplist[lineIndex+2].toFloat()-number,tmplist[lineIndex+3].toFloat()-tmplist[lineIndex+1].toFloat()));
        actualNode->setPos(QPointF(actualNode->pos().x(), actualNode->pos().y()-actualNode->size().height()));
      }
    }

    if(line.split("=").first()=="lp"){
      int lineIndex = tmplist.indexOf(line);
      if(line.split("=").length()==2){
        actualNode->setLabelPos(QPointF(line.split("=")[1].toFloat(),-tmplist[lineIndex+1].toFloat()));
      }
    }

    if(line.split("=").first()=="lheight"){
      if(line.split("=").length()==2){
        tmp = line.split("=")[1];
        actualNode->setLabelTextSize(tmp.toFloat()*100);
      }
    }
  }
}
void DotModelListener::enterNode_stmt(DOTParser::Node_stmtContext *ctx) {
  //return if no graph is set
  if(_graph==nullptr){
    qDebug()<<"no graph set for DotModelListener";
    return;
  }
  QString input = QString::fromStdString(ctx->getText());
  //select node
  QString tmp = input.split("[").first();
  tmp = tmp.right(tmp.length()-1);
  int nodeNumber = tmp.toInt();
  int nodeCounter = 0;
  graphlayout::LayoutNode* actualNode=nullptr;
  foreach (graphlayout::LayoutNode* node, _graph->allNodes()) {
    if(node->nodes().isEmpty()==true){
      if(nodeCounter==nodeNumber){
        actualNode=node;
      }
      nodeCounter++;
    }
  }
  if(actualNode==nullptr){
    return;
  }
  //format data
  input = input.replace("]","");
  QStringList tmplist = input.split("[");
  if(tmplist.length()>=2){
    tmp="";
    for(int i=1;i<tmplist.length();i++){
      tmp=tmp + tmplist[i];
    }
  }else{
    return;
  }
  tmp = tmp.replace('\"',"");
  //write data to graph
  QStringList attr = tmp.split(",");
  foreach (QString line, attr) {
    tmplist = line.split("=");
    if(tmplist.length()<=2){
      if(tmplist.first()=="height"){
        float number = tmplist[1].toFloat();
        actualNode->setSize(QSizeF(actualNode->size().width(),number*_pixperinch));
      }
      if(tmplist.first()=="width"){
        float number = tmplist[1].toFloat();
        actualNode->setSize(QSizeF(number*_pixperinch,actualNode->size().height()));
      }
      if(tmplist.first()=="pos"){
        float number = tmplist[1].toFloat();
        actualNode->setPos(QPointF(number, actualNode->pos().y()));
        int index = attr.indexOf(line);
        number = attr[index+1].toFloat();
        actualNode->setPos(QPointF(actualNode->pos().x(),-number));
      }
      if(tmplist.first()=="xlp"){
        float number = tmplist[1].toFloat();
        actualNode->setLabelPos(QPointF(number, actualNode->labelPos().y()));
        int index = attr.indexOf(line);
        number = attr[index+1].toFloat();
        actualNode->setLabelPos(QPointF(actualNode->labelPos().x(),-number));
      }
    }
  }
}
void DotModelListener::enterEdge_stmt(DOTParser::Edge_stmtContext *ctx) {
  if(_graph==nullptr){
    qDebug()<<"no graph set for DotModelListener";
    return;
  }
  graphlayout::LayoutEdge* actualEdge=nullptr;
  int edgeNumber=-1;
  //format data
  QString input = QString::fromStdString(ctx->getText());

  input = input.replace('\n',"");
  input = input.replace('\r',"");
  input = input.replace('\\',"");
  input = input.replace('\"',"");
  input.replace("]","");
  input.replace("[",",");

  QStringList tmplist  = input.split(",");
  foreach (QString line, tmplist) {
    if(line.split("=").first()=="label"){
      if(line.split("=").length()>=2){
        QString tmp = line.split("=")[1];
        tmp = tmp.split(" ")[0];
        edgeNumber=tmp.toInt();
      }
    }
  }
  if(edgeNumber<0){
    return;
  }
  actualEdge = _graph->edges()[edgeNumber];
  //add data
  tmplist = input.split("=e,");
  if(tmplist.length()>=2){
    QString tmp = tmplist[1];
    tmplist = tmp.split(" ");
    for(int i = 1; i<tmplist.length(); i++){
      QString line = tmplist[i];
      float x = line.split(",")[0].toFloat();
      float y = line.split(",")[1].toFloat();
      actualEdge->addPoint(QPointF(x,-y));
    }
    QString line = tmplist[0];
    float x = line.split(",")[0].toFloat();
    float y = line.split(",")[1].toFloat();
    actualEdge->addPoint(QPointF(x,-y));

  }
  tmplist = input.split("lp=");
  if(tmplist.length()>=2){
    QString tmp = tmplist[1];
    tmplist = tmp.split(",");
    if(tmplist.length()>=2){
      actualEdge->setLabelPos(QPointF(tmplist[0].toFloat(),-tmplist[1].toFloat()));
    }
  }
}

