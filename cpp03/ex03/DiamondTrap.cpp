#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap():ClapTrap(), ScavTrap(), FragTrap()
{
    Name = "Default";
    ClapTrap::Name = this->Name + "_clap_name";
    Hit_point = FragTrap::Hit_point;
    Eneregy_points = ScavTrap::Eneregy_points;
    Attack_damage = FragTrap::Attack_damage;
    std::cout<<"DiamondTrap constructor called"<<std::endl;
}

DiamondTrap::DiamondTrap(std::string name):ClapTrap(name), ScavTrap(name), FragTrap(name)
{
    Name = name;
    ClapTrap::Name += "_clap_name";
    Hit_point = FragTrap::Hit_point;
    Eneregy_points = ScavTrap::Eneregy_points;
    Attack_damage = FragTrap::Attack_damage;
    std::cout<<"DiamondTrap parameterized constructor called"<<std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other):ClapTrap(other), ScavTrap(other), FragTrap(other)
{
    *this = other;
    std::cout<<"DiamondTrap copy constructor called"<<std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout<<"DiamondTrap destructor called"<<std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        this->::ClapTrap::Name = other.ClapTrap::Name;
        this->Name = other.Name;
        this->Hit_point = other.Hit_point;
        this->Eneregy_points = other.Eneregy_points;
        this->Attack_damage = other.Attack_damage;
    }
    std::cout<<"DiamondTrap copy assignment operator called"<<std::endl;
    return *this;
}

void DiamondTrap::whoAmI()
{
    std::cout<<"DiamondTrap name: "<<Name<<", ClapTrap name: "<<ClapTrap::Name<<std::endl;
}
