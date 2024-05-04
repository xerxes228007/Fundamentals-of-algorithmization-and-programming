#include "employer.h"

Employer::Employer(QString secondName, QString name, QString patronymic, QDate birtday, bool graduation, QString desiredPosition, double minimalSalary)
    :secondName(secondName)
    ,name(name)
    ,patronymic(patronymic)
    ,birthday(birtday)
    ,graduation(graduation)
    ,desiredPosition(desiredPosition)
    ,minimalSalary(minimalSalary)
{

    age = QDate::currentDate().year() - birtday.year();
    if(birthday.month() > QDate::currentDate().month() || (birthday.month() == QDate::currentDate().month() && birthday.day() > QDate::currentDate().day())) age--;
}
int Employer::stageInDesired(){
    int stage = 0;
    for(int i = 0; i<positions.size(); ++i){
        if(desiredPosition==positions[i])
        {
            stage = stageOfThisPositions[i];
            break;
        }
    }
    return stage;
}
