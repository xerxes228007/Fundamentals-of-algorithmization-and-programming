#ifndef PENCIL_H
#define PENCIL_H

//#include "shape.h"
#include <QGraphicsScene>
#include <QGraphicsPathItem>
#include <QGraphicsItem>

#include "figure.h"

class Pencil : public QGraphicsItem
{
public:
    Pencil();
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    bool drawing;

    QVector <QPointF> points;

    QPainterPath path;
    Figure* tempFigure;
};

#endif // PENCIL_H
