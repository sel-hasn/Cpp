#include "ShrubberyCreationForm.hpp"
#include "fstream"

ShrubberyCreationForm::ShrubberyCreationForm():AForm("chihaja", 145, 137), target("Creation")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target):AForm("chihaja", 145, 137), target(_target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):AForm(other), target(other.target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!getIsSign())
        throw(FormNotSignedException());
    if (getRequiredtoExecute() < executor.getGrade())
        throw(GradeTooLowException());
    
    std::string filename = target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    if (!outfile.is_open()){
        std::cerr<<"Error: Could not create "<<filename<<" file."<<std::endl;
        return ;
    }
    outfile<<"            &&& &&  & &&            "<<std::endl;
    outfile<<"        && &\\/&\\|& ()|/ @, &&     "<<std::endl;
    outfile<<"        &\\/(/&/&||/& /_/)_&/_&     "<<std::endl;
    outfile<<"      &() &\\/&|()|/&\\/ '%' & ()   "<<std::endl;
    outfile<<"     &_\\_&&_\\ |& |&&/&__%_/_& &&    "<<std::endl;
    outfile<<"    &&   && & &| &| /& & % ()& /&&  "<<std::endl;
    outfile<<"     ()&_---()&\\&\\|&&-&&--%---()~   "<<std::endl;
    outfile<<"       &&     \\|||                  "<<std::endl;
    outfile<<"               |||                  "<<std::endl;
    outfile<<"               |||                  "<<std::endl;
    outfile<<"               |||                  "<<std::endl;
    outfile<<"         , -=-~  .-^- _             "<<std::endl;
    outfile.close();
}