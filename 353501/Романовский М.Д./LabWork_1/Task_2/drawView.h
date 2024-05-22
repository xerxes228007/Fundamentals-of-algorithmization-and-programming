#include <QDialog>
#include <qdialog.h>
#include <qgraphicsview.h>
#include <qpoint.h>

class DrawingView : public QGraphicsView {
public:
  DrawingView(QWidget *parent = nullptr);

  QVector<QPointF> getPoints();
  
protected:
  void mouseMoveEvent(QMouseEvent *e);

private:
  QGraphicsScene scene;

  QVector<QPointF> points;
};