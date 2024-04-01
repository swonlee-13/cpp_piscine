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

	protected:
		void calculateElements(char op);
	
	public:
		RPN(const char *argument);
		~RPN();
		static bool isStrValid(const char *argument);
		void calculateRPN();
		void printResult();
};

#endif
