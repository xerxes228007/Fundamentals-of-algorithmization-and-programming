#ifndef SORTCOMPANYS_H
#define SORTCOMPANYS_H

#include <QDialog>
#include <QPushButton>
#include <QRadioButton>
#include <QCloseEvent>

class sortcompanys: public QDialog
{
public:
    sortcompanys();
    QPushButton* okPushButton = new QPushButton;
    QRadioButton* salryCheckBox = new QRadioButton;
    QRadioButton* higeAducationCheckBox = new QRadioButton;
    QRadioButton* surnameCheckBox = new QRadioButton;

    bool getIsChecked();
    void reject() override;
private:
    bool isChecked;
    void closeEvent(QCloseEvent *event);
private slots:
    void on_okPushButton_clicked();
};

#endif // SORTCOMPANYS_H
