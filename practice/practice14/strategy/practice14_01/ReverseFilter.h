#pragma once

#include "ITextFilter.h"
#include <algorithm>

class ReverseFilter : public ITextFilter {
public:
	std::string apply(const std::string& input) override {
		std::string result = input;
		std::reverse(result.begin(), result.end());
		return result;
	}
};
