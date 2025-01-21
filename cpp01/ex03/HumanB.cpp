#include "HumanB.hpp"

HumanB::HumanB(std::string newname): weapon(NULL), name(newname)
{
}

void HumanB::setWeapon(Weapon &new_weapon)
{
    weapon = &new_weapon;
}

void HumanB::attack()
{
    if (!weapon)
        std::cout<<name<<" has no weapon to attack with"<<std::endl;
    else
        std::cout<<name<<" attacks with their "<<weapon->getType()<<std::endl;
}