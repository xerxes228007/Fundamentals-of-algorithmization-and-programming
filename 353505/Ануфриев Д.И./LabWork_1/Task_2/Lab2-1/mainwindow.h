#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QVector>
#include <QMessageBox>
#include <QValidator>

#include "paintscene.h"
#include "polygon.h"
#include "square.h"
#include "triangle.h"
#include "rhomb.h"
#include "rectangle.h"
#include "circle.h"
#include "hexagon.h"
#include "star5.h"
#include "star6.h"
#include "star8.h"
#include "pencil.h"

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

private slots:

    void on_square_clicked();

    void on_triangle_clicked();

    void on_rhomb_clicked();

    void on_rectangle_clicked();

    void on_circle_clicked();

    void on_hexagon_clicked();

    void on_star5_clicked();

    void on_star6_clicked();

    void on_star8_clicked();

private:

    Ui::MainWindow *ui;
    PaintScene *scene;

    QVector<Shape*> objects;
    QTimer *updatingScene;

signals:

    void addedToScene();

};
#endif // MAINWINDOW_H
