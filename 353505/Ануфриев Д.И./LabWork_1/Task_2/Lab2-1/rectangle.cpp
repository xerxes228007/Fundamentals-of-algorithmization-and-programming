#include "rectangle.h"

Rectangle::Rectangle(QPointF p1, QPointF p2, QPointF p3, QPointF p4)
{
    qreal cx, cy;

    cx = (p2.x() - p1.x()) / 2;
    cy = (- p2.y() + p3.y()) / 2;

    QPointF cpoint(cx, cy);

    rectangle << p1 - cpoint << p2  - cpoint << p3 - cpoint << p4 - cpoint;

    const int sides = 4;

    for(int i = 0; i < sides - 1; i++)
    {
        Area += (rectangle[i].x() * rectangle[i + 1].y() - rectangle[i].y() * rectangle[i + 1].x());
    }
    Area += (rectangle[sides - 1].x() * rectangle[0].y() - rectangle[sides - 1].y() * rectangle[0].x());
    Area = abs(Area) / 2;

    Perimetr += QLineF(p1, p2).length() * 2 + QLineF(p2, p3).length() * 2;





    qreal x = 0, y = 0;

    for(int i = 0; i < sides; i++)
    {
        x += rectangle[i].x();
        y += rectangle[i].y();
    }

    x /= sides * 1.0;
    y /= sides * 1.0;


    originPoint = QPointF(x, y);
    setTransformOriginPoint(originPoint);
}

QRectF Rectangle::boundingRect() const {
    return rectangle.boundingRect();
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(Qt::green);
    painter->drawPolygon(rectangle);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

