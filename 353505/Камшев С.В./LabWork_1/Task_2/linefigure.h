#ifndef LINEFIGURE_H
#define LINEFIGURE_H

#include "figure.h"

class lineFigure: public figure
{
public:
    lineFigure();

    virtual void areaCalculating() override;
    virtual void perimetrCalculating() override;
    bool pointInSide(QPointF point) override;
    void draw(QPainter *paint) override;

};

#endif // LINEFIGURE_H
