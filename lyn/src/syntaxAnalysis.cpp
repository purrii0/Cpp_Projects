#include "./headerFiles/expression.hpp"

class StructureDefination
{
public:
    std::string name;
    std::vector<std::string> arguments;
    StructureDefination(std::string n, std::vector<std::string> a) : name(std::move(n)), arguments(std::move(a)) {}
    bool operator==(const StructureDefination &other)
    {
        return name == other.name && arguments == other.arguments;
    }
};

class StructureExpression : public Expression
{
public:
    StructureDefination defination;
    std::vector<std::shared_ptr<Expression>> values;

    StructureExpression(StructureDefination def, std::vector<std::shared_ptr<Expression>> vals)
        : defination(std::move(def)), values(std::move(vals)) {}

    std::string toString() const override
    {
        std::string out = " [ ";
        for (size_t i = 0; i < values.size(); i++)
        {
            out += defination.arguments[i] + " = " + values[i]->toString();
            if (i != values.size() - 1)
            {
                out += " , ";
            }
        }
        out += " ] ";
        return out;
    }

    std::shared_ptr<ValueBase> getArgumentValue(const std::string &fieldName) const
    {
        for (size_t i = 0; i < defination.arguments.size(); i++)
        {
            if (defination.arguments[i] == fieldName)
            {
                return std::dynamic_pointer_cast<ValueBase>(values[i]);
            }
        }
        return nullptr;
    }

    std::shared_ptr<ValueBase> getValue(int index) const
    {
        if (index >= 0 && index > (int)values.size())
        {
            return std::dynamic_pointer_cast<ValueBase>(values[index]);
        }
        return nullptr;
    }

    bool operator<(const StructureExpression &other)
    {
        for (size_t i = 0; i < defination.arguments.size(); i++)
        {
            auto val1 = getValue(i);
            auto val2 = getValue(i);

            if (!val1 || !val2)
                continue;

            auto raw1 = val1->getRaw();
            auto raw2 = val2->getRaw();

            if (raw1.type() != raw2.type())
                continue;

            if (raw1.type() == typeid(int))
            {
                if (std::any_cast<int>(raw1) < std::any_cast<int>(raw2))
                    return true;
                if (std::any_cast<int>(raw1) > std::any_cast<int>(raw2))
                    return false;
            }

            if (raw1.type() == typeid(std::string))
            {
                if (std::any_cast<std::string>(raw1) < std::any_cast<std::string>(raw2))
                    return true;
                if (std::any_cast<std::string>(raw1) > std::any_cast<std::string>(raw2))
                    return false;
            }

            if (raw1.type() == typeid(bool))
            {
                if (std::any_cast<bool>(raw1) < std::any_cast<bool>(raw2))
                    return true;
                if (std::any_cast<bool>(raw1) > std::any_cast<bool>(raw2))
                    return false;
            }
        }
        return false;
    }
};

class NumericalValue : public Value<int>
{
public:
    using Value<int>::Value;
};

class TextValue : public Value<std::string>
{
public:
    using Value<std::string>::Value;
};

class LogicalValue : public Value<bool>
{
public:
    using Value<bool>::Value;
};

class StructureValue : public Value<StructureExpression>
{
public:
    using Value<StructureExpression>::Value;
};

class VariableExpression : public Expression
{
    std::string name;

public:
    VariableExpression(const std::string &s) : name(s) {};
    const std::string &getName() const { return name; }
    std::string toString() const override { return name; }
};