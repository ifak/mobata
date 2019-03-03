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

#include "readlayout.hpp"
#include "layoutgraph.hpp"
#include "layoutnode.hpp"
#include "layoutedge.hpp"
#include "layoututils.hpp"
#include "mobata/model/base/io/readbasemodel.hpp"

#include <mobata/utils/functors.hpp>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>

using namespace model::base::io;

namespace graphlayout {
namespace io {

void readLayout(const QJsonObject& jsonObject,
                LayoutGraph* layout,
                QString* errorMessage)
{
  Q_ASSERT(layout);

  if(jsonObject.value(QStringLiteral("nodes"))!=QJsonValue::Undefined)
    readNodes(jsonObject, layout, errorMessage);

  if(jsonObject.value(QStringLiteral("edges"))!=QJsonValue::Undefined)
    readEdges(jsonObject, layout, errorMessage);

  return;
}

void readNodes(const QJsonObject& jsonObject,
               LayoutGraph* layout,
               QString* errorMessage)
{
  QJsonArray jsonArray;
  if(!readJsonArray(jsonObject, QStringLiteral("nodes"),
                    &jsonArray, errorMessage))
    return;

  for(const QJsonValue& jsonValue: jsonArray)
  {
    if(!jsonValue.isObject())
    {
      utils::AddPtrString(errorMessage) << "json value of array 'nodes' is not a json-object";
      return;
    }
    QJsonObject jsonObject=jsonValue.toObject();

    QString path;
    if(!readProperty<QString>(jsonObject, QStringLiteral("path"),
                              &path, errorMessage))
      return;

    readNode(jsonObject, layout->nodeByPath(path), errorMessage);
  }
  return;
}

void readNode(const QJsonObject& jsonObject,
               LayoutNode* node,
               QString* errorMessage)
{
  QString valueString;
  bool valueBool;
  double valueWidth, valueHeight, valueX, valueY;
  int valueInt;
  QColor valueColor;

  if(readProperty<QString>(jsonObject, QStringLiteral("name"), &valueString, errorMessage))
    node->setName(valueString);
  if(readProperty<QString>(jsonObject, QStringLiteral("shape"), &valueString, errorMessage))
    node->setShape(ShapeEnumFromString(valueString));
  if(readProperty_2<double, double>(jsonObject, QStringLiteral("sizeWidth"), &valueWidth,
                                    QStringLiteral("sizeHeight"), &valueHeight, errorMessage))
    node->setSize(QSizeF(valueWidth, valueHeight));
  if(readProperty_2<double, double>(jsonObject, QStringLiteral("posX"), &valueX,
                                    QStringLiteral("posY"), &valueY, errorMessage))
    node->setPos(QPointF(valueX, valueY));
  if(readProperty_2<double, double>(jsonObject, QStringLiteral("absolutePosX"), &valueX,
                                    QStringLiteral("absolutePosY"), &valueY, errorMessage))
    node->setAbsolutePos(QPointF(valueX, valueY));
  if(readProperty<QColor>(jsonObject, QStringLiteral("color"), &valueColor, errorMessage))
    node->setColor(valueColor);
  if(readProperty<double>(jsonObject, QStringLiteral("borderWidth"), &valueWidth, errorMessage))
    node->setBorderWidth(valueWidth);
  if(readProperty<QColor>(jsonObject, QStringLiteral("borderColor"), &valueColor, errorMessage))
    node->setBorderColor(valueColor);
  if(readProperty<QString>(jsonObject, QStringLiteral("label"), &valueString, errorMessage))
    node->setLabel(valueString);
  if(readProperty_2<double, double>(jsonObject, QStringLiteral("labelPosX"), &valueX,
                                    QStringLiteral("labelPosy"), &valueY, errorMessage))
    node->setLabelPos(QPointF(valueX, valueY));
  if(readProperty<int>(jsonObject, QStringLiteral("labelTextSize"), &valueInt, errorMessage))
    node->setLabelTextSize(valueInt);
  if(readProperty<QColor>(jsonObject, QStringLiteral("labelColor"), &valueColor, errorMessage))
    node->setLabelColor(valueColor);
  if(readProperty<QString>(jsonObject, QStringLiteral("xLabel"), &valueString, errorMessage))
    node->setXLabel(valueString);
  if(readProperty<int>(jsonObject, QStringLiteral("xLabelTextSize"), &valueInt, errorMessage))
    node->setXLabelTextSize(valueInt);
  if(readProperty<QColor>(jsonObject, QStringLiteral("xLabelColor"), &valueColor, errorMessage))
    node->setXLabelColor(valueColor);
  if(readProperty<bool>(jsonObject, QStringLiteral("staticLabels"), &valueBool, errorMessage))
    node->setStaticLabels(valueBool);
  if(readProperty<bool>(jsonObject, QStringLiteral("showInfobox"), &valueBool, errorMessage))
    node->setShowInfobox(valueBool);
  if(readProperty<QString>(jsonObject, QStringLiteral("infoBoxStrings"), &valueString, errorMessage))
    node->setInfoBoxStrings(valueString);
  if(readProperty<bool>(jsonObject, QStringLiteral("token"), &valueBool, errorMessage))
    node->setToken(valueBool);
  if(readProperty<QColor>(jsonObject, QStringLiteral("tokenColor"), &valueColor, errorMessage))
    node->setTokenColor(valueColor);
  if(readProperty<bool>(jsonObject, QStringLiteral("hideLabel"), &valueBool, errorMessage))
    node->setHideLabel(valueBool);
  if(readProperty<bool>(jsonObject, QStringLiteral("highlight"), &valueBool, errorMessage))
    node->setHighlight(valueBool);
  if(readProperty<QColor>(jsonObject, QStringLiteral("highlightColor"), &valueColor, errorMessage))
    node->setHighlightColor(valueColor);
  if(readProperty<QColor>(jsonObject, QStringLiteral("highlightBorderColor"), &valueColor, errorMessage))
    node->setHighlightBorderColor(valueColor);
  if(readProperty<double>(jsonObject, QStringLiteral("highlightBorderWidth"), &valueWidth, errorMessage))
    node->setHighlightBorderWidth(valueWidth);
  if(readProperty<bool>(jsonObject, QStringLiteral("fixedPos"), &valueBool, errorMessage))
    node->setFixedPos(valueBool);

  if(jsonObject.value(QStringLiteral("ports"))!=QJsonValue::Undefined)
    readPorts(jsonObject, node, errorMessage);

  return;
}

void readEdges(const QJsonObject& jsonObject,
               LayoutGraph* layout,
               QString* errorMessage)
{
  QJsonArray jsonArray;
  if(!readJsonArray(jsonObject, QStringLiteral("edges"),
                    &jsonArray, errorMessage))
    return;

  for(const QJsonValue& jsonValue: jsonArray)
  {
    if(!jsonValue.isObject())
    {
      utils::AddPtrString(errorMessage) << "json value of array 'edges' is not a json-object";
      return;
    }
    QJsonObject jsonObject=jsonValue.toObject();

    QString name;
    if(!readProperty<QString>(jsonObject, QStringLiteral("name"),
                              &name, errorMessage))
      return;

    readEdge(jsonObject, layout->edgeByName(name), errorMessage);
  }

  return;
}

void readEdge(const QJsonObject& jsonObject,
              LayoutEdge* edge,
              QString* errorMessage)
{
  QString valueString;
  bool valueBool;
  double valueDouble, valueX, valueY;
  int valueInt;
  QColor valueColor;

  if(readProperty<QString>(jsonObject, QStringLiteral("name"), &valueString, errorMessage))
    edge->setName(valueString);
  if(readProperty<QColor>(jsonObject, QStringLiteral("color"), &valueColor, errorMessage))
    edge->setColor(valueColor);
  if(readProperty<QString>(jsonObject, QStringLiteral("type"), &valueString, errorMessage))
    edge->setType(ArrowEnumFromString(valueString));
  if(readProperty<double>(jsonObject, QStringLiteral("lineWidth"), &valueDouble, errorMessage))
    edge->setLineWidth(valueDouble);
  if(readProperty<double>(jsonObject, QStringLiteral("arrowSize"), &valueDouble, errorMessage))
    edge->setArrowsize(valueDouble);
  if(readProperty<QColor>(jsonObject, QStringLiteral("borderColor"), &valueColor, errorMessage))
    edge->setColor(valueColor);
  if(readProperty<QString>(jsonObject, QStringLiteral("label"), &valueString, errorMessage))
    edge->setLabel(valueString);
  if(readProperty_2<double, double>(jsonObject, QStringLiteral("labelPosX"), &valueX,
                                    QStringLiteral("labelPosy"), &valueY, errorMessage))
    edge->setLabelPos(QPointF(valueX, valueY));
  if(readProperty<int>(jsonObject, QStringLiteral("labelTextSize"), &valueInt, errorMessage))
    edge->setLabelTextSize(valueInt);
  if(readProperty<QColor>(jsonObject, QStringLiteral("labelColor"), &valueColor, errorMessage))
    edge->setLabelColor(valueColor);
  if(readProperty<bool>(jsonObject, QStringLiteral("showInfobox"), &valueBool, errorMessage))
    edge->setShowInfobox(valueBool);
  if(readProperty<QString>(jsonObject, QStringLiteral("infoBoxStrings"), &valueString, errorMessage))
    edge->setInfoBoxStrings(valueString);
  if(readProperty<bool>(jsonObject, QStringLiteral("highlight"), &valueBool, errorMessage))
    edge->setHighlight(valueBool);
  if(readProperty<QColor>(jsonObject, QStringLiteral("highlightColor"), &valueColor, errorMessage))
    edge->setHighlightColor(valueColor);
  if(readProperty<bool>(jsonObject, QStringLiteral("staticLabel"), &valueBool, errorMessage))
    edge->setStaticLabel(valueBool);
  if(readProperty<bool>(jsonObject, QStringLiteral("constraint"), &valueBool, errorMessage))
    edge->setConstraint(valueBool);
  if(readProperty<int>(jsonObject, QStringLiteral("weight"), &valueInt, errorMessage))
    edge->setWeight(valueInt);
  if(readProperty<double>(jsonObject, QStringLiteral("minLen"), &valueDouble, errorMessage))
    edge->setMinLen(valueDouble);
  if(readProperty<QString>(jsonObject, QStringLiteral("rank"), &valueString, errorMessage))
    edge->setRank(valueString);

  QJsonArray jsonArray;
  if(!readJsonArray(jsonObject, QStringLiteral("points"),
                    &jsonArray, errorMessage))
    return;

  edge->clearPoints();

  for(const QJsonValue& jsonValue: jsonArray)
  {
    if(!jsonValue.isObject())
    {
      utils::AddPtrString(errorMessage) << "json value of array 'points' is not a json-object";
      return;
    }
    QJsonObject jsonObject=jsonValue.toObject();

    double x, y;
    if(!readProperty_2<double, double>(jsonObject, QStringLiteral("pointPosX"), &x,
                                       QStringLiteral("pointPosY"), &y, errorMessage))
      return;

    edge->addPoint(QPointF(x, y));
  }
}

void readPorts(const QJsonObject& jsonObject,
               LayoutNode* node,
               QString* errorMessage)
{
  QJsonArray jsonArray;
  if(!readJsonArray(jsonObject, QStringLiteral("ports"),
                    &jsonArray, errorMessage))
    return;

  for(const QJsonValue& jsonValue: jsonArray)
  {
    if(!jsonValue.isObject())
    {
      utils::AddPtrString(errorMessage) << "json value of array 'ports' is not a json-object";
      return;
    }
    QJsonObject jsonObject=jsonValue.toObject();

    QString name;
    if(!readProperty<QString>(jsonObject, QStringLiteral("name"),
                              &name, errorMessage))
      return;

    readPort(jsonObject, node->portByName(name), errorMessage);
  }

  return;
}

void readPort(const QJsonObject& jsonObject,
              LayoutNodePort* port,
              QString* errorMessage)
{
  QString valueString;
  double valueX, valueY, valueWidth, valueHeight;
  int valueInt;
  QColor valueColor;

  if(readProperty<QString>(jsonObject, QStringLiteral("name"), &valueString, errorMessage))
    port->setName(valueString);
  if(readProperty<QString>(jsonObject, QStringLiteral("shape"), &valueString, errorMessage))
    port->setShape(ShapeEnumFromString(valueString));
  if(readProperty_2<double, double>(jsonObject, QStringLiteral("sizeWidth"), &valueWidth,
                                    QStringLiteral("sizeHeight"), &valueHeight, errorMessage))
    port->setSize(QSizeF(valueWidth, valueHeight));
  if(readProperty_2<double, double>(jsonObject, QStringLiteral("posX"), &valueX,
                                    QStringLiteral("posY"), &valueY, errorMessage))
    port->setPos(QPointF(valueX, valueY));
  if(readProperty_2<double, double>(jsonObject, QStringLiteral("labelPosX"), &valueX,
                                    QStringLiteral("labelPosy"), &valueY, errorMessage))
    port->setLabelPos(QPointF(valueX, valueY));
  if(readProperty<QColor>(jsonObject, QStringLiteral("color"), &valueColor, errorMessage))
    port->setColor(valueColor);
  if(readProperty<QString>(jsonObject, QStringLiteral("label"), &valueString, errorMessage))
    port->setLabel(valueString);
  if(readProperty<int>(jsonObject, QStringLiteral("labelSize"), &valueInt, errorMessage))
    port->setLabelSize(valueInt);
  if(readProperty<QString>(jsonObject, QStringLiteral("type"), &valueString, errorMessage))
    port->setType(valueString);
}

bool dependencyCheck(const QJsonObject& jsonObject,
                     LayoutGraph* layout,
                     QString* errorMessage)
{
  //node dependency check
  QJsonArray jsonArray;
  if(!readJsonArray(jsonObject, QStringLiteral("nodes"),
                    &jsonArray, errorMessage))
    return false;

  for(const QJsonValue& jsonValue: jsonArray)
  {
    if(!jsonValue.isObject())
    {
      utils::AddPtrString(errorMessage) << "json value of array 'nodes' is not a json-object";
      return false;
    }
    QJsonObject jsonNodeObject=jsonValue.toObject();

    QString path;
    bool result = readProperty<QString>(jsonNodeObject,
                                        QStringLiteral("path"),
                                        &path,
                                        errorMessage);
    LayoutNode* node = layout->nodeByPath(path);
    if(!result || !node){
      utils::AddPtrString(errorMessage) << "Layout Dependency check: Node " << path << " not found!";
      return false;
    }

    //port dependency check
    QJsonArray jsonPortArray;
    if(readJsonArray(jsonObject, QStringLiteral("ports"),
                     &jsonPortArray, errorMessage)){
      for(const QJsonValue& jsonValue: jsonPortArray)
      {
        if(!jsonValue.isObject())
        {
          utils::AddPtrString(errorMessage) << "json value of array 'ports' is not a json-object";
          return false;
        }
        QJsonObject jsonPortObject=jsonValue.toObject();

        QString name;
        bool result = readProperty<QString>(jsonPortObject,
                                            QStringLiteral("name"),
                                            &name,
                                            errorMessage);
        if(!result || !node->portByName(name)){
          utils::AddPtrString(errorMessage) << "Layout Dependency check: Port " << name << " not found!";
          return false;
        }
      }
    }
  }

  QJsonArray jsonEdgeArray;
  //edge dependency check
  if(!readJsonArray(jsonObject, QStringLiteral("edges"),
                    &jsonEdgeArray, errorMessage))
    return false;

  for(const QJsonValue& jsonValue: jsonEdgeArray)
  {
    if(!jsonValue.isObject())
    {
      utils::AddPtrString(errorMessage) << "json value of array 'edges' is not a json-object";
      return false;
    }
    QJsonObject jsonEdgeObject=jsonValue.toObject();

    QString name;
    bool result = readProperty<QString>(jsonEdgeObject,
                                        QStringLiteral("name"),
                                        &name,
                                        errorMessage);
    if(!result || !layout->edgeByName(name)){
      utils::AddPtrString(errorMessage) << "Layout Dependency check: Edge " << name << " not found!";
      return false;
    }
  }

  return true;
}

} // namespace io
} // namespace graphlayout
