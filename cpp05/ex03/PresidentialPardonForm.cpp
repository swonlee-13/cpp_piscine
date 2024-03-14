#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &Copy) {
	if (this == &Copy) {std::cout << "Don't use." << std::endl;}
	else {std::cout << "Don't use." << std::endl;}
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &Copy) : AForm(Copy.getName(), 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (this->getIsSigned() == false)
		throw NotSignedYetException();
	if (this->getGradeToExecute() < executor.getGrade())
		throw GradeTooLowException();
	
	/* executing */
	
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
