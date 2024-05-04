#pragma once

#include "base.h"
#include <QPushButton>
#include <QSpinBox>
#include <qformlayout.h>
#include <qpoint.h>
#include <qtmetamacros.h>

class DrawingView;

class CustomShape : public BaseShape {
  QPushButton btn;

public:
  CustomShape();

  QRectF boundingRect() const;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget);

  void setupOptions(QFormLayout *form);

  float area();
  float perimeter();

private slots:
  void openDrawer();
  void drawingClosed();

private:
  QDialog *drawingDialog;
  DrawingView *drawingView;
  QVector<QPointF> points;
};