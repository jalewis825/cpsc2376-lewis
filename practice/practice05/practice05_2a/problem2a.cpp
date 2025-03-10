#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> values{ 1, 5, 8, 14, 22, 25, 27 };

    //finds sum of numbers in vector
    int sum = std::accumulate(values.begin(), values.end(), 0);

    //multiplies all numbers in vector together; initilized at 1 for multiplication
    int product = 1;
    for (std::vector<int>::iterator it = values.begin(); it != values.end(); it++) {
        product *= *it;
    }

    //prints vector
    std::cout << "Vector contents: {";
    for (std::vector<int>::iterator it = values.begin(); it != values.end(); it++) {
        if (it != values.begin()) {
            std::cout << ", ";
        }
        std::cout << *it;
    }
    std::cout << "}" << std::endl;

    std::cout << "Vector Sum: " << sum << std::endl;
    std::cout << "Vector Product: " << product << std::endl;

    return 0;
}

//AI: N/A