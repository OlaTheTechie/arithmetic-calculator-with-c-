#pragma once
#include <cmath>
#include <stdexcept>
#include <string>

class Calculator {
public:
    // Basic arithmetic operations
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);

    // Advanced operations
    double power(double base, double exponent);
    double squareRoot(double number);
    unsigned long long factorial(unsigned int n);

    // Utility functions
    static double getValidNumber(const std::string& message);

private:
    // Helper function for error handling
    void checkDivisionByZero(double denominator);
    void checkNegativeNumber(double number, const std::string& operation);
};
