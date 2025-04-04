#include <iostream>
#include "calculator.h"
using namespace std;

int main(){

    cout << "==TESTING CALCULATOR LIBRARY==" << endl;
    
    double a, b;
    cout << "Enter two numbers: ";
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "Addition: " << add(a, b) << endl;
    cout << "Subtraction: " << subtract(a, b) << endl;
    cout << "Multiplication: " << multiply(a, b) << endl;
    cout << "Division: " << divide(a,b) << endl;
    cout << "Power: " << power(a, b) << endl;
    cout << "Factorial of first number: " << factorial(a) << endl;
    cout << "Factorial of second number: " << factorial(b) << endl;
    cout << "GCD: " << gcd(a, b) << endl;
    cout << "LCM: " << lcm(a, b) << endl;

    cout << "Random number generator test: " << endl;
    cout << "Enter two numbers for your range: ";
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "Random number between " << a << " and " << b << ": " << rng(a, b) << endl;

    cout << "==CALCULATOR LIBRARY TESTING DONE==" << endl;

    return 0;
}
