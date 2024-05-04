#pragma once

#include "Expression.h"

enum BinaryOp {
  Add,
  Sub,
  Mul,
  Div
};

class BinaryOperation : public Expression {
public:
  BinaryOperation(Expression *left, char op, Expression *right);
  ~BinaryOperation();

  double evaluate();

private:
  Expression *left;
  Expression *right;
  BinaryOp op;
};