#ifndef RHOMB_H
#define RHOMB_H
#include "linefigure.h"

class rhomb: public lineFigure
{
public:
    rhomb();
    rhomb(QPointF point1, QPointF point2);
    bool pointInSide(QPointF point) override;
    void areaCalculating() override;
    void perimetrCalculating() override;
    void radiusCalculating() override;

};

#endif // RHOMB_H
