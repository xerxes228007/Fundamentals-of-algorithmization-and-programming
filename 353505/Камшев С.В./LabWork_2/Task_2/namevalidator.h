#ifndef NAMEVALIDATOR_H
#define NAMEVALIDATOR_H
#include <QValidator>

class nameValidator: public QValidator
{
public:
    nameValidator();

    QValidator::State validate(QString &input, int &pos) const override;
};

#endif // NAMEVALIDATOR_H
