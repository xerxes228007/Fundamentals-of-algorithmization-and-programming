#ifndef SQUARE_H
#define SQUARE_H
#include "linefigure.h"

class square: public lineFigure
{
public:
    square();
    square(QPointF point1, QPointF point2);
    bool pointInSide(QPointF point) override;
    void areaCalculating() override;
    void perimetrCalculating() override;
    void radiusCalculating() override;

};

#endif // SQUARE_H
