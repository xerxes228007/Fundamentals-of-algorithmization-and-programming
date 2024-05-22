#include "square.h"
#include "qgraphicsscene.h"
#include "qtimer.h"

Square::Square(qreal newside)
{
    side = newside;

    const int sides = 4;

    square << QPointF(-side / 2, side / 2) << QPointF(side / 2, side / 2) << QPointF(side / 2, - side / 2) << QPointF(- side / 2, - side / 2);

    for(int i = 0; i < sides - 1; i++)
    {
        Area += (square[i].x() * square[i + 1].y() - square[i].y() * square[i + 1].x());
    }
    Area += (square[sides - 1].x() * square[0].y() - square[sides - 1].y() * square[0].x());
    Area = abs(Area) / 2;

    Perimetr += side * 4;



    qreal x = 0, y = 0;

    for(int i = 0; i < sides; i++)
    {
        x += square[i].x();
        y += square[i].y();
    }

    x /= sides * 1.0;
    y /= sides * 1.0;


    originPoint = QPointF(x, y);
    setTransformOriginPoint(originPoint);

    setSide = contextMenu.addAction("Задать новую длину стороны");

}

void Square::mousePressEvent(QGraphicsSceneMouseEvent *event) { // то что и в фигуре, но добавили контекстную кнопку

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
            else if (selectedAction == setSide)
            {
                DialogSquare* dialog = new DialogSquare();

                connect(dialog, &DialogSquare::setNewSide, [this, dialog](){

                    originalSize = dialog->getNewSide() / side;
                    setScale(originalSize);

                    isScaling = true;



                    QTimer timer; // отключение бесконечного обновления

                    timer.singleShot(20, this, [=](){//
                        isScaling = false;//
                    });//

                });

                dialog->setValue(side * originalSize);
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

QRectF Square::boundingRect() const {
    return square.boundingRect();
}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(Qt::red);
    painter->drawPolygon(square);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
