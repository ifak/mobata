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
#ifndef VIEW_TS_TESTCASEVIEW_HPP
#define VIEW_TS_TESTCASEVIEW_HPP

#include "../mobatawidgets_global.hpp"

#include "../msc/mscview.hpp"

namespace view {
namespace ts {

class TestCaseScene;

class MOBATAWIDGETSSHARED_EXPORT TestCaseView
    : public msc::KMscView
{
public:
  TestCaseView(QWidget* parent = 0);
  TestCaseView(TestCaseScene* testCaseScene,
               QWidget* parent = 0);
  virtual	~TestCaseView();

public:
  TestCaseScene*  testCaseScene();
};

} // namespace ts
} // namespace view

#endif // VIEW_TS_TESTCASEVIEW_HPP
