#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &Copy) {
	if (this == &Copy) {std::cout << "Don't use." << std::endl;}
	else {std::cout << "Don't use." << std::endl;}
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &Copy) : AForm(Copy.getName(), 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (this->getIsSigned() == false)
		throw NotSignedYetException();
	if (this->getGradeToExecute() < executor.getGrade())
		throw GradeTooLowException();
	
	/* executing */
	std::cout << "Drilling sound..." << std::endl;
	std::srand(std::time(NULL));
	int value = std::rand();
	if (value % 2 == 0)
		throw "Robotomy failed.";
	std::cout << "Robotomy completed" << std::endl;
}
