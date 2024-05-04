#include "pen.h"

pen::pen() {}

pen::pen(QVector<QPointF> points)
{
    name = "Линия";

    double sumX = 0, sumY = 0;
    for (int i = 0; i < points.size(); ++i){
        nowPoints.append(points[i]);
        startPoints.append(points[i]);
        sumX += points[i].x();
        sumY += points[i].y();
    }
    QPointF centrPoint = QPointF(sumX/points.size(), sumY/points.size());


    centrMass = centrPoint;

    for (int i = 0; i < startPoints.size(); ++i){
        speedReiszeArr.append(QPointF(0,0));
    }
}

void pen::areaCalculating()
{
    area = 0;
}

void pen::perimetrCalculating()
{
    perimetr = 0;
    for (int i = 0; i < nowPoints.size() - 1; ++i){
        perimetr += pointsDistance(nowPoints[i], nowPoints[i+1]);
    }
}

void pen::draw(QPainter *paint)
{
    for (int i = 0; i < nowPoints.size() - 1;++i){
        paint->drawLine(nowPoints[i], nowPoints[(i+1)]);
    }
}

bool pen::pointInSide(QPointF point){
    for (int i = 0; i < nowPoints.size(); ++i){
        if (pointsDistance(point, nowPoints[i]) < 20){
            return true;
        }
    }
    return false;
}

void pen::radiusCalculating(){}
