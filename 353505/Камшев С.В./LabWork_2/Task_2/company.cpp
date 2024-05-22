#include "company.h"

company::company() {}

company::company(QString nameOfCompany, QString post, double salary, bool hasRequirementsForHigherEducation, bool hasAgeRequirements, bool hasExperienceRequirements, int numberOfVacationDays, int experience, int minimumAge, int maximumAge)
{
    this->nameOfCompany = nameOfCompany;
    this->post = post.toUpper();
    this->salary = salary;
    this->hasRequirementsForHigherEducation = hasRequirementsForHigherEducation;
    this->hasAgeRequirements = hasAgeRequirements;
    this->hasExperienceRequirements = hasExperienceRequirements;
    this->numberOfVacationDays = numberOfVacationDays;

    if (hasRequirementsForHigherEducation)
    if (hasAgeRequirements){
            if (minimumAge > maximumAge) std::swap(minimumAge, maximumAge);
        this->minimumAge = minimumAge;
        this->maximumAge = maximumAge;
    }
    if (hasExperienceRequirements) this->experience = experience;


}

company company::stringToWorker(QString str)
{
    str.remove(str.size()- 2, 2);
    str.remove(0, 1);
    QStringList strArr = str.split(", ");

    company Company(strArr[0], strArr[1], strArr[2].toDouble(), strArr[3].toInt(), strArr[4].toInt(), strArr[5].toInt(), strArr[6].toInt(), strArr[7].toInt(), strArr[8].toInt(), strArr[9].toInt());
    return Company;
}
