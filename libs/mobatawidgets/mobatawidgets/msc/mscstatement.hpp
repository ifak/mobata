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
#ifndef VIEW_MSC_KMSCSTATEMENT_HPP
#define VIEW_MSC_KMSCSTATEMENT_HPP

#include "../mobatawidgets_global.hpp"

#include "../base/roundrect.hpp"
#include "mscsequencestep.hpp"

#include "types.hpp"

namespace view {
namespace msc {

class MOBATAWIDGETSSHARED_EXPORT KMscStatement
    : public base::RoundRect,
    public MscSequenceStep
{
public:
  KMscStatement(const QString& statement,
                KMscComponent const* mscComponent,
                QGraphicsItem* parentItem = 0);

  KMscStatement(const QString& statement,
                KMscComponent const* mscComponent,
                const view::graph::ArcOptions& arcOptions,
                QGraphicsItem* parentItem = 0);

  virtual ~KMscStatement();

  virtual qreal updateGeometry(const qreal bottomSceneY,
                               const qreal marginSpace);

public:
  const QString& statement() const;

public:
  virtual KMscComponent const* mscComponent() const;

public:
  void paint(QPainter *painter,
             const QStyleOptionGraphicsItem *option,
             QWidget *widget = 0);
  QRectF boundingRect() const;

private:
  Q_DISABLE_COPY(KMscStatement)
  class Private;
  Private* _d;
};

} // namespace msc
} // namespace view

#endif // VIEW_MSC_KMSCSTATEMENT_HPP
