#include "circle.h"
#include "qgraphicsscene.h"
#include "qtimer.h"

Circle::Circle(double newRadius) {
    radius = newRadius;

    Area = radius * radius * M_PI;
    Perimetr = 2 * M_PI * radius;

    originPoint = QPointF(0, 0);
    setTransformOriginPoint(originPoint);
    setRadius = contextMenu.addAction("Задать новый радиус");
}

QRectF Circle::boundingRect() const {
    return QRectF(-radius, -radius, radius * 2, radius * 2);
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(Qt::magenta);

    painter->drawEllipse(-radius, -radius, 2 * radius, 2 * radius);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

void Circle::mousePressEvent(QGraphicsSceneMouseEvent *event) { // то что и в фигуре, но добавили контекстную кнопку

    if (event->button() == Qt::RightButton)
    {
        if (contains(event->pos())) {
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
            else if (selectedAction == setRadius)
            {
                DialogCircle* dialog = new DialogCircle();

                connect(dialog, &DialogCircle::setNewRadius, [this, dialog](){

                    originalSize = dialog->getNewRadius() / radius;
                    setScale(originalSize);

                    isScaling = true;



                    QTimer timer; // отключение бесконечного обновления

                    timer.singleShot(20, this, [=](){//
                        isScaling = false;//
                    });//

                });

                qDebug() << radius * originalSize;

                dialog->setValue(radius * originalSize);
                dialog->exec();
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

QPainterPath Circle::shape() const {
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}
