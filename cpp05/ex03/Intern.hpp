#ifndef INTERN_HPP
# define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern &other);
    ~Intern();
    Intern &operator=(const Intern &other);

    AForm *makeForm(std::string name, std::string target);
    AForm *MakePresidentialPardonForm(std::string target);
    AForm *MakeShrubberyCreationForm(std::string target);
    AForm *MakeRobotomyRequestForm(std::string target);

    class InvalidFormException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif