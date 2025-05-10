#pragma once
#include "observer.h"
#include <vector>
#include <memory>

class Gradebook {
	std::vector<std::shared_ptr<Observer>> observers;
	double grade;
public:
	void addObserver(std::shared_ptr<Observer> obs);
	void setGrade(double g);
private:
	void notifyObservers();
};
