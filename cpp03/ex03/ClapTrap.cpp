#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    Name = "Default";
    Hit_point = 10;
    Eneregy_points = 10;
    Attack_damage = 0;
    std::cout<<"ClapTrap constructor called"<<std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    Name = name;
    Hit_point = 10;
    Eneregy_points = 10;
    Attack_damage = 0;
    std::cout<<"ClapTrap parameterized constructor called"<<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    *this = other;
    std::cout<<"ClapTrap copy constructor called"<<std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout<<"ClapTrap destructor called"<<std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        this->Name = other.Name;
        this->Hit_point = other.Hit_point;
        this->Eneregy_points = other.Eneregy_points;
        this->Attack_damage = other.Attack_damage;
    }
    std::cout<<"ClapTrap copy assignment operator called"<<std::endl;
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (Hit_point == 0){
        std::cout<<"ClapTrap "<<Name<<" it has no hit point left"<<std::endl;
        return ;
    }
    if (Eneregy_points == 0){
        std::cout<<"ClapTrap "<<Name<<" it has no Eneregy points left"<<std::endl;
        return ;
    }
    std::cout<<"ClapTrap "<<Name<<" attacks "<<target<<", cousing "<<Attack_damage<<" damage!"<<std::endl;
    --Eneregy_points;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (Hit_point == 0){
        std::cout<<"ClapTrap "<<Name<<" it has no hit point left"<<std::endl;
        return ;
    }
    if (Eneregy_points == 0){
        std::cout<<"ClapTrap "<<Name<<" it has no Eneregy points left"<<std::endl;
        return ;
    }
    --Eneregy_points;
    unsigned int damage;
    damage = (Hit_point > amount) ? amount : Hit_point;
    Hit_point -= damage;
    std::cout<<"ClapTrap "<<Name<<" take damage, lose "<<damage<<" hit point"<<std::endl;
    if (!Hit_point)
        std::cout<<"ClapTrap "<<Name<<" has been defeated!"<<std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (Hit_point == 0){
        std::cout<<"ClapTrap "<<Name<<" it has no hit point left"<<std::endl;
        return ;
    }
    if (Eneregy_points == 0){
        std::cout<<"ClapTrap "<<Name<<" it has no Eneregy points left"<<std::endl;
        return ;
    }
    --Eneregy_points;
    Hit_point += amount;
    std::cout<<"ClapTrap "<<Name<<" repairs itself, gets "<<amount<<" hit points"<<std::endl;
}
