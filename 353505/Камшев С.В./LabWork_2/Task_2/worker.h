#ifndef WORKER_H
#define WORKER_H
#include <QString>
#include <QVector>
#include <QPair>
#include "date.h"

class worker
{
public:
    worker();
    worker(QString firstName, QString surname, QString patronymic, QString desiredPosition, bool hasRequirementsForHigherEducation, double minimumSalary, QVector <QPair <QString, int>> listOfPositions, Date dateOfBirth);
    bool hasRequirementsForHigherEducation;
    int age;
    double minimumSalary;
    QString firstName, surname, patronymic, desiredPosition;
    QVector <QPair <QString, int>> listOfPositions;
    Date dateOfBirth;

    static worker stringToWorker(QString str);
    int getSumOfExperience();
    void ageCalculating();
};

#endif // WORKER_H
