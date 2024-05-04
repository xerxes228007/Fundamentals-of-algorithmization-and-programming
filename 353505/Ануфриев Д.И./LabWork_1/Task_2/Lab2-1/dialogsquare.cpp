#include "dialogsquare.h"
#include "ui_dialogsquare.h"

DialogSquare::DialogSquare(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogSquare)
{
    ui->setupUi(this);

    ui->spinBox->setRange(14, 345);
}

void DialogSquare::setValue(qreal side)
{
    ui->spinBox->setValue(side);
}

DialogSquare::~DialogSquare()
{
    delete ui;
}

int DialogSquare::getNewSide()
{
    return ui->spinBox->value();
}

void DialogSquare::on_buttonBox_accepted()
{
    newSide = ui->spinBox->value();

    emit setNewSide();
}

