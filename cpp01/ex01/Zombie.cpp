#include "Zombie.hpp"

Zombie::Zombie(void)
{
    this->name = "Fang";
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie(void)
{
    std::cout<<name<<": is Deaaaaaaddddd..."<<std::endl;
}

void    Zombie::announce(void)
{
    std::cout<<name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}

void Zombie::set_name(std::string name)
{
    this->name = name;
}