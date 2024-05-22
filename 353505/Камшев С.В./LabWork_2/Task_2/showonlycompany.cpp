#include "showonlycompany.h"

ShowOnlyCompany::ShowOnlyCompany() {
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
    surnameCheckBox->setGeometry(0,120,170,30);

    spinBox->setParent(this);
    spinBox->setRange(500,10000);
    spinBox->setGeometry(180, 0, 100, 30);

    expCheckBox->setParent(this);
    expCheckBox->setText("Стаж");
    expCheckBox->setGeometry(0,80,170,30);

    expspinBox->setParent(this);
    expspinBox->setRange(0,40);
    expspinBox->setGeometry(180, 80, 100, 30);

    surnameCheckBox->setChecked(true);
    connect(okPushButton, &QPushButton::clicked, this, &QDialog::reject);
}

bool ShowOnlyCompany::getIsChecked()
{
    return isChecked;
}

void ShowOnlyCompany::reject()
{
    isChecked = true;
    this->hide();
}

void ShowOnlyCompany::closeEvent(QCloseEvent *event)
{
    isChecked = false;
    event->accept();
}
