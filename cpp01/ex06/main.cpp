#include "Harl.hpp"

int main(int arc, char *arv[])
{
    Harl harl;

    if (arc == 2)
        harl.complain(arv[1]);
    else
        std::cout<<"Invalid input"<<std::endl;
}