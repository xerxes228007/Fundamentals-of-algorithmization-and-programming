#include "shape2.h"

Shape2::Shape2() : Shape(){}

QRectF Shape2::boundingRect() const
{
    return QRectF(0, 0, 100, 50);
}

void Shape2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::green);
    painter->drawRect(boundingRect());
    Q_UNUSED(option)
    Q_UNUSED(widget)
}
