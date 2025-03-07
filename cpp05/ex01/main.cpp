#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat highRank("ichigo", 1);
        Bureaucrat lowRank("nigo", 150);
        Bureaucrat midRank("sango", 75);

        Form easyForm("EasyForm", 100, 50);
        Form hardForm("HardForm", 10, 5);

        std::cout << highRank << std::endl;
        std::cout << lowRank << std::endl;
        std::cout << midRank << std::endl;
        std::cout << easyForm << std::endl;
        std::cout << hardForm << std::endl;

        std::cout << "\nTrying to sign easyForm:\n";
        
        highRank.signForm(easyForm);
        midRank.signForm(easyForm);
        lowRank.signForm(easyForm);
        
        std::cout << "\nTrying to sign hardForm:\n";
        highRank.signForm(hardForm);
        midRank.signForm(hardForm);

        std::cout << "\nFinal form statuses:\n";
        std::cout << easyForm << std::endl;
        std::cout << hardForm << std::endl;
        midRank.increment();
        midRank.increment();
        midRank.increment();
        midRank.increment();
        highRank.increment();
    }
    catch (const std::exception &e) {
        std::cerr << "Exception : " << e.what() << std::endl;
    }

    return 0;
}