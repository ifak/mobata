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
#ifndef VIEW_SPENAT_DECLMODELVIEW_HPP
#define VIEW_SPENAT_DECLMODELVIEW_HPP

#include "../mobatawidgets_global.hpp"

#include <QTreeView>

namespace model{namespace spenat{class SpenatDeclModel;}}

namespace view{
namespace spenat{

class MOBATAWIDGETSSHARED_EXPORT DeclModelView
    : public QTreeView
{
	Q_OBJECT
public:
	explicit DeclModelView(QWidget *parent = 0);
	
signals:
	
public slots:
	
public:
	virtual void setDeclModel(model::spenat::SpenatDeclModel* declModel);
};

} // namespace spenat
} // namespace view

#endif // VIEW_SPENAT_DECLMODELVIEW_HPP
