#include "shield.h"
#include <qpoint.h>
#include <qpolygon.h>

ShieldShape::ShieldShape() : side(), arrow() {
  side.setMinimum(10);
  side.setMaximum(500);
  side.setValue(71);

  arrow.setMinimum(5);
  arrow.setMaximum(500);
  arrow.setValue(29);

  connect(&side, QOverload<int>::of(&QSpinBox::valueChanged), this,
          &ShieldShape::updateSlot);
  connect(&arrow, QOverload<int>::of(&QSpinBox::valueChanged), this,
          &ShieldShape::updateSlot);
}

void ShieldShape::setupOptions(QFormLayout *form) {
  form->addRow("Side: ", &side);
  form->addRow("Arrow: ", &arrow);
}

QPolygonF ShieldShape::shapePoly() const {
  float s = side.value() / 2.;
  return QPolygonF() << QPointF(-s, -s) << QPointF(s, -s) << QPointF(s, s)
                     << QPointF(0, s + arrow.value()) << QPointF(-s, s);
}