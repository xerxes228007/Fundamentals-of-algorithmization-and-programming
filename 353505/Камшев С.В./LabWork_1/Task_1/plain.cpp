#include "plain.h"

plain::plain() {
    wing = QRectF(( 2* rect.x() + rect.width()) / 2 - 10,( 2* rect.y() + rect.height()) / 2 - 5,20,10);
    tail = QRectF(rect.x(), rect.y() - 15, 10,15);
    chassis = QRectF(rect.x() + rect.width() - 20, rect.y() + rect.height()  , 10, 10);
}

void plain::movement()
{
    timer_movement = new QTimer(this);
    connect(timer_movement, &QTimer::timeout, [=](){
        if (rect.x() < 2400){
            rect.moveTo(rect.topLeft() + QPointF(speed_x, speed_y));
            wing.moveTo(wing.topLeft() + QPointF(speed_x, speed_y));
            tail.moveTo(tail.topLeft() + QPointF(speed_x, speed_y));
            chassis.moveTo(chassis.topLeft() + QPointF(speed_x, speed_y));

        }
        else{
            rect.setRect(0 - rect.width(), rect.y(), rect.width(), rect.height());
            wing.setRect(( 2* rect.x() + rect.width()) / 2 - 10,( 2* rect.y() + rect.height()) / 2 - 5,20,10);
            tail.setRect(rect.x(), rect.y() - 15, 10,15);
            chassis.setRect(rect.x() + rect.width() - 20, chassis.y() , 10, 10);
        }

    });
    timer_movement->start(30);
}

void plain::takeoff()
{
    if (flight == -1){
        timer_boarding->stop();
    }

    timer_takeoff = new QTimer(this);
    connect(timer_takeoff, &QTimer::timeout, [=](){
        flight = 1;
        if (rect.y() > 400){
            speed_y -= 0.3;
        }
        else{
            speed_y = 0;
            flight = 0;
            timer_takeoff->stop();
        }
    });
    timer_takeoff->start(30);
}

void plain::boarding()
{
    if (flight == 1){
        timer_takeoff->stop();
    }

    timer_boarding = new QTimer(this);
    connect(timer_boarding,&QTimer::timeout, [=](){
        flight = -1;
        if (rect.y() < 850){
            speed_y += 0.3;
        }
        else{
            speed_y = 0;
            flight = 0;
            rect.setRect(rect.x(), 860, rect.width(), rect.height());
            wing = QRectF(( 2* rect.x() + rect.width()) / 2 - 10,( 2* rect.y() + rect.height()) / 2 - 5,20,10);
            tail = QRectF(rect.x(), rect.y() - 15, 10,15);
            chassis = QRectF(rect.x() + rect.width() - 20, rect.y() + rect.height()  , 10, 10);
            timer_boarding->stop();
        }
    });
    timer_boarding->start(30);
}

double plain::getSpeedY()
{
    return speed_y;
}

int plain::getFlight()
{
    return flight;
}

void plain::release()
{
    timer_chassis = new QTimer(this);
    connect(timer_chassis, &QTimer::timeout, [=](){
        if (chassis.y() < rect.y() + rect.height()){
            chassis.moveTo(chassis.topLeft() + QPointF(0, 0.5));
        }
        else{
            timer_chassis->stop();
        }
    });
    timer_chassis->start(30);
    chassisReleased = true;
}

void plain::remove()
{
    timer_chassis = new QTimer(this);
    connect(timer_chassis, &QTimer::timeout, [=](){
        if (chassis.y() > rect.y() + rect.height() - 10){
            chassis.moveTo(chassis.topLeft() + QPointF(0, -0.5));
        }
        else{
            timer_chassis->stop();
        }
    });
    timer_chassis->start(30);
    chassisReleased = false;
}

bool plain::getChassisReleased()
{
    return chassisReleased;
}
