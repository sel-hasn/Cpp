#include "Span.hpp"

int main() {
    try {
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        // Massive test with 10000 numbers
        Span bigSpan(10000);

        std::srand(std::time(0));
        for (int i = 0; i < 10000; ++i) {
            bigSpan.addNumber(std::rand());
        }

        std::cout << "Big span shortest: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Big span longest: " << bigSpan.longestSpan() << std::endl;

    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
