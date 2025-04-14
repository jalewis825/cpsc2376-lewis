### Bad Usage Example:
	Rectangle* raw = new Rectangle(4, 3);
	std::unique_ptr<Rectangle> badPtr(raw); // BAD!

	Safer Alternative:
	auto goodPtr = std::make_unique<Rectangle>(4, 3);

### Passing unique_ptr to a Function (by value)
	void takeOwnership(std::unique_ptr<Rectangle> r) {
		r -> printArea();
	}

	int main () {
		auto rect = std::make_unique<Rectangle>(2, 3);
		takeOwnership(std::move(rect));
	}

### Returning unique_ptr from a function:
	std::unique_pt<Rectangle> makeRect() {
		return std::make_unique<Rectangle>(5,5);
	}

### Passing unique_ptr by Reference:
	void createRectangle(std::unique_ptr<Rectangle>& ptr) {
		ptr = std::make_unique<Rectangle>(7,4);
	}