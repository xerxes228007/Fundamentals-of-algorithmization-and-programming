#include "dialogcircle.h"
#include "ui_dialogcircle.h"

DialogCircle::DialogCircle(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogCircle)
{
    ui->setupUi(this);

    ui->spinBox->setRange(14, 344);
}

void DialogCircle::setValue(qreal radius)
{
    ui->spinBox->setValue(radius);
}

DialogCircle::~DialogCircle()
{
    delete ui;
}


int DialogCircle::getNewRadius()
{
    return newRadius;
}


void DialogCircle::on_buttonBox_accepted()
{
    newRadius = ui->spinBox->value();

    if(ui->spinBox->value() < 14) QMessageBox::warning(this, "Ошибка", "Вы ввели число, меньшее 14!");

    emit setNewRadius();
}

