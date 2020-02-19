#include "filtermodel.hpp"

#include <QAbstractItemModel>
#include <QDebug>

#include "../../memory_leak_start.hpp"

namespace model{
namespace base{

FilterModel::FilterModel(QObject *parent) :
	QSortFilterProxyModel(parent)
{}

FilterModel::~FilterModel()
{}

bool FilterModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
	if(QSortFilterProxyModel::filterAcceptsRow(sourceRow, sourceParent))
		return true;
	
	return this->hasAcceptedChildren(sourceRow,sourceParent);
}

bool FilterModel::hasAcceptedChildren(int sourceRow, const QModelIndex &sourceParent) const
{
	QAbstractItemModel* sourceModel=this->sourceModel();
	if(!sourceModel)
		return false;
	
	QModelIndex sourceIndex=sourceModel->index(sourceRow, 0, sourceParent);
	if(!sourceIndex.isValid())
		return false;
	
	int rows=sourceModel->rowCount(sourceIndex);
	for(int i=0; i<rows; ++i)
	{
		if(this->filterAcceptsRow(i, sourceIndex))
			return true;
	}
	return false;
}

}///end namespace base
}///end namespace model
