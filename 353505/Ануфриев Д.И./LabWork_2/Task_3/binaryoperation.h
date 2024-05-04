#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H

#include "expression.h"

class BinaryOperation : public Expression
{
public:
    BinaryOperation(Expression* num1, char op, Expression* num2);
    ~BinaryOperation();
    double evaluate() override;

private:
    Expression *first, *second;
    char operation;
};

#endif // BINARYOPERATION_H
