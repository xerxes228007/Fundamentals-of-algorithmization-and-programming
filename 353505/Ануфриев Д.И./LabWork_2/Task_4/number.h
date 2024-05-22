#ifndef NUMBER_H
#define NUMBER_H

#include "expression.h"

class Number : public Expression
{
public:
    ~Number();
    Number(double);

    double evaluate() override;

    Number() : Expression {Expression::Type::Number} {}

private:
    double number;
};

#endif // NUMBER_H
