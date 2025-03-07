#include <iostream>
#include "Fraction.h"
#include "MixedFraction.h"

int main () {
    std::cout << "Current fraction: " << std:: endl;
    std::cout << std::endl;
    while (true) {
        std::cout << "Options: " << std::endl;
        std::cout << "1. Enter a fraction manually" << std::endl;
        std::cout << "2. Add a fraction" << std::endl;
        std::cout << "3. Subtract a fraction" << std::endl;
        std::cout << "4. Multiply by a fraction" << std::endl;
        std::cout << "5. Divide by a fraction" << std::endl;
        std::cout << "6. Display as mixed fraction" << std::endl;
        std::cout << "7. Clear fraction" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter you choice: "; 
        int option;
        std::cin >> option;

        switch (option) {
            case 1: {
                double fraction;
                std::cout << "Enter fraction: ";
                std::cin >> fraction;
                std::cout << std::endl;
                break;
            }

            case 2:{
                double fraction;
                std::cout << "Enter a fraction you would like to add: ";
                std::cin >> fraction;
                break;
            }
            case 3:{
                double fraction;
                std::cout << "Enter a fraction you would like to subtract: ";
                std::cin >> fraction; 
                break;
            }
            case 4:{
                double fraction;
                std::cout << "Enter a fraction you would like to multiply by: ";
                std::cin >> fraction;
                break;
            }
            case 5:{
                double fraction;
                std::cout << "Enter a fraction you would like to divide by: ";
                std::cin >> fraction;
                break;
            }
            case 6:{
                std::cout << "Mixed fraction: " << std::endl;
                break;
            }
            case 7:{
                std::cout << "Fraction has been cleared!" << std::endl;
                break;
            }
            case 0:{
                std::cout << "Exiting program. Goodbye!" << std::endl;
                return 0;
            }
            default: {
                std::cout << "Invalid entry. Enter from options 0-7. Try Again: " << std::endl;
                break;
            }
        }
    }
    return 0;
}
