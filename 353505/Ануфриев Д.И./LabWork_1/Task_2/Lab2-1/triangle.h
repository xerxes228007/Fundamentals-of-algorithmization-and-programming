#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "polygon.h"

class Triangle : public Polygon
{

public:
    Triangle(QPointF p1, QPointF p2, QPointF p3);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QPainterPath shape() const override;
private:
    QPolygonF triangle;
};

#endif //TREIANGLE_H
