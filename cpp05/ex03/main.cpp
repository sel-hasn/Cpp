#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main() {
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);
    AForm *form;

    try
    {
        std::cout << "Requesting a valid form: Robotomy Request..." << std::endl;
        form = someRandomIntern.makeForm("Robotomy Request", "Bender");
        std::cout << "Intern creates " << form->getName() << std::endl;

        boss.signForm(*form);
        boss.executeForm(*form);

        delete form;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\nRequesting a valid form: Presidential Pardon..." << std::endl;
        form = someRandomIntern.makeForm("Presidential Pardon", "Carloos");
        std::cout << "Intern creates " << form->getName() << std::endl;

        boss.signForm(*form);
        boss.executeForm(*form);

        delete form;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\nRequesting an invalid form: Unknown Form..." << std::endl;
        form = someRandomIntern.makeForm("Unknown Form", "Target");
        delete form;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}