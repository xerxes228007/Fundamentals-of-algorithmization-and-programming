#ifndef EMPLOYER_H
#define EMPLOYER_H

#include <QString>
#include <QDate>

class Employer
{
public:
    Employer(QString secondName, QString name, QString patronymic, QDate birtday, bool graduation, QString desiredPosition, double minimalSalary);
    void addPosition(QString pos, int stage){positions.push_back(pos); stageOfThisPositions.push_back(stage);};
    void removePosition(int a){positions.remove(a); stageOfThisPositions.remove(a);};
    inline QString getName() const{return secondName+" "+ name+" "+patronymic;};
    inline QString getSecondName() const{return secondName;};
    inline QString getNam() const{return name;};
    inline QString getN() const{return patronymic;};
    inline QDate getBirth() const{return birthday;};
    inline QString getGrad() const{return graduation ? "true\n":"false\n";};
    inline int getAge() const{return age;};
    inline QString getGraduation() const{return graduation ? "Есть":"Нет";};
    inline QString getDesiredPos() const{return desiredPosition;};
    inline double getSalary() const{return minimalSalary;};
    inline QString getPosition(int index) const{return positions[index];};
    inline int getPosStage(int index) const{return stageOfThisPositions[index];};
    int posSize(){return positions.size();};
    int stageInDesired();
private:
    QString secondName;
    QString name;
    QString patronymic;
    QDate birthday;
    bool graduation;
    int age;
    QString desiredPosition;
    double minimalSalary;
    QVector<QString> positions;
    QVector<int> stageOfThisPositions;
};

#endif // EMPLOYER_H
