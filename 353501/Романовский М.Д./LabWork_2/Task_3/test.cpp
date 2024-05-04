#include "BinaryOperation.h"
#include "Expression.h"
#include "Number.h"
#include "gtest/gtest.h"

TEST(basic, taskExample) {
  Expression *sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
  // потом используем его в выражении для +
  Expression *expr = new BinaryOperation(new Number(3), '+', sube);
  // вычисляем и выводим результат: 25.5
  EXPECT_NEAR(expr->evaluate(), 25.5, 1e-4);
  // тут освобождаются *все* выделенные объекты
  // (например, sube будет правым операндом expr, поэтому его удалять не нужно)
  delete expr;
}

TEST(comp, checkEqualNum) {
  Expression *a = new Number(5);
  Expression *b = new Number(10);

  EXPECT_TRUE(Expression::isSameType(a, b));
}

TEST(comp, checkEqualBinOp) {
  Expression *a = new BinaryOperation(nullptr, '+', nullptr);
  Expression *b = new BinaryOperation(nullptr, '+', nullptr);

  EXPECT_TRUE(Expression::isSameType(a, b));
}

TEST(comp, checkUnequal) {
  Expression *a = new BinaryOperation(nullptr, '+', nullptr);
  Expression *b = new Number(0);

  EXPECT_FALSE(Expression::isSameType(a, b));
}