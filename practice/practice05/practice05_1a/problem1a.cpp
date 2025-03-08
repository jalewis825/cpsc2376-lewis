/* Write a program that takes user input for a list of integers, stores them in a std::vector,
and prints them in the same order using iterators. Then, find and print the sum of only the
even numbers using an iterator-based loop.*/

#include <iostream>
#include <iterator> 
#include <vector>

int main () {
    std::vector<int> values; //empty vector for user to enter ints into

    std::cout << "Enter the number(s) you would like to add to the vector(Press 0 when done): " << std::endl;

    while (true) {
        int userNum;
        std::cin >> userNum;

        //stop when user enters zero without adding 0 to vector
        if (userNum == 0) {
            break;
        }
        values.push_back(userNum);
    }

    //prints values in the same order 
    if (values.empty()) {
        std::cout << "The vector is empty." << std::endl;
    }
    else {
        std::cout << "Vector contents: {";
        for (std::vector<int>::iterator it = values.begin(); it != values.end(); it++) {
            if (it != values.begin()) {
                std::cout << ", ";
            }
            std::cout << *it;
        } 
        std::cout << "}";
    }

    //checks for even numbers and then adds them 
    int sum = 0;
    for (std::vector<int>::iterator it = values.begin(); it!= values.end(); it++){
        if (*it % 2 == 0){
            sum += *it;
        }
    }

    std::cout << std::endl;
    std::cout << "Sum of even numbers in the vector: " << sum << std::endl;

    return 0;
}

//AI: I was facing syntax issues with the iterators. I used AI to help me with that