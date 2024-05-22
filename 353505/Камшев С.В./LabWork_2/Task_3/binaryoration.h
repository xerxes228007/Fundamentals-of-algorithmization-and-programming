#ifndef BINARYORATION_H
#define BINARYORATION_H
#include "expression.h"

class BinaryOration: public Expression
{
public:
    BinaryOration();
    ~BinaryOration();
    BinaryOration(double* a, char str, double* b);
    double evaluate() override;
    double* number1, *number2;
    char operation;
};

#endif // BINARYORATION_H
