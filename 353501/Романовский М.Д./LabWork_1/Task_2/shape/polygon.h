#pragma once

#include "base.h"
#include <QSpinBox>
#include <qformlayout.h>
#include <qtmetamacros.h>

class PolygonShape : public BaseShape {
protected:
  virtual QPolygonF shapePoly() const = 0;

public:
  QRectF boundingRect() const;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget);

  float area();
  float perimeter();
};