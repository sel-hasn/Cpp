#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "defualt";
    std::cout<<"Brain defualt constructor called"<<std::endl;
}

Brain::Brain(const Brain &other)
{
    std::cout<<"Brain copy constructor called"<<std::endl;
    *this = other;
}

Brain::~Brain()
{
    std::cout<<"Brain destructor called"<<std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    std::cout<<"Brain copy assignment called"<<std::endl;
    return *this;
}