#include <iostream>

int main() {
    int x = 10;
    int* y = nullptr;

    // Check if y is nullptr (two ways)
    if (y == nullptr) {
        std::cout << "y is nullptr (y == nullptr)" << std::endl;
    }
    if (!y) {
        std::cout << "y is nullptr (!y)" << std::endl;
    }

    // Assign address of x to y
    y = &x;
    if (y) {
        std::cout << "y now points to x's address." << std::endl;
    }

    // Modify x
    x = 20;
    std::cout << "x: " << x << std::endl;
    std::cout << "*y: " << *y << std::endl;
    std::cout << "&x: " << &x << std::endl;
    std::cout << "y: " << y << std::endl;

    return 0;
}

/*
expected output:
x: 20
*y: 20
&x: address of x
y: same address of x 

actual output:
y is nullptr(y==nullptr)
y is nullptr(!y)
y now points to x's address.
x: 20
*y: 20
&x: address of x
y: same address of x
*/