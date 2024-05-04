#include "pencil.h"
#include "qgraphicsscene.h"
#include "qgraphicssceneevent.h"

Pencil::Pencil(){
    drawing = false;
    tempFigure = nullptr;
}

QRectF Pencil::boundingRect() const {
    return QRectF();
}

void Pencil::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)  {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    Q_UNUSED(painter);
}

void Pencil::mousePressEvent(QGraphicsSceneMouseEvent *event)  {
    if(scene())
    {
        if (event->button() == Qt::LeftButton) {

            drawing = true;
            points.clear();

            points.push_back(mapToScene((event->scenePos())));
            path.moveTo(points.back());

            tempFigure = new Figure(points, path);
            scene()->addItem(tempFigure);

            update();
        }
    }
}

void Pencil::mouseMoveEvent(QGraphicsSceneMouseEvent *event)  {
    if (scene() && drawing) {
        points.push_back((QPointF(event->scenePos())));
        path.lineTo(points.back());

        tempFigure->updatePath(path);

        update();
    }
}

void Pencil::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)  {
    if (scene() && event->button() == Qt::LeftButton && drawing) {
        drawing = false;

        delete tempFigure;
        tempFigure = nullptr;

        Figure* newFigure = new Figure(points, path);

        scene()->addItem(newFigure);

        points.clear();
        path.clear();


        update();
    }
}
