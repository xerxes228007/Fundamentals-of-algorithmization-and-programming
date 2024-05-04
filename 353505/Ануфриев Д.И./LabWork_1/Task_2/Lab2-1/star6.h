#ifndef STAR6_H
#define STAR6_H

#include "polygon.h"

class Star6 : public Polygon
{

public:
    Star6(double, double);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPainterPath shape() const override;

private:
    QPolygonF star6;
};

#endif // STAR6_H
