#include "createorderwindow.h"
#include "ui_createorderwindow.h"

CreateOrderWindow::CreateOrderWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CreateOrderWindow)
{
    ui->setupUi(this);
}

CreateOrderWindow::~CreateOrderWindow()
{
    delete ui;
}
