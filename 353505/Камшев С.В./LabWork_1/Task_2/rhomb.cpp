#include "rhomb.h"
#include <QDebug>
rhomb::rhomb() {}

rhomb::rhomb(QPointF point1, QPointF point2)
{
    len1 = point2.x() - point1.x();
    len2 = point2.y() - point1.y();
    radius = sqrt(pow(centrMass.x() - point1.x(), 2) + pow(centrMass.y() - point1.y(), 2));

    if (abs(len1) < abs(len2)){
        len2= abs(len1) * abs(len2)/len2;
    }
    else{
        len1 = abs(len2) * abs(len1) / len1;
    }


    nowPoints.append(point1);
    nowPoints.append(point1 + QPointF(len1, 0));
    nowPoints.append(point1 + QPointF(1.867 * len1, 0.5 * len2));
    nowPoints.append(point1 + QPointF(0.867 * len1, 0.5 * len2));

    startPoints.append(point1);
    startPoints.append(point1 + QPointF(len1, 0));
    startPoints.append(point1 + QPointF(1.867 * len1, 0.5 * len2));
    startPoints.append(point1 + QPointF(0.867 * len1, 0.5 * len2));
    centrMass = point1 + (point1 + QPointF(1.867 * len1, 0.5 * len2) - point1) / 2;

    for (int i = 0; i < startPoints.size(); ++i){
        speedReiszeArr.append(QPointF(0,0));
    }

    name = "Ромб";

}

bool rhomb::pointInSide(QPointF point)
{
    if (pow(centrMass.x() - point.x(),2) + pow(centrMass.y() - point.y(),2) <= pow(radius,2)){
        return 1;
    }
    return 0;
}

void rhomb::areaCalculating()
{
    area = abs(len1 * len1 * 0.5);
}

void rhomb::perimetrCalculating()
{
    perimetr = abs(len1 * 4);
}

void rhomb::radiusCalculating()
{
    radius = sqrt(pow(centrMass.x() - nowPoints[0].x(), 2) + pow(centrMass.y() - nowPoints[0].y(), 2));
}

