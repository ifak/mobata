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
#ifndef VIEW_GRAPH_GRAPHVIEWSTATEMACHINE_HPP
#define VIEW_GRAPH_GRAPHVIEWSTATEMACHINE_HPP

#include "../mobatawidgets_global.hpp"

namespace view{
namespace graph{

class GraphView;

class AbstractViewState : public QState
{
public:
  AbstractViewState(GraphView* graphView,
                    QState* parentState = 0)
    :	QState(parentState), _graphView(graphView)
  {}

public:
  virtual void addItem(QPointF pos)	=0;
  virtual void mouseMove(QPointF)		{}

protected:
  GraphView*	_graphView;
};

////focus out transition/////////
class FocusOutTransition : public QAbstractTransition
{
public:
  FocusOutTransition()	{}

protected:
  bool eventTest(QEvent *event)
  {
    if (event->type() != QEvent::Type(QEvent::FocusOut)) // FocusOut
      return false;

    return true;
  }

  virtual void onTransition(QEvent *) {}
};

////mouse press transition/////////
class MousePressTransition : public QAbstractTransition
{
public:
  MousePressTransition()	{}

protected:
  bool eventTest(QEvent *event)
  {
    if (event->type() != QEvent::Type(QEvent::MouseButtonPress)) // Mouse Press
      return false;

    return true;
  }

  virtual void onTransition(QEvent *) {}
};

////mouse release transition/////////
class MouseReleaseTransition : public QAbstractTransition
{
public:
  MouseReleaseTransition()	{}

protected:
  bool eventTest(QEvent *event)
  {
    if (event->type() != QEvent::Type(QEvent::MouseButtonRelease)) // Mouse Release
      return false;

    return true;
  }

  virtual void onTransition(QEvent *) {}
};

}//////end namespace graph
}//end namespace view

#endif // VIEW_GRAPH_GRAPHVIEWSTATEMACHINE_HPP
