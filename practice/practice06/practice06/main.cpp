#include <iostream>
#include <limits>
#include "Fraction.h"
#include "MixedFraction.h"

//Function to make sure integer is entered from user

int getValidInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter valid integer." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            return value;
        }
    }
}

//Fuction to get valid denominator
int getValidDenominator() {
    int den;
    while (true) {
        den = getValidInt("Enter denominator: ");
        if (den == 0) {
            std::cout << "Denominator cannot be zero. Please enter a valid denominator." << std::endl;
        }
        else {
            return den;
        }
    }
}


int main() {
    int userInput;
    Fraction currentFraction;

    while (true) {
        std::cout << "Options:" << std::endl;
        std::cout << "1. Enter a fraction manually" << std::endl;
        std::cout << "2. Add a fraction" << std::endl;
        std::cout << "3. Subtract a fraction" << std::endl;
        std::cout << "4. Multiply by a fraction" << std::endl;
        std::cout << "5. Divide by a fraction" << std::endl;
        std::cout << "6. Display as mixed fraction" << std::endl;
        std::cout << "7. Clear fraction" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> userInput;

        if (std::cin.fail() || userInput < 0 || userInput > 7) {
            std::cout << "Invalid choice. Please choose from options 0-7." << std::endl;
            std::cout << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (userInput) {
        case 1: {
            int num = getValidInt("Enter numerator: ");
            int den = getValidDenominator();

            try {
                currentFraction = Fraction(num, den);
                std::cout << "Fraction is set to: " << currentFraction << std::endl;
            }
            catch (const std::exception& e) {
                std::cout << "Error " << e.what() << std::endl;
            }
            break;
        }
        case 2: {
            int num = getValidInt("Enter numerator: ");
            int den = getValidDenominator();

            try {
                Fraction newFraction(num, den);
                currentFraction = currentFraction + newFraction;
                std::cout << "Result: " << currentFraction << std::endl;
            }
            catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            break;
        }
        case 3: {
            int num = getValidInt("Enter numerator: ");
            int den = getValidDenominator();

            try {
                Fraction newFraction(num, den);
                currentFraction = currentFraction - newFraction;
                std::cout << "Result: " << currentFraction << std::endl;
            }
            catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            break;
        }
        case 4: {
            int num = getValidInt("Enter numerator: ");
            int den = getValidDenominator();

            try {
                Fraction newFraction(num, den);
                currentFraction = currentFraction * newFraction;
                std::cout << "Result: " << currentFraction << std::endl;
            }
            catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            break;
        }
        case 5: {
            int num = getValidInt("Enter numerator: ");
            int den = getValidDenominator();

            try {
                Fraction newFraction(num, den);
                currentFraction = currentFraction / newFraction;
                std::cout << "Result: " << currentFraction << std::endl;
            }
            catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            break;
        }
        case 6: {
            MixedFraction mixed(currentFraction);
            std::cout << "Mixed fraction: " << mixed << std::endl;
            break;
        }
        case 7: {
            currentFraction = Fraction(0, 1);
            std::cout << "Fraction cleared. Current fraction is: " << currentFraction << std::endl;
            break;
        }
        case 0: {
            std::cout << "Exiting the program. Goodbye!" << std::endl;
            std::cout << std::endl;
            return 0;
        }
        }
        std::cout << std::endl; //extra lines so program is easier to read for the user
        std::cout << "Returning to menu..." << std::endl;
        std::cout << std::endl;
    }
}
    
