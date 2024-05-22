#include "triangle.h"

Triangle::Triangle(QPointF p1, QPointF p2, QPointF p3){

    qreal cx, cy;

    cx = (p3.x() - p1.x()) / 2;
    cy = (p1.y() + p2.y() + p3.y()) / 3;

    QPointF cpoint(cx, cy);

    triangle << p1 - cpoint << p2 - cpoint << p3 - cpoint;

    const int sides = 3;

    for(int i = 0; i < sides - 1; i++)
    {
        Area += (triangle[i].x() * triangle[i + 1].y() - triangle[i].y() * triangle[i + 1].x());
    }
    Area += (triangle[sides - 1].x() * triangle[0].y() - triangle[sides - 1].y() * triangle[0].x());
    Area = abs(Area) / 2;

    Perimetr += QLineF(p1, p2).length() + QLineF(p2, p3).length() + QLineF(p3, p1).length();




    qreal x = 0, y = 0;

    for(int i = 0; i < sides; i++)
    {
        x += triangle[i].x();
        y += triangle[i].y();
    }

    x /= sides * 1.0;
    y /= sides * 1.0;


    originPoint = QPointF(x, y);
    setTransformOriginPoint(originPoint);

}

QRectF Triangle::boundingRect() const {
    return triangle.boundingRect();
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    painter->setBrush(Qt::blue);
    painter->drawPolygon(triangle);


    Q_UNUSED(option)
    Q_UNUSED(widget)
}

QPainterPath Triangle::shape() const {
    QPainterPath path;
    path.addPolygon(triangle);
    return path;
}
