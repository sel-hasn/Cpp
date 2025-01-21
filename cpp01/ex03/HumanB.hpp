#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
    Weapon *weapon;
    std::string name;
public:
    HumanB(std::string newname);
    void setWeapon(Weapon &new_weapon);
    void attack();
};

#endif