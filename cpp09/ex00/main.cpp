#include "BitcoinExchange.hpp"

int main(int arc, char **arv)
{
    if (arc != 2)
    {
        std::cerr<<"Error: could not open file."<<std::endl;
        return 1;
    }
    try {
        std::map<std::string, double> dataBase = loadDatabase();
        std::ifstream input(arv[1]);
        if (!input.is_open())
            throw std::runtime_error("Error: could not open input file.");
        Processinginput(input, dataBase);
    }
    catch (std::exception &exp)
    {
        std::cerr << exp.what() << std::endl;
    }
    return 0;
}