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
#ifndef QMLEDGE_HPP
#define QMLEDGE_HPP

#include <QQuickPaintedItem>
#include <QPen>
#include <QPainter>
#include <QColor>
#include <QUuid>
#include <QtMath>


class QmlEdge : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid NOTIFY uuidChanged)
    Q_PROPERTY(QString label READ label WRITE setLabel NOTIFY labelChanged)
    Q_PROPERTY(QColor lineColor READ lineColor WRITE setLineColor NOTIFY lineColorChanged)
    Q_PROPERTY(QList<QPointF> points READ points WRITE setPoints NOTIFY pointsChanged)
    Q_PROPERTY(QPointF labelPos READ labelPos WRITE setLabelPos NOTIFY labelPosChanged)
    Q_PROPERTY(int type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(int splines READ splines WRITE setSplines NOTIFY splinesChanged)
    Q_PROPERTY(qreal lineWidth READ lineWidth WRITE setLineWidth NOTIFY lineWidthChanged)
    Q_PROPERTY(qreal arrowSize READ arrowSize WRITE setArrowSize NOTIFY arrowSizeChanged)
    Q_PROPERTY(qreal textSize READ textSize WRITE setTextSize NOTIFY textSizeChanged)
    Q_PROPERTY(QColor textColor READ textColor WRITE setTextColor NOTIFY textColorChanged)
    Q_PROPERTY(QString textFamily READ textFamily WRITE setTextFamily NOTIFY textFamilyChanged)

    Q_PROPERTY(qreal skale READ skale WRITE setSkale NOTIFY skaleChanged)
    Q_PROPERTY(qreal skaleX READ skaleX WRITE setSkaleX NOTIFY skaleXChanged)
    Q_PROPERTY(qreal skaleY READ skaleY WRITE setSkaleY NOTIFY skaleYChanged)
    Q_PROPERTY(qreal skaleW READ skaleW WRITE setSkaleW NOTIFY skaleWChanged)
    Q_PROPERTY(qreal skaleH READ skaleH WRITE setSkaleH NOTIFY skaleHChanged)

public:
    QmlEdge(QQuickItem* parent = nullptr);
    ~QmlEdge();
    void paint(QPainter* painter);
    //READ / WRITE Properties
    QUuid uuid() const;
    void setUuid(const QUuid &uuid);

    QString label() const;
    void setLabel(const QString &label);

    QColor lineColor() const;
    void setLineColor(const QColor &lineColor);

    QList<QPointF> points() const;
    void setPoints(const QList<QPointF> &list);

    QPointF labelPos() const;
    void setLabelPos(const QPointF &labelPos);

    int type() const;
    void setType(const int &type);

    int splines() const;
    void setSplines(const int &splines);

    qreal lineWidth() const;
    void setLineWidth(const qreal &lineWidth);

    qreal arrowSize() const;
    void setArrowSize(const qreal &arrowSize);

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
    void edgeClicked(const QUuid& uuid);
    //PropertySignals
    void uuidChanged();
    void labelChanged();
    void lineColorChanged();
    void infoBoxChanged();
    void pointsChanged();
    void labelPosChanged();
    void typeChanged();
    void splinesChanged();
    void lineWidthChanged();
    void arrowSizeChanged();
    void textSizeChanged();
    void textColorChanged();
    void textFamilyChanged();
    void skaleChanged();
    void skaleXChanged();
    void skaleYChanged();
    void skaleWChanged();
    void skaleHChanged();

    void highlightChanged(QVariant ok);

public slots:
    void repaint(){
        this->update(QRect(this->x(),this->y(),this->width(),this->height()));
    }
    void applyskale();
    bool containsPos(QPointF pos);
    bool containsPos(qreal posX, qreal posY);
private:
    QUuid _uuid;
    QString _label = "";
    QColor _lineColor = QColor("black");
    QList<QPointF> _points;
    QPointF _labelPos;
    int _type = 1;
    int _splines = 0;
    qreal _lineWidth = 3;
    qreal _arrowSize = 15;
    qreal _textSize = 0;
    QColor _textColor = QColor("black");
    QString _textFamily = "serif";
    qreal _skale = 1.0;
    qreal _skaleX = 0;
    qreal _skaleY = 0;
    qreal _skaleW = 0;
    qreal _skaleH = 0;

    QPainterPath* _currentPath = new QPainterPath();
};

#endif // QMLEDGE_HPP
