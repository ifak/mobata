/*
 * This file is part of mobata.
 *
 * Copyright (C) 2019 ifak, https://www.ifak.eu/
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

#include "filtermodel.hpp"

#include <QAbstractItemModel>
#include <QDebug>

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
