#include "Harl.hpp"

void Harl::debug( void )
{
    std::cout<<"I love having extra cheese for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"<<std::endl;
}

void Harl::info( void )
{
    std::cout<<"I cannot believe adding extra cheese costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"<<std::endl;
}

void Harl::warning( void )
{
    std::cout<<"I think I deserve to have some extra cheese for free. I’ve been coming for years whereas you started working here since last month."<<std::endl;
}

void Harl::error( void )
{
    std::cout<<"This is unacceptable! I want to speak to the manager now."<<std::endl;
}

void Harl::complain(std::string level)
{
    const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*pointer_to_functions[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            (this->*pointer_to_functions[i])();
            return;
        }
    }
    std::cout << "[INVALID] Invalid level!" << std::endl;
}
