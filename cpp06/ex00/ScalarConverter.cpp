#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

bool Non_PrinTable(const std::string &input)
{
    for (size_t i=0; i < input.length(); i++)
    {
        if (input[i] < 32 || input[i] > 126)
            return true;
    }
    return false;
}

bool Is_Char(const std::string &input)
{
    if (input.size() == 1 && !isdigit(input[0]))
        return true;
    return false;
}

bool Is_Integer(const std::string &input)
{
    if (input.length() > 1 && (input[0] == '-' || input[0] == '+'))
    {
        for (size_t i=1; i < input.length(); i++)
        {
            if (!isdigit(input[i]))
            return false;
        }
    }
    for (size_t i=0; i < input.length(); i++)
    {
        if (!isdigit(input[i]))
        return false;
    }
    return true;
}

bool Is_Double(const std::string &input)
{
    int dot = 0;

    if (input.length() > 1 && (input[0] == '-' || input[0] == '+'))
    {
        for (size_t i=1; i < input.length(); i++)
        {
            if (input[i] == '.')
            dot++;
            if (!isdigit(input[i]) && input[i] != '.')
            return false;
        }
        if (dot == 1)
            return true;
    }
    for (size_t i=0; i < input.length(); i++)
    {
        if (input[i] == '.')
            dot++;
        if (!isdigit(input[i]) && input[i] != '.')
            return false;
    }
    if (dot == 1)
        return true;
    return false;
}

bool Is_Float(const std::string input)
{
    if (input.length() > 0 && input[input.length() - 1] == 'f')
    {
        return Is_Double(input.substr(0, input.length() - 1));
    }
    return false;
}

int ConvertToInt(const std::string &input)
{
    std::stringstream ss(input);
    int num;
    
    ss >> num;
    if (ss.fail() || !ss.eof())
    throw std::runtime_error("char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n");
    return num;
}

float ConvertToFloat(const std::string &input)
{
    std::stringstream ss(input);
    float num;
    
    ss >> num;
    if (ss.fail() || !ss.eof())
    throw std::runtime_error("char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n");
    return num;
}

double ConvertToDouble(const std::string &input)
{
    std::stringstream ss(input);
    double num;
    
    ss >> num;
    if (ss.fail() || !ss.eof())
    throw std::runtime_error("char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n");
    return num;
}

bool Is_Special(const std::string &input)
{
    return (input == "-inf" || input == "+inf" || input == "nan" || input == "nanf" || input == "-inff" || input == "+inff");
}

void ScalarConverter::convert(std::string input)
{
    try {
        if (Non_PrinTable(input))
            throw std::runtime_error("Invalid Input (Non PrinTable Character)");
        else if (Is_Char(input))
        {
            char c = input[0];
            std::cout<<"char: ";
            if ((c >= 0 && c < 32) || c == 127)
                std::cout<<"Non Printable"<<std::endl;
                else
                std::cout<<"'"<<c<<"'"<<std::endl;
                std::cout<<"int: "<<static_cast<int>(c)<<std::endl;
                std::cout<<"float: "<<static_cast<float>(c)<<".0f"<<std::endl;
                std::cout<<"double: "<<static_cast<double>(c)<<".0"<<std::endl;
            }
            else if (Is_Integer(input))
            {
                int i = ConvertToInt(input);
                std::cout<<"char: ";
                if (i > std::numeric_limits<char>::max() || i < std::numeric_limits<char>::min())
                    std::cout<<"impossible"<<std::endl;
                else if (i < 0 || ((i >= 0 && i < 32) || i == 127))
                    std::cout<<"Non Printable"<<std::endl;
                else
                    std::cout<<"'"<<static_cast<char>(i)<<"'"<<std::endl;
                std::cout<<"int: "<<i<<std::endl;
                std::cout<<"float: "<<static_cast<float>(i)<<".0f"<<std::endl;
                std::cout<<"double: "<<static_cast<double>(i)<<".0"<<std::endl;
            }
            else if (Is_Float(input))
            {
                float f = ConvertToFloat(input);
                std::cout<<"char: ";
                if (f > std::numeric_limits<char>::max() || f < std::numeric_limits<char>::min())
                    std::cout<<"impossible"<<std::endl;
                else if (f < 0 || ((f >= 0 && f < 32) || f == 127))
                    std::cout<<"Non Printable"<<std::endl;
                else
                    std::cout<<"'"<<static_cast<char>(f)<<"'"<<std::endl;
                std::cout<<"int: ";
                if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
                    std::cout<<"impossible"<<std::endl;
                else 
                    std::cout<<static_cast<int>(f)<<std::endl;
                std::cout<<"float: "<<f<<std::endl;
                std::cout<<"double: "<<static_cast<double>(f)<<std::endl;
            }
            else if (Is_Double(input))
            {
                double d = ConvertToDouble(input);
                std::cout<<"char: ";
                if (d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min())
                    std::cout<<"impossible"<<std::endl;
                else if (d < 0 || ((d >= 0 && d < 32) || d == 127))
                    std::cout<<"Non Printable"<<std::endl;
                else
                    std::cout<<"'"<<static_cast<char>(d)<<"'"<<std::endl;
                std::cout<<"int: ";
                if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
                    std::cout<<"impossible"<<std::endl;
                else 
                    std::cout<<static_cast<int>(d)<<std::endl;
                std::cout<<"float: "<<static_cast<float>(d)<<std::endl;
                std::cout<<"double: "<<d<<std::endl;
            }
            else if (Is_Special(input))
            {
                if (input == "nan" || input == "nanf")
                {
                    std::cout<<"char: impossible"<<std::endl;
                    std::cout<<"int: impossible"<<std::endl;
                    std::cout<<"float: nanf"<<std::endl;
                    std::cout<<"double: nan"<<std::endl;
                }
                else if (input == "-inf" || input == "-inff")
                {
                    std::cout<<"char: impossible"<<std::endl;
                    std::cout<<"int: impossible"<<std::endl;
                    std::cout<<"float: -inff"<<std::endl;
                    std::cout<<"double: -inf"<<std::endl;
                }
                else if (input == "+inf" || input == "+inff")
                {
                    std::cout<<"char: impossible"<<std::endl;
                    std::cout<<"int: impossible"<<std::endl;
                    std::cout<<"float: +inff"<<std::endl;
                    std::cout<<"double: +inf"<<std::endl;
                }
            }
            else 
                throw std::runtime_error("Invalid Input");
    }
    catch (std::exception &exp)
    {
        std::cerr<<"Erorr: "<<exp.what()<<std::endl;
    }
}
