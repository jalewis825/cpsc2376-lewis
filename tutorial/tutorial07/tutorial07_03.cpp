#include <iostream>
 //Virtual Destructor
class Animal {
public:
    virtual ~Animal() { std::cout << "Animal destroyed\n"; } //if you don't use virtual only animal will be destroyed and cat will not
};
 
class Cat : public Animal {
public:
    ~Cat() { std::cout << "Cat destroyed\n"; }
};
 
int main() {
    Animal* a = new Cat();
    delete a;  // Ensures Cat's destructor is called
}