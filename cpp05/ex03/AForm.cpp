#include "AForm.hpp"

AForm::AForm(): name("AForm"), is_sign(false), required_to_sign(150), required_to_execute(150)
{
}

AForm::AForm(std::string _name, const int ToSing, const int ToExecute): name(_name), is_sign(false), required_to_sign(ToSing), required_to_execute(ToExecute)
{
    if (required_to_sign < 1 || required_to_execute < 1)
        throw (GradeTooHighException());
    if (required_to_sign > 150 || required_to_execute > 150)
        throw (GradeTooLowException());
}

AForm::AForm(const AForm &other):name(other.name), is_sign(other.is_sign), required_to_sign(other.required_to_sign), required_to_execute(other.required_to_execute)
{
}

AForm::~AForm()
{
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        is_sign = other.is_sign;
    }
    return *this;
}

const std::string AForm::getName() const
{
    return name;
}

bool AForm::getIsSign() const
{
    return is_sign;
}

int AForm::getRequiredtoSign() const
{
    return required_to_sign;
}

int AForm::getRequiredtoExecute() const
{
    return required_to_execute;
}

void   AForm::beSigned(const Bureaucrat& obj)
{
    if (required_to_sign < obj.getGrade())
        throw(GradeTooLowException());
    is_sign = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Bureaucrat Grade Too High";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Bureaucrat Grade Too Low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form Is Not Signed";
}

std::ostream &operator<<(std::ostream &out, const AForm &obj)
{
    out<<"AForm : "<<obj.getName()<<" is ";
    if (obj.getIsSign())
        out<<"singed";
    else
        out<<"not singed";
    out<<", grade required to sign "<<obj.getRequiredtoSign();
    out<<", grade required to execute "<<obj.getRequiredtoExecute();
    return out;
}
