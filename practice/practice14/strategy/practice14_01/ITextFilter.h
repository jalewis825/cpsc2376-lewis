//AI: I was a little confused with a starting point and I used AI to help me with a file structure to give me an idea where to start

#pragma once

#include <string>

//interface for text filters with a method to apply a transformation to a string
class ITextFilter {
public:
	virtual std::string apply(const std::string& input) = 0;
	virtual ~ITextFilter() = default;
};