#include "showonlyworkersdialog.h"

showOnlyWorkersDialog::showOnlyWorkersDialog() {
    okPushButton->setParent(this);
    okPushButton->setText("ОК");
    this->resize(500,200);
    this->setWindowTitle("Настройка сортировки");
    okPushButton->setGeometry(190, 170, 120, 30);

    salryCheckBox->setParent(this);
    salryCheckBox->setText("Зарплата");
    salryCheckBox->setGeometry(0,0,170,30);

    higeAducationCheckBox->setParent(this);
    higeAducationCheckBox->setText("Наличие вышки");
    higeAducationCheckBox->setGeometry(0,40,170,30);

    surnameCheckBox->setParent(this);
    surnameCheckBox->setText("Все");
    surnameCheckBox->setGeometry(0,80,170,30);

    spinBox->setParent(this);
    spinBox->setRange(500,10000);
    spinBox->setGeometry(180, 0, 100, 30);

    surnameCheckBox->setChecked(true);
    connect(okPushButton, &QPushButton::clicked, this, &QDialog::reject);

}

bool showOnlyWorkersDialog::getIsChecked()
{
    return isChecked;
}

void showOnlyWorkersDialog::reject()
{
    isChecked = true;
    this->hide();
}


void showOnlyWorkersDialog::closeEvent(QCloseEvent *event)
{
    isChecked = false;
    event->accept();
}
