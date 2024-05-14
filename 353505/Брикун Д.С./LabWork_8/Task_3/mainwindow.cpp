#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_s_add_clicked()
{
    set.add(ui->spinBox->value());
}


void MainWindow::on_pushButton_s_check_clicked()
{
    ui->textEdit->setPlainText(set.contains(ui->spinBox->value()) ? "Yes" : "No");
}


void MainWindow::on_pushButton_s_clear_clicked()
{
    set.clear();
}


void MainWindow::on_pushButton_s_remove_clicked()
{
    set.remove(ui->spinBox->value());
}


void MainWindow::on_pushButton_m_add_clicked()
{
    map.add(ui->spinBox->value(), ui->spinBox_val->value());
}


void MainWindow::on_pushButton_m_check_clicked()
{
    ui->textEdit->setPlainText(map.contains(ui->spinBox->value()) ? "Yes" : "No");
}


void MainWindow::on_pushButton_m_get_clicked()
{
    ui->textEdit->setPlainText(QString::number(map.get(ui->spinBox->value())));
}


void MainWindow::on_pushButton_m_clear_clicked()
{
    map.clear();
}


void MainWindow::on_pushButton_m_remove_clicked()
{
    map.remove(ui->spinBox->value());
}


void MainWindow::on_pushButton_m_set_clicked()
{
    map[ui->spinBox->value()] = ui->spinBox_val->value();
}

