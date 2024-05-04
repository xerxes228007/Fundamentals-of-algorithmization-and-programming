#include "binaryoperation.h"

BinaryOperation::BinaryOperation(Expression* num1, char op, Expression* num2)
{
    first = num1;
    operation = op;
    second = num2;
}

BinaryOperation::~BinaryOperation()
{
    delete first;
    delete second;
}

double BinaryOperation::evaluate()
{
    if(operation == '+') return (first->evaluate() + second->evaluate());
    else if(operation == '-') return (first->evaluate() - second->evaluate());
    else if(operation == '*') return (first->evaluate() * second->evaluate());
    else return (first->evaluate() / second->evaluate());
}
