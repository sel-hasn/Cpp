#include "Weapon.hpp"

Weapon::Weapon(std::string newtype):type (newtype)
{
}

const std::string& Weapon::getType()
{
    return type;
}

void Weapon::setType(std::string newtype)
{
    type = newtype;
}