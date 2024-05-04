#ifndef COMPANY_H
#define COMPANY_H
#include <QString>
#include <QVector>

class company
{
public:
    company();
    company(QString nameOfCompany, QString post, double salary, bool hasRequirementsForHigherEducation, bool hasAgeRequirements, bool hasExperienceRequirements, int numberOfVacationDays, int experience, int minimumAge,int maximumAge);
    static company stringToWorker(QString str);

    bool hasRequirementsForHigherEducation, hasAgeRequirements, hasExperienceRequirements;
    int numberOfVacationDays, experience, minimumAge, maximumAge;
    double salary;
    QString nameOfCompany, post;

};

#endif // COMPANY_H
