#include "calculator.hpp"
#include <iostream>
#include <string>

// Function to display the menu
void displayMenu() {
    std::cout << "\nArithmetic Calculator Menu:\n";
    std::cout << "1. Addition\n";
    std::cout << "2. Subtraction\n";
    std::cout << "3. Multiplication\n";
    std::cout << "4. Division\n";
    std::cout << "5. Power\n";
    std::cout << "6. Square Root\n";
    std::cout << "7. Factorial\n";
    std::cout << "8. Exit\n";
    std::cout << "Enter your choice (1-8): ";
}

int main() {
    Calculator calc;
    int choice;
    double num1, num2, result;

    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        try {
            switch(choice) {
                case 1:
                    num1 = calc.getValidNumber("Enter first number: ");
                    num2 = calc.getValidNumber("Enter second number: ");
                    result = calc.add(num1, num2);
                    std::cout << "Result: " << num1 << " + " << num2 << " = " << result << std::endl;
                    break;

                case 2:
                    num1 = calc.getValidNumber("Enter first number: ");
                    num2 = calc.getValidNumber("Enter second number: ");
                    result = calc.subtract(num1, num2);
                    std::cout << "Result: " << num1 << " - " << num2 << " = " << result << std::endl;
                    break;

                case 3:
                    num1 = calc.getValidNumber("Enter first number: ");
                    num2 = calc.getValidNumber("Enter second number: ");
                    result = calc.multiply(num1, num2);
                    std::cout << "Result: " << num1 << " * " << num2 << " = " << result << std::endl;
                    break;

                case 4:
                    num1 = calc.getValidNumber("Enter numerator: ");
                    num2 = calc.getValidNumber("Enter denominator: ");
                    result = calc.divide(num1, num2);
                    std::cout << "Result: " << num1 << " / " << num2 << " = " << result << std::endl;
                    break;

                case 5:
                    num1 = calc.getValidNumber("Enter base: ");
                    num2 = calc.getValidNumber("Enter exponent: ");
                    result = calc.power(num1, num2);
                    std::cout << "Result: " << num1 << " ^ " << num2 << " = " << result << std::endl;
                    break;

                case 6:
                    num1 = calc.getValidNumber("Enter number: ");
                    result = calc.squareRoot(num1);
                    std::cout << "Result: sqrt(" << num1 << ") = " << result << std::endl;
                    break;

                case 7:
                    num1 = calc.getValidNumber("Enter number: ");
                    result = calc.factorial(static_cast<unsigned int>(num1));
                    std::cout << "Result: " << num1 << "! = " << result << std::endl;
                    break;

                case 8:
                    std::cout << "Thank you for using the Arithmetic Calculator!" << std::endl;
                    break;

                default:
                    std::cout << "Invalid choice! Please try again." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    } while (choice != 8);

    return 0;
}
