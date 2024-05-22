#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QTimer>
#include <QRectF>
#include <QPointF>

class rectangle: public QObject
{
public:
    rectangle();

    QTimer *timer_movement;

    QRectF rect;

    virtual void movement();
    void acceleration();
    void braking();

    double getSpeedX();
    int getTraffic();

protected:
    double speed_x = 0;
    int traffic = 0;
    QTimer *timer_boost, *timer_stop;


};

#endif // RECTANGLE_H
