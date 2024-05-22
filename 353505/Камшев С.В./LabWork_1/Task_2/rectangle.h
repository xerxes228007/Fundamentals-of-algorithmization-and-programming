#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "linefigure.h"

class rectangle: public lineFigure
{
public:
    rectangle();

    rectangle(QPointF point1,QPointF point2);
    bool pointInSide(QPointF point) override;
    void areaCalculating() override;
    void perimetrCalculating() override;
    void radiusCalculating() override;

};

#endif // RECTANGLE_H
