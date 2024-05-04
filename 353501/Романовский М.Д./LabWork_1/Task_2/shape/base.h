#pragma once

#include <QGraphicsItem>
#include <qformlayout.h>
#include <qgraphicsitem.h>
#include <qobject.h>
#include <qpainter.h>
#include <qtmetamacros.h>

#include "../animTrans.h"

class BaseShape: public QGraphicsObject {
Q_OBJECT

public:
  BaseShape(): QGraphicsObject() {
    trans = nullptr;
  }

  virtual void setupOptions(QFormLayout *form) = 0;
  virtual float area() = 0; 
  virtual float perimeter() = 0; 

  QString description();

  void attachTrans(AnimTrans *t);

protected:
  void beginPaint(QPainter *p);
  void endPaint(QPainter *p);

signals:
  void updated();

protected slots: 
  void updateSlot();

private:
  AnimTrans* trans;
};