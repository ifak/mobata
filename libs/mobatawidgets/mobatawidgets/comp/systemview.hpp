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
#ifndef VIEW_COMP_SYSTEMVIEW_HPP
#define VIEW_COMP_SYSTEMVIEW_HPP

#include "../graph/graphview.hpp"
#include "types.hpp"

class QToolBar;
class QActionGroup;

namespace view{
namespace comp{

class SystemScene;
class Port;

class SystemView : public graph::GraphView
{
	Q_OBJECT
public:
  SystemView(SystemScene* systemScene, QWidget* parent = 0);
  ~SystemView();

private:
  SystemScene* systemScene();

public:
  virtual QAction*        action(const QVariant& actionData);
  virtual QList<QAction*> systemViewActions();

  virtual void setCompNodeOptions(NodeOptions options);
  virtual void setPortNodeOptions(NodeOptions options);
  virtual void setLinkArcOptions(ArcOptions options);

protected:
  void mouseReleaseEvent(QMouseEvent* event);
  void mouseMoveEvent(QMouseEvent* event);
  void focusOutEvent(QFocusEvent * event);
  void keyReleaseEvent(QKeyEvent* event);
  void removeCompItems(QList<QGraphicsItem*>& graphicsItems);

public slots:
  void setSelectModeSlot();
  void setAddComponentModeSlot();
  void setAddPortModeSlot();
  void setAddLinkModeSlot();

private:
  QActionGroup*	_actionGroup;

private:
	enum Mode
	{
    SELECT,
    ADDCOMPONENT,
    ADDPORT,
    ADDLINK,
    ADDLINKTARGET,
	};

protected:
  Mode                _mode;
  QGraphicsRectItem*  _preViewComponent;
  QGraphicsPathItem*  _preViewLink;
  Port*               _fromPort;
  QToolBar*           _systemViewToolbar;
  NodeOptions         _compOptions;
  NodeOptions         _portOptions;
  ArcOptions          _linkOptions;
};

}/// end namespace comp
}/// end namespace view

#endif
