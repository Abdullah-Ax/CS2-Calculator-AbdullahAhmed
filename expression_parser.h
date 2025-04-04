#ifndef EXPRESSION_PARSER_H
#define EXPRESSION_PARSER_H

#include <string>
#include <vector>
#include <stack>

using namespace std;

// Token types for parsing
enum TokenType { NUMBER, OPERATOR, LEFT_PAREN, RIGHT_PAREN };

// Token structure
struct Token {
    TokenType type;
    string value;
};

class ExpressionParser {
private:
    vector<Token> tokenize(const string& expression);
    bool isOperator(char c);
    int getPrecedence(const string& op);
    vector<Token> infixToPostfix(const vector<Token>& tokens);
    double evaluatePostfix(const vector<Token>& postfix);

public:
    double evaluate(const string& expression);
};

#endif // EXPRESSION_PARSER_H

