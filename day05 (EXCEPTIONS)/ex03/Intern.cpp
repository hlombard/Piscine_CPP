#include "Intern.hpp"

const char *Intern::UnknownForm::what(void) const throw() {
	return ("Intern Exception: Intern never heard about this form before...");
}

Intern::Intern(void) {return;}

Intern::Intern(Intern const & src) {
	*this = src;
}

Form *Intern::createNewPresidentialPardonForm(std::string const & target) {
	Form *form = new PresidentialPardonForm(target);
	std::cout << "Intern creates a Form: " << form->getName() << std::endl;
	return (form);
}

Form *Intern::createNewRobotomyRequestForm(std::string const & target) {
	Form *form = new RobotomyRequestForm(target);
	std::cout << "Intern creates a Form: " << form->getName() << std::endl;
	return (form);
}

Form *Intern::createNewShrubberyCreationForm(std::string const & target) {
	Form *form = new ShrubberyCreationForm(target);
	std::cout << "Intern creates a Form: " << form->getName() << std::endl;
	return (form);
}

Form *Intern::makeForm(std::string name, std::string target) {

	Form *(Intern::*functptr[3])(std::string const & target) = {
		&Intern::createNewPresidentialPardonForm,
		&Intern::createNewRobotomyRequestForm,
		&Intern::createNewShrubberyCreationForm
		};

	std::string knownForms[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
		};

	for (int i = 0; i < 3; i++)
	{
		if (name.compare(knownForms[i]) == 0)
		{
			return((this->*functptr[i])(target));
		}
	}
	throw Intern::UnknownForm();
	return (NULL);
}


Intern & Intern::operator=(Intern const & src) {
	(void)src;
	return (*this);
}

Intern::~Intern(void) {return;}
