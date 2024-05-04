#ifndef WAGON_H
#define WAGON_H

#include "rectangle.h"

class Wagon : public Rectangle
{

public:
    Wagon();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    qreal speedMoving = 0;
};

#endif // WAGON_H
