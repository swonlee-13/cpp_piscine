#ifndef SPAN_HPP
# define SPAN_HPP
# include <cstddef>
# include <algorithm>
# include <exception>
# include <vector>
# include <iostream>
# include <numeric>
# include <cstdlib>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _vector;
		unsigned int _currentNumberOfData;
	
	protected:
		static size_t abs_diff(int a, int b);
		
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &Copy);
		Span &operator=(const Span &Copy);
		~Span();

		typedef std::vector<int>::iterator	iterator_t;

		void addNumber(int data);
		void addNumber(iterator_t begin, iterator_t end);
		size_t shortestSpan();
		size_t longestSpan();

};
#endif
