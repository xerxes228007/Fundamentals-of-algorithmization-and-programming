#include "hexagon.h"

hexagon::hexagon() {}

hexagon::hexagon(QPointF point1, QPointF point2)
{
    centrMass = (point1 + (point2 - point1) / 2);
    len1 = point2.x() - point1.x();
    len2 = point2.y() - point1.y();

    radius = len1;

    nowPoints.append(point1);
    nowPoints.append(point1 + QPointF(len1, 0));
    nowPoints.append(point1 + QPointF(1.5 * len1 , len2/2));
    nowPoints.append(point2);
    nowPoints.append(point2 + QPointF(-len1, 0));
    nowPoints.append(point1 + QPointF(-0.5 * len1 , len2/2));


    startPoints.append(point1);
    startPoints.append(point1 + QPointF(len1, 0));
    startPoints.append(point1 + QPointF(1.5 * len1 , len2/2));
    startPoints.append(point2);
    startPoints.append(point2 + QPointF(-len1, 0));
    startPoints.append(point1 + QPointF(-0.5 * len1 , len2/2));

    name = "Шестиугольник";


    for (int i = 0; i < startPoints.size(); ++i){
        speedReiszeArr.append(QPointF(0,0));
    }
}

void hexagon::areaCalculating()
{
    area = abs(3 * sqrt(3) * len1 * len1)/2;
}

void hexagon::perimetrCalculating()
{
    perimetr = abs(6 * len1);
}

bool hexagon::pointInSide(QPointF point)
{
    if (pow(centrMass.x() - point.x(),2) + pow(centrMass.y() - point.y(),2) <= pow(radius,2)){
        return 1;
    }
    return 0;
}

void hexagon::radiusCalculating()
{
    radius = len1;
}


