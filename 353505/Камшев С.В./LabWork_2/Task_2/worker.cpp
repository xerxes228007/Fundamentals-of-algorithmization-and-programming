#include "worker.h"

worker::worker() {}

worker::worker(QString firstName, QString surname, QString patronymic, QString desiredPosition,bool hasRequirementsForHigherEducation, double minimumSalary, QVector<QPair<QString, int> > listOfPositions, Date dateOfBirth)
{
    this->firstName = firstName;
    this->surname = surname;
    this->patronymic = patronymic;
    this->desiredPosition = desiredPosition.toUpper();

    this->hasRequirementsForHigherEducation = hasRequirementsForHigherEducation;
    this->minimumSalary = minimumSalary;
    this->dateOfBirth = dateOfBirth;
    age = abs(int(Date::Duration(this->dateOfBirth) / 365));
    this->listOfPositions = listOfPositions;
}

worker worker::stringToWorker(QString str)
{
    worker Worker;
    str.remove(str.size()- 2, 2);
    str.remove(0, 1);
    QStringList strArr = str.split("//");

    strArr[1].remove(strArr[1].size()- 1, 1);
    strArr[1].remove(0, 1);

    if (strArr[1].size() > 0){
        for (int i = 0; i < strArr[1].split("}, {").size(); ++i){
            QPair <QString, int> pair(strArr[1].split("}, {")[i].split(':')[0], (strArr[1].split("}, {")[i].split(':')[1]).toInt());
            Worker.listOfPositions.append(pair);
        }
    }
    strArr = strArr[0].split(", ");
    Worker.surname = strArr[0];
    Worker.firstName = strArr[1];
    Worker.patronymic = strArr[2];
    Worker.desiredPosition = strArr[3];
    Worker.hasRequirementsForHigherEducation = strArr[4].toInt();
    Worker.minimumSalary = strArr[5].toInt();
    Worker.dateOfBirth = Date::stringToDate(strArr[6]);

    Worker = worker(Worker.firstName,  Worker.surname, Worker.patronymic, Worker.desiredPosition, Worker.hasRequirementsForHigherEducation, Worker.minimumSalary, Worker.listOfPositions,Worker.dateOfBirth);
    return Worker;
}

int worker::getSumOfExperience()
{
    int ans = 0;
    for (auto& i : listOfPositions){
        ans += i.second;
    }
    return ans;
}

void worker::ageCalculating()
{
    age = abs(int(Date::Duration(this->dateOfBirth) / 365));
}
