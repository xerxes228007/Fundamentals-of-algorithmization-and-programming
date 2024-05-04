#include "circle.h"
#include <QPainter>
#include <cmath>
#include <qformlayout.h>
#include <qobject.h>
#include <qspinbox.h>

CircleShape::CircleShape() : radius() {
  radius.setValue(50);
  radius.setMinimum(10);
  radius.setMaximum(250);

  connect(&radius, QOverload<int>::of(&QSpinBox::valueChanged), this,
          &CircleShape::updateSlot);
}

void CircleShape::paint(QPainter *painter,
                        const QStyleOptionGraphicsItem *option,
                        QWidget *widget) {

  beginPaint(painter);
  int r = radius.value();
  painter->drawEllipse(-r, -r, r * 2, r * 2);
  endPaint(painter);
}

QRectF CircleShape::boundingRect() const {

  int r = radius.value() + 5;
  return QRectF(-r, -r, r * 2, r * 2);
}

void CircleShape::setupOptions(QFormLayout *form) {
  form->addRow("Radius: ", &radius);
}

float CircleShape::area() { return M_PI * radius.value() * radius.value(); }

float CircleShape::perimeter() { return 2 * M_PI * radius.value(); }