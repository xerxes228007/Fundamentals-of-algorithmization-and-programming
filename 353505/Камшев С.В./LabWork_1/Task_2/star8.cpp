#include "star8.h"

star8::star8() {}

star8::star8(QPointF point1, QPointF point2)
{
    centrMass = QPointF(point1.x(), point2.y());
    len1 = (point1.y() - point2.y()) / 0.86;
    radius = sqrt(pow(centrMass.x() - point1.x(), 2) + pow(centrMass.y() - point1.y(), 2));

    double len_x = 0.5 *  len1;
    double len_y = 0.866 *  len1;
    double len_x2 = len1 * 0.7;
    double len_y2 = len1 * 0.7;


    nowPoints.append(point1);
    nowPoints.append(centrMass + QPointF(len_x, 0));
    nowPoints.append(centrMass + QPointF(0, -len_y));
    nowPoints.append(centrMass + QPointF(-len_x, 0));

    nowPoints.append(centrMass + QPointF(0, -len_x));
    nowPoints.append(centrMass + QPointF(len_y, 0));
    nowPoints.append(centrMass + QPointF(0, len_x));
    nowPoints.append(centrMass + QPointF(-len_y, 0));

    nowPoints.append(centrMass + QPointF(len_x2, -len_y2));
    nowPoints.append(centrMass + QPointF(-len_x * 0.6, -len_y2 * 0.5));
    nowPoints.append(centrMass + QPointF(-len_x2, len_y2));
    nowPoints.append(centrMass + QPointF(len_x * 0.6, len_y2 * 0.5));

    nowPoints.append(centrMass + QPointF(-len_x2, -len_y2));
    nowPoints.append(centrMass + QPointF(len_x * 0.6, -len_y2 * 0.5));
    nowPoints.append(centrMass + QPointF(len_x2, len_y2));
    nowPoints.append(centrMass + QPointF(-len_x * 0.6, len_y2 * 0.5));



    startPoints.append(point1);
    startPoints.append(centrMass + QPointF(len_x, 0));
    startPoints.append(centrMass + QPointF(0, -len_y));
    startPoints.append(centrMass + QPointF(-len_x, 0));

    startPoints.append(centrMass + QPointF(0, -len_x));
    startPoints.append(centrMass + QPointF(len_y, 0));
    startPoints.append(centrMass + QPointF(0, len_x));
    startPoints.append(centrMass + QPointF(-len_y, 0));

    startPoints.append(centrMass + QPointF(len_x2, -len_y2));
    startPoints.append(centrMass + QPointF(-len_x * 0.6, -len_y2 * 0.5));
    startPoints.append(centrMass + QPointF(-len_x2, len_y2));
    startPoints.append(centrMass + QPointF(len_x * 0.6, len_y2 * 0.5));

    startPoints.append(centrMass + QPointF(-len_x2, -len_y2));
    startPoints.append(centrMass + QPointF(len_x * 0.6, -len_y2 * 0.5));
    startPoints.append(centrMass + QPointF(len_x2, len_y2));
    startPoints.append(centrMass + QPointF(-len_x * 0.6, len_y2 * 0.5));

    for (int i = 0; i < startPoints.size(); ++i){
        speedReiszeArr.append(QPointF(0,0));
    }

    name = "Звезда8";

}

bool star8::pointInSide(QPointF point)
{
    if (pow(centrMass.x() - point.x(),2) + pow(centrMass.y() - point.y(),2) <= pow(radius,2)){
        return 1;
    }
    return 0;
}

void star8::areaCalculating()
{
    area = abs(len1 * len1 * 0.5 + len1 * len1 * 0.5 / 2 * 3);
}

void star8::perimetrCalculating()
{
    perimetr = abs(4 *  2/3 * len1 * 0.86 * 4);
}

void star8::draw(QPainter *paint)
{

    paint->drawLine(nowPoints[0], nowPoints[1]);
    paint->drawLine(nowPoints[1], nowPoints[2]);
    paint->drawLine(nowPoints[2], nowPoints[3]);
    paint->drawLine(nowPoints[3], nowPoints[0]);

    paint->drawLine(nowPoints[4], nowPoints[5]);
    paint->drawLine(nowPoints[5], nowPoints[6]);
    paint->drawLine(nowPoints[6], nowPoints[7]);
    paint->drawLine(nowPoints[7], nowPoints[4]);

    paint->drawLine(nowPoints[8], nowPoints[9]);
    paint->drawLine(nowPoints[9], nowPoints[10]);
    paint->drawLine(nowPoints[10], nowPoints[11]);
    paint->drawLine(nowPoints[11], nowPoints[8]);

    paint->drawLine(nowPoints[12], nowPoints[13]);
    paint->drawLine(nowPoints[13], nowPoints[14]);
    paint->drawLine(nowPoints[14], nowPoints[15]);
    paint->drawLine(nowPoints[15], nowPoints[12]);

    // QPen pen;
    // pen.setWidth(20);
    // paint->setPen(pen);
    // paint->drawPoint(centrMass);
    // pen.setWidth(1);
    // paint->setPen(pen);
}

void star8::radiusCalculating()
{
    radius = sqrt(pow(centrMass.x() - nowPoints[0].x(), 2) + pow(centrMass.y() - nowPoints[0].y(), 2));

}
