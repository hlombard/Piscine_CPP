#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat joe("Joe", 150);
	Bureaucrat rogan("Rogan", 3);
	std::cout << joe;
	std::cout << rogan << std::endl;

	ShrubberyCreationForm shrubbery("shrubbery");
	PresidentialPardonForm pardon("pardon");
	RobotomyRequestForm robotomy1("robotomy1");
	RobotomyRequestForm robotomy2("robotomy2");
	RobotomyRequestForm robotomy3("robotomy3");
	std::cout << shrubbery;
	std::cout << pardon;
	std::cout << robotomy1;
	std::cout << robotomy2;
	std::cout << robotomy3 << std::endl;

    rogan.signForm(shrubbery);
    rogan.executeForm(shrubbery);

    rogan.signForm(pardon);
    rogan.executeForm(pardon);

    rogan.signForm(robotomy1);
    rogan.signForm(robotomy2);
    rogan.signForm(robotomy3);
    rogan.executeForm(robotomy1);
    rogan.executeForm(robotomy2);
    rogan.executeForm(robotomy3);

    std::cout << std::endl << std::endl;
    // Execute not signed;
    RobotomyRequestForm a("robo");
    rogan.executeForm(a);

    //Execute gradeToExecute too low
    Bureaucrat low("low",  70);
    low.signForm(a);
    low.executeForm(a);

}
