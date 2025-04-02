#include <iostream>

int main() {
    // Allocate integer on the heap
    int* dyn = new int(42);
    std::cout << "Dynamically allocated value: " << *dyn << std::endl;
    std::cout << "Address of dyn: " << dyn << std::endl;

    // Modify the allocated integer
    *dyn = 100;
    std::cout << "Modified value: " << *dyn << std::endl;

    // Clean up
    delete dyn;
    dyn = nullptr; // Prevent dangling pointer

    if (!dyn) {
        std::cout << "dyn is now nullptr after deletion." << std::endl;
    }

    return 0;
}
/*
    expected output:
    Dynamically allocated value: 43
    address of dyn: address of dyn
    Modified value: 100

    ************************
    since it successfully delected dyn it will also display
    "dyn is now nullptr after deletion."
*/