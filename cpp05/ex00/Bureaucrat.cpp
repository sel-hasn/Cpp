#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("Default"), grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string _name, int _grade): name(_name), grade(_grade)
{
    if (grade > 150)
        throw (GradeTooLowException());
    if (grade < 1)
        throw (GradeTooHighException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):name(other.name), grade(other.grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        this->grade = other.grade;
    return *this;
}

const std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::increment()
{
    if (grade < 2)
        throw (GradeTooHighException());
    --grade;
}

void Bureaucrat::decrement()
{
    if (grade > 149)
        throw (GradeTooLowException());
    ++grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat Grade Too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat Grade Too Low";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat obj)
{
    out<<obj.getName()<<", bureaucrat grade "<<obj.getGrade();
    return out;
}
