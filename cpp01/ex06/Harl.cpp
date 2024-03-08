#include "Harl.hpp"

void	Harl::debug(void) {
	std::cout << "[ DEBUG ]" << std::endl << std::endl;
	std::cout << "I love having extra bacon for my special burger." << std::endl;
	std::cout << "I really do!" << std::endl;
}

void	Harl::info(void) {
	std::cout << "[ INFO ]" << std::endl << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger!" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "[ WARNING ]" << std::endl << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void) {
	std::cout << "[ ERROR ]" << std::endl << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level) {

	std::string string[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	
	int i;
	for (i = 0;i < 5; i++) {
		if (level == string[i])
				break;
	}
	switch (i) {
		case 0:
			this->debug();
			std::cout << std::endl;
		case 1:
			this->info();
			std::cout << std::endl;
		case 2:
			this->warning();
			std::cout << std::endl;
		case 3:
			this->error();
			std::cout << std::endl;
			break ;
		default :
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
