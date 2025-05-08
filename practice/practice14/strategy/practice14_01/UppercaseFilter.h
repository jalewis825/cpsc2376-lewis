//AI: I always have to look up the std::transform syntax; you'd think I'd have it memorized by now
#pragma once

#include "ITextFilter.h"
#include <algorithm>

class UppercaseFilter : public ITextFilter {
public:
	std::string apply(const std::string& input) override {
		std::string result = input;
		std::transform(result.begin(), result.end(), result.begin(), ::toupper);
		return result;
	}
};