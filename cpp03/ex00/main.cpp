#include "ClapTrap.hpp"

int main()
{
    std::cout << "\t===== ClapTrap Test =====" << std::endl;
    std::cout << "===== TEST 1: ClapTrap Basic Functionality =====" << std::endl;
    ClapTrap clap1("Clappy");
    clap1.attack("Enemy");
    clap1.takeDamage(5);
    clap1.beRepaired(3);
    
    std::cout << "\n===== TEST 2: ClapTrap Energy Exhaustion =====" << std::endl;
    ClapTrap clap2("TiredBot");
    for (int i = 0; i < 9; i++)
        clap2.attack("Target");
    clap2.takeDamage(10);
    clap2.attack("Target");
    return 0;
}