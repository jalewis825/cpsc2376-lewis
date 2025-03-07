/* Write a program that takes user input for a list of integers, stores them in a std::vector,
and prints them in the same order using iterators. Then, find and print the sum of only the
even numbers using an iterator-based loop.*/

#include <iostream>
#include <vector>

void printVector(std::vector<int>& values) {
    if (values.empty()) {
        std::cout << "The vector is empty." << std::endl;
    }
    else {
        std::cout << "Vector contents: { ";
        for (int num : values) {
            std::cout << num << " ";
        }
        std::cout << "}";
        std::cout << std::endl;
    }
}

int main () {
    std::vector<int> values; //empty vector for user to enter ints into

    std::cout << "Enter the number(s) you would like to add to the vector(Press 0 when done): ";

    while (true) {
        int userNum;
        std::cin >> userNum;

        //stop when user enters zero without adding 0 to vector
        if (userNum == 0) {
            break;
        }
        values.push_back(userNum);
    }

    printVector(values);

    //for (int it = values.begin(); it != nums.end(); ++it) {
        //std::cout << *it << " ";
    //}

    return 0;
}