#ifndef DESIREDPOSITIONVALIDATOR_H
#define DESIREDPOSITIONVALIDATOR_H
#include <QValidator>

class desiredPositionValidator: public QValidator
{
public:
    desiredPositionValidator();
    QValidator::State validate(QString &input, int &pos) const override;

};

#endif // DESIREDPOSITIONVALIDATOR_H
