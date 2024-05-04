#pragma once

#include "polygon.h"
#include <qpolygon.h>

class StarShape: public PolygonShape {
  QSpinBox points;
  QSpinBox radiusA;
  QSpinBox radiusB;

public:
  StarShape();

  QPolygonF shapePoly() const;

  void setupOptions(QFormLayout *form);
};