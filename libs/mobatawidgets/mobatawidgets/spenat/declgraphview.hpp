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
#ifndef VIEW_SPENAT_DECLGRAPHVIEW_HPP
#define VIEW_SPENAT_DECLGRAPHVIEW_HPP

#include "../mobatawidgets_global.hpp"

#include "../graph/graphview.hpp"

namespace view{
namespace spenat{

class DeclScene;

class MOBATAWIDGETSSHARED_EXPORT DeclGraphView
    :	public graph::GraphView
{
  Q_OBJECT
public:
  DeclGraphView(QWidget* parent = 0);
  virtual ~DeclGraphView();

private:
  void createActions();
  void createStateMachine();

public:
  DeclScene*  declGraphScene();
  void        setDeclGraphScene(DeclScene* declGraphScene);
  QAction*    selectAction();
  QAction*    addPlaceAction();
  QAction*    addTransitionAction();
  QAction*    addJunctionAction();
  QAction*    addArcAction();
  QAction*    initMarkingAction();

  QList<QAction*> declGraphViewActions();

public slots:
  void reset();

protected:
  virtual void	mousePressEvent(QMouseEvent* event);
  virtual void	mouseMoveEvent(QMouseEvent *event);
  virtual void	mouseReleaseEvent (QMouseEvent* event);
  virtual void	focusOutEvent(QFocusEvent * event);
  virtual void	resizeEvent(QResizeEvent* event);
  virtual void	keyReleaseEvent(QKeyEvent* event);
  virtual void	createPreviewStuff();

private:
  Q_DISABLE_COPY(DeclGraphView)
  class Private;
  QScopedPointer<Private> _d;
};

}/// namespace spenat
}/// namespace view

#endif //VIEW_SPENAT_DECLGRAPHVIEW_HPP
