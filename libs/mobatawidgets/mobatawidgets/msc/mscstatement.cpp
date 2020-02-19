#include "mscstatement.hpp"

#include "msccomponent.hpp"

#include <QGraphicsTextItem>
#include <QPainter>

#include <mobata/memory_leak_start.hpp>

namespace view {
namespace msc {

class KMscStatement::Private
{
  friend class KMscStatement;

  QString               _statement;
  KMscComponent const*  _mscComponent;
  QGraphicsTextItem*    _statementItem;

  Private(const QString& statement,
          KMscComponent const* mscComponent)
    : _statement(statement),
      _mscComponent(mscComponent),
      _statementItem(0)
  {}
};

KMscStatement::KMscStatement(const QString& statement,
                             KMscComponent const* mscComponent,
                             QGraphicsItem* parentItem)
  : base::RoundRect(10, parentItem),
    MscSequenceStep(this),
    _d(new Private(statement, mscComponent))
{
  this->_d->_statementItem=new QGraphicsTextItem(this->_d->_statement,
                                                 this);
  this->_d->_statementItem->setPos(0,0);
  this->setPen(QPen(Qt::black, 3));
  this->setBrush(QBrush(Qt::white));
}

KMscStatement::KMscStatement(const QString& statement,
                             KMscComponent const* mscComponent,
                             const view::graph::ArcOptions& arcOptions,
                             QGraphicsItem* parentItem)
  : base::RoundRect(10, parentItem),
    MscSequenceStep(this),
    _d(new Private(statement, mscComponent))
{
  this->_d->_statementItem=new QGraphicsTextItem(this->_d->_statement,
                                                 this);
  this->_d->_statementItem->setFont(arcOptions.textFont());
  this->_d->_statementItem->setDefaultTextColor(arcOptions.textColor());
  this->_d->_statementItem->setPos(0,0);
  this->setPen(arcOptions.pen());
  this->setBrush(QBrush(Qt::white));
}

KMscStatement::~KMscStatement()
{
  delete this->_d;
}

qreal KMscStatement::updateGeometry(const qreal bottomSceneY,
                                    const qreal marginSpace)
{
  Q_ASSERT(this->_d->_mscComponent);

  qreal currentBottomSceneY=bottomSceneY;

  QRectF rect=this->boundingRect();
  QPointF compPos=this->_d->_mscComponent->pos();

  qreal x=compPos.x() - rect.width()/2;
  qreal y=currentBottomSceneY + rect.height();
  this->setPos(x, y);

  currentBottomSceneY=currentBottomSceneY + rect.height();

  return currentBottomSceneY + marginSpace;
}

const QString& KMscStatement::statement() const
{
  return this->_d->_statement;
}

KMscComponent const* KMscStatement::mscComponent() const
{
  return this->_d->_mscComponent;
}

void KMscStatement::paint(QPainter *painter,
                          const QStyleOptionGraphicsItem *option,
                          QWidget *widget)
{
  this->setRect(this->boundingRect());
  base::RoundRect::paint(painter, option, widget);

  this->_d->_statementItem->setPos(0,0);

  return;
}

QRectF	KMscStatement::boundingRect() const
{
  return this->_d->_statementItem->boundingRect();
}

} // namespace msc
} // namespace view

