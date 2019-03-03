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

#include "qmledge.hpp"

QmlEdge::QmlEdge(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
    QObject::connect(this, &QmlEdge::xChanged, this, &QmlEdge::repaint);
    QObject::connect(this, &QmlEdge::yChanged, this, &QmlEdge::repaint);
    QObject::connect(this, &QmlEdge::widthChanged, this, &QmlEdge::repaint);
    QObject::connect(this, &QmlEdge::heightChanged, this, &QmlEdge::repaint);

    QObject::connect(this, &QmlEdge::uuidChanged, this, &QmlEdge::repaint);
    QObject::connect(this, &QmlEdge::labelChanged, this, &QmlEdge::repaint);
    QObject::connect(this, &QmlEdge::lineColorChanged, this, &QmlEdge::repaint);
    QObject::connect(this, &QmlEdge::infoBoxChanged, this, &QmlEdge::repaint);
    QObject::connect(this, &QmlEdge::pointsChanged, this, &QmlEdge::repaint);
    QObject::connect(this, &QmlEdge::labelPosChanged, this, &QmlEdge::repaint);
    QObject::connect(this, &QmlEdge::typeChanged, this, &QmlEdge::repaint);
    QObject::connect(this, &QmlEdge::splinesChanged, this, &QmlEdge::repaint);
    QObject::connect(this, &QmlEdge::lineWidthChanged, this, &QmlEdge::repaint);
    QObject::connect(this, &QmlEdge::arrowSizeChanged, this, &QmlEdge::repaint);
    QObject::connect(this, &QmlEdge::textSizeChanged, this, &QmlEdge::repaint);
    QObject::connect(this, &QmlEdge::textColorChanged, this, &QmlEdge::repaint);
    QObject::connect(this, &QmlEdge::textFamilyChanged, this, &QmlEdge::repaint);

    QObject::connect(this, &QmlEdge::skaleChanged, this, &QmlEdge::repaint);
}
QmlEdge::~QmlEdge(){
  delete this->_currentPath;
}
QUuid QmlEdge::uuid() const{
    return this->_uuid;
}
void QmlEdge::setUuid(const QUuid &uuid){
    this->_uuid = uuid;
}

QString QmlEdge::label() const{
    return this->_label;
}
void QmlEdge::setLabel(const QString &label){
    this->_label = label;
}

QColor QmlEdge::lineColor() const{
    return this->_lineColor;
}
void QmlEdge::setLineColor(const QColor &lineColor){
    this->_lineColor = lineColor;
}

QList<QPointF> QmlEdge::points() const{
    return this->_points;
}
void QmlEdge::setPoints(const QList<QPointF> &list){
    this->_points = list;
}

QPointF QmlEdge::labelPos() const{
    return this->_labelPos;
}
void QmlEdge::setLabelPos(const QPointF &labelPos){
    this->_labelPos = labelPos;
}

int QmlEdge::type() const{
    return this->_type;
}
void QmlEdge::setType(const int &type){
    this->_type = type;
}

int QmlEdge::splines() const{
    return this->_splines;
}
void QmlEdge::setSplines(const int &splines){
    this->_splines = splines;
}

qreal QmlEdge::lineWidth() const{
    return this->_lineWidth;
}
void QmlEdge::setLineWidth(const qreal &lineWidth){
    this->_lineWidth = lineWidth;
}

qreal QmlEdge::arrowSize() const{
    return this->_arrowSize;
}
void QmlEdge::setArrowSize(const qreal &arrowSize){
    this->_arrowSize = arrowSize;
}

qreal QmlEdge::textSize() const{
    return this->_textSize;
}
void QmlEdge::setTextSize(const qreal &textSize){
    this->_textSize = textSize;
}

QColor QmlEdge::textColor() const{
    return this->_textColor;
}
void QmlEdge::setTextColor(const QColor &textColor){
    this->_textColor = textColor;
}

QString QmlEdge::textFamily() const{
    return this->_textFamily;
}
void QmlEdge::setTextFamily(const QString &textFamily){
    this->_textFamily = textFamily;
}

qreal QmlEdge::skale() const{
    return this->_skale;
}
void QmlEdge::setSkale(const qreal &skale){
    this->_skale = skale;
}

qreal QmlEdge::skaleX() const{
    return this->_skaleX;
}
void QmlEdge::setSkaleX(const qreal &skale){
    this->_skaleX = skale;
}
qreal QmlEdge::skaleY() const{
    return this->_skaleY;
}
void QmlEdge::setSkaleY(const qreal &skale){
    this->_skaleY = skale;
}
qreal QmlEdge::skaleW() const{
    return this->_skaleW;
}
void QmlEdge::setSkaleW(const qreal &skale){
    this->_skaleW = skale;
}
qreal QmlEdge::skaleH() const{
    return this->_skaleH;
}
void QmlEdge::setSkaleH(const qreal &skale){
    this->_skaleH = skale;
}

void QmlEdge::applyskale(){
  this->setX(this->skaleX()*this->skale());
  this->setY(this->skaleY()*this->skale());
  this->setWidth(this->skaleW()*this->skale());
  this->setHeight(this->skaleH()*this->skale());
}

bool QmlEdge::containsPos(QPointF pos){
  return this->_currentPath->intersects(QRectF(pos.x()-2, pos.y()-2,4,4));
}
bool QmlEdge::containsPos(qreal posX, qreal posY){
  return this->containsPos(QPointF(posX,posY));
}

void QmlEdge::paint(QPainter* painter){
    this->applyskale();
    if(this->_points.length()<2){
        return;
    }
    qreal angle1 = qAtan2(this->_points.last().y() - this->_points[this->points().length()-2].y(), this->_points.last().x() - this->_points[this->points().length()-2].x()) ;
    qreal angle2 = qAtan2(this->_points.first().y() - this->_points[1].y(), this->_points.first().x() - this->_points[1].x()) ;
    delete this->_currentPath;
    this->_currentPath = new QPainterPath();

    if (this->_splines == 2 && (this->_points.length()-2)%3 == 0 && this->_points.length() != 2){
      this->_currentPath->moveTo((this->_points.first() - QPointF(this->_skaleX,this->_skaleY))*this->_skale);
      for(int i = 1; i < this->_points.length()-3; i=i+3){
        this->_currentPath->cubicTo((this->_points.at(i) - QPointF(this->_skaleX,this->_skaleY))*this->_skale,
                     (this->_points.at(i+1) - QPointF(this->_skaleX,this->_skaleY))*this->_skale,
                     (this->_points.at(i+2) - QPointF(this->_skaleX,this->_skaleY))*this->_skale);
      }
      this->_currentPath->lineTo((this->_points.last() - QPointF(this->_skaleX,this->_skaleY))*this->_skale);
    }else{
      for (QPointF point : this->_points){
          if(point == this->_points.first()){
              this->_currentPath->moveTo((this->_points.first() - QPointF(this->_skaleX,this->_skaleY))*this->_skale);
          }else{
              this->_currentPath->lineTo((point - QPointF(this->_skaleX,this->_skaleY))*this->_skale);
          }
      }
    }
    if (this->_type == 0 || this->_type == 2){
        this->_currentPath->moveTo((this->_points.last() - QPointF(this->_skaleX,this->_skaleY))*this->_skale);
        this->_currentPath->lineTo((this->_points.last().x() - this->_skaleX) * this->_skale - this->_arrowSize * qCos(angle1-M_PI/6),
                    (this->_points.last().y() - this->_skaleY) * this->_skale - this->_arrowSize * qSin(angle1-M_PI/6));
        this->_currentPath->moveTo((this->_points.last() - QPointF(this->_skaleX,this->_skaleY))*this->_skale);
        this->_currentPath->lineTo((this->_points.last().x() - this->_skaleX) * this->_skale - this->_arrowSize * qCos(angle1+M_PI/6),
                    (this->_points.last().y() - this->_skaleY) * this->_skale - this->_arrowSize * qSin(angle1+M_PI/6));
    }
    if (this->_type == 4){
        this->_currentPath->moveTo(this->_points.last() - QPointF(this->_skaleX,this->_skaleY));
        QRectF rect((this->_points.last().x()-this->_skaleX) * this->_skale -this->arrowSize()/2,
                    this->_points.last().y() * this->skale(),this->_arrowSize, this->_arrowSize);
        this->_currentPath->addRect(rect);
    }
    if (this->_type == 3 || this->_type == 2){
        this->_currentPath->moveTo((this->_points.first() - QPointF(this->_skaleX,this->_skaleY))*this->_skale);
        this->_currentPath->lineTo((this->_points.last().x() - this->_skaleX) * this->_skale - this->_arrowSize * qCos(angle2-M_PI/6),
                    (this->_points.last().y() - this->_skaleY) * this->_skale - this->_arrowSize * qSin(angle2-M_PI/6));
        this->_currentPath->moveTo((this->_points.first() - QPointF(this->_skaleX,this->_skaleY))*this->_skale);
        this->_currentPath->lineTo((this->_points.last().x() - this->_skaleX) * this->_skale - this->_arrowSize * qCos(angle2+M_PI/6),
                    (this->_points.last().y() - this->_skaleY) * this->_skale - this->_arrowSize * qSin(angle2+M_PI/6));
    }

    QPen pen;
    pen.setColor(this->_lineColor);
    pen.setWidthF(this->_lineWidth);
    painter->setPen(pen);
    painter->setRenderHints(QPainter::Antialiasing, true);
    //painter->fillPath(*this->_currentPath,QColor("green"));
    painter->drawPath(*this->_currentPath);
}
