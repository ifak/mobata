grammar GraphvizPlainOutput;

@parser::postinclude
{
#include <stdexcept>

#define QT_NO_KEYWORDS
#include "graphvizgraph.hpp"
#undef QT_NO_KEYWORDS
}

@parser::members
{
  void setGraphvizGraph(graphvizparser::GraphvizGraph* graphvizGraph)
  {
    assert(graphvizGraph);
    this->_graphvizGraph = graphvizGraph;

    return;
  }

  graphvizparser::GraphvizGraph*	_graphvizGraph = nullptr;
}

graphvizPlainOutput
:	graph
  node*
  edge*
  stop
  ;

graph
:	'graph' NUMBER NUMBER NUMBER
          ;

node
  : {graphvizparser::GraphvizNode newNode;}
    'node'	name=ID x=NUMBER y=NUMBER w=NUMBER h=NUMBER
      {
         newNode.setName(QString::fromStdString($name.text));
         newNode.setPos(QString::fromStdString($x.text).toDouble(),
                               QString::fromStdString($y.text).toDouble());
         newNode.setWidth(QString::fromStdString($w.text).toDouble());
         newNode.setHeight(QString::fromStdString($h.text).toDouble());
       }
    ( '"' labelString=textRule '"'
        {newNode.setLabel(QString::fromStdString($labelString.text));}
      | labelID=ID
        {newNode.setLabel(QString::fromStdString($labelID.text));}
    )
    style=ID shape=ID color=ID fillcolor=ID
        {this->_graphvizGraph->addNode(newNode);}
  ;

edge
  :  {graphvizparser::GraphvizEdge newEdge;}
     'edge'	from=ID	to=ID
       {newEdge.setFrom(QString::fromStdString($from.text));
        newEdge.setTo(QString::fromStdString($to.text));}
      points_count=NUMBER
      (
        x=NUMBER y=NUMBER
          {newEdge.addPoint(QString::fromStdString($x.text).toDouble(),
                            QString::fromStdString($y.text).toDouble());
          }
      )*
      (
         ( '"' labelString=textRule '"'
             {newEdge.setLabel(QString::fromStdString($labelString.text));}
           |  labelID=ID
              {newEdge.setLabel(QString::fromStdString($labelID.text));}
         )
         x_label=NUMBER y_label=NUMBER
          {
             newEdge.setLabelPos(QString::fromStdString($x_label.text).toDouble(),
                                 QString::fromStdString($y_label.text).toDouble());
          }
         )?
         style=ID color=ID
          {this->_graphvizGraph->addEdge(newEdge);}
  ;

string
:	'"' textRule '"'
      ;

textRule
:	(.|':'|'['|']'|'/'|';')*?
  ;

stop
:	'stop'
  ;

GraphID:	'graph'
;

NodeID:		'node'
;

EdgeID:		'edge'
;

StopID:		'stop'
;

ID  :	('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'0'..'9'|'_')*
;

WS  :   ( ' '
          | '\t'
          | '\r'
          | '\n'
        ) -> channel(HIDDEN)
;

NUMBER
:	INT|FLOAT
  ;

fragment
INT
:	'1'..'9' Digit*
           | '0'
           ;

fragment
FLOAT
:   ('0'..'9')+ '.' ('0'..'9')* EXPONENT?
                                |   '.' ('0'..'9')+ EXPONENT?
|   ('0'..'9')+ EXPONENT
;

fragment
EXPONENT : ('e'|'E') ('+'|'-')? ('0'..'9')+ ;

fragment Digits:	Digit+ ;

fragment Digit:	('0'..'9') ;
