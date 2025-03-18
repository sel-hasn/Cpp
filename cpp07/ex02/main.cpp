#include "Array.hpp"

int main() {
    Array<int> emptyArray;
    std::cout << "Size of emptyArray: " << emptyArray.size() << std::endl;

    Array<int> intArray(5);
    std::cout << "Size of intArray: " << intArray.size() << std::endl;

    for (int i = 0; i < intArray.size(); ++i) {
        intArray[i] = i * 10;
    }
    std::cout << "intArray elements: ";
    for (int i = 0; i < intArray.size(); ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    Array<int> copiedArray(intArray);
    std::cout << "Size of copiedArray: " << copiedArray.size() << std::endl;
    std::cout << "copiedArray elements: ";
    for (int i = 0; i < copiedArray.size(); ++i) {
        std::cout << copiedArray[i] << " ";
    }
    std::cout << std::endl;

    copiedArray[0] = 100;
    std::cout << "Modified copiedArray[0]: " << copiedArray[0] << std::endl;
    std::cout << "intArray[0] remains unchanged: " << intArray[0] << std::endl;

    Array<int> assignedArray;
    assignedArray = intArray;
    std::cout << "Size of assignedArray: " << assignedArray.size() << std::endl;
    std::cout << "assignedArray elements: ";
    for (int i = 0; i < assignedArray.size(); ++i) {
        std::cout << assignedArray[i] << " ";
    }
    std::cout << std::endl;

    assignedArray[1] = 200;
    std::cout << "Modified assignedArray[1]: " << assignedArray[1] << std::endl;
    std::cout << "intArray[1] remains unchanged: " << intArray[1] << std::endl;

    try {
        std::cout << "Attempting to access intArray[10]: ";
        std::cout << intArray[10] << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    Array<std::string> stringArray(3);
    stringArray[0] = "Hello";
    stringArray[1] = "World";
    stringArray[2] = "Template";
    std::cout << "stringArray elements: ";
    for (int i = 0; i < stringArray.size(); ++i) {
        std::cout << stringArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}