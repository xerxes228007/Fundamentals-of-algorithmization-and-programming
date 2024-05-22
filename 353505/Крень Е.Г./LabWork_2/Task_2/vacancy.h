#ifndef VACANCY_H
#define VACANCY_H
#include <QString>
#include "employer.h"

class Vacancy
{
public:
    Vacancy(QString firmName, QString position, double salary, int vocation, bool needGraduation,int minAge, int maxAge, int stage);
    QVector<Employer> possibleCandites(QVector<Employer> list);
    QVector<Vacancy> defecateVacancy(QVector<Employer> list, QVector<Vacancy> vacancyList);
    QVector<Employer> joblessCandidates(QVector<Employer> list, QVector<Vacancy> vacancyList);
    inline QString getFirmName() const {return firmName;};
    inline QString getPosition() const {return position;};
    inline QString getSalary() const{return QString::number(salary);};
    inline QString getVocation() const {return QString::number(vocation);};
    inline QString getMinAge() const {return QString::number(minAge);};
    inline QString getMaxAge() const {return QString::number(maxAge);};
    inline QString getAge() const{return QString::number(minAge) + " - " + QString::number(maxAge);};
    inline QString getGraduation() const {return needGraduation ? "Да" : "Нет";};
    inline QString getStage() const {return QString::number(stage);};
private:
    QString firmName;
    QString position;
    double salary;
    int vocation;
    bool needGraduation;
    int minAge;
    int maxAge;
    int stage;
};

#endif // VACANCY_H
