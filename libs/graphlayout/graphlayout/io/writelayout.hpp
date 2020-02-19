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
#pragma once

class QJsonObject;
class QColor;
class QString;

namespace graphlayout {

class LayoutGraph;
class LayoutNode;
class LayoutEdge;
class LayoutNodePort;

namespace io {

///write objects//////////

void writeLayout(LayoutGraph const* layout,
                 QJsonObject& jsonObject);
void writeNodes(LayoutGraph const* layout,
                QJsonObject& jsonObject);
void writeEdges(LayoutGraph const* layout,
                QJsonObject& jsonObject);
void writeNode(const LayoutNode *node,
               QJsonObject& jsonObject);
void writeEdge(LayoutEdge const* edge,
               QJsonObject& jsonObject);

void writePort(LayoutNodePort const* port,
               QJsonObject& jsonObject);

QString fullColorHexString(QColor color);

} // namespace io
} // namespace graphlayout
