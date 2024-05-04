#include <qcombobox.h>
#include <qlogging.h>
#include <qspinbox.h>
#include <qwidget.h>

#include "animTrans.h"
#include "mainwindow.h"
#include "shape/custom.h"
#include "shape/shield.h"
#include "ui_mainwindow.h"

#include "shape/base.h"
#include "shape/circle.h"
#include "shape/hexagon.h"
#include "shape/rect.h"
#include "shape/rhombus.h"
#include "shape/shield.h"
#include "shape/square.h"
#include "shape/star.h"
#include "shape/triangle.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), scene(), ui(new Ui::MainWindow), currentShape(0) {
  ui->setupUi(this);

  ui->shapeInp->addItems({"Circle", "Square", "Triangle", "Rhombus",
                          "Rectangle", "Hexagon", "Star", "Shield", "Custom"});

  ui->graphicsView->setScene(&scene);
  ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

  connect(ui->shapeInp, &QComboBox::activated, this, &MainWindow::shapeChanged);
  connect(&animTrans, &AnimTrans::animationUpdate, this, &MainWindow::animUpdate);
  
  connect(ui->xInp, &QSpinBox::valueChanged, [&](int value) {
    animTrans.setTargetX(value);
  });
  connect(ui->yInp, &QSpinBox::valueChanged, [&](int value) {
    animTrans.setTargetY(value);
  });
  connect(ui->rotInp, &QSpinBox::valueChanged, [&](int value) {
    animTrans.setTargetRotation(value);
  });
  connect(ui->scaleInp, &QSpinBox::valueChanged, [&](int value) {
    animTrans.setTargetScale(value / 100.);
  });

  connect(ui->transPointX, &QSpinBox::valueChanged, [&](int value) {
    animTrans.setTransX(value);
  });

  connect(ui->transPointY, &QSpinBox::valueChanged, [&](int value) {
    animTrans.setTransY(value);
  });

  shapeChanged(0);
  animUpdate();
}

void MainWindow::shapeChanged(int s) {
  if (currentShape) {

    while (ui->shapeProps->rowCount() > 0) {
      // Inputs themeselves are removed when delete currentShape is called
      QLayoutItem *layoutItem = ui->shapeProps->takeRow(0).labelItem;
      if (layoutItem)
        delete layoutItem->widget();
    }

    scene.removeItem((QGraphicsItem *)currentShape);
    delete currentShape;
  }

  if (s == 0) {
    currentShape = (BaseShape *)new CircleShape;
  } else if (s == 1) {
    currentShape = (BaseShape *)new SquareShape;
  } else if (s == 2) {
    currentShape = (BaseShape *)new TriangleShape;
  } else if (s == 3) {
    currentShape = (BaseShape *)new RhombusShape;
  } else if (s == 4) {
    currentShape = (BaseShape *)new RectShape;
  } else if (s == 5) {
    currentShape = (BaseShape *)new HexagonShape;
  } else if (s == 6) {
    currentShape = (BaseShape *)new StarShape;
  } else if (s == 7) {
    currentShape = (ShieldShape *)new ShieldShape;
  } else if (s == 8) {
    currentShape = (CustomShape *)new CustomShape;
  } else {
    assert(0);
  }

  currentShape->attachTrans(&animTrans);
  currentShape->setupOptions(ui->shapeProps);
  scene.addItem((QGraphicsItem *)currentShape);

  connect(currentShape, &BaseShape::updated, this, &MainWindow::shapeUpdated);
  shapeUpdated();
}

void MainWindow::shapeUpdated() {
  ui->shapeDesc->setText(currentShape->description());
}

void MainWindow::animUpdate() {

  ui->xCur->setText(QString::number(animTrans.x));
  ui->yCur->setText(QString::number(animTrans.y));

  ui->rotCur->setText(QString::number(animTrans.rotation));
  ui->scaleCur->setText(QString::number(animTrans.scale / 100));
}