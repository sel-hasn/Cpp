#include "RPN.hpp"

bool isOperator(std::string &token)
{
	return token == "+" || token == "-" || token == "*" || token == "/";
}

bool isSingleDigit(std::string &token)
{
	return token.length() == 1 && std::isdigit(token[0]);
}

double applyOperator(double a, double b, const std::string &op)
{
	if (op == "+")
		return a + b;
	if (op == "-")
		return a - b;
	if (op == "*")
        return a * b;
	if (op == "/")
	{
		if (b == 0)
			throw std::runtime_error("Error: division by zero.");
		return a / b;
	}
    throw std::runtime_error("Error: unknown operator.");
}