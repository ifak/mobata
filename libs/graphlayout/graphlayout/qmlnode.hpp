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

#ifndef QMLNODE_HPP
#define QMLNODE_HPP

#include <QQuickPaintedItem>
#include <QPen>
#include <QBrush>
#include <QPainter>
#include <QColor>
#include <QUuid>

class QmlNode : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid NOTIFY uuidChanged)
    Q_PROPERTY(int shape READ shape WRITE setShape NOTIFY shapeChanged)
    Q_PROPERTY(QString label READ label WRITE setLabel NOTIFY labelChanged)
    Q_PROPERTY(QPointF labelPos READ labelPos WRITE setLabelPos NOTIFY labelPosChanged)
    Q_PROPERTY(QString xLabel READ xLabel WRITE setXLabel NOTIFY xLabelChanged)
    Q_PROPERTY(bool token READ token WRITE setToken NOTIFY tokenChanged)
    Q_PROPERTY(QColor tokenColor READ tokenColor WRITE setTokenColor NOTIFY tokenColorChanged)
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(qreal borderWidth READ borderWidth WRITE setBorderWidth NOTIFY borderWidthChanged)
    Q_PROPERTY(QColor borderColor READ borderColor WRITE setBorderColor NOTIFY borderColorChanged)
    Q_PROPERTY(qreal textSize READ textSize WRITE setTextSize NOTIFY textSizeChanged)
    Q_PROPERTY(QColor textColor READ textColor WRITE setTextColor NOTIFY textColorChanged)
    Q_PROPERTY(QString textFamily READ textFamily WRITE setTextFamily NOTIFY textFamilyChanged)

    Q_PROPERTY(qreal skale READ skale WRITE setSkale NOTIFY skaleChanged)
    Q_PROPERTY(qreal skaleX READ skaleX WRITE setSkaleX NOTIFY skaleXChanged)
    Q_PROPERTY(qreal skaleY READ skaleY WRITE setSkaleY NOTIFY skaleYChanged)
    Q_PROPERTY(qreal skaleW READ skaleW WRITE setSkaleW NOTIFY skaleWChanged)
    Q_PROPERTY(qreal skaleH READ skaleH WRITE setSkaleH NOTIFY skaleHChanged)

public:
    QmlNode(QQuickItem* parent = nullptr);
    ~QmlNode();
    void paint(QPainter* painter);

    QUuid uuid() const;
    void setUuid(const QUuid &uuid);

    int shape() const;
    void setShape(const int &shape);

    QString label() const;
    void setLabel(const QString &label);

    QPointF labelPos() const;
    void setLabelPos(const QPointF &labelPos);

    QString xLabel() const;
    void setXLabel(const QString &xLabel);

    bool token() const;
    void setToken(const bool &token);

    QColor tokenColor() const;
    void setTokenColor(const QColor &tokenColor);

    QColor color() const;
    void setColor(const QColor &color);

    qreal borderWidth() const;
    void setBorderWidth(const qreal &borderWidth);

    QColor borderColor() const;
    void setBorderColor(const QColor &borderColor);

    qreal textSize() const;
    void setTextSize(const qreal &textSize);

    QColor textColor() const;
    void setTextColor(const QColor &textColor);

    QString textFamily() const;
    void setTextFamily(const QString &textFamily);

    qreal skale() const;
    void setSkale(const qreal &skale);

    qreal skaleX() const;
    void setSkaleX(const qreal &skale);
    qreal skaleY() const;
    void setSkaleY(const qreal &skale);
    qreal skaleW() const;
    void setSkaleW(const qreal &skale);
    qreal skaleH() const;
    void setSkaleH(const qreal &skale);

signals:
    void nodeClicked(const QUuid& uuid);

    void uuidChanged();
    void shapeChanged();
    void labelChanged();
    void labelPosChanged();
    void xLabelChanged();
    void tokenChanged();
    void tokenColorChanged();
    void colorChanged();
    void borderWidthChanged();
    void borderColorChanged();
    void textSizeChanged();
    void textColorChanged();
    void textFamilyChanged();
    void skaleChanged();
    void skaleXChanged();
    void skaleYChanged();
    void skaleWChanged();
    void skaleHChanged();

public slots:
    void repaint(){
        this->update(QRect(0,0,this->width(),this->height()));
    }
    void applyskale();
private:
    QUuid _uuid;
    int _shape;
    QString _label = "";
    QPointF _labelPos;
    QString _xLabel = "";
    bool _token = false;
    QColor _tokenColor = QColor("black");
    QColor _color = QColor("white");
    qreal _borderWidth = 3.0;
    QColor _borderColor = QColor("black");
    qreal _textSize = 12;
    QColor _textColor = QColor("black");
    QString _textFamily;
    qreal _skale = 1.0;
    qreal _skaleX = 0;
    qreal _skaleY = 0;
    qreal _skaleW = 0;
    qreal _skaleH = 0;
};

#endif // QMLNODE_HPP
