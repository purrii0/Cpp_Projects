#include "./headerFiles/expression.hpp"

class OperatorExpression : public Expression
{
};

class UnaryOperatorExpression : public OperatorExpression
{
    std::shared_ptr<Expression> value;

public:
    UnaryOperatorExpression(std::shared_ptr<Expression> val)
        : value(std::move(val)) {}

    std::shared_ptr<Expression> getValue() const
    {
        return value;
    }
    std::string toString() const override
    {
        return " Unary ( " + value->toString() + " ) ";
    }
};

class BinaryOperatorExpression : public OperatorExpression
{
    std::shared_ptr<Expression> left;
    std::shared_ptr<Expression> right;

public:
    BinaryOperatorExpression(std::shared_ptr<Expression> l, std::shared_ptr<Expression> r)
        : left(std::move(l)), right(std::move(r)) {}

    std::shared_ptr<Expression> getLeft() const
    {
        return left;
    }
    std::shared_ptr<Expression> getRight() const
    {
        return right;
    }
    std::string toString() const override
    {
        return " Binary ( " + left->toString() + " , " + right->toString() + " ) ";
    }
};

class UnaryOperatorExpression : public OperatorExpression
{
public:
    virtual std::shared_ptr<ValueBase> calc(std::shared_ptr<ValueBase> val) const = 0;
};

class BinaryOperatorExpression : public OperatorExpression
{
public:
    virtual std::shared_ptr<ValueBase> calc(std::shared_ptr<ValueBase> l, std::shared_ptr<ValueBase> r) const = 0;
};