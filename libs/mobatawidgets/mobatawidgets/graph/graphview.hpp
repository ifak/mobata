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
#ifndef VIEW_GRAPH_GRAPHVIEW_HPP
#define VIEW_GRAPH_GRAPHVIEW_HPP

#include "../mobatawidgets_global.hpp"

#include <QGraphicsView>

class QAction;
class QSlider;

namespace view{
namespace graph{

class GraphScene;

class MOBATAWIDGETSSHARED_EXPORT GraphView
    : public QGraphicsView
{
  Q_OBJECT
public:
  GraphView(QWidget * parent = 0);
  GraphView(GraphScene* graphScene, QWidget * parent = 0);
  virtual ~GraphView();

signals:
  void  zoomValueChanged(int zoomValue);
  void  shown();
  void  resized();

public:
  QAction*        zoomInAction();
  QAction*        zoomOutAction();
  QAction*        zoomFitInViewAction();
  QAction*        zoomResetAction();
  QList<QAction*> allZoomActions();

public:
  GraphScene* graphScene();
  void        updateSceneRect();

public:
  int		zoomValue() const;
  int		zoomMin() const;
  int		zoomMax() const;
  void	setZoomRange(const int zoomMin, const int zoomMax);

public slots:
  void	zoomInView();
  void	zoomIn();
  void	zoomOut();
  void	zoomReset();
  void	setupTransform();
  void	print();
  void	setZoomValue(int zoomValue);

protected:
  virtual void wheelEvent(QWheelEvent* event);
  virtual void showEvent(QShowEvent *event);
  virtual void resizeEvent(QResizeEvent* event);



private:
  Q_DISABLE_COPY(GraphView)
  class Private;
  Private*	_d;
};

}//end namspace graph
}//end namespace view

#endif //VIEW_GRAPH_GRAPHVIEW_HPP
