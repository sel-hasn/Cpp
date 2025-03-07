#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
    const std::string name;
    bool        is_sign;
    const int   required_to_sign;
    const int   required_to_execute;
public:
    Form();
    Form(const Form &other);
    Form(std::string _name, const int ToSing, const int ToExecute);
    ~Form();

    Form &operator=(const Form &other);

    const std::string getName() const;
    bool        getIsSign() const;
    int   getRequiredtoSign() const;
    int   getRequiredtoExecute() const;
    void        beSigned(const Bureaucrat& obj);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const Form &obj);

#endif