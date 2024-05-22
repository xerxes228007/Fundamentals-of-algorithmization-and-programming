#include "square.h"
#include <qpoint.h>
#include <qpolygon.h>

SquareShape::SquareShape() : side() {
  side.setMinimum(10);
  side.setMaximum(500);
  side.setValue(71);

  connect(&side, QOverload<int>::of(&QSpinBox::valueChanged), this,
          &SquareShape::updateSlot);
}

void SquareShape::setupOptions(QFormLayout *form) {
  form->addRow("Side: ", &side);
}

QPolygonF SquareShape::shapePoly() const {
  float s = side.value() / 2.;
  return QPolygonF() << QPointF(-s, -s) << QPointF(s, -s) << QPointF(s, s)
                     << QPointF(-s, s);
}