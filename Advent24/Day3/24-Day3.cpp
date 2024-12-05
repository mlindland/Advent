#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <regex>

int main(int argc, char const *argv[])
{
    std::ifstream file;
    file.open("input.txt");
    
    if (!file)
    {
        std::cout << "Invalid file." << std::endl;
    }
    std::regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
    
    std::string line;
    int total = 0;
    

    while (std::getline(file, line))
    {
        std::smatch matches;
        std::stringstream ss(line);
        std::string token;
        auto search_start = line.cbegin();
        while (std::regex_search(search_start, line.cend(), matches, pattern))
        {
            total += std::stoi(matches[1]) * std::stoi(matches[2]);
            search_start = matches.suffix().first;
        }
        
    }
    std::cout << "Total: " << total << std::endl;
    return 0;
}

