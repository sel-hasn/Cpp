#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    brain = new Brain();
    std::cout<<"Dog defualt constructor called"<<std::endl;
}

Dog::Dog(const Dog &other):Animal(other)
{
    brain = new Brain(*other.brain);
    std::cout<<"Dog copy constructor called"<<std::endl;
}

Dog::~Dog()
{
    delete brain;
    std::cout<<"Dog destructor called"<<std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
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