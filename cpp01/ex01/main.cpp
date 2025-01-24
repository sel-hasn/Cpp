#include "Zombie.hpp"

int main()
{
    Zombie *zombie = zombieHorde(7, "GGGGAAAHHHHH.....");
    if (!zombie)
    {
        std::cout << "[new] : Bad allocation\n";
        return 1;
    }
    for (int i=0; i < 7; i++)
        zombie->announce();
    return (0);
}
