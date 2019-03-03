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

#include "writelayout.hpp"
#include "layoutgraph.hpp"
#include "layoutnode.hpp"
#include "layoutnodeport.hpp"
#include "layoutedge.hpp"
#include "layoututils.hpp"

#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include <QColor>

namespace graphlayout {
namespace io {

void writeLayout(LayoutGraph const* layout,
                 QJsonObject& jsonObject)
{
  Q_ASSERT(layout);

  writeNodes(layout, jsonObject);
  writeEdges(layout, jsonObject);

  return;
}

void writeNodes(LayoutGraph const* layout, QJsonObject& jsonObject)
{
  Q_ASSERT(layout);

  if(layout->nodes().isEmpty())
    return;

  QJsonArray nodesArray;
  for(LayoutNode const* node:
           layout->allNodes())
  {
    QJsonObject nodeObject;
    writeNode(node, nodeObject);
    nodesArray.append(nodeObject);
  }
  jsonObject["nodes"] = nodesArray;
}

void writeEdges(LayoutGraph const* layout, QJsonObject& jsonObject)
{
  Q_ASSERT(layout);

  if(layout->edges().isEmpty())
    return;

  QJsonArray edgesArray;
  for(LayoutEdge const* edge:
           layout->edges())
  {
    QJsonObject edgeObject;
    writeEdge(edge, edgeObject);
    edgesArray.append(edgeObject);
  }
  jsonObject["edges"] = edgesArray;
}

void writeNode(LayoutNode const* node, QJsonObject& jsonObject)
{
  Q_ASSERT(node);
  jsonObject["name"] = node->name();
  jsonObject["path"] = recursiveNodeName(node);
  jsonObject["shape"] = ShapeEnumToString(node->shape());
  jsonObject["sizeWidth"] = QString::number(node->size().width());
  jsonObject["sizeHeight"] = QString::number(node->size().height());
  jsonObject["posX"] = QString::number(node->pos().x());
  jsonObject["posY"] = QString::number(node->pos().y());
  jsonObject["absolutePosX"] = QString::number(node->absolutePos().x());
  jsonObject["absolutePosY"] = QString::number(node->absolutePos().y());
  jsonObject["color"] = fullColorHexString(node->color());
  jsonObject["borderWidth"] =  QString::number(node->borderWidth());
  jsonObject["borderColor"] =  fullColorHexString(node->borderColor());
  jsonObject["label"] =  node->label();
  jsonObject["labelPosX"] =  QString::number(node->labelPos().x());
  jsonObject["labelPosy"] =  QString::number(node->labelPos().y());
  jsonObject["labelTextSize"] =  QString::number(node->labelTextSize());
  jsonObject["labelColor"] =  fullColorHexString(node->labelColor());
  jsonObject["xLabel"] =  node->xLabel();
  jsonObject["xLabelTextSize"] =  QString::number(node->xLabelTextSize());
  jsonObject["xLabelColor"] =  fullColorHexString(node->xLabelColor());
  jsonObject["staticLabels"] =  QString::number(node->staticLabels());
  jsonObject["showInfobox"] =  QString::number(node->showInfobox());
  jsonObject["infoBoxStrings"] =  node->infoBoxStrings();
  jsonObject["token"] =  QString::number(node->token());
  jsonObject["tokenColor"] =  fullColorHexString(node->tokenColor());
  jsonObject["hideLabel"] =  QString::number(node->hideLabel());
  jsonObject["highlight"] =  QString::number(node->highlight());
  jsonObject["highlightColor"] =  fullColorHexString(node->highlightColor());
  jsonObject["highlightBorderColor"] =  fullColorHexString(node->highlightBorderColor());
  jsonObject["highlightBorderWidth"] =  QString::number(node->highlightBorderWidth());
  jsonObject["fixedPos"] =  QString::number(node->fixedPos());

  if(!node->ports().isEmpty()){
    QJsonArray portsArray;
    for(LayoutNodePort* port: node->ports()){
      QJsonObject portObject;
      writePort(port, portObject);
      portsArray.append(portObject);
    }
    jsonObject["ports"] = portsArray;
  }
}

void writeEdge(LayoutEdge const* edge, QJsonObject& jsonObject)
{
  Q_ASSERT(edge);

  jsonObject["name"] = edge->name();
  jsonObject["type"] = ArrowEnumToString(edge->type());
  jsonObject["color"] = fullColorHexString(edge->color());
  jsonObject["lineWidth"] =  QString::number(edge->lineWidth());
  jsonObject["arrowSize"] =  QString::number(edge->Arrowsize());
  jsonObject["label"] =  edge->label();
  jsonObject["labelPosX"] =  QString::number(edge->labelPos().x());
  jsonObject["labelPosy"] =  QString::number(edge->labelPos().y());
  jsonObject["labelTextSize"] =  QString::number(edge->labelTextSize());
  jsonObject["labelColor"] =  fullColorHexString(edge->labelColor());
  jsonObject["showInfobox"] =  QString::number(edge->showInfobox());
  jsonObject["infoBoxStrings"] =  fullColorHexString(edge->infoBoxStrings());
  jsonObject["highlight"] =  QString::number(edge->highlight());
  jsonObject["highlightColor"] =  fullColorHexString(edge->highlightColor());
  jsonObject["constraint"] =  QString::number(edge->constraint());
  jsonObject["weight"] =  QString::number(edge->weight());
  jsonObject["minLen"] =  QString::number(edge->minLen());
  jsonObject["rank"] =  edge->rank();
  jsonObject["staticLabel"] =  QString::number(edge->staticLabel());

  QJsonArray pointArray;
  for(QPointF* point: edge->points()){
    QJsonObject pointObject;
    pointObject["pointPosX"] = QString::number(point->x());
    pointObject["pointPosY"] = QString::number(point->y());
    pointArray.append(pointObject);
  }
  jsonObject["points"] =  pointArray;
}

void writePort(LayoutNodePort const* port, QJsonObject& jsonObject)
{
  Q_ASSERT(port);

  jsonObject["name"] = port->name();
  jsonObject["shape"] = ShapeEnumToString(port->shape());
  jsonObject["color"] = fullColorHexString(port->color());
  jsonObject["type"] = port->type();
  jsonObject["label"] =  port->label();
  jsonObject["sizeWidth"] = QString::number(port->size().width());
  jsonObject["sizeHeight"] = QString::number(port->size().height());
  jsonObject["labelPosX"] =  QString::number(port->labelPos().x());
  jsonObject["labelPosy"] =  QString::number(port->labelPos().y());
  jsonObject["labelSize"] =  QString::number(port->labelSize());
  jsonObject["posX"] = QString::number(port->pos().x());
  jsonObject["posY"] = QString::number(port->pos().y());
}

QString fullColorHexString(QColor color)
{
  QString hexString("#");
  QString alpha, red, blue, green;
  alpha = QString::number(color.alpha(), 16); //add transparency
  if(alpha.size() == 1)
    alpha.prepend("0");
  red = QString::number(color.red(), 16); //add red
  if(red.size() == 1)
    red.prepend("0");
  green = QString::number(color.green(), 16); //add green
  if(green.size() == 1)
    green.prepend("0");
  blue = QString::number(color.blue(), 16); //add blue
  if(blue.size() == 1)
    blue.prepend("0");
  hexString.append(alpha + red + green + blue);
  return hexString;
}

} // namespace io
} // namespace graphlayout
