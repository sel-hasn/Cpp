#include "easyfind.hpp"

int main()
{
    std::vector<int> numbers;
    
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);
    numbers.push_back(50);

    try {
        std::vector<int>::iterator it = easyfind(numbers, 50);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::exception &exp)
    {
        std::cout<<"Error: "<<exp.what()<<std::endl;
    }
    try {
        std::vector<int>::iterator it = easyfind(numbers, 11);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::exception &exp)
    {
        std::cout<<"Error: "<<exp.what()<<std::endl;
    }
}