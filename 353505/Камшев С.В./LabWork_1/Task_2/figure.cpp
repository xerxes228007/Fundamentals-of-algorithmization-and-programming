#include "figure.h"
#include <QDebug>

figure::figure() {}
void figure::areaCalculating(){}
void figure::perimetrCalculating(){}
void figure::draw(QPainter *paint){}

bool figure::pointInSide(QPointF point){}

void figure::radiusCalculating(){}

void figure::resize(int numb)
{
    double multiplier = (numb + 0.0) / startSize;

    startSize = numb;

    for (int i = 0; i < speedReiszeArr.size(); ++i){
        speedReiszeArr[i] = (multiplier - 1) * (-centrMass + nowPoints[i]);
    }
    double speedResize1 = (multiplier - 1) * len1;
    double speedResize2 = (multiplier - 1) * len2;
    double speedResize3 = (multiplier - 1) * len3;

    for (int i = 0; i < speedReiszeArr.size(); ++i){
        nowPoints[i].setX(nowPoints[i].x() + speedReiszeArr[i].x());
        nowPoints[i].setY(nowPoints[i].y() + speedReiszeArr[i].y());
        startPoints[i].setX(startPoints[i].x() + speedReiszeArr[i].x());
        startPoints[i].setY(startPoints[i].y() + speedReiszeArr[i].y());
    }

    len1 += speedResize1;
    len2 += speedResize2;
    len3 += speedResize2;



}

void figure::setCentr(QPointF point)
{
    QPointF oldCentrMass = centrMass;
    centrMass = point;
    for (int i = 0; i < nowPoints.size(); ++i) {
        nowPoints[i].setX(centrMass.x() - oldCentrMass.x() + nowPoints[i].x());
        nowPoints[i].setY(centrMass.y() - oldCentrMass.y() + nowPoints[i].y());
        startPoints[i].setX(centrMass.x() - oldCentrMass.x() + startPoints[i].x());
        startPoints[i].setY(centrMass.y() - oldCentrMass.y() + startPoints[i].y());
    }
}

void figure::turn()
{
    QPointF oldCentr = centrMass;

    for (int i = 0; i < nowPoints.size(); ++i) {
        setCentr(QPointF(0,0));
        nowPoints[i].setX(startPoints[i].x() * cos(turnAngle) - startPoints[i].y() * sin(turnAngle));
        nowPoints[i].setY(startPoints[i].x() * sin(turnAngle) + startPoints[i].y() * cos(turnAngle));
    }
    setCentr(oldCentr);
}



double figure::getPerimetr()
{
    return perimetr;
}

double figure::getArea()
{
    return area;
}

QPointF figure::getCentre()
{
    return centrMass;
}

double figure::getLen1()
{
    return len1;
}

double figure::getLen2()
{
    return len2;
}

double figure::getRadius()
{
    return radius;
}

double figure::getTurnAngle()
{
    return turnAngle;
}

short figure::getSize()
{
    return startSize;
}

QString figure::getName()
{
    return name;
}

double figure::pointsDistance(QPointF point1, QPointF point2)
{
    return sqrt(pow(point2.x() - point1.x(), 2) + pow(point2.y() - point1.y(), 2));

}

short figure::getNearPoint(QPointF point)
{
    short min = 0;
    bool p = false;
    for (int i = 0; i < nowPoints.size(); ++i){
        if (pointsDistance(nowPoints[i], point) < radius / 2 ){
            p = true;
            if (pointsDistance(nowPoints[i], point) < pointsDistance(nowPoints[min], point)){
                min = i;
            }
        }
    }

    if (p) return min;
    else return -1;
}

void figure::movePoint(int numb, QPointF point)
{

    nowPoints[numb] = point;

    startPoints[0] = nowPoints[0];
    startPoints[1] = nowPoints[1];
    startPoints[2] = nowPoints[2];

    centrMass = QPointF((nowPoints[0].x() + nowPoints[1].x() + nowPoints[2].x())/3, (nowPoints[0].y() + nowPoints[1].y() + nowPoints[2].y())/3);
    turnAngle = 0;
}

void figure::changeTurnAngle(double angle)
{
    turnAngle += angle;
}

