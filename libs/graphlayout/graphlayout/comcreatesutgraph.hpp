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

#include <graphlayout/layoutgraph.hpp>
#include <mobata/model/ts/sutitem.hpp>
#include <mobata/model/ts/ts.hpp>
#include <QDebug>

namespace graphlayout {

class ComCreateSutGraph
{
public:
  ComCreateSutGraph(LayoutGraph* graph, model::ts::SutItem* sutItem);
  ~ComCreateSutGraph(){}

  void setSutComponentColor(const QColor& color);
  void setSutPortColor(const QColor& color);
  const QColor& sutComponentColor();
  const QColor& sutPortColor();

  void execute();

private:
  LayoutGraph*        _graph = nullptr;
  model::ts::SutItem* _sutItem = nullptr;

  QColor _sutComponentColor=QColor("cyan");
  QColor _sutPortColor=QColor("red");
};
}
