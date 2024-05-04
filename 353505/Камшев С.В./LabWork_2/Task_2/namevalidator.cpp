#include "namevalidator.h"

nameValidator::nameValidator() {}

QValidator::State nameValidator::validate(QString &input, int &pos) const{
    if (input.size() > 0 && input.size() <= 30 && input.split(' ').size() == 1  && input[0].isUpper()){
        for (auto& i: input){
            if (!i.isLetter() && i != '-') return QValidator::Invalid;
        }
        return QValidator::Acceptable;
    }
    return QValidator::Invalid;
}
