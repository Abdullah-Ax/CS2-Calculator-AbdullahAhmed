#include "calculator.h"
#include <stdexcept> // for std::invalid_argument
#include <cmath>
#include <cstdlib> // for rand()

using namespace std;

double add (double a, double b) {
    return a + b;
}

double subtract (double a, double b) {
    return a - b;
}

double multiply (double a, double b) {
    return a * b;
}

double divide (double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero is not allowed."); //throwing instead of printing so as to be more efficient
    }
    return a / b;
}

double power (double base, double exponent) {
    return pow(base, exponent);
}

int factorial(int n) {
    if (n < 0) {
        throw std::invalid_argument("Factorial of a negative number is not defined.");
    }
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    if (a == 0 || b == 0) {
        throw std::invalid_argument("LCM of zero is not defined.");
    }
    return abs(a * b) / gcd(a, b);
}

int rng(int min, int max) {
    if (min > max) {
        throw std::invalid_argument("Minimum value cannot be greater than maximum value.");
    }
    return rand() % (max - min + 1) + min;
} 

// The rng function generates a random number between min and max (inclusive).
// It uses the rand() function from the C++ standard library.