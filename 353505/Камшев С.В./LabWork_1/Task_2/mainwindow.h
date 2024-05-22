#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once

#include <QMainWindow>
#include <QPainter>
#include <QCursor>
#include <QPointF>
#include <QMouseEvent>
#include <QVector>
#include <QTimer>
#include <QMessageBox>
#include <QPair>



#include "circle.h"
#include "hexagon.h"
#include "rectangle.h"
#include "rhomb.h"
#include "square.h"
#include "star5.h"
#include "star6.h"
#include "star8.h"
#include "triangle.h"
#include "pen.h"
#include "figure.h"
#include "pentagon.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setValues();
    void valuesCalculating();

    QVector <QPointF> vec;

    QVector <figure*> figures_arr;


private slots:
    void on_nextFigureButton_clicked();

    void on_lastFigureButton_clicked();

    void on_horizontalSlider_actionTriggered(int action);

    void on_clearAllButton_clicked();

    void on_clearOneButton_clicked();

private:
    Ui::MainWindow *ui;
    bool click = false;

    int figureNumber = 0;

    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent (QWheelEvent * event);
    void setCentr();

    QPointF point1, point2 = QPointF(-1,-1), start_pos;
    QTimer *update_timer;
};
#endif // MAINWINDOW_H
