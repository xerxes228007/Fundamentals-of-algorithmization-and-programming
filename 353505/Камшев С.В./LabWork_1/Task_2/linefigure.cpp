#include "linefigure.h"

lineFigure::lineFigure() {}

void lineFigure::areaCalculating(){}

void lineFigure::perimetrCalculating(){}

bool lineFigure::pointInSide(QPointF point){}

void lineFigure::draw(QPainter *paint)
{
    for (int i = 0; i < nowPoints.size();++i){
        paint->drawLine(nowPoints[i], nowPoints[(i+1) % nowPoints.size()]);

    }
}

