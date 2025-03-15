#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
    int random = rand() % 3;
    switch (random)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
    }
    return NULL; 
}

void identify(Base* p)
{
    if (dynamic_cast<A *>(p))
        std::cout<<" A"<<std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout<<" B"<<std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout<<" C"<<std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout<<" A"<<std::endl;
        return ;
    }
    catch(...) {}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout<<" B"<<std::endl;
        return ;
    }
    catch(...) {}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout<<" C"<<std::endl;
        return ;
    }
    catch(...) {}
}

int main()
{
    srand(time(0));

    Base *obj = generate();

    std::cout<<"Identifying using pointer:";
    identify(obj);

    std::cout << "Identifying using reference:";
    identify(*obj);

    delete obj;
    return 0;
}