#include "Car.h"
#include "MovingRectangle.h"
#include <qnamespace.h>
#include <qpainter.h>

Car::Car() {
  lightEnabled = false;
  doorOpen = false;
  doorAngle = 0;
}

void Car::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                QWidget *widget) {

  MovingRectangle::paint(painter, option, widget);
  painter->save();
  painter->translate(x, 0);
  if (dx > 0)
    painter->scale(-1, 1);

  painter->drawRect(-140, 0, 60, 50);

  painter->setBrush(Qt::black);
  painter->drawEllipse(-120, 25, 40, 40);
  painter->drawEllipse(50, 25, 40, 40);

  painter->setBrush(lightEnabled ? Qt::yellow : Qt::lightGray);
  painter->drawRect(-140, 5, 30, 10);

  painter->setBrush(Qt::red);
  painter->translate(-65, -40);

  if (doorOpen && doorAngle < 70)
    doorAngle += 2;
  if (!doorOpen && doorAngle > 0)
    doorAngle -= 2;

  painter->rotate(-doorAngle);
  painter->drawRect(0, 0, 110, 85);

  painter->restore();
}

void Car::setLights(bool enabled) { lightEnabled = enabled; }
void Car::setDoor(bool open) { doorOpen = open; }