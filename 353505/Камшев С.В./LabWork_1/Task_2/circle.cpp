#include "circle.h"

circle::circle() {}

circle::circle(QPointF point1, QPointF point2)
{
    centrMass = QPointF(point1 +(point2 - point1)/2);
    len1 = sqrt(pow(point2.x() - point1.x(),2) + pow(point2.y() - point1.y(),2));
    radius = len1/2;

    name = "Круг";
}

void circle::areaCalculating()
{
    area = abs(len1 * len1) * M_PI;
}

void circle::perimetrCalculating()
{
    perimetr = 2 * M_PI * abs(len1);
}

void circle::draw(QPainter *paint)
{
    paint->drawEllipse(centrMass.x() - len1/2, centrMass.y() - len1/2, len1, len1);
}

bool circle::pointInSide(QPointF point)
{
    if (pow(centrMass.x() - point.x(),2) + pow(centrMass.y() - point.y(),2) <= pow(radius,2)){
        return 1;
    }
    return 0;
}

void circle::radiusCalculating()
{
    radius = len1/2;
}
