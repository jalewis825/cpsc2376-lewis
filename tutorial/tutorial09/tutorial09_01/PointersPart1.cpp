#include <iostream>

int main()
{
    int x = 10;                     //declare & initilize integer
    int* y = nullptr;               //delcare a pointer initilzed to nullptr

    y = &x;                         //assign the address of x to y

    //print the values
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "*y: " << *y << std::endl;
    std::cout << "&x: " << &x << std::endl;

    /* expected output:
         x: 10
         y: address of x
        *y: 10
        &x: same as y */
}