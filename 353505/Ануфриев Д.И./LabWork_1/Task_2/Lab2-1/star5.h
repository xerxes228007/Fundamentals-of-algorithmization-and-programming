#ifndef STAR5_H
#define STAR5_H

#include "polygon.h"
#include "dialogstar5.h"

#include <QMessageBox>

class Star5 : public Polygon
{

public:
    Star5(double, double);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPainterPath shape() const override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QPolygonF star5;
    QAction* setRadiuses;
    qreal externalRadius, internalRadius;
};

#endif // STAR5_H
