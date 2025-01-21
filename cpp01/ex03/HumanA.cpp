#include "HumanA.hpp"

HumanA::HumanA(std::string A_name, Weapon &A_weapon): weapon(A_weapon), name(A_name)
{
}

void HumanA::attack()
{
    std::cout<<name<<" attacks with their "<<weapon.getType()<<std::endl;
}
