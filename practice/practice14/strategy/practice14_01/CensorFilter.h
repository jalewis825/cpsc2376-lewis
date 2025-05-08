//AI: Used to help me with the logic of filtering specific words
#pragma once

#include "ITextFilter.h"
#include <string>
#include <vector>
#include <sstream>

class CensorFilter : public ITextFilter {
	std::vector<std::string> badWords = {
		"fuck",
		"bitch",
		"shit",
		"ass",
		"asshole",
		"bastard",
		"damn",
		"dammit",
		"damn it",
		"cunt",
		"piss off",
		"motherfucker"
	};

	std::string toLower(const std::string& str) const {
		std::string result = str;
		std::transform(result.begin(), result.end(), result.begin(), ::tolower);
		return result;
	}

	std::string censorWord(const std::string& word) {
		std::string core = word;
		std::string trailing;

		while (!core.empty() && std::ispunct(core.back())) {
			trailing = core.back() + trailing;
			core.pop_back();
		}
		std::string lowerCore = toLower(core);
		for (const auto& bad : badWords) {
			if (lowerCore == bad) {
				return std::string(word.size(), '*') + trailing;
			}
		}
		return word;
	}

public:
	std::string apply(const std::string& input) override {
		std::istringstream iss(input);
		std::ostringstream oss;
		std::string word;
		bool first = true;
		while (iss >> word) {
			if (!first) oss << " ";
			oss << censorWord(word);
			first = false;
		}
		return oss.str();
	}
};
