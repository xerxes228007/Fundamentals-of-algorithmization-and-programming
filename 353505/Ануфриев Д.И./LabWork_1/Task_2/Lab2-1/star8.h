#ifndef STAR8_H
#define STAR8_H

#include "polygon.h"

class Star8 : public Polygon
{

public:
    Star8(double, double);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPainterPath shape() const override;

private:
    QPolygonF star8;
};

#endif // STAR8_H
