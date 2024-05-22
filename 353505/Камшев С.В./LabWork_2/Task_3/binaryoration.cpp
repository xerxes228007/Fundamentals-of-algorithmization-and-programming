#include "binaryoration.h"

BinaryOration::BinaryOration() {}

BinaryOration::~BinaryOration()
{
    delete number1;
    delete number2;
}

BinaryOration::BinaryOration(double *a, char str, double *b)
{
    number1 =a;
    number2 = b;
    operation = str;
}

double BinaryOration::evaluate()
{
    if (operation == '+') return *number1 + *number2;
    if (operation == '*') return *number1 * *number2;
    if (operation == '/') return *number1 / *number2;
    if (operation == '-') return *number1 - *number2;
}
