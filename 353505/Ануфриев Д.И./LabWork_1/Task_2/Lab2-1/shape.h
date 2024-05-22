#ifndef SHAPE_H
#define SHAPE_H

#include <QObject>

#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>
#include <QPointF>
#include <QCursor>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneWheelEvent>
#include <QKeyEvent>
#include <QAction>
#include <QSlider>
#include <QMenu>
#include <QAction>
#include <QEvent>

class Shape : public QObject, public QGraphicsItem{

Q_OBJECT

public:
    Shape(QGraphicsItem *parent = nullptr);

    void wheelEvent(QGraphicsSceneWheelEvent *event) override;
    void rotateShape(qreal angle);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    //virtual QRectF boundingRect() const override = 0;
    //virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override = 0;

    double getArea();
    double getPerimetr();
    QPointF getCenter();
    bool getIsMoving();
    bool getIsScaling();

protected:
    double Area;
    double Perimetr;
    qreal originalSize;
    QPointF originPoint;
    QMenu contextMenu;
    QAction *removeAct;
    QAction *setScaleAct;
    QAction *setRotateAct;
    QAction *clearAct;


    qreal rotationAngle;
    bool isScalingable;
    bool isScaling;
    bool isRotatable;
    bool isDeleting;
    bool isMoving;

private:



signals:
    void isDeleted();
};

#endif // SHAPE_H
