#include "ScavTrap.hpp"

int main()
{
    std::cout << "\t===== ScavTrap Test =====" << std::endl;
    std::cout << "===== TEST : ScavTrap Basic Functionality =====" << std::endl;
    ScavTrap scav1("Scavvy");
    scav1.attack("Bandit");
    scav1.takeDamage(20);
    scav1.beRepaired(10);
    scav1.guardGate();
    return 0;
}