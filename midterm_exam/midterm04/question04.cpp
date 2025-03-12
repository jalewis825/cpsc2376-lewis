/*AI: couldn't remember how to break apart the string to ints; used AI for sstream.
Also, I kept confusing myself with my bool and needed help with the "if (isOddA != isOddB)" part. 
I couldn't figure out how to articulate that.*/
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>


int main() {
    std::vector<int> values; //empty vector for user to enter ints into

    std::cout << "Enter a list of space-separate numbers: ";

    std::string userNums;
    std::getline(std::cin, userNums);

    //break up each input into an integer & store in vector
    std::stringstream ss(userNums);
    std::vector<int> numbers;
    int num;

    while (ss >> num) {
        numbers.push_back(num);
    }

    //create lambda function
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
        
        //defines odd
        bool isOddA = a % 2 != 0;
        bool isOddB = b % 2 != 0;
        
        //checks numbers to see if they are both even
        if (isOddA != isOddB) {
            return isOddA;
        }
        return a > b;
        });

    //print results
    std::cout << "Sorted numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }

    return 0;
}
 