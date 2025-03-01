#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const int SIZE = 4;
    Animal* animals[SIZE];

    std::cout<<"/******/Creat Objects of class Dog/******/"<<std::endl;
    std::cout<<std::endl;
    for (int i = 0; i < SIZE / 2; i++)
    animals[i] = new Dog();
    std::cout<<std::endl;
    std::cout<<"/******/Creat Objects of class Cat/******/"<<std::endl;
    std::cout<<std::endl;
    for (int i = SIZE / 2; i < SIZE; i++)
    animals[i] = new Cat();
    std::cout<<std::endl;
    
    std::cout<<"/*****/Test Sounds/*****/"<<std::endl;
    std::cout<<std::endl;
    for (int i = 0; i < SIZE; i++)
        animals[i]->makeSound();
    std::cout<<std::endl;
    
    std::cout<<"/*****/Destructures/*****/"<<std::endl;
    std::cout<<std::endl;
    for (int i = 0; i < SIZE; i++)
        delete animals[i];
    return 0;
}
