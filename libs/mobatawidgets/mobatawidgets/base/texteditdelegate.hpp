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
#ifndef VIEW_BASE_TEXTEDITDELEGATE_HPP
#define VIEW_BASE_TEXTEDITDELEGATE_HPP

#include "../mobatawidgets_global.hpp"

#include <QStyledItemDelegate>

namespace view{
namespace base{

class MOBATAWIDGETSSHARED_EXPORT TextEditDelegate
		: public QStyledItemDelegate
{
	Q_OBJECT
public:
	explicit TextEditDelegate(QObject *parent = 0);
	virtual ~TextEditDelegate();
	
signals:
	
public slots:
	
public:
	QWidget *createEditor(QWidget *parent,
												const QStyleOptionViewItem &option,
												const QModelIndex &index) const;
	void setEditorData(QWidget *editor, const QModelIndex &index) const;
	void setModelData(QWidget *editor, 
										QAbstractItemModel *Model,
										const QModelIndex &index) const;
	QSize sizeHint(const QStyleOptionViewItem &option, 
								 const QModelIndex &index) const;
	
private slots:
	void closeAndCommitEditor();
	
private:
	Q_DISABLE_COPY(TextEditDelegate)
	class Private;
	QScopedPointer<Private>	_d;
};

}/// namespace base
}/// namespace view

#endif // VIEW_BASE_TEXTEDITDELEGATE_HPP
