#pragma once

#include "polygon.h"
#include <qpolygon.h>

class SquareShape: public PolygonShape {
  QSpinBox side;

public:
  SquareShape();

  QPolygonF shapePoly() const;

  void setupOptions(QFormLayout *form);
};