#ifndef SHAPE2_H
#define SHAPE2_H

#include "shape.h"

class Shape2 : public Shape
{
public:
    Shape2();

protected:
    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

};

#endif // SHAPE2_H
