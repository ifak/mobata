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

#include <mobata/utils/functors.hpp>
#include <graphlayout/layoutgraph.hpp>

class QSettings;

namespace graphlayout {

class LayoutGraph;

class ComExportGraph
{
public:
  ComExportGraph(LayoutGraph const* layoutGraph,
                 QString* graphString);
  ~ComExportGraph();

public:
  bool execute(QString* errorString);
  void setWithEdgeLabels(const bool withEdgeLabels);

private:
  bool addNode(LayoutNode* node);
  bool addEdge(LayoutEdge* edge, QString* errorString);

  void initGraph();

  QString colorToHtml(const QColor& color);

private:
  class Private;
  Private* _d;
};

}// end namespace graphlayout
