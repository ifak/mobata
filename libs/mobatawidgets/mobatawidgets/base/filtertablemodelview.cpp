#include "filtertablemodelview.hpp"

#include <mobata/model/base/filtermodel.hpp>
#include "texteditdelegate.hpp"

#include <QSortFilterProxyModel>
#include <QHeaderView>
#include <QLayout>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace base{

class FilterTableModelView::Private
{
	friend class FilterTableModelView;
	
	Private()
		:	_tableView(0)
	{}
	
public:
	~Private()
	{}
	
private:
	QTableView*	_tableView;
};

FilterTableModelView::FilterTableModelView(QWidget *parent)
	:	BaseFilterModelView(parent), _d(new Private())
{
	this->_d->_tableView=new QTableView(this);
	this->_d->_tableView->setModel(this->filterModel());
	setModelViewProperties();
	
	this->layout()->addWidget(this->_d->_tableView);
}

FilterTableModelView::~FilterTableModelView()
{}

QTableView* FilterTableModelView::filterModelView()
{
	return this->_d->_tableView;
}

void FilterTableModelView::setEditableColumn(int column)
{
	if(!this->sourceModel())
		return;
	
	this->_d->_tableView->setItemDelegateForColumn(column, this->textEditDelegate());
	
	return;
}

void FilterTableModelView::setModelViewProperties()
{
	if(this->_d->_tableView)
		return;
	
	this->_d->_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	this->_d->_tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	this->_d->_tableView->setVerticalScrollMode(QTableView::ScrollPerPixel);
	
	return;
}

}///end namespace base
}///end namespace view
