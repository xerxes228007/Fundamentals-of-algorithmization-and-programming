#ifndef STAR8_H
#define STAR8_H
#include "figure.h"

class star8: public figure
{
public:
    star8();
    star8(QPointF point1, QPointF point2);
    bool pointInSide(QPointF point) override;
    void areaCalculating() override;
    void perimetrCalculating() override;
    void draw(QPainter *paint) override;
    void radiusCalculating() override;

};

#endif // STAR8_H
