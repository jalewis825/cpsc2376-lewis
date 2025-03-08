#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main () {
    std::vector<int> values; //empty vector for user to enter ints into

    std::cout << "Enter a list of integers (press 0 when done): " << std::endl;

    while (true) {
        int userNum;
        std::cin >> userNum;

        //stop when user enters zero without adding 0 to vector
        if (userNum == 0) {
            break;
        }
        values.push_back(userNum);
    }

    //for_each that squares each vector element
    std::cout << "Each integer squared: "; 
    std::for_each(values.begin(), values.end(), [](int num) { std::cout << num * num << " "; });
    std::cout << std::endl; 
    
    //lambda function using accumulate to sum the squared ints
    int squareSum = std::accumulate (values.begin(), values.end(), 0,
        [](int sum, int num){ return sum + (num * num); });
    std::cout << "Sum of squared integers: " << squareSum << std::endl;

    return 0;
}

/*AI: I used AI to help me with the second lambda function. I hadn't added the second parameter
    so I could pass both sum and the squared number.*/
