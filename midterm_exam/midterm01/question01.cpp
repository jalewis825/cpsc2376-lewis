/*AI: couldn't remember the engine (std::mt19937) and used AI to look it up. Also forgot to dereference max/min at first.
Used AI to figure out that.*/

#include <iostream>
#include <random>
#include <vector>
#include <numeric>

std::vector<int> randomNums;

int calculateSum(const std::vector<int>& nums) {
	if (nums.empty()) {
		std::cout << "Vector is empty." << std::endl;
		return 0;
	}

	return std::accumulate(nums.begin(), nums.end(), 0);
}

void findMaxMin(const std::vector<int>& nums) {
	if (nums.empty()) {
		std::cout << "Vector is empty." << std::endl;
	}
	int minValue = *std::min_element(nums.begin(), nums.end());
	int maxValue = *std::max_element(nums.begin(), nums.end());

	std::cout << "Minimum Value: " << minValue << std::endl;
	std::cout << "Maximum Value: " << maxValue << std::endl;
}

int calculateAverage(const std::vector<int>& nums) {
	if (nums.empty()) {
		std::cout << "Vector is empty." << std::endl;
		return 0;
	}
	int average = calculateSum(nums) / nums.size();
	return average;
}

int main() {
	std::cout << "How many random numbers should I generate? ";
	while (true) {
		int userInput;
		std::cin >> userInput;

		//check for valid input from user
		if (std::cin.fail() || userInput <= 0) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
			std::cout << "Invalid input! Please enter a number greater than 0. " << std::endl;
		}
		else
		{
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<> dist(1, 100);//sets rang of nums 1-100

			for (int i = 0; i < userInput; i++) {
				int randNum = dist(gen);
				randomNums.push_back(randNum);//stores the numbers to the vector
			}

			std::cout << "Generated Numbers: " << std::endl;
			for (int i = 0; i < randomNums.size(); i++) {
				std::cout << randomNums[i] << " " << std::endl;
			}

			std::cout << std::endl;

			int vectorSum = calculateSum(randomNums);
			std::cout << "Sum of all numbers: " << vectorSum << std::endl;

			findMaxMin(randomNums);

			std::cout << "Average of all numbers: " << calculateAverage(randomNums) << std::endl;
			
			break;
		}
	}
	return 0;
}