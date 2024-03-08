#include <iostream>
#include "Contact.hpp"
#include <iomanip>
#include <sstream>

class PhoneBook
{
private:
	Contact		Contact[8];
	int			index;
	std::string strFormatting(std::string str);
	int			isValidNumber(std::string const &str);
	void		printPhoneBook();
	void		printContact(int i);
public:
	PhoneBook() : index(0) {}
	~PhoneBook();

	int		getIndex();
	void	setIndex(int index);
	void	setContact();
	void	show();
	int		init(int i);
	void	searchContact();
};
