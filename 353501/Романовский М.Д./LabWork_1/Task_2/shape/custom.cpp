#include "custom.h"
#include "../drawView.h"
#include <QPainter>
#include <cmath>
#include <qdialog.h>
#include <qformlayout.h>
#include <qnamespace.h>
#include <qobject.h>
#include <qpushbutton.h>
#include <qspinbox.h>

CustomShape::CustomShape() : btn() {
  btn.setText("DRAW SHAPE");
  connect(&btn, &QPushButton::clicked, this, &CustomShape::openDrawer);
  drawingDialog = nullptr;
}

void CustomShape::paint(QPainter *painter,
                        const QStyleOptionGraphicsItem *option,
                        QWidget *widget) {

  beginPaint(painter);
  painter->setPen(Qt::NoPen);
  for (auto p : points) {
    qDebug() << "POINT TO DRAW";
    painter->drawEllipse(p, 6, 6);
  }
  endPaint(painter);
}

QRectF CustomShape::boundingRect() const {
  return QRectF(-100, -100, 100 * 2, 100 * 2);
}

void CustomShape::setupOptions(QFormLayout *form) { form->addRow("", &btn); }

float CustomShape::area() { return -1; }

float CustomShape::perimeter() { return -1; }

void CustomShape::openDrawer() {
  if (drawingDialog) {
    drawingDialog->show();
    return;
  }

  drawingDialog = new QDialog;
  drawingView = new DrawingView(drawingDialog);
  drawingDialog->setWindowTitle("Draw custom shape");
  drawingDialog->setFixedSize(400, 400);
  drawingDialog->show();

  connect(drawingDialog, &QDialog::finished, this, &CustomShape::drawingClosed);
}

void CustomShape::drawingClosed() {
  points = drawingView->getPoints();
  updateSlot();
  qDebug() << "upate TO DRAW";
  delete drawingView;
  delete drawingDialog;
  drawingDialog = nullptr;
  drawingView = nullptr;
}