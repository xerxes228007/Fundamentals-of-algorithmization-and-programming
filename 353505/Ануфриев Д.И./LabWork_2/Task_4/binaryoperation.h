#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H

#include "expression.h"

class BinaryOperation : public Expression
{
public:
    ~BinaryOperation();
    double evaluate() override;

    BinaryOperation() : Expression {Expression::Type::BinaryOperation} {}


private:
    Expression *first, *second;
    char operation;
};

#endif // BINARYOPERATION_H
