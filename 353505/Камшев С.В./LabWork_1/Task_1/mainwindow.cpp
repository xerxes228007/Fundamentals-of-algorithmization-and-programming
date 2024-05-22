#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    timer_update = new QTimer(this);
    connect(timer_update, &QTimer::timeout,
            [=]()
            {
                update();
                if (Plain.rect.y() > 420 || Plain.getChassisReleased() == false){
                    ui->boarding->setEnabled(false);
                    ui->boarding->setPalette(QPalette(Qt::gray));
                }
                else{
                    ui->boarding->setEnabled(true);
                    ui->boarding->setPalette(QPalette(Qt::white));

                }

                if (Plain.rect.y() == 860 && Plain.getSpeedX() > 20){
                    ui->takeoff->setEnabled(true);
                    ui->takeoff->setPalette(QPalette(Qt::white));

                }
                else{
                    ui->takeoff->setEnabled(false);
                    ui->takeoff->setPalette(QPalette(Qt::gray));


                }

                if (Plain.getSpeedX() > 0){
                    ui->overclocking->setEnabled(false);
                    ui->overclocking->setPalette(QPalette(Qt::gray));

                }
                else{
                    ui->overclocking->setEnabled(true);
                    ui->overclocking->setPalette(QPalette(Qt::white));

                }

                if (Plain.getSpeedX() >= 29.7 && Plain.rect.y() == 860){
                    ui->brakin->setEnabled(true);
                    ui->brakin->setPalette(QPalette(Qt::white));

                }
                else{
                    ui->brakin->setEnabled(false);
                    ui->brakin->setPalette(QPalette(Qt::gray));
                }

                if (Plain.rect.y() == 860 || Plain.getFlight() == -1){
                    ui->releaseChassis->setEnabled(false);
                    ui->releaseChassis->setPalette(QPalette(Qt::gray));
                    ui->removeChassis->setEnabled(false);
                    ui->removeChassis->setPalette(QPalette(Qt::gray));


                }
                else{
                    if (Plain.getChassisReleased() == 1){

                        ui->releaseChassis->setEnabled(false);
                        ui->releaseChassis->setPalette(QPalette(Qt::gray));
                        ui->removeChassis->setEnabled(true);
                        ui->removeChassis->setPalette(QPalette(Qt::white));
                    }
                    else{
                        ui->releaseChassis->setEnabled(true);
                        ui->releaseChassis->setPalette(QPalette(Qt::white));
                        ui->removeChassis->setEnabled(false);
                        ui->removeChassis->setPalette(QPalette(Qt::gray));
                    }


                }

                if (Plain.getTraffic() == -1){
                    ui->takeoff->setEnabled(false);
                    ui->takeoff->setPalette(QPalette(Qt::gray));

                }


    });
    timer_update->start(30);
    Plain.movement();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);

    paint.setBrush(Qt::cyan);
    paint.drawRect(0, 0, width(), height());

    paint.setBrush(Qt::green);
    paint.drawRect(0, 700, width(), 300);

    paint.setBrush(Qt::gray);
    paint.drawRect(0, 800, width(), 100);

    paint.setBrush(Qt::black);
    paint.drawRect(Plain.chassis);

    paint.setBrush(Qt::red);
    paint.drawRect(Plain.rect);

    paint.setBrush(Qt::blue);
    paint.drawRect(Plain.wing);

    paint.setBrush(Qt::yellow);
    paint.drawRect(Plain.tail);


}

void MainWindow::on_overclocking_clicked()
{
    if (Plain.getSpeedX() == 0){
        Plain.acceleration();
    }
    else{
        QMessageBox::information(this, "Разогнаться можно  только на нулевой скорости.", "Ваша скорость " + QString::number(Plain.getSpeedX()));
    }
}


void MainWindow::on_brakin_clicked()
{
    if (Plain.rect.y() == 860){
        if (Plain.getSpeedX() >= 29.7){
            Plain.braking();
        }
        else if (Plain.getSpeedX() > 0 && Plain.getSpeedX() < 29.7){
            QMessageBox::information(this, "Затормозить можно  только на максимальной скорости раной 30.", "Ваша скорость " + QString::number(Plain.getSpeedX()));
        }
        else if (Plain.getSpeedX() == 0){
            QMessageBox::critical(this, "Ошибка", "Вы уже стоите на месте.");
        }
    }
    else{
        QMessageBox::critical(this, "Ошибка", "Нельзя остановться в воздухе!!");
    }
}


void MainWindow::on_takeoff_clicked() 
{
    if (Plain.getSpeedX() < 20){
        QMessageBox::critical(this, "Ошибка", "Взлёт не возможен: слишком маленькая скорость");
    }
    else{
        if (Plain.rect.y() == 860){
            Plain.takeoff();
        }
        else{

            QMessageBox::critical(this, "Ошибка.", " Начать взлет только на земле, высота которой 860. Ваша высота " +  QString::number(Plain.rect.y()));
        }
    }
}


void MainWindow::on_boarding_clicked()
{
    if (Plain.rect.y() < 400){
        if (Plain.getChassisReleased() == true ){
            Plain.boarding();
        }
    }
    else if (Plain.rect.y() == 860)
    {
        QMessageBox::critical(this, "Ошибка", "Вы и так на земле.");
    }
    else{
        QMessageBox::critical(this, "Ошибка.", " Начать посадку только после максимальной высоты, равной 400. Ваша высота " +  QString::number(Plain.rect.y()));
    }
}


void MainWindow::on_removeChassis_clicked()
{
    if (Plain.rect.y() < 860){
        if (Plain.getChassisReleased() == true){
            Plain.remove();
        }
    }
    else{
        QMessageBox::critical(this, "Ошибка", "На земле нельзя убрать шасси.");
    }
}


void MainWindow::on_releaseChassis_clicked()
{

    if (Plain.getChassisReleased() == false){
        Plain.release();
    }
}

