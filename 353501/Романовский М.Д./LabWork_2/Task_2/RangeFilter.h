#pragma once
#include "Car.h"
#include "Filter.h"
#include <qspinbox.h>
#include <qtclasshelpermacros.h>

class RangeFilter : public QObject, public Filter {
  Q_OBJECT

public:
  RangeFilter(const Car::Property *prop);

  virtual void setupUI(QBoxLayout *);
  virtual bool matches(QSharedPointer<Car> c);

private slots:
  void onMin(double v);
  void onMax(double v);

signals:
  void changed();

private:
  const Car::Property *prop;
  QDoubleSpinBox *minInp;
  QDoubleSpinBox *maxInp;

  double min;
  double max;
};