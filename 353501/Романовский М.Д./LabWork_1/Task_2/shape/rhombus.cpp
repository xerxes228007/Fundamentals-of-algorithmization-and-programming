#include "rhombus.h"
#include <qpoint.h>
#include <qpolygon.h>

RhombusShape::RhombusShape() : width(), height() {
  width.setMinimum(10);
  width.setMaximum(500);
  width.setValue(100);

  height.setMinimum(10);
  height.setMaximum(500);
  height.setValue(100);

  connect(&width, QOverload<int>::of(&QSpinBox::valueChanged), this,
          &RhombusShape::updateSlot);

  connect(&height, QOverload<int>::of(&QSpinBox::valueChanged), this,
          &RhombusShape::updateSlot);
}

void RhombusShape::setupOptions(QFormLayout *form) {
  form->addRow("Width: ", &width);
  form->addRow("Height: ", &height);
}

QPolygonF RhombusShape::shapePoly() const {
  float w = width.value() / 2.;
  float h = height.value() / 2.;

  return QPolygonF() << QPointF(-w, 0) << QPointF(0, -h) << QPointF(w, 0)
                     << QPointF(0, h);
}