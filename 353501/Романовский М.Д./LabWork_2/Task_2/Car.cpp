#include "Car.h"
#include <QVariant>
#include <cstring>

Car::Car() {
  country = "Belarus";
  producer = "Toyota";
  engineType = "V8";
  price = 10000;
  fuelConsumption = 8;
  reliability = 10;
  comfort = 8;
}

Car *Car::clone() const {
  Car *res = new Car;
  for (int i = 0; i < Car::PROPERTY_COUNT; i++) {
    const char *name = Car::PROPERTIES[i].name;
    res->setProperty(name, property(name));
  }
  return res;
}

const Car::Property Car::PROPERTIES[] = {
    {"country", "Country", 0, 0, -1},
    {"producer", "Producer", 0, 0, -1},
    {"engineType", "Engine Type", 0, 0, -1},
    {"price", "Price", 200, 1000000, 10},
    {"fuelConsumption", "Fuel use", 0, 100, 0.1},
    {"reliability", "Reliability", 0, 50, 0.25},
    {"comfort", "Comfort", 1, 10, 0.1},
};

static const Car::Property *getProperty(const char *property) {
  for (int i = 0; i < Car::PROPERTY_COUNT; i++) {
    if (strcmp(property, Car::PROPERTIES[i].name) == 0) {
      return &Car::PROPERTIES[i];
    }
  }
  return nullptr;
};