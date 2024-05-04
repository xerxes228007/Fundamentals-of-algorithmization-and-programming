#include "triangle.h"
#include <qdebug.h>
#include <qpoint.h>
#include <qpolygon.h>

TriangleShape::TriangleShape() : lenA(), lenB(), lenC() {
  for (auto lenS : {&lenA, &lenB, &lenC}) {
    lenS->setMinimum(10);
    lenS->setMaximum(500);
    lenS->setValue(86);

    connect(lenS, QOverload<int>::of(&QSpinBox::valueChanged), this,
            &TriangleShape::updateSlot);

    connect(lenS, QOverload<int>::of(&QSpinBox::valueChanged), this,
            &TriangleShape::updateInpMax);
  }
}

void TriangleShape::setupOptions(QFormLayout *form) {
  form->addRow("Len A: ", &lenA);
  form->addRow("Len B: ", &lenB);
  form->addRow("Len C: ", &lenC);
}

void TriangleShape::updateInpMax() {
  int a = lenA.value();
  int b = lenB.value();
  int c = lenC.value();

  lenA.setMaximum(b + c - 1);
  lenB.setMaximum(a + c - 1);
  lenC.setMaximum(b + a - 1);
}

QPolygonF TriangleShape::shapePoly() const {
  float a = lenA.value();
  float b = lenB.value();
  float c = lenC.value();

  float lx = (c * c + a * a - b * b) / 2 / a;
  float ly = -sqrt(c * c - lx * lx);
  
  float sx = - ((0 + a + lx) / 3);
  float sy = - ((0 + 0 + ly) / 3);
  
  
  QPolygonF pol;
  pol << QPointF(sx, sy);
  pol << QPointF(lx + sx, ly + sy);
  pol << QPointF(a + sx, sy);

  return pol;
}