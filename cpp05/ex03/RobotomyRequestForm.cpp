#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm():AForm("Robot", 72, 45), target("target")
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):AForm(other), target(other.target)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target):AForm("Robot", 72, 45), target(_target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!getIsSign())
        throw(FormNotSignedException());
    if (getRequiredtoExecute() < executor.getGrade())
        throw(GradeTooLowException());

    std::cout << "💥 *Drilling noises* 🔩⚙️" << std::endl;

    std::srand(std::time(NULL));
    if (std::rand() % 2) {
        std::cout << target << " has been successfully robotomized! 🤖✅" << std::endl;
    } else {
        std::cout << "Robotomy failed on " << target << " ❌💀" << std::endl;
    }
}
