#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* ice_tmp;
    ice_tmp = src->createMateria("ice");
    me->equip(ice_tmp);
    ice_tmp = src->createMateria("ice");
    me->equip(ice_tmp);
    AMateria* cure_tmp;
    cure_tmp = src->createMateria("cure");
    me->equip(cure_tmp);
    cure_tmp = src->createMateria("cure");
    me->equip(cure_tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);
    me->use(4, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    me->unequip(3);
    me->use(3, *bob);
    me->unequip(1);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
    delete ice_tmp;
    delete cure_tmp;

    return 0;
}