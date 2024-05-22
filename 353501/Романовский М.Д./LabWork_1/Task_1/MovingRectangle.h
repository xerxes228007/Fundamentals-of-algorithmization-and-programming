#pragma once

#include <QGraphicsItem>
#include <QTimer>

class MovingRectangle : public QGraphicsObject {
  Q_OBJECT

public:
  MovingRectangle();

  virtual QRectF boundingRect() const;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget);

protected slots:
  void onTick();

protected:
  int dx;
  int x;

private:
  QTimer timer;
};