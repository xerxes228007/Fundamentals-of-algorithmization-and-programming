#include "desiredpositionvalidator.h"

desiredPositionValidator::desiredPositionValidator() {}

QValidator::State desiredPositionValidator::validate(QString &input, int &pos) const
{
    if (input.size() > 0 && input.size() <= 30 && input.split(' ').size() == 1){
        for (auto& i: input){
            if (!i.isLetter() && i != '-') return QValidator::Invalid;
        }
        return QValidator::Acceptable;
    }
    return QValidator::Invalid;
}
