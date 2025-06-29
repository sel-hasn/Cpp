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
    Span();
    Span(unsigned int _N);
    Span(const Span& other);
    ~Span();

    Span& operator=(const Span& other);

    void addNumber(int number);

    template <typename Iterator>
    void AddNumbers(Iterator begin, Iterator end)
    {
        unsigned int remaining = N - element.size();
        unsigned int distance = std::distance(begin, end);

        if (distance > remaining){
            throw std::length_error("Not enough space in Span");
        }
        element.insert(element.end(), begin, end);
    }

    int shortestSpan() const;
    int longestSpan() const;
};

#endif