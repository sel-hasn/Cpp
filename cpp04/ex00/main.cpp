#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout<<"=======Tests For Animal Class======"<<std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    std::cout<<std::endl;

    std::cout<<"=======Destructures======"<<std::endl;
    delete meta;
    delete j;
    delete i;
    std::cout<<std::endl;

    std::cout<<"=======Tests For WrongAnimal Class======"<<std::endl;
    const WrongAnimal* meta1 = new WrongAnimal();
    const WrongAnimal* c = new WrongCat();
    std::cout << c->getType() << " " << std::endl;
    meta1->makeSound();
    c->makeSound();
    std::cout<<std::endl;

    std::cout<<"=======Destructures======"<<std::endl;
    delete meta1;
    delete c;

    return 0;
}