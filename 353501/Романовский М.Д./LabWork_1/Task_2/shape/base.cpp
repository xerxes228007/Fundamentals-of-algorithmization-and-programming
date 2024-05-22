#include "base.h"
#include <QPainter>
#include <qlogging.h>
#include <qpainter.h>
#include <qpoint.h>

void BaseShape::updateSlot() {
  update();
  emit updated();
}

QString BaseShape::description() {
  float scale = trans ? trans->scale : 1;

  QPointF pos(0, 0);
  if(trans) {
    pos = QPointF(trans->x, trans->y);
    pos -= QPointF(trans->transX, trans->transY);
    float ang = trans->rotation / 180 * M_PI;
    pos += trans->transX * QPointF(cos(ang), sin(ang));
    pos += trans->transY * QPointF(sin(ang), cos(ang));
  }

  if (area() < 0 || perimeter() < 0)
    return QString("Custom shape is drawn");

  return QString(""
                 "Area: **%1px**\n\n"
                 "Perimeter: **%2px**\n\n"
                 "Center: **%3 %4**\n\n")
      .arg(area() * scale * scale)
      .arg(perimeter() * scale)
      .arg(pos.x())
      .arg(pos.y());
}

void BaseShape::attachTrans(AnimTrans *t) {
  trans = t;
  connect(t, &AnimTrans::animationUpdate, this, &BaseShape::updateSlot);
}

void BaseShape::beginPaint(QPainter *p) {
  p->save();
  p->setBrush(Qt::red);

  if(trans) {
    p->translate(trans->x, trans->y);

    p->translate(trans->transX, trans->transY);
    p->rotate(trans->rotation);
    p->translate(-trans->transX, -trans->transY);

    p->scale(trans->scale, trans->scale);
    
  }
}


void BaseShape::endPaint(QPainter *p) {
  p->restore();
}