#pragma once

#include "polygon.h"
#include <qpolygon.h>

class RhombusShape: public PolygonShape {
  QSpinBox width;
  QSpinBox height;

public:
  RhombusShape();

  QPolygonF shapePoly() const;

  void setupOptions(QFormLayout *form);
};