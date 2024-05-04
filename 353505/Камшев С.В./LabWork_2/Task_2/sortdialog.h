#ifndef SORTDIALOG_H
#define SORTDIALOG_H
#include <QDialog>
#include <QPushButton>
#include <QRadioButton>
#include <QCloseEvent>

class sortDialog: public QDialog
{
public:
    sortDialog();
    ~sortDialog();
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

#endif // SORTDIALOG_H
