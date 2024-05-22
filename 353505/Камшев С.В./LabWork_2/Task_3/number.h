#ifndef NUMBER_H
#define NUMBER_H
#include "expression.h"

class Number: public Expression
{
public:
    Number();
    Number(double numb);

    double evaluate() override;

    double numb;

};

#endif // NUMBER_H
