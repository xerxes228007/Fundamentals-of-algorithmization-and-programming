#include "square.h"

square::square() {}

square::square(QPointF point1,  QPointF point2)
{

    len1 = point2.x() - point1.x();
    len2 = point2.y() - point1.y();

    if (abs(len1) < abs(len2)){
        len2= abs(len1) * abs(len2)/len2;
    }
    else{
        len1 = abs(len2) * abs(len1) / len1;
    }

    centrMass = QPointF(point1 +QPointF(len1 , len2) / 2);
    radius = fmin(abs(len1), abs(len2));


    nowPoints.append(point1);
    nowPoints.append(point1 + QPointF(len1, 0));
    nowPoints.append(point1 + QPointF(len1, len2));
    nowPoints.append(point1 + QPointF(0, len2));

    startPoints.append(point1);
    startPoints.append(point1 + QPointF(len1, 0));
    startPoints.append(point1 + QPointF(len1, len2));
    startPoints.append(point1 + QPointF(0, len2));

    for (int i = 0; i < startPoints.size(); ++i){
        speedReiszeArr.append(QPointF(0,0));
    }
    name = "Квадрат";

}

bool square::pointInSide(QPointF point)
{
    if (pow(centrMass.x() - point.x(),2) + pow(centrMass.y() - point.y(),2) <= pow(radius,2)){
        return 1;
    }
    return 0;
}

void square::areaCalculating()
{
    area = abs(len1 * len1);
}

void square::perimetrCalculating()
{
    perimetr = abs(len1) * 4;
}

void square::radiusCalculating()
{
    radius = fmin(abs(len1), abs(len2));
}


