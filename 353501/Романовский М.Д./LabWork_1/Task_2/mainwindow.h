#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "animTrans.h"
#include "shape/base.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    
protected slots:
    void shapeChanged(int newI);
    void shapeUpdated();
    void animUpdate();

private:
    QGraphicsScene scene;
    BaseShape *currentShape;

    Ui::MainWindow *ui;
    QString currentFile;

    AnimTrans animTrans;
};
