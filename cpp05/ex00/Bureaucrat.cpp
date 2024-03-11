#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (_grade > 150)
		throw GradeTooLowException();
	if (_grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &Copy) : _name(Copy._name), _grade(Copy._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &Copy) {
	if (this != &Copy) {
		_grade = Copy._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::increment(int promotionGap){
	if (_grade - promotionGap < 1)
		throw GradeTooHighException();
	_grade -= promotionGap;
}

void Bureaucrat::decrement(int relegationGap){
	if (_grade + relegationGap > 150){
		std::cout << "test\n";
		throw GradeTooLowException();
	}
		_grade += relegationGap;
}

// Bureaucrat::GradeTooLowException::GradeTooLowException() {}

const char *Bureaucrat::GradeTooLowException::what()const throw() {
	return "Current grade is lower than minimum value(150).";
}

// Bureaucrat::GradeTooHighException::GradeTooHighException() {}

const char *Bureaucrat::GradeTooHighException::what()const throw() {
	return "Current grade higher than maximum value(1).";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &param) {
	out << param.getName() << ", bureaucrat grade " << param.getGrade() << ".";
	return out;
}
