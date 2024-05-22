#ifndef CIRCLE_H
#define CIRCLE_H
#include "figure.h"

class circle: public figure
{
public:
    circle();
    circle(QPointF point1, QPointF point2);


    void areaCalculating() override;
    void perimetrCalculating() override;
    void draw(QPainter *paint) override;
    bool pointInSide(QPointF point) override;
    void radiusCalculating() override;

};

#endif // CIRCLE_H
