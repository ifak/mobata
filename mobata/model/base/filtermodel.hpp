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

#pragma once

#include "../../mobata_global.hpp"

#include <QSortFilterProxyModel>

namespace model{
namespace base{

class MOBATASHARED_EXPORT FilterModel
		:	public QSortFilterProxyModel
{
	Q_OBJECT
public:
	explicit FilterModel(QObject *parent = 0);
	virtual ~FilterModel();
	
protected:
	virtual bool filterAcceptsRow(int sourceRow, 
																const QModelIndex &sourceParent) const;
	virtual bool hasAcceptedChildren(int sourceRow, 
																	 const QModelIndex &sourceParent) const;

};

}//////end namespace base
}///end namespace model
