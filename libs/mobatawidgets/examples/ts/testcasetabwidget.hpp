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
#ifndef TESTCASETABWIDGET_HPP
#define TESTCASETABWIDGET_HPP

#include <QTabWidget>

#include <mobata/model/ts/ts_types.hpp>
#include <mobatawidgets/ts/types.hpp>

class TestCaseTabWidget : public QTabWidget
{
	Q_OBJECT
	
	typedef model::ts::TestCaseItem     TsTestCaseItem;
  typedef view::ts::TsTestCasePixWidget TsTestCasePixWidget;

public:
	explicit TestCaseTabWidget(QWidget *parent = 0);
	virtual ~TestCaseTabWidget();
  
public:
	void setCurrentTestCase(TsTestCaseItem const* testCase);
  
private:
  TsTestCasePixWidget*  testCasePixWidget(TsTestCaseItem const* testCase);
	
private:
	Q_DISABLE_COPY(TestCaseTabWidget)
	class Private;
	QScopedPointer<Private> _d;
};

#endif // TESTCASETABWIDGET_HPP
