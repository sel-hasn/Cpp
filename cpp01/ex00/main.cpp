#include "Zombie.hpp"

int main()
{
    Zombie *zombie = newZombie("walker");
    zombie->announce();
    delete zombie;
    randomChump("haalllkkkrr");
    return (0);
}