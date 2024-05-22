#include "sortdialog.h"

sortDialog::sortDialog() {
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
    surnameCheckBox->setText("Фамилия");
    surnameCheckBox->setGeometry(0,80,170,30);

    surnameCheckBox->setChecked(true);
    connect(okPushButton, &QPushButton::clicked, this, &QDialog::reject);



}

sortDialog::~sortDialog(){}

bool sortDialog::getIsChecked()
{
    return isChecked;
}

void sortDialog::reject()
{
    isChecked = true;
    this->hide();
}

void sortDialog::closeEvent(QCloseEvent *event)
{
    event->ignore();
    isChecked = false;
    this->close();
    event->accept();
}

void sortDialog::on_okPushButton_clicked(){
}
