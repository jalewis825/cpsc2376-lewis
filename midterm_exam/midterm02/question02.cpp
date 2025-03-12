/*AI: Used AI to help with the template function. */
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <fstream>


template<typename T>
T findLargest(const std::vector<T>& vec) {
	T largestNum = std::numeric_limits<T>::lowest();
	for (typename std::vector<T>::const_iterator it = vec.begin(); it != vec.end(); it++) {
		if (*it > largestNum) {
			largestNum = *it;
		}
	}
	return largestNum;
}

int main() {
	std::cout << "Enter filename: ";
	std::string filename;
	std::getline(std::cin, filename);

	std::ifstream file(filename);
	if (!file) {
		std::cout << "Error opening file!" << std::endl;
		return 1;
	}

	std::vector<int> numbers;
	int num;

	//read numbers from the file into the vector
	while (file >> num) {
		numbers.push_back(num);
	}

	//check if numbers is empty
	if (numbers.empty()) {
		std::cerr << "No numbers found in file." << std::endl;
		return 1;
	}

	auto largest = findLargest(numbers);

	std::cout << "The largest number in the file is: " << largest << std::endl;


}