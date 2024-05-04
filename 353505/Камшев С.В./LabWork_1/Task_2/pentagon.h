#ifndef PENTAGON_H
#define PENTAGON_H
#include "linefigure.h"

class pentagon: public lineFigure
{
public:
    pentagon();

    pentagon(QPointF point1, QPointF point2);
    bool pointInSide(QPointF point) override;
    void areaCalculating() override;
    void perimetrCalculating() override;
    void radiusCalculating() override;

};

#endif // PENTAGON_H
