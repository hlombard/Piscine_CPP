#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form(target, 72, 45) {return;}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : Form(src) {return;}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {

	Form::execute(executor);
	std::cout << "* drilling noises * ";
	if (std::rand() % 2)
		std::cout << this->getName() << " has been robotomized successfully!";
	else
		std::cout << this->getName() << " robotomized failure...";
	std::cout << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & src) {
	(void)src;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {return;}
