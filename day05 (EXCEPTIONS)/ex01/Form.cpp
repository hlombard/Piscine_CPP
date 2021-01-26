#include "Form.hpp"

const char *Form::GradeTooHighException::what(void) const throw() {
	return ("Form Exception: Grade too high!");
}

const char *Form::GradeTooLowException::what(void) const throw() {
	return ("Form Exception: Grade too low!");
}

Form::Form(void) :
_name("default"),
_signed(false),
_gradeToSign(42),
_gradeToExecute(42)
{return;}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) :
_name(name),
_signed(false),
_gradeToSign(gradeToSign),
_gradeToExecute(gradeToExecute)
{
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const & src) :
_name(src._name),
_signed(src._signed),
_gradeToSign(src._gradeToSign),
_gradeToExecute(src._gradeToExecute)
{return;}

std::string Form::getName(void) const {
	return (this->_name);
}

bool Form::getSign(void) const {
	return (this->_signed);
}

int Form::getGradeToSign(void) const {
	return (this->_gradeToSign);
}

int Form::getGradeToExecute(void) const {
	return (this->_gradeToExecute);
}

void Form::beSigned(Bureaucrat const & src) {
	if (src.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
}

Form & Form::operator=(Form const & src) {
	if (this != & src) {
		this->_signed = src.getSign();
	}
	return (*this);
}

Form::~Form(void) {return;}

std::ostream & operator<<(std::ostream & out, Form const & src) {
	out << src.getName() << " is ";
	if (src.getSign() == true)
		out << "signed";
	else
		out << "not signed";
	out << ", grade to sign is " << src.getGradeToSign();
	out << " and grade to execute is " << src.getGradeToExecute();
	out << std::endl;
	return (out);
}
