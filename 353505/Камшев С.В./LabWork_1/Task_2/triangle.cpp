#include "triangle.h"
#include <QDebug>

triangle::triangle(QPointF point1, QPointF point2)
{
    len1 = point2.x() - point1.x();
    len2 = point2.y() - point1.y();
    centrMass = QPointF(point1.x(), point1.y() + (point2.y() - point1.y()) *2/3);
    radius = sqrt(pow(centrMass.x() - point1.x(), 2) + pow(centrMass.y() - point1.y(), 2));

    nowPoints.append(point1);
    nowPoints.append(point2);
    nowPoints.append(point2 + QPointF(-2* len1, 0));


    startPoints.append(point1);
    startPoints.append(point2);
    startPoints.append(point2 + QPointF(-2* len1, 0));

    for (int i = 0; i < startPoints.size(); ++i){
        speedReiszeArr.append(QPointF(0,0));
    }

    name = "Треугольник";

}

bool triangle::pointInSide(QPointF point)
{
    if (pow(centrMass.x() - point.x(),2) + pow(centrMass.y() - point.y(),2) <= pow(radius,2)){
        return 1;
    }
    return 0;
}

void triangle::areaCalculating()
{
    perimetrCalculating();
    double halfPerimetr = perimetr/2;
    area = sqrt(halfPerimetr * (halfPerimetr-edge1) * (halfPerimetr-edge2) * (halfPerimetr-edge3));
}

void triangle::perimetrCalculating()
{
    edgeCalculating();
    perimetr = edge1 + edge2+ edge3;

}

void triangle::edgeCalculating()
{
    edge1 = sqrt(pow(nowPoints[0].x() - nowPoints[1].x(),2) + pow(nowPoints[0].y() - nowPoints[1].y(),2));
    edge2 = sqrt(pow(nowPoints[0].x() - nowPoints[2].x(),2) + pow(nowPoints[0].y() - nowPoints[2].y(),2));
    edge3 = sqrt(pow(nowPoints[1].x() - nowPoints[2].x(),2) + pow(nowPoints[1].y() - nowPoints[2].y(),2));
}

void triangle::radiusCalculating()
{
    radius = sqrt(pow(centrMass.x() - nowPoints[0].x(), 2) + pow(centrMass.y() - nowPoints[0].y(), 2));
}




