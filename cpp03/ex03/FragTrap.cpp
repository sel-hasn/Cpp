#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    Name = "Fraggg";
    Hit_point = 100;
    Eneregy_points = 100;
    Attack_damage = 30;
    std::cout<<"FragTrap constructor called"<<std::endl;
}

FragTrap::FragTrap(std::string name):ClapTrap(name)
{
    Name = name;
    Hit_point = 100;
    Eneregy_points = 100;
    Attack_damage = 30;
    std::cout<<"FragTrap parameterized constructor called"<<std::endl;
}

FragTrap::FragTrap(const FragTrap& other):ClapTrap(other)
{
    *this = other;
    std::cout<<"FragTrap copy constructor called"<<std::endl;
}

FragTrap::~FragTrap()
{
    std::cout<<"FragTrap destructor called"<<std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
    {
        this->Name = other.Name;
        this->Hit_point = other.Hit_point;
        this->Eneregy_points = other.Eneregy_points;
        this->Attack_damage = other.Attack_damage;
    }
    std::cout<<"FragTrap copy assignment operator called"<<std::endl;
    return (*this);
}

void FragTrap::highFivesGuys(void)
{
    std::cout<<"FragTrap "<<Name<<" requests high fives."<<std::endl;
}
