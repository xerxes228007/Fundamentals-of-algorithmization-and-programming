#ifndef DATE_H
#define DATE_H
#include <QString>
#include <QPair>
#include <QDateTime>

class Date
{
public:
    Date();
    Date(int day, int month, int year);
    Date NextDay();
    QString ToString();
    bool IsLeap();
    Date PreviousDay();
    short WeekNumber();
    int DaysTillYourBithday(Date bithdaydate);
    static int Duration (Date date);
    int dayToDate(Date date);
    static Date stringToDate(QString str);
    int getMonthDays(int index);
    int getday();
    int getMonth();
    int getYear();

    bool operator !=(Date date);
private:
    int Day, Month, Year;
    QPair <QString, int> months[12];

};

#endif // DATE_H
