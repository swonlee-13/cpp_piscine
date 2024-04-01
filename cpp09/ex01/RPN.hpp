#ifndef RPN_HPP
# define RPN_HPP
# include <stack>
# include <string>
# include <iostream>

class RPN
{
	private:
		std::string _argString;
		std::stack<double> _calculator;
		
		RPN();
		RPN(const RPN &Copy);
		RPN &operator=(const RPN &Copy);

	public:
		RPN(const char *argument);
		~RPN();

		static bool isStrValid(const char *argument);
		void calculateRPN();
		void calculateElements(char op);
		void printResult();
};

#endif
