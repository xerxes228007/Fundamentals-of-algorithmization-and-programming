#ifndef HEXAGON_H
#define HEXAGON_H

#include "polygon.h"

class Hexagon : public Polygon
{
public:
    Hexagon(double);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPainterPath shape() const override;

private:
    QPolygonF hexagon;
};

#endif // HEXAGON_H
