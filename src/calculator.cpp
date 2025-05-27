#include "calculator.hpp"
#include <iostream>
#include <limits>

// Basic arithmetic operations
double Calculator::add(double a, double b) {
    return a + b;
}

double Calculator::subtract(double a, double b) {
    return a - b;
}

double Calculator::multiply(double a, double b) {
    return a * b;
}

double Calculator::divide(double a, double b) {
    checkDivisionByZero(b);
    return a / b;
}

// Advanced operations
double Calculator::power(double base, double exponent) {
    return std::pow(base, exponent);
}

double Calculator::squareRoot(double number) {
    checkNegativeNumber(number, "square root");
    return std::sqrt(number);
}

unsigned long long Calculator::factorial(unsigned int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

// Utility functions
double Calculator::getValidNumber(const std::string& message) {
    double num;
    std::cout << message;
    while (true) {
        std::cin >> num;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number: ";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return num;
        }
    }
}

// Private helper functions
void Calculator::checkDivisionByZero(double denominator) {
    if (denominator == 0) {
        throw std::runtime_error("Error: Division by zero is not allowed!");
    }
}

void Calculator::checkNegativeNumber(double number, const std::string& operation) {
    if (number < 0) {
        throw std::runtime_error("Error: Cannot calculate " + operation + " of a negative number!");
    }
}
