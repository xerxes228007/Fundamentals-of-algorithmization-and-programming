#include "star6.h"

star6::star6() {}

star6::star6(QPointF point1, QPointF point2)
{
    len1 = point2.x() - point1.x();
    len2 = point2.y() - point1.y();
    len3 = sqrt(pow(len1, 2) + pow(len2,2));
    centrMass = QPointF(point1.x(), point1.y() + (point2.y() - point1.y()) *2/3);
    radius = sqrt(pow(centrMass.x() - point1.x(), 2) + pow(centrMass.y() - point1.y(), 2));

    nowPoints.append(point1);
    nowPoints.append(point2);
    nowPoints.append(point2 + QPointF(-2* len1, 0));
    nowPoints.append(centrMass + (centrMass - point1));
    nowPoints.append(nowPoints[3] + QPointF(len1, -len2));
    nowPoints.append(nowPoints[4] + QPointF(-2 * len1, 0));

    startPoints.append(point1);
    startPoints.append(point2);
    startPoints.append(point2 + QPointF(-2* len1, 0));
    startPoints.append(centrMass + (centrMass - point1));
    startPoints.append(nowPoints[3] + QPointF(len1, -len2));
    startPoints.append(nowPoints[4] + QPointF(-2 * len1, 0));

    for (int i = 0; i < startPoints.size(); ++i){
        speedReiszeArr.append(QPointF(0,0));
    }
    name = "Звезда6";

}

bool star6::pointInSide(QPointF point)
{
    if (pow(centrMass.x() - point.x(),2) + pow(centrMass.y() - point.y(),2) <= pow(radius,2)){
        return 1;
    }
    return 0;
}

void star6::areaCalculating()
{
    area = len3 * len3 * 9 * sqrt(3) / 4 + 3 * len3 * len3 *sqrt(3) / 4;
}

void star6::perimetrCalculating()
{
    perimetr = len3 * 12;
}

void star6::draw(QPainter *paint)
{
    paint->drawLine(nowPoints[0], nowPoints[1]);
    paint->drawLine(nowPoints[1], nowPoints[2]);
    paint->drawLine(nowPoints[2], nowPoints[0]);
    paint->drawLine(nowPoints[3], nowPoints[4]);
    paint->drawLine(nowPoints[4], nowPoints[5]);
    paint->drawLine(nowPoints[5], nowPoints[3]);
}

void star6::radiusCalculating()
{
    radius = sqrt(pow(centrMass.x() - nowPoints[0].x(), 2) + pow(centrMass.y() - nowPoints[0].y(), 2));

}
