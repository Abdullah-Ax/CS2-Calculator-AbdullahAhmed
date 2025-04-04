#include <iostream>
#include <iomanip>
#include "calculator.h"
#include "expression_parser.h"

using namespace std;

void testExpressionParser() {
    ExpressionParser parser;
    
    cout << "\n===== Expression Parsing =====" << endl;
    
    string expr1 = "3 + 4 * (2 - 1) / 5";
    cout << "Expression: " << expr1 << endl;
    cout << "Result: " << fixed << setprecision(2) << parser.evaluate(expr1) << endl;
    
    string expr2 = "10 - 2 * 3";
    cout << "Expression: " << expr2 << endl;
    cout << "Result: " << parser.evaluate(expr2) << endl;
    
    string expr3 = "(8 + 2 * 5) / (1 + 3 * 2 - 3)";
    cout << "Expression: " << expr3 << endl;
    cout << "Result: " << parser.evaluate(expr3) << endl;
}

int main() {
    cout << "Calculator Function Testing" << endl;
    cout << "==========================" << endl;
    
    cout << "==TESTING CALCULATOR LIBRARY==" << endl;
    
    double a = 10.5, b = 5.25;
    cout << "Testing with values: " << a << " and " << b << endl;
    cout << "Addition: " << add(a, b) << endl;
    cout << "Subtraction: " << subtract(a, b) << endl;
    cout << "Multiplication: " << multiply(a, b) << endl;
    cout << "Division: " << divide(a, b) << endl;
    cout << "Power: " << power(a, b) << endl;
    
    int n1 = 5, n2 = 3;
    cout << "Factorial of " << n1 << ": " << factorial(n1) << endl;
    cout << "GCD of " << n1 << " and " << n2 << ": " << gcd(n1, n2) << endl;
    cout << "LCM of " << n1 << " and " << n2 << ": " << lcm(n1, n2) << endl;
    
    cout << "Random number between 1 and 100: " << rng(1, 100) << endl;
    
    testExpressionParser();
    
    cout << "==CALCULATOR LIBRARY TESTING DONE==" << endl;
    
    return 0;
}

