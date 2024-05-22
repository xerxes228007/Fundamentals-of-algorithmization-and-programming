#include "star8.h"

Star8::Star8(double externalRadius, double internalRadius)
{
    const int sides = 16;

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

        star8 << QPointF(x, y);
    }

    for(int i = 0; i < sides - 1; i++)
    {
        Area += (star8[i].x() * star8[i + 1].y() - star8[i].y() * star8[i + 1].x());
    }
    Area += (star8[sides - 1].x() * star8[0].y() - star8[sides - 1].y() * star8[0].x());
    Area = abs(Area) / 2;

    Perimetr += QLineF(star8[0], star8[1]).length() * sides;




    qreal x = 0, y = 0;

    for(int i = 0; i < sides; i++)
    {
        x += star8[i].x();
        y += star8[i].y();
    }

    x /= sides * 1.0;
    y /= sides * 1.0;


    originPoint = QPointF(x, y);
    setTransformOriginPoint(originPoint);

}

QRectF Star8::boundingRect() const
{
    return star8.boundingRect();
}

void Star8::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QColor(qRgb(130,100,90)));
    painter->drawPolygon(star8);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

QPainterPath Star8::shape() const
{
    QPainterPath path;
    path.addPolygon(star8);
    return path;
}
