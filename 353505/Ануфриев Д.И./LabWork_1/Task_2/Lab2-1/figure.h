#ifndef FIGURE_H
#define FIGURE_H

#include "shape.h"

class Figure : public Shape
{
public:
    Figure(QVector<QPointF>, QPainterPath);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void updatePath(const QPainterPath &newPath);

private:
    QVector<QPointF> figure;
    QPainterPath path;
};

#endif // FIGURE_H
