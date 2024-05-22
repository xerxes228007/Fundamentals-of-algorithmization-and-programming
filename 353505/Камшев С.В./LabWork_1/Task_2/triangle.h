#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "linefigure.h"

class triangle: public lineFigure
{
public:
    triangle();
    triangle(QPointF point1, QPointF point2);
    bool pointInSide(QPointF point) override;
    void areaCalculating() override;
    void perimetrCalculating() override;
    void edgeCalculating();
    void radiusCalculating() override;


private:
    double edge1,edge2, edge3;

};

#endif // TRIANGLE_H
