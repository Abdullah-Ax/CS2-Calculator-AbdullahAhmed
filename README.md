This is a simple calculator library in C++ that includes several mathematical operations. The project will be structured with multiple files, utilize proper build management, and be tracked using Git version control.

## Features

- Basic arithmetic operations (addition, subtraction, multiplication, division)
- Advanced operations (factorial, GCD, LCM, power)
- Random number generation
- Mathematical expression parsing using the Shunting Yard Algorithm

## Building the Project

### Prerequisites

- CMake (version 3.10 or higher)
- C++ compiler with C++14 support

### Build Instructions

1. Clone the repository:

git clone https://github.com/Abdullah-Ax/CS2-Calculator-AbdullahAhmed/commits/master
cd CS2-Calculator-AbdullahAhmed

2. Create a build directory and navigate to it:

mkdir build
cd build

3. Generate build files with CMake:

cmake..

4. Build the project:

cmake --build .

5. Run the test program:

./bin/test_calculator


## Usage

### Basic Calculator Functions

#include "calculator.h"
using namespace std;
// Basic arithmetic
double result1 = add(5.0, 3.0); // 8.0
double result2 = subtract(5.0, 3.0); // 2.0
double result3 = multiply(5.0, 3.0); // 15.0
double result4 = divide(5.0, 3.0); // 1.6666...
// Advanced operations
int fact = factorial(5); // 120
int greatest = gcd(48, 18); // 6
int least = lcm(48, 18); // 144
// Random number
int random = rng(1, 100); // Random number between 1 and 100

### Expression Parser

#include "expression_parser.h"
using namespace std;
ExpressionParser parser;
double result = parser.evaluate("3 + 4 * (2 - 1) / 5"); // 3.8


## Expression Syntax

The expression parser supports:
- Basic arithmetic operators: +, -, *, /
- Parentheses for grouping: ( )
- Decimal numbers

Example expressions:
- `3 + 4`
- `10 - 2 * 3`
- `(8 + 2 * 5) / (1 + 3 * 2 - 3)`





Author: Abdullah Ahmed
ID: 900241507
