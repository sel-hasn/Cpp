#include "RPN.hpp"

int main(int arc, char *arv[])
{
	if (arc != 2) {
		std::cerr << "Error: invalid number of arguments." << std::endl;
		return 1;
	}

	std::string input(arv[1]);
	std::istringstream iss(input);
	std::string token;
	std::stack<double> stack;

	while (iss >> token) {
		if (isSingleDigit(token)) {
			stack.push(token[0] - '0');
		}
		else if (isOperator(token)) {
			if (stack.size() < 2) {
				std::cerr << "Error: not enough operands." << std::endl;
				return 1;
			}
			double b = stack.top();
			stack.pop();
			double a = stack.top();
			stack.pop();
			try {
				double result = applyOperator(a, b, token);
				stack.push(result);
			}
			catch (const std::exception &exp) {
				std::cerr << exp.what() << std::endl;
				return 1;
			}

		}
		else {
			std::cerr << "Error" << std::endl;
			return 1;
		}
	}
	if (stack.size() != 1) {
		std::cerr << "Error: invalid expression." << std::endl;
		return 1;
	}
	std::cout << stack.top() << std::endl;
}
