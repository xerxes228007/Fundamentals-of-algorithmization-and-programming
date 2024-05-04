#ifndef SHOWONLYCOMPANY_H
#define SHOWONLYCOMPANY_H

#include <QDialog>
#include <QPushButton>
#include <QRadioButton>
#include <QCloseEvent>
#include <QSpinBox>

class ShowOnlyCompany: public QDialog
{
public:
    ShowOnlyCompany();
    QPushButton* okPushButton = new QPushButton;
    QRadioButton* salryCheckBox = new QRadioButton;
    QRadioButton* higeAducationCheckBox = new QRadioButton;
    QRadioButton* surnameCheckBox = new QRadioButton;
    QRadioButton* expCheckBox = new QRadioButton;

    QSpinBox* spinBox = new QSpinBox;
    QSpinBox* expspinBox = new QSpinBox;

    bool getIsChecked();
    void reject() override;

private:
    bool isChecked;
    void closeEvent(QCloseEvent *event);
};

#endif // SHOWONLYCOMPANY_H
