#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
    Weapon &weapon;
    std::string name;
public:
    HumanA(std::string A_name, Weapon &A_weapon);
    void attack();
};

#endif