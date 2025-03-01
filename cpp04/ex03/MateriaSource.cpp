#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i=0; i < 4; i++)
        slot[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    for (int i=0; i < 4; i++)
        this->slot[i] = (other.slot[i]) ? other.slot[i]->clone() : NULL;
}

MateriaSource::~MateriaSource()
{
    for (int i=0; i < 4; i++)
        delete slot[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        for (int i=0; i < 4; i++)
        {
            delete this->slot[i];
            this->slot[i] = (other.slot[i]) ? other.slot[i]->clone() : NULL;
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *ptr)
{
    int i = 0;
    while (slot[i] != NULL)
        i++;
    slot[i] = ptr->clone();
    delete ptr;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i=0; i < 4; i++)
    {
        if (slot[i] && type == slot[i]->getType())
            return slot[i]->clone();
    }
    return (NULL);
}
