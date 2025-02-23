#include "FragTrap.hpp"

int main()
{
    std::cout << "\t===== FragTrap Test =====" << std::endl;
    std::cout << "===== TEST : FragTrap Basic Functionality =====" << std::endl;
    FragTrap frag1("Fraggy");
    frag1.attack("Robot");
    frag1.takeDamage(30);
    frag1.beRepaired(20);
    frag1.highFivesGuys();
    return 0;
}