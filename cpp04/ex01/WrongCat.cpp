#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout<<"WrongCat defualt constructor called"<<std::endl;
}

WrongCat::WrongCat(const WrongCat &other):WrongAnimal(other)
{
    std::cout<<"WrongCat copy constructor called"<<std::endl;
}

WrongCat::~WrongCat()
{
    std::cout<<"WrongCat destructor called"<<std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    std::cout<<"WrongCat copy assignment called"<<std::endl;
    return *this;
}

std::string WrongCat::getType() const
{
    return this->type;
}

void WrongCat::makeSound() const
{
    std::cout<<"~~~Meow~~~"<<std::endl;    
}