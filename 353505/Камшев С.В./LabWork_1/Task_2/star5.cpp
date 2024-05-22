#include "star5.h"

star5::star5() {}

star5::star5(QPointF point1, QPointF point2)
{
    centrMass = QPointF(point1.x(), point1.y() + (point2.y() - point1.y()) / 2);
    len1 = point2 .x() - point1.x();
    len2= point2.y() - point1.y();
    len3 = sqrt(pow(len1, 2) + pow(len2,2)) / 3;
    radius = sqrt(pow(centrMass.x() - point1.x(), 2) + pow(centrMass.y() - point1.y(), 2));

    nowPoints.append(point1);
    nowPoints.append(point2);
    nowPoints.append(point1 + QPointF( -1.5 *len1, len2/3));
    nowPoints.append(point1 + QPointF(1.5 * len1, len2/3));
    nowPoints.append(point1 + QPointF(-len1, len2));

    startPoints.append(point1);
    startPoints.append(point2);
    startPoints.append(point1 + QPointF( -1.5 *len1, len2/3));
    startPoints.append(point1 + QPointF(1.5 * len1, len2/3));
    startPoints.append(point1 + QPointF(-len1, len2));

    for (int i = 0; i < startPoints.size(); ++i){
        speedReiszeArr.append(QPointF(0,0));
    }

    name = "Звезда5";

}

bool star5::pointInSide(QPointF point)
{
    if (pow(centrMass.x() - point.x(),2) + pow(centrMass.y() - point.y(),2) <= pow(radius,2)){
        return 1;
    }
    return 0;
}

void star5::areaCalculating()
{
    area = 1.72 * pow(len3 * 0.62, 2) + 5 * 0.5 * (0.62 * len3) * (0.97 * len3);
}

void star5::perimetrCalculating()
{
    perimetr = len3 * 10;
}

void star5::radiusCalculating()
{
    radius = sqrt(pow(centrMass.x() - nowPoints[0].x(), 2) + pow(centrMass.y() - nowPoints[0].y(), 2));
}

