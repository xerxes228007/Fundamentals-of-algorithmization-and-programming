#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->deductSpeed->setStyleSheet("QPushButton:disabled { color: gray; background-color: lightgray; }"); // стиль кнопок при дизактивации
    ui->addSpeed->setStyleSheet("QPushButton:disabled { color: gray; background-color: lightgray; }");
    ui->stopMoving->setStyleSheet("QPushButton:disabled { color: gray; background-color: lightgray; }");
    ui->startMoving->setStyleSheet("QPushButton:disabled { color: gray; background-color: lightgray; }");

    ui->addSpeed->setDisabled(true);
    ui->deductSpeed->setDisabled(true);
    ui->stopMoving->setDisabled(true);
    ui->stopMoving->setDisabled(true);

    wagon = new Wagon();

    scene->addItem(wagon);

    movingObjectTimer = new QTimer(this);
    speedUpdating = new QTimer(this);

    connect(speedUpdating, &QTimer::timeout, [this](){                          //обновление счетчика скорости
        ui->speed->setText("Speed: " + QString::number(wagon->getSpeed()));

        if(wagon->getSpeed() == 20 || wagon->getSpeed() == 0)
            {
            ui->addSpeed->setDisabled(true);
        }

        else ui->addSpeed->setDisabled(false);
    });

    speedUpdating->start(10);



    connect(movingObjectTimer, &QTimer::timeout,
            wagon, &Rectangle::moveRect);

    connect(ui->addSpeed, &QPushButton::clicked,
             wagon, &Rectangle::addSpeed);

    connect(ui->deductSpeed, &QPushButton::clicked,
            wagon, &Rectangle::deductSpeed);

    btSpeedAddTimer = new QTimer(this); // таймеры для обновления скорости при зажатии кнопок
    connect(btSpeedAddTimer, &QTimer::timeout, wagon, &Rectangle::addSpeed);

    btSpeedDeductTimer = new QTimer(this);
    connect(btSpeedDeductTimer, &QTimer::timeout, wagon, &Rectangle::deductSpeed);


    connect(wagon, &Wagon::stop, this, [this]() { // выключение кнопок при нажатии противоположных по функции
        movingObjectTimer->stop();
        wagon->setSpeed(0);

        ui->stopMoving->setDisabled(true);
        ui->startMoving->setDisabled(false);
        ui->addSpeed->setDisabled(true);
        ui->deductSpeed->setDisabled(true);
    });


    connect(wagon, &Wagon::highSpeed, this, [this]() {
        ui->addSpeed->setDisabled(false);
        ui->deductSpeed->setDisabled(false);
        ui->addSpeed->setDisabled(true);

        QMessageBox message;
        message.warning(this, "Warning", "Не нарушаем! У тебя и так педаль в пол!");
    });




}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startMoving_clicked()
{
    movingObjectTimer->start(1000/120);
    wagon->setSpeed(1);

    ui->startMoving->setDisabled(true);
    ui->stopMoving->setDisabled(false);
    ui->addSpeed->setDisabled(false);
    ui->deductSpeed->setDisabled(false);
}

void MainWindow::on_stopMoving_clicked()
{
    int speedAtTheMoment = wagon->getSpeed();
    movingObjectTimer->stop();
    wagon->setSpeed(0);

    ui->stopMoving->setDisabled(true);
    ui->startMoving->setDisabled(false);
    ui->addSpeed->setDisabled(true);
    ui->deductSpeed->setDisabled(true);

    if(speedAtTheMoment > 10)
    {
        QMessageBox message;
        message.information(this, "Stop", "Надеюсь, ты был пристегнут...");
    }
}

void MainWindow::on_addSpeed_pressed() //работа добавления и убывания скорости при зажатии кнопок
{
    int interval = 150;
    btSpeedAddTimer->start(interval);
}


void MainWindow::on_addSpeed_released()
{
    btSpeedAddTimer->stop();
}


void MainWindow::on_deductSpeed_pressed()
{
    int interval = 150;
    btSpeedDeductTimer->start(interval);
}


void MainWindow::on_deductSpeed_released()
{
    btSpeedDeductTimer->stop();
}

