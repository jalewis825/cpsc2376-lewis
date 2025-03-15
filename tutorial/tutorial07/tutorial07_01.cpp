#include <iostream>
 //Polymorphism, Virtual, & override
class Animal {
public:
    virtual void speak() { std::cout << "Animal speaks\n"; } 
};
 
class Cat : public Animal {
public:
    void speak() { std::cout << "Meow\n"; }
};
 
class Dog : public Animal {
public:
    void speak() { std::cout << "Woof\n"; }
};
 
int main() {
    Animal* a1 = new Cat();
    Animal* a2 = new Dog();
 
    a1->speak(); // What will this print? wo "virtual" on base class will print "animal speaks"
    a2->speak(); // What will this print? added "virtual" and now prints "meow" & "woof"
 
    delete a1;
    delete a2;
}