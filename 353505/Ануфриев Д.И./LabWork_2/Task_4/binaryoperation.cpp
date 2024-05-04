#include "binaryoperation.h"

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
