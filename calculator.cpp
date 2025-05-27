#include <iostream>
#include <cmath>
#include <string>
#include <limits>

using namespace std;

// Function prototypes
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double base, double exponent);
double squareRoot(double number);
unsigned long long factorial(unsigned int n);

// Function to validate user input
double getValidNumber(const string& message) {
    double num;
    cout << message;
    while (true) {
        cin >> num;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return num;
        }
    }
}

// Function to display the menu
void displayMenu() {
    cout << "\nArithmetic Calculator Menu:\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Power\n";
    cout << "6. Square Root\n";
    cout << "7. Factorial\n";
    cout << "8. Exit\n";
    cout << "Enter your choice (1-8): ";
}

int main() {
    int choice;
    double num1, num2, result;
    
    do {
        displayMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch(choice) {
            case 1:
                num1 = getValidNumber("Enter first number: ");
                num2 = getValidNumber("Enter second number: ");
                result = add(num1, num2);
                cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
                break;
                
            case 2:
                num1 = getValidNumber("Enter first number: ");
                num2 = getValidNumber("Enter second number: ");
                result = subtract(num1, num2);
                cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
                break;
                
            case 3:
                num1 = getValidNumber("Enter first number: ");
                num2 = getValidNumber("Enter second number: ");
                result = multiply(num1, num2);
                cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
                break;
                
            case 4:
                num1 = getValidNumber("Enter numerator: ");
                num2 = getValidNumber("Enter denominator: ");
                if (num2 == 0) {
                    cout << "Error: Division by zero is not allowed!" << endl;
                    break;
                }
                result = divide(num1, num2);
                cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
                break;
                
            case 5:
                num1 = getValidNumber("Enter base: ");
                num2 = getValidNumber("Enter exponent: ");
                result = power(num1, num2);
                cout << "Result: " << num1 << " ^ " << num2 << " = " << result << endl;
                break;
                
            case 6:
                num1 = getValidNumber("Enter number: ");
                if (num1 < 0) {
                    cout << "Error: Cannot calculate square root of a negative number!" << endl;
                    break;
                }
                result = squareRoot(num1);
                cout << "Result: sqrt(" << num1 << ") = " << result << endl;
                break;
                
            case 7:
                num1 = getValidNumber("Enter number: ");
                if (num1 < 0) {
                    cout << "Error: Factorial is not defined for negative numbers!" << endl;
                    break;
                }
                result = factorial(static_cast<unsigned int>(num1));
                cout << "Result: " << num1 << "! = " << result << endl;
                break;
                
            case 8:
                cout << "Thank you for using the Arithmetic Calculator!" << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 8);
    
    return 0;
}

// Function implementations
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

double power(double base, double exponent) {
    return pow(base, exponent);
}

double squareRoot(double number) {
    return sqrt(number);
}

unsigned long long factorial(unsigned int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}
