#include "Expression.h"

bool Expression::isSameType(Expression *a, Expression *b) {
  void *aVtablePointer = *(void**)a;
  void *bVtablePointer = *(void**)b;
  
  return aVtablePointer == bVtablePointer;
}