#include "BitcoinExchange.hpp"

bool isAllDigits(const std::string& str) {
    for (size_t i = 0; i < str.length(); ++i) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

bool isValidDate(std::string date)
{
    if (date.length() != 11 || date[4] != '-' || date[7] != '-' || date[10] != ' ')
        return false;

    const std::string minDate = "2009-01-02";

    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    if (!isAllDigits(yearStr) || !isAllDigits(monthStr) || !isAllDigits(dayStr))
        return false;

    int year = std::atoi(yearStr.c_str());
    int month = std::atoi(monthStr.c_str());
    int day = std::atoi(dayStr.c_str());

    if (year < 0 || month < 1 || month > 12 || day < 1)
        return false;

    int maxDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        maxDays[1] = 29;

    if (day > maxDays[month - 1])
        return false;

    if (date.substr(0, 10) < minDate)
        return false;

    return true;
}

bool isValidRate(std::string rate)
{
    if (rate.empty())
    {
        std::cout << "Error: empty input." << std::endl;
        return false;
    }

    if (rate[0] != ' ' || (rate[1] != '.' && !std::isdigit(rate[1])))
    {
        std::cout << "Error: invalid characters in input." << std::endl;
        return false;
    }

    char* end;
    errno = 0;
    double value = strtod(rate.c_str(), &end);

    if (*end != '\0')
    {
        std::cout << "Error: invalid characters in input." << std::endl;
        return false;
    }

    if (errno == ERANGE || value > static_cast<double>(INT_MAX))
    {
        std::cout << "Error: number exceeds INT_MAX." << std::endl;
        return false;
    }

    if (value < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }

    if (value > 1000)
    {
        std::cout << "Error: to large number." << std::endl;
        return false;
    }

    return true;
}

void parseInput(std::string &line, std::map<std::string, double> &map)
{
    if (line.empty())
    {
        std::cout << "Error: empty line detected." << std::endl;
        return ;
    }
    size_t pipepos = line.find('|');
    if (pipepos == std::string::npos)
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return ;
    }
    std::string date = line.substr(0, line.find('|'));
    if (!isValidDate(date))
    {         
        std::cout << "Error: bad input => " << date << std::endl;
		return;
    }
    std::string linerate = line.substr(12);
    if (!isValidRate(linerate))
    return ;
    double value = atof(linerate.c_str());
    
    std::map<std::string, double>::iterator it;
    std::map<std::string, double>::iterator prev;
    it = map.begin();
    prev = map.begin();
    while (it != map.end() && it->first <= date)
    {
        prev = it;
        it++;
    }
    std::cout << date << " => " << value << " = "  << value * prev->second << std::endl;
}

void Processinginput(std::ifstream &input, std::map<std::string, double> &map)
{
    std::string line;
    if (!std::getline(input, line))
    {
        std::cout << "Error: input file is empty." << std::endl;
        return ;
    }
    if (line != "date | value")
    {
        std::cout << "Error: bad header => " << line << std::endl;
        return ;
    }
    while (std::getline(input, line))
    {
        parseInput(line, map);
    }
    input.close();
}

std::map<std::string, double> loadDatabase()
{
    std::ifstream datafile("data.csv");
    if (!datafile.is_open())
		throw std::runtime_error("Error: could not open database file.");
    std::map<std::string, double> dataBase;
    std::string line;
    while (std::getline(datafile, line))
    {
        std::string key = line.substr(0, line.find(','));
        double value = std::atof(line.substr(line.find(',') + 1).c_str());
        dataBase[key] = value;
    }
    datafile.close();
    return dataBase;
}