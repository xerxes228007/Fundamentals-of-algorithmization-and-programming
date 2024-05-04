#include "pentagon.h"
#include "QDebug"

pentagon::pentagon() {}

pentagon::pentagon(QPointF point1, QPointF point2)
{
    centrMass = QPointF(point1.x(), point1.y() + (point2.y() - point1.y())/2);
    len1 = point2.x() - point1.x();
    len2 = point2.y() - point1.y();

    radius = abs(centrMass.y() - point1.y());
    nowPoints.append(point1);
    nowPoints.append(point1 + QPointF(2* len1 * 0.81 , len2 * 0.36));
    nowPoints.append(point2);
    nowPoints.append(point2 + QPointF(-2 * len1, 0));
    nowPoints.append(point1 + QPointF( -2*len1 * 0.81 ,  len2 * 0.36));


    startPoints.append(point1);
    startPoints.append(point1 + QPointF(2* len1 * 0.81 , len2 * 0.36));
    startPoints.append(point2);
    startPoints.append(point2 + QPointF(-2 * len1, 0));
    startPoints.append(point1 + QPointF( -2*len1 * 0.81 ,  len2 * 0.36));

    for (int i = 0; i < startPoints.size(); ++i){
        speedReiszeArr.append(QPointF(0,0));
    }

    name = "Пятиугольник";

}

bool pentagon::pointInSide(QPointF point)
{
    if (pow(centrMass.x() - point.x(),2) + pow(centrMass.y() - point.y(),2) <= pow(radius,2)){
        return 1;
    }
    return 0;
}

void pentagon::areaCalculating()
{
    area = abs(1.72 * len1 * len1);
}

void pentagon::perimetrCalculating()
{
    perimetr = abs(len1 * 5);
}

void pentagon::radiusCalculating()
{
    radius = abs(centrMass.y() - nowPoints[0].y());
}


