#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat {

	private:
		Bureaucrat(void);

		std::string const _name;
		int _grade;

	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & src);

		class GradeTooHighException : public std::exception {
			virtual const char *what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
			virtual const char *what(void) const throw();
		};

		std::string const getName(void) const;
		int getGrade(void) const;
		void upgrade(void);
		void downgrade(void);

		Bureaucrat & operator=(Bureaucrat const & src);

		~Bureaucrat(void);

};

std::ostream & operator<<(std::ostream & out, Bureaucrat const & src);

#endif
