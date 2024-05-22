#include "polygon.h"
#include <QPainter>
#include <cmath>
#include <qformlayout.h>
#include <qobject.h>
#include <qpoint.h>
#include <qpolygon.h>
#include <qspinbox.h>

void PolygonShape::paint(QPainter *painter,
                        const QStyleOptionGraphicsItem *option,
                        QWidget *widget) {

  beginPaint(painter);
  painter->drawPolygon(shapePoly());
  endPaint(painter);
}

QRectF PolygonShape::boundingRect() const {
  QRectF br = shapePoly().boundingRect();
  br.adjust(-5, -5, 10, 10);
  return br;
}


float PolygonShape::area() { 
  QPolygonF pol = shapePoly();
  QPointF lastp = pol.last();
  float ans = 0;
  
  for(int i = 0; i < pol.count(); i++) {
    QPointF curp = pol[i];
    ans += lastp.x() * curp.y() - curp.x() * lastp.y();
    lastp = curp;
  }
  return ans / 2.;
}

float PolygonShape::perimeter() { 
  QPolygonF pol = shapePoly();
  QPointF lastp = pol.last();
  float ans = 0;
  for(int i = 0; i < pol.count(); i++) {
    QPointF curp = pol[i];
    ans += sqrt(QPointF::dotProduct((lastp - curp), (lastp - curp)));
    lastp = curp;
  }
  return ans;
}