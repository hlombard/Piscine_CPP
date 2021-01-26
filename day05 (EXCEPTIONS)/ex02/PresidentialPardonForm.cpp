#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form(target, 25, 5) {return;}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) {
	*this = src;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	Form::execute(executor);
	std::cout << this->getName() <<" has been pardoned by Zafod Beeblebrox" << std::endl;
}


PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & src) {
	(void)src;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {return;}
