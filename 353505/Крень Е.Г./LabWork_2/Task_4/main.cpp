#include <iostream>
#include "expression.h"

bool check_equals(expression const* left, expression const* right)
{
    return *(void**)left == *(void**)right;
}
int main()
{
    expression* operation1 = new BinaryOperation(new Number(4.5), '*', new Number(5));
    expression* operation2 = new BinaryOperation(new Number(3), '+', operation1);
    expression* number1 = new Number(1);
    expression* number2 = new Number(2);

	std::cout << check_equals(operation1, operation2) << std::endl;
    std::cout << check_equals(number1, operation2) << std::endl;
    std::cout << check_equals(number1, number2) << std::endl;
}
