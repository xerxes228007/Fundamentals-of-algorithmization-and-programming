#include "drawView.h"
#include <QMouseEvent>
#include <qdialog.h>
#include <qgraphicsview.h>
#include <qnamespace.h>
#include <qobject.h>
#include <qpoint.h>

DrawingView::DrawingView(QWidget *parent) : QGraphicsView(parent), scene(this) {
  setScene(&scene);
  setFixedSize(400, 400);
  scene.setSceneRect(-100, -100, 200, 200);
}

void DrawingView::mouseMoveEvent(QMouseEvent *e) {
  double rad = 1;
  QPointF pt = mapToScene(e->pos());
  points << QPointF(pt.x() - 6, pt.y() - 6);
  scene.addEllipse(pt.x() - 6, pt.y() - 6, 12, 12, Qt::NoPen, Qt::red);
}

QVector<QPointF> DrawingView::getPoints() { return points; }