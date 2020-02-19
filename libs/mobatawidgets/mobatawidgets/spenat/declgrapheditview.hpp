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
#ifndef VIEW_SPENAT_DECLGRAPHEDITVIEW_HPP
#define VIEW_SPENAT_DECLGRAPHEDITVIEW_HPP

#include "../mobatawidgets_global.hpp"

#include <QWidget>

namespace view{
namespace spenat{

namespace Ui
{
	class DeclGraphEditView;
}

class DeclScene;

class MOBATAWIDGETSSHARED_EXPORT DeclGraphEditView : public QWidget
{
	Q_OBJECT
	
public:
	explicit DeclGraphEditView(QWidget *parent = 0);
	virtual ~DeclGraphEditView();
	
public:
	DeclScene*	declGraphScene();
	void				setDeclGraphScene(DeclScene* declGraphScene);

public:
  QAction*        zoomInAction();
  QAction*        zoomOutAction();
  QAction*        zoomFitInViewAction();
  QAction*        zoomResetAction();
  QList<QAction*> allZoomActions();
  
public slots:
	void	reset();
  void zoomIn();
  void zoomOut();
  void zoomInView();
  void zoomReset();
  
private:
	Q_DISABLE_COPY(DeclGraphEditView)
	class Private;
	QScopedPointer<Private>	_d;
	Ui::DeclGraphEditView*	_ui;
};


} // namespace spenat
} // namespace view

#endif // VIEW_SPENAT_DECLGRAPHEDITVIEW_HPP
