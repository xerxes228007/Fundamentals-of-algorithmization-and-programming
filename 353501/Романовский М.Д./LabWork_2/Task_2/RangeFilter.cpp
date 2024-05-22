#include "RangeFilter.h"
#include "Car.h"
#include <qboxlayout.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qspinbox.h>

RangeFilter::RangeFilter(const Car::Property *_prop) : prop(_prop) {

  minInp = new QDoubleSpinBox();
  minInp->setRange(prop->min, prop->max);
  minInp->setValue(prop->min);
  minInp->setSingleStep(prop->step);
  minInp->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  connect(minInp, &QDoubleSpinBox::valueChanged, this, &RangeFilter::onMin);
  min = prop->min;

  maxInp = new QDoubleSpinBox();
  maxInp->setRange(prop->min, prop->max);
  maxInp->setValue(prop->max);
  maxInp->setSingleStep(prop->step);
  maxInp->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  connect(maxInp, &QDoubleSpinBox::valueChanged, this, &RangeFilter::onMax);
  max = prop->max;
}

void RangeFilter::setupUI(QBoxLayout *layout) {
  QHBoxLayout *hbox = new QHBoxLayout;
  hbox->addWidget(new QLabel("Min: "));
  hbox->addWidget(minInp);
  hbox->addSpacing(10);
  hbox->addWidget(new QLabel(" Max: "));
  hbox->addWidget(maxInp);

  layout->addWidget(new QLabel(QString("<b>%0</b>").arg(prop->displayName)));
  layout->addLayout(hbox);
}

void RangeFilter::onMin(double v) {
  min = v;
  maxInp->setMinimum(v);
  emit changed();
}

void RangeFilter::onMax(double v) {
  max = v;
  minInp->setMaximum(v);
  emit changed();
}

bool RangeFilter::matches(QSharedPointer<Car> c) {
  double v = c->property(prop->name).toFloat();
  // return true;
  return min - 1e-4 < v && v < max + 1e-4;
}