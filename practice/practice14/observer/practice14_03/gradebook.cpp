#include "gradebook.h"

void Gradebook::addObserver(std::shared_ptr<Observer> obs) {
	observers.push_back(obs);
}

void Gradebook::setGrade(double g) {
	grade = g;
	notifyObservers();
}

void Gradebook::notifyObservers() {
	for (auto& obs : observers) {
		obs->update(grade);
	}
}