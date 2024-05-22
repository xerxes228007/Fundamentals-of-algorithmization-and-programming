#include "mainwindow.h"

#include <QDebug>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->horizontalSlider->setRange(1, 100);
    ui->horizontalSlider->setValue(50);
    update_timer = new QTimer(this);
    ui->moveTrianglePointsRadio->hide();

    connect(update_timer, &QTimer::timeout,[=]()
            {
                update();
                setValues();

                if (figures_arr.size() > 0){
                    figures_arr[figureNumber - 1]->radiusCalculating();
                    valuesCalculating();
                    ui->horizontalSlider->setValue(figures_arr[figureNumber - 1]->getSize());

                    if (figures_arr[figureNumber - 1]->getName() == "Треугольник"){
                        ui->moveTrianglePointsRadio->show();
                    }
                    else{
                        ui->moveTrianglePointsRadio->hide();
                    }
                }
                else{
                    ui->horizontalSlider->setValue(50);
                }
            });
    update_timer->start(30);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setValues()
{
    if (figures_arr.size() > 0){
        ui->AreaLable->setText(QString::number(figures_arr[figureNumber - 1]->getArea()));
        ui->PerLable->setText(QString::number(figures_arr[figureNumber - 1]->getPerimetr()));
        ui->CentrLable->setText(QString::number(figures_arr[figureNumber - 1]->getCentre().x()) + " " + QString::number(figures_arr[figureNumber - 1]->getCentre().y()));
    }
    else{
        ui->AreaLable->setText("");
        ui->PerLable->setText("");
        ui->CentrLable->setText("");
    }

}

void MainWindow::valuesCalculating()
{
    figures_arr[figureNumber - 1]->areaCalculating();
    figures_arr[figureNumber - 1]->perimetrCalculating();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);

    if (ui->circkeRadio->isChecked()){
        if (click){

            if (point2 != QPointF(-1,-1) && !QApplication::mouseButtons()){

                circle* circ = new circle(point1, point2);
                circ->perimetrCalculating();
                circ->areaCalculating();
                point2 = QPointF(-1, -1);
                click = false;
                figures_arr.push_back(circ);
                figureNumber = figures_arr.size();
            }
            else if (point2 != QPointF(-1,-1) && QApplication::mouseButtons()){
                circle circ(point1, point2);
                circ.draw(&paint);
            }
        }
    }

    if (ui->rectangleRadio->isChecked()){
        if (click){
            if (point2 != QPointF(-1,-1) && !QApplication::mouseButtons()){
                rectangle* rect = new rectangle(point1, point2);
                rect->perimetrCalculating();
                rect->areaCalculating();
                click = false;
                figures_arr.push_back(rect);
                figureNumber = figures_arr.size();
                point2 = QPointF(-1, -1);

            }
            else if (point2 != QPointF(-1,-1) && QApplication::mouseButtons()){
                rectangle rect(point1, point2);
                rect.draw(&paint);
            }
        }
    }

    if (ui->squareRadio->isChecked()){
        if (click){
            if (point2 != QPointF(-1,-1) && !QApplication::mouseButtons()){
                square* sq = new square(point1, point2);
                sq->perimetrCalculating();
                sq->areaCalculating();
                point2 = QPointF(-1, -1);
                click = false;
                figures_arr.push_back(sq);
                figureNumber = figures_arr.size();

            }
            else if (point2 != QPointF(-1,-1) && QApplication::mouseButtons()){
                square sq(point1, point2);
                sq.draw(&paint);
            }
        }
    }

    if (ui->HexRadio->isChecked()){
        if (click){
            if (point2 != QPointF(-1,-1) && !QApplication::mouseButtons()){
                hexagon* hex = new hexagon(point1, point2);
                hex->perimetrCalculating();
                hex->areaCalculating();
                point2 = QPointF(-1, -1);
                click = false;
                figures_arr.push_back(hex);
                figureNumber = figures_arr.size();
            }
            else if (point2 != QPointF(-1,-1) && QApplication::mouseButtons()){
                hexagon hex(point1, point2);
                hex.draw(&paint);
            }
        }
    }

    if (ui->star5Radio->isChecked()){
        if (click){
            if (point2 != QPointF(-1,-1) && !QApplication::mouseButtons()){
                star5* Star5 = new star5(point1, point2);
                Star5->perimetrCalculating();
                Star5->areaCalculating();
                point2 = QPointF(-1, -1);
                click = false;
                figures_arr.push_back(Star5);
                figureNumber = figures_arr.size();
            }
            else if (point2 != QPointF(-1,-1) && QApplication::mouseButtons()){
                star5 Star5(point1, point2);
                Star5.draw(&paint);
            }
        }
    }

    if (ui->rhombRadio->isChecked()){
        if (click){
            if (point2 != QPointF(-1,-1) && !QApplication::mouseButtons()){
                rhomb* Rhomb = new rhomb(point1, point2);
                Rhomb->perimetrCalculating();
                Rhomb->areaCalculating();
                point2 = QPointF(-1, -1);
                click = false;
                figures_arr.push_back(Rhomb);
                figureNumber = figures_arr.size();
            }
            else if (point2 != QPointF(-1,-1) && QApplication::mouseButtons()){
                rhomb Rhomb(point1, point2);
                Rhomb.draw(&paint);
            }
        }
    }


    if (ui->pentagonRadio->isChecked()){
        if (click){
            if (point2 != QPointF(-1,-1) && !QApplication::mouseButtons()){
                pentagon* pent = new pentagon(point1, point2);
                pent->perimetrCalculating();
                pent->areaCalculating();
                point2 = QPointF(-1, -1);
                click = false;
                figures_arr.push_back(pent);
                figureNumber = figures_arr.size();
            }
            else if (point2 != QPointF(-1,-1) && QApplication::mouseButtons()){
                pentagon pent(point1, point2);
                pent.draw(&paint);
            }
        }
    }


    if (ui->star6Radoi->isChecked()){
        if (click){
            if (point2 != QPointF(-1,-1) && !QApplication::mouseButtons()){
                star6* Star6 = new star6(point1, point2);
                Star6->perimetrCalculating();
                Star6->areaCalculating();
                point2 = QPointF(-1, -1);
                click = false;
                figures_arr.push_back(Star6);
                figureNumber = figures_arr.size();
            }
            else if (point2 != QPointF(-1,-1) && QApplication::mouseButtons()){
                star6 Star6(point1, point2);
                Star6.draw(&paint);
            }
        }
    }


    if (ui->star8Radoi->isChecked()){
        if (click){
            if (point2 != QPointF(-1,-1) && !QApplication::mouseButtons()){
                star8* Star8 = new star8(point1, point2);
                Star8->perimetrCalculating();
                Star8->areaCalculating();
                point2 = QPointF(-1, -1);
                click = false;
                figures_arr.push_back(Star8);
                figureNumber = figures_arr.size();
            }
            else if (point2 != QPointF(-1,-1) && QApplication::mouseButtons()){
                star8 Star8(point1, point2);
                Star8.draw(&paint);
            }
        }
    }



    if (ui->triangleRadio->isChecked()){
        if (click){
            if (point2 != QPointF(-1,-1) && !QApplication::mouseButtons()){
                triangle* trian = new triangle(point1, point2);
                trian->perimetrCalculating();
                trian->areaCalculating();
                point2 = QPointF(-1, -1);
                click = false;
                figures_arr.push_back(trian);
                figureNumber = figures_arr.size();
            }
            else if (point2 != QPointF(-1,-1) && QApplication::mouseButtons()){
                triangle trian(point1, point2);
                trian.draw(&paint);
            }
        }
    }

    if (ui->penRadoi->isChecked()){

        if (point2 != QPointF(-1,-1) && !QApplication::mouseButtons()){
            if (vec.size() > 0){
                pen* p = new pen(vec);
                p->perimetrCalculating();
                p->areaCalculating();
                point2 = QPointF(-1, -1);
                figures_arr.push_back(p);
                figureNumber = figures_arr.size();
                vec.clear();
            }
        }
        else if (point2 != QPointF(-1,-1) && QApplication::mouseButtons()){
            if (vec.size() > 0){
                pen p(vec);
                p.draw(&paint);
            }
        }
    }

    for(int i = 0; i < figures_arr.size(); ++i){
        if (i == figureNumber - 1){
        paint.setPen(Qt::red);
        }
        figures_arr[i]->draw(&paint);
        paint.setPen(Qt::black);
    }


}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button()== Qt::LeftButton){
        if (ui->hendRadio->isChecked()){
            start_pos = event->pos();
        }
        else if (!click && ( ui->circkeRadio->isChecked() || ui->HexRadio->isChecked() || ui->pentagonRadio->isChecked() || ui->rectangleRadio->isChecked() || ui->rhombRadio->isChecked() || ui->squareRadio->isChecked() || ui->star5Radio->isChecked() || ui->star6Radoi->isChecked() || ui->star8Radoi->isChecked() || ui->triangleRadio->isChecked())){
            point1 = event->pos();
            click = true;
        }
        else if (ui->penRadoi->isChecked() ){
            point1 = event->pos();
        }
        else if (ui->moveTrianglePointsRadio->isChecked()){
            point1 = event->pos();
        }
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{

    point2 = event->pos();
    if (ui->hendRadio->isChecked()){
        setCentr();
    }
    else if (ui->penRadoi->isChecked()){
        vec.append(point2);
    }
    if (ui->moveTrianglePointsRadio->isChecked()){
        int pointNumb = figures_arr[figureNumber - 1]->getNearPoint(point2);
        if (pointNumb != -1) figures_arr[figureNumber - 1]->movePoint(pointNumb ,point2);
    }
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    if (figures_arr.size() > 0){
        if (event->angleDelta().y() > 0){
            figures_arr[figureNumber - 1]->changeTurnAngle(-0.1);
        }
        else{
            figures_arr[figureNumber - 1]->changeTurnAngle(0.1);
        }
        figures_arr[figureNumber - 1]->turn();
    }


}

void MainWindow::setCentr()
{
    if (figures_arr.size() > 0){
        if (figures_arr[figureNumber - 1]->pointInSide(point2)){
            figures_arr[figureNumber - 1]->setCentr(figures_arr[figureNumber - 1]->getCentre() + (point2 - start_pos));
        }
    }
    start_pos = point2;
}

void MainWindow::on_nextFigureButton_clicked()
{
    if (figureNumber - 1 < figures_arr.size() - 1){
        ++figureNumber;
    }
}


void MainWindow::on_lastFigureButton_clicked()
{
    if (figureNumber - 1 > 0){
        --figureNumber;
    }
}


void MainWindow::on_horizontalSlider_actionTriggered(int action)
{
    if (figures_arr.size() > 0){
        figures_arr[figureNumber - 1]->resize(ui->horizontalSlider->value()) ;
    }
}


void MainWindow::on_clearAllButton_clicked()
{
    figures_arr.clear();
    figureNumber = 0;
}


void MainWindow::on_clearOneButton_clicked()
{
    if (figures_arr.size() > 0){
        figures_arr.erase(figures_arr.begin() + figureNumber - 1);
        if (figureNumber != 1){
            figureNumber --;
        }
    }
}

