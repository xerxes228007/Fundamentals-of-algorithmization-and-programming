#include <stdio.h>
#include "expression.h"
#include "number.h"
#include "binaryoperation.h"


bool check_equals(Expression const* left, Expression const* right) {
    return  *(void **)left == *(void **)right;
}

int main()
{
    return 0;
}
