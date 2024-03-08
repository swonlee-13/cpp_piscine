#include "PhoneBook.hpp"

PhoneBook::~PhoneBook() {}

int		PhoneBook::getIndex() {return index;}

void	PhoneBook::setIndex(int index) {this->index = index;}

void	PhoneBook::setContact() {
    
	int i = getIndex();
    int res = init(i % 8);
	if (res == 1)
		return ;
    i++;
    setIndex(i);
}

int    PhoneBook::init(int i) {

    std::string stringElements[5] = {
        "first name",
        "last name",
        "nick name",
        "phone number",
        "darkest secret"
    };
    std::string info;
    for (int j = 0; j < 5; j++){
        std::cout << "Enter " << stringElements[j] << " : " ;
		std::getline(std::cin, info);
		if (info.length() == 0) {
			j--;
			continue ;
		}
		if (std::cin.eof()) {
			clearerr(stdin);
			std::cin.clear();
			std::cout << std::endl;
			j--;
			return (1);
		}
		switch (j) {
			case 0:
				Contact[i].setFirstName(info);
				break;
			case 1:
				Contact[i].setLastName(info);
				break;
			case 2:
				Contact[i].setNickName(info);
				break;
			case 3:
				if (isValidNumber(info)) {
					Contact[i].setPhoneNumber(info);
				} else {
					j--;
					std::cout << "Error : Wrong number type." << std::endl;
					continue ;
				}
				break;
			case 4:
				Contact[i].setSecret(info);
				break;
			default :
				break;
		}
    }
	return (0);
}

int	PhoneBook::isValidNumber(std::string const &str) {

	for(unsigned long long  i = 0; i < str.size(); i++)
		if (!isdigit(str[i]))
			return (false);
	return (true);
}

std::string PhoneBook::strFormatting(std::string str) {
	if (str.length() > 10)
		return str.substr(0, 10).append(".");
	else
		return str;
}

void	PhoneBook::printPhoneBook(void) {
	int width = 11;
	int end;

	if (index < 8)
		end = index; else end = 8;
	for (int i = 0; i < end; i++){
		std::cout << std::right 
				  << std::setw(width) << i + 1 << "| "
				  << std::setw(width) << strFormatting(Contact[i].getFirstName()) << "| "
				  << std::setw(width) << strFormatting(Contact[i].getLastName()) <<  "| "
				  << std::setw(width) << strFormatting(Contact[i].getNickName()) << "| "
				  << std::setw(width) << strFormatting(Contact[i].getPhoneNumber()) << "| "
				  << std::endl;
	}
}

void	PhoneBook::printContact(int i) {
	std::cout << "********************************" << std::endl;
	std::cout << "Details about index " << i << std::endl;
	std::cout << "First name : " << Contact[i-1].getFirstName() << std::endl;
	std::cout << "Last name : " << Contact[i-1].getLastName() << std::endl;
	std::cout << "Nick name : " << Contact[i-1].getNickName() << std::endl;
	std::cout << "Phone number : " << Contact[i-1].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret : " << Contact[i-1].getSecret() << std::endl;
	std::cout << "********************************" << std::endl;
}

void	PhoneBook::searchContact() {
	std::string line;
	int	index = 0;

	while (!std::cin.eof())
	{
		std::cout << "Write index of contact : ";
		std::getline(std::cin, line);
		if (line.empty()){
			continue ;
		}
		if (std::cin.eof()) {
			if (std::cin.eof())
				std::cout << std::endl;
			clearerr(stdin);
			std::cin.clear();
			return ;
		}
		std::stringstream ss(line);
		ss >> index;
		if (ss.fail()){
			std::cout << "Enter numeric value between 1 to 8" << std::endl;
			index = 0;
			continue ;
		}
		if (index > 8 || index < 1){
			std::cout << "Please enter numeric value between 1 to 8" << std::endl;
			index = 0;
			continue ;
		}
		if (index > this->index) {
			std::cout << "Invalid input. The phone number you requested is not available as it has not been filled." << std::endl;
			index = 0;
			continue ;
		}
		else
			break;
	}
	printContact(index);
}

void	PhoneBook::show() {
	int	width = 11;
	std::cout << "_______________________________________________________________." << std::endl;
	std::cout << std::setfill(' ')
			  << std::setw(width) << std::internal << "Index" << "| "
			  << std::setw(width) << std::internal << "Firstname" << "| "
			  << std::setw(width) << std::internal << "Lastname" << "| "
			  << std::setw(width) << std::internal << "Nickname" << "| "
			  << std::setw(width) << std::internal << "Phonenumber" << "| "
			  << std::endl;
    printPhoneBook();
}
