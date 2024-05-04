#include "shape.h"
#include "qgraphicsscene.h"
#include "qmenu.h"
#include <QDebug>
#include <mainwindow.h>
#include <QItemSelectionModel>

Shape::Shape(QGraphicsItem *parent) : QGraphicsItem(parent){
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsMovable);
    setCursor(Qt::OpenHandCursor);
    rotationAngle = 0.0;
    isScalingable = false;
    isRotatable = false;
    isDeleting = false;
    originalSize = 1;

    isMoving = false;
    isScaling = false;


    removeAct = contextMenu.addAction("Удалить");
    setScaleAct = contextMenu.addAction("Масштибировать по колесику мыши");
    setRotateAct = contextMenu.addAction("Поворачивать по колесику мыши");
    clearAct = contextMenu.addAction("Не использовать колесико мыши");

    clearAct->setVisible(false);
}

void Shape::wheelEvent(QGraphicsSceneWheelEvent *event) {
    isScaling = true;
    if (isRotatable)
    {
        qreal angleDelta = event->delta() / 30;
        rotateShape(angleDelta);
    }
    else if (isScalingable)
    {
        qreal delt = event->delta() / 1000.0;

        if(delt == 0) isScaling = false;

        if(originalSize + delt > 0.2 && originalSize + delt < 7)
        {
            originalSize += delt;
            setScale(originalSize);
            event->accept();
        }
    }

    QGraphicsItem::wheelEvent(event);
}

void Shape::rotateShape(qreal angle) {

    rotationAngle += angle;
    setRotation(rotationAngle);
}

void Shape::mousePressEvent(QGraphicsSceneMouseEvent *event) {

    if (event->button() == Qt::RightButton)
    {
        if (contains(event->pos()))
        {
            QAction *selectedAction = contextMenu.exec(event->screenPos());

            if (selectedAction == removeAct)
            {
                scene()->removeItem(this);
                emit isDeleted();
            }
            else if(selectedAction == setScaleAct)
            {
                isScalingable = true;
                isRotatable = false;

                setScaleAct->setVisible(false);
                setRotateAct->setVisible(true);

                clearAct->setVisible(true);
            }
            else if(selectedAction == setRotateAct)
            {
                isScalingable = false;
                isRotatable = true;

                setScaleAct->setVisible(true);
                setRotateAct->setVisible(false);

                clearAct->setVisible(true);
            }
            else if(selectedAction == clearAct)
            {
                isScalingable = false;
                isRotatable = false;

                setScaleAct->setVisible(true);
                setRotateAct->setVisible(true);

                clearAct->setVisible(false);
            }
        }
    }

    else if(event->button() == Qt::LeftButton)
    {
        isMoving = true;
        isScaling = true;
        setCursor(Qt::ClosedHandCursor);
    }


    QGraphicsItem::mousePressEvent(event);
}

void Shape::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    isMoving = false;
    isScaling = false;
    setCursor(Qt::OpenHandCursor);

    QGraphicsItem::mouseReleaseEvent(event);
}

double Shape::getArea()
{
   return Area * originalSize * originalSize;
}

double Shape::getPerimetr()
{
    return Perimetr * originalSize;
}

QPointF Shape::getCenter()
{
    return QPointF(mapToScene(QPointF(originPoint.x(), originPoint.y())));
}

bool Shape::getIsMoving()
{
    if(isMoving) return true;
    else return false;
}

bool Shape::getIsScaling()
{
    if(isScaling) return true;
    else return false;
}



