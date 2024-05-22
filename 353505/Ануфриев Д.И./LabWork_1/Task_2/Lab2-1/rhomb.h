#ifndef RHOMB_H
#define RHOMB_H

#include "polygon.h"

class Rhomb: public Polygon
{
public:
    Rhomb(QPointF p1, QPointF p2, QPointF p3, QPointF p4);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPainterPath shape() const override;

private:
    QPolygonF rhomb;
};


#endif // RHOMB_H
