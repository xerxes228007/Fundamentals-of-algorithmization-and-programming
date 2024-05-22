#include "expression.h"

BinaryOperation::BinaryOperation(expression* left, char action, expression* right)
	: action(action)
	, left(left)
	, right(right)
{};

double BinaryOperation::evaluate()
{
    switch (action)
    {
	case '+':return(left->evaluate() + right->evaluate());
	case '-':return(left->evaluate() - right->evaluate());
	case '*':return(left->evaluate() * right->evaluate());
	case '/':return(left->evaluate() / right->evaluate());
	default:return(0);
    }
};