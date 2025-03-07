#include "Form.hpp"

Form::Form(): name("Form"), is_sign(false), required_to_sign(150), required_to_execute(150)
{
}

Form::Form(std::string _name, const int ToSing, const int ToExecute): name(_name), is_sign(false), required_to_sign(ToSing), required_to_execute(ToExecute)
{
    if (required_to_sign < 1 || required_to_execute < 1)
        throw (GradeTooHighException());
    if (required_to_sign > 150 || required_to_execute > 150)
        throw (GradeTooLowException());
}

Form::Form(const Form &other):name(other.name), is_sign(other.is_sign), required_to_sign(other.required_to_sign), required_to_execute(other.required_to_execute)
{
}

Form::~Form()
{
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        is_sign = other.is_sign;
    }
    return *this;
}

const std::string Form::getName() const
{
    return name;
}

bool Form::getIsSign() const
{
    return is_sign;
}

int Form::getRequiredtoSign() const
{
    return required_to_sign;
}

int Form::getRequiredtoExecute() const
{
    return required_to_execute;
}

void   Form::beSigned(const Bureaucrat& obj)
{
    if (required_to_sign < obj.getGrade())
        throw(GradeTooLowException());
    is_sign = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Bureaucrat Grade Too High";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Bureaucrat Grade Too Low";
}

std::ostream &operator<<(std::ostream &out, const Form &obj)
{
    out<<"Form : "<<obj.getName()<<" is ";
    if (obj.getIsSign())
        out<<"singed";
    else
        out<<"not singed";
    out<<", grade required to sign "<<obj.getRequiredtoSign();
    out<<", grade required to execute "<<obj.getRequiredtoExecute();
    return out;
}
