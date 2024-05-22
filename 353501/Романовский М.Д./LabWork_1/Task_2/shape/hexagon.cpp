#include "hexagon.h"
#include <cmath>
#include <qpoint.h>
#include <qpolygon.h>

HexagonShape::HexagonShape() : radius() {
  radius.setMinimum(10);
  radius.setMaximum(500);
  radius.setValue(50);

  connect(&radius, QOverload<int>::of(&QSpinBox::valueChanged), this,
          &HexagonShape::updateSlot);
}

void HexagonShape::setupOptions(QFormLayout *form) {
  form->addRow("Radius: ", &radius);
}

QPolygonF HexagonShape::shapePoly() const {
  float r = radius.value();
  QPolygonF pol;
  for(int i = 0; i < 6; i++) {
    pol << QPointF(r * cos(i * M_PI / 3), r * sin(i * M_PI / 3));
  }
  return pol;
}