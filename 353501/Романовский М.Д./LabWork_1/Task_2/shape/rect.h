#pragma once

#include "polygon.h"
#include <qpolygon.h>

class RectShape: public PolygonShape {
  QSpinBox width;
  QSpinBox height;

public:
  RectShape ();

  QPolygonF shapePoly() const;

  void setupOptions(QFormLayout *form);
};