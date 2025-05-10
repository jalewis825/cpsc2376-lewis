#include "gradebook.h"
#include "observer.h"
#include <iostream>
//AI: used to give me a file system as a starting point
#include <memory>

int main()
{
    Gradebook gb;
    
    gb.addObserver(std::make_shared<Averager>());
    gb.addObserver(std::make_shared<Notifier>(60.0));

    double grade;
    std::cout << "Enter grades (-1 to exit): " << std::endl;
    while (true) {
        std::cout << "Grade: ";
        std::cin >> grade;
        if (grade < 0) {
            break;
        }
        gb.setGrade(grade);
    }
    return 0;
}
