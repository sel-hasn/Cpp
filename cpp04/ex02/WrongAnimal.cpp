#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    type = "WrongAnimal";
    std::cout<<"WrongAnimal defualt constructor called"<<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other):type(other.type)
{
    std::cout<<"WrongAnimal copy constructor called"<<std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout<<"WrongAnimal destructor called"<<std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    std::cout<<"WrongAnimal copy assignment called"<<std::endl;
    return *this;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}

void WrongAnimal::makeSound() const
{
    std::cout<<"WrongAnimal do not have a Sound"<<std::endl;    
}