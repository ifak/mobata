#include "basefiltermodelview.hpp"

#include "ui_basefiltermodelview.h"

#include <mobata/model/base/filtermodel.hpp>
#include "texteditdelegate.hpp"

#include <QSortFilterProxyModel>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace base{

class BaseFilterModelView::Private
{
	friend class BaseFilterModelView;
	
	Private()
		:	_filterModel(0), _sourceModel(0), _textEditDelegate(0)
	{}
	
public:
	~Private()
	{}
	
private:
	model::base::FilterModel* _filterModel;
	QAbstractItemModel*       _sourceModel;
	TextEditDelegate*         _textEditDelegate;
};

BaseFilterModelView::BaseFilterModelView(QWidget *parent)
	:	QWidget(parent),
		_d(new Private()),
		_ui(new Ui::BaseFilterModelView())
{
	this->_ui->setupUi(this);
	
	this->_d->_filterModel=new model::base::FilterModel(this);
	this->_d->_textEditDelegate=new TextEditDelegate(this);
	
	connect(this->_ui->_searchTextEdit, SIGNAL(textChanged(const QString&)),
					this->_d->_filterModel, SLOT(setFilterRegExp(const QString&)));
}

BaseFilterModelView::~BaseFilterModelView()
{
	delete this->_ui;
}

void BaseFilterModelView::setSourceModel(QAbstractItemModel* itemModel,
                                         int filterKeyColumn)
{
	this->_d->_sourceModel=itemModel;
	
	if(!this->_d->_sourceModel)
		return;
	
	this->_d->_filterModel->setSourceModel(this->_d->_sourceModel);
	this->_d->_filterModel->setFilterKeyColumn(filterKeyColumn);
	
	return;
}

QAbstractItemModel *BaseFilterModelView::sourceModel()
{
	return this->_d->_sourceModel;
}

QSortFilterProxyModel *BaseFilterModelView::filterModel()
{
	return this->_d->_filterModel;
}

TextEditDelegate *BaseFilterModelView::textEditDelegate()
{
	return this->_d->_textEditDelegate;
}

QWidget *BaseFilterModelView::toolBarWidget()
{
	return this->_ui->_toolBarWidget;
}

}///end namespace base
}///end namespace view
