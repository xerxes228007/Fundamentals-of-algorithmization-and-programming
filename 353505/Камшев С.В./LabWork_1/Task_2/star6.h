#ifndef STAR6_H
#define STAR6_H
#include "figure.h"

class star6: public figure
{
public:
    star6();
    star6(QPointF point1, QPointF point2);
    bool pointInSide(QPointF point) override;
    void areaCalculating() override;
    void perimetrCalculating() override;
    void draw(QPainter *paint) override;
    void radiusCalculating() override;

};

#endif // STAR6_H
