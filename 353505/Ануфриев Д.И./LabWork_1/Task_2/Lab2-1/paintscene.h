#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <pencil.h>

class PaintScene : public QGraphicsScene
{
public:
    PaintScene(QObject *parent = nullptr);

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override ;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    void turnOnPencil();
    void turnOffPencil();
private:
    Pencil* pencil;
};

#endif // PAINTSCENE_H
