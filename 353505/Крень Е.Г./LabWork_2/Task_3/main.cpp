#include <iostream>
#include "expression.h"

int main()
{
    expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    expression* expr = new BinaryOperation(new Number(3), '+', sube);

    std::cout << sube->evaluate() << std::endl;
    
    delete expr;

    return 0;
}