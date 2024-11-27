#include <iostream>
#include <fstream>

std::string getlinesum(std::string);

int main(int argc, char const *argv[])
{
    std::ifstream file;
    int total = 0;
    std::string line;

    file.open("input.txt");
    if (!file)
    {
        std::cout << "Invalid File" << std::endl;
    }

    
    while (std::getline(file, line))
    {
        std::string result = getlinesum(line);
        std::cout << result << std::endl;
        std::cout << line << std::endl;
        total += std::stoi(result);
    }
    std::cout << total << std::endl;
    return 0;
}

std::string getlinesum(std::string line)
{
    char first = '\0';
    char last = '\0';
    for (auto it = line.begin(); it != line.end(); ++it )
    {
        if (!isdigit(*it))
            continue;
        
        if (first == '\0')
            first = *it;
        else
        {
            last = *it;
        }
    }
    last = last == '\0' ? first : last;
    std::string result = std::string(1, first) + std::string(1, last);
    return result;
}