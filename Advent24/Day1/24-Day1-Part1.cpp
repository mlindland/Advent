#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstdlib>

int main()
{
    int total = 0;
    std::ifstream file;
    std::string line;
    std::vector<int> row_one;
    std::vector<int> row_two;

    file.open("input.txt");
    if (!file)
    {
        std::cout << "Invalid File" << std::endl;
    }
    
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string token;
        long long counter = 0;
        
        while (std::getline(ss, token, ' '))
        {
            if (token == " " || token == "")
            {
                continue;
            }
            if (counter == 0)
            {
                row_one.push_back(std::stoi(token));
                counter++;
            }
            else
            {
                row_two.push_back(std::stoi(token));
            }
        }
    }
    std::sort(row_one.begin(), row_one.end());
    std::sort(row_two.begin(), row_two.end());
    
    for (auto i = 0; i < row_one.size(); i++)
    {
        total += std::abs(row_two[i] - row_one[i]);
    }
    std::cout << "Total Distance: " << total << std::endl;
    return 0; 
}
