#ifndef SPAN_HPP
# define SPAN_HPP
# include <cstddef>
# include <algorithm>
# include <exception>

class Span
{
	private:
		unsigned int _n;
		int *_array;
		unsigned int _numberOfDatas;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &Copy);
		Span &operator=(const Span &Copy);
		~Span();

		void addNumber(int data);
		int shortestSpan();
		int longestSpan();
};
#endif
