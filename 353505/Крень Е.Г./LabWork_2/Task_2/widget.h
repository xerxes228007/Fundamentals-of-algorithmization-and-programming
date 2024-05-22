#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>
#include "vacancy.h"
#include <QFileDialog>


QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QDate stringToDate(QString a);
    QString dateTostring(QDate a);
    QFile* openFileEmployer;
    QFile* openFileVacancy;
    void showCandidates(QVector<Employer> a);
    void showPositions(Employer a);
    void showEmployerTable();
    void showVacancyTable();
    QVector<Employer> employerList;
    QVector<Vacancy> vacancyList;
    Ui::Widget *ui;
};
#endif // WIDGET_H
