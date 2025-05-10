#include "shape.h"
#include <string>
#include <sstream>
#include <memory>
#include <stdexcept>
#include <algorithm>

std::unique_ptr<Shape> createShape(const std::string& line, int lineNumber) {
	std::istringstream iss(line);
	std::string type;
	iss >> type;

	std::transform(type.begin(), type.end(), type.begin(), ::tolower);

	if (type == "circle") {
		double r;
		if (iss >> r) {
			return std::make_unique<Circle>(r);
		}
	}
	else if (type == "square") {
		double s;
		if (iss >> s) {
			return std::make_unique<Square>(s);
		}
	}
	else if (type == "rectangle") {
		double w;
		double h;
		if (iss >> w >> h) {
			return std::make_unique<Rectangle>(w, h);
		}
	}
	else if (type == "triangle") {
		double b;
		double h;
		if (iss >> b >> h) {
			return std::make_unique<Triangle>(b, h);
		}
	}

	throw std::runtime_error("Line " + std::to_string(lineNumber) + ". Invalid shape or parameters: " + line);
}