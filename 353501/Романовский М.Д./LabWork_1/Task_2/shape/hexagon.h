#pragma once

#include "polygon.h"
#include <qpolygon.h>

class HexagonShape: public PolygonShape {
  QSpinBox radius;

public:
  HexagonShape();

  QPolygonF shapePoly() const;

  void setupOptions(QFormLayout *form);
};