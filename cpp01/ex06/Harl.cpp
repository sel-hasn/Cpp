#include "Harl.hpp"

void Harl::debug( void )
{
    std::cout<<"I love having extra cheese for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n I really do!"<<std::endl<<std::endl;
}

void Harl::info( void )
{
    std::cout<<"I cannot believe adding extra cheese costs more money.\n You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"<<std::endl<<std::endl;
}

void Harl::warning( void )
{
    std::cout<<"I think I deserve to have some extra cheese for free.\n I’ve been coming for years whereas you started working here since last month."<<std::endl<<std::endl;
}

void Harl::error( void )
{
    std::cout<<"This is unacceptable!\n I want to speak to the manager now."<<std::endl<<std::endl;
}

int get_case(std::string level)
{
    int i;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (i=0; i < 4; i++)
    {
        if (levels[i].compare(level) == 0)
            return i;
    }
    return i;
}

void Harl::complain( std::string level )
{
    int i = get_case(level);
    switch (i)
    {
    case 0:
        std::cout<<"[ "<<level<<" ]"<<std::endl;
        debug();
        std::cout<<"[ INFO ]"<<std::endl;
        info();
        std::cout<<"[ WARNING ]"<<std::endl;
        warning();
        std::cout<<"[ ERROR ]"<<std::endl;
        error();
        break;
    case 1:
        std::cout<<"[ "<<level<<" ]"<<std::endl;
        info();
        std::cout<<"[ WARNING ]"<<std::endl;
        warning();
        std::cout<<"[ ERROR ]"<<std::endl;
        error();
        break;
    case 2:
        std::cout<<"[ "<<level<<" ]"<<std::endl;
        warning();
        std::cout<<"[ ERROR ]"<<std::endl;
        error();
        break;
    case 3:
        std::cout<<"[ "<<level<<" ]"<<std::endl;
        error();
        break;
    default:
        std::cout<<"[ Probably complaining about insignificant problems ]"<<std::endl;
        break;
    }
}
