#include "paintscene.h"

PaintScene::PaintScene(QObject *parent) {

    pencil = new Pencil();
    // this->addItem(pencil);
}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mousePressEvent(event);
    if(this->selectedItems().isEmpty()) pencil->mousePressEvent(event);
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseMoveEvent(event);
    if(this->selectedItems().isEmpty()) pencil->mouseMoveEvent(event);
}

void PaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseReleaseEvent(event);
    if(this->selectedItems().isEmpty()) pencil->mouseReleaseEvent(event);
}

void PaintScene::turnOnPencil()
{
    this->addItem(pencil);
}

void PaintScene::turnOffPencil()
{
    this->removeItem(pencil);
}
