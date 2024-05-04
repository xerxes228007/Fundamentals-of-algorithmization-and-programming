#include "number.h"

Number::Number() {}

Number::Number(double numb)
{
    this->numb = numb;
}

double Number::evaluate()
{
    return numb;
}
