#include "dialogstar5.h"
#include "ui_dialogstar5.h"

DialogStar5::DialogStar5(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogStar5)
{
    ui->setupUi(this);

    ui->spinBox->setRange(10, 50);
    ui->spinBox_2->setRange(50, 100);
}

DialogStar5::~DialogStar5()
{
    delete ui;
}

qreal DialogStar5::getNewExternalRadius()
{
    return newExternalRadius;
}

qreal DialogStar5::getNewInternalRadius()
{
    return newInternalRadius;
}

void DialogStar5::setValues(qreal intrad, qreal extrad)
{
    ui->spinBox->setValue(intrad);
    ui->spinBox_2->setValue(extrad);
}

void DialogStar5::on_buttonBox_accepted()
{
    newInternalRadius = ui->spinBox->value();
    newExternalRadius = ui->spinBox_2->value();

    emit setNewRadiuses();
}

