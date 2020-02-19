#include "mscfragmentregion.hpp"

#include "mscfragment.hpp"
#include "msccomponent.hpp"
#include "msccomponentlifeline.hpp"

#include "../base/textitem.hpp"

#include <QPen>
#include <QDebug>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace msc{

class KMscFragmentRegion::Private
{
  friend class KMscFragmentRegion;

  Private(const QString& condition)
    : _condition(condition),
      _conditionItem(0),
      _heightOffset(20)
  {}

  QString         _condition;
  base::TextItem* _conditionItem;
  int             _heightOffset;
};

KMscFragmentRegion::KMscFragmentRegion(KMscFragment* parent,
                                       const QString& condition)
  : KMscSequence(parent), _d(new Private(condition))
{
  this->setPen(QPen(Qt::NoPen));

  QFont textFont;
  textFont.setBold(true);

  this->_d->_conditionItem=new base::TextItem(QStringLiteral("[")
                                              +this->_d->_condition
                                              +QStringLiteral("]"),
                                              this);
  this->_d->_conditionItem->setFont(textFont);
}

KMscFragmentRegion::~KMscFragmentRegion()
{
  delete this->_d;
}

const QString& KMscFragmentRegion::condition() const
{
  return this->_d->_condition;
}

qreal KMscFragmentRegion::updateGeometry(const qreal bottomSceneY,
                                         const qreal marginSpace)
{
  QRectF textRect=this->_d->_conditionItem->boundingRect();

  qreal currBottomSceneY=bottomSceneY + textRect.height();
  currBottomSceneY=KMscSequence::updateGeometry(currBottomSceneY,
                                                marginSpace);

  this->_d->_conditionItem->setPos(0,
                                   bottomSceneY+textRect.height());

  //calculation children-rect
  QRectF childrenRect=this->childrenBoundingRect();
  childrenRect.setHeight(childrenRect.height()+marginSpace);
  this->setRect(childrenRect);

  // re-positioning of condition-item
  qreal x=childrenRect.x() + childrenRect.width()/2 - textRect.width()/2;
  qreal y=bottomSceneY + textRect.height();
  this->_d->_conditionItem->setPos(this->mapFromScene(x, y));

  if((bottomSceneY + this->rect().height()) > currBottomSceneY)
    currBottomSceneY = bottomSceneY + this->rect().height();

  ///redraw hide component lines
  foreach(KMscComponent const* mscComponent,
          this->componentLines().keys())
  {
    QGraphicsPathItem* compLine=this->componentLines().value(mscComponent);
    Q_ASSERT(compLine);

    if(mscComponent->lifeline())
      compLine->setPen(mscComponent->lifeline()->pen());
    else
      compLine->setPen(mscComponent->pen());

    QPainterPath compLinePath;
    compLinePath.moveTo(mscComponent->pos().x(),
                        this->rect().y());
    compLinePath.lineTo(mscComponent->pos().x(),
                        this->rect().y()
                        + this->rect().height());
    compLine->setPath(compLinePath);
  }

  return currBottomSceneY;
}

}//////end namespace msc
}/// end namespace view
