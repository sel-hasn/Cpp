#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout<<"Dog defualt constructor called"<<std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), TEST()
{
    std::cout<<"Dog copy constructor called"<<std::endl;
}

Dog::~Dog()
{
    std::cout<<"Dog destructor called"<<std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    std::cout<<"Dog copy assignment called"<<std::endl;
    return *this;
}

std::string Dog::getType() const
{
    return this->type;
}

void Dog::makeSound() const
{
    std::cout<<"~~~Bark~~~"<<std::endl;    
}
