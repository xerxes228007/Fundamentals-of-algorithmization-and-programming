#pragma once

class expression
{
public:
    virtual double evaluate() = 0;
    virtual ~expression() {};
};

class Number : public expression
{
public:
    Number(double num)
        : expression()
        , value(num)
    {};
    double evaluate() override { return value; };
private:
    double value;
};

class BinaryOperation : public expression
{
public:
    BinaryOperation(expression* left, const char action, expression* right);
    ~BinaryOperation() { delete left; delete right; };
    double evaluate() override;
private:
    expression* left;
    expression* right;
    char action;
};