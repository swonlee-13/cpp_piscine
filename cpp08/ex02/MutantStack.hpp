#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <deque>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{		
	public:
		MutantStack() : std::stack<T>() {}
		MutantStack(const MutantStack &Copy) : std::stack<T>(Copy) {}
		MutantStack& operator=( const MutantStack& Copy) {
			this->c = Copy.c;
			return *this;
		}
		~MutantStack() {}
		
		typedef typename std::stack<T>::container_type::iterator			iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator	reverse_iterator;

		iterator begin() { return std::stack<T>::c.begin(); }
		iterator end() { return std::stack<T>::c.end(); }
		reverse_iterator rbegin(void) {return this->c.rbegin();}
		reverse_iterator rend(void) {return this->c.rend();}
};

#endif
