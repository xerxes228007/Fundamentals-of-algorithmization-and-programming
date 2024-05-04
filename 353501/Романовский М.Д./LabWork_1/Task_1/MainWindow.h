#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>

class Car;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow();

private slots:
  void onClick();

protected:
  Car *car;
  QGraphicsScene scene;
  Ui::MainWindow *ui;
};