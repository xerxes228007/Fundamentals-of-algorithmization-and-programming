#pragma once

#include <QObject>
#include <QString>

class Car : public QObject {
  Q_OBJECT

public:
  QString country;
  QString producer;
  QString engineType;
  float price;
  float fuelConsumption;
  float reliability;
  float comfort;

  Q_PROPERTY(QString country MEMBER country);
  Q_PROPERTY(QString producer MEMBER producer);
  Q_PROPERTY(QString engineType MEMBER engineType);
  Q_PROPERTY(float price MEMBER price);
  Q_PROPERTY(float fuelConsumption MEMBER fuelConsumption);
  Q_PROPERTY(float reliability MEMBER reliability);
  Q_PROPERTY(float comfort MEMBER comfort);


  Car();
  Car *clone() const;


  struct Property {
    const char *name;
    QString displayName;
    float min, max, step;
  };


  static const Property PROPERTIES[];
  static const int PROPERTY_COUNT = 7; 
  static const Property* getProperty(const char *property);

private:
};