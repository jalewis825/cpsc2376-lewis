/* Write a program that calculates the sum of all elements in a vector using std::accumulate.
Extend the program to also calculate the product of all elements in the vector and print both results.*/

#include <iostream>
#include <vector>
#include <numeric>

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
        std::cout << "}" << std::endl;
    }
    
    //finds sum of numbers in vector
    int sum = std::accumulate(values.begin(), values.end(), 0);
    
    //multiplies all numbers in vector together
    int product = 1;
    for (std::vector<int>::iterator it = values.begin(); it!= values.end(); it++){
        product *= *it;
    }

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Product: " << product << std::endl;

    return 0;
}

//AI: N/A