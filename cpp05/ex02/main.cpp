#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
    try {
        Bureaucrat highRank("Alice", 1);
        Bureaucrat midRank("Bob", 50);
        Bureaucrat lowRank("Charlie", 150);

        std::cout << "----------------------\n";
        std::cout << "     FORM TESTS      \n";
        std::cout << "----------------------\n";

        ShrubberyCreationForm shrubbery("Garden");
        RobotomyRequestForm robotomy("Human");
        PresidentialPardonForm pardon("Criminal");

        std::cout << "\n[🌳 Testing ShrubberyCreationForm]\n";
        lowRank.signForm(shrubbery);
        highRank.signForm(shrubbery);
        highRank.executeForm(shrubbery);

        std::cout << "\n[🤖 Testing RobotomyRequestForm]\n";
        midRank.signForm(robotomy);
        highRank.signForm(robotomy);
        highRank.executeForm(robotomy);

        std::cout << "\n[🎩 Testing PresidentialPardonForm]\n";
        midRank.signForm(pardon);
        highRank.signForm(pardon);
        highRank.executeForm(pardon);

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}