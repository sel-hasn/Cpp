#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    brain = new Brain();
    std::cout<<"Cat defualt constructor called"<<std::endl;
}

Cat::Cat(const Cat &other):Animal(other)
{
    brain = new Brain(*other.brain);
    std::cout<<"Cat copy constructor called"<<std::endl;
}

Cat::~Cat()
{
    delete brain;
    std::cout<<"Cat destructor called"<<std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
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