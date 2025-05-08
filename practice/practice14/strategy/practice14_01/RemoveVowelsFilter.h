//AI: I needed AI to help me with the logic of this filter. The previous too where simplier because I knew std::reverse and std::transform existed
#pragma once

#include "ITextFilter.h"
#include <string>

class RemoveVowelsFilter : public ITextFilter {
public:
	std::string apply(const std::string& input) override {
		std::string result;
		for (char c : input) {
			if (std::string("aeiouAEIOU").find(c) == std::string::npos) {
				result += c;
			}
		}
		return result;
	}
};