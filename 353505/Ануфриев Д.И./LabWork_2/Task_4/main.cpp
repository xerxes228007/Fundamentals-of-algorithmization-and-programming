#include <iostream>
#include "expression.h"
#include "number.h"
#include "binaryoperation.h"

Expression::Type check(Expression const* left)
{
    if(left->m_kind == Expression::Type::Number)
    {
        //auto number = static_cast<const Number*>(left);
        return Expression::Number;
    }
    else if(left->m_kind == Expression::Type::BinaryOperation)
    {
        //auto binaryOperation = static_cast<const BinaryOperation*>(left);
        return Expression::BinaryOperation;
    }
}


bool check_equals(Expression const* left, Expression const* right)
{
    if(check(left) == check(right)) return true;
    return false;
}

int main()
{
    BinaryOperation* num1 = new BinaryOperation(), *num2 = new BinaryOperation();
    Number* num3 = new Number(), *num4 = new Number();

    std::cout << check_equals(num1, num2) << ' ' << check_equals(num3, num4) << ' ' << check_equals(num1, num3);

    return 0;
}
