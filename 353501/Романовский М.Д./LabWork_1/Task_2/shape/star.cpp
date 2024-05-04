#include "star.h"
#include <cmath>
#include <qpoint.h>
#include <qpolygon.h>

StarShape::StarShape() : points(), radiusA(), radiusB() {
  points.setMinimum(5);
  points.setMaximum(10);
  points.setValue(5);

  radiusA.setMinimum(10);
  radiusA.setMaximum(500);
  radiusA.setValue(50);

  radiusB.setMinimum(10);
  radiusB.setMaximum(500);
  radiusB.setValue(30);

  connect(&radiusA, QOverload<int>::of(&QSpinBox::valueChanged), this,
          &StarShape::updateSlot);

  connect(&radiusB, QOverload<int>::of(&QSpinBox::valueChanged), this,
          &StarShape::updateSlot);

  connect(&points, QOverload<int>::of(&QSpinBox::valueChanged), this,
          &StarShape::updateSlot);
}

void StarShape::setupOptions(QFormLayout *form) {
  form->addRow("Points: ", &points);
  form->addRow("Radius A: ", &radiusA);
  form->addRow("Radius B: ", &radiusB);
}

QPolygonF StarShape::shapePoly() const {
  float ra = radiusA.value();
  float rb = radiusB.value();
  QPolygonF pol;

  int ends = points.value();
  
  for(int i = 0; i < ends * 2; i++) {
    float r = i % 2 ? ra : rb;
    pol << QPointF(-r * sin(i * M_PI / ends), r * cos(i * M_PI / ends));
  }

  return pol;
}