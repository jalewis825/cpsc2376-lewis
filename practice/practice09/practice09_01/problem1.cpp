//AI: I always forget the syntax for the ::tolower/::toupper. I used AI for that

#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    float redPotion{ 0.0f };    //amount of red potion in mL
    float bluePotion{ 0.0f };   //amount of blue potion in mL
    float* flask{ nullptr };    //pointer to the selected potion
    
    std::string userInput;
    while (true) {
        std::cout << "Which potion would you like to add to (Red or Blue)? " << std::endl;
        std::cout << "(enter Done when you are finished.)" << std::endl;
        std::getline(std::cin, userInput);

        std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
    
        if (userInput == "red") {
            flask = &redPotion;     //if user chooses red, it will store address of redPotion in flask
        }
        else if (userInput == "blue") {
            flask = &bluePotion;    //if user chooses blue, it will store address of bluePotion in flask
        }
        else if (userInput == "done") {
            break;
        }
        else {
            std::cout << "Invalid entry. Please enter 'Red', 'Blue', or 'Done'." << std::endl;
            std::cout << std::endl;
            continue;
        }

        float amount;
        std::cout << "How many millileters would you like to add?" << std::endl;
        std::cin >> amount;

        if (std::cin.fail() || amount <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a positive number.";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        //verifies that flask pointer is actually pointing to an address 
        //then adds amount to flask at address stored from above (red or blue)
        if (flask != nullptr) {  
            *flask += amount;
        }

        std::cout << "Current potion levels: " << std::endl;
        std::cout << "Red Potion: " << redPotion << std::endl;
        std::cout << "Blue Potion: " << bluePotion << std::endl;
        std::cout << std::endl;
    }

    std::cout << "Exiting..." << std::endl;
    return 0;
}
