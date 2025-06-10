#include <map>
#include <cstring>
#include <vector>
#include <iostream>
#include <regex>

enum class TokenType
{
    Whitespace,
    Keyword,
    GroupDivider,
    Logical,
    Numeric,
    Float,
    Text,
    Variable,
    Operator,
    Comment
};

struct Token
{
    TokenType type;
    std::string value;
};

std::vector<TokenType>
    tokenTypeList = {
        TokenType::Whitespace,
        TokenType::Keyword,
        TokenType::GroupDivider,
        TokenType::Logical,
        TokenType::Numeric,
        TokenType::Float,
        TokenType::Text,
        TokenType::Variable,
        TokenType::Operator,
        TokenType::Comment};

std::map<TokenType, std::string> tokenPatterns = {

    {TokenType::Whitespace, ("[\\s\\t\\n\\r]")},
    {TokenType::Keyword, ("(if|then|end|print|input|struct|arg|new)")},
    {TokenType::GroupDivider, ("(\\[|\\])")},
    {TokenType::Logical, ("true|false")},
    {TokenType::Numeric, ("[0-9]+")},
    {TokenType::Float, ("[0-9]*\\.[0-9]+")},
    {TokenType::Text, ("\"([^\"]*)\"")},
    {TokenType::Variable, ("[a-zA-Z_]+[a-zA-Z0-9_]*")},
    {TokenType::Operator, ("(\\+|\\-|\\>|\\<|\\={1,2}|\\!|\\:{2})")},
    {TokenType::Comment, ("#. *")}

};