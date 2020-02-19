#include "testcasetabwidget.hpp"

#include <mobata/model/ts/testcaseitem.hpp>
#include <mobatawidgets/ts/tstestcasepixwidget.hpp>

#include <QNetworkAccessManager>

class TestCaseTabWidget::Private
{
  friend class TestCaseTabWidget;
  
  QNetworkAccessManager* _networkManager;
};

TestCaseTabWidget::TestCaseTabWidget(QWidget *parent)
  : QTabWidget(parent), _d(new Private())
{
  this->_d->_networkManager=new QNetworkAccessManager(this);
}

TestCaseTabWidget::~TestCaseTabWidget()
{}

view::ts::TsTestCasePixWidget *TestCaseTabWidget::testCasePixWidget(const TsTestCaseItem *testCase)
{
	int count=this->count();
	for(int i=0; i<count; ++i)
	{
		QWidget* tabWidget=this->widget(i);
		TsTestCasePixWidget* testCasePixView=dynamic_cast<TsTestCasePixWidget*>(tabWidget);
		Q_ASSERT(testCasePixView);
		if(testCasePixView->modelItem()==testCase)
			return testCasePixView;
	}
	
	return 0;
}

void TestCaseTabWidget::setCurrentTestCase(const TsTestCaseItem *testCase)
{
	if(!testCase)
		return;
	
	if(TsTestCasePixWidget* existTestCasePixView=this->testCasePixWidget(testCase))
	{
		this->setCurrentWidget(existTestCasePixView);
		return;
	}
	
	TsTestCasePixWidget* newTestCasePixView=new TsTestCasePixWidget(testCase, this);
	this->addTab(newTestCasePixView, newTestCasePixView->modelItem()->text());
	this->setCurrentWidget(newTestCasePixView);
	newTestCasePixView->renderModeItem(this->_d->_networkManager);
	
	return;
}
