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
#ifndef VIEW_BASE_BASEFILTERMODELVIEW_HPP
#define VIEW_BASE_BASEFILTERMODELVIEW_HPP

#include "../mobatawidgets_global.hpp"

#include <QWidget>

class QAbstractItemModel;
class QAbstractItemView;
class QSortFilterProxyModel;

namespace view{
namespace base{

namespace Ui {
	class BaseFilterModelView;
}

class TextEditDelegate;

class MOBATAWIDGETSSHARED_EXPORT BaseFilterModelView
		:	public QWidget
{
	Q_OBJECT
	
public:
	explicit BaseFilterModelView(QWidget *parent = 0);
	virtual ~BaseFilterModelView();
	
public:
	virtual void setSourceModel(QAbstractItemModel* itemModel, 
															int filterKeyColumn=-1);
	
public:
	virtual QAbstractItemView*	filterModelView() =0;
	virtual void								setEditableColumn(int column)=0;
	
protected:
	virtual void	setModelViewProperties()=0;
	
protected:
	QAbstractItemModel*			sourceModel();
	QSortFilterProxyModel*	filterModel();
	TextEditDelegate*				textEditDelegate();
	QWidget*								toolBarWidget();
	
private:
	Q_DISABLE_COPY(BaseFilterModelView)
	class Private;
	QScopedPointer<Private>		_d;
	Ui::BaseFilterModelView*	_ui;
};


}/// namespace base
}/// namespace view

#endif // VIEW_BASE_BASEFILTERMODELVIEW_HPP
