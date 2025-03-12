#include <iostream>
#include <vector>

class Robot {
private:
	int chargeLevel;

public:
	Robot() : chargeLevel(100) {};

	friend std::ostream& operator<< (std::ostream& os, const Robot& robot) {
		os << "Charge Level: " << robot.chargeLevel << "%";
		return os;
	}
};