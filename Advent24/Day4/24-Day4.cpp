#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <regex>

std::vector<std::vector<char>> parse_input(std::ifstream& file)
{ 
    std::string line;
    std::vector<std::vector<char>> puzzle;
    int i = 0;
    while (std::getline(file, line))
    {
        std::vector<char> row;
        for (auto j = 0; j < line.size(); j++)
        {
           row.push_back(line[j]);
           std::cout << line[j];
        }
        puzzle.push_back(row);
        std::cout << std::endl;
        i++;
    }
    return puzzle;
}
int main(int argc, char const *argv[])
{
    std::ifstream file;
    file.open("input.txt");
    
    if (!file)
    {
        std::cout << "Invalid file." << std::endl;
    }
    
    int total = 0;
    std::vector<std::vector<char>> puzzle;
    puzzle = parse_input(file);
    int rows = puzzle.size();
    int columns = puzzle[0].size();
    for (auto i = 0; i < rows; i++)
    {
        for (auto j = 0; j < columns; j++)
        {
            /* BRUTE
            If a value is 'x', check in all 8 directions to see if 'xmas' can be spelled out.
            If it can, Increment total.
            To check if xmas can be spelled out.
                * Ensure the direction has 3 additional indexes available.
                    * Requires knowing the max rows/columns and the current index. 
                    * Up / Down require knowing y+- 3, Left / Right require knowing x+- 3.
                    * Combination of the two requies both x+- and y+- indexing.
                * Check each layer and if reaching the final 's' increment the total and continue.
            */
            char current = puzzle[i][j];
            if (current != 'X')
            {
               continue; 
            }
            //Check UP
            if (i > 2)
            {
                if (puzzle[i-1][j] == 'M'
                && puzzle[i-2][j] == 'A'
                && puzzle[i-3][j] == 'S')
                {
                    total++;
                }
            }
            //Check DOWN
            if (i + 3 < rows)
            {
                if (puzzle[i+1][j] == 'M'
                && puzzle[i+2][j] == 'A'
                && puzzle[i+3][j] == 'S')
                {
                   total++;
                }
            }
            //Check LEFT
            if (j > 2)
            {
                if (puzzle[i][j-1] == 'M'
                && puzzle[i][j-2] == 'A'
                && puzzle[i][j-3] == 'S')
                {
                    total++;
                }
            }
            //Check RIGHT
            if (j + 3 < columns)
            {
                if (puzzle[i][j+1] == 'M'
                && puzzle[i][j+2] == 'A'
                && puzzle[i][j+3] == 'S')
                {
                    total++;
                }
            }
            //Check UP & LEFT
            if (j > 2 && i > 2)
            {
                if (puzzle[i-1][j-1] == 'M'
                && puzzle[i-2][j-2] == 'A'
                && puzzle[i-3][j-3] == 'S')
                {
                    total++;
                }
            }
            //Check DOWN & LEFT
            if (j > 2 && i + 3 < rows)
            {
                if (puzzle[i+1][j-1] == 'M'
                && puzzle[i+2][j-2] == 'A'
                && puzzle[i+3][j-3] == 'S')
                {
                    total++;
                }
            }
            //Check DOWN & RIGHT
            if (j + 3 < columns && i + 3 < rows)
            {
                if (puzzle[i+1][j+1] == 'M'
                && puzzle[i+2][j+2] == 'A'
                && puzzle[i+3][j+3] == 'S')
                {
                    total++;
                }
            }
            //Check UP & RIGHT
            if (j + 3 < columns && i > 2)
            {
                if (puzzle[i-1][j+1] == 'M'
                && puzzle[i-2][j+2] == 'A'
                && puzzle[i-3][j+3] == 'S')
                {
                    total++;
                }
            }
        }
    }
    
    std::cout << "Total: " << total << std::endl;
    return 0;
}