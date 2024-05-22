#include "vacancy.h"

Vacancy::Vacancy(QString firmName, QString position, double salary, int vocation, bool needGraduation,int minAge, int maxAge, int stage)
    :firmName(firmName)
    ,position(position)
    ,salary(salary)
    ,vocation(vocation)
    ,needGraduation(needGraduation)
    ,minAge(minAge)
    ,maxAge(maxAge)
    ,stage(stage)
{}

QVector<Employer> Vacancy::possibleCandites(QVector<Employer> list){
    QVector<Employer> candidates;
    for(int i = 0; i<list.size(); ++i){
        if(this->stage==0||(this->position==list[i].getDesiredPos()&&list[i].stageInDesired()/12 >= this->stage&&list[i].getAge()>=this->minAge&&list[i].getAge()<=this->maxAge)){
            if(this->needGraduation){
                if(list[i].getGraduation()=="Есть"){
                    candidates.push_back(list[i]);
                }
            }
            else{
                candidates.push_back(list[i]);
            }
        }
    }
    return candidates;
}

QVector<Vacancy> Vacancy::defecateVacancy(QVector<Employer> list, QVector<Vacancy> vacancyList){
    QVector<Vacancy> defecateVacancy = vacancyList;

    for (int j = 0; j < defecateVacancy.size(); ++j) {
        for(int i = 0; i < list.size(); ++i){
            if(this->stage==0||(defecateVacancy[j].position==list[i].getDesiredPos()&&list[i].stageInDesired()/12 >= defecateVacancy[j].stage&&list[i].getAge()>=defecateVacancy[j].minAge&&list[i].getAge()<=defecateVacancy[j].maxAge)){
                if(defecateVacancy[j].needGraduation){
                    if(list[i].getGraduation()=="Есть"){
                        defecateVacancy.remove(j);
                        break;
                    }
                }
                else{
                    defecateVacancy.remove(j);
                    break;
                }
            }
        }
    }

    return defecateVacancy;
}

QVector<Employer> Vacancy::joblessCandidates(QVector<Employer> list, QVector<Vacancy> vacancyList){
    QVector<Employer> candidates = list;

    for(int i = 0; i<candidates.size(); ++i){
        for(int j = 0; j < vacancyList.size(); ++j){
            if(this->stage==0||(vacancyList[j].position==list[i].getDesiredPos()&&list[i].stageInDesired()/12 >= vacancyList[j].stage&&list[i].getAge()>=vacancyList[j].minAge&&list[i].getAge()<=vacancyList[j].maxAge)){
                if(vacancyList[j].needGraduation){
                    if(list[i].getGraduation()=="Есть"){
                        candidates.remove(i);
                        break;
                    }
                }
                else{
                    candidates.remove(i);
                    break;
                }
            }
        }
    }

    return candidates;
}

