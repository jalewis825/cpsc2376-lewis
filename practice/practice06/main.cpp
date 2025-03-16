#include <iostream>
#include <limits>
#include "Fraction.h"
#include "MixedFraction.h"

int main() {
    int userInput;

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

        if (std::cin.fail()) {
            std::cout << "Invalid choice. Please choose from options 0-7." << std::endl;
            std::cout << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            switch (userInput) {
                case 1:
                    
                    break;
                case 2:
                    
                    break;
                case 3:
                    
                    break;
                case 4:
                    
                    break;
                case 5:
                    
                    break;
                case 6:
                    
                    break;
                case 7:
                    
                    break;
                case 0:
                    std::cout << "Exiting the program. Goodbye!" << std::endl;
                    std::cout << std::endl;
                    return 0;
                default:
                    std::cout << "Invalid choice. Please choose from options 0-7." << std::endl;
                }
                std::cout << std::endl; //extra lines so program is easier to read for the user
                std::cout << "Returning to menu..." << std::endl;
                std::cout << std::endl;
            }
        }
}