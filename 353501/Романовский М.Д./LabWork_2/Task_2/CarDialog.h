#pragma once

#include <QDialog>
#include <qdialog.h>
#include <qwidget.h>

class Car;

class CarDialog : public QDialog {
  Q_OBJECT

public:
  CarDialog(QSharedPointer<Car> car, QWidget *parent = nullptr);

private:
  QSharedPointer<Car> car;
};