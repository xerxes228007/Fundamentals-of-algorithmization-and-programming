#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include "dialogcircle.h"

#include <QMessageBox>

class Circle : public Shape
{
public:
    Circle(double newRadius);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QPainterPath shape() const override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
private:
    double radius;
    QGraphicsEllipseItem circle;
    QAction *setRadius;
};

#endif // CIRCLE_H
