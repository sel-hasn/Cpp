#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout<<"Cat defualt constructor called"<<std::endl;
}

Cat::Cat(const Cat &other):Animal(other)
{
    std::cout<<"Cat copy constructor called"<<std::endl;
}

Cat::~Cat()
{
    std::cout<<"Cat destructor called"<<std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    std::cout<<"Cat copy assignment called"<<std::endl;
    return *this;
}

std::string Cat::getType() const
{
    return this->type;
}

void Cat::makeSound() const
{
    std::cout<<"~~~Meow~~~"<<std::endl;    
}