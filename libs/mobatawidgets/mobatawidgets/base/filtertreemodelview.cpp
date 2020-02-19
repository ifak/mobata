#include "filtertreemodelview.hpp"

#include "texteditdelegate.hpp"

#include <QTreeView>
#include <QSortFilterProxyModel>
#include <QHeaderView>
#include <QLayout>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace base{

class FilterTreeModelView::Private
{
	friend class FilterTreeModelView;
	
	Private()
		:	_treeView(0)
	{}
	
public:
	~Private()
	{}
	
private:
	QTreeView*	_treeView;
};

FilterTreeModelView::FilterTreeModelView(QTreeView *treeView, 
                                            QWidget *parent)
	:	BaseFilterModelView(parent), _d(new Private())
{
	if(treeView)
		this->_d->_treeView=treeView;
	else
		this->_d->_treeView=new QTreeView();
	
	this->setModelViewProperties();
	this->layout()->addWidget(this->_d->_treeView);
}

FilterTreeModelView::~FilterTreeModelView()
{}

QTreeView *FilterTreeModelView::filterModelView()
{
	return this->_d->_treeView;
}

void FilterTreeModelView::setFilterModelView(QTreeView *treeView)
{
	if(!treeView
		 || treeView==this->_d->_treeView)
		return;
	
	if(this->_d->_treeView)
	{
		this->layout()->removeWidget(this->_d->_treeView);
		this->_d->_treeView->deleteLater();
	}
	
	this->_d->_treeView=treeView;
	this->setModelViewProperties();
	this->layout()->addWidget(this->_d->_treeView);
	
	return;
}

void FilterTreeModelView::setEditableColumn(int column)
{
	if(!this->sourceModel())
		return;
	
	this->_d->_treeView->setItemDelegateForColumn(column, this->textEditDelegate());
	
	return;
}

void FilterTreeModelView::setModelViewProperties()
{
	if(!this->_d->_treeView)
		return;
	
	this->_d->_treeView->setParent(this);
	this->_d->_treeView->setModel(this->filterModel());
	this->_d->_treeView->setWordWrap(true);
	this->_d->_treeView->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
	this->_d->_treeView->setVerticalScrollMode(QTreeView::ScrollPerPixel);
	
	return;
}

}///end namespace base
}///end namespace view
