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
#ifndef VIEW_MSC_MSCSEQUENCESTEP_HPP
#define VIEW_MSC_MSCSEQUENCESTEP_HPP

#include "../mobatawidgets_global.hpp"

#include <mobata/prop/referenceidproperty.hpp>

#include <QGraphicsItem>

namespace view {
namespace msc {

class KMscScene;

class MOBATAWIDGETSSHARED_EXPORT MscSequenceStep
    : public prop::ReferenceIdProperty
{
public:
  MscSequenceStep(QGraphicsItem* parent);
  virtual ~MscSequenceStep();

public:
  virtual qreal updateGeometry(const qreal bottomSceneY,
                               const qreal marginSpace) =0;

public:
  QRectF boundingRect() const;

protected:
  KMscScene* mscScene();

private:
  Q_DISABLE_COPY(MscSequenceStep)
  class Private;
  Private* _d;
};

} // namespace msc
} // namespace view

#endif // VIEW_MSC_MSCSEQUENCESTEP_HPP
