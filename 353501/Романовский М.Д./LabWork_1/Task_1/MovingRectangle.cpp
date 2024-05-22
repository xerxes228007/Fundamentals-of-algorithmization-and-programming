#include "MovingRectangle.h"
#include <QPainter>
#include <qlogging.h>
#include <qnamespace.h>
#include <qpainter.h>
#include <qpoint.h>
#include <qtimer.h>

MovingRectangle::MovingRectangle() : timer(this) {
  connect(&timer, &QTimer::timeout, this, &MovingRectangle::onTick);

  dx = 2;
  x = 0;

  timer.setInterval(20);
  timer.start();
}

void MovingRectangle::onTick() {
  x += dx;
  if (x > 300)
    dx = -2;
  if (x < -300)
    dx = 2;
  update();
}

QRectF MovingRectangle::boundingRect() const {
  return QRectF(-200 + x, -100, 400, 200);
}

void MovingRectangle::paint(QPainter *painter,
                            const QStyleOptionGraphicsItem *option,
                            QWidget *widget) {
  painter->setPen(Qt::NoPen);
  painter->setBrush(Qt::gray);
  painter->drawRect(-100 + x, -50, 200, 100);
}