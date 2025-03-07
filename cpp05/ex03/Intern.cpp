#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    std::string AForms[3] = {"Presidential Pardon", "Robotomy Request", "Shrubbery Creation"};
    AForm* (Intern::*PointerToFunctions[3])(std::string) = {
        &Intern::MakePresidentialPardonForm,
        &Intern::MakeRobotomyRequestForm,
        &Intern::MakeShrubberyCreationForm
    };

    for (int i = 0; i < 3; i++)
    {
        if (name == AForms[i])
        {
            return (this->*PointerToFunctions[i])(target);
        }
    }
    throw InvalidFormException();
}

const char* Intern::InvalidFormException::what() const throw()
{
    return "Invalid Form";
}

AForm *Intern::MakePresidentialPardonForm(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::MakeShrubberyCreationForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::MakeRobotomyRequestForm(std::string target)
{
    return new RobotomyRequestForm(target);
}
