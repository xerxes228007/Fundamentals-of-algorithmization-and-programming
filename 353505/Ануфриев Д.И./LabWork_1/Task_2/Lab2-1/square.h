#ifndef SQUARE_H
#define SQUARE_H

#include "polygon.h"
#include "dialogsquare.h"

class Square : public Polygon
{

public:
    Square(qreal side);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
private:
    QPolygonF square;
    QAction* setSide;
    qreal side;
};

#endif // SQUARE_H
