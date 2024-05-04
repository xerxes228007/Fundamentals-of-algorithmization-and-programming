#ifndef HEXAGON_H
#define HEXAGON_H
#include "linefigure.h"

class hexagon: public lineFigure
{
public:
    hexagon();
    hexagon(QPointF point1, QPointF point2);

    void areaCalculating() override;
    void perimetrCalculating() override;
    bool pointInSide(QPointF point) override;
    void radiusCalculating() override;

};

#endif // HEXAGON_H
