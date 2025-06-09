#include "./token/tokenType.hpp"
#include <iostream>

std::string getRegex(TokenType type)
{
    return tokenPatterns[type];
}

class lexicalParser
{
private:
    std::vector<Token> tokens;
    std::string sourceCode;

public:
    lexicalParser(const std::string &s) : sourceCode(s) {};
    std::vector<Token> parse();
    int nextToken(int);
    std::vector<Token> getToken()
    {
        return tokens;
    }
    ~lexicalParser() {};
};

std::vector<Token> lexicalParser::parse()
{
    int position = 0;

    while (position < sourceCode.length())
    {
        int len = nextToken(position);
        if (len == -1)
            break;
        position += len;
    }
    return tokens;
}

int lexicalParser::nextToken(int pos)
{
    std::string nextToken = sourceCode.substr(pos);

    for (TokenType type : tokenTypeList)
    {
        std::string pattern = "^" + getRegex(type);
        std::regex regexPattern(pattern);
        std::smatch match;

        if (std::regex_search(nextToken, match, regexPattern) && match.position(0) == 0)
        {
            std::string fullMatch = match[0].str();
            std::string value = match.size() > 1 ? match[1].str() : match[0].str();
            if (type != TokenType::Whitespace)
            {
                tokens.push_back({type, value});
            }
            return fullMatch.length();
        }
    }

    if (!nextToken.empty())
        std::cerr << "Unexpected token: " << nextToken[0] << "\n";
    else
        std::cerr << "Unexpected end of input\n";
    return -1;
}
