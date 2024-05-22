#include "wagon.h"

Wagon::Wagon()
{
    speedMoving = 0;
}

QRectF Wagon::boundingRect() const
{
    return QRectF(0, 0, 200, 150);
}

void Wagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QColor color;
    color.setRgb(255, 239, 213);
    painter->setBrush(color);
    painter->drawRect(0, 0, 200, 100);

    color.setRgb(255, 69, 0);
    painter->setBrush(color);
    painter->drawEllipse(0, 90, 33, 33);
    painter->drawEllipse(167, 90, 33, 33);
}
