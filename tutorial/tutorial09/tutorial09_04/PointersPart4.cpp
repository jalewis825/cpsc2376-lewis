#include <iostream>

int main() {
    int x = 99;
    int* ptr = &x;      // Pointer to x
    int** ptr2 = &ptr;  // Pointer to ptr

    // Print values
    std::cout << "x: " << x << std::endl;
    std::cout << "*ptr: " << *ptr << std::endl;
    std::cout << "**ptr2: " << **ptr2 << std::endl;

    // Print addresses
    std::cout << "&x: " << &x << std::endl;
    std::cout << "ptr (address of x): " << ptr << std::endl;
    std::cout << "*ptr2 (should be same as ptr): " << *ptr2 << std::endl;
    std::cout << "ptr2 (address of ptr): " << ptr2 << std::endl;

    return 0;
}
/* 
    expected outcome:
         x: 99
      *ptr: 99
    **ptr2: 99
    &x: address of x
    ptr(address of x): should print same as above
    *ptrs2(should be same as ptr): should print same as above
    ptr2(address of ptr): should print new address, address of ptr instead of x
*/