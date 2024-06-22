#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const char *argument) : _argString(argument) {}

RPN::~RPN() {}

bool RPN::isStrValid(const char *argument) {
	std::string str = argument;

	if (!isdigit(str[0]) || str[1] != ' ' || !isdigit(str[2]))
		return false;
	for(size_t i = 3; i < str.length(); i++) {
		if (i % 2 == 1 && str[i] == ' ')
			continue ;
		else if (i % 2 == 0 && (isdigit(str[i]) || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'))
			continue ;
		else
			return false;
	}
	return true;
}

void RPN::calculateRPN() {
	for (size_t i = 0; i < _argString.length(); i++) {
		if (isdigit(_argString[i]))
			_calculator.push(static_cast<double>(_argString[i] - 48));
		else if (_argString[i] == '+' || _argString[i] == '-' || _argString[i] == '*' || _argString[i] == '/')
			calculateElements(_argString[i]);
		else if (_argString[i] == ' ')
			continue;
	}
	if (_calculator.size() != 1)
		throw std::invalid_argument("Error");
}

void RPN::calculateElements(char op) {
	double num1;
	double num2;
	if (_calculator.size() < 2) 
		throw std::invalid_argument("Error");
	num2 = _calculator.top();
	_calculator.pop();
	num1 = _calculator.top();
	_calculator.pop();
	if (op == '+')
		num1 = num1 + num2;
	else if (op == '-')
		num1 = num1 - num2;
	else if (op == '*')
		num1 = num1 * num2;
	else if (op == '/') {
		if (num2 == 0)
			throw std::runtime_error("Error");
		num1 = num1 / num2;
	}
	_calculator.push(num1);
}

void RPN::printResult() {
	std::cout << _calculator.top() << std::endl;
}