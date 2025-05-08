/*City Marathon Results 
Your Task:

Read runner names and their race times (in minutes) from results.txt. Format: Name Time.
Store in std::vector<std::pair<std::string, int>>.
Sort runners from fastest to slowest using std::sort and a lambda.
Print:
Top 3 runners with rankings.
An ellipsis (...) for skipped rankings.
Bottom 3 runners with rankings.

AI: Used AI to generate my runner/times list. I also used it to see the syntax for lambda function with std::sort.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
    std::vector<std::pair<std::string, int>> results;
    std::string name;
    int time;

    std::ifstream infile("results.txt");
    if (!infile) {
        std::cerr << "Failed to open results.txt" << std::endl;
        return 1;
    }

    while (infile >> name >> time) {
        results.emplace_back(name, time);
    }

    int size = results.size();
    
    if (size == 0) {
        std::cout << "No results found." << std::endl;
        return 0;
    }

    if (size > 6 ) {
        std::cout << "Top Runners: " << std::endl;
    }
    else {
        std::cout << "Race Results: " << std::endl;
    }
    

    //loops through the file with sort and uses "second" from pair to sort it by the second piece of data in the file
    std::sort(results.begin(), results.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    for (int i = 0; i < 3 && i < size; ++i) {
        std::cout << (i + 1) << ". " << results[i].first << " - " << results[i].second << " minutes" << std::endl;
    }

    //excludes the ... and "bottom runners" if there were less than 6 runners
    if (size > 6) {
        std::cout << "..." << std::endl;
        std::cout << "Bottom Runners: " << std::endl;
    }

    //makes sure to print the bottom 3 runners from the list without overlap if it was a short list
    for (int i = std::max(3, size - 3); i < size; ++i) {
        std::cout << (i + 1) << ". " << results[i].first << " - " << results[i].second << " minutes" << std::endl;
    }
}
