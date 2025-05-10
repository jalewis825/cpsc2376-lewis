#include "observer.h"
#include <iostream>

void Averager::update(double grade){
	total += grade;
	++count;
	double average = total / count;
	std::cout << "[Averager] New grade: " << grade << ", Running average: " << average << std::endl;

};

void Notifier::update(double grade) {
	if (grade < threshold) {
		std::cout << "[Notifier] Grade " << grade << " is below threshold (" << threshold
			<< "). Email sent to student@example.com." << std::endl;
	}

};