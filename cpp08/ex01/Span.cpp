#include "Span.hpp"

Span::Span(unsigned int _N): N(_N)
{
}
Span::Span(const Span& other):element(other.element), N(other.N)
{
}
Span::~Span()
{
}

Span &Span::operator=(const Span& other)
{
    if (this != &other)
    {
        element = other.element;
        N = other.N;
    }
    return *this;
}

void Span::addNumber(int number)
{
    if (number > std::numeric_limits<int>::max() || number < std::numeric_limits<int>::min())
        throw std::overflow_error("number is out of int range");
    if (element.size() < N)
        element.push_back(number);
    else
        throw std::logic_error("max size reached");
}

int Span::shortestSpan() const
{
    if (element.size() < 2) 
        throw( std::logic_error("span have less than 2 values!") );
    std::vector<int> tmp = element;
    std::sort(tmp.begin(), tmp.end());
    int shortestSpan = tmp[1] - tmp[0];
    for (size_t i = 1; i < tmp.size(); i++) 
    {
        int current_Span = tmp[i] - tmp[i - 1];
        if (current_Span < shortestSpan) 
            shortestSpan = current_Span;
    }
    return shortestSpan;
}

int Span::longestSpan() const
{
    if (element.size() < 2) 
        throw( std::logic_error("span have less than 2 values!") );
    std::vector<int> tmp = element;
    std::sort(tmp.begin(), tmp.end());
    return tmp[tmp.size() - 1] - tmp[0];
}