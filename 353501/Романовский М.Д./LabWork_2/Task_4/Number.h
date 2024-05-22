#pragma once

#include "Expression.h"

class Number : public Expression {
public:
  Number(double val);
  ~Number();

  double evaluate();

private:
  double val;
};