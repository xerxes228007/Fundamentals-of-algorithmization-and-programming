#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include "rectangle.h"
#include <QMessageBox>
#include "plain.h"

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
    int n1 = 10, n2 = 10;

    rectangle Rectangle;
    plain Plain;

protected:
    void paintEvent(QPaintEvent *event);
    QTimer *timer_update;

private slots:
    void on_overclocking_clicked();

    void on_brakin_clicked();

    void on_takeoff_clicked();

    void on_boarding_clicked();

    void on_removeChassis_clicked();

    void on_releaseChassis_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
