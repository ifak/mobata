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
class QJsonArray;
class QString;

namespace graphlayout {

class LayoutGraph;
class LayoutNode;
class LayoutEdge;
class LayoutNodePort;

namespace io {

///read objects//////////
void readLayout(const QJsonObject& jsonObject,
                LayoutGraph* layout,
                QString* errorMessage);

void readNodes(const QJsonObject& jsonObject,
               LayoutGraph* layout,
               QString* errorMessage);

void readEdges(const QJsonObject& jsonObject,
               LayoutGraph* layout,
               QString* errorMessage);

void readPorts(const QJsonObject& jsonObject,
               LayoutNode* node,
               QString* errorMessage);

void readNode(const QJsonObject& jsonObject,
              LayoutNode* node,
              QString* errorMessage);

void readEdge(const QJsonObject& jsonObject,
              LayoutEdge* edge,
              QString* errorMessage);

void readPort(const QJsonObject& jsonObject,
              LayoutNodePort* port,
              QString* errorMessage);

bool dependencyCheck(const QJsonObject& jsonObject,
                     LayoutGraph* layout,
                     QString* errorMessage);

} // namespace io
} // namespace graphlayout
