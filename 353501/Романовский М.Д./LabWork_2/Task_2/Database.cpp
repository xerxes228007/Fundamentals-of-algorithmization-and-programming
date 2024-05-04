#include "Database.h"
#include "Car.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <qcontainerfwd.h>
#include <qjsondocument.h>
#include <qjsonobject.h>
#include <qtypes.h>

Database::Database() {
  connect(this, &Database::updated, this, &Database::saveFile);
}

qsizetype Database::count() const { return cars.count(); }

QSharedPointer<Car> Database::getCar(qsizetype i) const { return cars.at(i); }

void Database::addCar(QSharedPointer<Car> car) {
  cars.push_back(car);
  emit updated();
}

void Database::setCar(qsizetype i, QSharedPointer<Car> car) {
  cars[i] = car;
  emit updated();
}

void Database::deleteCar(qsizetype i) {
  cars.removeAt(i);
  emit updated();
}

QJsonDocument Database::storeJSON() const {
  QJsonArray arr;
  for (auto car : cars) {
    QJsonObject carS;
    for (int i = 0; i < Car::PROPERTY_COUNT; i++) {
      const Car::Property *prop = &Car::PROPERTIES[i];
      carS[prop->name] = car->property(prop->name).toJsonValue();
    }
    arr.append(carS);
  }

  return QJsonDocument(arr);
}

void Database::loadJSON(QJsonDocument d) {
  cars.clear();

  QJsonArray arr = d.array();
  for (auto carSv : arr) {
    QJsonObject carS = carSv.toObject();
    QSharedPointer<Car> car(new Car);
    for (int i = 0; i < Car::PROPERTY_COUNT; i++) {
      const Car::Property *prop = &Car::PROPERTIES[i];
      car->setProperty(prop->name, carS[prop->name].toVariant());
    }
    cars.append(car);
  }

  emit updated();
}

void Database::openFile(QString _filePath) {
  filePath = _filePath;

  QFile f(filePath);
  if (f.exists()) {
    f.open(QFile::ReadOnly);
    loadJSON(QJsonDocument::fromJson(f.readAll()));
    f.close();
  } else {
    cars.clear();
    emit updated();
  }
}

void Database::saveFile() {
  if (filePath.size() > 0) {
    QFile f(filePath);
    f.open(QFile::WriteOnly | QFile::Truncate);
    f.write(storeJSON().toJson());
    f.close();
  }
}

QSet<QString> Database::getUniqOptions(const char *prop) {
  QSet<QString> options;
  for (qsizetype i = 0; i < cars.count(); i++) {
    options.insert(cars[i]->property(prop).toString());
  }
  return options;
}