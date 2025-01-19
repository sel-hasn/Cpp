#include "Zombie.hpp"

int main()
{
    Zombie *zombie = zombieHorde(7, "GGGGAAAHHHHH.....");
    for (int i=0; i < 7; i++)
        zombie->announce();
    return (0);
}