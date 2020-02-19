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
#ifndef VIEW_TS_COMRENDERTESTSYSTEM_HPP
#define VIEW_TS_COMRENDERTESTSYSTEM_HPP

#include "../mobatawidgets_global.hpp"

#include "types.hpp"

#include <mobata/model/ts/testsystemitem.hpp>

#include "testsystemscene.hpp"
#include "comrendersut.hpp"

namespace view {
namespace ts {

class ComRenderTestSystem
{
public:
  ComRenderTestSystem(TestSystemScene* testSystemScene,
                      model::ts::TestSystemItem const* testSystemItem,
                      const NodeOptions& sutCompOptions = ComRenderSut::defaultComponentOptions(),
                      const NodeOptions& sutPortOptions = ComRenderSut::defaultPortOptions(),
                      const ArcOptions& sutLinkOptions = ComRenderSut::defaultLinkOptions(),
                      const QBrush& sutBoxBrushOption = ComRenderSut::defaultSutBoxBrushOption(),
                      const qreal sutCompMarginSpace = ComRenderSut::defaultCompMarginSpace(),
                      const qreal sutBoxMarginSpace = ComRenderSut::defaultSutBoxMarginSpace(),
                      const qreal sutBoxRadius = ComRenderSut::defaultSutBoxRadius(),
                      const NodeOptions& testSystemCompOptions = defaultTestSystemCompOptions(),
                      const NodeOptions& testSystemPortOptions = defaultTestSystemPortOptions(),
                      const ArcOptions& testSystemLinkOptions = defaultTestSystemLinkOptions(),
                      const qreal spaceToSutBox = defaultSpaceToSutBox(),
                      const NodeOptions& testSystemBoxOptions = defaultTestSystemBoxOptions(),
                      const qreal testSystemBoxMarginSpace = defaultTestSystemBoxMarginSpace(),
                      const qreal testSystemBoxRadius = defaultTestSystemBoxRadius());
  virtual ~ComRenderTestSystem();

public:
  bool execute(QString* errorMessage);
  static NodeOptions defaultTestSystemCompOptions()
  {
      return NodeOptions().setSize(QSizeF(100,75)).setColor(Qt::white).setPen(QPen(Qt::darkRed, 3));
  }
  static NodeOptions defaultTestSystemPortOptions()
  {
      return NodeOptions().setSize(QSizeF(15,15)).setColor(Qt::white).setPen(QPen(Qt::darkRed, 3));
  }
  static ArcOptions defaultTestSystemLinkOptions()
  {
      return ArcOptions().setPen(QPen(Qt::darkRed, 3));
  }
  static qreal defaultSpaceToSutBox()
  {
      return 50;
  }
  static NodeOptions defaultTestSystemBoxOptions()
  {
      return NodeOptions().setColor(Qt::darkBlue).setPen(QPen(Qt::white, 3)).setTextColor(Qt::white).setTextFont(QFont(QStringLiteral("Times"), 12, QFont::Bold));
  }
  static qreal defaultTestSystemBoxMarginSpace()
  {
      return 25;
  }
  static qreal defaultTestSystemBoxRadius()
  {
      return 15;
  }

private:
  Q_DISABLE_COPY(ComRenderTestSystem)
  class Private;
  Private* _d;
};

} // namespace ts
} // namespace view

#endif // VIEW_TS_COMRENDERTESTSYSTEM_HPP
