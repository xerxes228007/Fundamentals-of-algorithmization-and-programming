#include "MainWindow.h"
#include "Car.h"
#include "ui_MainWindow.h"
#include <qcheckbox.h>

MainWindow::MainWindow() : ui(new Ui::MainWindow), scene() {
  ui->setupUi(this);

  ui->graphicsView->setScene(&scene);
  ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

  car = new Car;

  scene.addItem(car);

  connect(ui->lightBox, &QCheckBox::clicked, car, &Car::setLights);
  connect(ui->doorBox, &QCheckBox::clicked, car, &Car::setDoor);
}

void MainWindow::onClick() {}