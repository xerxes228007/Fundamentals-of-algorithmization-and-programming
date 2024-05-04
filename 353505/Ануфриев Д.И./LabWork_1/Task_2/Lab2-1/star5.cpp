#include "star5.h"
#include "dialogcircle.h"
#include "qgraphicsscene.h"
#include "qtimer.h"

Star5::Star5(double externalRadius_, double internalRadius_)
{
    //setTransformOriginPoint(boundingRect().width() / 2.0, boundingRect().height() / 2.0);

    externalRadius = externalRadius_;
    internalRadius = internalRadius_;

    const int sides = 10;

    for (int i = 0; i < sides; ++i) {
        qreal angle = 2 * M_PI * i / sides - M_PI / 10;
        qreal x;
        qreal y;

        if(i % 2 == 0)
        {
            x = externalRadius * cos(angle);
            y = externalRadius * sin(angle);
        }

        else
        {
            x = internalRadius * cos(angle);
            y = internalRadius * sin(angle);
        }

        star5 << QPointF(x, y);
    }

    for(int i = 0; i < sides - 1; i++)
    {
        Area += (star5[i].x() * star5[i + 1].y() - star5[i].y() * star5[i + 1].x());
    }
    Area += (star5[sides - 1].x() * star5[0].y() - star5[sides - 1].y() * star5[0].x());
    Area = abs(Area) / 2;

    Perimetr += QLineF(star5[0], star5[1]).length() * sides;


    qreal x = 0, y = 0;

    for(int i = 0; i < sides; i++)
    {
        x += star5[i].x();
        y += star5[i].y();
    }

    x /= sides * 1.0;
    y /= sides * 1.0;


    originPoint = QPointF(x, y);
    setTransformOriginPoint(originPoint);


    setRadiuses = contextMenu.addAction("Изменить внутренний и внешний радиусы");
}

void Star5::mousePressEvent(QGraphicsSceneMouseEvent *event) { // то что и в фигуре, но добавили контекстную кнопку

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
            else if (selectedAction == setRadiuses)
            {
                DialogStar5* dialog = new DialogStar5();

                connect(dialog, &DialogStar5::setNewRadiuses, [this, dialog](){

                    externalRadius = dialog->getNewExternalRadius();
                    internalRadius = dialog->getNewInternalRadius();

                    star5.clear();

                    const int sides = 10;

                    for (int i = 0; i < sides; ++i) {
                        qreal angle = 2 * M_PI * i / sides - M_PI / 10;
                        qreal x;
                        qreal y;

                        if(i % 2 == 0)
                        {
                            x = externalRadius * cos(angle);
                            y = externalRadius * sin(angle);
                        }

                        else
                        {
                            x = internalRadius * cos(angle);
                            y = internalRadius * sin(angle);
                        }

                        star5 << QPointF(x, y);
                    }

                    for(int i = 0; i < sides - 1; i++)
                    {
                        Area += (star5[i].x() * star5[i + 1].y() - star5[i].y() * star5[i + 1].x());
                    }
                    Area += (star5[sides - 1].x() * star5[0].y() - star5[sides - 1].y() * star5[0].x());
                    Area = abs(Area) / 2;

                    Perimetr += QLineF(star5[0], star5[1]).length() * sides;


                    qreal x = 0, y = 0;

                    for(int i = 0; i < sides; i++)
                    {
                        x += star5[i].x();
                        y += star5[i].y();
                    }

                    x /= sides * 1.0;
                    y /= sides * 1.0;


                    originPoint = QPointF(x, y);
                    setTransformOriginPoint(originPoint);





                    isScaling = true;



                    QTimer timer; // отключение бесконечного обновления

                    timer.singleShot(20, this, [=](){//
                        isScaling = false;//
                    });//

                });

                dialog->setValues(internalRadius, externalRadius);
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


QRectF Star5::boundingRect() const
{
    return star5.boundingRect();
}

void Star5::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::lightGray);
    painter->drawPolygon(star5);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

QPainterPath Star5::shape() const {
    QPainterPath path;
    path.addPolygon(star5);
    return path;
}
