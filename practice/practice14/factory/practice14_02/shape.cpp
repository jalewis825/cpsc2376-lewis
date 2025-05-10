#define _USE_MATH_DEFINES
#include <cmath>
#include "shape.h"

Circle::Circle(double r) : radius(r) {}
double Circle::area() const { return M_PI * pow(radius, 2); }

Square::Square(double s) : side(s) {}
double Square::area() const { return pow(side, 2); }

Rectangle::Rectangle(double w, double h) : width(w), height(h) {}
double Rectangle::area() const { return width * height; }

Triangle::Triangle(double b, double h) : base(b), height(h) {}
double Triangle::area() const { return .5 * base * height; }