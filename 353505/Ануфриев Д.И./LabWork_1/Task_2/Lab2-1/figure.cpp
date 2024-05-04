#include "figure.h"

Figure::Figure(QVector<QPointF> points, QPainterPath path2) {

    figure = points;
    path = path2;

    qreal x = 0, y = 0;

    for(int i = 0; i < figure.size(); i++)
    {
        x += figure[i].x();
        y += figure[i].y();
    }

    x /= figure.size() * 1.0;
    y /= figure.size() * 1.0;


    originPoint = QPointF(x, y);
    setTransformOriginPoint(originPoint);
}

QRectF Figure::boundingRect() const
{
    return path.boundingRect();
}

void Figure::updatePath(const QPainterPath &newPath) {
    path = newPath;
    update();
}

void Figure::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;

    pen.setWidth(3);
    pen.setColor(Qt::black);

    painter->setPen(pen);
    painter->drawPath(path);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
