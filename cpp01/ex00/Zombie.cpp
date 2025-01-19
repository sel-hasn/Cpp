#include "Zombie.hpp"

Zombie::Zombie(void)
{
    this->name = "Fang";
}

Zombie::Zombie(std::string _name)
{
    this->name = _name;
}

Zombie::~Zombie(void)
{
    std::cout<<name<<": is Deaaaaaaddddd..."<<std::endl;
}

void    Zombie::announce(void)
{
    std::cout<<name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}
