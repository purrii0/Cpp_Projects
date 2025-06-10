#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <any>
#include <functional>
#include <type_traits>

class Expression
{
public:
    virtual ~Expression() = default;
    virtual std::string toString() const = 0;
};

class ValueBase : public Expression
{
public:
    virtual std::any getRaw() const = 0;
};

template <typename T>
class Value : public ValueBase
{
protected:
    T value;

public:
    Value(const T &val) : value(val) {}
    T getValue() const { return value; }

    std::any getRaw() const override
    {
        return value;
    }
    std::string toString() const override
    {
        if constexpr (std::is_same_v(T, std::string))
        {
            return value;
        }
        else if constexpr (std::is_same_v(T, bool))
        {
            return value ? "true" : "false";
        }
        else
        {
            return std::to_string(Value);
        }
    }
};
