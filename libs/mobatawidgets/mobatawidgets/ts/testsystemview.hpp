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
#ifndef VIEW_TS_TESTSYSTEMVIEW_HPP
#define VIEW_TS_TESTSYSTEMVIEW_HPP

#include "../mobatawidgets_global.hpp"

#include "../graph/graphview.hpp"

namespace view {
namespace ts {

class TestSystemScene;

class MOBATAWIDGETSSHARED_EXPORT TestSystemView
    : public graph::GraphView
{
  Q_OBJECT

public:
  TestSystemView(QWidget* parent =0);
  TestSystemView(TestSystemScene* testSystemScene,
                 QWidget *parent = 0);
  virtual ~TestSystemView();

public:
  TestSystemScene* testSystemScene();
};

} // namespace ts
} // namespace view

#endif // VIEW_TS_TESTSYSTEMVIEW_HPP
