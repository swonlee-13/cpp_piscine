#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &Copy) {(void)Copy;}

Intern &Intern::operator=(const Intern &Copy) {
	(void)Copy;
	return *this;
}

Intern::~Intern() {}

AForm * Intern::makeForm(const std::string &nameOfForm, const std::string &targetOfForm) {
	std::string nameTable[3] = {
		"Shrubbery Creation",
		"Robotomy Request",
		"Presidential Pardon"
	};
	int i;
	for (i = 0; i < 3; i++) {
		if (nameOfForm == nameTable[i])
			break;
	}
	if (i == 3)
		throw "Form name doesn't match.";
	switch(i) {
		case 0:
			return new ShrubberyCreationForm(targetOfForm);
			break;
		case 1:
			return new RobotomyRequestForm(targetOfForm);
			break;
		case 2:
			return new PresidentialPardonForm(targetOfForm);
			break;
	}
	return (NULL);
}
