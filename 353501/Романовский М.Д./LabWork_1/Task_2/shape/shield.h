#pragma once

#include "polygon.h"
#include <qpolygon.h>

class ShieldShape: public PolygonShape {
  QSpinBox side;
  QSpinBox arrow;

public:
  ShieldShape();

  QPolygonF shapePoly() const;

  void setupOptions(QFormLayout *form);
};