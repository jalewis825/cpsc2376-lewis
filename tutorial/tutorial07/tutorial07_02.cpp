#include <iostream>
 //Object Slicing
class Animal {
public:
    virtual void speak() { std::cout << "Animal speaks\n"; }
};
 
class Cat : public Animal {
public:
    void speak() override { std::cout << "Meow\n"; }
};
 
int main() {
    Cat c;
    Animal& a = c;  // Object slicing happens here without the reference!
    a.speak();     // What will this print? 
    //will print "animal speaks without Animal a being a reference; when reference added prints meow"
}