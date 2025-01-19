#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie *p = new Zombie(name);
    return (p);
}