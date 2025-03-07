#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        std::cout << "Creating Bureaucrat Alice with grade 1 (valid)" << std::endl;
        Bureaucrat alice("Alice", 1);
        std::cout << alice << std::endl;

        std::cout << "\nTrying to increment Alice (should throw exception)" << std::endl;
        alice.increment();
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "---------------------------\n";

    try {
        std::cout << "Creating Bureaucrat Bob with grade 150 (valid)" << std::endl;
        Bureaucrat bob("Bob", 150);
        std::cout << bob << std::endl;

        std::cout << "\nTrying to decrement Bob (should throw exception)" << std::endl;
        bob.decrement();
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "---------------------------\n";

    try {
        std::cout << "Creating Bureaucrat Charlie with grade 50 (valid)" << std::endl;
        Bureaucrat charlie("Charlie", 50);
        std::cout << charlie << std::endl;

        std::cout << "\nIncrementing Charlie's grade (should be 49 now)" << std::endl;
        charlie.increment();
        std::cout << charlie << std::endl;

        std::cout << "\nDecrementing Charlie's grade (should be back to 50)" << std::endl;
        charlie.decrement();
        std::cout << charlie << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "---------------------------\n";

    try {
        std::cout << "Trying to create Bureaucrat Dave with grade 0 (should throw exception)" << std::endl;
        Bureaucrat dave("Dave", 0);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "---------------------------\n";

    try {
        std::cout << "Trying to create Bureaucrat Eve with grade 151 (should throw exception)" << std::endl;
        Bureaucrat eve("Eve", 151);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
