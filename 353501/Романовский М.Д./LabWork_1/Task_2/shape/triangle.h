#pragma once

#include "polygon.h"
#include <qpolygon.h>

class TriangleShape: public PolygonShape {
  QSpinBox lenA;
  QSpinBox lenB;
  QSpinBox lenC;

public:
  TriangleShape();

  QPolygonF shapePoly() const;

  void setupOptions(QFormLayout *form);

protected slots:
  void updateInpMax();
};