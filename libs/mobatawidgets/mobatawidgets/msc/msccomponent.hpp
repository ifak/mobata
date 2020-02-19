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
#ifndef VIEW_MSC_MSCCOMPONENT_HPP
#define VIEW_MSC_MSCCOMPONENT_HPP

#include "../mobatawidgets_global.hpp"

#include <QGraphicsRectItem>
#include <mobata/prop/uuidproperty.hpp>
#include <mobata/prop/referenceidproperty.hpp>
#include <mobata/prop/nameproperty.hpp>

namespace view{
namespace msc{

class KMscAnchor;
class KMscComponentLifeline;

class MOBATAWIDGETSSHARED_EXPORT KMscComponent
    : public QGraphicsRectItem,
    public prop::UuidProperty,
    public prop::ReferenceIdProperty,
    public prop::NameProperty
{
public:
  KMscComponent(const QString& compName,
                const QUuid& referenceId,
                QGraphicsItem * parent=0);

  KMscComponent(const QString& compName,
                const QUuid& referenceId,
                const QFont& compNameFont,
                const QColor& compNameColor,
                const QSizeF& compBoxSize,
                const QColor &compBoxColor,
                const QPen& compBorderPen,
                const QPen &lifeLinePen,
                QGraphicsItem * parent=0);

  virtual ~KMscComponent();

public:
  KMscComponentLifeline const*  lifeline() const;
  qreal                         lifelineEndSceneY() const;
  void                          setLifelineEndSceneY(const qreal endLifelineSceneY);
  KMscAnchor*                   addAnchor();
  QPointF                       scenePos() const;
  qreal                         stepSize() const;

protected:
  virtual QVariant  itemChange(GraphicsItemChange change,
                               const QVariant &value);

protected:
  KMscComponentLifeline*  lifeline();
  void                    setLifeline(KMscComponentLifeline* lifeline);

private:
  Q_DISABLE_COPY(KMscComponent)
  class Private;
  Private* _d;
};

}//////end namespace msc
}/// end namespace view

#endif /// VIEW_MSC_MSCCOMPONENT_HPP
