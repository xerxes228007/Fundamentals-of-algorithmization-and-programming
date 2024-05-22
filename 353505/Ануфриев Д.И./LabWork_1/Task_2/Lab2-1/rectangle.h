#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "polygon.h"


class Rectangle : public Polygon
{
public:
    Rectangle(QPointF p1, QPointF p2, QPointF p3, QPointF p4);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QPolygonF rectangle;
};


#endif // RECTANGLE_H
