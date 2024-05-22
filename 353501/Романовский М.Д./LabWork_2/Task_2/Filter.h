#pragma once

#include <QBoxLayout>

class Car;

class Filter {
public:
  virtual void setupUI(QBoxLayout *) = 0;
  virtual bool matches(QSharedPointer<Car> car) = 0;
};