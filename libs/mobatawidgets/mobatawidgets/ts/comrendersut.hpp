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
#ifndef VIEW_TS_COMRENDERSUT_HPP
#define VIEW_TS_COMRENDERSUT_HPP

#include "../mobatawidgets_global.hpp"

#include "types.hpp"

#include <mobata/model/ts/testcaseitem.hpp>

#include "sutscene.hpp"

namespace view {
namespace ts {

class MOBATAWIDGETSSHARED_EXPORT ComRenderSut
{
public:
  ComRenderSut(SutScene* sutScene,
               model::ts::SutItem const* sutItem,
               const NodeOptions& compOptions = defaultComponentOptions(),
               const NodeOptions& portOptions = defaultPortOptions(),
               const ArcOptions& linkOptions = defaultLinkOptions(),
               const QBrush& sutBoxBrushOption = defaultSutBoxBrushOption(),
               const qreal compMarginSpace = defaultCompMarginSpace(),
               const qreal sutBoxMarginSpace = defaultSutBoxMarginSpace(),
               const qreal sutBoxRadius = defaultSutBoxRadius());
  virtual ~ComRenderSut();

public:
  bool execute(QString* errorMessage);
  static NodeOptions defaultComponentOptions()
  {
      return NodeOptions().setSize(QSizeF(100,75)).setColor(Qt::white).setPen(QPen(Qt::darkBlue, 3));
  }
  static NodeOptions defaultPortOptions()
  {
      return NodeOptions().setSize(QSizeF(15,15)).setColor(Qt::white).setPen(QPen(Qt::darkBlue, 3));
  }
  static ArcOptions defaultLinkOptions()
  {
      return ArcOptions().setPen(QPen(Qt::darkBlue, 3));
  }
  static QBrush defaultSutBoxBrushOption()
  {
      return QBrush(Qt::white);
  }
  static qreal defaultCompMarginSpace()
  {
      return 50;
  }
  static qreal defaultSutBoxMarginSpace()
  {
      return 25;
  }
  static qreal defaultSutBoxRadius()
  {
      return 15;
  }

private:
  Q_DISABLE_COPY(ComRenderSut)
  class Private;
  Private* _d;
};

} // namespace ts
} // namespace view

#endif // VIEW_TS_COMRENDERSUT_HPP
