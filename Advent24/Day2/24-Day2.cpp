#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>

int main(int argc, char const *argv[])
{
    std::ifstream file;
    file.open("debug.txt");
    
    if (!file)
    {
        std::cout << "Invalid file." << std::endl;
    }

    std::string line;
    int total = 0;
    

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string token;
        
        int current, previous = -1;
        int direction = 0;
        bool safe = true;
        bool dampener = true;
        
        while (std::getline(ss, token, ' ') && safe)
        {
            current = std::stoi(token);
            // Handle the first two iterations of a row.
            if (previous == -1)
            {
                previous = current;
                continue;
            }
            
            
            if (current == previous || std::abs(current - previous) > 3)
            {
                if (dampener)
                {
                    dampener = false;
                    //previous = current;
                    continue;
                }
                else
                {
                    safe = false;
                    continue;
                }
            }

            if (direction == 0)
            {
                if (current < previous)
                {
                    direction = -1;
                }
                else
                {
                    direction = 1;
                }
            }
            if ((direction == -1 && current > previous) ||
                (direction == 1 && current < previous))
            {
                // Need to determine which (previous or current) is the problem level and the increment it.
                if (dampener)
                {
                    dampener = false;
                    direction *= -1;
                    //previous = current;
                    continue;
                }
                else
                {
                    safe = false;
                    continue;
                }
            }
            previous = current;
        }
        if (safe)
        {
            std:: cout << line << std::endl;
            total += 1;
        }
    }
    std::cout << "Total safe: " << total << std::endl;
}
