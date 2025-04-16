//AI: used for the "use math defines" I didn't know I needed that as well as cmath library for M_PI to work
//I had set precision for the areas using pi but I didn't like the trailing zeros on the whole numbers. I used AI to help me get rid of them.
//also I wasn't please with my output so I used AI to help me clean it up.

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <memory>
#include <string>

//Base class
class Shape {
public:
	virtual double getArea() const = 0;
	virtual ~Shape() = default;
};

//Derived classes (Rectangle, Circle, Triangle, Trapezoid)
class Rectangle : public Shape {
private:
	double width;
	double height;

public:
	Rectangle(double w, double h) : width(w), height(h) {}

	double getArea() const override {
		return width * height;
	}

	//print out message to verify destructor is properly called when unique_ptr goes out of scope
	~Rectangle() {
		std::cout << "[Rectangle destroyed]" << std::endl;
	}
};

class Circle : public Shape {
private:
	double radius;

public:
	Circle(double r) : radius(r) {}

	double getArea() const override {
		return M_PI * (radius * radius);
	}

	~Circle() {
		std::cout << "[Circle destroyed]" << std::endl;
	}
};

class Triangle : public Shape {
private:
	double base;
	double height;

public:
	Triangle(double b, double h) : base(b), height(h) {}

	double getArea() const override {
		return .5 * base * height;
	}
	~Triangle() {
		std::cout << "[Triangle destroyed]" << std::endl;
	}
};

class Trapezoid : public Shape {
private:
	double base1;
	double base2;
	double height;

public:
	Trapezoid(double b1, double b2, double h) : base1(b1), base2(b2), height(h) {}

	double getArea() const override {
		return .5 * (base1 + base2) * height;
	}

	~Trapezoid() {
		std::cout << "[Trapezoid destroyed]" << std::endl;
	}
};

void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
	for (const auto& shape : shapes) {
		double area = shape->getArea();

		//checking for whole number to eleminate trailing zeros
		if (std::floor(area) == area) {
			std::cout << "Area: " << static_cast<int>(area) << std::endl;
		}
		else {
			std::cout << "Area: " << std::fixed << std::setprecision(4) << area << std::endl;
		}
	}
}

int main() {
	std::vector<std::unique_ptr<Shape>> shapes;
	std::ifstream file("shapes.txt");

	//verification that there is a file to be opened
	if (!file) {
		std::cerr << "Error: Could not open file." << std::endl;
		return 1;
	}

	std::string line;
	int lineNumber = 0;

	//error checking for valid data in txt file and saving shapes to vector
	while (std::getline(file, line)) {
		++lineNumber;
		std::istringstream iss(line);
		std::string shapeType;
		iss >> shapeType;

		if (shapeType == "rectangle") {
			double width;
			double height;
			if (!(iss >> width >> height)) {
				std::cerr << "Error on line " << lineNumber << ": Invalid or missing rectangle demension." << std::endl;
				continue;
			}
			if (width <= 0 || height <= 0) {
				std::cerr << "Error on line " << lineNumber << ": Rectangle dimensions must be positive." << std::endl;
				continue;
			}
			shapes.push_back(std::make_unique<Rectangle>(width, height));
		}

		else if (shapeType == "circle") {
			double radius;
			if (!(iss >> radius)) {
				std::cerr << "Error on line " << lineNumber << ": Invalid or missing circle demension." << std::endl;
				continue;
			}
			if (radius <= 0) {
				std::cerr << "Error on line " << lineNumber << ": Circle dimensions must be positive." << std::endl;
				continue;
			}
			shapes.push_back(std::make_unique<Circle>(radius));
		}

		else if (shapeType == "triangle") {
			double base;
			double height;
			if (!(iss >> base >> height)) {
				std::cerr << "Error on line " << lineNumber << ": Invalid or missing triangle demension." << std::endl;
				continue;
			}
			if (base <= 0 || height <= 0) {
				std::cerr << "Error on line " << lineNumber << ": Triangle dimensions must be positive." << std::endl;
				continue;
			}
			shapes.push_back(std::make_unique<Triangle>(base, height));
		}

		else if (shapeType == "trapezoid") {
			double base1;
			double base2;
			double height;
			if (!(iss >> base1 >> base2 >> height)) {
				std::cerr << "Error on line " << lineNumber << ": Invalid or missing trapezoid demension." << std::endl;
				continue;
			}
			if (base1 <= 0 || base2 <= 0 || height <= 0) {
				std::cerr << "Error on line " << lineNumber << ": Trapezoid dimensions must be positive." << std::endl;
				continue;
			}
			shapes.push_back(std::make_unique<Trapezoid>(base1, base2, height));
		}

		else {
			std::cerr << "Error on line " << lineNumber << ": Unknown shape type '" << shapeType << "'." << std::endl;
		}
	}

	printAllAreas(shapes);

	return 0;
}