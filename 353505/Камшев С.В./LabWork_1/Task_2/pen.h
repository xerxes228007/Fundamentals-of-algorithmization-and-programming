#ifndef PEN_H
#define PEN_H
#include "figure.h"

class pen: public figure
{
public:
    pen();
    pen(QVector <QPointF> points);

    void areaCalculating() override;
    void perimetrCalculating() override;
    void draw(QPainter *paint) override;
    bool pointInSide(QPointF point) override;
    void radiusCalculating() override;

};

#endif // PEN_H
