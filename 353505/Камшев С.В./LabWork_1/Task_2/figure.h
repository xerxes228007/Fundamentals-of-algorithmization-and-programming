#ifndef FIGURE_H
#define FIGURE_H

#include <QVector>
#include <QPainter>
#include <QTimer>
#include <QPointF>

class figure
{
public:
    figure();

    virtual void areaCalculating();
    virtual void perimetrCalculating();
    virtual void draw(QPainter *paint);
    virtual bool pointInSide(QPointF point);
    virtual void radiusCalculating();


    void resize(int numb);
    void setCentr(QPointF point);
    void turn();

    double getPerimetr();
    double getArea();
    QPointF getCentre();
    double getLen1();
    double getLen2();
    double getRadius();
    double getTurnAngle();
    short getSize();
    QString getName();
    double pointsDistance(QPointF point1, QPointF point2);
    short getNearPoint(QPointF point);
    void movePoint(int numb, QPointF point);

    void changeTurnAngle(double angle);

protected:
    QString name;
    QVector <QPointF> nowPoints;
    QVector <QPointF> startPoints;
    QVector <QPointF> speedReiszeArr;

    QPointF centrMass;
    short startSize = 50;
    double len1 = 0, len2 = 0, len3 = 0, radius = 0, turnAngle = 0;
    double perimetr, area;

};

#endif // FIGURE_H
