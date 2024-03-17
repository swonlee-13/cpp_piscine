#include "Form.hpp"

Form::Form() :_name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : 
_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
}

Form::Form(const Form &Copy) : _name(Copy._name), _isSigned(Copy._isSigned), _gradeToSign(Copy._gradeToSign), _gradeToExecute(Copy._gradeToExecute) {}

Form &Form::operator=(const Form &Copy) {
	if (this != &Copy) {
		this->_isSigned = Copy._isSigned;
	}
	return *this;
}

Form::~Form() {}

std::string Form::getName() const {
	return _name;
}

bool Form::getIsSigned() const {
	return _isSigned;
}

int Form::getGrageToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &param) {
	if (this->_gradeToSign < param.getGrade())
		throw GradeTooLowException();
	this->_isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const Form &param) {
	out << "form [" << param.getName() << "], signed [" << std::boolalpha << param.getIsSigned() << "] " 
		<< "sign_grade [" << param.getGrageToSign() << "], execute_grade [" << param.getGradeToExecute() << "]";
	return out;
}

const char *Form::GradeTooLowException::what()const throw() {
	return "Grade is low.";
}

const char *Form::GradeTooHighException::what()const throw() {
	return "Grade is high.";
}
