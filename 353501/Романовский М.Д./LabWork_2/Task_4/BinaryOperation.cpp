#include "BinaryOperation.h"
#include "Expression.h"
#include <stdexcept>

#include <iostream>

BinaryOperation::BinaryOperation(Expression *_left, char _op,
                                 Expression *_right) {
  left = _left;
  switch (_op) {
  case '+':
    op = BinaryOp::Add;
    break;

  case '-':
    op = BinaryOp::Sub;
    break;

  case '*':
    op = BinaryOp::Mul;
    break;

  case '/':
    op = BinaryOp::Div;
    break;

  default:
    throw std::invalid_argument("Unknown operation");
  }
  right = _right;
}

BinaryOperation::~BinaryOperation() {
  // std::cout << "BinaryOperation destroyed" << std::endl;
  delete left;
  delete right;
}

double BinaryOperation::evaluate() {
  double l = left->evaluate();
  double r = right->evaluate();

  switch (op) {
  case BinaryOp::Add:
    return l + r;
  case BinaryOp::Sub:
    return l - r;
  case BinaryOp::Mul:
    return l * r;
  case BinaryOp::Div:
    return l / r;
  }
}