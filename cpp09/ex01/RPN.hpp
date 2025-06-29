#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <stdexcept>
#include <sstream>

bool isOperator(std::string &token);
bool isSingleDigit(std::string &token);
double applyOperator(double a, double b, const std::string &op);

#endif