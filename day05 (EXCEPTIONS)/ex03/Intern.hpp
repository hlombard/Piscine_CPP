#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {

	public:
		Intern(void);
		Intern(Intern const & src);

		Form *createNewPresidentialPardonForm(std::string const &target);
		Form *createNewRobotomyRequestForm(std::string const &target);
		Form *createNewShrubberyCreationForm(std::string const &target);

		Form *makeForm(std::string name, std::string target);

		class UnknownForm : public std::exception {
			virtual const char *what(void) const throw();
		};

		Intern & operator=(Intern const & src);

		~Intern(void);

};

#endif
