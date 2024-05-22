#pragma once

#include <QObject>
#include <QSharedPointer>
#include <qtypes.h>

class Car;

class Database : public QObject {
  Q_OBJECT

public:
  Database();

  qsizetype count() const;
  QSharedPointer<Car> getCar(qsizetype i) const;

  void addCar(QSharedPointer<Car> car);
  void setCar(qsizetype i, QSharedPointer<Car> car);
  void deleteCar(qsizetype i);

  QSet<QString> getUniqOptions(const char *prop);

  QJsonDocument storeJSON() const;
  void loadJSON(QJsonDocument d);

  void openFile(QString filePath);

signals:
  void updated();

private slots:
  void saveFile();

private:
  QList<QSharedPointer<Car>> cars;
  QString filePath;
};