#include "AForm.hpp"

AForm::AForm() :_name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : 
_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSign < _gradeToExecute)
		throw GradeReverseOrderException();
}

AForm::AForm(const AForm &Copy) : _name(Copy._name), _isSigned(Copy._isSigned), _gradeToSign(Copy._gradeToSign), _gradeToExecute(Copy._gradeToExecute) {}

AForm &AForm::operator=(const AForm &Copy) {
	if (this != &Copy) {
		this->_isSigned = Copy._isSigned;
	}
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const {
	return _name;
}

bool AForm::getIsSigned() const {
	return _isSigned;
}

int AForm::getGrageToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &param) {
	if (this->_gradeToSign < param.getGrade())
		throw GradeTooLowException();
	this->_isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &param) {
	out << "Form [" << param.getName() << "], signed [" << std::boolalpha << param.getIsSigned() << "] " 
		<< "sign_grade [" << param.getGrageToSign() << "], execute_grade [" << param.getGradeToExecute() << "]";
	return out;
}

const char *AForm::GradeTooLowException::what()const throw() {
	return "Grade is low.";
}

const char *AForm::GradeTooHighException::what()const throw() {
	return "Grade is high.";
}

const char *AForm::NotSignedYetException::what()const throw() {
	return "Not signed yet.";
}

const char *AForm::GradeReverseOrderException::what()const throw() {
	return "Sign_grade cannot be set higher than execute_grade.";
}
