#include "rect.h"
#include <qpoint.h>
#include <qpolygon.h>

RectShape::RectShape() : width(), height() {
  width.setMinimum(10);
  width.setMaximum(500);
  width.setValue(50);

  height.setMinimum(10);
  height.setMaximum(500);
  height.setValue(86);

  connect(&width, QOverload<int>::of(&QSpinBox::valueChanged), this,
          &RectShape::updateSlot);

  connect(&height, QOverload<int>::of(&QSpinBox::valueChanged), this,
          &RectShape::updateSlot);
}

void RectShape::setupOptions(QFormLayout *form) {
  form->addRow("Width: ", &width);
  form->addRow("Height: ", &height);
}

QPolygonF RectShape::shapePoly() const {
  float w = width.value() / 2.;
  float h = height.value() / 2.;

  return QPolygonF() << QPointF(-w, -h) << QPointF(w, -h) << QPointF(w, h)
                     << QPointF(-w, h);
}