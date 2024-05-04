#ifndef STAR5_H
#define STAR5_H
#include "linefigure.h"

class star5: public lineFigure
{
public:
    star5();
    star5(QPointF point1, QPointF point2);
    bool pointInSide(QPointF point) override;
    void areaCalculating() override;
    void perimetrCalculating() override;
    void radiusCalculating() override;

};

#endif // STAR5_H
