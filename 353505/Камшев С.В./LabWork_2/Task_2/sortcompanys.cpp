#include "sortcompanys.h"

sortcompanys::sortcompanys() {
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
    surnameCheckBox->setText("Требование к стажу");
    surnameCheckBox->setGeometry(0,80,170,30);

    surnameCheckBox->setChecked(true);
    connect(okPushButton, &QPushButton::clicked, this, &QDialog::reject);
}

bool sortcompanys::getIsChecked()
{
    return isChecked;
}

void sortcompanys::reject()
{
    isChecked = true;
    this->hide();
}

void sortcompanys::closeEvent(QCloseEvent *event)
{
    isChecked = false;
    this->close();
}
