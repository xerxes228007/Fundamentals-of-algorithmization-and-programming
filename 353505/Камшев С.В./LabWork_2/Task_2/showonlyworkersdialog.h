#ifndef SHOWONLYWORKERSDIALOG_H
#define SHOWONLYWORKERSDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QRadioButton>
#include <QCloseEvent>
#include <QSpinBox>

class showOnlyWorkersDialog: public QDialog
{
public:
    showOnlyWorkersDialog();
    QPushButton* okPushButton = new QPushButton;
    QRadioButton* salryCheckBox = new QRadioButton;
    QRadioButton* higeAducationCheckBox = new QRadioButton;
    QRadioButton* surnameCheckBox = new QRadioButton;

    QSpinBox* spinBox = new QSpinBox;

    bool getIsChecked();
    void reject() override;

private:
    bool isChecked;
    void closeEvent(QCloseEvent *event);
};

#endif // SHOWONLYWORKERSDIALOG_H
