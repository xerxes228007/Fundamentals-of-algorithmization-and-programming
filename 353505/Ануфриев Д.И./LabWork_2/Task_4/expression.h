#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression
{
public:
    virtual ~Expression();

    enum Type {Number, BinaryOperation};
    const Type m_kind;
    Expression(Type kind) : m_kind {kind} {}

    virtual double evaluate() = 0;
};

#endif // EXPRESSION_H
