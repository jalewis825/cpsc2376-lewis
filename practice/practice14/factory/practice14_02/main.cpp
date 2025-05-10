//AI: Used to give me a file structure to give me an idea where to start.

#include "shape.h"
#include "shape_factory.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>



int main()
{
    std::ifstream infile("shapes.txt");
    if (!infile) {
        std::cerr << "Failed to open shapes.txt" << std::endl;
        return 1;
    }

    std::vector<std::unique_ptr<Shape>> shapes;
    std::string line;
    int lineNumber = 1;

    while (std::getline(infile, line)) {
        try {
            shapes.push_back(createShape(line, lineNumber));
        }
        catch (const std::exception& e) {
            std::cerr << "Skipping line: " << e.what() << std::endl;
        }
        ++lineNumber;
    }

    double totalArea = 0.0;
        for (const auto& shape : shapes) {
            totalArea += shape->area();
        }

        std::cout << "Total area of all valid shapes: " << totalArea << std::endl;

        return 0;
}