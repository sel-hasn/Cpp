#include "iter.hpp"

template <typename T>
void printelem(T& elem)
{
    std::cout<<elem<<". ";
}

template <typename T>
void incrementelem(T& elem)
{
    ++elem;
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original int array: ";
    iter(intArray, intArrayLength, printelem<int>);
    std::cout << std::endl;

    iter(intArray, intArrayLength, incrementelem<int>);

    std::cout << "Incremented int array: ";
    iter(intArray, intArrayLength, printelem<int>);
    std::cout << std::endl;

    std::string stringArray[] = {"Hello", "World", "Template", "Function"};
    size_t stringArrayLength = sizeof(stringArray) / sizeof(stringArray[0]);

    std::cout << "String array: ";
    iter(stringArray, stringArrayLength, printelem<std::string>);
    std::cout << std::endl;
}
