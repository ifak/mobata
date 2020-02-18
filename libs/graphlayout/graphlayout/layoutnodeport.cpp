#include "layoutnodeport.hpp"

#include <mobata/memory_leak_start.hpp>

using namespace graphlayout;

class LayoutNodePort::Private
{
    friend class LayoutNodePort;

public:
    Private(){}

    ~Private(){}

private:
    ShapeEnum _shape = Square;
    QUuid _externUuid = QUuid::createUuid();
    QSizeF _size = QSizeF(15,15);
    QColor _color = QColor("white");
    QPointF _pos = QPointF(0,0);
    QString _label = "";
    QPointF _labelPos = QPointF(0,0);
    float _labelSize=12;
    QString _type;
};

LayoutNodePort::LayoutNodePort(QObject *parent): QObject(parent), _d(new Private())
{
    this->setObjectName("port");
}

LayoutNodePort::~LayoutNodePort()
{
    delete this->_d;
}

void LayoutNodePort::setExternUuid(const QUuid& newExternUuid)
{
    this->_d->_externUuid=newExternUuid;
}

const QUuid& LayoutNodePort::externUuid() const
{
    return this->_d->_externUuid;
}

void LayoutNodePort::setPos(const QPointF& newPos)
{
    this->_d->_pos=newPos;
}

const QPointF& LayoutNodePort::pos() const
{
    return this->_d->_pos;
}

void LayoutNodePort::setLabelPos(const QPointF& newPos)
{
    this->_d->_labelPos=newPos;
}

const QPointF& LayoutNodePort::labelPos() const
{
    return this->_d->_labelPos;
}

void LayoutNodePort::setLabelSize(const float& size)
{
    this->_d->_labelSize=size;
}

const float& LayoutNodePort::labelSize() const
{
    return this->_d->_labelSize;
}

void LayoutNodePort::setSize(const QSizeF& newSize)
{
    this->_d->_size=newSize;
}

const QSizeF& LayoutNodePort::size() const
{
    return this->_d->_size;
}

void LayoutNodePort::setLabel(const QString& label)
{
    this->_d->_label=label;
}

const QString& LayoutNodePort::label() const
{
    return this->_d->_label;
}

void LayoutNodePort::setType(const QString& type)
{
    this->_d->_type=type;
}

const QString& LayoutNodePort::type() const
{
    return this->_d->_type;
}

void LayoutNodePort::setColor(const QColor& color)
{
    this->_d->_color=color;
}

const QColor& LayoutNodePort::color() const
{
    return this->_d->_color;
}

void LayoutNodePort::setShape(const ShapeEnum& shape)
{
    this->_d->_shape=shape;
}

const ShapeEnum& LayoutNodePort::shape() const
{
    return this->_d->_shape;
}
