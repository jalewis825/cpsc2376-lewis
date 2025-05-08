/*Book Catalog Analyzer
Your Task:

Write a templated function countMatching that accepts a std::vector<T> and a lambda.
In main(), create a std::vector<std::string> with book titles.
Use countMatching to count how many titles contain the word "history".

AI: Used to look up the templated function syntax. Used to generate book title list. Used it to help me search the list regardless of case or 's
*/

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
int countMatching(const std::vector<T>& vec, bool(*condition)(const T&)) {
    int count = 0;
    for (const auto& element : vec) {
        if (condition(element)) {
            ++count;
        }
    }
    return count;
}

bool containsHistory(const std::string& title) {
    std::string lowerTitle = title;
    std::transform(lowerTitle.begin(), lowerTitle.end(), lowerTitle.begin(), 
        [](unsigned char c) {return std::tolower(c);});

    return lowerTitle.find("history") != std::string::npos;
}
int main()
{
    std::vector<std::string> bookTitles = {
        "The Silent Garden",
        "History's Echo",
        "Whispers of the Past",
        "A Journey Through Time",
        "The History of Forgotten Dreams",
        "Shadows of the Empire",
        "History in the Blood",
        "Hogwarts: A History"
    };

    int count = countMatching(bookTitles, containsHistory);

    std::cout << "Number of books titles containing 'history': " << count << std::endl;

    return 0;
}
