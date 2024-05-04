#include "rectangle.h"
#include <QPainter>
#include <QTimer>

Rectangle::Rectangle()
{
    speedMoving = 0;
}

QRectF Rectangle::boundingRect() const
{
    return QRectF(0, 0, 200, 100);
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QColor color;
    color.setRgb(255, 0, 255);
    painter->setBrush(color);
    painter->drawRect(boundingRect());

    Q_UNUSED (option)
    Q_UNUSED (widget)
}

void Rectangle::setSpeed(qreal newSpeed)
{
    speedMoving = newSpeed;
}

qreal Rectangle::getSpeed() const
{
    return speedMoving;
}

void Rectangle::addSpeed()
{
    if(speedMoving < 19)
    {
        qreal newSpeed = getSpeed() + qreal(1);
        setSpeed(newSpeed);
    }
    else
    {
        qreal newSpeed = getSpeed() + qreal(1);
        setSpeed(newSpeed);


        emit highSpeed();
    }
}

void Rectangle::deductSpeed()
{
    if(speedMoving > 1 && speedMoving <= 20)
    {
        qreal newSpeed = getSpeed() + qreal(-1);
        setSpeed(newSpeed);
    }
    else
    {
        speedMoving = 0;
        emit stop();
    }
}

void Rectangle::moveRect()
{
    if(x() + speedMoving >= 800)
    {
        setPos(x() - 800 - boundingRect().width(), y());
    }
    else if(x() + speedMoving < 0 - boundingRect().width())
    {
        setPos(x() + 800 + boundingRect().width(), y());
    }
    else setPos(x() + speedMoving, y());
}
