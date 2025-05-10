#pragma once

#include <string>
#include <memory>

//base class
class Shape {
public:
	virtual ~Shape() {}
	virtual double area() const = 0;
};

//derived classes
class Circle : public Shape {
private:
	double radius;
public:
	Circle(double r);
	double area() const override;
};

class Square : public Shape {
private:
	double side;
public:
	Square(double s);
	double area() const override;
};

class Rectangle : public Shape {
private:
	double width;
	double height;
public:
	Rectangle(double w, double h);
	double area() const override;
};

class Triangle : public Shape {
private:
	double base;
	double height;
public:
	Triangle(double b, double h);
	double area() const override;
};