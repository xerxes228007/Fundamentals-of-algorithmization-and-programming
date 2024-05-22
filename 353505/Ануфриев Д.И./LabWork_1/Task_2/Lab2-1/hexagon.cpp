#include "hexagon.h"

Hexagon::Hexagon(double radius) {
    const int sides = 6;

    for (int i = 0; i < 6; ++i) {
        qreal angle = 2 * M_PI * i / sides;
        qreal x = radius * cos(angle);
        qreal y = radius * sin(angle);
        hexagon << QPointF(x, y);
    }

    Area = 2.59808 * radius * radius;
    Perimetr = radius * 6;



    qreal x = 0, y = 0; // get center

    for(int i = 0; i < sides; i++)
    {
        x += hexagon[i].x();
        y += hexagon[i].y();
    }

    x /= sides * 1.0;
    y /= sides * 1.0;

    originPoint = QPointF(0, 0); //this place is edited
    setTransformOriginPoint(originPoint);
}

QRectF Hexagon::boundingRect() const {
    return hexagon.boundingRect();
}

void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    painter->setBrush(Qt::black);
    painter->drawPolygon(hexagon);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

QPainterPath Hexagon::shape() const
{
    QPainterPath path;
    path.addPolygon(hexagon);
    return path;
}
