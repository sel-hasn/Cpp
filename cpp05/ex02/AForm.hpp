#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
    const std::string name;
    bool        is_sign;
    const int   required_to_sign;
    const int   required_to_execute;
public:
    AForm();
    AForm(std::string _name, const int ToSing, const int ToExecute);
    AForm(const AForm &other);
    virtual ~AForm();

    AForm &operator=(const AForm &other);

    const std::string getName() const;
    bool         getIsSign() const;
    int   getRequiredtoSign() const;
    int   getRequiredtoExecute() const;
    void         beSigned(const Bureaucrat& obj);
    virtual void execute(Bureaucrat const &executor) const = 0;

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class FormNotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const AForm &obj);

#endif