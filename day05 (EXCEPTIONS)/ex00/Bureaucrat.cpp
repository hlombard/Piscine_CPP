#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("Bureaucrat Exception: Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("Bureaucrat Exception: Grade too low!");
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name), _grade(src._grade) {

}


std::string const Bureaucrat::getName(void) const {
	return (this->_name);
}

int Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void Bureaucrat::upgrade(void) {
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::downgrade(void) {
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}


Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src) {
	if (this != & src) {
		this->_grade = src._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void) {return;}

std::ostream & operator<<(std::ostream & out, Bureaucrat const & src) {
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return (out);
}
