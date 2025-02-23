#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    Name = "ScavTT";
    Hit_point = 100;
    Eneregy_points = 50;
    Attack_damage = 20;
    std::cout<<"ScavTrap constructor called"<<std::endl;
}

ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
    Name = name;
    Hit_point = 100;
    Eneregy_points = 50;
    Attack_damage = 20;
    std::cout<<"ScavTrap parameterized constructor called"<<std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other):ClapTrap(other)
{
    this->Name = other.Name;
    this->Hit_point = other.Hit_point;
    this->Eneregy_points = other.Eneregy_points;
    this->Attack_damage = other.Attack_damage;
    std::cout<<"ScavTrap copy assignment operator called"<<std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout<<"ScavTrap destructor called"<<std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (Hit_point == 0){
        std::cout<<"ScavTrap "<<Name<<" it has no hit point left"<<std::endl;
        return ;
    }
    if (Eneregy_points == 0){
        std::cout<<"ScavTrap "<<Name<<" it has no Eneregy points left"<<std::endl;
        return ;
    }
    std::cout<<"ScavTrap "<<Name<<" attacks "<<target<<", cousing "<<Attack_damage<<" damage!"<<std::endl;
    --Eneregy_points;
}

void ScavTrap::guardGate()
{
    std::cout<<"ScavTrap "<<Name<<" is now in Gate keeper mode!"<<std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        this->Name = other.Name;
        this->Hit_point = other.Hit_point;
        this->Eneregy_points = other.Eneregy_points;
        this->Attack_damage = other.Attack_damage;
    }
    std::cout<<"ScavTrap copy assignment operator called"<<std::endl;
    return (*this);
}

