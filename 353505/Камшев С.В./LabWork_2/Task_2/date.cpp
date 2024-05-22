#include "date.h"

Date::Date()
{

}

Date::Date(int day, int month, int year)
{
    Day = day;
    Month = month;
    Year = year;
    QPair <QString, int> months2[12]{{"январь",31}, {"февраль", IsLeap()? 29 : 28}, {"март", 31}, {"апрель", 30}, {"май", 31}, {"июнь", 30}, {"июль", 31}, {"август", 31}, {"сентябрь", 30}, {"октябрь", 31}, {"ноябрь", 30}, {"декабрь", 31}};

    for (int i = 0 ;i < 12; ++i){
        months[i] = months2[i];
    }

}
Date Date::NextDay()
{
    if (Day < months[Month - 1].second) return Date(Day + 1, Month, Year);
    if (Month == 12) return Date(1,1, Year + 1);
    return Date(1, Month + 1, Year);
}

QString Date::ToString()
{
    QString d =  QString::number(Day).size() == 1? '0' + QString::number(Day): QString::number(Day);
    QString m =  QString::number(Month).size() == 1? '0' + QString::number(Month): QString::number(Month);
    QString y = QString::number(Year);

    if (y[0] == '-'){
        for (int i = y.size(); i < 5; ++i){
            y.insert(1, '0');
        }
    }
    else{
        for (int i = y.size(); i < 4; ++i){
            y.insert(0, '0');
        }
    }
    return d + "." + m + "." + y;
}

bool Date::IsLeap()
{
    return ( Year % 100 != 0 && Year % 4 == 0) || Year % 400 == 0;
}

Date Date::PreviousDay()
{
    if (Day == 1){
        if (Month == 1)return Date(31, 12, Year - 1);
        return Date(months[Month - 1].second, Month - 1 , Year);
    }
    return Date(Day - 1, Month, Year);
}

short Date::WeekNumber()
{
    short sum = 0;
    for (short i = 0; i < Month; ++i){
        sum+= months[i].second;
    }
    sum += Day;
    return sum / 7 + 1;
}

int Date::DaysTillYourBithday(Date bithdaydate)
{
    if (dayToDate(bithdaydate) >= 365){
        while (dayToDate(bithdaydate) >= 365) bithdaydate.Year -=1;
    }

    if (dayToDate(bithdaydate) < 0){
        while (dayToDate(bithdaydate) < 0) bithdaydate.Year +=1;
    }

    return dayToDate(bithdaydate);
}

int Date::Duration(Date date)
{
    QDate nowDate = QDate::currentDate();
    QDate secondDate(date.Year, date.Month, date.Day);
    return nowDate.daysTo(secondDate);
}

int Date::dayToDate(Date date)
{
    QDate nowDate(Year, Month, Day);
    QDate secondDate(date.Year, date.Month, date.Day);
    return nowDate.daysTo(secondDate);
}

Date Date::stringToDate(QString str)
{
    QString arr[3]{"", "", ""};
    int indexOfArr = 0;
    for(auto &i: str){
        if (i == '.'){
            indexOfArr++;
        }
        if (i.isDigit()){
            arr[indexOfArr] += i;
        }
    }

    int day = arr[0].QString::toInt();
    int month = arr[1].QString::toInt();
    int year = arr[2].QString::toInt();
    Date date(1,1, year);
    int ans = date.getMonthDays(month-1);
    if (month > 0 && month < 13 && day > 0 && day <= date.getMonthDays(month-1) && arr[2] != "") return Date(day, month, year);
    return Date(-1,-1,-1);
}

int Date::getMonthDays(int index)
{
    return months[index].second;
}



int Date::getday()
{
    return Day;
}

int Date::getMonth()
{
    return Month;
}

int Date::getYear()
{
    return Year;
}

bool Date::operator !=(Date date)
{
    return (Day != date.getday() || Month != date.getMonth() || Year != date.getYear());
}
