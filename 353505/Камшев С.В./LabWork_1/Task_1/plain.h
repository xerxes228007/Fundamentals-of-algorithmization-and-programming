#ifndef PLAIN_H
#define PLAIN_H

#include "rectangle.h"

class plain: public rectangle
{
public:
    plain();

    QRectF wing, tail, chassis;

    void movement() override;
    void takeoff();
    void boarding();
    double getSpeedY();
    int getFlight();
    void release();
    void remove();
    bool getChassisReleased();

protected:
    bool chassisReleased = true;
    int flight = 0;
    double speed_y = 0;

    QTimer *timer_takeoff, *timer_boarding, *timer_chassis;
};

#endif // PLAIN_H
