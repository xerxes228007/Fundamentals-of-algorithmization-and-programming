#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QFileDialog>
#include <QFile>
#include <QTabWidget>
#include <QTableWidget>
#include <QSpinBox>
#include <QDateTimeEdit>
#include <QLineEdit>
#include <QTextEdit>
#include <QTimer>
#include <QMessageBox>
#include <QCloseEvent>
#include <QtAlgorithms>
#include <QTextEdit>

#include "company.h"
#include "worker.h"
#include "namevalidator.h"
#include "desiredpositionvalidator.h"
#include "sortdialog.h"
#include "showonlyworkersdialog.h"
#include "sortcompanys.h"
#include "showonlycompany.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QPushButton* workersListPushButton = new QPushButton;
    QPushButton* companyListPushButton = new QPushButton;
    QPushButton* addExperiencePushButton = new QPushButton;
    QPushButton* delExperiencePushButton = new QPushButton;
    QPushButton* dellWorkerPushButton = new QPushButton;
    QPushButton* addNewWorkerPushButton = new QPushButton;
    QPushButton* sortWorkersPushButton = new QPushButton;
    QPushButton* showOnlyPushButton = new QPushButton;

    QPushButton* dellCompanyPushButton = new QPushButton;
    QPushButton* addNewCompanyPushButton = new QPushButton;
    QPushButton* sortCompanyPushButton = new QPushButton;
    QPushButton* showOnlyCompanyPushButton = new QPushButton;

    QPushButton* getWorkersPushButton = new QPushButton;
    QPushButton* getwhitputWorkersPushButton = new QPushButton;
    QPushButton* getWorkerswithoutJobPushButton = new QPushButton;

    QTabWidget* tabWidget = new QTabWidget;
    QLineEdit* newExperianceLineEdit = new QLineEdit;

    QTableWidget* workersTable = new QTableWidget;
    QTableWidget* companysTable = new QTableWidget;

    QSpinBox* delExperiense = new QSpinBox;

    QTimer* timer;

    QStringList workerColomnNames{"Фамилия","Имя", "Отчество", "Дата рождения", "Желаемая зарплата", "Высшее образование", "Желаемая должность", "Список мест работы"};
    QStringList companyColomnNames{"Название","Дожность", "Дней отпуска", "Зарплата", "Требования к вышке", "Требование к опыту", "Опыт", "Требование к возрасту", "Минимальный возраст", "Максимальный возраст"};


    QString workersFileName, companyFileName;
    QFile workerFile, companyFile;
    QVector <company> companyList;
    QVector <worker> workerList;
    QVector <worker> workerCopyList;
    QVector <bool> workersisShowedArr;
    QVector <bool> companyShowedArr;


    QVector <QSpinBox*> spinBoxArr;
    QVector <QDateTimeEdit*> calendarArr;
    QVector <QLineEdit*> firstNameEditArr;
    QVector <QLineEdit*> surNameEditArr;
    QVector <QLineEdit*> patronimycEditArr;
    QVector <QLineEdit*> desiredPositionEditArr;

    QVector <bool> workersWithoutJobArr;
    QVector <bool> defecitPostArr;
    QVector <QPair <company, QVector <worker>>> ansArr;

    QVector <QLineEdit*> companyNameEditArr;
    QVector <QLineEdit*> companyPostEditArr;
    QVector <QSpinBox*> HolydaysSpinBoxArr;
    QVector <QSpinBox*> salarySpinBoxArr;
    QVector <QSpinBox*> experienceBoxArr;
    QVector <QSpinBox*> minAgeSpinBoxArr;
    QVector <QSpinBox*> maxAgeSpinBoxArr;

    showOnlyWorkersDialog* onlyDialog;
    sortDialog* SortDialog;
    sortcompanys* SortCompanys;
    ShowOnlyCompany* showonlycompanyDialog;
    bool workersFileWosOpen = false;
    bool experienceIsOk(int index);
    bool companyFileWosOpen = false;

    QTextEdit* textEdit;

    void openWorkersFile();
    void openCompanyFile();
    void showWorkers();
    void showCompanys();
    bool checkNewExperianceString(QString &str);
    void workersVileSave();
    void companyFileSave();


    void closeEvent(QCloseEvent *event);
    void getAns();

    void showWorkersWithoutJobArr();
    void showDefecitPostArr();
    void showAnsArr();


private slots:
    void on_workersListPushButton_clicked();
    void on_companyListPushButton_clicked();
    void on_addExperiencePushButton_clicked();
    void on_dellWorkerPushButton_clicked();
    void on_addNewWorkerPushButton_clicked();
    void on_delExperiencePushButton_clicked();
    void on_sortWorkersPushButton_clicked();
    void on_showOnlyPushButton_clicked();

    void on_dellCompanyPushButton_clicked();
    void on_addNewCompanyPushButton_clicked();
    void on_sortCompanyPushButton_clicked();
    void on_showOnlyCompanyPushButton_clicked();

    void on_getWorkersPushButton_clicked();
    void on_getwhitputWorkersPushButton_clicked();
    void on_getWorkerswithoutJobPushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
