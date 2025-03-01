#include "AMateria.hpp"

AMateria::AMateria():type("")
{}

AMateria::~AMateria()
{}

AMateria::AMateria(const AMateria &other):type(other.type)
{}

AMateria::AMateria(std::string const & type)
{
    this->type = type;
}

AMateria &AMateria::operator=(const AMateria &other)
{
    (void)other;
    return *this;
}

std::string const & AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}
