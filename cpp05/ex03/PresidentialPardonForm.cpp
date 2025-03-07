#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("Pardon", 25, 5), target("home")
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):AForm(other), target(other.target)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target):AForm("Pardon", 25, 5), target(_target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!getIsSign())
        throw(FormNotSignedException());
    if (getRequiredtoExecute() < executor.getGrade())
        throw(GradeTooLowException());

    std::cout<<target<<" has been pardoned by Zaphod Beeblebrox."<<std::endl;
}
