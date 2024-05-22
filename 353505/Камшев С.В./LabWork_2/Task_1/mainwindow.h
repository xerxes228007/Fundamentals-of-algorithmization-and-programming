#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QPushButton>
#include <QFile>
#include <QIODevice>
#include <QWidget>
#include <QVector>
#include "date.h"
#include <QTableWidget>
#include <QLineEdit>
#include <QTimer>
#include <QVariant>
#include <QMessageBox>
#include <QCloseEvent>
#include "savefilewindow.h"
#include <QThread>
#include <QSizePolicy>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QPushButton* FilePushButton  = new QPushButton();
    QPushButton* addNewDatePushButton  = new QPushButton();
    QPushButton* changeSelecteRowPushButton  = new QPushButton();
    QPushButton* calculateCoontDaydToBithdayPushButton  = new QPushButton();

    QTableWidget* table = new QTableWidget();
    QLineEdit* newDate = new QLineEdit();
    QPushButton* nextRow  = new QPushButton();
    QPushButton* lastRow  = new QPushButton();
    QLineEdit* changeDate = new QLineEdit();
    QLineEdit* bithdayDate = new QLineEdit();


    QString fileName;
    QFile file;
    QVector <Date> dateArr;
    QVector <Date> oldDateArr;


    QStringList colomnNames{"Текущая дата","Следующий день", "Предыдущий день", "Является ли год високосным", "Номер недели", "До следующей даты", "Дней до дня рождения", "Количество дней до текущей дыты"};
    QTimer* update_timer;


    int rowNumber = 0;
    bool fileWosOpen = false;
    bool saveWosPressed = true;
    bool bithdayIsWrite = false;

    savefilewindow* SaveFileWindow = new savefilewindow();

    QAbstractButton *yes = SaveFileWindow->addButton("Да",QMessageBox::YesRole);
    QAbstractButton *canel = SaveFileWindow->addButton("Отмена",QMessageBox::NoRole);
    QAbstractButton *no = SaveFileWindow->addButton("Нет",QMessageBox::AcceptRole);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void showInformation();
    void readInformation();
    void AddNewdate();
    void setValues(int index);
    void closeEvent(QCloseEvent *event);
    void seveQuestion();
    void openFile();

public slots:
    void on_openFilePushButton_clicked();
    void on_saveFilePushButton_clicked();
    void on_closeFilePushButton_clicked();

    void on_addNewDatePushButton_clicked();
    void on_nextRow_clicked();
    void on_lastRow_clicked();
    void on_changeSelecteRowPushButton_clicked();
    void on_calculateCoontDaydToBithdayPushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
