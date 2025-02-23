#include "DiamondTrap.hpp"

int main()
{
    std::cout << "\t===== DiamondTrap Test =====" << std::endl;
    std::cout << "===== TEST : DiamondTrap Basic Functionality =====" << std::endl;
    DiamondTrap diamond1("Diamondy");
    diamond1.attack("Target");
    diamond1.takeDamage(40);
    diamond1.beRepaired(25);
    diamond1.whoAmI();
    return 0;
}