#include "Harl.hpp"

int main()
{
    Harl harl;

    std::cout<<"Testing With DEBUG Level"<<std::endl;
    harl.complain("DEBUG");
    std::cout<<"Testing With INFO Level"<<std::endl;
    harl.complain("INFO");
    std::cout<<"Testing With WARNING Level"<<std::endl;
    harl.complain("WARNING");
    std::cout<<"Testing With ERROR Level"<<std::endl;
    harl.complain("ERROR");
    std::cout<<"Testing With INVALID Level"<<std::endl;
    harl.complain("INVALID");
}