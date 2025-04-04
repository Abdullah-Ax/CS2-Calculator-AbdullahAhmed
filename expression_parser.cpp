#include "expression_parser.h"
#include "calculator.h"
#include <cctype>
#include <stdexcept>

using namespace std;

vector<Token> ExpressionParser::tokenize(const string& expression) {
    vector<Token> tokens;
    string currentNumber;
    
    for (size_t i = 0; i < expression.length(); i++) {
        char c = expression[i];
        
        if (isspace(c)) continue;
        
        if (isdigit(c) || c == '.') {
            currentNumber += c;
            if (i + 1 == expression.length() || (!isdigit(expression[i + 1]) && expression[i + 1] != '.')) {
                tokens.push_back({NUMBER, currentNumber});
                currentNumber.clear();
            }
        }
        else if (isOperator(c)) {
            tokens.push_back({OPERATOR, string(1, c)});
        }
        else if (c == '(') {
            tokens.push_back({LEFT_PAREN, "("});
        }
        else if (c == ')') {
            tokens.push_back({RIGHT_PAREN, ")"});
        }
        else {
            throw runtime_error("Invalid character in expression");
        }
    }
    
    return tokens;
}

bool ExpressionParser::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int ExpressionParser::getPrecedence(const string& op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    return 0;
}

vector<Token> ExpressionParser::infixToPostfix(const vector<Token>& tokens) {
    vector<Token> output;
    stack<Token> operators;
    
    for (const Token& token : tokens) {
        switch (token.type) {
            case NUMBER:
                output.push_back(token);
                break;
                
            case LEFT_PAREN:
                operators.push(token);
                break;
                
            case RIGHT_PAREN:
                while (!operators.empty() && operators.top().type != LEFT_PAREN) {
                    output.push_back(operators.top());
                    operators.pop();
                }
                if (!operators.empty()) operators.pop(); // Discard left parenthesis
                break;
                
            case OPERATOR:
                while (!operators.empty() && operators.top().type == OPERATOR &&
                       getPrecedence(operators.top().value) >= getPrecedence(token.value)) {
                    output.push_back(operators.top());
                    operators.pop();
                }
                operators.push(token);
                break;
        }
    }
    
    while (!operators.empty()) {
        output.push_back(operators.top());
        operators.pop();
    }
    
    return output;
}

double ExpressionParser::evaluatePostfix(const vector<Token>& postfix) {
    stack<double> values;
    
    for (const Token& token : postfix) {
        if (token.type == NUMBER) {
            values.push(stod(token.value));
        }
        else if (token.type == OPERATOR) {
            if (values.size() < 2) throw runtime_error("Invalid expression");
            
            double b = values.top(); values.pop();
            double a = values.top(); values.pop();
            
            if (token.value == "+") values.push(add(a, b));
            else if (token.value == "-") values.push(subtract(a, b));
            else if (token.value == "*") values.push(multiply(a, b));
            else if (token.value == "/") values.push(divide(a, b));
        }
    }
    
    if (values.size() != 1) throw runtime_error("Invalid expression");
    return values.top();
}

double ExpressionParser::evaluate(const string& expression) {
    vector<Token> tokens = tokenize(expression);
    vector<Token> postfix = infixToPostfix(tokens);
    return evaluatePostfix(postfix);
}

