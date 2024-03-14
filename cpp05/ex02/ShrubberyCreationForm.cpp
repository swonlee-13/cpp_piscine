#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"		

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &Copy) {
	if (this == &Copy) {std::cout << "Don't use." << std::endl;}
	else {std::cout << "Don't use." << std::endl;}
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &Copy) : AForm(Copy.getName(), 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (this->getIsSigned() == false)
		throw NotSignedYetException();
	if (this->getGradeToExecute() < executor.getGrade())
		throw GradeTooLowException();	

	/* executing */

	std::string fileName = getName() + "_shrubbery";
	std::ofstream outFile(fileName);
	if (!outFile.is_open())
		throw std::ios_base::failure("Failed to open file");
	outFile << "	              v .   ._, |_  .," << std::endl;
	outFile << "           `-._\\/  .  \\ /    |/_" << std::endl;
	outFile << "               \\  _\\, y | \\//" << std::endl;
	outFile << "         _\\_.___\\, \\/ -.\\||" << std::endl;
	outFile << "           `7-,--.`._||  / / ," << std::endl;
	outFile << "           /'     `-. `./ / |/_.'" << std::endl;
	outFile << "                     |    |//" << std::endl;
	outFile << "                     |_    /" << std::endl;
	outFile << "                     |-   |" << std::endl;
	outFile << "                     |   =|" << std::endl;
	outFile << "                     |    |" << std::endl;
	outFile << "--------------------/ ,  . \\--------._" << std::endl;
	outFile.close();	
}
