#ifndef SPAN_HPP
# define SPAN_HPP

#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <vector>
#include <ctime>

class Span {
private:
std::vector<int> element;
unsigned int N;

public:
    Span(unsigned int _N);
    Span(const Span& other);
    ~Span();

    Span& operator=(const Span& other);

    void addNumber(int number);

    int shortestSpan() const;
    int longestSpan() const;
};

#endif