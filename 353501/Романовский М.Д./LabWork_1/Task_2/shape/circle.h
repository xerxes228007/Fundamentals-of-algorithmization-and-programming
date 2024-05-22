#pragma once

#include "base.h"
#include <QSpinBox>
#include <qformlayout.h>
#include <qtmetamacros.h>

class CircleShape : public BaseShape {
  QSpinBox radius;

public:
  CircleShape();

  QRectF boundingRect() const;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget);

  void setupOptions(QFormLayout *form);

  float area();
  float perimeter();
};