#pragma once

class Expression {
public:
  virtual double evaluate() = 0;
  virtual ~Expression(){};

  static bool isSameType(Expression *a, Expression *b);
};