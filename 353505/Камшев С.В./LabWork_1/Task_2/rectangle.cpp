#include "rectangle.h"

rectangle::rectangle() {}

rectangle::rectangle(QPointF point1, QPointF point2)
{
    centrMass = QPointF(point1 +(point2 - point1)/2);
    len1 =point2.x() - point1.x();
    len2 = point2.y() - point1.y();
    radius = fmin(abs(len1), abs(len2));


    nowPoints.append(centrMass + QPointF(-len1/2, -len2/2));
    nowPoints.append(centrMass + QPointF(len1/2, -len2/2));
    nowPoints.append(centrMass + QPointF(len1/2, len2/2));
    nowPoints.append(centrMass + QPointF(-len1/2, len2/2));

    startPoints.append(centrMass + QPointF(-len1/2, -len2/2));
    startPoints.append(centrMass + QPointF(len1/2, -len2/2));
    startPoints.append(centrMass + QPointF(len1/2, len2/2));
    startPoints.append(centrMass + QPointF(-len1/2, len2/2));

    for (int i = 0; i < startPoints.size(); ++i){
        speedReiszeArr.append(QPointF(0,0));
    }

    name = "Прямоугольник";

}

bool rectangle::pointInSide(QPointF point)
{
    if (pow(centrMass.x() - point.x(),2) + pow(centrMass.y() - point.y(),2) <= pow(radius,2)){
        return 1;
    }
    return 0;
}

void rectangle::areaCalculating()
{
    area = abs(len1 * len2);
}

void rectangle::perimetrCalculating()
{
    perimetr = 2 * (abs(len1) + abs(len2));
}

void rectangle::radiusCalculating()
{
    radius = fmin(abs(len1), abs(len2));
}


