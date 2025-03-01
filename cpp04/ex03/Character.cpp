#include "Character.hpp"

Character::Character():name("")
{
    for (int i=0; i < 4 ; i++)
        inventory[i] = NULL;
}

Character::Character(std::string _name):name(_name)
{
    for (int i=0; i < 4 ; i++)
        inventory[i] = NULL;
}

Character::Character(const Character &other):name(other.name)
{
    for (int i=0; i < 4 ; i++)
        this->inventory[i] = (other.inventory[i]) ? other.inventory[i]->clone() : NULL;
}

Character::~Character()
{
    for (int i=0; i < 4; i++)
        delete inventory[i];
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        this->name = other.name;
        for (int i=0; i < 4 ; i++)
        {
            delete this->inventory[i];
            this->inventory[i] = (other.inventory[i]) ? other.inventory[i]->clone() : NULL;
        }
    }
    return *this;
}

std::string const &Character:: getName() const
{
    return name;
}

void Character::equip(AMateria* m)
{
    for (int i=0; i < 4; i++)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    if (0 > idx || idx > 3 || (inventory[idx] == NULL))
        return ;
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if ((inventory[idx] != NULL) && (0 <= idx && idx < 4))
        inventory[idx]->use(target);
}
