#include "textitem.hpp"

#include <QTextCursor>
#include <QTextDocument>
#include <QSyntaxHighlighter>

#include "functors.hpp"

#include <QDebug>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace base{

class TextItem::Private
{
  friend class TextItem;

public:
  Private()	:_associationLine(0), _textHighlighter(0)
  {}
  ~Private()
  {}
private:
  QGraphicsLineItem*	_associationLine;
  QSyntaxHighlighter*	_textHighlighter;
};

TextItem::TextItem(const QString& text, QGraphicsItem * parentItem)
  :	QGraphicsTextItem(text, parentItem)
{
  this->_d=new Private();

  this->setFlag(QGraphicsItem::ItemIsMovable);
  this->setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);

  if(parentItem)
  {
    QPointF centerScenePos=this->scenePos()+this->boundingRect().center();
    this->_d->_associationLine=new QGraphicsLineItem(QLineF(this->mapFromScene(parentItem->scenePos()),
                                                            this->mapFromScene(centerScenePos)),
                                                     this);
    this->_d->_associationLine->setPen(QPen(Qt::black, 2, Qt::DashDotLine));
    this->_d->_associationLine->setFlags(QGraphicsItem::ItemStacksBehindParent);
    this->_d->_associationLine->hide();
  }
}

TextItem::~TextItem()
{
  delete this->_d;
}

int	TextItem::type() const
{
  return Type;
}

void TextItem::setSyntaxHighlighter(QSyntaxHighlighter* newTextHighlighter)
{
  if(this->_d->_textHighlighter)
    delete this->_d->_textHighlighter;

  this->_d->_textHighlighter=newTextHighlighter;
}

void TextItem::showAssociationLine(bool value)
{
  if(value)
  {
    QRectF boundingRect=this->boundingRect();
    QLineF associationLine=this->_d->_associationLine->line();
    if(boundingRect.contains(associationLine.p1())
       && boundingRect.contains(associationLine.p2()))
      this->_d->_associationLine->hide();
    else
      this->_d->_associationLine->show();
  }
  else
    this->_d->_associationLine->hide();

  return;
}

void	TextItem::focusOutEvent(QFocusEvent * event)
{
  this->setTextInteractionFlags(Qt::NoTextInteraction);

  QTextCursor currentCursor=this->textCursor();
  currentCursor.clearSelection();
  this->setTextCursor(currentCursor);

  if(this->document()->isModified())
    emit changed(true);

  this->document()->setModified(false);

  return QGraphicsTextItem::focusOutEvent(event);
}

void	TextItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{
  this->setTextInteractionFlags(Qt::TextEditorInteraction);
  this->setFocus();

  return QGraphicsTextItem::mouseDoubleClickEvent(event);
}

QVariant	TextItem::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant& value)
{
  if (change == QGraphicsItem::ItemPositionChange)
  {
    if((this->scene() && this->_d->_associationLine))
    {
      QPointF sourcePoint=this->mapFromScene(this->scenePos()+this->boundingRect().center());
      QPointF targetPoint=this->mapFromScene(this->parentItem()->scenePos());

      QRectF sourceRect=this->boundingRect();
      QRectF targetRect=this->parentItem()->boundingRect();
      targetRect.translate(targetPoint);

      sourcePoint=calcIntercectPoint(QLineF(sourcePoint, targetPoint), sourceRect);
      targetPoint=calcIntercectPoint(QLineF(sourcePoint, targetPoint), targetRect);

      this->_d->_associationLine->setLine(QLineF(sourcePoint, targetPoint));
      if(sourcePoint==QPointF() || targetPoint==QPointF())
        this->_d->_associationLine->hide();
      else
        this->_d->_associationLine->show();
    }
  }

  return QGraphicsItem::itemChange(change, value);
}

}////end namespace graph
}//end namespace view
