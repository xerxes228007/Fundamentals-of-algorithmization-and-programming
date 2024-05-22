#include "star6.h"

Star6::Star6(double externalRadius, double internalRadius)
{
    const int sides = 12;

    for (int i = 0; i < sides; ++i) {
        qreal angle = 2 * M_PI * i / sides;
        qreal x;
        qreal y;

        if(i % 2 == 0)
        {
            x = externalRadius * cos(angle);
            y = externalRadius * sin(angle);
        }

        else
        {
            x = internalRadius * cos(angle);
            y = internalRadius * sin(angle);
        }

        star6 << QPointF(x, y);
    }

    for(int i = 0; i < sides - 1; i++)
    {
        Area += (star6[i].x() * star6[i + 1].y() - star6[i].y() * star6[i + 1].x());
    }
    Area += (star6[sides - 1].x() * star6[0].y() - star6[sides - 1].y() * star6[0].x());
    Area = abs(Area) / 2;

    Perimetr += QLineF(star6[0], star6[1]).length() * sides;

    qreal x = 0, y = 0;

    for(int i = 0; i < sides; i++)
    {
        x += star6[i].x();
        y += star6[i].y();
    }

    x /= sides * 1.0;
    y /= sides * 1.0;


    originPoint = QPointF(x, y);
    setTransformOriginPoint(originPoint);

}

QRectF Star6::boundingRect() const
{
    return star6.boundingRect();
}

void Star6::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QColor(qRgb(56,145,160)));
    painter->drawPolygon(star6);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

QPainterPath Star6::shape() const {
    QPainterPath path;
    path.addPolygon(star6);
    return path;
}
