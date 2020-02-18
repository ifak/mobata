#include "qmlnode.hpp"

QmlNode::QmlNode(QQuickItem* parent)
    : QQuickPaintedItem(parent)
{
    QObject::connect(this, &QmlNode::xChanged, this, &QmlNode::repaint);
    QObject::connect(this, &QmlNode::yChanged, this, &QmlNode::repaint);
    QObject::connect(this, &QmlNode::widthChanged, this, &QmlNode::repaint);
    QObject::connect(this, &QmlNode::heightChanged, this, &QmlNode::repaint);

    QObject::connect(this, &QmlNode::uuidChanged, this, &QmlNode::repaint);
    QObject::connect(this, &QmlNode::shapeChanged, this, &QmlNode::repaint);
    QObject::connect(this, &QmlNode::labelChanged, this, &QmlNode::repaint);
    QObject::connect(this, &QmlNode::labelPosChanged, this, &QmlNode::repaint);
    QObject::connect(this, &QmlNode::xLabelChanged, this, &QmlNode::repaint);
    QObject::connect(this, &QmlNode::tokenChanged, this, &QmlNode::repaint);
    QObject::connect(this, &QmlNode::tokenColorChanged, this, &QmlNode::repaint);
    QObject::connect(this, &QmlNode::colorChanged, this, &QmlNode::repaint);
    QObject::connect(this, &QmlNode::borderWidthChanged, this, &QmlNode::repaint);
    QObject::connect(this, &QmlNode::borderColorChanged, this, &QmlNode::repaint);
    QObject::connect(this, &QmlNode::textSizeChanged, this, &QmlNode::repaint);
    QObject::connect(this, &QmlNode::textColorChanged, this, &QmlNode::repaint);
    QObject::connect(this, &QmlNode::textFamilyChanged, this, &QmlNode::repaint);
    QObject::connect(this, &QmlNode::skaleChanged, this, &QmlNode::repaint);
}

QmlNode::~QmlNode(){
}

QUuid QmlNode::uuid() const{
    return this->_uuid;
}
void QmlNode::setUuid(const QUuid &uuid){
    this->_uuid = uuid;
}

int QmlNode::shape() const{
    return this->_shape;
}
void QmlNode::setShape(const int &shape){
    this->_shape = shape;
}

QString QmlNode::label() const{
    return this->_label;
}
void QmlNode::setLabel(const QString &label){
    this->_label = label;
}

QPointF QmlNode::labelPos() const{
    return this->_labelPos;
}
void QmlNode::setLabelPos(const QPointF &labelPos){
    this->_labelPos = labelPos;
}

QString QmlNode::xLabel() const{
    return this->_xLabel;
}
void QmlNode::setXLabel(const QString &xLabel){
    this->_xLabel = xLabel;
}

bool QmlNode::token() const{
    return this->_token;
}
void QmlNode::setToken(const bool &token){
    this->_token = token;
}

QColor QmlNode::tokenColor() const{
    return this->_tokenColor;
}
void QmlNode::setTokenColor(const QColor &tokenColor){
    this->_tokenColor = tokenColor;
}

QColor QmlNode::color() const{
    return this->_color;
}
void QmlNode::setColor(const QColor &color){
    this->_color = color;
}

qreal QmlNode::borderWidth() const{
    return this->_borderWidth;
}
void QmlNode::setBorderWidth(const qreal &borderWidth){
    this->_borderWidth = borderWidth;
}

QColor QmlNode::borderColor() const{
    return this->_borderColor;
}
void QmlNode::setBorderColor(const QColor &borderColor){
    this->_borderColor = borderColor;
}

qreal QmlNode::textSize() const{
    return this->_textSize;
}
void QmlNode::setTextSize(const qreal &textSize){
    this->_textSize = textSize;
}

QColor QmlNode::textColor() const{
    return this->_textColor;
}
void QmlNode::setTextColor(const QColor &textColor){
    this->_textColor = textColor;
}

QString QmlNode::textFamily() const{
    return this->_textFamily;
}
void QmlNode::setTextFamily(const QString &textFamily){
    this->_textFamily = textFamily;
}

qreal QmlNode::skale() const{
    return this->_skale;
}
void QmlNode::setSkale(const qreal &skale){
    this->_skale = skale;
}

qreal QmlNode::skaleX() const{
    return this->_skaleX;
}
void QmlNode::setSkaleX(const qreal &skale){
    this->_skaleX = skale;
}
qreal QmlNode::skaleY() const{
    return this->_skaleY;
}
void QmlNode::setSkaleY(const qreal &skale){
    this->_skaleY = skale;
}
qreal QmlNode::skaleW() const{
    return this->_skaleW;
}
void QmlNode::setSkaleW(const qreal &skale){
    this->_skaleW = skale;
}
qreal QmlNode::skaleH() const{
    return this->_skaleH;
}
void QmlNode::setSkaleH(const qreal &skale){
    this->_skaleH = skale;
}

void QmlNode::applyskale(){
  if(!this->parent()){
    return;
  }
  this->_skale = qvariant_cast<qreal>(this->parent()->property("skale"));
  this->setX(this->_skaleX*this->_skale);
  this->setY(this->_skaleY*this->_skale);
  this->setWidth(this->_skaleW*this->_skale);
  this->setHeight(this->_skaleH*this->_skale);
}

void QmlNode::paint(QPainter* painter){
    this->setFillColor(QColor(Qt::transparent));
    painter->eraseRect(QRectF(0,0,this->width(),this->height()));
    painter->fillRect(QRectF(0,0,this->width(),this->height()),QColor(Qt::transparent));
    this->applyskale();
    QPainterPath path;
    if (this->_shape == 0){
        path.addRect(QRectF(this->_borderWidth, this->_borderWidth,
                            this->width()-2*this->_borderWidth, this->height()-2*this->_borderWidth));
    }else if (this->_shape == 1){
        path.addRoundedRect(QRectF(this->_borderWidth, this->_borderWidth,
                            this->width()-2*this->_borderWidth, this->height()-2*this->_borderWidth),this->height()/4, this->height()/4);
    }else if (this->_shape == 2){
        path.addEllipse(QRectF(this->_borderWidth, this->_borderWidth,
                               this->width()-2*this->_borderWidth, this->height()-2*this->_borderWidth));
    }else if (this->_shape == 3){
        path.addEllipse(QRectF(this->width()/2-2, this->height()/2-2,
                               4,4));
    }else if (this->_shape == 4){
        path.addEllipse(QRectF(this->width()/2-this->height()/2+this->_borderWidth, this->_borderWidth,
                              this->height()-this->_borderWidth*2, this->height()-this->_borderWidth*2));
    }else if (this->_shape == 5){
        path.moveTo(this->_borderWidth, this->height()/2);
        path.lineTo(this->width()/2, this->borderWidth());
        path.lineTo(this->width()-this->_borderWidth, this->height()/2);
        path.lineTo(this->width()/2, this->height()-this->borderWidth());
    }else if (this->_shape == 6){
        path.moveTo(this->width()/5, this->_borderWidth);
        path.lineTo(this->width()-this->_borderWidth, this->_borderWidth);
        path.lineTo(this->width()-this->width()/5, this->height()-this->_borderWidth);
        path.lineTo(this->_borderWidth, this->height()-this->_borderWidth);
        path.lineTo(this->width()/5, this->_borderWidth);
    }else if (this->_shape == 7){
        path.moveTo(this->width()/2,this->_borderWidth);
        path.lineTo(this->width()-this->_borderWidth, this->height()-this->_borderWidth);
        path.lineTo(this->_borderWidth, this->height()-this->_borderWidth);
        path.lineTo(this->width()/2, this->_borderWidth);
    }else if (this->_shape == 8){
        path.moveTo(this->_borderWidth, this->_borderWidth);
        path.lineTo(this->width()-this->_borderWidth, this->_borderWidth);
        path.lineTo(this->width()/2, this->height()-this->_borderWidth);
        path.lineTo(this->_borderWidth, this->_borderWidth);
    }else if (this->_shape == 9){
        path.moveTo(this->width()/5, this->_borderWidth);
        path.lineTo(this->width()-this->width()/5, this->_borderWidth);
        path.lineTo(this->width()-this->_borderWidth, this->height()-this->_borderWidth);
        path.lineTo(this->_borderWidth, this->height()-this->_borderWidth);
        path.lineTo(this->width()/5, this->_borderWidth);
    }else if (this->_shape == 10){
        path.moveTo(this->_borderWidth, this->_borderWidth);
        path.lineTo(this->width()-this->_borderWidth, this->_borderWidth);
        path.lineTo(this->width()-this->width()/5, this->height()-this->_borderWidth);
        path.lineTo(this->width()/5, this->height()-this->_borderWidth);
        path.lineTo(this->_borderWidth, this->_borderWidth);
    }else if (this->_shape == 11){
        path.moveTo(this->width()/3,this->_borderWidth);
        path.lineTo(2*this->width()/3,this->_borderWidth);
        path.lineTo(this->width()-this->_borderWidth,this->height()/3);
        path.lineTo(this->width()-this->_borderWidth,2*this->height()/3);
        path.lineTo(2*this->width()/3,this->height()-this->_borderWidth);
        path.lineTo(this->width()/3,this->height()-this->_borderWidth);
        path.lineTo(this->_borderWidth,2*this->height()/3);
        path.lineTo(this->_borderWidth,this->height()/3);
        path.lineTo(this->width()/3,3);
    }else if (this->_shape == 12){
        path.moveTo(this->width()/4,this->_borderWidth);
        path.lineTo(3*this->width()/4,this->_borderWidth);
        path.lineTo(this->width()-this->_borderWidth,this->height()/2);
        path.lineTo(3*this->width()/4,this->height()-this->_borderWidth);
        path.lineTo(this->width()/4,this->height()-this->_borderWidth);
        path.lineTo(this->_borderWidth,this->height()/2);
        path.lineTo(this->width()/4,this->_borderWidth);
    }else if (this->_shape == 13){
        path.addRect(QRectF(this->_borderWidth, this->_borderWidth,
                            this->width()-2*this->_borderWidth, this->height()-2*this->_borderWidth));
    }else if (this->_shape == 14){
        path.moveTo(this->_borderWidth+this->width()/20,3);
        path.lineTo(this->width()-this->_borderWidth,3);
        path.lineTo(this->width()-this->_borderWidth-this->width()/20,this->_borderWidth+this->height()/20);
        path.lineTo(3,this->_borderWidth+this->height()/20);
        path.lineTo(this->_borderWidth+this->width()/20,3);

        path.moveTo(3,this->_borderWidth+this->height()/20);
        path.lineTo(3,this->height()-this->_borderWidth);
        path.lineTo(this->width()-this->_borderWidth-this->width()/20,this->height()-this->_borderWidth);
        path.lineTo(this->width()-this->_borderWidth-this->width()/20,this->_borderWidth+this->height()/20);
        path.lineTo(3,this->_borderWidth+this->height()/20);

        path.moveTo(this->width()-this->_borderWidth,3);
        path.lineTo(this->width()-this->_borderWidth,this->height()-this->_borderWidth-this->height()/20);
        path.lineTo(this->width()-this->_borderWidth-this->width()/20,this->height()-this->_borderWidth);
        path.lineTo(this->width()-this->_borderWidth-this->width()/20,this->_borderWidth+this->height()/20);
        path.lineTo(this->width()-this->_borderWidth,3);
    }else if (this->_shape == 15){

    }
    QPen pen;
    pen.setColor(this->_borderColor);
    pen.setWidthF(this->_borderWidth);
    painter->setPen(pen);
    painter->setRenderHints(QPainter::Antialiasing, true);
    painter->fillPath(path,this->_color);
    painter->drawPath(path);
    if (this->_token == true){
        QPainterPath tokenpath;
        tokenpath.addEllipse(QRectF((this->_skaleW/2-this->_skaleH/8)*this->_skale, this->_borderWidth*2*this->_skale,
                                    this->_skaleH/4*this->_skale, this->_skaleH/4*this->_skale));
        painter->fillPath(tokenpath, this->_tokenColor);
    }
    QFont font = painter->font();
    font.setPointSize((this->_textSize-2)*this->_skale);
    painter->setFont(font);
    pen.setColor(this->_textColor);
    painter->setPen(pen);
    painter->drawText(QRectF(0,0,this->width(),this->height()),Qt::AlignVCenter+Qt::AlignHCenter,this->_xLabel);
}
