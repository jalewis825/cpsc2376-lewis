#include <iostream>
#include <memory>
#include "ITextFilter.h"
#include "ReverseFilter.h"
#include "UppercaseFilter.h"
#include "RemoveVowelsFilter.h"
#include "CensorFilter.h"

void printMenu() {
	std::cout << "Choose a filter strategy: " << std::endl;
	std::cout << "1. Reverse" << std::endl;
	std::cout << "2. Uppercase" << std::endl;
	std::cout << "3. Remove Vowels" << std::endl;
	std::cout << "4. Censor Bad Words" << std::endl;
	std::cout << "0. Exit" << std::endl;
	std::cout << "Your choice: ";
}

std::unique_ptr<ITextFilter> createStrategy(int choice) {
	switch (choice) {
	case 1:
		return std::make_unique<ReverseFilter>();
	case 2:
		return std::make_unique<UppercaseFilter>();
	case 3:
		return std::make_unique<RemoveVowelsFilter>();
	case 4:
		return std::make_unique<CensorFilter>();
	default:
		return nullptr;
	}
}

int main() {
	std::string input;
	std::cout << "Enter a sentance: ";
	std::getline(std::cin, input);

	int choice = -1;

	while (true) {
		printMenu();
		std::cin >> choice;
		std::cin.ignore();

		if (choice == 0) {
			break;
		}

		auto strategy = createStrategy(choice);
		if (!strategy) {
			std::cout << "Invalid choice. Try again" << std::endl;
			continue;
		}

		std::string output = strategy->apply(input);
		std::cout << "Filtered Output: " << output << std::endl;
	}

	std::cout << "Goodbye!" << std::endl;
	return 0;
}