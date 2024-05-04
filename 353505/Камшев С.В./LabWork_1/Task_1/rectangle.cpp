#include "rectangle.h"

rectangle::rectangle() {
    rect = QRectF(30, 860, 70,20);
}

void rectangle::movement()
{
    timer_movement = new QTimer(this);
    connect(timer_movement, &QTimer::timeout, [=](){
        if (rect.x() < 2400){
            rect.moveTo(rect.topLeft() + QPointF(speed_x, 0));
        }
        else{
            rect.setRect(0 - rect.width(), rect.y(), rect.width(), rect.height());
        }

    });
    timer_movement->start(30);

}

void rectangle::acceleration()
{
    if (traffic == -1){
        timer_stop->stop();
    }

    timer_boost = new QTimer(this);
    connect(timer_boost, &QTimer::timeout, [=](){
        traffic = 1;

                if (speed_x < 30){
                    speed_x += 0.3;
                }
                else{
                    timer_boost->stop();
                }
            });
    timer_boost->start(30);
}

void rectangle::braking()
{
    if (traffic == 1){
        timer_boost->stop();

        timer_stop = new QTimer(this);
        connect(timer_stop,&QTimer::timeout, [=](){
                    traffic = -1;
                    if (speed_x > 1){
                        speed_x -= 0.3;
                    }
                    else{
                        speed_x = 0;
                        traffic = 0;
                        timer_stop->stop();
                    }
                });
        timer_stop->start(30);
    }
}

double rectangle::getSpeedX()
{
    return speed_x;
}

int rectangle::getTraffic()
{
    return traffic;
}
